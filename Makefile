
practica.exe: practica.o 
	g++ -o practica.exe *.o

practica.o: main.cpp
	g++ -c --std=c++11 *.cpp src/classes/*.cpp src/classes/*.h src/problem/*.cpp  src/problem/*.h  src/algorithm/*.cpp src/algorithm/*.h  -D_GLIBCXX_DEBUG

reclean:
	rm results.txt Results1.txt time.csv

# Aquesta última opció serverix per netejar el directori de fitxers
# innecesaris; s'executa mitjançant el comandament "make clean"
	
	
clean:
	rm *.o
	rm *.exe
	rm *.h.gch
