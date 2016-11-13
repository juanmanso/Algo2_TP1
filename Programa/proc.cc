
#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "complejo.h"
#include "ft.h"
#include "proc.h"

using namespace std;

// En el nivel más alto de abstracción del programa
// el sistema es la función entera
void
proc(istream *is, ostream *os, const size_t& s){
	
	// En el nivel intermedio de abstracción
	// el sistema consta de 5 subsistemas
	// representados en las siguientes 5 funciones 
	//
	// Luego el nivel más bajo de abstracción
	// es la implementación de cada función



	// VECTORIZAR LA ENTRADA
//	********************************************
//	Se va a hacer uso de los vectores std:vector	
//	********************************************
	// Se desea que el programa pueda funcionar en tiempo real.
	// Por lo tanto, se propone un while que agarre la entrada,
	// vectorice y realize todo el cálculo dentro del while.

	vector<complejo> array(pow(2,s));	// Vector de complejos (0's) con largo pow(2,s)
	complejo aux;				// Variable auxiliar para captura
	size_t i;				// Variable para iterar el for
	bool eof_flag=false;	

	// Si la entrada es vacia, la vectorizacion corta primero (el for)
	// y luego corta el while (porque lo que leyó el EOF)
	while(!eof_flag){

// *****************************VECTORIZACIÓN************************************* //	

		// Se completan los valores del vector (por def está con ceros)
		for(i=0; i<array.size() && ((*is)>>aux); i++)
			array[i]=(aux);
	
		// Se comprueba si se llegó a EOF
		if(is->eof()){
			eof_flag=true;
			if(i==0)	// Si el archivo está vacio, lo primero que
				break;	// se lee (i=0) es eof ==> se debe salir del
		}			// while de modo que el archivo siga vacio
		
		if(is->bad()){ 
		// El 'for' terminó por no poder guardar el caracter en aux
			cerr	<< "Error: Cannot read complex on input stream"
				<< endl;
			exit(1);
		}		
		
// **************************FIN DE LA VECTORIZACIÓN****************************** //	

	// TRANSFORMAR LOS VECTORES
	

	// ECUALIZAR LA SEÑAL (multiplicación de los coefs por los coefs de la eq)


	// ANTITRANSFORMAR LA SEÑAL


	// IMPRIMIR SEÑAL RESULTANTE
	//
		for(i=0; i<array.size() && ((*os)<<array[i]<<endl); i++)
		
		if(os->bad()){
			cerr	<< "Error: Cannot write output file"
				<< endl;
			exit(1);
		}
	}
}
