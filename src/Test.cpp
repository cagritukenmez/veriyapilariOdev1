/** 
* @file Test.cpp
* @description Programın execute edildiği alandır.Sayilar.txt'den sayıları okur ve menü işlemlerini yaptırtır.
* @course Veri Yapıları - 1.Öğretim A Grubu
* @assignment 1.Ödev
* @date 17.11.2023
* @author Çağrı Tükenmez,grfspear@gmail.com
*/

#include "SayilarListesi.hpp"
int main() {
	SayilarListesi* liste = new SayilarListesi();
	ifstream dosya("Sayilar.txt");
	if (dosya.is_open()) {
		unsigned long long sayi = 0;
		while (dosya >> sayi) {
			liste->SayiEkle(sayi);
		}
	}
	else {
		cout << "THE FILE IS NOT OPENED!!!!" << endl;
		return 0;
	}
	dosya.close();// dosya ile artık işimiz olmadığı için hemen kapatıyorum.
	int secenek = 0;
	do {
		liste->sayiListesiniYazdir();
		cout << "\n1.Tek Basamaklari Basa Al\n";
		cout << "2.Basamaklari Tersle\n";
		cout << "3.En Buyuk Cikar Al\n";
		cout << "4.Cikis\n";
		cin >> secenek;
		switch (secenek) {
		case 1:
		if (liste->isEmpty()) {
			cout << "Liste bos, cikis yapiliyor..." << endl;
			return 0;
		}
			liste->SayilarinBasamaklariniBasaAl();
			break;
		case 2:
		if (liste->isEmpty()) {
			cout << "Liste bos, cikis yapiliyor..." << endl;
			return 0;
		}
			liste->BasamaklariTersle();
			break;
		case 3:
			if (liste->isEmpty()) {
				cout << "Liste bos, cikis yapiliyor..." << endl;
				return 0;
			}
			liste->removeAt(liste->SayilarinEnBuyugununKonumunuBul());
			break;
		default:
			break;
		}
	} while (secenek != 4);
	delete liste;
	return 0;
}