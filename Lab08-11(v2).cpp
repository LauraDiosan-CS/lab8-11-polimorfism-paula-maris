// Lab08-11(v2).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Test.h"
#include "RepoFileCSV.h"
#include "IRepository.h"
#include "RepoFile.h"
#include "RepoFileTXT.h"
#include "RepositoryInMemory.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main() {
	
	cout << "start tests..." << endl;
	Test t;
	t.runTests();
	cout << "...succes!" << endl;

	cout << "De unde doriti sa cititi datele?\n";
	cout << "1. Fisiere TXT\n";
	cout << "2. Fisiere CSV\n";
	cout << endl;
	cout << "Introduceti optiunea: ";
	int opt;
	cin >> opt;
	cout << endl;
	if (opt == 1)
	{
		IRepository<Angajat>* repoAng = new RepositoryFileTXT<Angajat>("angajat.txt");
		((Repository<Angajat>*)repoAng)->loadFromFile();
		IRepository<Medicament>* repoMed = new RepositoryFileTXT<Medicament>("medicament.txt");
		((Repository<Medicament>*)repoMed)->loadFromFile();
		IRepository<User>* repoUser = new RepositoryInMemory<User>();
		Service s(repoMed, repoAng, repoUser);
		UI ui(s);
		ui.runUI();
	}
	else
		if (opt==2)
		{
			IRepository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>("ang.csv");
			((Repository<Angajat>*)repoAng)->loadFromFile();
			IRepository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>("med.csv");
			((Repository<Medicament>*)repoMed)->loadFromFile();
			IRepository<User>* repoUser = new RepositoryInMemory<User>();
			Service s(repoMed, repoAng, repoUser);
			UI ui(s);
			ui.runUI();
		}
	
	return 0;
}