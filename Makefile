all: radixSort MarcosOndruska

radixSort: radixSort.o
	cc -o radixSort radixSort.c 

MarcosOndruska: MarcosOndruska.o 
	cc -o MarcosOndruska MarcosOndruska.c 					

clean:
	rm *.o
