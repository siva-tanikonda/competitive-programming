import os
import filecmp
import sys

#change this if you want to run more or fewer tests
n = 100

class color:
    RED = "\033[91m"
    GREEN = "\033[92m"
    BOLD = "\033[1m"
    END = "\033[0m"

#Prints the contents of a file
def printFileContents(name):
    file = open(name, "r")
    file_contents = file.read()
    file_contents = file_contents[:-1]
    print(file_contents)
    file.close()

#Gets the contents of a file (with all characters in lowercase)
def getFileContents(name):
    file = open(name, "r")
    file_contents = file.read()
    file_contents = file_contents[:-1]
    file_contents = file_contents.lower()
    file.close()
    return file_contents

def stressTest():

    #You need arguments when running the scripts
    file_base = sys.argv[2]
    directory_base = sys.argv[3]
    operating_system = sys.argv[4]

    #Pick file slash character based on OS
    slash = ""
    if (operating_system == "windows"):
        slash = "\\"
    elif (operating_system == "macos"):
        slash = "/"

    print("Beginning process...")

    #These are just the build commands
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + file_base + "_generator_compiled -g " + file_base + "_generator.cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + file_base + "_compiled -g " + file_base + ".cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + file_base + "_slow_compiled -g " + file_base + "_slow.cpp")
    print("Building complete...")

    #Run the tests and check if both programs have the same output
    print("Beginning tests...")
    for i in range(1, n + 1):
        print("Test " + str(i) + ":", end = " ")
        os.system("Build" + slash + file_base + "_generator_compiled > \"" + directory_base + "/input.txt\"")
        os.system("Build" + slash + file_base + "_compiled < \"" + directory_base + "/input.txt\" > " + file_base + "_output.txt")
        os.system("Build" + slash + file_base + "_slow_compiled < \"" + directory_base + "/input.txt\" > " + file_base + "_slow_output.txt")
        res = filecmp.cmp(file_base + "_output.txt", file_base + "_slow_output.txt")
        if (not res):
            print(color.RED + "FAILED" + color.END)
            print(color.BOLD + "input.txt:", color.END)
            printFileContents(directory_base + "/input.txt")
            print(color.BOLD + file_base + "_output.txt:", color.END)
            printFileContents(file_base + "_output.txt")
            print(color.BOLD + file_base + "_slow_output.txt:", color.END)
            printFileContents(file_base + "_slow_output.txt")
            break
        else:
            print(color.GREEN + "SUCCESS" + color.END)
    print("Done")

def constructiveTest():

    #You need arguments when running the scripts
    file_base = sys.argv[2]
    directory_base = sys.argv[3]
    operating_system = sys.argv[4]

    #Pick file slash character based on OS
    slash = ""
    if (operating_system == "windows"):
        slash = "\\"
    elif (operating_system == "macos"):
        slash = "/"

    print("Beginning process...")

    #These are just the build commands
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + file_base + "_generator_compiled -g " + file_base + "_generator.cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + file_base + "_compiled -g " + file_base + ".cpp")
    os.system("g++ -std=c++17 -fdiagnostics-color=always -Wall -Wno-pragmas -Wno-attributes -o " + "Build/" + file_base + "_checker_compiled -g " + file_base + "_checker.cpp")
    print("Building complete...")

    #Run the tests and check if each output is a proper construction based-off the input
    print("Beginning tests...")
    for i in range(1, n + 1):
        print("Test " + str(i) + ":", end = " ")
        os.system("Build" + slash + file_base + "_generator_compiled > \"" + directory_base + "/input.txt\"")
        os.system("Build" + slash + file_base + "_compiled < \"" + directory_base + "/input.txt\" > " + file_base + "_output.txt")
        os.system("Build" + slash + file_base + "_checker_compiled > " + file_base + "_checker_output.txt")
        verdict = getFileContents(file_base + "_checker_output.txt")
        valid = (verdict == "yes")
        if (not valid):
            print(color.RED + "FAILED" + color.END)
            print(color.BOLD + "input.txt:", color.END)
            printFileContents(directory_base + "/input.txt")
            print(color.BOLD + file_base + "_output.txt:", color.END)
            printFileContents(file_base + "_output.txt")
            break
        else:
            print(color.GREEN + "SUCCESS" + color.END)
    print("Done")


#Actually stress test based on the flags
action = sys.argv[1]
if (action == "stress"):
    stressTest()
else:
    constructiveTest()