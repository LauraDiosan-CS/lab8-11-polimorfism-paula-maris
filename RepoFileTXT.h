#pragma once
#include "RepoFile.h"
#include <fstream>
using namespace std;

template <class T> class RepositoryFileTXT :public Repository<T>
{
public:
	RepositoryFileTXT();
	RepositoryFileTXT(const char*);
	void loadFromFile();
	void saveToFile();
	void clearFromFile();
	~RepositoryFileTXT();
};


template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT()
{
}

template<class T>
inline RepositoryFileTXT<T>::RepositoryFileTXT(const char* fName) : Repository<T>(fName)
{
}

template<class T>
inline void RepositoryFileTXT<T>::loadFromFile()
{
	string line;
	ifstream f(Repository<T>::fileName);
	while (getline(f, line)) {
		T ob(line, ' ');
		IRepository<T>::elem.push_back(ob);
	}
}

template<class T>
inline void RepositoryFileTXT<T>::saveToFile()
{
	ofstream f(Repository<T>::fileName);
	for (T crt : IRepository<T>::elem) {
		f << crt.toStringDelimiter(' ') << endl;
	}
}

template<class T>
void RepositoryFileTXT<T>::clearFromFile()
{
	Repository<T>::clear();
}

template<class T>
inline RepositoryFileTXT<T>::~RepositoryFileTXT()
{
}
