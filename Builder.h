#ifndef _BUILDER
#define _BUILDER
#include "Machine.h"

template <class T>
class MachineBuilder {
protected:
	T* product;
public:
	virtual void Reset() = 0;
	virtual void SetStatement() = 0;
	virtual void SetSpeed() = 0;
	virtual void SetMaxSpeed() = 0;
	virtual void SetCarryingWaste() = 0;
	virtual void SetRecycling() = 0;
	virtual void SetBurning() = 0;
	virtual void SetSeparating() = 0;
	virtual T* GetProduct() = 0;
};
class ExpensiveLine: public MachineBuilder<Machine> {
private:
	Machine* product;
public:
	ExpensiveLine() { product = new Machine(); }
	void Reset() { delete product; product = new Machine(); }
	void SetStatement() { product->ChangeStatement(MACHINE_OFF); }
	void SetSpeed() { product->setSpeed(0); }
	void SetMaxSpeed() { product->setMaxSpeed(5000); }
	void SetCarryingWaste() { product->setCarryingWaste(10000); }
	void SetRecycling() { product->recyclingAction = new Recycling(); }
	void SetBurning() { product->burningAction = new NotBurning(); }
	void SetSeparating() { product->separatingAction = new NotSeparating(); }
	Machine* GetProduct() { return product; }
};
class FastSeparator : public MachineBuilder<Machine> {
private:
	Machine* product;
public:
	FastSeparator() { product = new Machine(); }
	void Reset() { delete product; product = new Machine(); }
	void SetStatement() { product->ChangeStatement(MACHINE_OFF); }
	void SetSpeed() { product->setSpeed(0); }
	void SetMaxSpeed() { product->setMaxSpeed(10000); }
	void SetCarryingWaste() { product->setCarryingWaste(500); }
	void SetRecycling() { product->recyclingAction = new NotRecycling(); }
	void SetBurning() { product->burningAction = new Burning(); }
	void SetSeparating() { product->separatingAction = new Separating(); }
	Machine* GetProduct() { return product; }
};
#endif