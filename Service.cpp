#include "Service.h"
#include "User.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

Service::Service(){
}

Service::Service(IRepository<Medicament>* repoMed, IRepository<Angajat>* repoAng, IRepository<User>* repoUser)
{
	this->repoMed = repoMed;
	this->repoAng = repoAng;
	this->repoUser = repoUser;
	User u1("Ana", "123");
	User u2("Ion", "345");
	User u3("Maria", "123");
	User u4("Mihai", "29");
	User u5("Dana", "222");
	User u6("Mara", "23");
	repoUser->add(u1);
	repoUser->add(u2);
	repoUser->add(u3);
	repoUser->add(u4);
	repoUser->add(u5);
}


// Returns a string of random alphabets of 
// length n. 
string printRandomString(int n)
{
	const int MAX = 26;
	char alphabet[MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
						  'h', 'i', 'j', 'k', 'l', 'm', 'n',
						  'o', 'p', 'q', 'r', 's', 't', 'u',
						  'v', 'w', 'x', 'y', 'z' };

	string res = "";
	for (int i = 0; i < n; i++)
		res = res + alphabet[rand() % MAX];

	return res;
}

void Service::random200Angajati() {

	int id = 0; string email; string nume; int grad_acces; string parola;
	
	for (int i = 0; i < 200; i++) {
		id = rand() % 100;
		grad_acces = rand() % 100;
		srand(time(NULL));
		nume = printRandomString(5);
		email = printRandomString(7);
		parola = "random";
		User u(nume, parola);
		repoUser->add(u);
		Angajat random(id,nume,email,grad_acces);
		addAng(id, nume, email, grad_acces);
	}
}


			//CRUD Medicament:

void Service::addMed(int id, string nume, bool necesita_reteta, int nr_stoc, string producator)
{
	try {
		Medicament e(id,nume,necesita_reteta,nr_stoc,producator);
		if (valMed.validate(e,0) == 0)
		{
			repoMed->add(e);
			((Repository<Medicament>*)repoMed)->saveToFile();
		}
	}
	catch (ValidationException & ex) {
		throw ex;
	}
}

void Service::add(Medicament a)
{
	try {
		if (valMed.validate(a, 0) == 0)
		{
			repoMed->add(a);
			((Repository<Medicament>*)repoMed)->saveToFile();
		}
	}
	catch (ValidationException & ex) {
		throw ex;
	}
}

void Service::deleteMed(Medicament& e)
{
	repoMed->deleteElem(e);
	((Repository<Medicament>*)repoMed)->saveToFile();
}

void Service::remove(int id)
{
	repoMed->remove(id);
	((Repository<Medicament>*)repoMed)->saveToFile();
}

void Service::update(Medicament &e, Medicament &new_e)
{
	repoMed->update(e, new_e);
	((Repository<Medicament>*)repoMed)->saveToFile();
}

vector<Medicament> Service::search(string nume)
{
	vector<Medicament> medList;
	vector<Medicament> Medicamente = repoMed->getAll();
	for (Medicament b : Medicamente) {
		if (b.getNume().find(nume) != string::npos)
			medList.push_back(b);
	}
	return medList;
}


void Service::validareAng(Angajat a) {
	bool ok = true;
	vector<Angajat> Ang = repoAng->getAll();
	for (int i = 0; i < Ang.size(); i++)
		if (Ang[i].getId() == a.getId())
			ok = false;
	int rez;
	if (ok == false)
		rez = valAng.validate(a,1);
	else
		rez = valAng.validate(a, 0);
	if (rez != 0)
		throw ValidationException(valAng.toString());
}

void Service::validareMed(Medicament m) {
	bool ok = true;
	vector<Medicament> Med = repoMed->getAll();
	for (int i = 0; i < Med.size(); i++)
		if (Med[i].getId() == m.getId())
			ok = false;
	int rez;
	if (ok == false)
		rez = valMed.validate(m, 1);
	else
		rez = valMed.validate(m, 0);

	if (rez != 0)
		throw ValidationException(valMed.toString());
}

			//CRUD Angajat:


void Service::addAng(int id, string nume, string email, int grad_acces)
{
	try {
		Angajat e(id, nume, email,grad_acces);
		if (valAng.validate(e,0) == 0)
		{
			repoAng->add(e);
			((Repository<Angajat>*)repoAng)->saveToFile();
		}
	}
	catch (ValidationException & ex) {
		throw ex;
	}
}

void Service::removeAng(int id)  //stergerea dupa id
{
	repoAng->remove(id);
	((Repository<Angajat>*)repoAng)->saveToFile();
}

void Service::deleteAng(Angajat& e)	//optionala
{
	repoAng->deleteElem(e);
	((Repository<Angajat>*)repoAng)->saveToFile();
}

void Service::updateAng(Angajat& e, Angajat& new_e)
{
	repoAng->update(e, new_e);
	((Repository<Angajat>*)repoAng)->saveToFile();
}


// LOGIN, LOGOUT:

bool Service::login(string u, string p)
{
	User usr(u, p);
	return repoUser->findElem(usr) != -1;
}

void Service::logout(string name, string pass)
{
	User u(name, pass);
	repoUser->deleteElem(u);
}


vector<Medicament> Service::getAllMed()
{
	return repoMed->getAll();
}

vector<Medicament> Service::getAll()
{
	return repoMed->getAll();
}

vector<Angajat> Service::getAllAng()
{
	return repoAng->getAll();
}


void Service::changeGrad(string nume_utilizator, int change_id, int change_grad_acces) 
{
	int grad_utilizator = 0; int grad_id = 0;
	int id; int grad_acces; string nume; string email;
	for (int i = 0; i < getAllAng().size(); i++)
	{
		if (getAllAng()[i].getNume() == nume_utilizator)
		{
			grad_utilizator = getAllAng()[i].getGradAcces();
		}
		if (getAllAng()[i].getId() == change_id)
		{
			grad_id = getAllAng()[i].getGradAcces();
			id = getAllAng()[i].getId();
			nume = getAllAng()[i].getNume();
			email = getAllAng()[i].getEmail();
		}
	}
	if (grad_utilizator > grad_id)
	{
		Angajat new_a(id, nume, email, change_grad_acces);
		Angajat a(id, nume, email, grad_id);
		updateAng(a, new_a);
	}
}


Service::~Service(){
}
