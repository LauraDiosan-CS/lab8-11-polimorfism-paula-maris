#pragma once
#include "Angajat.h"
#include "Exceptions.h"
#include "IRepository.h"
#include "RepoFile.h"

class ValidatorAngajat 
{
private:
	int err;
	string mesaj;
public:
	ValidatorAngajat();
	int validate(Angajat, int contor);
	void showMesaj();
	string toString();
	~ValidatorAngajat();
};