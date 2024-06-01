
value.o: Value.cpp
	g++ -c Value.cpp -o value.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

all: main.o value.o
	g++ main.o value.o -o main

clean:
	rm *.o
