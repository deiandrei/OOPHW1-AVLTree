#ifndef ARBORE_AVL_H
#define ARBORE_AVL_H

#include "Arbore.h"
#include "Nod_AVL.h"

class Arbore_AVL : public Arbore {
	public:
		Arbore_AVL() { mRoot = nullptr; }

		void PrintEchilibru() { PrintEchilibruHelper((Nod_AVL*)mRoot); }

	private:
		Nod* InsertHelper(int value, Nod* ref);
		void PrintEchilibruHelper(Nod_AVL* node);

		int Echilibru(Nod_AVL* node);
		Nod_AVL* RR_rotation(Nod_AVL* node);
		Nod_AVL* LL_rotation(Nod_AVL* node);
		Nod_AVL* LR_rotation(Nod_AVL* node);
		Nod_AVL* RL_rotation(Nod_AVL* node);
		Nod_AVL* BalanceNode(Nod_AVL* node);

	public:
		friend std::istream& operator>>(std::istream& input, Arbore_AVL& Arbore);
		friend std::ostream& operator<<(std::ostream& output, Arbore_AVL& Arbore);
		Arbore_AVL operator+(const int& value);
		friend Arbore_AVL operator+(int value, Arbore_AVL& Arbore);

};

#endif
