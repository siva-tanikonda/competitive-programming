#STRESS-TESTER TEMPLATE
#Purpose: This is just a Bash template for a stress tester

g++ -std=c++11 -Wshadow -Wall -O2 -Wno-unused-result -o a.out Ag.cpp
g++ -std=c++11 -Wshadow -Wall -O2 -Wno-unused-result -o b.out A1.cpp
#g++ -std=c++11 -Wshadow -Wall -O2 -Wno-unused-result -o c.out A2.cpp
echo START
for((i = 1; i <= 100; i++)); do
    echo test $i
    ./a.out > input.txt
    ./b.out < input.txt > output1.txt
    #./c.out < input.txt > output2.txt
    #diff -w output1.txt output2.txt || break
done
echo DONE