#ifndef CONTATTO
#define CONTATTO
#include <string>
using namespace std;
class Contatto
{
public:
	Contatto(string a, string b, string c);
	void stampa();
	void cambia_nome(string a);
	void cambia_cognome(string a);
	void cambia_numero(string a);
private:
	string nome;
	string cognome;
	string num_telefono;
};
#endif // Contatto

