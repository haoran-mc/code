CXX=g++
Objects=main.o swap.o
--haoran:$(Objects)
	$(CXX) -o --haoran $(Objects)
main.o:main.cpp include/swap.h
	$(CXX) -c main.cpp
swap.o:src/swap.cpp include/swap.h
	$(CXX) -c src/swap.cpp
