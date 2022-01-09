all: main run
	@./run

run: run.c
	@gcc -o run run.c

main: main.c
	@gcc -o main main.c
