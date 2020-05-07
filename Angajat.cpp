#include "Angajat.h"
#include <string.h>
#include <iostream>
#include <istream>
#include <cstddef>
#include <ostream>

#include "Utils.h"
#include <vector>
#include <string>
#include <sstream>

using namespace std;

//constructor implicit(fara param)
Angajat::Angajat() {
	this->nume = "";
	this->email = "";
	this->id = 0;
	this->grad_acces = 0;
}

Angajat::Angajat(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	id = stoi(tokens[0]);
	nume = tokens[1];
	email = tokens[2];
	grad_acces = stoi(tokens[3]);
}

//constructor cu parametri
Angajat::Angajat(int id, string nume, string email, int grad_acces) {
	/*this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->email = new char[strlen(email) + 1];
	strcpy_s(this->email, strlen(email) + 1, email);*/
	this->nume = nume;
	this->email = email;
	this->id = id;
	this->grad_acces = grad_acces;
}

//constructor de copiere
Angajat::Angajat(const Angajat& s) {
	/*this->nume = new char[strlen(s.nume) + 1];
	strcpy_s(this->nume, strlen(s.nume) + 1, s.nume);
	this->email = new char[strlen(s.email) + 1];
	strcpy_s(this->email, strlen(s.email) + 1, s.email);*/
	this->nume = s.nume;
	this->email = s.email;
	this->grad_acces = s.grad_acces;
	this->id = s.id;
}

//getter pentru id
int Angajat::getId() {
	return this->id;
}

//setter pentru id
void Angajat::setId(int c) {
	this->id = c;
}

//getter pentru grad acces
int Angajat::getGradAcces() {
	return this->grad_acces;
}

//setter pentru grad acces
void Angajat::setGradAcces(int grad_acces) {
	this->grad_acces = grad_acces;
}

//getter pentru nume
string Angajat::getNume() {
	return this->nume;
}

//setter pentru nume
void Angajat::setNume(string t) {
	/*if (nume) delete[]nume;
	nume = new char[strlen(t) + 1];
	strcpy_s(nume, strlen(t) + 1, t);*/
	nume = t;
}

//getter pentru email
string Angajat::getEmail() {
	return this->email;
}

//setter pentru email
void Angajat::setEmail(string t) {
	/*if (email) delete[]email;
	email = new char[strlen(t) + 1];
	strcpy_s(email, strlen(t) + 1, t);*/
	email = t;
}

//destructor
Angajat::~Angajat() {
	//if (nume) delete[]nume;
	nume = "";
	//if (email) delete[]email;
	email = "";
	id = -1;
	grad_acces = -1;
}

//suprascrie operatorul "=" pentru un element de nume Angajat
Angajat& Angajat::operator=(const Angajat& s) {
	this->setId(s.id);
	this->setNume(s.nume);
	this->setEmail(s.email);
	this->setGradAcces(s.grad_acces);
	return *this;
}

//operatorul de egalitate
bool Angajat::operator==(const Angajat& s) {
	return (id == s.id && grad_acces == s.grad_acces && nume == s.nume && email == s.email);
}

//afisare2
void Angajat::afisare() {
	cout << "ID: " << this->id << ", nume: " << this->nume << ", email: " << this->email << ", grad acces: " << this->grad_acces;
}

ostream& operator<<(ostream& os, const Angajat& p)
{
	cout << "ID: " << p.id << ", nume: " << p.nume << ", email: " << p.email << ", grad acces: " << p.grad_acces;
	return os;
}

istream& operator>>(istream& is, Angajat& p)
{
	/*if (p.email == NULL)
		p.email = new char[20];
	if (p.nume == NULL)
		p.nume = new char[20];*/
	is >> p.id >> p.nume >> p.email >> p.grad_acces;
	return is;
}

string Angajat::toString() {
	return to_string(id) + " " + nume + " " + email + " " + to_string(grad_acces);;
}

string Angajat::toStringDelimiter(char delim)
{
	return to_string(id) + delim + nume + delim + email + delim + to_string(grad_acces);;
}