CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage

TARGET = tetris

BACKEND_DIR = brick_game/tetris
FRONTEND_DIR = gui/cli
GAME_DIR = game
TEST_DIR = tests
REPORT_DIR = report
DVI_DIR = dvi
DIST_DIR = brick_game gui dvi/ game/

BACKEND_BUILD_DIR = $(BACKEND_DIR)/build
FRONTEND_BUILD_DIR = $(FRONTEND_DIR)/build
GAME_BUILD_DIR = $(GAME_DIR)/build
TEST_BUILD_DIR = $(TEST_DIR)/build

BACKEND_SRC = $(wildcard $(BACKEND_DIR)/*.c)
FRONTEND_SRC = $(wildcard $(FRONTEND_DIR)/*.c)
GAME_SRC = $(wildcard $(GAME_DIR)/*.c)
TEST_SRC = $(wildcard $(TEST_DIR)/*.c)

BACKEND_OBJ = $(patsubst $(BACKEND_DIR)/%.c, $(BACKEND_BUILD_DIR)/%.o, $(BACKEND_SRC))
FRONTEND_OBJ = $(patsubst $(FRONTEND_DIR)/%.c, $(FRONTEND_BUILD_DIR)/%.o, $(FRONTEND_SRC))
GAME_OBJ = $(patsubst $(GAME_DIR)/%.c, $(GAME_BUILD_DIR)/%.o, $(GAME_SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.c, $(TEST_BUILD_DIR)/%.o, $(TEST_SRC))

LIBRARY = lib_tetris.a

UNAME := $(shell uname -s)
ifeq ($(UNAME),Linux)
	LDFLAGS = -lcheck -lsubunit -lrt -lpthread -lm
	OPEN_CM = xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS = -lcheck -lpthread -lm
	OPEN_CM = open
endif

all: $(TARGET)

$(BACKEND_BUILD_DIR):
	mkdir -p $(BACKEND_BUILD_DIR)

$(FRONTEND_BUILD_DIR):
	mkdir -p $(FRONTEND_BUILD_DIR)

$(GAME_BUILD_DIR):
	mkdir -p $(GAME_BUILD_DIR)

$(TEST_BUILD_DIR):
	mkdir -p $(TEST_BUILD_DIR)

$(REPORT_DIR):
	mkdir -p $(REPORT_DIR)

$(BACKEND_BUILD_DIR)/%.o: $(BACKEND_DIR)/%.c $(BACKEND_BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(FRONTEND_BUILD_DIR)/%.o: $(FRONTEND_DIR)/%.c $(FRONTEND_BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(GAME_BUILD_DIR)/%.o: $(GAME_DIR)/%.c $(GAME_BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(TEST_BUILD_DIR)/%.o: $(TEST_DIR)/%.c $(TEST_BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(LIBRARY): $(BACKEND_OBJ)
	ar rcs $@ $^

$(TARGET): $(LIBRARY) $(FRONTEND_OBJ) $(GAME_OBJ)
	$(CC) $(FLAGS) -o $@ $(FRONTEND_OBJ) $(GAME_OBJ) $(LIBRARY) -lncurses

install: $(TARGET)
	mkdir -p build
	mv $(TARGET) build/
	@echo "┏=========================================┓"
	@echo "┃           Установка завершена           ┃"
	@echo "┗=========================================┛"

uninstall:
	rm -rf build/
	@echo "┏=========================================┓"
	@echo "┃            Удаление завершено           ┃"
	@echo "┗=========================================┛"

dvi: 
	doxygen dvi/Doxyfile
	@echo "┏=========================================┓"
	@echo "┃              Отчет создан               ┃"
	@echo "┗=========================================┛"

dist: clean
	mkdir -p dist/tetris/
	cp -r $(DIST_DIR) dist/tetris/
	cp Makefile .clang-format dist/tetris/
	tar -czvf tetris.tar.gz -C dist tetris
	rm -rf dist
	@echo "┏=========================================┓"
	@echo "┃              Архив создан               ┃"
	@echo "┗=========================================┛"

test: $(LIBRARY) $(TEST_OBJ)
	$(CC) $(FLAGS) $(TEST_OBJ) $(LIBRARY) $(LDFLAGS) -o tetris_test
	@echo "┏=========================================┓"
	@echo "┃            tetris_test создан           ┃"
	@echo "┗=========================================┛"

clang:
	clang-format -i $(BACKEND_DIR)/*.h $(BACKEND_DIR)/*.c $(FRONTEND_DIR)/*.h $(FRONTEND_DIR)/*.c $(GAME_DIR)/*.h $(GAME_DIR)/*.c $(TEST_DIR)/*.c $(TEST_DIR)/*.h

clang_check:
	clang-format -n $(BACKEND_DIR)/*.h $(BACKEND_DIR)/*.c $(FRONTEND_DIR)/*.h $(FRONTEND_DIR)/*.c $(GAME_DIR)/*.h $(GAME_DIR)/*.c $(TEST_DIR)/*.c $(TEST_DIR)/*.h

gcov_report: test $(REPORT_DIR)
	$(CC) $(GCOVFLAGS) $(TEST_SRC) $(BACKEND_SRC) $(LDFLAGS) -o ./$(REPORT_DIR)/report.out
	./$(REPORT_DIR)/report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d $(REPORT_DIR)
	genhtml -o ./$(REPORT_DIR)/report Coverage_Report.info
	@echo "┏=========================================┓"
	@echo "┃    Отчет по покрытиям тестами создан    ┃"
	@echo "┗=========================================┛"

clean:
	rm -rf $(BACKEND_BUILD_DIR) $(FRONTEND_BUILD_DIR) $(GAME_BUILD_DIR) $(TEST_BUILD_DIR) $(TARGET) $(LIBRARY) $(REPORT_DIR) $(DVI_DIR)/gen/ *.out Coverage_Report.info tetris_test *.txt /tetris *.tar.gz
	@echo "┏=========================================┓"
	@echo "┃            Очистка завершена            ┃"
	@echo "┗=========================================┛"

dependencies:
	sudo apt install -y libncurses5-dev check lcov valgrind doxygen graphviz tar clang-format make

.PHONY: all install run uninstall dvi dist test valgrind_test valgrind gcov_report clean clean_tetris clean_tests clean_dvi clean_dist rebuild clang_check clang_format dependencies