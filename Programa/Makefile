# Makefile para compilar el Trabajo Práctico 1 de Algoritmos y Programación II

DIR_INCLUDE= -I.
CXX = g++
CXXARGS  = -ansi -pedantic -Wall -g
CXXFLAGS = $(DIR_INCLUDE) $(CXXARGS)
RM = -rm -f


all: tp1.exe 
	
tp1.exe: main.o cmdline.o complejo.o ft.o proc.o cmdline.h complejo.h ft.h proc.h 
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
proc.cc: proc.h complejo.h ft.h

# Testing
# ¡Hacer las pruebas del enunciado y usar valgrind!
test: tp1.exe test1

# Empty file test
test1:
	@set -e; echo **TEST 1** - Empty file;		\
	touch test1.in;					\
	./tp1.exe -i test1.in -o test1.out;		\
	if (diff -b test1.out test1.in); 		\
	then	echo **TEST 1 OK**;			\
	else	echo **TEST 1 FAILED**;			\
	fi											
	@rm test1.*;			

# Filling with ceros test
test2:
	@set -e; echo **TEST 2** - Filling with ceros;		\
	echo 1 1 > test2.in;					\
	echo (1,0) (1,0) (0,0) (0,0) > test2.ref;		\
	./tp1.exe -i test2.in -o test2.out -b 2;		\
	if (diff -b test2.out test2.ref); 			\
	then	echo **TEST 2 OK**;				\
	else	echo **TEST 2 FAILED**;				\
	fi											
	@rm test2.*;			

################## END TESTING #######################



# Cleaning targets

.PHONY: clean
clean:
	$(RM) -v *.o *.exe *.t *.out *.err .*.swp

.PHONY: partial_cleaning
partial_cleaning:
	$(RM) *.o .*.swp	
