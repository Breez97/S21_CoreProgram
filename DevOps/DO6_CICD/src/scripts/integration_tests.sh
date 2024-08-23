#!/bin/bash

set -e
chmod +x ../cat/test_cat_func.sh ../grep/test_grep_func.sh

# CAT tests
cd ../cat
./test_cat_func.sh > test_cat_func_result.txt 2>&1

if grep -q "FAIL: 0" ./test_cat_func_result.txt; then
  echo "Tests for cat passed"
else
  echo "Tests for cat failed"
  grep "fail" ./test_cat_func_result.txt > failed_tests_cat.txt
  cat failed_tests_cat.txt
  exit 1
fi

# GREP tests
cd ../grep
./test_grep_func.sh > test_grep_func_result.txt 2>&1

if grep -q "FAIL: 0" ./test_grep_func_result.txt; then
  echo "Tests for grep passed"
else
  echo "Tests for grep failed"
  grep "fail" ./test_grep_func_result.txt > failed_tests_grep.txt
  cat failed_tests_grep.txt
  exit 1
fi
