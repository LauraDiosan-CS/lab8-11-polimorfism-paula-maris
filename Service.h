#pragma once
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "Medicament.h"
#include "Angajat.h"
#include "User.h"
#include "ValidatorAngajat.h"
#include "ValidatorMedicament.h"
#include "Exceptions.h"

class Service
{
private:
	IRepository<Medicament>* repoMed;
	IRepository<Angajat>* repoAng;
	IRepository<User>* repoUser;
	ValidatorAngajat valAng;
	ValidatorMedicament valMed;
public:
	Service();
	Service(IRepository<Medicament>*, IRepository<Angajat>*, IRepository<User>*);
	bool login(string, string);
	void logout(string, string);
	
	void add(Medicament);
	void addMed(int id, string nume, bool necesita_reteta, int nr_stoc, string producator);
	void validareMed(Medicament m);
	void deleteMed(Medicament&);
	void remove(int id);
	void update(Medicament&, Medicament&);
	vector<Medicament> search(string nume);

	void addAng(int id, string nume, string email, int grad_acces);
	void validareAng(Angajat a);
	void removeAng(int id);
	void deleteAng(Angajat&);
	void updateAng(Angajat&, Angajat&);
	void changeGrad(string nume_utilizator,int change_id, int change_grad_acces);
	//void buyTicket(string destinatie, string data, string ora, int nrLocuri);
	//int findAvailableSeats(string destinatie, string data, string ora);
	//int findSoldSeats(string destinatie, string data, string ora);
	vector<Medicament> getAllMed();
	vector<Medicament> getAll();
	vector<Angajat> getAllAng();
	//vector<Zbor> getAllFlightsToDestination(string destinatie);
	~Service();
};

