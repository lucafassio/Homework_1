make:
	clear
	g++ main.cpp -o run
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./run
	rm run

del:
	rm Ej2/log.txt
	