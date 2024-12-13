.PHONY: build run all

build:
	gcc -o a main.c mzl.c -lglfw -lGLEW -lGL

run:
	./a

all:
	@make build
	@make run
