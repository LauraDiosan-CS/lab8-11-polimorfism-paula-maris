#pragma once
#include "Medicament.h"
#include "Exceptions.h"

class ValidatorMedicament 
{
private:
	int err;
	string mesaj;
public:
	ValidatorMedicament();
	int validate(Medicament, int);
	string toString();
	~ValidatorMedicament();
};