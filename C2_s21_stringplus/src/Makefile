FLAGS=-Wall -Werror -Wextra -std=c11
LIBS=-lcheck -lsubunit -lm
FUNCTIONS_DIR=s21_string_functions
TESTS_DIR=s21_string_tests
OUT_DIR=build
OUT_EXECUTABLE=string
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.

TEST_FILES=$(wildcard $(TESTS_DIR)/*.c)
FUNCTION_FILES=$(wildcard $(FUNCTIONS_DIR)/*.c)
SRCS = $(wildcard s21_string_functions/*.c)
OBJS = $(patsubst s21_string_functions/%.c, %.o, $(SRCS))
SPRINTFSRCS = $(wildcard s21_string_functions/s21_sprintf/*.c)
SPRINTFOBJS = $(patsubst s21_string_functions/s21_sprintf/%.c, %.o, $(SPRINTFSRCS))
TEST_SRCS = $(wildcard s21_string_tests/*.c)
TEST_OBJS = $(patsubst s21_string_tests/%.c, %.o, $(TEST_SRCS))
TEST_PROGRAM_NAME = s21_string_tests/s21_test_main.c

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

all: s21_string.a test gcov_report

s21_string.a: $(OBJS) $(SPRINTFOBJS)
	ar rcs $@ $^

%.o: s21_string_functions/%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: s21_string_functions/s21_sprintf/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clang:
	clang-format -i s21_string_functions/*.c s21_string_functions/s21_sprintf/*.c s21_string_functions/s21_sprintf/*.h s21_string_tests/*.c s21_string_tests/*.h *.h

clang_check:
	clang-format -n s21_string_functions/*.c s21_string_functions/s21_sprintf/*.c s21_string_functions/s21_sprintf/*.h s21_string_tests/*.c s21_string_tests/*.h *.h

test: $(TEST_PROGRAM_NAME) $(SRCS) $(SPRINTFSRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SRCS) $(SPRINTFSRCS) $(TEST_SRCS) $(LDFLAGS) -o report.out
	./report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info

clean:
	rm -rf $(OUT_DIR)
	rm -rf *.o s21_string.a
