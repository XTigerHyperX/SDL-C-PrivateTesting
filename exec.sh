gcc -c main.c -g 
gcc -c function.c -g 
gcc -c functionPerso.c -g 
gcc main.o function.o functionPerso.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
./prog