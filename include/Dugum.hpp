#ifndef DUGUM_HPP
#define DUGUM_HPP
#include "Sayi.hpp"
struct Dugum {
public:
	Sayi* Sayilar;
	Dugum* next;

	Dugum();
	Dugum(Sayi*);
	Dugum(Sayi*, Dugum*);
};
#endif