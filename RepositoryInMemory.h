#pragma once
#include "IRepository.h"
template <class T> class RepositoryInMemory :
	public IRepository<T>
{
public:
	RepositoryInMemory() :IRepository<T>() {};
	~RepositoryInMemory() {};
};