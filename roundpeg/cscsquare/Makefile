
hello.pdf : hello.c
	gcc hello.c -o hello -lm
	./hello > hello.ps
	ps2pdf hello.ps
	atril hello.pdf
