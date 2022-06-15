#include "polynomial.h"
polynomial::polynomial()
{

}

void polynomial::add(float coef, int power)
{
	term newTerm(coef, power);
	bool flag = true;
	for (int i = 0; i < this->poly.size() && flag; i++)
	{
		if (this->poly[i].getPower() == power)
		{
			this->poly[i].setCoef(this->poly[i].getCoef() + coef);
			flag = false;
		}
	}
	if (flag)
		poly.push_back(newTerm);
	sort();
}

void polynomial::sort()
{
	for (int i = 0; i < this->poly.size() - 1; i++)
	for (int j = 0; j < this->poly.size() - i - 1; j++)
	if (this->poly[j] < this->poly[j + 1])
	{
		term temp;
		temp = this->poly[j];
		this->poly[j] = this->poly[j + 1];
		this->poly[j + 1] = temp;
	}
}


ostream& operator << (ostream& out, const polynomial& samp)
{
	for (int i = 0; i<samp.poly.size(); i++)
	{
		if (i != 0 && samp.poly[i].getCoef()>0)
		{
			out << "+";
		}
		out << samp.poly[i];
	}
	return out;
}

void polynomial::addFromInput(string str)
{
	bool isCoefPositive = true;
	bool isPowerPositive = true;
	int i = 0;
	if (str[0] == '-')
	{
		isCoefPositive = false;
		i = 1;
	}
	else if(str[0] == '+')
	{
		i = 1;
	}
	int coef = 0, power = 0;
	bool isCoef = true;
	for (; i < str.length(); i++)
	{
		if (str[i]=='x' || str[i]=='X')
		{
			isCoef = false;
			i+=2;
		}
		if (!isCoef)
		{
			if (str[i] == '-')
			{
				isPowerPositive = false;
				i++;
			}
		}
		if (isCoef)
			coef = coef * 10 + (str[i] - 48);
		else
			power = power * 10 + (str[i] - 48);
	
	}
	if (isCoefPositive && isPowerPositive)
		add(coef, power);
	else if (!isCoefPositive && isPowerPositive)
		add(-1*coef,power);
	else if (isCoefPositive && !isPowerPositive)
		add(coef, -1 * power);
	else
		add(-1 * coef, -1 * power);
}

istream& operator >> (istream& in, polynomial& samp)
{
	string str;
	getline(cin, str);
	string subStr = "";
	int count = 0;
	for (int i = 0; i < str.length(); i++)
	{
		if (count == 0)
		{
			count++;
			subStr += str[i];
		}
		else if (!(str[i] == '+' || str[i] == '-') && count == 1)
		{
			subStr += str[i];
			if (str[i - 1] == '^')
				count++;
		}
		else
		{
			samp.addFromInput(subStr);
			subStr = "";
			count = 0;
			subStr += str[i];
		}
	}
	samp.addFromInput(subStr);
	return in;
}

polynomial polynomial::operator +(polynomial const& b)
{
	polynomial newPoly;
	newPoly = *this;
	for (int i = 0; i<b.poly.size(); i++)
	{
		newPoly.add(b.poly[i].getCoef(), b.poly[i].getPower());
	}
	sort();
	return newPoly;
}

polynomial polynomial::operator -(polynomial const& b)
{
	polynomial newPoly;
	newPoly = *this;
	for (int i = 0; i < b.poly.size(); i++)
	{
		newPoly.add(-1 * b.poly[i].getCoef(), b.poly[i].getPower());
	}
	sort();
	return newPoly;
}

polynomial polynomial::operator *(polynomial const& b)
{
	polynomial newPoly;
	for (int i = 0; i < this->poly.size(); i++)
	{
		for (int j = 0; j < b.poly.size(); j++)
		{
			newPoly.add(this->poly[i].getCoef()*b.poly[j].getCoef(), this->poly[i].getPower() + b.poly[j].getPower());
		}
	}
	sort();
	return newPoly;
}

void polynomial::operator +=(polynomial const& b)
{
	for (int i = 0; i < b.poly.size(); i++)
	{
		this->add(b.poly[i].getCoef(), b.poly[i].getPower());
	}
	sort();
}

void polynomial::operator -=(polynomial const& b)
{
	for (int i = 0; i < b.poly.size(); i++)
	{
		this->add(-1 * b.poly[i].getCoef(), b.poly[i].getPower());
	}
	sort();
}

void polynomial::operator *=(polynomial const& b)
{
	polynomial newPoly;
	newPoly = (*this) * b;
	*this = newPoly;
	sort();
}

void polynomial::operator =(polynomial const& b)
{
	this->poly = b.poly;
	sort();
}
void polynomial::operator ~()
{
	for (int i = 0; i < this->poly.size(); i++)
	{
		if (i != 0 && this->poly[i].getCoef()>0)
			cout << "+";
		~poly[i];
	}
}

polynomial& polynomial::operator ++()
{
	this->add(1, 0);
	sort();
	return *this;
}
polynomial polynomial::operator ++(int)
{
	polynomial newPoly = *this;
	++(*this);
	sort();
	return newPoly;
}

polynomial& polynomial::operator --()
{
	this->add(-1, 0);
	sort();
	return *this;
}
polynomial polynomial::operator --(int)
{
	polynomial newPoly = *this;
	--(*this);
	sort();
	return newPoly;
}
float polynomial::operator()(float x)
{
	float result = 0;
	for (int i = 0; i<this->poly.size(); i++)
	{
		result += this->poly[i](x);
	}
	return result;
}

term polynomial::operator[](int index)
{
	if (index < this->poly.size())
	{
		return this->poly[index];
	}
	else
	{
		cout << "out of range.\n";
	}
	term x(0, 0);
	return x;
}

bool polynomial::operator ==(polynomial const& b)
{
	if (this->poly.size() == b.poly.size())
	{
		bool flag = true;
		for (int i = 0; i < this->poly.size(); i++)
		{
			if (this->poly[i] != b.poly[i])
			{
				flag = false;
				break;
			}
		}
		return flag;
	}
	else
	{
		return false;
	}
}

bool polynomial::operator !=(polynomial const& b)
{
	return !(*this==b);
}
bool polynomial::operator >(polynomial const& b)
{
	int size;
	if (this->poly.size() < b.poly.size())
		size = this->poly.size();
	else
		size = b.poly.size();

	for (int i = 0; i < size; i++)
	{
		if (this->poly[i] > b.poly[i])
		{
			return true;
		}
		else if (this->poly[i] < b.poly[i])
		{
			return false;
		}
	}
	if (this->poly.size()>b.poly.size())
		return true;
	else
		return false;
}
bool polynomial::operator >=(polynomial const& b)
{
	int size;
	if (this->poly.size() < b.poly.size())
		size = this->poly.size();
	else
		size = b.poly.size();

	for (int i = 0; i < size; i++)
	{
		if (this->poly[i] >= b.poly[i])
		{
			return true;
		}
		else if (this->poly[i] < b.poly[i])
		{
			return false;
		}
	}
	if (this->poly.size()>=b.poly.size())
		return true;
	else
		return false;
}
bool polynomial::operator <(polynomial const& b)
{
	int size;
	if (this->poly.size() < b.poly.size())
		size = this->poly.size();
	else
		size = b.poly.size();

	for (int i = 0; i < size; i++)
	{
		if (this->poly[i] < b.poly[i])
		{
			return true;
		}
		else if (this->poly[i] > b.poly[i])
		{
			return false;
		}
	}
	if (this->poly.size()<b.poly.size())
		return true;
	else
		return false;
}
bool polynomial::operator <=(polynomial const& b)
{
	int size;
	if (this->poly.size() < b.poly.size())
		size = this->poly.size();
	else
		size = b.poly.size();

	for (int i = 0; i < size; i++)
	{
		if (this->poly[i] <= b.poly[i])
		{
			return true;
		}
		else if (this->poly[i] > b.poly[i])
		{
			return false;
		}
	}
	if (this->poly.size()<=b.poly.size())
		return true;
	else
		return false;
}