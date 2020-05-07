#pragma once
#include <ostream>
using namespace std;

class Angajat {
private:
	int id;
	int grad_acces;
	string nume;
	string email;
public:
	Angajat();
	Angajat(string, char);
	Angajat(int id, string nume, string email, int grad_acces);
	Angajat(const Angajat&);
	Angajat& operator=(const Angajat&);
	int getId();
	void setId(int id);
	int getGradAcces();
	void setGradAcces(int grad_acces);
	string getNume();
	void setNume(string nume);
	string getEmail();
	void setEmail(string email);
	bool operator==(const Angajat&);
	friend ostream& operator<<(ostream& os, const Angajat& p);
	friend istream& operator>>(istream& is, Angajat& p);
	void afisare();
	string toString();
	string toStringDelimiter(char delim);
	~Angajat();
};