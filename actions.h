#ifndef _ACTIONS
#define _ACTIONS

#include <vector>
#include <iostream>
using namespace std;

/*Итератор*/
template <typename T>
class IIterator {
public:
	virtual T Next() = 0;
	virtual bool HasNext() = 0;
	virtual vector<T> SortCollection() = 0;
};

/*Переработка*/
class IRecyclingAction {
public:
	virtual void Recycle() = 0; // интерфейс не имеет реализации
};

/*Сжигание*/
class IBurningAction {
public:
	virtual void Burn() = 0; // интерфейс не имеет реализации
};

/*Разделение*/
class ISeparatingAction {
public:
	virtual void Separate() = 0; // интерфейс не имеет реализации
};

/*Изменение токсичности*/
class IChangeToxicity {
	virtual void EmitToxicity() = 0;
	virtual void RemoveToxicity() = 0;
	virtual void UpToxicity(int _num) = 0;
	virtual void DownToxicity(int _num) = 0;
};
#endif