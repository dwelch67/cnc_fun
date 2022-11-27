

all : cutme

cutme: cutme.c
	gcc cutme.c -o cutme -lm
	./cutme
	atril hello00005.ps
	atril hello00006.ps


hello.ps : hello
	./hello > hello.ps
	atril hello.ps


hello : hello.c
	gcc hello.c -o hello




numbers.ps : numbers
	./numbers > numbers.ps
	atril numbers.ps


numbers : numbers.c
	gcc numbers.c -o numbers
