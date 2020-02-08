#ifndef _WASTE
#define _WASTE
#include "Actions.h"
#include<string>

class PlasticWaste;
class PaperWaste;
class BioWaste;

class Visitor {
public:
	Visitor() {}
	virtual void visit(PaperWaste* paperw) {}
	virtual void visit(PlasticWaste* plasticw) {}
	virtual void visit(BioWaste* biow) {}
};

class PaperVisitor : public Visitor {
public:
	PaperVisitor() {}
	void visit(PaperWaste* paperw) {
		cout << "Paper waste can't have toxicity!!!" << endl;
	}
};

class PlasticVisitor : public Visitor {
public:
	PlasticVisitor() {}
	void visit(PlasticWaste* plasticw) {
		cout << "Plastic waste will be processed soon..." << endl;
	}
};

/*Класс отходов*/
class Waste : public IChangeToxicity
{
protected:
	string Name;
	int Mass;
	int Toxicity;

public:
	//Конструкторы и деструкторы
	Waste();
	Waste(int _mass, int _toxicity);

	//Гетеры
	int getMass();
	int getToxicity();
	string getName();

	//Сетеры
	void setMass(int _Mass);
	void setToxicity(int _Toxicity);
	void setName(string _Name);

	//Наследуемые от интерфейса методы
	virtual void EmitToxicity();
	virtual void RemoveToxicity();
	virtual void UpToxicity(int _num); 
	virtual void DownToxicity(int _num);

	//Переопределение операндов
	Waste& operator= (const Waste& waste);
	bool operator == (const Waste& waste);

	void Determine();
	virtual void Need() {
		cout << "We are not determinate toxicity!!!" << endl;
	}
	virtual void accept(Visitor* v) {}
};

/*Proxy для Waste*/
class ProxyWaste : public IChangeToxicity {
private:
	Waste* PWaste;
	void log();
public:
	ProxyWaste(int _mass, int _toxicity);
	~ProxyWaste();

	virtual void EmitToxicity();
	virtual void RemoveToxicity();
	virtual void UpToxicity(int _num);
	virtual void DownToxicity(int _num);
};

/*Конкретный класс "Пластиковые отходы"*/
class PlasticWaste : public Waste
{
public:
	PlasticWaste();
	PlasticWaste(int _mass, int _toxicity);
	void Determine();
	virtual void accept(Visitor* v) { v->visit(this); }
};

/*Конкретный класс "Бумажные отходы"*/
class PaperWaste : public Waste
{
public:
	PaperWaste();
	PaperWaste(int _mass, int _toxicity);
	void Determine();
	virtual void Need() {
		if (Toxicity > 30)
			cout << "Paper need down toxicity!!!" << endl;
		else if (Toxicity == 0)
			cout << "Paper haven't toxicity!!!" << endl;
		else
			cout << "Paper have toxicity!!!" << endl;
	}
	virtual void accept(Visitor* v) { v->visit(this); }
};

/*Конкретный класс "Биологические отходы"*/
class BioWaste : public Waste
{
public:
	BioWaste();
	BioWaste(int _mass, int _toxicity);
	void Determine();
	virtual void Need(){
		if (Toxicity > 50)
			cout << "Bio need down toxicity!!!" << endl;
		else if (Toxicity == 0)
			cout << "Bio haven't toxicity!!!" << endl;
		else
			cout << "Bio have toxicity!!!" << endl;
	}
};

/*Декоратор  "Смешанные отходы"*/
class MixedWaste : public Waste
{
protected:
	Waste* waste;
public:
	MixedWaste() {}
	MixedWaste(Waste* _waste) { waste = _waste; }
	virtual void Determine() = 0;
};

/*Конкретный декоратор "Смешанные с биологическими отходами"*/
class MixWithBio : public MixedWaste
{
public:
	virtual void Determine();
	void MixBio(string _type);
	MixWithBio(Waste* _waste) : MixedWaste(_waste) { Determine(); }
	~MixWithBio();
};

//Конкретный декоратор "Смешанные с бумажными отходами"
class MixWithPaper : public MixedWaste
{
public:
	virtual void Determine();
	void MixBio(string _type);
	MixWithPaper(Waste* _waste) : MixedWaste(_waste) { Determine(); }
	~MixWithPaper();
};

//Конкретный декоратор "Смешанные с пластиковыми отходами"
class MixWithPlastic : public MixedWaste
{
public:
	virtual void Determine();
	void MixBio(string _type);
	MixWithPlastic(Waste* _waste) : MixedWaste(_waste) { Determine(); }
	~MixWithPlastic();
};


#endif