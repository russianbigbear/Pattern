#ifndef _BEHAVIOUR
#define _BEHAVIOUR
#include "Actions.h"

#include <iostream>
using namespace std;

/*��������������*/
//����� ��������� ��� �����, ������� �� ����� ��������������
class NotRecycling : public IRecyclingAction {
public:
	void Recycle() {
		cout << "I can't recycle waste!!!" << endl;
	}
};

//����� ��������� ��� �����, ������� ����� ��������������
class Recycling : public IRecyclingAction {
public:
	void Recycle() {
		cout << "Recycle waste..." << endl;
	}
};

/*�������*/
//����� ��������� ��� �����, ������� �� ����� ������� ������
class NotBurning : public IBurningAction {
public:
	void Burn() {
		cout << "I can't burn the waste!!!" << endl;
	}
};

//����� ��������� ��� �����, ������� ����� ������� ������
class Burning : public IBurningAction {
public:
	void Burn() {
		cout << "I burn waste..." << endl;
	}
};

/*���������*/
//����� ��������� ��� �����, ������� �� ����� ��������� �����
class NotSeparating : public ISeparatingAction {
public:
	void Separate() {
		cout << "I can't separate the waste!!!" << endl;
	}
};

//����� ��������� ��� �����, ������� ����� ��������� �����
class Separating : public ISeparatingAction {
public:
	void Separate() {
		cout << "I separate the waste..." << endl;
	}
};
#endif