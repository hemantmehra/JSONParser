
value.o: Value.cpp
	g++ -c Value.cpp -o value.o

tokenizer.o: tokenizer.cpp
	g++ -c tokenizer.cpp -o tokenizer.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

all: main.o value.o tokenizer.o
	g++ main.o value.o tokenizer.o -o main

clean:
	rm *.o
