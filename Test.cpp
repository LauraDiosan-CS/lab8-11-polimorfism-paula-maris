#include "Test.h"
#include <assert.h>

Test::Test() {
}

void Test::runCSVTests()
{
	/*Angajat*/
	Repository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>("test3_ang.csv");
	((RepositoryFileCSV<Angajat>*)repoAng)->loadFromFile();	//incarcarea din fisier
	assert(repoAng->size() == 4);					//dimensiunea repo-ului
	
	Angajat a(9,"ludovic","hello@eu.com",5);			//crearea unui angajat
	repoAng->add(a);								//adaugarea unui angajat
	((RepositoryFileCSV<Angajat>*)repoAng)->saveToFile();		//salvarea in fisier

	assert(repoAng->findElem(a) == 4);					//pozitia elementului daca acesta se afla in repo

	Angajat a1(5,"wer","oop@poo",1);
	repoAng->update(a, a1);							//actualizarea unui angajat
	assert(repoAng->findElem(a1) == 4);
	assert(repoAng->findElem(a) == -1);
	assert(repoAng->size()==5);

	repoAng->remove(5);							//stergerea unui angajat
	assert(repoAng->size() == 4);
	((RepositoryFileCSV<Angajat>*)repoAng)->saveToFile();		//salvarea in fisier


	/*Medicament*/
	const char* fileNameMed = "test2_med.csv";
	Repository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>(fileNameMed);
	((RepositoryFileCSV<Medicament>*)repoMed)->loadFromFile();
	assert(repoMed->size() == 5);
	Medicament b(7, "tenox", 1, 109, "farma10");
	repoMed->add(b);
	((RepositoryFileCSV<Medicament>*)repoMed)->saveToFile();
	assert(repoMed->size() == 6);

	repoMed->remove(7);
	((RepositoryFileCSV<Medicament>*)repoMed)->saveToFile();
	assert(repoMed->size() == 5);

	assert(repoMed->findElem(b) == -1);
}

void Test::runTXTTests()
{
	/*Medicament*/
	Repository<Medicament>* repoMed = new RepositoryFileTXT<Medicament>("test_med.txt");
	((RepositoryFileTXT<Medicament>*)repoMed)->loadFromFile();
	assert(repoMed->size() == 5);	//getSize()

	Medicament z(16, "zenit", 1	, 16, "farmica");
	repoMed->add(z);	//adaugarea unui medicament
	((RepositoryFileTXT<Medicament>*)repoMed)->saveToFile();

	assert(repoMed->findElem(z) == 5);	//returnarea pozitiei daca elementul este gasit

	Medicament z1(11,"zenit",0,15,"farmica");
	repoMed->update(z, z1);									//actualizarea medicamentului
	assert(repoMed->findElem(z1) == 5);
	assert(repoMed->findElem(z) == -1);
	assert(repoMed->size() == 6);

	repoMed->remove(11);									//stergerea medicamentului
	((RepositoryFileTXT<Medicament>*)repoMed)->saveToFile();	//salvarea in fisier

	/*Angajat*/
	const char* fileNameAngajat = "test_ang.txt";
	Repository<Angajat>* repoAngajat = new RepositoryFileTXT<Angajat>(fileNameAngajat);
	((RepositoryFileTXT<Angajat>*)repoAngajat)->loadFromFile();	//incarcarea din fisier
	assert(repoAngajat->size() == 4);

	
	Angajat b(1, "ang1", "hello@bye", 2);
	repoAngajat->add(b);
	assert(repoAngajat->size() == 5);

	repoAngajat->remove(1);
	assert(repoAngajat->size() == 4);

}

void Test::runInMemoryTests()
{
	IRepository<User>* repoUseri = new RepositoryInMemory<User>();
	User u("Ana", "123");

	repoUseri->add(u);
	assert(repoUseri->size() == 1);
	assert(repoUseri->findElem(u) == 0);

}

void Test::runLiveTests()
{
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();

	Medicament m1(100, "parasinus", false, 10, "p1");
	Medicament m2(200, "ketonal", false, 90, "p2");
	Medicament m3(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().size() == 2);


	assert(repo->getAll()[0] == m1);
	assert(repo->getAll()[1] == m2);
	repo->add(m3);
	assert(repo->getAll()[2] == m3);

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, m1_new);
	assert(repo->getAll()[0] != m1);
	assert(repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getAll().size() == 2);
}

void Test::runTests()
{
	runCSVTests();
	runTXTTests();
	runInMemoryTests();
	runLiveTests();
}


Test::~Test(){
}
