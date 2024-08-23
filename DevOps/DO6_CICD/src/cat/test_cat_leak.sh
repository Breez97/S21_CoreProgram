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
    "test_files/test_1.txt -n"
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
    "test_files/test_1.txt --number --number"
)

test()
{
    current=$(echo $@ | sed "s/VAR/$var/")
    leaks -atExit -- ./s21_cat $current > test_s21_grep_leak.log
    leaks -atExit -- cat $current > test_cat_leak.log
    leak=$(cat test_s21_grep_leak.log)
    (( COUNTER++ ))
    if [[ $leak == *"0 leaks for 0 total leaked bytes"* ]]
    then
      (( SUCCESS++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[32msuccess\033[0m cat $current"
    else
      (( FAIL++ ))
      echo "\033[31m$FAIL\033[0m/\033[32m$SUCCESS\033[0m/$COUNTER \033[31mfail\033[0m cat $current"
    fi
}

for i in "${manual[@]}"
do 
    test "$i"
done

for var1 in b e n s t v
do
    for i in "${tests[@]}"
    do
        test '-'"$var1" "$i"
    done
done

for var1 in b e n s t v
do
    for var2 in b e n s t v
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

for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        for var3 in b e n s t v
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

for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        for var3 in b e n s t v
        do
            for var4 in b e n s t v
            do
                if [ $var1 != $var2 ] && [ $var2 != $var3 ] \
                && [ $var1 != $var3 ] && [ $var1 != $var4 ] \
                && [ $var2 != $var4 ] && [ $var3 != $var4 ]
                then
                    for i in "${tests[@]}"
                    do
                        test '-'"$var1" '-'"$var2" '-'"$var3" "$i"
                    done
                fi
            done
        done
    done
done

for var1 in b e n s t v
do
    for var2 in b e n s t v
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

for var1 in b e n s t v
do
    for var2 in b e n s t v
    do
        for var3 in b e n s t v
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

for i in "${gnu[@]}"
do 
    test "$i"
done

echo "\033[31mFAIL: $FAIL\033[0m"
echo "\033[32mSUCCESS: $SUCCESS\033[0m"
echo "ALL: $COUNTER"