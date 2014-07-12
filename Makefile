CC = g++ 
CFLAGS = #-O3
LFLAGS = #
OBJECTS = ising.o lattice.o

#output.txt: main.exe
#	./main.exe > output.txt

ising.exe: $(OBJECTS)
	$(CC) $(LFLAGS) $(OBJECTS) -o ising.exe

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< 
