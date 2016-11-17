

#include "ft.h"
#include <string>
#include <iostream>

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

