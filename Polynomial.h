#pragma once
#include <string>
#include <map>
#include <iostream>
//#include <cstdlib>
#define DEBUG

struct Polynomial {
	//Do not use default constructor. For some fucking reason it doesn't go very well
	Polynomial(std::string s);
	std::string get();
	std::string get() const;
	int getDegree() {
		return degree;
	}
	int getDegree() const {
		return degree;
	}
	//Overrided operators to get coefficient from exponent
	double operator[](const int &i) {
		return poly[i];
	}
	double operator[](const int &i) const {
		//Returns a right-hand operand
		std::map<int, double>::const_iterator j = poly.find(i);
		return (*j).second;
	}
	void operator+=(Polynomial &rhs);
	void operator+=(std::pair<int, double> &rhs);
	void operator-=(Polynomial &rhs);
	Polynomial operator*(const std::pair<int, double> &p) const;
	std::pair<Polynomial, Polynomial> operator/(const Polynomial &rhs);
protected:
	//Key is the exponent, value is the coefficient
	std::map<int, double> poly;
	int degree;
	void updateDegree();
};