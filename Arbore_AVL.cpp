#include "Arbore_AVL.h"

Nod* Arbore_AVL::InsertHelper(int value, Nod* ref) {
	if (ref == nullptr) ref = new Nod_AVL(value);
	else if (value < ref->mData) {
		ref->mLeft = InsertHelper(value, ref->mLeft);
		ref = BalanceNode((Nod_AVL*)ref);
	}
	else if (value > ref->mData) {
		ref->mRight = InsertHelper(value, ref->mRight);
		ref = BalanceNode((Nod_AVL*)ref);
	}

	return ref;
}

int Arbore_AVL::Echilibru(Nod_AVL* node) {
	if (node == nullptr) return 0;

	return HeightHelper(node->mLeft) - HeightHelper(node->mRight);
}

Nod_AVL* Arbore_AVL::RR_rotation(Nod_AVL* node) {
	Nod_AVL* temp;
	temp = (Nod_AVL*)node->mRight;
	node->mRight = (Nod_AVL*)temp->mLeft;
	temp->mLeft = node;
	return temp;
}

Nod_AVL* Arbore_AVL::LL_rotation(Nod_AVL* node) {
	Nod_AVL* temp;
	temp = (Nod_AVL*)node->mLeft;
	node->mLeft = (Nod_AVL*)temp->mRight;
	temp->mRight = node;
	return temp;
}


Nod_AVL* Arbore_AVL::LR_rotation(Nod_AVL* node) {
	Nod_AVL* temp;
	temp = (Nod_AVL*)node->mLeft;
	node->mLeft = RR_rotation(temp);
	return LL_rotation(node);
}

Nod_AVL* Arbore_AVL::RL_rotation(Nod_AVL* node) {
	Nod_AVL* temp;
	temp = (Nod_AVL*)node->mRight;
	node->mRight = LL_rotation(temp);
	return RR_rotation(node);
}

Nod_AVL* Arbore_AVL::BalanceNode(Nod_AVL* node) {
	int factor = Echilibru(node);
	if (factor > 1) {
		if (Echilibru((Nod_AVL*)node->mLeft) > 0)
			node = LL_rotation(node);
		else
			node = LR_rotation(node);
	}
	else if (factor < -1) {
		if (Echilibru((Nod_AVL*)node->mRight) > 0)
			node = RL_rotation(node);
		else
			node = RR_rotation(node);
	}

	return node;
}

std::istream& operator>>(std::istream& input, Arbore_AVL& Arbore) {
	int value;
	input >> value;
	Arbore.Insert(value);
	return input;
}

std::ostream& operator<<(std::ostream& output, Arbore_AVL& Arbore) {
	Arbore.PrintHelper(output, Arbore.mRoot);
	return output;
}

Arbore_AVL Arbore_AVL::operator+(const int& value) {
	Insert(value);
	return *this;
}

Arbore_AVL operator+(int value, Arbore_AVL& Arbore) {
	Arbore.Insert(value);
	return Arbore;
}

void Arbore_AVL::PrintEchilibruHelper(Nod_AVL* node) {
	if (node != nullptr) {
		node->mBalanced = Echilibru(node);
		std::cout << node->mBalanced << " ";

		PrintEchilibruHelper((Nod_AVL*)node->mLeft);
		PrintEchilibruHelper((Nod_AVL*)node->mRight);
	}
}
