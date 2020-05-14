#include "UI.h"
#include "User.h"
#include <string>
#include <iostream>
using namespace std;


UI::UI() {
}

UI::UI(Service serv)
{
	this->serv = serv;
}


//CRUD Medicament:

void UI::addMed()
{
	int id; int nr_stoc; bool necesita_reteta; string nume; string producator;
	try {
		cout << "ID: "; cin >> id;
		cout << "Nume: "; cin >> nume;
		cout << "Necesita reteta (0/1): "; cin >> necesita_reteta;
		cout << "Nr stoc: "; cin >> nr_stoc;
		cout << "Producator: "; cin >> producator;
		Medicament a(id, nume, necesita_reteta, nr_stoc, producator);
		serv.validareMed(a);
		serv.addMed(id, nume, necesita_reteta, nr_stoc, producator);
		cout << "Adaugare medicament cu succes!" << endl;
	}
	catch (ValidationException & ex) {
		cout << "Exceptii: " << ex.what() << endl;
	}
}

void UI::deleteMed()
{
	cout << "Dati id-ul medicamentului pe care doriti sa il stergeti: ";
	int id;
	cin >> id;
	serv.remove(id);
}


void UI::updateMed()
{
	cout << "Dati id-ul medicamentului de actualizat: ";
	int new_id; int new_nr_stoc; bool new_nec_reteta; string new_producator; string nume;
	cin >> new_id;
	Medicament old_med;
	for (int i = 0; i < serv.getAllMed().size(); i++)
		if (new_id == serv.getAllMed()[i].getId())
			old_med = serv.getAllMed()[i];
	cout << "Dati noul nume: "; cin >> nume;
	cout << "Necesita reteta (0/1): "; cin >> new_nec_reteta;
	cout << "Nr stoc: "; cin >> new_nr_stoc;
	cout << "Noul producator: "; cin >> new_producator;
	Medicament new_med(new_id, nume, new_nec_reteta, new_nr_stoc, new_producator);
	serv.update(old_med, new_med);
}

void UI::findMed()
{
	cout << "Dati numele de medicament pe care doriti sa-l gasiti: ";
	string nume;
	cin >> nume;
	vector<Medicament> findMed = serv.search(nume);
	for (Medicament m : findMed)
	{
		m.afisare();
		cout << endl;
	}
}


//CRUD Angajat:

void UI::addAng()
{
	int id; int grad_acces; string nume; string email;
	try {
		cout << "ID: "; cin >> id;
		cout << "Nume: "; cin >> nume;
		cout << "Email: "; cin >> email;
		cout << "Grad Acces: "; cin >> grad_acces;
		Angajat a(id, nume, email, grad_acces);
		serv.validareAng(a);
		serv.addAng(id, nume, email, grad_acces);
		cout << "Adaugare angajat cu succes!" << endl;
	}
	catch (ValidationException& ex) {
		cout << "Exceptii: " << ex.what() << endl;
	}
}


void UI::deleteAng()
{
	cout << "Dati id-ul angajatului pe care doriti sa il stergeti: ";
	int id;
	cin >> id;
	serv.removeAng(id);
}

void UI::updateAng()
{
	cout << "Dati id-ul angajatului de actualizat: ";
	int new_id; int new_grad_acces; string new_email; string nume;
	cin >> new_id;
	Angajat old_ang;
	for (int i = 0; i < serv.getAllAng().size(); i++)
		if (new_id == serv.getAllAng()[i].getId())
			old_ang = serv.getAllAng()[i];
	cout << "Dati noul nume: "; cin >> nume;
	cout << "Noul email: "; cin >> new_email;
	cout << "Grad acces: "; cin >> new_grad_acces;
	Angajat new_ang(new_id, nume, new_email, new_grad_acces);
	serv.updateAng(old_ang, new_ang);
}

void UI::changeGrad(string username)
{
	string nume = username;
	cout << "Dati id-ul angajatului caruia doriti sa ii modificati gradul de acces: ";
	int id;
	cin >> id;
	cout << "Dati noul grad de acces: ";
	int new_grad;
	cin >> new_grad;
	serv.changeGrad(nume, id, new_grad);
}


void UI::login(bool &rez, string& username)
{
	cout << "--->LOGIN: " << endl;
	cout << "Username: ";
	cin >> username;
	string parola;
	cout << "Parola: ";
	cin >> parola;
	rez = serv.login(username, parola);
}

void UI::logout()
{
	/*cout << "--->LOGOUT: " << endl;
	cout << "Username: ";
	string username;
	cin >> username;
	string parola;
	cout << "Parola: ";
	cin >> parola;
	serv.logout(username, parola);*/
}


void UI::getAllMed()
{
	for (int i = 0; i < serv.getAllMed().size(); i++)
	{
		cout << i + 1 << ".) ";
		serv.getAllMed()[i].afisare();
		cout << endl;
	}
	cout << endl;
}

void UI::getAllAng()
{
	for (int i = 0; i < serv.getAllAng().size(); i++)
	{
		cout << i + 1 << ".) ";
		serv.getAllAng()[i].afisare();
		cout << endl;
	}
	cout << endl;
}

void UI::showMenu() {
	cout << endl;
	cout << endl;
	cout << "       >---MENIU---<\n";
	cout << endl;
	cout << "......Medicamente.....\n";
	cout << "1. Adaugare medicament\n";
	cout << "2. Stergere medicament\n";
	cout << "3. Update medicament\n";
	cout << "4. Gasire medicament dupa nume\n";
	cout << "......Angajati.....\n";
	cout << "5. Adaugare angajat\n";
	cout << "6. Stergere angajat\n";
	cout << "7. Update angajat\n";
	cout << "8. Modificare grad acces\n";
	cout << "10. Afisare medicamente\n";
	cout << "11. Afisare angajati\n";
	cout << "13. Logout\n";
	cout << "15. Exit\n";
	cout << endl;
}

void UI::runUI()
{
	bool k = true;
	bool rez; string username = "";
	login(rez,username);
	if (rez) {
		cout << "Autentificare cu succes!" << endl;
		while (k)
		{
			showMenu();
			int option = 0;
			cout << "Alegeti optiunea: ";
			cin >> option;
			if (option == 1)
			{
				addMed();
				continue;
			}
			if (option == 2) {
				deleteMed();
				continue;
			}
			if (option == 3) {
				updateMed();
				continue;
			}
			if (option == 4) {
				findMed();
				continue;
			}
			if (option == 5)
			{
				addAng();
				continue;
			}
			if (option == 6) {
				deleteAng();
				continue;
			}
			if (option == 7) {
				updateAng();
				continue;
			}
			if (option == 8) {
				changeGrad(username);
				continue;
			}
			if (option == 10) {
				getAllMed();
				continue;
			}
			if (option == 11) {
				getAllAng();
				continue;
			}
			if (option == 13) {
				logout();
				//k = false;
				login(rez, username);
			}
			if (option == 15) {
				k = false;
			}
		}
	}
	else
		cout << "User sau parola incorecte..." << endl;
} 

UI::~UI() {
}
