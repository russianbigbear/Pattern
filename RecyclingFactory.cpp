// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "RecyclingFactory.h"

///Методы для класса RecyclingFactory 
RecyclingFactory::RecyclingFactory(int _Max){ this->MaxPlatformCount = _Max; }
RecyclingFactory* RecyclingFactory::getInstance() {
	if (!Instance)
		Instance = new RecyclingFactory();
	return Instance;
}
RecyclingFactory* RecyclingFactory::getInstance(int _Max) {
	if (!Instance)
		Instance = new RecyclingFactory(_Max);
	return Instance;
}

int RecyclingFactory::getMaxPlatformCount() { return this->MaxPlatformCount; }
vector<Platform*> RecyclingFactory::getPlatforms() { return this->Platforms; }
vector<Machine*> RecyclingFactory::getMachines() { return this->Machines; }

void RecyclingFactory::setPlatforms(vector<Platform*> _Platforms) { this->Platforms = _Platforms; }
void RecyclingFactory::setMachines(vector <Machine*> _Machines) { this->Machines = _Machines; }
void RecyclingFactory::setSpeedRegulator(SpeedRegulator* _sp) { this->sp = _sp; }
	
void RecyclingFactory::AddPlatform(Platform* p) {
	if (Platforms.size() < MaxPlatformCount) {		
		Platforms.push_back(p);
		cout << "OK! Platform added... " << endl;
	}
	else { cout << "ERROR! Not enough places for platforms..." << endl; }
}
void RecyclingFactory::RemovePlatform() {
	if (Platforms.size() != 0) {
		Platforms.pop_back();
		cout << "Ok! Platform removed..." << endl;		
	}
	else 
		cout << "ERROR! I don't have platform..." << endl;
}
void RecyclingFactory::addMachine(Machine* m) {
	Machines.push_back(m);
	cout << "OK! Machine added..." << endl;
}

void RecyclingFactory::Update() {
	if (command != nullptr)
		delete command;

	if (Platforms.size() > 0) {
		for (int i = 0; i < Machines.size(); i++) {
			command = new CommandOn(Machines[i]);
			command->Execute();
		}
	}
	else {
		for (int i = 0; i < Machines.size(); i++) {
			command = new CommandOff(Machines[i]);
			command->Execute();
		}
	}
}