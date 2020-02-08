#include "Recyclingfactory.h"
#include "Builder.h"

RecyclingFactory* RecyclingFactory::Instance = 0;
int RecyclingFactory::MaxPlatformCount = 0;

int main()
{
	cout << "----------------------Statement + Memento------------------------" << endl;
	cout << "Separator:" << endl;
	MachineFactory* mf1 = new SeparatingMachineFactory();
	Machine* m1 = mf1->CreateSeparator();
	m1->Stats();

	m1->ChangeStatement(MACHINE_ON);
	cout << "Original machine" << endl;
	m1->Stats();
	
	cout << "Change machine" << endl;
	Snapshot* ss = m1->TakeSnapshot();

	m1->ChangeWasteCount(100);
	m1->ChangeSpeed(5000);
	m1->ChangeStatement(MACHINE_PAUSED);
	m1->Stats();

	cout << "Restore machine: " << endl;
	ss->Restore();
	m1->Stats();

	system("pause");
}
