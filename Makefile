
value.o: Value.cpp
	g++ -c Value.cpp -o value.o

tokenizer.o: tokenizer.cpp
	g++ -c tokenizer.cpp -o tokenizer.o

parser.o: parser.cpp
	g++ -c parser.cpp -o parser.o

main.o: main.cpp
	g++ -c main.cpp -o main.o

all: main.o value.o tokenizer.o parser.o
	g++ main.o value.o tokenizer.o parser.o -o main

clean:
	rm *.o
