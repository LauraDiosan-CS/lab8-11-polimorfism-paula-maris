#include "Medicament.h"
#include <string.h>
#include <istream>
#include <cstddef>
#include <ostream>

#include "Utils.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;



//constructor implicit(fara param)
Medicament::Medicament() {
	this->nume = "";
	this->producator = "";
	this->id = 0;
	this->nr_stoc = 0;
	this->necesita_reteta = true;
}

Medicament::Medicament(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	id = stoi(tokens[0]);
	nume = tokens[1];
	
	necesita_reteta = stoi(tokens[2]);
	nr_stoc = stoi(tokens[3]);
	producator = tokens[4];
}

//constructor cu parametri
Medicament::Medicament(int id, string nume, bool necesita_reteta, int nr_stoc, string producator) {
	this->nume = nume; 
	this->producator = producator;
	this->id = id;
	this->nr_stoc = nr_stoc;
	this->necesita_reteta = necesita_reteta;
}

//constructor de copiere
Medicament::Medicament(const Medicament& s) {
	this->nume = s.nume;
	this->producator = s.producator;
	this->nr_stoc = s.nr_stoc;
	this->necesita_reteta = s.necesita_reteta;
	this->id = s.id;
}

//getter pentru id
int Medicament::getId() {
	return this->id;
}

//setter pentru id
void Medicament::setId(int c) {
	this->id = c;
}

//getter pentru numar stoc
int Medicament::getNrStoc() {
	return this->nr_stoc;
}

//setter pentru numar stoc
void Medicament::setNrStoc(int nr_stoc) {
	this->nr_stoc = nr_stoc;
}

//getter pentru nume
string Medicament::getNume() {
	return this->nume;
}

//setter pentru nume
void Medicament::setNume(string t) {
	nume = t;
}

//getter pentru producator
string Medicament::getProducator() {
	return this->producator;
}

//setter pentru producator
void Medicament::setProducator(string t) {
	producator = t;
}

//setter pentru necesita reteta
void Medicament::setNecesitaReteta(bool necesita_reteta) {
	this->necesita_reteta = necesita_reteta;
}

//getter pentru necesita reteta
bool Medicament::getNecesitaReteta() {
	return this->necesita_reteta;
}


//destructor
Medicament::~Medicament() {
	nume = "";
	producator = "";
	necesita_reteta = false;
	id = -1;
	nr_stoc = -1;
}

//suprascrie operatorul "=" pentru un element de nume Medicament
Medicament& Medicament::operator=(const Medicament& s) {
	this->setId(s.id);
	this->setNume(s.nume);
	this->setProducator(s.producator);
	this->setNrStoc(s.nr_stoc);
	this->setNecesitaReteta(s.necesita_reteta);
	return *this;
}

//operatorul de egalitate
bool Medicament::operator==(const Medicament& s) {
	return (id == s.id && nr_stoc == s.nr_stoc && nume == s.nume && producator == s.producator);
}

//operatorul de diferit
bool Medicament::operator!=(const Medicament& s) {
	return (id != s.id || nr_stoc != s.nr_stoc || nume != s.nume || producator != s.producator);
}

//afisare2
void Medicament::afisare() {
	cout << "ID: " << this->id << ", nume: " << this->nume << ", necesita reteta: " << this->necesita_reteta << ", numar stoc: " << this->nr_stoc << ", producator: " << this->producator;
}

string Medicament::toString() {
	return to_string(id) + " " + nume + " " + to_string(necesita_reteta) + " " + to_string(nr_stoc) + " " + producator;;
}

string Medicament::toStringDelimiter(char delim)
{
	return to_string(id) + delim + nume + delim + to_string(necesita_reteta) + delim + to_string(nr_stoc) + delim + producator;;
}

ostream& operator<<(ostream& os, const Medicament& p)
{
	cout << "ID: " << p.id << ", nume: " << p.nume << ", necesita reteta: " << p.necesita_reteta << ", numar stoc: " << p.nr_stoc << ", producator: " << p.producator;
	return os;
}

istream& operator>>(istream& is, Medicament& p)
{
	is >> p.id >> p.nume >> p.necesita_reteta >> p.nr_stoc >> p.producator;
	return is;
}