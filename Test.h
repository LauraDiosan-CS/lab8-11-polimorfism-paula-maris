#pragma once
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "RepositoryInMemory.h"
#include "Medicament.h"
#include "Angajat.h"
#include "User.h"
#include "Service.h"
#include "ValidatorAngajat.h"
#include "ValidatorMedicament.h"
#include "Exceptions.h"

class Test
{
private:
	void runCSVTests();
	void runTXTTests();
	void runInMemoryTests();
	void runLiveTests1();
	void runServiceTests();
	void runExceptionTests();
	void runLoginTests();
	void runLiveTests2();
public:
	Test();
	void runTests();
	~Test();
};