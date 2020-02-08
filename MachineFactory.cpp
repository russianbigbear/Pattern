#include "MachineFactory.h"

///Методы для класса RecyclingMachineFactory
Machine* RecyclingMachineFactory::CreateLine() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(1000);
	machine->setWasteCount(0);
	machine->setMaxSpeed(1000);
	machine->setSpeed(0);

	machine->recyclingAction = new Recycling();
	machine->burningAction = new NotBurning();
	machine->separatingAction = new NotSeparating();

	return machine;
}
Machine* RecyclingMachineFactory::CreateSeparator() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(1000);
	machine->setWasteCount(0);
	machine->setMaxSpeed(500);
	machine->setSpeed(0);

	machine->recyclingAction = new Recycling();
	machine->burningAction = new NotBurning();
	machine->separatingAction = new Separating();

	return machine;
}
Machine* RecyclingMachineFactory::CreateOven() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(1000);
	machine->setWasteCount(0);
	machine->setMaxSpeed(2000);
	machine->setSpeed(0);

	machine->recyclingAction = new Recycling();
	machine->burningAction = new Burning();
	machine->separatingAction = new NotSeparating();

	return machine;
}

///Методы для класса BurningMachineFactory
Machine* BurningMachineFactory::CreateLine() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(2500);
	machine->setWasteCount(0);
	machine->setMaxSpeed(1000);
	machine->setSpeed(0);

	machine->recyclingAction = new Recycling();
	machine->burningAction = new Burning();
	machine->separatingAction = new NotSeparating();

	return machine;
}
Machine* BurningMachineFactory::CreateSeparator() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(2500);
	machine->setWasteCount(0);
	machine->setMaxSpeed(500);
	machine->setSpeed(0);

	machine->recyclingAction = new NotRecycling();
	machine->burningAction = new Burning();
	machine->separatingAction = new NotSeparating();

	return machine;
}
Machine* BurningMachineFactory::CreateOven() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(2500);
	machine->setWasteCount(0);
	machine->setMaxSpeed(2500);
	machine->setSpeed(0);

	machine->recyclingAction = new NotRecycling();
	machine->burningAction = new Burning();
	machine->separatingAction = new NotSeparating();

	return machine;
}

///Методы для класса SeparatingMachineFactory
Machine* SeparatingMachineFactory::CreateLine() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(500);
	machine->setWasteCount(0);
	machine->setMaxSpeed(1000);
	machine->setSpeed(0);

	machine->recyclingAction = new Recycling();
	machine->burningAction = new NotBurning();
	machine->separatingAction = new Separating();

	return machine;
}
Machine* SeparatingMachineFactory::CreateSeparator() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(500);
	machine->setWasteCount(0);
	machine->setMaxSpeed(500);
	machine->setSpeed(0);

	machine->recyclingAction = new NotRecycling();
	machine->burningAction = new NotBurning();
	machine->separatingAction = new Separating();

	return machine;
}
Machine* SeparatingMachineFactory::CreateOven() {
	Machine* machine = new Machine();

	machine->ChangeStatement(MACHINE_OFF);
	machine->setCarryingWaste(500);
	machine->setWasteCount(0);
	machine->setMaxSpeed(1500);
	machine->setSpeed(0);

	machine->recyclingAction = new NotRecycling();
	machine->burningAction = new Burning();
	machine->separatingAction = new Separating();

	return machine;
}
