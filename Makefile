# simple makefile

# define target dependencies and files
matrixmanip: main.o matrix.o
	g++ -o matrixmanip main.o matrix.o

# define how each object file is to be built
main.o: main.cpp matrix.h
	g++ -c main.cpp -std=c++11 -W -Wall --pedantic

matrix.o: matrix.cpp matrix.h
	g++ -c matrix.cpp -std=c++11 -W -Wall --pedantic

# clean up
clean:
	rm -f matrixmanip.exe *.o

