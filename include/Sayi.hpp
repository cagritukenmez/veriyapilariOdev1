#ifndef SAYI_HPP
#define SAYI_HPP
#include "Basamak.hpp"
#include <string>
#include <cstring>
#include <iomanip>
class Sayi {
private:
	Basamak* konumdanBirOncekiniBul(int);
public:
	Basamak* head;//sayılar listesinden erişebilmek için public kısmında tanımladım.
	Sayi();
	int size();
	bool isEmpty();
	void basamakEkle(int);
	void sayiyiParcalaVeEkle(unsigned long long);
	unsigned long long SayininDegeri();
	void basamaklariYazdir1();
	void basamakAdresleriniYazdir();
	void removeAt(int);
	void tekBasamaklariBasaAl();
	void konumaGoreBasamagiTersle(int);
	void clear();
	~Sayi();
};
#endif