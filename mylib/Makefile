libmylib.a: palin.o ana.o parse.o opendir.o load.o
	ar -rs libmylib.a palin.o ana.o parse.o opendir.o load.o

palin.o: palin.c mylib.h
	gcc -Wall -c palin.c
	
ana.o: ana.c mylib.h
	gcc -Wall -c ana.c
	
parse.o: parse.c mylib.h
	gcc -Wall -c parse.c

#listeEntRep.o: listeEntRep.c mylib.h
#	gcc -Wall -c listeEntRep.c

opendir.o: opendir.c mylib.h
	gcc -Wall -c opendir.c

load.o: load.c mylib.h
	gcc -Wall -c load.c


clean:
	rm *.o *.a

