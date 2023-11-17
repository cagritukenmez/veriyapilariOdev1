#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP
#include "Dugum.hpp"
#include <fstream>
class SayilarListesi {
private:
	Dugum* head;
	Dugum* konumdanBirOncekiniBul(int);
public:
	SayilarListesi();
	bool isEmpty();
	int size();
	void SayiEkle(unsigned long long);
	int SayilarinEnBuyugununKonumunuBul();
	void removeAt(int);
	void sayiListesiniYazdir();
	void sayiyiYazdir(Sayi*);
	void SayilarinBasamaklariniBasaAl();
	void BasamaklariTersle();
	void clear();
	~SayilarListesi();
};
#endif