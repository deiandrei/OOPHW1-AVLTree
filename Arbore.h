#ifndef Arbore_H_
#define Arbore_H_

#include <iostream>
#include <algorithm>
#include <istream>

#include "Nod.h"

class Arbore {
	public:
		Arbore();
		Arbore(Nod* root) { mRoot = root; }
		~Arbore();

		void Insert(int value) { mRoot = InsertHelper(value, mRoot); }
		void Delete(int value) { mRoot = DeleteHelper(value, mRoot); }
		void Clear() { ClearHelper(mRoot); }
		
		int Height() { return HeightHelper(mRoot); }
		Nod* FindMin(Nod* Nod);
		Nod* FindMax(Nod* Nod);

		void Print() { PrintHelper(std::cout, mRoot); std::cout << "\n"; }
		void PrintLeafs() { PrintLeafsHelper(mRoot); std::cout << "\n"; }
	
	protected:
		Nod* mRoot;

	////Recursive helpers
	protected:
		void ClearHelper(Nod* Nod);
		int HeightHelper(Nod* Nod);
		virtual Nod* InsertHelper(int value, Nod* ref);
		Nod* DeleteHelper(int value, Nod* ref);
		void PrintHelper(std::ostream& stream, Nod* Nod);
		void PrintLeafsHelper(Nod* Nod);
	////
		
	public:
		friend std::istream& operator>>(std::istream& input, Arbore& Arbore);
		friend std::ostream& operator<<(std::ostream& output, Arbore& Arbore);
		Arbore operator+(const int& value);
		friend Arbore operator+(int value, Arbore& Arbore);
};

#endif
