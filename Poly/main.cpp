#include <iostream>
#include "Poly.h"
//#define _CRTDBG_MAP_ALLOC  
//#include <stdlib.h>  
//#include <crtdbg.h>  

using namespace std;

int main(int argc, char* argv[]) 
{

	Poly test(5, 7);
	cout << "original test: " << test << endl;
	Poly copyTest(test);
	cout << "original copyTest: " << copyTest << endl;
	test.setCoeff(6, 9);
	cout << "test after setCoeff(6, 9): " << test << endl;
	copyTest.setCoeff(17, 2);
	cout << "copyTest after setCoeff(17, 2): " << copyTest << endl;
	cout << "test after copyTest modified: " << test << endl;

	// test * and *=
	Poly mult1;
	Poly mult2;
	mult1.setCoeff(1, 2);
	mult1.setCoeff(2, 1);
	cout << "mult1: " << mult1 << endl;
	mult2.setCoeff(4, 0);
	mult2.setCoeff(1, 1);
	cout << "mult2: " << mult2 << endl;
	mult1 *= mult2;
	cout << "mult1 after mult1*=mult2: " << mult1 << endl;
	Poly multResult = mult1 * mult2;
	cout << "multResult after mult1*=mult2: " << multResult << endl;
	cout << endl;

	// test =
	Poly equate = multResult;
	cout << "equate after equate=multResult: " << equate << endl;
	equate.setCoeff(1, 1);
	multResult.setCoeff(1, 0);
	cout << "equate after changest to multResult and equate: " << equate << endl;
	cout << "multResult after changest to multResult and equate: " << multResult << endl;
	cout << endl;

	// test -
	cout << "mult1: " << mult1 << endl;
	mult2.setCoeff(-1, 6);
	cout << "mult2: " << mult2 << endl;
	Poly subtracted = mult1 - mult2;
	cout << "subtracted after = mult1 - mult2: " << subtracted << endl;
	subtracted -= mult2;
	cout << "subtracted after -=mult2: " << subtracted << endl;
	subtracted = subtracted - 16;
	cout << "subtracted after -=mult2: " << subtracted << endl;

	//test 0 polynomial
	Poly zero;
	cout << "zero polynomial: " << zero << endl;
	cout << "getting nonexistant term: " << zero.getCoeff(5) << endl;

	cout << endl << "_________________________________________" << endl;
	// DO NOT change anything in this file. Your code must compile and give 
	// correct output with this main on the linux machines.
	// Make sure the file containing the member function source is: poly.cpp
	// Use all lowercase in the file names.
	// This main does not do a thorough job of testing.  When testing arrays,
	// be sure to test the middle and also all the boundary conditions.  Test
	// values on the boundary and outside the boundaries, i.e., too big/small.

	Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
	Poly A2, B2, Z1, Z2;
	// set polynomials A and B to desired values
	// A = +5x^7 -4x^3 +10x -2
	// B = +3x^4 +1x^3
	cout << "Enter terms for polynomial A.  Enter a coefficient " << endl
		<< "then exponent for each term. Enter -1 -1 to terminate." << endl;
	cin >> A;                                     
	// or use a bunch of setCoeff
	cout << "Enter terms for polynomial B.  Enter a coefficient " << endl
		<< "then exponent for each term. Enter -1 -1 to terminate." << endl;
	cin >> B;                                     
	// or use a bunch of setCoeff
	// outputs exactly what is in quotes: "A = +5x^7 -4x^3 +10x -2"
	cout << "A =" << A << endl;
	// outputs exactly what is in quotes: "B = +3x^4 +1x^3"
	cout << "B =" << B << endl << endl;
	A2 = A;
	B2 = B;
	C = A + B;
	cout << "Compute C = A + B: " << C << endl << endl;
	cout << ((A == B) ? "A == B" : "A is not == B") << endl;
	cout << ((A != B) ? "A is not == B" : "A == B") << endl << endl;
	Z1 = A2 - B2;
	cout << "Compute  Z1 = A2 - B2: " << Z1 << endl;
	Z2 = B2 - A2;
	cout << "Compute  Z2 = B2 - A2: " << Z2 << endl << endl;
	cout << "Compute  D = A * B - 15" << endl;
	cout << "Before: D =" << D << endl;
	D = A * B - 15;
	cout << "After:  D =" << D << endl << endl;
	cout << "Test assignment operators" << endl;
	X = C = D = D;
	Y += A -= B *= A;
	cout << "X =" << X << endl;
	cout << "Y =" << Y << endl << endl;
	cout << "Get and Set coefficient" << endl;
	int coeff = D.getCoeff(0);
	cout << "coeff of subscript 0 of D is: " << coeff << endl;
	cout << "Doing getCoeff for term -20000" << endl;
	coeff = D.getCoeff(-20000);              // handle value out of range
	D.setCoeff(50, 0);                        // set x^0 coeff to 50
	D.setCoeff(50, 20000);                    // set x^20000 coeff to 50
	cout << "D =" << D << endl << endl;

	//_CrtDumpMemoryLeaks();
	cin.get();
	return 0;
}