gcc -c timerexample.c -o timerexample.o
gcc timerexample.o -o timerexample.exe -lrt
rm *.o
