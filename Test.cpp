#include "Test.h"
#include <assert.h>
using namespace std;
#include <iostream>

Test::Test() {
}

void Test::runCSVTests()
{
	/*Angajat*/
	Repository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>("test3_ang.csv");
	((RepositoryFileCSV<Angajat>*)repoAng)->loadFromFile();
	assert(repoAng->size() == 4);

	Angajat a(9, "ludovic", "hello@eu.com", 5);
	repoAng->add(a);
	assert(repoAng->findElem(a) == 4);

	Angajat a1(5, "wer", "oop@poo", 1);
	repoAng->update(a, a1);
	assert(repoAng->findElem(a1) == 4);
	assert(repoAng->findElem(a) == -1);
	assert(repoAng->size() == 5);

	repoAng->deleteElem(a1);
	assert(repoAng->size() == 4);

	/*Medicament*/
	const char* fileNameMed = "test2_med.csv";
	Repository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>(fileNameMed);
	((RepositoryFileCSV<Medicament>*)repoMed)->loadFromFile();
	assert(repoMed->size() == 5);
	Medicament b(7, "tenox", 1, 109, "farma10");
	repoMed->add(b);
	((RepositoryFileCSV<Medicament>*)repoMed)->saveToFile();
	assert(repoMed->size() == 6);

	repoMed->deleteElem(b);
	((RepositoryFileCSV<Medicament>*)repoMed)->saveToFile();
	assert(repoMed->size() == 5);

	assert(repoMed->findElem(b) == -1);
}

void Test::runTXTTests()
{
	/*Medicament*/
	Repository<Medicament>* repoMed = new RepositoryFileTXT<Medicament>("test_med.txt");
	((RepositoryFileTXT<Medicament>*)repoMed)->loadFromFile();
	assert(repoMed->size() == 5);

	Medicament z(16, "zenit", 1, 16, "farmica");
	repoMed->add(z);
	((RepositoryFileTXT<Medicament>*)repoMed)->saveToFile();

	assert(repoMed->findElem(z) == 5);

	Medicament z1(11, "zenit", 0, 15, "farmica");
	repoMed->update(z, z1);
	assert(repoMed->findElem(z1) == 5);
	assert(repoMed->findElem(z) == -1);
	assert(repoMed->size() == 6);

	repoMed->remove(11);
	((RepositoryFileTXT<Medicament>*)repoMed)->saveToFile();

	/*Angajat*/
	const char* fileNameAngajat = "test_ang.txt";
	Repository<Angajat>* repoAngajat = new RepositoryFileTXT<Angajat>(fileNameAngajat);
	((RepositoryFileTXT<Angajat>*)repoAngajat)->loadFromFile();

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

void Test::runLoginTests()
{
	IRepository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>();
	IRepository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>();
	IRepository<User>* repoUser = new RepositoryInMemory<User>();

	User u1("Dana", "12");
	repoUser->add(u1);
	User u2("Maria", "23");
	repoUser->add(u2);

	Service s(repoMed, repoAng, repoUser);

	assert(s.login("Ana", "123") == true);		//deja s-a adaugat in User (in Service)
	assert(s.login("Maria", "23") == true);
	assert(s.login("Maria", "3") == false);
}

void Test::runServiceTests() 
{
	IRepository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>("");
	IRepository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>("");
	IRepository<User>* repoUser = new RepositoryInMemory<User>();

	Service s(repoMed, repoAng, repoUser);

	assert(s.getAllMed().size() == 0);
	assert(s.getAllAng().size() == 0);

	//CRUDURI:

	s.addMed(1, "paracetamol", 1, 13, "farma2");
	s.addMed(13, "live", 1, 13, "farma22");
	s.addMed(2, "panadol", 1, 13, "farma12");
	s.addMed(5, "pratre", 1, 13, "farma62");

	vector<Medicament> Meds = s.search("para");		//cautare medicamente care au un anumit string in nume
	assert(Meds.size() == 1);

	s.addAng(1, "je", "hello@hello", 2);
	Angajat b(3, "tu", "hello@hello", 3);
	s.addAng(3, "tu", "hello@hello", 3);
	assert(s.getAllAng().size() == 2);
	s.removeAng(3);
	assert(s.getAllAng().size() == 1);
	s.removeAng(1);
	assert(s.getAllAng().size() == 0);
}

void Test::runExceptionTests()
{
	IRepository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>("");
	IRepository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>("");
	IRepository<User>* repoUser = new RepositoryInMemory<User>();

	Service s(repoMed, repoAng, repoUser);

	assert(s.getAllAng().size() == 0);

	//Testare validari:
	ValidatorAngajat valAng;
	Angajat a(1, "-", "hello@hello", 2);
	if (valAng.validate(a,0) == 0)
		s.addAng(1, "-", "hello@hello", 2);
	//valAng.showMesaj();						//pentru a vedea care sunt erorile
	assert(s.getAllAng().size() == 0);			//nu adauga deoarece a aparut o eroare la validare 
	Angajat b(3, "tu", "hello@hello", 1);
	if (valAng.validate(b,0) == 0)
		s.addAng(3, "tu", "hello@hello", 1);
	valAng.showMesaj();							//nu are ce erori sa afiseze
	assert(s.getAllAng().size() == 1);			//acum se poate adauga un angajat nou
	Angajat b1(3, "been", "hello@hello", 41);
	if (valAng.validate(b1,1) == 0)
		s.addAng(3, "been", "hello@hello", 41); //eroare: ID-ul trebuie sa fie unic
	assert(s.getAllAng().size() == 1);			//nu s-a adaugat angajatul nou

	//Testare exceptii:
	try {
		Angajat a(1, "-", "c_b@yahoo.com", 2);
		s.validareAng(a);
		s.addAng(1, "-", "c_b@yahoo.com", 2);
	}
	catch (ValidationException& ex) {
		//cout << "Exceptii: " << ex.what() << endl;    //pentru a afisa eroarea
	}
	assert(s.getAllAng().size() == 1);

	//pentru Medicamente:
	assert(s.getAllMed().size() == 0);
	Medicament m1(1, "ddd", 0, 123, "f1");
	Medicament m2(13, "dad", 1, 123, "f13");
	Medicament m3(1, "did", 0, 13, "f4");
	try {
		s.validareMed(m1);
		s.addMed(1, "ddd", 0, 123, "f1");
		
	}
	catch (ValidationException & ex) {}
	assert(s.getAllMed().size() == 1);

	try {
		s.validareMed(m2);
		s.addMed(13, "dad", 1, 123, "f13");
	}
	catch (ValidationException & ex) {}
	assert(s.getAllMed().size() == 2);

	try {
		s.validareMed(m3);
		s.addMed(1, "did", 0, 13, "f4");
	}
	catch (ValidationException & ex) {}
	assert(s.getAllMed().size() == 2);		//id-ul trebuie sa fie unic, deci nu s-a mai adaugat
	
}

void Test::runLiveTests2()
{
	IRepository<Angajat>* repoAng = new RepositoryFileCSV<Angajat>("");
	IRepository<Medicament>* repoMed = new RepositoryFileCSV<Medicament>("");
	IRepository<User>* repoUser = new RepositoryInMemory<User>();

	Service service(repoMed, repoAng, repoUser);

	Medicament m1(100, "parasinus", false, 10, "p1");
	Medicament m2(200, "ketonal", false, 90, "p2");
	Medicament m3(300, "antibiotic", true, 70, "p3");

	service.add(m1);
	service.add(m2);
	assert(service.getAll().size() == 2);
	assert(service.getAll()[0] == m1);
	assert(service.getAll()[1] == m2);
	service.add(m3);
	assert(service.getAll()[2] == m3);

	assert(service.search("ic").size() == 1);
	assert(service.search("a").size() == 3);

	Medicament m1_new(100, "altceva", false, 50, "p1");
	service.update(m1, m1_new);
	assert(service.search("al").size() == 2);
	assert(service.search("al")[0] == m1_new);
	assert(service.search("al")[1] == m2);
	service.remove(200);
	assert(service.search("al").size() == 1);
	assert(service.search("al")[0] == m1_new);

}

void Test::runLiveTests1()
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
	runLiveTests1();
	runServiceTests();
	runExceptionTests();
	runLoginTests();
	runLiveTests2();
}


Test::~Test() {
}
