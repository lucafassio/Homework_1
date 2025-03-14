make:
	clear
	g++ -W main.cpp -g -o run
	./run
	rm run

del:
	rm Ej2/log.txt
	
	
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./run