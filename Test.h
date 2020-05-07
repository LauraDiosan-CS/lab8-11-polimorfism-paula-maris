#pragma once
#include "RepoFile.h"
#include "RepoFileCSV.h"
#include "RepoFileTXT.h"
#include "RepositoryInMemory.h"
#include "Medicament.h"
#include "Angajat.h"
#include "User.h"

class Test
{
private:
	void runCSVTests();
	void runTXTTests();
	void runInMemoryTests();
	void runLiveTests();
public:
	Test();
	void runTests();
	~Test();
};