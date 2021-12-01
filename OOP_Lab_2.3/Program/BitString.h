#pragma once
//визначення класу

#include <string>
#include <iostream>
#include <sstream>

class BitString
{
private:
    long first = 0;
    long second = 0;

public:
	BitString() {};
	BitString(const BitString& obj) :
		first(obj.first), second(obj.second) {}
	BitString(const long& first, const long& second);
	~BitString() {};

	BitString& operator = (const BitString&);

	operator std::string() const;

	friend std::ostream& operator << (std::ostream&, const BitString&);
	friend std::istream& operator >> (std::istream&, BitString&);

	// prefix
	BitString& operator ++();
	BitString& operator --();

	// postfix
	BitString operator ++(int);
	BitString operator --(int);

    long GetFirst() const;
    long GetSecond() const;

    void SetFirst(double value);
    void SetSecond(double value);

    friend BitString operator ^ (const BitString& a, const BitString& b);

    friend BitString operator << (const BitString& a, int n);
    friend BitString operator >> (const BitString& a, int n);
};