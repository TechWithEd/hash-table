default: build run

build:
	gcc -O3 -o main main.c hashtable.c -s
	gcc -O3 -o db_main main.c hashtable.c -g
run:
	./main
debug:
	gdb ./db_main