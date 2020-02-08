#ifndef _MACHINE
#define _MACHINE
#include "Actions.h"
#include "Behaviour.h"
#include "Prototype.h"

const int MACHINE_ON = 1;
const int MACHINE_OFF = 0;
const int MACHINE_PAUSED = -1;

class Machine;
class Snapshot;

class Observer;
class SpeedRegulator;


/*�����������*/
class Observer
{
public:
	Observer() {}
	~Observer() {}
	virtual void Update() = 0;
};

/*�������*/
class Subject
{
public:
	Subject() {}
	virtual ~Subject() {}
	virtual void Attach(Observer* o) = 0;
	virtual void Detach(Observer* o) = 0;
	virtual void Notify() = 0;
};

/*����� ������*/
class WorkingMode {
public:
	virtual void DoStrategy() = 0;
};
/*����� ������ �� �������*/
class SwitchTime : public WorkingMode {
public:
	void DoStrategy();
};
/*��� ����*/
class NonPaused : public WorkingMode {
public:
	void DoStrategy();
};

/*����� ���������*/
class Statement : public Prototype<Statement> {
public:
	virtual void DoAction() = 0;
	virtual Statement* Clone() = 0;
};

/*��������*/
class StateOn : public Statement {
protected:
	Machine* machine;
public:
	StateOn(Machine* m);
	void DoAction();
	Statement* Clone();
};
/*���������*/
class StateOff : public Statement {
private:
	Machine* machine;
public:
	StateOff(Machine* m);
	void DoAction();
	Statement* Clone();
};
/*�� �����*/
class StatePaused : public Statement {
private:
	Machine* machine;
public:
	StatePaused(Machine* m);
	void DoAction();
	Statement* Clone();
};

/*�������*/
class Command {
protected:
	Machine* m;
public:
	virtual void Execute() = 0;
};
class CommandOn : public Command {
public:
	CommandOn(Machine* machine);
	void Execute();
};
class CommandOff : public Command {
public:
	CommandOff(Machine* machine);
	void Execute();
};

/*����� ��������� �����*/
class Machine : public Prototype<Machine>, public Subject{
protected:
	Observer* observer;
	Statement* statement;
	WorkingMode* mode;
	int CarryingWaste;
	int WasteCount;
	int MaxSpeed;
	int Speed;

public:
	IRecyclingAction* recyclingAction;
	IBurningAction* burningAction;
	ISeparatingAction* separatingAction;

	Machine();
	Machine(WorkingMode* _mode);
	~Machine();

	void Attach(Observer* o);
	void Detach(Observer* o);
	void Notify();

	//���������� ���������� �������� ������� ���������
	void performRecycling();
	void performBurning();
	void performSeparating();

	int getSpeed();
	int getMaxSpeed();
	int getWasteCount();
	int getCarryingWaste();

	void setSpeed(int Speed);
	void setMaxSpeed(int Speed);
	void setWasteCount(int WasteCount);
	void setCarryingWaste(int CarryingWaste);
	void SetMode(WorkingMode* _mode);

	void ChangeStatement(int _state);
	void ChangeStatement(Statement* _state);
	void ChangeSpeed(int _speed);
	void UpSpeed(int _speed);
	void DownSpeed(int _speed);
	void ChangeCarrying(int _cary);
	void ChangeWasteCount(int _wc);
	void UpWasteCount(int _wc);
	void DownWasteCount(int _wc);

	void Stats();
	virtual void DoAction();
	virtual void DoStrategy();
	virtual Snapshot* TakeSnapshot();
	Machine* Clone();
};

/*��������� ��������*/
class SpeedRegulator : public Observer
{
private:
	Machine* subject;
public:
	SpeedRegulator(Machine* m);
	~SpeedRegulator();
	void Update();
};

/*���������*/
class Snapshot {
private:
	Machine* snap;
	Statement* _statement;
	int _WasteCount;
	int _Speed;
	int _MaxSpeed;
public:
	Snapshot(Machine* m, Statement* s, int wc, int sp, int ms);
	void Restore();
};

/*������������(����������)*/
class Shreder
{
public:
	void Shred() { cout << "OK! I'm sred it..." << endl; }
};

/*������� ��� ISeparatingAction*/
class Adapter : public ISeparatingAction
{
private:
	Shreder* shreder;
public:
	void Separate() { shreder->Shred(); }
	Adapter() { shreder = new Shreder(); }
	~Adapter() { delete shreder; }

};
#endif
