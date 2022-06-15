#include "term.h"

term::term()
{
}

term::term(float coef, int power)
{
	this->coef = coef;
	this->power = power;
}

void term::setCoef(float coef)
{
	this->coef = coef;
}
void term::setPower(int power)
{
	this->power = power;
}

float term::getCoef() const
{
	return this->coef;
}

int term::getPower() const
{
	return this->power;
}
ostream& operator << (ostream& out, const term& c)
{
	if (c.coef != 0)
		out << c.coef;
	if (c.power != 0)
	{
		out << "X^" << c.power;
	}
	return out;
}
istream& operator >> (istream& in, term& c)
{
	cout << "enter the coef: ";
	in >> c.coef;
	cout << "enter the power: ";
	in >> c.power;
	return in;
}

term term::operator+(term const& b)
{
	term newTerm;
	newTerm.power = this->power;
	newTerm.coef = this->coef;
	if (this->power == b.power)
	{
		newTerm.coef = this->coef + b.coef;
	}
	return newTerm;
}
term term::operator+(float const& b)
{
	term newTerm;
	newTerm.power = this->power;
	newTerm.coef = this->coef;
	if (this->power == 0)
	{
		newTerm.coef += +b;
	}
	return newTerm;
}
float& operator+(float& f, term const& b)
{
	float result = b.coef;
	if (b.power == 0)
	{
		result = b.coef + f;
	}
	return result;
}

term term::operator-(term const& b)
{
	term newTerm;
	newTerm.power = this->power;
	newTerm.coef = this->coef;
	if (this->power == b.power)
	{
		newTerm.coef = this->coef - b.coef;
	}
	return newTerm;
}

term term::operator*(term const& b)
{
	term newTerm;
	newTerm.coef = this->coef * b.coef;
	newTerm.power = this->power + b.power;
	return newTerm;
}

term term::operator/(term const& b)
{
	term newTerm;
	newTerm.coef = this->coef / b.coef;
	newTerm.power = this->power - b.power;
	return newTerm;
}
void term::operator+=(term const& b)
{
	if (this->power == b.power)
	{
		this->coef += b.coef;
	}
}
void term::operator-=(term const& b)
{
	if (this->power == b.power)
	{
		this->coef -= b.coef;
	}
}
void term::operator*=(term const& b)
{
	this->power += b.power;
	this->coef *= b.coef;
}
void term::operator/=(term const& b)
{
	this->power -= b.power;
	this->coef /= b.coef;
}
void term::operator=(term const& b)
{
	this->power = b.power;
	this->coef = b.coef;
}
bool term::operator ==(term const& b)
{
	return (this->power == b.power && this->coef == b.coef);
}
bool term::operator !=(term const& b)
{
	return !(this->power == b.power && this->coef == b.coef);
}
bool term::operator >(term const& b)
{
	if (this->power > b.power)
	{
		return true;
	}
	else if (this->power == b.power && this->coef > b.coef)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool term::operator <(term const& b)
{
	if (this->power < b.power)
	{
		return true;
	}
	else if (this->power == b.power && this->coef < b.coef)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool term::operator >=(term const& b)
{
	if (this->power >= b.power)
	{
		return true;
	}
	else if (this->power == b.power && this->coef >= b.coef)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool term::operator <=(term const& b)
{
	if (this->power <= b.power)
	{
		return true;
	}
	else if (this->power == b.power && this->coef <= b.coef)
	{
		return true;
	}
	else
	{
		return false;
	}
}

term& term::operator++()
{
	if (this->power == 0)
	{
		this->coef += 1;
	}
	return *this;
}
term term::operator++(int)
{
	term temp = *this;
	if (this->power == 0)
	{
		++(*this);
	}
	return temp;
}


term& term::operator--()
{
	if (this->power == 0)
	{
		this->coef -= 1;
	}
	return *this;
}
term term::operator--(int)
{
	term temp = *this;
	if (temp.power == 0)
	{
		--(*this);
	}
	return temp;
}
void term::operator ~()
{
	float tempCoef = this->coef*this->power;
	int tempPower = this->power - 1;
	cout << tempCoef << "X^" << tempPower;
}

float term::operator()(float x)
{
	float result;
	result = pow(x, this->power);
	result *= this->coef;
	return result;
}
