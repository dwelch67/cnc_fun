

all : hello.ps

cutme: cutme.c
	gcc cutme.c -o cutme -lm
	./cutme 
	ps2pdf wider.ps
	pdf2svg wider.pdf wider.svg
	atril wider.pdf
	

hello.ps : hello
	./hello > hello.ps
	ps2pdf hello.ps
	atril hello.pdf


hello : hello.c
	gcc hello.c -o hello -lm
