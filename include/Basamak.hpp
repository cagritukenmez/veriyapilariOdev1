#ifndef BASAMAK_HPP
#define BASAMAK_HPP
#include <iostream>
using namespace std;
struct Basamak {
public:
	int basamakDegeri;
	Basamak* next;
	Basamak();
	Basamak(int x);
	Basamak(int, Basamak*);
};
#endif