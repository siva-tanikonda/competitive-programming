import os
import sys
from datetime import date
if(sys.argv[1] == '-c'):
	for i, j, k in os.walk('Environment'):
		for l in k:
			os.remove(os.path.join(i, l))
	open('Environment/input.txt', 'w+');
	for i in range(0, int(sys.argv[3])):
		with open('Resources/Templates/' + sys.argv[2] + '.cpp', 'r') as fin:
			with open('Environment/' + chr(65 + i) + '.cpp', 'w+') as fout:
				for j in fin:
					fout.write(j)
elif(sys.argv[1] == '-t'):
	with open('Resources/Templates/' + sys.argv[2] + '.cpp', 'r') as fin:
		with open('Environment/' + sys.argv[3], 'w+') as fout:
			for i in fin:
				fout.write(i)
elif(sys.argv[1] == '-x'):
	for i, j, k in os.walk('Environment'):
		for l in k:
			os.remove(os.path.join(i, l))
elif(sys.argv[1] == '-d'):
	os.remove('Environment/' + sys.argv[2])
elif(sys.argv[1] == '-r'):
	os.system('g++ -std=c++17 -Wshadow -Wall -o Environment/compiled.out Environment/' + sys.argv[2] + '.cpp -O2 -Wno-unused-result')
	if(len(sys.argv) == 3):
		os.system('./Environment/compiled.out < Environment/input.txt')
	else:
		os.system('./Environment/compiled.out')
elif(sys.argv[1] == '-ra'):
	os.system('g++ -std=c++17 -Wshadow -Wall -o Environment/compiled.out Environment/' + sys.argv[2] + '.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG')
	if(len(sys.argv) == 3):
		os.system('./Environment/compiled.out < Environment/input.txt')
	else:
		os.system('./Environment/compiled.out')
elif(sys.argv[1] == '-b'):
	os.system('g++ -std=c++17 -Wshadow -Wall -o Environment/compiled.out Environment/' + sys.argv[2] + '.cpp -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG')
elif(sys.argv[1] == '-p'):
	os.system('git add *')
	os.system('git commit -m ' + date.today().strftime("%m/%d/%Y"))
	os.system('git push')
