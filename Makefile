default:
	gcc screen.c -lglut -lGLU -lGL -o screen

run:
	gcc screen.c -lglut -lGLU -lGL -o screen
	./screen
