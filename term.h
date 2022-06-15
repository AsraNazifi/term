#pragma once
#include <iostream>
using namespace std;
class term
{
private:

	float coef;
	int power;
public:
	term();
	term(float, int);
	void setCoef(float);
	void setPower(int);
	float getCoef() const;
	int getPower() const;
	term operator +(term const&);
	term operator +(float const&);
	term operator -(term const&);
	term operator *(term const&);
	term operator /(term const&);
	void operator +=(term const&);
	void operator -=(term const&);
	void operator *=(term const&);
	void operator /=(term const&);
	void operator =(term const&);
	bool operator ==(term const&);
	bool operator !=(term const&);
	bool operator >(term const&);
	bool operator <(term const&);
	bool operator >=(term const&);
	bool operator <=(term const&);
	term& operator ++();//pre
	term operator ++(int);//post
	term& operator --();//pre
	term operator --(int);//post
	void operator ~();
	float operator()(float);
	friend ostream& operator << (ostream&, const term&);
	friend istream& operator >> (istream&, term&);
	friend float& operator+(float&, term const&);
};

