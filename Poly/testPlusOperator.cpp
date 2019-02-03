//#pragma once
//#include <iostream>
//class TestPlusOperator {
//
//	friend std::ostream& operator<<(std::ostream &out, const Poly& polynomial);
//	friend std::istream& operator>>(std::istream &in, Poly& polynomial);
//
//private:
//
//
//
//public:
//	int* coeff;
//	int length;
//
//	TestPlusOperator(int coefficient, int largestExponentExpected) {
//		this->length = largestExponentExpected + 1;
//		this->coeff = new int[length]();
//		this->coeff[largestExponentExpected] = coefficient;
//	}
//
//	// Copy Constructor
//	TestPlusOperator(const TestPlusOperator & other) {
//		this->length = other.length;
//
//		this->coeff = new int[this->length]();
//		for (int i = 0; i < this->length; i++) {
//			std::cout << other.coeff[i] << ", ";
//			this->coeff[i] = other.coeff[i];
//		}
//	}
//
//	Poly operator+(const Poly &poly) const;
//
//
//	Poly& operator+=(const Poly &poly);
//
//};
//
