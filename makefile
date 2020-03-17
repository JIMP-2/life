main:
	$(CC)  main.c rules.c tab2d.c gen_name.c png.c  -lm -lpng
	./a.out z.txt do.txt
