#pragma once
//визначення класу

#include <string>
#include <iostream>
#include <sstream>

class BitStringBase
{
private:
    long first = 0;
    long second = 0;

public:
	BitStringBase() {};
	BitStringBase(const BitStringBase& obj) :
		first(obj.first), second(obj.second) {}
	BitStringBase(const long& first, const long& second);
	~BitStringBase() {};

	BitStringBase& operator = (const BitStringBase&);
	operator std::string() const;

    long GetFirst() const;
    long GetSecond() const;

    void SetFirst(long value);
    void SetSecond(long value);

	friend std::ostream& operator << (std::ostream&, const BitStringBase&);
	friend std::istream& operator >> (std::istream&, BitStringBase&);
};