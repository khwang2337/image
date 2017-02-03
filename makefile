image.o: makeimage.c
	gcc makeimage.c -o image.o
	
run: image.o
	./image.o
	
clean: 
	rm *.o ; rm image.ppm