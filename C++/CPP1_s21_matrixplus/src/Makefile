# Compiler and flags
CC = gcc
FLAGS = -std=c++17 -Wall -Werror -Wextra
LDFLAGS = -lstdc++ -lgtest -pthread -lm
GCOVFLAGS = -fprofile-arcs -ftest-coverage
VALFLAGS = --tool=memcheck --leak-check=yes

# Directories and files
SRC_DIR = s21_matrix_oop_functions
TESTS_DIR = s21_matrix_oop_tests

SRC_BUILD_DIR = $(SRC_DIR)/build
TESTS_BUILD_DIR = $(TESTS_DIR)/build
$(SRC_BUILD_DIR):
	mkdir -p $@
$(TESTS_BUILD_DIR):
	mkdir -p $@

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(SRC_BUILD_DIR)/%.o, $(SRC_FILES))
TESTS_FILES = $(wildcard $(TESTS_DIR)/*.cpp)
TESTS_OBJS = $(patsubst $(TESTS_DIR)/%.cpp, $(TESTS_BUILD_DIR)/%.o, $(TESTS_FILES))

LIBRARY = s21_matrix_oop.a

$(SRC_BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(SRC_BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(TESTS_BUILD_DIR)/%.o: $(TESTS_DIR)/%.cpp | $(TESTS_BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

# Targets
all: s21_matrix_oop.a test gcov_report

s21_matrix_oop.a: $(SRC_OBJS)
	ar rcs $@ $^

test: s21_matrix_oop.a $(TESTS_OBJS)
	$(CC) $(FLAGS) -o $@ $(TESTS_OBJS) s21_matrix_oop.a $(LDFLAGS)
	./$@

clang_check:
	clang-format -n $(SRC_DIR)/*.cpp *.h $(TESTS_DIR)/*.cpp $(TESTS_DIR)/*.h

clang_format:
	clang-format -i $(SRC_DIR)/*.cpp *.h $(TESTS_DIR)/*.cpp $(TESTS_DIR)/*.h

valgrind: test
	$@ $(VALFLAGS) ./$^

gcov_report: test
	@mkdir -p $@
	$(CC) $(GCOVFLAGS) $(SRC_FILES) $(TESTS_FILES) $(LDFLAGS) -o $@/report.out
	./$@/report.out
	lcov -t "gcov_report" -o $@/Coverage_Report.info -c -d . --no-external --ignore-errors mismatch
	genhtml -o ./$@/report $@/Coverage_Report.info
	rm -rf ./$@/*.info ./$@/*.out ./$@/*.gcda ./$@/*.gcno
	open ./$@/report/index.html

clean:
	rm -rf $(SRC_BUILD_DIR) $(TESTS_BUILD_DIR) gcov_report/ s21_matrix_oop.a test a.out

dependencies:
	sudo apt install build-essential libgtest-dev lcov