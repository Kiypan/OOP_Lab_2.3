// функція main
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "BitString.h"

using namespace std;

int main()
{

	BitString o;

	cin >> o;

	int n;

	cout << o << endl << endl;

	// ShiftLeft
	cout << "How many bits do you want to shift left?" << endl;
	cout << "Input:  "; cin >> n;
	BitString a = o << n;
	cout << a << endl;

	// ShiftRight
	cout << "How many bits do you want to shift right?" << endl;
	cout << "Input:  "; cin >> n;
	BitString b = o >> n;
	cout << b << endl;

	// Xor
	cout << "Xor: " << endl;
	cout << (a ^ b) << endl;

	cin.get();

	return 0;

}