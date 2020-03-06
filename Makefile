
CC = g++
CFLAGS = -std=c++11
INCLUDE = -I/Applications/MATLAB_R2019b.app/extern/include/
LIB = -L/Applications/MATLAB_R2019b.app/bin/maci64/

objects_file = run.o IOManager.o

run : $(objects_file)
	$(CC) $(CFLAGS) $(objects_file) -o run $(INCLUDE) $(LIB) -leng -lm -lmat -lmx -lut -fno-elide-constructors

#run.o	:	test_file.cpp
#	$(CC) -c test_file.cpp -o run.o
run.o	:	run.cpp
	$(CC) -c run.cpp -o run.o
IOManager.o	:	IOManager.h IOManager.cpp Matrix.h
	$(CC) -c IOManager.cpp -o IOManager.o $(INCLUDE)

clean :
	rm $(objects_file) run
