#ifndef _ACTIONS
#define _ACTIONS

#include <vector>
#include <iostream>
using namespace std;

/*��������*/
template <typename T>
class IIterator {
public:
	virtual T Next() = 0;
	virtual bool HasNext() = 0;
	virtual vector<T> SortCollection() = 0;
};

/*�����������*/
class IRecyclingAction {
public:
	virtual void Recycle() = 0; // ��������� �� ����� ����������
};

/*��������*/
class IBurningAction {
public:
	virtual void Burn() = 0; // ��������� �� ����� ����������
};

/*����������*/
class ISeparatingAction {
public:
	virtual void Separate() = 0; // ��������� �� ����� ����������
};

/*��������� �����������*/
class IChangeToxicity {
	virtual void EmitToxicity() = 0;
	virtual void RemoveToxicity() = 0;
	virtual void UpToxicity(int _num) = 0;
	virtual void DownToxicity(int _num) = 0;
};
#endif