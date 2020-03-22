life: main.o tab2d.o rules.o pictures.o
	$(CC)  -o life main.o tab2d.o rules.o pictures.o -lm -lpng 

tab2d.o: tab2d.c tab2d.h

rules.o: rules.c rules.h

pictures.o: pictures.c pictures.h

.PHONY: clean

clean:
	-rm *.o life

