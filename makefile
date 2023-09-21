all: make

make:
	gcc -o build/webServer webServer.c

run:
	./build/webServer