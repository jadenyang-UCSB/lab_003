testbst: intbst.o testbst.o
	g++ -Wall -Werror intbst.o testbst.o -o testbst
intbst.o: intbst.cpp intbst.h
	g++ -Wall -Werror -c intbst.cpp
testbst.o: testbst.cpp intbst.h
	g++ -Wall -Werror -c testbst.cpp
clean:
	rm -f *.o testbst