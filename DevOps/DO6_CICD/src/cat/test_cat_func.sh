#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""

declare -a tests=(
    "VAR test_files/test_1.txt"
    "VAR test_files/test_1.txt test_files/test_2.txt"
)

declare -a manual=(
    "-b test_files/test_1.txt"
    "-b test_files/test_1.txt nofile.txt"
    "-e test_files/test_1.txt"
    "-e test_files/test_1.txt nofile.txt"
    "-n test_files/test_2.txt"
    "-n test_files/test_2.txt nofile.txt"
    "-s test_files/test_3.txt"
    "-s test_files/test_3.txt nofile.txt"
    "-t test_files/test_3.txt"
    "-t test_files/test_3.txt nofile.txt"
    "-n test_files/test_4.txt"
    "-n test_files/test_4.txt test_files/test_5.txt"
    "-v test_files/test_5.txt"
    "-- test_files/test_5.txt"
    "no_file.txt"
    "-n -b test_files/test_1.txt"
    "-s -n -e test_files/test_4.txt"
    "-b -e -n -s -t -v test_files/test_3.txt"
    "-benstv test_files/test_3.txt"
    "-v catTest1.txt"
)

declare -a gnu=(
    "-T test_files/test_1.txt"
    "-E test_files/test_1.txt"
    "-vT test_files/test_3.txt"
    "--number test_files/test_2.txt"
    "--squeeze-blank test_files/test_1.txt"
    "--number-nonblank test_files/test_4.txt"
)

test()
{
    current=$(echo $@ | sed "s/VAR/$var/")
    ./s21_cat $current > test_s21_cat.log
    cat $current > test_cat.log
    DIFF="$(diff -s test_s21_cat.log test_cat.log)"
    (( COUNTER++ ))
    if [ "$DIFF" == "Files test_s21_cat.log and test_cat.log are identical" ]
    then
      (( SUCCESS++ ))
      echo -e "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m cat $current"
    else
      (( FAIL++ ))
      echo -e "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m cat $current"
    fi
}

for i in "${manual[@]}"
do
    test "$i"
done

for var1 in e n v t
do
    for i in "${tests[@]}"
    do
        test '-'"$var1" "$i"
    done
done

for var1 in e n
do
    for var2 in e n t
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                test '-'"$var1" '-'"$var2" "$i"
            done
        fi
    done
done

for i in "${gnu[@]}"
do
    test "$i"
done

echo -e "\033[31mFAIL: $FAIL\033[0m"
echo -e "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"