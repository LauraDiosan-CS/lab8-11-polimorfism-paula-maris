#pragma once#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "Medicament.h"
#include "Angajat.h"
#include "User.h"
#include "Service.h"

class UI
{
private:
	Service serv;
public:
	UI();
	UI(Service serv);
	void login(bool& rez, string& username);
	void logout();

	void showMenu();
	void runUI();

	void addMed();
	void deleteMed();
	void updateMed();
	void findMed();

	void addAng();
	void deleteAng();
	void updateAng();
	void changeGrad(string username);

	void getAllMed();
	void getAllAng();

	~UI();
};
