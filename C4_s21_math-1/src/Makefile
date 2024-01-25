FLAGS=-Wall -Werror -Wextra -std=c11
LIBS=-lcheck -lsubunit -lm
FUNCTIONS_DIR=s21_math_functions
TESTS_DIR=s21_math_tests
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -I.

TEST_FILES=$(wildcard $(TESTS_DIR)/*.c)
FUNCTION_FILES=$(wildcard $(FUNCTIONS_DIR)/*.c)
SRCS = $(wildcard s21_math_functions/*.c)
OBJS = $(patsubst s21_math_functions/%.c, %.o, $(SRCS))
TEST_SRCS = $(wildcard s21_math_tests/*.c)
TEST_OBJS = $(patsubst s21_math_tests/%.c, %.o, $(TEST_SRCS))
TEST_PROGRAM_NAME = s21_math_tests/s21_test_main.c

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

all: s21_math.a test gcov_report

s21_math.a: $(OBJS) 
	ar rcs $@ $^

%.o: s21_math_functions/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clang:
	clang-format -i s21_math_functions/*.c s21_math_tests/*.c s21_math_tests/*.h *.h

clang_check:
	clang-format -n s21_math_functions/*.c s21_math_tests/*.c s21_math_tests/*.h *.h

test: $(TEST_PROGRAM_NAME) $(SRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SRCS) $(TEST_SRCS) $(LDFLAGS) -o report.out
	./report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info

clean:
	rm -rf report
	rm -rf *.o s21_math.a *.gcda *.gcno Coverage_Report.info
	rm -rf test
