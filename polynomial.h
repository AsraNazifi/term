#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "term.h"
using namespace std;
class polynomial
{
public:
	polynomial();
	void add(float, int);
	void sort();
	void addFromInput(string);
	polynomial operator +(polynomial const&);
	polynomial operator -(polynomial const&);
	polynomial operator *(polynomial const&);
	void operator +=(polynomial const&);
	void operator -=(polynomial const&);
	void operator *=(polynomial const&);
	void operator =(polynomial const&);
	polynomial& operator ++();//pre
	polynomial operator ++(int);//post
	polynomial& operator --();//pre
	polynomial operator --(int);//post
	bool operator ==(polynomial const&);
	bool operator !=(polynomial const&);
	bool operator >(polynomial const&);
	bool operator <(polynomial const&);
	bool operator >=(polynomial const&);
	bool operator <=(polynomial const&);
	void operator ~();
	float operator()(float);
	term operator[](int);
	friend ostream& operator << (ostream&, const polynomial&);
	friend istream& operator >> (istream&, polynomial&);
private:
	vector<term> poly;
};

