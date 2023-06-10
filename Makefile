all: afterLab4 radixSort MarcosOndruska

afterLab4: afterLab4.o
	cc -o afterLab4 afterLab4.c 

radixSort: radixSort.o
	cc -o radixSort radixSort.c 

MarcosOndruska: MarcosOndruska.o 
	cc -o MarcosOndruska MarcosOndruska.c 					

clean:
	rm *.o
