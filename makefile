CC = gcc

all: server client

server:
	@echo "building webserver"
	${CC} -o build/webServer src/webServer.c

client:
	@echo "building client"
	${CC} -o build/client.c src/webServer.c

run:
	@echo "running project"
	./build/client.c wait ./build/webServer

clean:
	@echo "Cleaning project"
	rm build/*