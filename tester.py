import os
from re import match
from unittest import case


test = input("Tester: \n(1 : defined Buffer)\n(2 : Buffer 99)\n(3 : Buffer 9999)\n(4 : valgrind)\n(5 : valgrind Bonus)\n(Github commit : Commit Github)\n(commit all : vogt and github)\n")
match test:
	case '1':
		os.system('cc get_next_line.c get_next_line_utils.c test.c -o test.o -ggdb3; ./test.o; rm test.o')
		input("Fertig?")
		os.system('clear')
	case '2':
		os.system('cc get_next_line.c get_next_line_utils.c test.c -o test.o -ggdb3 -D BUFFER_SIZE=99; ./test.o; rm test.o')
		input("Fertig?")
		os.system('clear')
	case '3':
		os.system('cc get_next_line.c get_next_line_utils.c test.c -o test.o -ggdb3 -D BUFFER_SIZE=9999; ./test.o; rm test.o')
		input("Fertig?")
		os.system('clear')
	case '4':
		buffer_size = input("Buffer_size: ")
		os.system('cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c test.c -o test.o -ggdb3 -D BUFFER_SIZE=' + buffer_size +' ; valgrind --show-leak-kinds=all --leak-check=full  -s ./test.o | cat -e; rm test.o')
		input("Fertig?")
		os.system('clear')
	case '5':
		buffer_size = input("Buffer_size: ")
		os.system('cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c test_bonus.c -o test.o -ggdb3 -D BUFFER_SIZE=' + buffer_size +' ; valgrind --show-leak-kinds=all --leak-check=full  -s ./test.o | cat -e; rm test.o')
		input("Fertig?")
		os.system('clear')
	case 'github':
		os.system('git push git@github.com:Granada28/get_next_line.git')
	case 'vogt':
		os.system('git push')
	case 'push all':
		os.system('git push git@github.com:Granada28/get_next_line.git')
		os.system('git push')
	case 'github commit':
		commit = input("Name des Commits: ")
		command = 'git add -A; git commit -m ""' + commit + '""; git push git@github.com:Granada28/get_next_line.git'
		os.system(command)
	case 'vogt commit':
		commit = input("Name des Commits: ")
		command = 'git add -A; git commit -m ""' + commit + '""; git push'
		os.system(command)
	case 'commit all':
		commit = input("Name des Commits: ")
		command = 'git add -A; git commit -m ""' + commit + '""; git push git@github.com:Granada28/get_next_line.git; git push'
		os.system(command)