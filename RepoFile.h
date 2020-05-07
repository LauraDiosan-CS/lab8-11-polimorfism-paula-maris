#pragma once
#include "IRepository.h"
template <class T> class Repository : public IRepository<T>
{

protected:
	const char* fileName;

public:
	Repository();
	Repository(const char*);
	virtual void saveToFile();
	virtual void loadFromFile();
	virtual void clearFromFile();
	void clear() {
		this->elem.clear();
	}
	~Repository();
};


template<class T>
Repository<T>::Repository() :IRepository<T>()
{
}

template<class T>
Repository<T>::Repository(const char* name)
{
	fileName = name;
}

template<class T>
Repository<T>::~Repository()
{
}

template<class T>
void Repository<T>::saveToFile()
{
}

template<class T>
void Repository<T>::loadFromFile()
{
}

template<class T>
void Repository<T>::clearFromFile()
{
}