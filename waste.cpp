// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "Waste.h"

///������ ��� ������ Waste
Waste::Waste() {
	Determine();
	this->Mass = 0;
	this->Toxicity = 0;
}
Waste::Waste(int _mass, int _toxicity) {
	Determine();
	this->Mass = _mass;
	this->Toxicity = _toxicity;
}

//������
int Waste::getMass() { return this->Mass; }
int Waste::getToxicity() { return this->Toxicity; }
string Waste::getName() { return this->Name; }

void Waste::setToxicity(int _Toxicity) { this->Toxicity = _Toxicity; }
void Waste::setName(string _Name) { this->Name = _Name; }
void Waste::setMass(int _Mass) { this->Mass = _Mass; }

void Waste::EmitToxicity() {
	if (Toxicity < 100) { Toxicity = 100; }
	else { cout << "I have maximum toxicity!!!\n"; }
	cout << "I'm emited... Toxicity = [" << Toxicity << "]\n";
}
void Waste::RemoveToxicity() {
	if (Toxicity > 0) { Toxicity = 0; }
	else { cout << "I haven minimum toxicity!!!\n"; }
	cout << "I'm removed toxicity... Toxicity = [" << Toxicity << "]\n";
}
void Waste::UpToxicity(int _num) {
	if (Toxicity < 100 && _num <= (100 - Toxicity)) { Toxicity += _num; }
	else { cout << "I'm not raisedtoxicity!!!\n"; }
	cout << "I'm raised toxicity... Toxicity = [" << Toxicity << "]\n";
}
void Waste::DownToxicity(int _num) {
	if (Toxicity > 0 && _num <= (Toxicity)) { Toxicity -= _num; }
	else { cout << "I'm not lowered toxicity!!!\n"; }
	cout << "I'm lowered toxicity... Toxicity = [" << Toxicity << "]\n";
}

void Waste::Determine() {
	this->Name = "Waste";
}

//��������������� ���������
Waste& Waste::operator= (const Waste& waste) {
	Name = waste.Name;
	Mass = waste.Mass;
	Toxicity = waste.Toxicity;

	return *this;
}
bool Waste::operator == (const Waste& waste) {
	return Name == waste.Name;
}

///������ ��� ������ ProxyWaste
void ProxyWaste::log() {
	cout << "I'AM PROXY_WASTE!\nPrimary Toxicity = [" << PWaste->getToxicity() << "]\n";
}
ProxyWaste::ProxyWaste(int _mass, int _toxicity) {
	PWaste = new Waste(_mass, _toxicity);
}
ProxyWaste::~ProxyWaste() {
	delete PWaste;
}
void ProxyWaste::EmitToxicity() { log(); PWaste->EmitToxicity(); }
void ProxyWaste::RemoveToxicity() { log(); PWaste->RemoveToxicity(); }
void ProxyWaste::UpToxicity(int _num) { log(); PWaste->UpToxicity(_num); }
void ProxyWaste::DownToxicity(int _num) { log(); PWaste->DownToxicity(_num); }

///������ ��� ������ PlasticWaste
PlasticWaste::PlasticWaste() {
	Determine();
	this->Mass = 100;
	this->Toxicity = 30;
}
PlasticWaste::PlasticWaste(int _mass, int _toxicity) {
	Determine();
	this->Mass = _mass;
	UpToxicity(_toxicity);
}
void PlasticWaste::Determine() {
	this->Name = "Plastic";
}

///������ ��� ������ PaperWaste
PaperWaste::PaperWaste() {
	Determine();
	this->Mass = 60;
	this->Toxicity = 0;
}
PaperWaste::PaperWaste(int _mass, int _toxicity) {
	Determine();
	this->Mass = _mass;
	UpToxicity(_toxicity);
}
void PaperWaste::Determine() {
	this->Name = "Paper";
}

///������ ��� ������ BioWaste
BioWaste::BioWaste() {
	Determine();
	this->Mass = 150;
	this->Toxicity = 80;
}
BioWaste::BioWaste(int _mass, int _toxicity) {
	Determine();
	this->Mass = _mass;
	UpToxicity(_toxicity);
}
void BioWaste::Determine() {
	this->Name = "Bio";
}

///������ ��� ������ MixWithBio
void MixWithBio::Determine() {
	string type;

	if (*waste == PlasticWaste()) {
		type = "BioPlastic";
	}
	else if (*waste == PaperWaste()) {
		type = "BioPaper";
	}
	else if (waste->getName() == "BioPlastic" || waste->getName() == "BioPaper" || waste->getName() == "PaperPlastic") {
		type = "Mixed";
	}
	else {
		type = "Bio";
	}
	MixBio(type);
}
void MixWithBio::MixBio(string _type) {
	Name = _type;
	Toxicity += 2;
}
MixWithBio::~MixWithBio() {}

///������ ��� ������ MixWithPaper
void MixWithPaper::Determine() {
	string type;

	if (*waste == PlasticWaste()) {
		type = "PaperPlastic";
	}
	else if (*waste == BioWaste()) {
		type = "BioPaper";
	}
	else if (waste->getName() == "BioPlastic" || waste->getName() == "BioPaper" || waste->getName() == "PaperPlastic") {
		type = "Mixed";
	}
	else {
		type = "Paper";
	}
	MixBio(type);
}
void MixWithPaper::MixBio(string _type) {
	Name = _type;
	Toxicity += 1;
}
MixWithPaper::~MixWithPaper() {}

///������ ��� ������ MixWithPlastic
void MixWithPlastic::Determine() {
	string type;

	if (*waste == PaperWaste()) {
		type = "PaperPlastic";
	}
	else if (*waste == BioWaste()) {
		type = "BioPlastic";
	}
	else if (waste->getName() == "BioPlastic" || waste->getName() == "BioPaper" || waste->getName() == "PaperPlastic") {
		type = "Mixed";
	}
	else {
		type = "Plastic";
	}
	MixBio(type);
}
void MixWithPlastic::MixBio(string _type) {
	Name = _type;
	Toxicity += 4;
}
MixWithPlastic::~MixWithPlastic() {}