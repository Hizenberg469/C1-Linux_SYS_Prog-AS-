TARGET: endian_exe

endian_exe: main.o endian.o
	gcc main.o endian.o -o endian_exe

endian.o: endian.c
	gcc -c endian.c -o endian.o

main.o: main.c
	gcc -c main.c -o main.o

clean:
	rm main.o
	rm endian.o
