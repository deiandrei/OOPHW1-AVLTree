#ifndef NOD_AVL_H
#define NOD_AVL_H

#include "Nod.h"

class Nod_AVL : public Nod {
	public:
		Nod_AVL(int value = 0);
	
	private:
		int mBalanced;

		friend class Arbore_AVL;

};

#endif
