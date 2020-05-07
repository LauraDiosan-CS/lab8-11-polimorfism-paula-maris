#pragma once
#include <ostream>
using namespace std;

class Medicament {
private:
	int id;
	bool necesita_reteta;
	string nume;
	string producator;
	int nr_stoc;
public:
	Medicament();
	Medicament(string, char);
	Medicament(int id, string nume, bool necesita_reteta, int nr_stoc, string producator);
	Medicament(const Medicament&);
	Medicament& operator=(const Medicament&);
	int getId();
	void setId(int id);
	string getNume();
	void setNume(string nume);
	int getNrStoc();
	void setNrStoc(int nr_stoc);
	string getProducator();
	void setProducator(string producator);
	void setNecesitaReteta(bool necesita_reteta);
	bool getNecesitaReteta();
	bool operator==(const Medicament&);
	bool operator!=(const Medicament&);
	friend ostream& operator<<(ostream& os, const Medicament& p);
	friend istream& operator>>(istream& is, Medicament& p);
	void afisare();
	string toString();
	string toStringDelimiter(char delim);
	~Medicament();
};