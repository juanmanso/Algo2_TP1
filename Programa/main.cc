
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstdlib>

#include "cmdline.h"
#include "complejo.h"
#include "ft.h"
#include "proc.h"

using namespace std;

static void opt_input(string const &);
static void opt_output(string const &);
static void opt_forward-op(string const &);
static void opt_reverse-op(string const &);
static void opt_block-shift(string const &);
static void opt_taps(string const &);

// Tabla de opciones de línea de comando. El formato de la tabla
// consta de un elemento por cada opción a definir. A su vez, en
// cada entrada de la tabla tendremos:
//
// o La primera columna indica si la opción lleva (1) o no (0) un
//   argumento adicional.
// 
// o La segunda columna representa el nombre corto de la opción.
// 
// o Similarmente, la tercera columna determina el nombre largo.
// 
// o La cuarta columna contiene el valor por defecto a asignarle
//   a esta opción en caso que no esté explícitamente presente
//   en la línea de comandos del programa. Si la opción no tiene
//   argumento (primera columna nula), todo esto no tiene efecto.
//
// o La quinta columna apunta al método de parseo de la opción,
//   cuyo prototipo debe ser siempre void (*m)(string const &arg);
//
// o La última columna sirve para especificar el comportamiento a
//   adoptar en el momento de procesar esta opción: cuando la
//   opción es obligatoria, deberá activarse OPT_MANDATORY.
//
// Además, la última entrada de la tabla debe contener todos sus
// elementos nulos, para indicar el final de la misma.
//

//**************** Elementos globales ******************//
static option_t options[] = {
	{1, "i", "input", "-", opt_input, OPT_DEFAULT},
	{1, "o", "output", "-", opt_output, OPT_DEFAULT},
	{1, "f", "forward-op","fft",opt_forward-op, OPT_DEFAULT},
	{1, "r", "reverse-op","ifft",opt_reverse-op, OPT_DEFAULT},
	{1, "b", "block-shift","0",opt_block-shift, OPT_DEFAULT},
	{1, "t", "taps","1",opt_taps, OPT_DEFAULT},
	{0, "h", "help", NULL, opt_help, OPT_DEFAULT},
	{0, },
};

static istream *iss = 0;	// Input Stream (clase para manejo de los flujos de entrada)
static ostream *oss = 0;	// Output Stream (clase para manejo de los flujos de salida)
static fstream ifs; 		// Input File Stream (derivada de la clase ifstream que deriva de istream para el manejo de archivos)
static fstream ofs;		// Output File Stream (derivada de la clase ofstream que deriva de ostream para el manejo de archivos)


#define POS_I_OPT 0
#define POS_O_OPT 1
#define POS_F_OPT 2
#define POS_R_OPT 3
#define POS_B_OPT 4
#define POS_T_OPT 5
#define POS_HELP_OPT 6



//*****************************************************//

static void
opt_input(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la entrada
	// estándar. De lo contrario, abrimos un archivo en modo
	// de lectura.
	//
	if (arg == (options+POS_I_OPT)->def_value) {
		iss = &cin;		// Establezco la entrada estandar cin como flujo de entrada
	}
	else {
		ifs.open(arg.c_str(), ios::in); // c_str(): Returns a pointer to an array that contains a null-terminated
										// sequence of characters (i.e., a C-string) representing
										// the current value of the string object.
		iss = &ifs;
	}

	// Verificamos que el stream este OK.
	//
	if (!iss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}
}

static void
opt_output(string const &arg)
{
	// Si el nombre del archivos es "-", usaremos la salida
	// estándar. De lo contrario, abrimos un archivo en modo
	// de escritura.
	//
	if (arg == (options+POS_O_OPT)->def_value) {
		oss = &cout;	// Establezco la salida estandar cout como flujo de salida
	} 
	else {
		ofs.open(arg.c_str(), ios::out);
		oss = &ofs;
	}

	// Verificamos que el stream este OK.
	//
	if (!oss->good()) {
		cerr << "cannot open "
		     << arg
		     << "."
	     << endl;
		exit(1);		// EXIT: Terminación del programa en su totalidad
	}
}

static void
opt_forward-op(string const &arg)
{
	istringstream iss(arg);

// Hacer la función

	if(!(iss >> ft_method) || !iss.eof()) {
		cerr << "non-integer factor: "
		     << arg
		     << "."
		     << endl;
		exit(1);
	}

	if (iss.bad()) {
		cerr << "cannot read integer factor."
		     << endl;
		exit(1);
	}
}


static void
opt_help(string const &arg)
{
	cout << "tp1 [-i file] [-o file] [-f ft_method] [-r ift_method] [-b block-shift] [-t taps]"
	     << endl;
	exit(0);
}

	

int
main(int argc, char * const argv[])
{
	cmdline cmdl(options);	// Objeto con parametro tipo option_t (struct) declarado globalmente.
	cmdl.parse(argc, argv);	// Metodo de parseo de la clase cmdline
	proc(iss, oss);	// Procesamiento de la señal
}
