default:
	gcc random.pixels.c -lglut -lGLU -lGL -o random.pixels

run:
	gcc random.pixels.c -lglut -lGLU -lGL -o random.pixels
	./random.pixels
