#ifndef _MACHINEFACTORY
#define _MACHINEFACTORY
#include "Machine.h"

class MachineFactory{
public:
	virtual Machine* CreateLine() = 0;
	virtual Machine* CreateSeparator() = 0;
	virtual Machine* CreateOven() = 0;
};
class RecyclingMachineFactory : public MachineFactory
{
public:
	Machine* CreateLine();
	Machine* CreateSeparator();
	Machine* CreateOven();
};
class BurningMachineFactory : public MachineFactory
{
public:
	Machine* CreateLine();
	Machine* CreateSeparator();
	Machine* CreateOven();
};
class SeparatingMachineFactory : public MachineFactory
{
public:
	Machine* CreateLine();
	Machine* CreateSeparator();
	Machine* CreateOven();
};
#endif