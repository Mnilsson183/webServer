CC = gcc

all: make

make:
	@echo "making project"
	${CC} -o build/webServer src/webServer.c

run:
	@echo "building project"
	./build/webServer

clean:
	@echo "Cleaning project"
	rm build/*