#include "Platform.h"
#include "PlaceIterator.h"

///Методы для класса PlacePlatform
void PlacePlatform::Display() {
	cout << "My place carrying = [" << getPlaceCarrying() << "]" << endl;
}

PlacePlatform& PlacePlatform::operator= (const PlacePlatform& placeplatform) {
	PlaceCarrying = placeplatform.PlaceCarrying;
	return *this;
}
bool PlacePlatform::operator== (const PlacePlatform& placeplatform) {
	return PlaceCarrying == placeplatform.PlaceCarrying;
}
bool PlacePlatform::Compirer(PlacePlatform* pp1, PlacePlatform* pp2) {
	if (pp1->getPlaceCarrying() > pp2->getPlaceCarrying())
		return true;
	else
		return false;
}

///Методы для класса Platform
Platform::Platform(int _place_count) { PlaceCount = _place_count; }
Platform::~Platform() { delete[] & places; }

IIterator<PlacePlatform*>* Platform::CreateIterator() {
	return new PlaceIterator(this);
}

int Platform::getPlaceCount() { return PlaceCount; }
int Platform::getPlaceCarrying() { return PlaceCarrying; }
int Platform::getPlaceSize() { return places.size(); }
PlacePlatform* Platform::getPlace(int index) {
	if (places.empty())
		return nullptr;
	return places[index];
}

void Platform::setPlaceCount(int _PlaceCount) { PlaceCount = _PlaceCount; }
void Platform::setPlaceCarrying(int _PlaceCarrying) { PlaceCarrying = _PlaceCarrying; }

bool Platform::AddWaste(Waste* _waste) {
	if (PlaceCarrying - _waste->getMass() > 0) {
		command->Execute();
		if (*_waste == PlasticWaste()) {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! Plastic waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
		else if (*_waste == PaperWaste()) {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! Paper waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
		else if (*_waste == BioWaste()) {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! Paper waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
		else if (_waste->getName() == "BioPlastic") {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! BioPlastic waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
		else if (_waste->getName() == "BioPaper") {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! BioPaper waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
		else if (_waste->getName() == "PaperPlastic") {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! PaperPlastic waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
		else if (_waste->getName() == "Mixed") {
			for (PlacePlatform* place : places) {
				if (place->AddWaste(_waste)) {
					PlaceCarrying -= _waste->getMass();
					cout << "OK! Mixed waste added... Mass=[" << _waste->getMass() << "], Toxicity=[" << _waste->getToxicity() << "]" << endl;
					return true;
				}
				else return false;
			}
		}
	}
	else {
		cout << "ERROR! Platform don't have empty place..." << endl;
		return false;
	}
}
bool Platform::DeleteWaste(Waste* _waste) {
	for (PlacePlatform* place : places) {
		if (*_waste == PlasticWaste()) {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! Plastic waste removed..." << endl;
				return true;
			}
			else return false;
		}
		else if (*_waste == PaperWaste()) {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! Paper waste removed..." << endl;
				return true;
			}
			else return false;
		}
		else if (*_waste == BioWaste()) {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! Bio waste removed..." << endl;;
				return true;
			}
			else return false;
		}
		else if (_waste->getName() == "BioPlastic") {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! BioPlastic waste removed..." << endl;;
				return true;
			}
			else return false;
		}
		else if (_waste->getName() == "BioPaper") {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! BioPaper waste removed..." << endl;;
				return true;
			}
			else return false;
		}
		else if (_waste->getName() == "PaperPlastic") {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! PaperPlastic waste removed..." << endl;
				return true;
			}
			else return false;
		}
		else if (_waste->getName() == "Mixed") {
			if (place->DeleteWaste(_waste)) {
				cout << "Ok! Mixed waste removed..." << endl;
				return true;
			}
			else return false;
		}
	}


	cout << "ERROR! Waste don't remove..." << endl;
	return false;
}

void Platform::AddPlace(PlacePlatform* place) {
	if (getPlaceSize() < PlaceCount) {
		places.push_back(place);
	}
}
void Platform::DeletePlace(int index) {
	delete places[index];
}

///Методы для класса SinglePlaceWaste
SinglePlaceWaste::SinglePlaceWaste() { waste = nullptr; PlaceCarrying = 1000; }
SinglePlaceWaste::SinglePlaceWaste(Waste* _waste) {
	waste = _waste;
}
SinglePlaceWaste::SinglePlaceWaste(int _placecarrying) {
	PlaceCarrying = _placecarrying;
}
int SinglePlaceWaste::getPlaceSize() { return 0; }
PlacePlatform* SinglePlaceWaste::getPlace(int index) { return nullptr; }

int SinglePlaceWaste::getPlaceCount() { return getPlaceCount(); }
int SinglePlaceWaste::getPlaceCarrying() { return PlaceCarrying; }

bool SinglePlaceWaste::AddWaste(Waste* _waste) {
	if (waste == nullptr && PlaceCarrying >= _waste->getMass()) {
		waste = _waste;
		PlaceCarrying -= _waste->getMass();
		return true;
	}
	else return false;
}
bool SinglePlaceWaste::DeleteWaste(Waste* _waste) {
		if (waste == _waste) {
			waste = nullptr;
			return true;
		}
		else
			return false;
}