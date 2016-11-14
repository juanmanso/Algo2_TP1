#ifndef _FT_H_INCLUDED_
#define _FT_H_INCLUDED_


// Aquí se debe definir la clase ft, la cual será abstracta. Ésta se encarga
// de indicar el método de cálculo a utilizar (i.e. DFT, FFT).
//
// Asímismo, se deben definir las clases "hijas" como DFT y FFT.

#include <string>

using namespace std;

#define AMOUNT_OF_F_METHODS 6
#define AMOUNT_OF_R_METHODS 2

static string FT_FLAGS[AMOUNT_OF_F_METHODS]={"dft","idft","fft","ifft","fft-iter","ifft-iter"};
static string IFT_FLAGS[AMOUNT_OF_R_METHODS]={"idft","ifft"};


class ft 
{
	public:
		virtual void calc()=0;
};



class dft : public ft
{
	public:
		virtual void calc()
		{
		       	cout<<"dft"<<endl;
		}
		dft(){}
		~dft(){}
};



class idft : public ft
{
	public:
		virtual void calc()
		{
		       	cout<<"idft"<<endl;
		}

		idft(){}
		~idft(){}
};



class fft : public ft
{
	public:
		virtual void calc()
		{
		       	cout<<"fft"<<endl;
		}
		fft(){}
		~fft(){}

};


#endif
