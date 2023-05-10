default: build run

build:
	clang -O3 -o main main.c hashtable.c -s
	clang -O3 -o db_main main.c hashtable.c -g
run:
	./main
debug:
	gdb ./db_main