#ifndef _PLATFORM
#define _PLATFORM
#include "Waste.h"
#include <conio.h>

#include "Machine.h"

/*Место платформы*/
class PlacePlatform
{
protected:
	Command* command;
	int PlaceCarrying;
	vector<PlacePlatform*> places;
	friend class PlaceIterator;

public:
	virtual bool AddWaste(Waste*) = 0;
	virtual bool DeleteWaste(Waste*) = 0;

	virtual int getPlaceCount() = 0;
	virtual int getPlaceCarrying() = 0;
	virtual int getPlaceSize() = 0;

	virtual PlacePlatform* getPlace(int) = 0;

	void Display();

	PlacePlatform& operator= (const PlacePlatform& placeplatform);
	bool operator == (const PlacePlatform& placeplatform);
	static bool Compirer(PlacePlatform* pp1, PlacePlatform* pp2);
};

class Platform;

/*Класс платформы*/
class Platform : public PlacePlatform
{
protected:
	int PlaceCount;
public:
	//Конструкторы и деструкторы
	Platform(int _place_count);
	~Platform();

	IIterator<PlacePlatform*>* CreateIterator();

	//Гетеры
	int getPlaceCount();
	int getPlaceCarrying();
	int getPlaceSize();
	PlacePlatform* getPlace(int index);

	//Сетеры
	void setPlaceCount(int _PlaceCount);
	void setPlaceCarrying(int _PlaceCarrying);

	bool AddWaste(Waste* _waste);
	bool DeleteWaste(Waste* _waste);

	void AddPlace(PlacePlatform* place);
	void DeletePlace(int index);
};

class SinglePlaceWaste : public PlacePlatform
{
protected:
	Waste* waste;
public:
	SinglePlaceWaste();
	SinglePlaceWaste(Waste* _waste);
	SinglePlaceWaste(int _placecarrying);

	bool AddWaste(Waste* _waste);
	bool DeleteWaste(Waste* _waste);

	int getPlaceSize();
	int getPlaceCount();
	int getPlaceCarrying();

	PlacePlatform* getPlace(int index);
};
#endif