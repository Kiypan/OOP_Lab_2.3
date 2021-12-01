//реалізація методів класу

#include "CBitStringBase.h"
using namespace std;

long BitStringBase::GetFirst() const
{
	return first;
}
long BitStringBase::GetSecond() const
{
	return second;
}
void BitStringBase::SetFirst(long value)
{
	first = value;
}
void BitStringBase::SetSecond(long value)
{
	second = value;
}
BitStringBase::BitStringBase(const long& first, const long& second): first(first), second(second) {}
BitStringBase& BitStringBase::operator = (const BitStringBase& pr)
{
    first = pr.first;
    second = pr.second;
    return *this;
}
BitStringBase::operator std::string() const
{
    stringstream ss;
    ss << first << ", " << second;
    return ss.str();
}
ostream& operator << (ostream& out, const BitStringBase& r)
{
    out << string(r);
    return out;
}
istream& operator >> (istream& in, BitStringBase& r)
{
    cout << "first = "; in >> r.first;
    cout << "second = "; in >> r.second;
    return in;
}
BitStringBase& BitStringBase::operator ++()
{
    first++;
    return *this;
}
BitStringBase& BitStringBase::operator --()
{
    first--;
    return *this;
}
BitStringBase BitStringBase::operator ++(int)
{
    BitStringBase t(*this);
    second++;
    return t;
}
BitStringBase BitStringBase::operator --(int)
{
    BitStringBase t(*this);
    second--;
    return t;
}
BitStringBase operator ^ (const BitStringBase& a, const BitStringBase& b)
{
	BitStringBase t;
	t.first = a.first ^ b.first;
	t.second = a.second ^ b.second;
	return t;
}

BitStringBase operator << (const BitStringBase& a, int n)
{
    BitStringBase t = a;
    long tmp[2];
    const int last_bit = sizeof(long) * 8 - 1;
    for (size_t i = 0; i < n; i++)
    {
        tmp[0] = t.first << 1;
        tmp[1] = t.second << 1;

        if (t.second & (1 << last_bit))
            tmp[0] |= (1 << 0);
        else
            tmp[0] &= ~(1 << 0);

        t.first = tmp[0];
        t.second = tmp[1];
    }
    return t;
}

BitStringBase operator >> (const BitStringBase& a, int n)
{
    BitStringBase t = a;
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

        t.first = tmp[0];
        t.second = tmp[1];
    }
    return t;
}