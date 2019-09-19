#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <typeinfo>
#include "Contatto.h"
using namespace std;
vector <string> nomi;
vector <string> cognomi; 
vector <string> numeri;
vector <Contatto> contatti;
vector <string> id;
vector <string> ::iterator n_itr;
vector <string> ::iterator c_itr;
vector <string> ::iterator num_itr;
vector <Contatto> ::iterator itr1;
int num;

bool find(vector <string> &x, string &a) {
	for (unsigned int i = 0; i < x.size(); i++) {
		if (a == x.at(i)) {
			return true;
			break;
		}
	}
	return false;
};

int max_lenght(vector <string> &x) {
	unsigned int max_size = 0;
	if (!x.empty()) {
		string y;
		if (x.size() == 1) {
			y = x.front();
			max_size = y.length();
		}
		else if (x.size() == 2) {
			if (x[0].length() >= x[1].length()) {
				y = x.at(0);
				max_size = y.length();
			}
			else {
				y = x.at(1);
				max_size = y.length();
			}
		}
		else {
			if (x[0].length() >= x[1].length()) {
				y = x.at(0);
				max_size = y.length();
			}
			else {
				y = x.at(1);
				max_size = y.length();
			}
			for (int i = 1; i != x.size(); i++) {
				if (x[i].length() >= max_size) {
					y = x.at(i);
					max_size = y.length();
				}
			}

		}
	};
	return max_size;
};

void stampa_contatti() {
	int l_id = 6;
	if (contatti.size() > 99) {
		int l_id = contatti.size() + 3;
	}
	int l_nomi = max_lenght(nomi) + 4 ;
	int l_cognomi = max_lenght(cognomi) + 4;
	int l_numeri = max_lenght(numeri) + 4;
	if (!contatti.empty()) {
		cout << setfill(' ') << setw(l_id) << "ID" << setw(l_nomi) << "NOME" << setw(l_cognomi) << "COGNOME" << setw(l_numeri) << "NUMERO" << endl;
		for (unsigned int i = 0; i < contatti.size(); i++) {
			cout << setfill(' ')<< setw(l_id) << i + 1 << setw(l_nomi) << 
				nomi[i] << setw(l_cognomi) << cognomi[i] << setw(l_numeri) << 
				numeri[i] << endl;
		};
	};
};

void Titolo() {
	cout << setfill('-') << setw(50) << "" << endl <<
	'|' << setfill(' ') << setw(15) << "" << "RUBRICA TELEFONICA" <<
	setfill(' ') << setw(15) << "" << '|' << endl <<
	setfill('-') << setw(50) << "" << endl << endl <<
	"a. CERCA CONTATTO" << endl << "b. CREA CONTATTO" << endl <<
	"c. ESCI" << endl << " SELEZIONA CONTATTO (digitare l'ID del contatto)"<<
	endl << endl;
	stampa_contatti();
	cout << endl << "Scegli una delle opzioni (a o b) : ";
};

void Seleziona(int idx) {
	int y = 0;
	system("cls");
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(14) << "" <<
		"CONTATTO SELEZIONATO" << setfill(' ') << setw(14) << "" << '|' << endl <<
		setfill('-') << setw(50) << "" << endl << "1. MODIFICA CONTATTO" <<
		endl << "2. ELIMINA CONTATTO" << endl << endl;
	contatti[idx].stampa();
	cout << endl << "Scegli una delle opzioni(1 o 2) : ";
	cin >> y;
	switch (y) {
	case 1: {
		string a, b, c;
		system("cls");
		cout << setfill('-') << setw(50) << "" << endl <<
			'|' << setfill(' ') << setw(15) << "" <<
			"MODIFICA CONTATTO " << setfill(' ') << setw(15) << "" << '|' << endl <<
			setfill('-') << setw(50) << "" << endl << "NOME: ";
		cin >> a;
		cout << "COGNOME: ";
		cin >> b;
		cout << "NUMERO DI TELEFONO: ";
		cin >> c;
		Contatto d(a, b, c);
		n_itr = nomi.erase(n_itr);
		c_itr = cognomi.erase(c_itr);
		num_itr = numeri.erase(num_itr);
		itr1 = contatti.erase(itr1);
		n_itr = nomi.insert(n_itr, a);
		c_itr = cognomi.insert(c_itr, b);
		num_itr = numeri.insert(num_itr, c);
		itr1 = contatti.insert(itr1, d);
		break;
		}
	case 2: {
			int a = 0;
			system("cls");
			cout << setfill('-') << setw(50) << "" << endl <<
				'|' << setfill(' ') << setw(16) << "" <<
				"ELIMINA CONTATTO " << setfill(' ') << setw(16) << "" << '|' << endl <<
				setfill('-') << setw(50) << "" << endl <<
				"Sei sicuro di voler eliminare questo contatto?" << endl << "1. Si'" << endl << "2. No" <<
				endl << endl << "Scegli una delle opzioni (1 o 2): ";
			cin >> a;
			switch (a) {
				case 1:
					nomi.erase(n_itr);
					cognomi.erase(c_itr);
					numeri.erase(num_itr);
					contatti.erase(itr1);
					break;
				case 2:
					break;
				}
		break;
		}
	}
};

void Aggiungi_contatto() {
	string a, b, c;
	system("cls");
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(17) << "" <<
		"CREA CONTATTO " << setfill(' ') << setw(17) << "" << '|' << endl <<
		setfill('-') << setw(50) << "" << endl << "NOME: ";
	cin >> a;
	cout <<"COGNOME: ";
	cin >> b;
	cout << "NUMERO DI TELEFONO: ";
	cin >> c;
	Contatto contatto(a, b, c);
	contatti.push_back(contatto);
	nomi.push_back(a);
	cognomi.push_back(b);
	numeri.push_back(c);
	id.push_back(to_string(contatti.size()));
};

void Ricerca(){
	string a, b, c;
	system("cls");
	cout << setfill('-') << setw(50) << "" << endl <<
		'|' << setfill(' ') << setw(20) << "" <<
	"RICERCA " << setfill(' ') << setw(20) << "" << '|' << endl <<
	 setfill('-') << setw(50) << "" << endl << "NOME: "; 
	cin >> a;
	cout << "COGNOME: ";
	cin >> b;
	cout << "NUMERO DI TELEFONO: ";
	cin >> c;
	n_itr = find(nomi.begin(), nomi.end(), a);
	c_itr = find(cognomi.begin(), cognomi.end(), b);
	num_itr = find(numeri.begin(), numeri.end(), c);
	if (n_itr != nomi.end() && c_itr != cognomi.end() && num_itr != numeri.end()) {
		int index = distance(nomi.begin(), n_itr);
		contatti[index].stampa();
		int a = 0;
		cout << endl << "1. SELEZIONA CONTATTO" << endl << "2. TORNA INDIETRO" << endl <<
			endl << "Scegli una delle opzioni (1 o 2): ";
		cin >> a;
		switch (a) {
		case 1:
		{n_itr = nomi.begin() + index;
		c_itr = cognomi.begin() + index;
		num_itr = numeri.begin() + index;
		itr1 = contatti.begin() + index;
		Seleziona(index);
		break;
		}
		case 2:
			break;
		}
	}
	else {
		cout << endl << "CONTATTO NON TROVATO" << endl;
		int a;
		cout << endl << "1. RIPROVA" << endl << "2. TORNA INDIETRO" << endl << 
			endl << "Scegli una delle opzioni (1 o 2): ";
		cin >> a;
		switch (a) {
		case 1:
			Ricerca();
			break;
		case 2:
			break;
		}
	}
};
int main(){
	string x;
	while (1) {
		Titolo();
		cin >> x;
		if (x == "a") {
			Ricerca();
			x = "0";
		}
		else if(x == "b"){
			Aggiungi_contatto();
			x = "0";
		}
		else if (x == "c") {
			exit(EXIT_SUCCESS);
		}
		else if (find(id, x) == true) {
			num = stoi(x);
			n_itr = nomi.begin() + num - 1 ;
			c_itr = cognomi.begin() + num - 1;
			num_itr = numeri.begin() + num - 1;
			itr1 = contatti.begin() + num - 1;
			Seleziona(num - 1);
		}
	system("cls");
	};
}