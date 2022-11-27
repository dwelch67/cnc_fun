

cutme: cutme.c
	gcc cutme.c -o cutme -lm
	./cutme 
	ps2pdf twobycorners.ps
	pdf2svg twobycorners.pdf twobycorners.svg
	cp twobycorners.svg twobycorners.orig.svg
	atril twobycorners.pdf


clean :
	rm -f cutme
