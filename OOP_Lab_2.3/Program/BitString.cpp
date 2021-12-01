//реалізація методів класу

#include "BitString.h"
using namespace std;

long BitString::GetFirst() const
{
	return first;
}
long BitString::GetSecond() const
{
	return second;
}
void BitString::SetFirst(long value)
{
	first = value;
}
void BitString::SetSecond(long value)
{
	second = value;
}
BitString::BitString(const long& first, const long& second): first(first), second(second) {}
BitString& BitString::operator = (const BitString& pr)
{
    first = pr.first;
    second = pr.second;
    return *this;
}
BitString::operator std::string() const
{
    stringstream ss;
    ss << first << ", " << second;
    return ss.str();
}
ostream& operator << (ostream& out, const BitString& r)
{
    out << string(r);
    return out;
}
istream& operator >> (istream& in, BitString& r)
{
    cout << "first = "; in >> r.first;
    cout << "second = "; in >> r.second;
    return in;
}
BitString& BitString::operator ++()
{
    first++;
    return *this;
}
BitString& BitString::operator --()
{
    first--;
    return *this;
}
BitString BitString::operator ++(int)
{
    BitString t(*this);
    second++;
    return t;
}
BitString BitString::operator --(int)
{
    BitString t(*this);
    second--;
    return t;
}
BitString operator ^ (const BitString& a, const BitString& b)
{
	BitString t;
	t.first = a.first ^ b.first;
	t.second = a.second ^ b.second;
	return t;
}

BitString operator << (const BitString& a, int n)
{
    BitString t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.first << 1;
        tmp[1] = t.second << 1;
        if (t.first & (1 << last_bit))
            tmp[1] |= (1 << 0);
        else
            tmp[1] &= ~(1 << 0);

        if (t.second & (1 << last_bit))
            tmp[0] |= (1 << 0);
        else
            tmp[0] &= ~(1 << 0);
        t.first = tmp[0];
        t.second = tmp[1];
    }
    return t;
}

BitString operator >> (const BitString& a, int n)
{
    BitString t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.first >> 1;
        tmp[1] = t.second >> 1;
        if (t.first & (1 << 0))
            tmp[1] |= (1 << last_bit);
        else
            tmp[1] &= ~(1 << last_bit);

        if (t.second & (1 << 0))
            tmp[0] |= (1 << last_bit);
        else
            tmp[0] &= ~(1 << last_bit);
        t.first = tmp[0];
        t.second = tmp[1];
    }
    return t;
}