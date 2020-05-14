#pragma once
#include <vector>
#include <algorithm>
using namespace std;

template <class T> class IRepository {
protected:
	vector<T> elem;
public:
	IRepository();
	void add(T&);
	int findElem(T&);
	T findElemFromId(int id);
	void update(T&, T&);
	int remove(int id);
	int deleteElem(T&);
	int size();
	vector<T> getAll();
};

template<class T>
inline IRepository<T>::IRepository(){
}

//Adaugarea unui element
//in: un obiect de tip T
//out: vectorul elem cu noul element adaugat
template<class T>
inline void IRepository<T>::add(T& e)
{
	elem.push_back(e);
}


//Actualizarea unui element
//in: un obiect de tip T
//out: vectorul elem cu elementul actualizat
template<class T>
inline void IRepository<T>::update(T& vechi, T& nou)
{
	std::replace(elem.begin(), elem.end(), vechi, nou);
}


//Stergerea unui element
//in: un obiect de tip T
//out: vectorul elem fara elementul sters
template<class T>
inline int IRepository<T>::deleteElem(T& e)
{
	auto last = std::remove(elem.begin(), elem.end(), e);
	if (last != elem.end()) {
		elem.erase(last, elem.end());
		return 0;
	}
	return -1;
}

template<class T>
inline int IRepository<T>::remove(int id)
{
	for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getId() == id)
		{
			elem.erase(elem.begin() + i);
			return 0;
		}
	}
	return -1;
}

//Aflarea unui element in repo
//in: un obiect de tip T
//out: returneaza pozitia daca acesta se afla in repo, -1 altfel
template<class T>
inline int IRepository<T>::findElem(T& e)
{
	auto it = std::find(elem.begin(), elem.end(), e);
	if (it != elem.end()) return distance(elem.begin(), it);
	return -1;
}


//Aflarea elementului dupa id
//in: id, int
//out: un element de tip Angajat
template<class T>
inline T IRepository<T>::findElemFromId(int id)
{
	/*for (int i = 0; i < elem.size(); i++) {
		if (elem[i].getId() == id)
			return elem[i];
	}
	return */
}


//Returnarea dimensiunii repo-ului
//in: -
//out: dimensiunea repo-ului
template<class T>
inline int IRepository<T>::size()
{
	return elem.size();
}


//getAll()
//in: -
//out: toate elementele de tip  T
template<class T>
inline vector<T> IRepository<T>::getAll()
{
	return elem;
}