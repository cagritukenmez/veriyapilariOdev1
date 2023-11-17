/** 
* @file Sayi.cpp
* @description Sayı Bağlı Listesi sınıfının tüm fonksiyonlarını içerir.
* @course Veri Yapıları - 1.Öğretim A Grubu
* @assignment 1.Ödev
* @date 17.11.2023
* @author Çağrı Tükenmez,grfspear@gmail.com
*/ 
#include "Sayi.hpp"
 Basamak* Sayi::konumdanBirOncekiniBul(int konum){//?
	if (konum < 0 || konum >= size()) {
		throw "Index out of range";
	}
	Basamak* itr = head;
	for (int index = 0; itr != NULL; itr = itr->next, index++) {
		if (konum == index) return itr;
	}
	return NULL;
}
 Sayi::Sayi(){
	head = new Basamak(); 
 }
 int Sayi::size(){
	 int uzunluk = 0;
		if (head->next == NULL) throw "List is Empty";
		Basamak* itr = head->next;
		for (itr; itr != NULL; itr = itr->next) uzunluk++;
		return uzunluk;
 }
 bool Sayi::isEmpty(){
	 return(head->next == NULL);
 }
 void Sayi::basamakEkle(int deger) {//girilen basamak degerini direkt olarak Sayı listesinin başına ekler.
		head->next = new Basamak(deger, head->next);
}
void Sayi::sayiyiParcalaVeEkle(unsigned long long sayi) {//Sayı listesine eklenecek sayıyı parçalar ve basamakları ekler.
	while (sayi > 0) {
		int basamak = sayi % 10;
		basamakEkle(basamak);
		sayi /= 10;
	}
}
unsigned long long Sayi::SayininDegeri() {
	string str = "";
	Basamak* gecici = head->next;
	for (gecici; gecici != NULL; gecici = gecici->next) {
		str += to_string(gecici->basamakDegeri);
	}
	return stoull(str);
}
void Sayi::basamaklariYazdir1() {
	Basamak* temp = head->next;
	for (temp; temp != NULL; temp = temp->next) {
		cout << "*" << setw(4) << temp->basamakDegeri << " * ";
	}
}
void Sayi::basamakAdresleriniYazdir() {
	Basamak* ptr = head->next;
	for (ptr; ptr != NULL; ptr = ptr->next) {
		uintptr_t adresSayisal = reinterpret_cast<uintptr_t>(ptr);
		cout << "* " << hex << setw(3) << (adresSayisal % 0x1000) << " * ";
	}
}
void Sayi::removeAt(int index) {
	if (isEmpty()) throw "Empty list";
	Basamak* del;
	Basamak* prev = konumdanBirOncekiniBul(index);
	del = prev->next;
	prev->next = del->next;
	delete del;
}
void Sayi::tekBasamaklariBasaAl() {
	Basamak* itr1 = head->next;
	Basamak* itr2 = itr1->next;
	int position1 = 0;
	for (itr1; itr1 != NULL; itr1 = itr1->next,position1++) {	
		itr2 = itr1->next;
		if (itr1->basamakDegeri % 2 != 1) {
			for (int position2 = position1 + 1; itr2 != NULL; itr2 = itr2->next, position2++) {
				if (itr2->basamakDegeri % 2 == 1) {
					Basamak* temp1 = konumdanBirOncekiniBul(position1);
					Basamak* temp2 = konumdanBirOncekiniBul(position2);
					temp2->next = itr2->next;
					temp1->next = itr2;
					itr2->next = itr1;
					itr2 = itr1;
					position1++;
					position2 = position1;
				}
			}
		}
	}
}
void Sayi::konumaGoreBasamagiTersle(int konum) {
	if (konum < 0 || konum >= size()) throw "Index out of range";
	int terslenecekKonum = size() - 1 - konum;
	Basamak* prev1 = konumdanBirOncekiniBul(konum);
	Basamak* ptr1 = prev1->next;
	Basamak* prev2 = konumdanBirOncekiniBul(terslenecekKonum);
	Basamak* ptr2 = prev2->next;
	prev1->next = ptr2;
	prev2->next = ptr1;
	Basamak* temp = ptr2->next;
	ptr2->next = ptr1->next;
	ptr1->next = temp;
}
void Sayi::clear() {
	while (!isEmpty())
		removeAt(0);	
}
Sayi::~Sayi() {
	clear();
	delete head;
}