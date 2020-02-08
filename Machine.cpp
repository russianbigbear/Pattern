#include "Machine.h"

///Методы для класса StateOn
StateOn::StateOn(Machine* m) {
	machine = m;
}
void StateOn::DoAction() {
	cout << "I'm working! ";
}
Statement* StateOn::Clone() {
	return new StateOn(machine);
}

///Методы для класса StateOff
StateOff::StateOff(Machine* m) {
	machine = m;
	m->setSpeed(0);
}
void StateOff::DoAction() {
	cout << "I'm off! ";
}
Statement* StateOff::Clone() {
	return new StateOff(machine);
}

///Методы для класса StatePaused
StatePaused::StatePaused(Machine* m) {
	machine = m;
	m->setSpeed(0);
}
void StatePaused::DoAction() {
	cout << "I'm paused! ";
}
Statement* StatePaused::Clone() {
	return new StatePaused(machine);
}

///Методы для класса SwitchTime
void SwitchTime::DoStrategy() {
	cout << "Device On" << endl;
	cout << "Device working" << endl;
	cout << "...." << endl;
	cout << "...." << endl;
	cout << "...." << endl;
	cout << "Device paused" << endl;
	cout << "Device off" << endl;
}
///Методы для класса NonPaused
void NonPaused::DoStrategy() { cout << "Device working until it will be paused!" << endl;}

///Методы для класса CommandON
CommandOn::CommandOn(Machine* machine) {
	m = machine;
}
void CommandOn::Execute() {
	m->ChangeStatement(new StateOn(m));
	cout << "Machine ON..." << endl;
	m->Stats();
}

///Методы для класса CommandOFF
CommandOff::CommandOff(Machine* machine) {
	m = machine;
}
void CommandOff::Execute() {
	m->ChangeStatement(new StateOff(m));
	cout << "Machine OFF..." << endl;
	m->Stats();
}

///Методы для класса Machine
Machine::Machine() {
	statement = new StateOff(this);
	CarryingWaste = 0;
	WasteCount = 0;
	MaxSpeed = 0;
	Speed = 0;

	recyclingAction = nullptr;
	burningAction = nullptr;
	separatingAction = nullptr;
}
Machine::Machine(WorkingMode* _mode) {
	mode = _mode;
}
Machine::~Machine() {}

void Machine::Attach(Observer* o) { observer = o; }
void Machine::Detach(Observer* o) { observer = nullptr; }
void Machine::Notify() { observer->Update(); }

void Machine::performRecycling() { recyclingAction->Recycle(); }
void Machine::performBurning() { burningAction->Burn(); }
void Machine::performSeparating() { separatingAction->Separate(); }

int Machine::getSpeed() { return this->Speed; }
int Machine::getMaxSpeed() { return this->MaxSpeed; }
int Machine::getWasteCount() { return this->WasteCount; }
int Machine::getCarryingWaste() { return this->CarryingWaste; }

void Machine::setSpeed(int _Speed) { this->Speed = _Speed; }
void Machine::setMaxSpeed(int _MaxSpeed) { this->MaxSpeed = _MaxSpeed; }
void Machine::setWasteCount(int _WasteCount) { this->WasteCount = _WasteCount; }
void Machine::setCarryingWaste(int _CarryingWaste) { this->CarryingWaste = _CarryingWaste; }
void Machine::SetMode(WorkingMode* _mode) { this->mode = _mode; }

void Machine::ChangeStatement(int _state) {
	delete statement;
	switch (_state) {
	case MACHINE_ON: {
		statement = new StateOn(this);
		break; }
	case MACHINE_OFF: {
		statement = new StateOff(this);
		break; }
	case MACHINE_PAUSED: {
		statement = new StatePaused(this);
		break; }
	default: {
		cout << "Unknown state" << endl;
		break; }
	}
}
void Machine::ChangeStatement(Statement* _state) {
	delete statement;
	statement = _state;
}
void Machine::ChangeSpeed(int _speed) {
	this->Speed = _speed;
}
void Machine::UpSpeed(int _speed) {
	if (Speed <= MaxSpeed - _speed)
		Speed += _speed;
	else {
		Speed = MaxSpeed;
		cout << "Machine have maximum speed!!!" << endl;
	}
}	 
void Machine::DownSpeed(int _speed) {
	if(Speed - _speed >= 0)
		Speed -= _speed; 
	else {
		Speed = 0;
		cout << "Machine haven't speed!!!" << endl;
	}

}
void Machine::ChangeCarrying(int _cary) {
	this->CarryingWaste = _cary;
}
void Machine::ChangeWasteCount(int _wc) {
	this->WasteCount =_wc;
	Notify();
}
void Machine::UpWasteCount(int _wc) {
	this->WasteCount += _wc;
}
void Machine::DownWasteCount(int _wc) {
	this->WasteCount -= _wc;
}

void Machine::Stats() {
	cout << "Statement: "; statement->DoAction(); cout << endl;
	cout << "MaxSpeed: " << getMaxSpeed() << " Speed: " << getSpeed() << endl;;
	cout << "Carrying: " << this->CarryingWaste << " Waste count: " << this->WasteCount << endl;

	this->performRecycling();
	this->performBurning();
	this->performSeparating();

	cout << endl;
}
Machine* Machine::Clone() {
	cout << "I am clone." << endl;
	return this;
}
Snapshot* Machine::TakeSnapshot() {
return new Snapshot(this, statement->Clone(), getWasteCount(), getSpeed(), getMaxSpeed());
}

void Machine::DoAction() { statement->DoAction(); }
void Machine::DoStrategy() { mode->DoStrategy(); }

///Методы для класса Snapshot
Snapshot::Snapshot(Machine* m, Statement* s, int wc, int sp, int ms) {
	snap = m;
	_statement = s;
	_WasteCount = wc;
	_Speed = sp;
	_MaxSpeed = ms;
}
void Snapshot::Restore() {
	snap->ChangeStatement(_statement);
	snap->setWasteCount(_WasteCount);
	snap->setSpeed(_Speed);
	snap->setMaxSpeed(_MaxSpeed);
}

///Методы для класса SpeedRegulator
SpeedRegulator::SpeedRegulator(Machine* m) {
	subject = m;
	subject->Attach(this);
}
SpeedRegulator::~SpeedRegulator() {
	subject->Detach(this);
}
void SpeedRegulator::Update() {
	if (subject->getWasteCount() > subject->getCarryingWaste()) {
		subject->UpSpeed(subject->getMaxSpeed() - subject->getSpeed());
		cout << "Machine have maximum speed!!!" << endl;
	}
	else if (subject->getWasteCount() < subject->getCarryingWaste()) {
		if (subject->getSpeed() > subject->getWasteCount()) {
			subject->DownSpeed(subject->getSpeed() - subject->getWasteCount());
			cout << "Speed down!!!" << endl;
		}
		else {
			subject->UpSpeed(subject->getWasteCount() - subject->getSpeed());
			cout << "Speed up!!!" << endl;
		}
	}
	else {
		cout << "Machine have optimal speed...";
	}
}