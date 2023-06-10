all: starter afterLab afterLab2 afterLab3 afterLab4 radixSort MarcosOndruska

starter: starter.o
	cc -o starter starter.c 

afterLab: afterLab.o
	cc -o afterLab afterlab.c 

afterLab2: afterLab2.o
	cc -o afterLab2 afterLab2.c 	

afterLab3: afterLab3.o
	cc -o afterLab3 afterLab3.c 

afterLab4: afterLab4.o
	cc -o afterLab4 afterLab4.c 

radixSort: radixSort.o
	cc -o radixSort radixSort.c 

MarcosOndruska: MarcosOndruska.o 
	cc -o MarcosOndruska MarcosOndruska.c 					

V2: V2.o
	cc -o V2 V2.c	

clean:
	rm *.o
