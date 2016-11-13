#ifndef _FT_H_INCLUDED_
#define _FT_H_INCLUDED_


// Aquí se debe definir la clase ft, la cual será abstracta. Ésta se encarga
// de indicar el método de cálculo a utilizar (i.e. DFT, FFT).
//
// Asímismo, se deben definir las clases "hijas" como DFT y FFT.

#include <string>

class ft 
{
	public:
		virtual void calc();

};



class dft : public ft
{
	public:
		void calc();
};



class fft : public ft
{
	public:
		void calc();

};

#endif
