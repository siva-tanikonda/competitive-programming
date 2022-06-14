#STRESS TESTER
#Purpose: This is a tool to stress-test slow, correct solutions against faster, incorrect solutions and find test cases that cause discrepancies

#!/bin/bash

g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o "$1"_compiled.out "$1".cpp
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o "$1"_slow_compiled.out "$1"_slow.cpp
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o "$1"_generator_compiled.out "$1"_generator.cpp

echo START
for((i = 1; i <= 100; i++));
do
    echo TEST "$i" 
    ./"$1"_generator_compiled.out > input.txt
    ./"$1"_compiled.out < input.txt > "$1"_output.txt
    ./"$1"_slow_compiled.out < input.txt > "$1"_slow_output.txt
    diff -w "$1"_output.txt "$1"_slow_output.txt || break
done
echo DONE