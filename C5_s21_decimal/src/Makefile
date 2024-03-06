# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11

# Директории и файлы
SRCS_DIRS = arithmetic/ compare/ conversion/ other/ supports/
SRCS = $(wildcard $(addsuffix *.c, $(SRCS_DIRS)))
OBJS = $(patsubst %.c, %.o, $(SRCS))
TESTS_DIR = tests/arithmetic/ tests/compare/ tests/conversion/ tests/other/ tests/
TEST_SRCS = $(wildcard $(addsuffix *.c, $(TESTS_DIR)))
TEST_OBJ = $(patsubst %.c, %.o, $(TEST_SRCS))
TEST_PROGRAM_NAME = tests/s21_test_main.c

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

all: s21_decimal.a test gcov_report

s21_decimal.a: $(OBJS)
	ar rcs $@ $^

test: $(TEST_PROGRAM_NAME) $(SRCS) $(TEST_SRCS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clang:
	clang-format -i arithmetic/*.c arithmetic/*.h compare/*.c compare/*.h conversion/*.c conversion/*.h other/*.c other/*.h supports/*.c supports/*.h tests/*.c tests/*.h tests/arithmetic/*.c tests/compare/*.c tests/conversion/*.c tests/other/*.c *.h

clang_check:
	clang-format -n arithmetic/*.c arithmetic/*.h compare/*.c compare/*.h conversion/*.c conversion/*.h other/*.c other/*.h supports/*.c supports/*.h tests/*.c tests/*.h tests/arithmetic/*.c tests/compare/*.c tests/conversion/*.c tests/other/*.c *.h

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SRCS) $(TEST_SRCS) $(LDFLAGS) -o report.out
	./report.out
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info

clean:
	rm -rf report
	rm -rf arithmetic/*.o compare/*.o conversion/*.o other/*.o supports/*.o *.o s21_decimal.a *.gcda *.gcno Coverage_Report.info
	rm -rf test

