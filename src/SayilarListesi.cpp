/** 
* @file SayilarListesi.cpp
* @description SayilarListesi listesinin tüm fonksiyonlarının kaynak kodlarını içerir.
* @course Veri Yapıları - 1.Öğretim A Grubu
* @assignment 1.Ödev
* @date 17.11.2023
* @author Çağrı Tükenmez,grfspear@gmail.com
*/
#include "SayilarListesi.hpp"
Dugum* SayilarListesi::konumdanBirOncekiniBul(int konum) {
	if (konum < 0 || konum > size()) throw "Index out of range";
	Dugum* itr = head;
	for (int index = 0; itr != NULL; itr = itr->next, index++) {
		if (konum == index) return itr;
	}
	return NULL;
}
SayilarListesi::SayilarListesi() {
	head = new Dugum();
}
bool SayilarListesi::isEmpty() {
	return head->next == NULL;
}
int SayilarListesi::size() {
	int length = 0;
	for (Dugum* itr = head->next; itr != NULL; itr = itr->next) length++;
	return length;
}
void SayilarListesi::SayiEkle(unsigned long long okunanSayi) {//?
	Sayi* yeniSayi = new Sayi();//yeniSayi adında sayı listesi oluşturulur 
	yeniSayi->sayiyiParcalaVeEkle(okunanSayi);
	if (isEmpty()) head->next = new Dugum(yeniSayi);
	else {
		Dugum* prev = konumdanBirOncekiniBul(size());
		Dugum* yeniDugum = new Dugum(yeniSayi);
		prev->next = yeniDugum;
	}
}
int SayilarListesi::SayilarinEnBuyugununKonumunuBul() {
	if (isEmpty()) throw"The list is empty";
	Dugum* ptr = head->next;
	unsigned long long enBuyuk = ptr->Sayilar->SayininDegeri();
	ptr = ptr->next;
	int index = 0;
	for (int i = 1; ptr != NULL; ptr = ptr->next,i++) {
		Sayi* temp = ptr->Sayilar;//anlaşılmasının daha kolay olması için başka bir değişken kullandım.
		if (temp->SayininDegeri() > enBuyuk) {
			enBuyuk = temp->SayininDegeri();
			index = i;
		}
	}
	return index;
}
void SayilarListesi::removeAt(int index) {
	if (isEmpty()) throw"The list is empty";
	if (index < 0 || index >= size())throw "Index out of range";
	Dugum* prev = konumdanBirOncekiniBul(index);
	Dugum* del = prev->next;
	prev->next = del->next;
	delete del;
}
void SayilarListesi::sayiListesiniYazdir() {
	if (isEmpty()) cout << "The list is empty....\n";
	Dugum* ptr = head->next;
	for (ptr; ptr != NULL; ptr = ptr->next) {
		sayiyiYazdir(ptr->Sayilar);
		cout << endl;
	}
}
void SayilarListesi::sayiyiYazdir(Sayi* YazdirilacakSayi) {
	int length = YazdirilacakSayi->size();
	cout << "\n############\t";
	for (int i = 0; i < length; i++)cout << "******* ";
	cout << endl << "#" << hex << setw(10) << YazdirilacakSayi << "#\t";
	YazdirilacakSayi->basamakAdresleriniYazdir();
	cout << "\n#----------#\t";
	for (int i = 0; i < length; i++)cout << "******* ";
	cout << endl << "#" << dec << setw(10) << YazdirilacakSayi->SayininDegeri() << "#\t";
	YazdirilacakSayi->basamaklariYazdir1();
	cout << endl << "############\t";
	for (int i = 0; i < length; i++)cout << "******* ";
	cout << "\t";
}
void SayilarListesi::SayilarinBasamaklariniBasaAl() {
	Dugum* gecici = head->next;
	for (gecici; gecici != NULL;gecici = gecici->next) {
		gecici->Sayilar->tekBasamaklariBasaAl();
	}
}
void SayilarListesi::BasamaklariTersle() {
	Dugum* gecici = head->next;
	for (gecici; gecici != NULL; gecici = gecici->next) {
		int islemSayisi = gecici->Sayilar->size() / 2;
		for (int i = 0; i < islemSayisi; i++) {
			gecici->Sayilar->konumaGoreBasamagiTersle(i);
		}
	}
}
void SayilarListesi::clear() {
	while (!isEmpty()) clear();
}
SayilarListesi::~SayilarListesi() {
	clear();
	delete head;
}
	