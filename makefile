make:
	clear
	g++ -W main.cpp -o run

#Si no quiere correr el valgrind, comentar la siguiente linea.
	valgrind --error-exitcode=1 --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./run
	rm run
	