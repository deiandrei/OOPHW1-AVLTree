#ifndef NODE_H_
#define NODE_H_

class Arbore;

class Nod {
	public:
		Nod(int value = 0);

	private:
		Nod *mLeft, *mRight;
		int mData;
		
		friend class Arbore;
		friend class Arbore_AVL;
};

#include "Arbore.h"

#endif
