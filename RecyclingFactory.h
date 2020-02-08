#ifndef _RECYCLINGFACTORY
#define _RECYCLINGFACTORY
#include "Platform.h"
#include "MachineFactory.h"
#include "Builder.h"

/*Основной класс "Перерабатывающая фабрика"*/
class RecyclingFactory
{
private:
	static int MaxPlatformCount;
	static RecyclingFactory* Instance;

	RecyclingFactory() : RecyclingFactory(100){}
	RecyclingFactory(int _Max);
protected:
	vector<Platform*> Platforms;
	vector<Machine*> Machines;
	SpeedRegulator* sp;
	Command* command;
public:
	static RecyclingFactory* getInstance();
	static RecyclingFactory* getInstance(int _Max);

	int getMaxPlatformCount();
	vector<Platform*> getPlatforms();
	vector<Machine*> getMachines();

	void setPlatforms(vector<Platform*> _Platforms);
	void setMachines(vector <Machine*> _Machines);
	void setSpeedRegulator(SpeedRegulator* _sp);
	void setCommand(Command* c) { command = c; }

	void addMachine(Machine* m);
	void AddPlatform(Platform* p);
	void RemovePlatform();

	void Update();
};


#endif