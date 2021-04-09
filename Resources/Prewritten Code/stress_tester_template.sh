#STRESS-TESTER TEMPLATE
#Purpose: This is just a Bash template for a stress tester

g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o A_compiled.out A.cpp
g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o B_compiled.out B.cpp
#g++ -std=c++17 -Wall -fsanitize=address -fsanitize=undefined -Wno-pragmas -Wno-attributes -D_GLIBCXX_DEBUG -o C_compiled.out C.cpp
echo START
for((i = 1; i <= 100; i++)); do
    echo test $i 
    ./A_compiled.out > input.txt
    ./B_compiled.out < input.txt > B_output.txt
    #./C_compiled.out < input.txt > C_output.txt
    #diff -w B_output.txt C_output.txt || break
done
echo DONE