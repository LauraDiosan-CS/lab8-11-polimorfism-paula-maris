#include "ValidatorMedicament.h"
#include <iostream>
using namespace std;

ValidatorMedicament::ValidatorMedicament()
{
	err = 0;
	mesaj = "";
}


int ValidatorMedicament::validate(Medicament e, int contor)
{
	err = 0;
	mesaj = "";
	if (e.getId() < 1) {
		err++; mesaj += "ID-ul trebuie sa fie un numar pozitiv! ";
	}
	if (e.getNume() == "-") {
		err++; mesaj += "Numele nu trebuie sa fie vid! ";
	}
	if (e.getProducator() == "-") {
		err++; mesaj += "Producatorul nu trebuie sa fie vid! ";
	}
	if (e.getNecesitaReteta() != 0 and e.getNecesitaReteta() != 1) {
		err++; mesaj += "La campul -necesita reteta- trebuie introdus doar 0(false) sau 1 (true)! ";
	}
	if (contor != 0) {
		err++; mesaj += "ID-ul trebuie sa fie unic! ";
	}
	return err;
}


string ValidatorMedicament::toString() {
	return mesaj;
}

ValidatorMedicament::~ValidatorMedicament(){
}