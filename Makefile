CCX=g++ -std=c++11

a.out: TestCase.o
		$(CCX) main.cpp *.o
		
TestCase.o: TestCase.cpp TestCase.hpp
		$(CCX) -c TestCase.cpp

clean:
		rm  *.o a.out

