
# Automatically generated Makefile

Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++17   
CPP = g++ 

main : Makefile   main.o map.o 
	$(CPP) $(Flags) -o main   main.o map.o 

main.o : Makefile   main.cpp  map.h 
	$(CPP) -c $(Flags) main.cpp -o  main.o


map.o : Makefile   map.cpp   map.h 
	$(CPP) -c $(Flags) map.cpp -o  map.o


