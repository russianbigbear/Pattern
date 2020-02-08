#ifndef _BEHAVIOUR
#define _BEHAVIOUR
#include "Actions.h"

#include <iostream>
using namespace std;

/*ПЕРЕРАБАТЫВАЕМ*/
//класс поведения для машин, которые НЕ МОГУТ перерабатывать
class NotRecycling : public IRecyclingAction {
public:
	void Recycle() {
		cout << "I can't recycle waste!!!" << endl;
	}
};

//класс поведения для машин, которые МОГУТ перерабатывать
class Recycling : public IRecyclingAction {
public:
	void Recycle() {
		cout << "Recycle waste..." << endl;
	}
};

/*СЖИГАЕМ*/
//класс поведения для машин, которые НЕ МОГУТ сжигать отходы
class NotBurning : public IBurningAction {
public:
	void Burn() {
		cout << "I can't burn the waste!!!" << endl;
	}
};

//класс поведения для машин, которые МОГУТ сжигать отходы
class Burning : public IBurningAction {
public:
	void Burn() {
		cout << "I burn waste..." << endl;
	}
};

/*РАЗДЕЛЯЕМ*/
//класс поведения для машин, которые НЕ МОГУТ разделять мусор
class NotSeparating : public ISeparatingAction {
public:
	void Separate() {
		cout << "I can't separate the waste!!!" << endl;
	}
};

//класс поведения для машин, которые МОГУТ разделять мусор
class Separating : public ISeparatingAction {
public:
	void Separate() {
		cout << "I separate the waste..." << endl;
	}
};
#endif