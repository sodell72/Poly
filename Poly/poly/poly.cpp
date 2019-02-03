// ------------------------------------------------ poly.cpp -------------------------------------------------------
// Sean O'Dell, CSS 502A
// Creation Date: 1/09/2019
// Date of Last Modification: 1/19/2019
// --------------------------------------------------------------------------------------------------------------------
// Purpose: Data structure implementation to store a polynomial
// --------------------------------------------------------------------------------------------------------------------
// Poly class allows for the creation, storage, and modification of a polynomial.  Functionality is 
// contained for common overload operators.  Accessors and mutators are also included. Users will enter 
// integers for overloaded >> mutator only, no type-checking required.
// --------------------------------------------------------------------------------------------------------------------

#include "poly.h"

// ------------------------------------getLength-----------------------------------------------
// Description: returnes length of the array of coefficients
// ---------------------------------------------------------------------------------------------------
int Poly::getLength() const 
{
	return this->length;
}

// ------------------------------------expandArray-----------------------------------------------
// Description: increases the size of the coeff array to accomidate the provided index
// ---------------------------------------------------------------------------------------------------
void Poly::expandArray(int index) 
{
	// resize array if too large of an index
	if (index > length - 1) {
		int* largerArray = new int[index + 1]();
		for (int i = this->length - 1; i >= 0; i--) 
		{
			largerArray[i] = this->coeff[i];
		}
		this->length = index + 1;
		delete[] this->coeff;
		this->coeff = largerArray;
	}
}

// ------------------------------------Poly-----------------------------------------------
// Description: constructor for polynomial, initializes largest expected exponent in polynomial
// with the given coefficient.
// ---------------------------------------------------------------------------------------------------
Poly::Poly(int coefficient, int largestExponentExpected) 
{
	if (largestExponentExpected < 0) 
	{
		coefficient = 0;
		largestExponentExpected = 0;
	}
	this->length = largestExponentExpected + 1;
	this->coeff = new int[length]();
	this->coeff[largestExponentExpected] = coefficient;
}

// ------------------------------------Poly-----------------------------------------------
// Description: constructor for polynomial, initializes 0th exponent with given coefficient.
// ---------------------------------------------------------------------------------------------------
Poly::Poly(int coefficient) 
{
	this->coeff = new int[1]();
	this->length = 1;
	this->coeff[0] = coefficient;
}

// ------------------------------------Poly-----------------------------------------------
// Description: constructor for polynomial, initializes 0th exponent with a coefficient of 0.
// ---------------------------------------------------------------------------------------------------
Poly::Poly() 
{
	this->coeff = new int[1]();
	this->length = 1;
}

// ------------------------------------Poly-----------------------------------------------
// Description: copy constructor, makes an exact and deep copy of the given polynomial
// ---------------------------------------------------------------------------------------------------
Poly::Poly(const Poly & other) 
{
	this->length = other.getLength();
	this->coeff = new int[this->length]();
	for (int i = 0; i < this->length; i++) 
	{
		this->coeff[i] = other.getCoeff(i);
	}
}

// ------------------------------------~Poly-----------------------------------------------
// Description: Destructor, de-allocates dynamically allocated memory
// ---------------------------------------------------------------------------------------------------
Poly::~Poly() 
{
	delete[] coeff;
}

// ------------------------------------operator<<-----------------------------------------------
// Description: Prints out polynomial
// ---------------------------------------------------------------------------------------------------
std::ostream & operator<<(std::ostream & out, const Poly & polynomial) 
{
	if (polynomial.length > 0) 
	{

		int zeroCount = 0;
		for (int i = polynomial.length - 1; i >= 0; i--) 
		{
			int currentCoeff = polynomial.coeff[i];
			if (currentCoeff == 0) zeroCount++;
			// prints space and sign
			if ((currentCoeff != 0 && i != 0) || (currentCoeff != 0 && i == 0)) 
			{
				out << " ";
				if (currentCoeff > 0) 
				{
					out << "+";
				}
			}
			// prints coeff and exponents
			if (currentCoeff != 0 && i != 0) 
			{
				out << currentCoeff << "x";
				if (i != 1) 
				{
					out << "^" << i;
				}
			} else if (currentCoeff != 0 && i == 0) 
			{
				out << currentCoeff;
			}
		}
		if (zeroCount == polynomial.length) out << " " << 0;
	}
	return out;
}

// ------------------------------------operator>>-----------------------------------------------
// Description: requests coefficient and index as integer pairs until user enters -1 -1 to stop
// ---------------------------------------------------------------------------------------------------
std::istream & operator>>(std::istream &in, Poly & polynomial) 
{
	int coefficient;
	int exponent;
	in >> coefficient >> exponent;
	while (coefficient != -1 || exponent != -1) 
	{
		if (exponent < 0) 
		{
			exponent = abs(exponent);
		}
		polynomial.setCoeff(coefficient, exponent);
		in >> coefficient >> exponent;
	}
	return in;
}

// ------------------------------------getCoeff-----------------------------------------------
// Description: gets coefficient for a given exponent
// ---------------------------------------------------------------------------------------------------
int Poly::getCoeff(int exponent) const 
{
	if (exponent < 0 || exponent > this->length - 1) 
	{
		return 0;
	}
	return this->coeff[exponent];
}

// ------------------------------------setCoeff-----------------------------------------------
// Description: sets exponent's coefficient
// ---------------------------------------------------------------------------------------------------
void Poly::setCoeff(int coefficient, int exponent) 
{
	if (exponent < 0) return;
	expandArray(exponent);
	coeff[exponent] = coefficient;
}

// ------------------------------------operator+-----------------------------------------------
// Description: performs polynomial addition returning a new polynomial
// ---------------------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly & poly) const 
{
	return Poly(*this) += poly;
}

// ------------------------------------operator(-)-----------------------------------------------
// Description: performs polynomial subtraction returning a new polynomial
// ---------------------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly & poly) const 
{
	return Poly(*this) -= poly;
}

// ------------------------------------operator*-----------------------------------------------
// Description: performs polynomial multiplication returning a new polynomial
// ---------------------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly & poly) const 
{
	return Poly(*this) *= poly;
}


// ------------------------------------operator+=-----------------------------------------------
// Description: performs polynomial addition, modifying the original polynomial
// ---------------------------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly & poly) 
{
	if (poly.getLength() == this->getLength()) 
	{
		for (int i = 0; i < this->getLength(); i++) 
		{
			this->setCoeff(this->getCoeff(i) + poly.getCoeff(i), i);
		}
	} else if (poly.getLength() > this->getLength()) 
	{
		for (int i = 0; i < this->getLength(); i++) 
		{
			this->setCoeff(this->getCoeff(i) + poly.getCoeff(i), i);
		}
		for (int i = this->getLength(); i < poly.getLength(); i++) 
		{
			this->setCoeff(poly.getCoeff(i), i);
		}
	} else {
		for (int i = 0; i < poly.getLength(); i++) 
		{
			this->setCoeff(this->getCoeff(i) + poly.getCoeff(i), i);
		}
	}
	return *this;
}


// ------------------------------------operator-=-----------------------------------------------
// Description: performs polynomial subtraction, modifying the original polynomial
// ---------------------------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly & poly) 
{
	if (poly.getLength() == this->getLength()) 
	{
		for (int i = 0; i < this->getLength(); i++) 
		{
			this->setCoeff(this->getCoeff(i) - poly.getCoeff(i), i);
		}
	} else if (poly.getLength() > this->getLength()) 
	{
		for (int i = 0; i < this->getLength(); i++) 
		{
			this->setCoeff(this->getCoeff(i) - poly.getCoeff(i), i);
		}
		for (int i = this->getLength(); i < poly.getLength(); i++) 
		{
			this->setCoeff(-poly.getCoeff(i), i);
		}
	} else {
		for (int i = 0; i < poly.getLength(); i++) 
		{
			this->setCoeff(this->getCoeff(i) - poly.getCoeff(i), i);
		}
	}
	return *this;
}

// ------------------------------------operator*=-----------------------------------------------
// Description: performs polynomial multiplication, modifying the original polynomial
// ---------------------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly & poly) 
{
	int newLength = this->getLength() + poly.getLength();
	int* newCoeff = new int[newLength]();
	for (int i = 0; i < this->getLength(); i++) 
	{
		for (int j = 0; j < poly.getLength(); j++) 
		{
			int coefficientProduct = this->getCoeff(i) * poly.getCoeff(j);
			newCoeff[i + j] = newCoeff[i + j] + coefficientProduct;
		}
	}
	delete[] this->coeff;
	this->length = newLength;
	this->coeff = newCoeff;
	return (*this);
}


// ------------------------------------operator==-----------------------------------------------
// Description: determines if two polynomials are equal
// ---------------------------------------------------------------------------------------------------
bool Poly::operator==(const Poly & other) const 
{
	if (other.getLength() == this->getLength()) 
	{
		for (int i = 0; i < this->getLength(); i++) 
		{
			if (this->getCoeff(i) != other.getCoeff(i)) 
			{
				return false;
			}
		}
	} else if (other.getLength() > this->getLength()) 
	{
		for (int i = 0; i < this->getLength(); i++) 
		{
			if (this->getCoeff(i) != other.getCoeff(i)) 
			{
				return false;
			}
		}
		for (int i = this->getLength(); i < other.getLength(); i++) 
		{
			if (other.getCoeff(i) != 0) 
			{
				return false;
			}
		}
	} else {
		for (int i = 0; i < other.getLength(); i++) 
		{
			if (this->getCoeff(i) != other.getCoeff(i)) 
			{
				return false;
			}
		}
		for (int i = other.getLength(); i < this->getLength(); i++) 
		{
			if (this->getCoeff(i) != 0) 
			{
				return false;
			}
		}
	}
	return true;
}

// ------------------------------------operator!=-----------------------------------------------
// Description: determines if two polynomials are not equal
// ---------------------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly & other) const 
{
	return !(*this == other);
}

// ------------------------------------operator=-----------------------------------------------
// Description: assignment, copies the information from the given polynomial to the assigned polynomial
// ---------------------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly & other) 
{
	if (this != &other) 
	{
		delete[] coeff;
		this->length = other.getLength();
		this->coeff = new int[this->length]();
		for (int i = 0; i < this->length; i++) 
		{
			this->coeff[i] = other.getCoeff(i);
		}
	}
	return (*this);
}