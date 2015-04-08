TARGETS = jogo

CC = gcc

FLAGS = -std=c99

LIBS = -lm -lopencv_core -lopencv_highgui -lallegro -lallegro_main -lallegro_primitives

all: $(TARGETS)

camera.o: camera.c camera.h
	$(CC) $(FLAGS) $< -c

jogo: jogo.c camera.o
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)

clean:
	rm -f *~ *.o

destroy: clean
	rm -f $(TARGETS)
