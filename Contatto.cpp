#include "Contatto.h"
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
Contatto::Contatto(string a, string b, string c)
{
	nome = a;
	cognome = b;
	num_telefono = c;
};
void Contatto::stampa() {
	cout << setfill(' ') << setw(nome.length() + 4) <<
		"NOME" << setw(cognome.length() + 4) << "COGNOME" <<
		setw(num_telefono.length() + 4) << "NUMERO" << endl;
	cout << setfill(' ') << setw(nome.length() + 4) <<
		nome << setw(cognome.length() + 4) << cognome <<
		setw(num_telefono.length() + 4) << num_telefono << endl;
};
void Contatto::cambia_nome(string a) {
	nome = a;
};
void Contatto::cambia_cognome(string a) {
	cognome = a;
};
void Contatto::cambia_numero(string a) {
	num_telefono = a;
};