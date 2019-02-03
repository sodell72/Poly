// ------------------------------------------------ poly.h -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 1/09/2019
// Date of Last Modification: 1/19/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Data structure to store a polynomial
// --------------------------------------------------------------------------------------------------------------------
// Poly class allows for the creation, storage, and modification of a polynomial.  Functionality is 
// contained for common overload operators.  Accessors and mutators are also included. Users will enter 
// integers for overloaded >> mutator only, no type-checking required.
// --------------------------------------------------------------------------------------------------------------------

#ifndef POLY_H
#define POLY_H
#include <iostream>

class Poly 
{
	// ------------------------------------operator<<-----------------------------------------------
	// Description: Prints out polynomial
	// ---------------------------------------------------------------------------------------------------
	friend std::ostream& operator<<(std::ostream &out, const Poly& polynomial);

	// ------------------------------------operator>>-----------------------------------------------
	// Description: requests coefficient and index as integer pairs until user enters -1 -1 to stop
	// ---------------------------------------------------------------------------------------------------
	friend std::istream& operator>>(std::istream &in, Poly& polynomial);

private:

	int* coeff;
	int length;

	// ------------------------------------getLength-----------------------------------------------
	// Description: returnes length of the array of coefficients
	// ---------------------------------------------------------------------------------------------------
	int getLength() const;

	// ------------------------------------expandArray-----------------------------------------------
	// Description: increases the size of the coeff array to accomidate the provided index
	// ---------------------------------------------------------------------------------------------------
	void expandArray(int index);

public:

	// ------------------------------------Poly-----------------------------------------------
	// Description: constructor for polynomial, initializes largest expected exponent in polynomial
	// with the given coefficient.
	// ---------------------------------------------------------------------------------------------------
	Poly(int coefficient, int largestExponentExpected);

	// ------------------------------------Poly-----------------------------------------------
	// Description: constructor for polynomial, initializes 0th exponent with given coefficient.
	// ---------------------------------------------------------------------------------------------------
	Poly(int coefficient);

	// ------------------------------------Poly-----------------------------------------------
	// Description: constructor for polynomial, initializes 0th exponent with a coefficient of 0.
	// ---------------------------------------------------------------------------------------------------
	Poly();

	// ------------------------------------Poly-----------------------------------------------
	// Description: copy constructor, makes an exact and deep copy of the given polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly(const Poly &other);

	// ------------------------------------~Poly-----------------------------------------------
	// Description: Destructor, de-allocates dynamically allocated memory
	// ---------------------------------------------------------------------------------------------------
	~Poly();


	// ------------------------------------getCoeff-----------------------------------------------
	// Description: gets coefficient for a given exponent
	// ---------------------------------------------------------------------------------------------------
	int getCoeff(int exponent) const;

	// ------------------------------------setCoeff-----------------------------------------------
	// Description: sets exponent's coefficient
	// ---------------------------------------------------------------------------------------------------
	void setCoeff(int coefficient, int exponent);


	// ------------------------------------operator+-----------------------------------------------
	// Description: performs polynomial addition returning a new polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly operator+(const Poly &poly) const;

	// ------------------------------------operator(-)-----------------------------------------------
	// Description: performs polynomial subtraction returning a new polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly operator-(const Poly &poly) const;

	// ------------------------------------operator*-----------------------------------------------
	// Description: performs polynomial multiplication returning a new polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly operator*(const Poly &poly) const;


	// ------------------------------------operator+=-----------------------------------------------
	// Description: performs polynomial addition, modifying the original polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly& operator+=(const Poly &poly);

	// ------------------------------------operator-=-----------------------------------------------
	// Description: performs polynomial subtraction, modifying the original polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly& operator-=(const Poly &poly);

	// ------------------------------------operator*=-----------------------------------------------
	// Description: performs polynomial multiplication, modifying the original polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly& operator*=(const Poly &poly);


	// ------------------------------------operator==-----------------------------------------------
	// Description: determines if two polynomials are equal
	// ---------------------------------------------------------------------------------------------------
	bool operator==(const Poly &other) const;

	// ------------------------------------operator!=-----------------------------------------------
	// Description: determines if two polynomials are not equal
	// ---------------------------------------------------------------------------------------------------
	bool operator!=(const Poly &other) const;


	// ------------------------------------operator=-----------------------------------------------
	// Description: assignment, copies the information from the given polynomial to the assigned polynomial
	// ---------------------------------------------------------------------------------------------------
	Poly& operator=(const Poly &other);
};

#endif
