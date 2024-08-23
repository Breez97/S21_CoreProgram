#!/bin/bash

SUCCESS=0
FAIL=0
COUNTER=0
DIFF=""

declare -a tests=(
    "for s21_grep.c s21_grep.h Makefile VAR"
    "for s21_grep.c VAR"
    "-e for -e ^text s21_grep.c test_files/test1.txt s21_grep.h Makefile VAR"
    "-e for -e ^t test_files/test1.txt VAR"
    "-e regex -e ^\} s21_grep.c VAR -f test_files/patterns.txt"
    "-e while -e number s21_grep.c Makefile VAR -f test_files/patterns.txt"
    "VAR -f test_files/patterns.txt test_files/test1.txt"
    "VAR t test_files/test5.txt"
    "VAR test_files/test1.txt test_files/test1.txt"
    "VAR test_files/test1.txt nofile.txt test_files/test2.txt"
    "VAR test_files/test7.txt test_files/test3.txt test_files/test4.txt"
)

declare -a extra=(
    "-n text test_files/test2.txt  test_files/test3.txt"
    "-n text test_files/test3.txt"
    "-n -e ^\} s21_grep.c"
    "-ce ^text test_files/test2.txt  test_files/test3.txt"
    "-e ^t test_files/test3.txt"
    "-nivh n test_files/test2.txt  test_files/test3.txt test_files/test4.txt test_files/test5.txt test_files/test6.txt"
    "-e"
    "-ie TEXT test_files/test3.txt"
    "-echar test_files/test2.txt test_files/test3.txt test_files/test5.txt"
    "-ne n -e text test_files/test2.txt"
    "-iv text test_files/test3.txt"
    "-in text test_files/test3.txt"
    "-c -l number test_files/test2.txt test_files/test6.txt"
    "-v test_files/test2.txt -e te"
    "-noe ) test_files/test2.txt"
    "-l number test_files/test5.txt test_files/test6.txt"
    "-o -e int s21_grep.c"
    "-e = -e text test_files/test2.txt"
    "-noe ing -e as -e include -e int -e is s21_grep.c"
    "-e text -e numb -e t -e aboba -e is test_files/test6.txt"
    "-c -e . test_files/test3.txt -e '.'"
    "-l for no_file.txt s21_grep.c"
    "-f test_files/patterns.txt s21_grep.c"
)

test()
{
    current=$(echo $@ | sed "s/VAR/$var/")
    leaks -atExit -- ./s21_grep $current > test_s21_grep_leak.log
    leaks -atExit -- grep $current > test_grep_leak.log
    leak=$(cat test_s21_grep_leak.log)
    (( COUNTER++ ))
    if [[ $leak == *"0 leaks for 0 total leaked bytes"* ]]
    then
      (( SUCCESS++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m grep $current"
    else
      (( FAIL++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m grep $current"
    fi
}

for i in "${extra[@]}"
do
    test "$i"
done

for var1 in i v c l n h o s
do
    for i in "${tests[@]}"
    do
        test '-'"$var1" "$i"
    done
done

for var1 in i v c l n h o s
do
    for var2 in i v c l n h o s
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

for var1 in i v c l n h o s
do
    for var2 in i v c l n h o s
    do
        for var3 in i v c l n h o s
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    test '-'"$var1" '-'"$var2" '-'"$var3" "$i"
                done
            fi
        done
    done
done

for var1 in i v c l n h o s
do
    for var2 in i v c l n h o s
    do
        if [ $var1 != $var2 ]
        then
            for i in "${tests[@]}"
            do
                test '-'"$var1$var2" "$i"
            done
        fi
    done
done

for var1 in i v c l n h o s
do
    for var2 in i v c l n h o s
    do
        for var3 in i v c l n h o s
        do
            if [ $var1 != $var2 ] && [ $var2 != $var3 ] && [ $var1 != $var3 ]
            then
                for i in "${tests[@]}"
                do
                    test '-'"$var1$var2$var3" "$i"
                done
            fi
        done
    done
done


echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"