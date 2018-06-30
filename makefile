CC= g++
exe_file=main
$(exe_file): main.o move.o
	$(CC) main.o move.o -o $(exe_file)
main.o:main.cpp
	$(CC) -c main.cpp
readMatrix.o:move.cpp move.hpp
	$(CC) -c move.cpp
clean:
	rm –f *.out *.o $(exe_file)
