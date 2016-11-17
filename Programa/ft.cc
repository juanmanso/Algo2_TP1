

#include "ft.h"
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

ft* ft::get_f_method(const ft_flag_t flag){
	ft* method;

	switch(flag){
		case FT_FLAG_DFT:	
			method = new dft;
			break;
		case FT_FLAG_IDFT:
			method = new idft;
			break;
		case FT_FLAG_FFT:
			method = new fft;
			break;
		case FT_FLAG_IFFT:
			method = new ifft;
			break;
		case FT_FLAG_FFT_ITER:
			method = new fft_iter;
			break;
		case FT_FLAG_IFFT_ITER:
			method = new ifft_iter;
			break;
	}

	return method;
}

ft* ft::get_r_method(const ift_flag_t flag){
	ft* method;

	switch(flag){
		case IFT_FLAG_IDFT:
			method = new idft;
			break;
		case IFT_FLAG_IFFT:
			method = new ifft;
			break;
	}

	return method;
}

void dft::calc(vector<complejo> &x){

	// Esta es la funcion que realiza la DFT propiamente
	// dicha, mediante el algoritmo "naive" - es decir
	// simplemente calculando la serie de la definicion.

	complejo suma;

	complejo WN0(cos(2*M_PI/(x.size())), -sin(2*M_PI/(x.size())));
	complejo WN(1);
	complejo WNk(1);

	cout << "N = " << x.size() << endl;

	vector<complejo> aux(x.size());

	// Hago la cuenta "in-place", reescribiendo el mismo
	// vector x que me pasan por referencia de manera de 
	// ahorrar memoria.

	complejo prueba(2);
	prueba = prueba.pow(3);

	cout << "prueba = " << prueba << endl;

	for(size_t k=0; k < aux.size(); k++){
//		WN = WNk;
		WNk = WN0.pow(k);
		suma = 0;
		for(size_t n=0; n < x.size(); n++){
			WN = WNk.pow(n);
			suma += x[n]*WN;
			WN *= WN;
		}
	
		aux[k] = suma;
	}


	cout << "Aux = [";

	for(size_t i=0; i<aux.size(); i++)
		cout << aux[i] << " ";
	cout << "]" << endl;
	
	x = aux;		

//	for(size_t i=0; i < x.size(); i++)
//		x[i] = aux[i];	
		

//	for(size_t i=0; i<x.size() ; i++){
//		cout << "WN = " << WN << endl;
//		suma += x[i]*WN;
//		WN *= WN0;
//	}	
//
//	WN = 1;

//	cout << "Suma =  " << suma << endl;
//
//	for(size_t i=0; i < x.size(); i++){
//		cout << "WN2 = " << WN << endl;
//		x[i] = suma*WN;
//		WN *= WN0;
//	}

}	
