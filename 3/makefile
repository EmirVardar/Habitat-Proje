hepsi: derle calistir

derle: Bitki.o Bocek.o Canli.o Habitat.o Pire.o Sinek.o

Bitki.o:
	gcc -I ./include/ -o ./lib/Bitki.o -c ./src/Bitki.c

Bocek.o:
	gcc -I ./include/ -o ./lib/Bocek.o -c ./src/Bocek.c

Canli.o:
	gcc -I ./include/ -o ./lib/Canli.o -c ./src/Canli.c

Habitat.o:
	gcc -I ./include/ -o ./lib/Habitat.o -c ./src/Habitat.c

Pire.o:
	gcc -I ./include/ -o ./lib/Pire.o -c ./src/Pire.c

Sinek.o:
	gcc -I ./include/ -o ./lib/Sinek.o -c ./src/Sinek.c

link:
	gcc -o ./bin/Test ./lib/Bitki.o ./lib/Bocek.o ./lib/Canli.o ./lib/Habitat.o ./lib/Pire.o ./lib/Sinek.o ./src/Test.c -I ./include/

calistir: link
	./bin/Test
