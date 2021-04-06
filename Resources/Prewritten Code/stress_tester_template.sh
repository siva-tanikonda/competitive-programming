#STRESS-TESTER TEMPLATE
#Purpose: This is just a Bash template for a stress tester

g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o a.out A.cpp
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o b.out B.cpp
#g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o c.out C.cpp
echo START
for((i = 1; i <= 100; i++)); do
    echo test $i 
    ./a.out > input.txt
    ./b.out < input.txt > B.txt
    #./c.out < input.txt > C.txt
    #diff -w B.txt C.txt || break
done
echo DONE