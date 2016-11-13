# Makefile para compilar el Trabajo Práctico 1 de Algoritmos y Programación II

DIR_INCLUDE= -I.
CXX = g++
CXXARGS  = -ansi -pedantic -Wall -g
CXXFLAGS = $(DIR_INCLUDE) $(CXXARGS)
RM = -rm -f


all: tp1.exe
	
tp1.exe: main.o cmdline.o complejo.o ft.o proc.o cmdline.h complejo.h ft.o proc.h 
	$(CXX) $(CXXFLAGS) -o tp1.exe main.o cmdline.o complejo.o ft.o proc.o


# Declaración de targets de objetos para tp0
main.o: main.cc
	$(CXX) $(CXXFLAGS) -c -o main.o main.cc
main.cc: cmdline.h complejo.h ft.h proc.h

cmdline.o: cmdline.cc
	$(CXX) $(CXXFLAGS) -c -o cmdline.o cmdline.cc
cmdline.cc: cmdline.h

complejo.o: complejo.cc
	$(CXX) $(CXXFLAGS) -c -o complejo.o complejo.cc
complejo.cc: complejo.h

ft.o: ft.cc
	$(CXX) $(CXXFLAGS) -c -o ft.o ft.cc
ft.cc: ft.h

proc.o: proc.cc
	$(CXX) $(CXXFLAGS) -c -o proc.o proc.cc
proc.cc: proc.h complejo.h 

# Testing
# ¡Hacer las pruebas del enunciado y usar valgrind!

# Cleaning target

.PHONY: clean
clean:
	$(RM) -vf *.o *.exe *.t *.out *.err .*.swp
