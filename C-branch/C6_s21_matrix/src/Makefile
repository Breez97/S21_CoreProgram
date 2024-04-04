# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.

# Directories and files
FUNCTIONS_DIR = s21_matrix_functions
TESTS_DIR = s21_matrix_tests

FUNCTION_FILES = $(wildcard $(FUNCTIONS_DIR)/*.c)
SRCS = $(wildcard $(FUNCTIONS_DIR)/*.c)
OBJS = $(patsubst $(FUNCTIONS_DIR)/%.c, %.o, $(SRCS))
TEST_FILES = $(wildcard $(TESTS_DIR)/*.c)
TEST_SRCS = $(wildcard $(TESTS_DIR)/*.c)
TEST_OBJS = $(patsubst $(TESTS_DIR)/%.c, %.o, $(TEST_SRCS))
TEST_PROGRAM_NAME = s21_matrix_tests/s21_test_matrix.c

# Report flags
GCOVFLAGS = -fprofile-arcs -ftest-coverage

UNAME:=$(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lrt -lpthread -lm
	OPEN_CM=xdg-open

endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck -lpthread -lm
	OPEN_CM=open
endif

all: s21_matrix.a test gcov_report

s21_matrix.a: $(OBJS) 
	ar rcs $@ $^

%.o: s21_matrix_functions/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clang:
	clang-format -i $(FUNCTIONS_DIR)/*.c $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h *.h

clang_check:
	clang-format -n $(FUNCTIONS_DIR)/*.c $(TESTS_DIR)/*.c $(TESTS_DIR)/*.h *.h

test: $(TEST_PROGRAM_NAME) $(SRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SRCS) $(TEST_SRCS) $(LDFLAGS) -o report.out
	./report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info

clean:
	rm -rf report
	rm -rf *.o s21_matrix.a *.gcda *.gcno Coverage_Report.info
	rm -rf test
