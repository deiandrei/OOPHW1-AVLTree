#include "Arbore.h"


Arbore::Arbore() {
	mRoot = nullptr;
}


Arbore::~Arbore() {
	
}

void Arbore::ClearHelper(Nod* target) {
	if (target == nullptr) return;
	
	ClearHelper(target->mLeft);
	ClearHelper(target->mRight);
	delete target;
}

Nod* Arbore::InsertHelper(int value, Nod* ref) {
	if (ref == nullptr) ref = new Nod(value);
	else if (value < ref->mData) ref->mLeft = InsertHelper(value, ref->mLeft);
	else if (value > ref->mData) ref->mRight = InsertHelper(value, ref->mRight);

	return ref;
}

int Arbore::HeightHelper(Nod* Nod) {
	if (Nod == nullptr) return 0;

	int leftHeight = HeightHelper(Nod->mLeft);
	int leftRight = HeightHelper(Nod->mRight);

	return (std::max(leftHeight, leftRight) + 1);
}

void Arbore::PrintHelper(std::ostream& stream, Nod* Nod) {
	if (Nod == nullptr) return;

	PrintHelper(stream, Nod->mLeft);
	stream << Nod->mData << " ";
	PrintHelper(stream, Nod->mRight);
}

void Arbore::PrintLeafsHelper(Nod* Nod) {
	if (Nod == nullptr) return;

	if (Nod->mLeft == nullptr && Nod->mRight == nullptr) std::cout << Nod->mData << " ";
	PrintLeafsHelper(Nod->mLeft);
	PrintLeafsHelper(Nod->mRight);
}

Nod* Arbore::FindMin(Nod* Nod) {
	if (Nod == nullptr) return nullptr;
	else if (Nod->mLeft == nullptr) return Nod;
	else return FindMin(Nod->mLeft);
}

Nod* Arbore::FindMax(Nod* Nod) {
	if (Nod == nullptr) return nullptr;
	else if (Nod->mRight) return Nod;
	else return FindMax(Nod->mRight);
}

Nod* Arbore::DeleteHelper(int value, Nod* ref) {
	if (ref == nullptr) return nullptr;
	
	Nod* tempNod;
	if (value < ref->mData) ref->mLeft = DeleteHelper(value, ref->mLeft);
	else if (value > ref->mData) ref->mRight = DeleteHelper(value, ref->mRight);
	else if (value == ref->mData) {
		if (ref->mLeft != nullptr && ref->mRight != nullptr) {
			tempNod = FindMin(ref->mRight);
			ref->mData = tempNod->mData;
			ref->mRight = DeleteHelper(ref->mData, ref->mRight);
		}
		else {
			tempNod = ref;
			if (ref->mLeft == nullptr) ref = ref->mRight;
			else if (ref->mRight == nullptr) ref = ref->mLeft;
			delete tempNod;
		}
	}

	return ref;
}

std::istream& operator>>(std::istream& input, Arbore& Arbore) {
	int value;
	input >> value;
	Arbore.Insert(value);
	return input;
}

std::ostream& operator<<(std::ostream& output, Arbore& Arbore) {
	Arbore.PrintHelper(output, Arbore.mRoot);
	return output;
}

Arbore Arbore::operator+(const int& value) {
	Insert(value);
	return *this;
}

Arbore operator+(int value, Arbore& Arbore) {
	Arbore.Insert(value);
	return Arbore;
}
