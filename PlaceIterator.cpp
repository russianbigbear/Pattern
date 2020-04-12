// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "PlaceIterator.h"

PlacePlatform* PlaceIterator::LevelUp() {
	current.pop_back();
	PlacePlatform* cur = collection;

	for (int i = 0; i < current.size() - 1; i++) {
		cur = cur->getPlace(current[i]);
	}
	return cur;
}
PlaceIterator::PlaceIterator(Platform* source) {
	collection = source;
}

bool PlaceIterator::HasNext() {
	bool has = false;
	vector<int> tmp = current;

	if (Next() != nullptr) {
		has = true;
	}
	else {
		cout << "I have no next element!" << endl;
	}
	current = tmp;
	return has;
}
PlacePlatform* PlaceIterator::Next() {
	PlacePlatform* cur = collection;

	if (current.empty()) {
		while (cur->getPlace(0) != nullptr) {
			cur = cur->getPlace(0);
			current.push_back(0);
		}
	}
	else {
		for (int i = 0; i < current.size() - 1; i++) {
			cur = cur->getPlace(current[i]);
		}
		while (current[current.size() - 1] >= cur->places.size() - 1
			&& cur != collection) {
			cur = LevelUp();
		}
		if (cur == collection &&
			current[0] >= cur->places.size() - 1) {
			return nullptr;
		}
		else {
			cur = cur->places[++current[current.size() - 1]];
			while (cur->getPlace(0 != nullptr)) {
				cur = cur->getPlace(0);
				current.push_back(0);
			}
		}
	}
	return cur;
}
vector<PlacePlatform*> PlaceIterator::SortCollection() {
	vector<PlacePlatform*> sorted;
	IIterator<PlacePlatform*>* it = collection->CreateIterator();
	while (it->HasNext()) {
		sorted.push_back(it->Next());
	}
	sort(sorted.begin(), sorted.end(), PlacePlatform::Compirer);
	return sorted;
}