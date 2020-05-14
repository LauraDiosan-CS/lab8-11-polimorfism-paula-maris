#pragma once
#include "RepoFile.h"
#include <fstream>
using namespace std;

template  <class T> class RepositoryFileCSV :
	public Repository<T>
{
public:
	RepositoryFileCSV();
	RepositoryFileCSV(const char*);
	void loadFromFile();
	void saveToFile();
	void clearFromFile();
	~RepositoryFileCSV();
};
template<class T>
RepositoryFileCSV<T>::RepositoryFileCSV()
{
}

template<class T>
inline RepositoryFileCSV<T>::RepositoryFileCSV(const char* fName) :Repository<T>(fName)
{
}

template<class T>
void RepositoryFileCSV<T>::loadFromFile()
{
	string line;
	ifstream f(Repository<T>::fileName);
	//ifstream f(fileName);
	while (getline(f, line)) {
		T ob(line, ',');
		IRepository<T>::elem.push_back(ob);
	}
}

template<class T>
void RepositoryFileCSV<T>::saveToFile()
{
	ofstream f(Repository<T>::fileName);
	for (T crt : IRepository<T>::elem) {
		f << crt.toStringDelimiter(',') << endl;
	}
}

template<class T>
void RepositoryFileCSV<T>::clearFromFile()
{
	Repository<T>::clear();
}

template<class T>
RepositoryFileCSV<T>::~RepositoryFileCSV()
{
}