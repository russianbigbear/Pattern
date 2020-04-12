// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Recyclingfactory.h"
#include "Builder.h"

RecyclingFactory* RecyclingFactory::Instance = 0;
int RecyclingFactory::MaxPlatformCount = 0;

int main()
{
	cout << "----------------------Strategy------------------------" << endl;
	cout << "Separator:" << endl;
	MachineFactory* mf1 = new SeparatingMachineFactory();
	Machine* m1 = mf1->CreateOven();
	m1->Stats();
	
	m1->SetMode(new NonPaused());
	m1->DoStrategy();
	cout << endl;

	m1->SetMode(new SwitchTime());
	m1->DoStrategy();
	cout << endl;

	cout << "----------------------Command------------------------" << endl;
	RecyclingFactory* factory = RecyclingFactory::getInstance(1000);
	factory->addMachine(m1);
	factory->AddPlatform(new Platform(100));
	cout << endl;

	factory->Update();

	factory->RemovePlatform();
	cout << endl;

	factory->Update();

	cout << "----------------------Visitor------------------------" << endl;
	Waste* waste[3] = { new PlasticWaste(100, 40), new PaperWaste(100, 20), new BioWaste(100, 55) };
	PlasticVisitor* pv = new PlasticVisitor();
	PaperVisitor* pav = new PaperVisitor();

	cout << endl;
	for (int i = 0; i < 3; i++) {
		waste[i]->Need();
		waste[i]->accept(pv);
		waste[i]->accept(pav);
		cout << endl;
	}

	cout << endl;

	system("pause");
}

