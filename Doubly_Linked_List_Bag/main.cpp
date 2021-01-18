#include "dbag.h"
#include <iostream>

using namespace std;
int main(void)
{
	dbag A, B, C,F;
	dbag::size_type i;
	dbag::value_type j;
	bool erasing, same;
	
	A.show_content();
	A.insert(3);
	//A.show_content();
	A.insert(5);
	//A.show_content();
	A.insert(1);
	//A.show_content();
	A.insert(7);
	//A.show_content();
	A.insert(4);
	A.show_content();

	i= A.count(3);
	j = A.grab();
	cout << "counting 3: [" <<i << "]" << endl << " grab number: " << j << endl;

	A.sort();
	cout << "A sorted" << endl;
	A.show_content();
	erasing=A.erase_one(5);

	cout << "erasing 5" << endl;
	A.show_content();

	A.sort();
	B = A;

	cout << "B=A" << endl << "show B :";
	B.show_content();

	C.insert(-1);
	C.insert(-2);
	C.insert(-3);
	C.show_content();

	A += C;

	A.show_content();

	dbag D;

	D.insert(-3);
	D.insert(-2);
	D.insert(-1);
	D.insert(3);
	D.insert(4);
	D.insert(1);
	D.insert(7);

	dbag E(D);

	D.show_content();

	E.sort();
	E.erase_one(7);

	same = A == D;

	cout << same << endl << "A";
	A.show_content();
	cout << "B";
	B.show_content();
	cout << "C";
	C.show_content();
	cout << "D";
	D.show_content();
	cout << "E";
	E.show_content();

	F = B + C;

	cout << "F";
	F.show_content();



}