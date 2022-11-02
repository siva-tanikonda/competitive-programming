import os
import filecmp
from re import L
import sys
import time

#change this if you want to run more or fewer tests
n = 100

class color:
    RED = "\033[91m"
    GREEN = "\033[92m"
    BOLD = "\033[1m"
    END = "\033[0m"

def printFileContents(name):
    file = open(name, "r")
    file_contents = file.read()
    file_contents = file_contents[:-1]
    print(file_contents)
    file.close()

def getFileContents(name):
    file = open(name, "r")
    file_contents = file.read()
    file_contents = file_contents[:-1]
    file_contents = file_contents.lower()
    file.close()
    return file_contents

def stressTest():
    #You need arguments when running the scripts
    fileBase = sys.argv[2]
    directoryBase = sys.argv[3]

    print("Beginning process...")

    #These are just the build commands
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + fileBase + "_generator_compiled -g " + fileBase + "_generator.cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + fileBase + "_compiled -g " + fileBase + ".cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + fileBase + "_slow_compiled -g " + fileBase + "_slow.cpp")
    print("Building complete...")

    print("Beginning tests...")
    for i in range(1, n + 1):
        print("Test " + str(i) + ":", end = " ")
        os.system("Build/" + fileBase + "_generator_compiled > \"" + directoryBase + "/input.txt\"")
        os.system("Build/" + fileBase + "_compiled < \"" + directoryBase + "/input.txt\" > " + fileBase + "_output.txt")
        os.system("Build/" + fileBase + "_slow_compiled < \"" + directoryBase + "/input.txt\" > " + fileBase + "_slow_output.txt")
        res = filecmp.cmp(fileBase + "_output.txt", fileBase + "_slow_output.txt")
        if (not res):
            print(color.RED + "FAILED" + color.END)
            print(color.BOLD + "input.txt:", color.END)
            printFileContents(directoryBase + "/input.txt")
            print(color.BOLD + fileBase + "_output.txt:", color.END)
            printFileContents(fileBase + "_output.txt")
            print(color.BOLD + fileBase + "_slow_output.txt:", color.END)
            printFileContents(fileBase + "_slow_output.txt")
            break
        else:
            print(color.GREEN + "SUCCESS" + color.END)
    print("Done")

def constructiveTest():
    #You need arguments when running the scripts
    fileBase = sys.argv[2]
    directoryBase = sys.argv[3]

    print("Beginning process...")

    #These are just the build commands
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + fileBase + "_generator_compiled -g " + fileBase + "_generator.cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + fileBase + "_compiled -g " + fileBase + ".cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + fileBase + "_checker_compiled -g " + fileBase + "_checker.cpp")
    print("Building complete...")

    print("Beginning tests...")
    for i in range(1, n + 1):
        print("Test " + str(i) + ":", end = " ")
        os.system("Build/" + fileBase + "_generator_compiled > \"" + directoryBase + "/input.txt\"")
        os.system("Build/" + fileBase + "_compiled < \"" + directoryBase + "/input.txt\" > " + fileBase + "_output.txt")
        os.system("Build/" + fileBase + "_checker_compiled > " + fileBase + "_checker_output.txt")
        verdict = getFileContents(fileBase + "_checker_output.txt")
        valid = (verdict == "yes")
        if (not valid):
            print(color.RED + "FAILED" + color.END)
            print(color.BOLD + "input.txt:", color.END)
            printFileContents(directoryBase + "/input.txt")
            print(color.BOLD + fileBase + "_output.txt:", color.END)
            printFileContents(fileBase + "_output.txt")
            break
        else:
            print(color.GREEN + "SUCCESS" + color.END)
    print("Done")


action = sys.argv[1]
if (action == "stress"):
    stressTest()
else:
    constructiveTest()