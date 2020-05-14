#include "ValidatorAngajat.h"
using namespace std;
#include <iostream>
#include <string.h>
#include <string>


ValidatorAngajat::ValidatorAngajat() 
{	
	err = 0;
	mesaj = "";
}


int ValidatorAngajat::validate(Angajat e, int contor)
{
	err = 0;
	mesaj = "";
	if (e.getNume() == "-") {
		err++; mesaj += "Numele nu trebuie sa fie vid! ";
	}
	if (e.getEmail() == "-") {
		err++; mesaj += "Emailul nu trebuie sa fie vid! ";
	}
	if (e.getId() < 1) {
		err++; mesaj += "ID-ul trebuie sa fie un numar pozitiv! ";
	}
	if (e.getGradAcces() < 1 ) {
		err++; mesaj += "Grad Acces trebuie sa fie un numar pozitiv! ";
	}
	if (contor != 0) {
		err++; mesaj += "ID-ul trebuie sa fie unic! ";
	}
	return err;
}

void ValidatorAngajat::showMesaj()
{
	if (mesaj != "")
	{
		cout << endl;
		cout << "--- ERORI ---: " << endl;
		cout << mesaj << endl;
		cout << endl;
	}
}

string ValidatorAngajat::toString() {
	return mesaj;
}


ValidatorAngajat::~ValidatorAngajat()
{
}