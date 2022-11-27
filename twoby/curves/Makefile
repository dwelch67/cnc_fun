

cutme: cutme.c
	gcc cutme.c -o cutme -lm
	./cutme 
	ps2pdf twobycurves.ps
	pdf2svg twobycurves.pdf twobycurves.svg
	cp twobycurves.svg twobycurves.orig.svg
	atril twobycurves.pdf


clean :
	rm -f cutme
