#STRESS TESTER
#Purpose: This is just Python code that allows for stress-testing solutions for correctness, and this requires having a correct solution that is too slow for the problem, and a testcase generator, along with the actual code you are testing

import os
import filecmp
import sys

def printFileContents(name):
    file = open(name, "r")
    file_contents = file.read()
    file_contents = file_contents[:-1]
    print(file_contents)
    file.close()

class color:
    RED = "\033[91m"
    GREEN = "\033[92m"
    BOLD = "\033[1m"
    END = "\033[0m"

#You need arguments when running the scripts
fileBase = sys.argv[1]
fileName = sys.argv[2]
directoryBase = sys.argv[3]

print("Starting Tests...")

#These are just the build commands
os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + fileBase + "_generator -g " + fileBase + "_generator.cpp")
os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + fileBase + " -g " + fileBase + ".cpp")
os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + fileBase + "_slow -g " + fileBase + "_slow.cpp")

print("Building Complete...")

#Change this if you want to run more or fewer tests
n = 100

for i in range(1, n + 1):
    print("Test " + str(i) + ":", end = " ")
    os.system(fileBase + "_generator.exe > " + directoryBase + "\\input.txt")
    os.system(fileBase + " < " + directoryBase + "\\input.txt > " + fileBase + "_output.txt")
    os.system(fileBase + "_slow < " + directoryBase + "\\input.txt > " + fileBase + "_slow_output.txt")
    res = filecmp.cmp(fileBase + "_output.txt", fileBase + "_slow_output.txt")
    if (not res):
        print(color.RED + "FAILED" + color.END)
        print(color.BOLD + "input.txt:", color.END)
        printFileContents(directoryBase + "\\input.txt")
        print(color.BOLD + fileName + "_output.txt:", color.END)
        printFileContents(fileBase + "_output.txt")
        print(color.BOLD + fileName + "_slow_output.txt:", color.END)
        printFileContents(fileBase + "_slow_output.txt")
        break
    else:
        print(color.GREEN + "SUCCESS" + color.END)