all: starter afterLab afterLab2

starter: starter.o
	cc -o starter starter.c 

afterlab: afterLab.o
	cc -o afterLab afterlab.c 

afterlab2: afterLab2.o
	cc -o afterLab2 afterLab2.c 		

V2: V2.o
	cc -o V2 V2.c	

clean:
	rm *.o
