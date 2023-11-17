/** 
* @file Basamak.cpp
* @description Basamak(Node) yapısının kurucu fonksiyonlarını içerir.
* @course Veri Yapıları - 1.Öğretim A Grubu
* @assignment 1.Ödev
* @date 17.11.2023
* @author Çağrı Tükenmez,grfspear@gmail.com
*/
#include "Basamak.hpp"
Basamak::Basamak(){
	basamakDegeri = 0;
	next = NULL;
}
Basamak::Basamak(int deger){
	basamakDegeri = deger;
	next =  NULL;
}
Basamak::Basamak(int deger,Basamak* next1){
	basamakDegeri = deger;
	next = next1;
}