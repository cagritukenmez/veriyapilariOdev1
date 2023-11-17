/** 
* @file Dugum.cpp
* @description Dugum(Node) yapısının kurucu fonksiyonlarını içerir.
* @course Veri Yapıları - 1.Öğretim A Grubu
* @assignment 1.Ödev
* @date 17.11.2023
* @author Çağrı Tükenmez,grfspear@gmail.com
*/
#include "Dugum.hpp"
Dugum::Dugum(){
	Sayilar = NULL;
	next = NULL;
}
Dugum::Dugum(Sayi* sayiPointer){
	Sayilar = sayiPointer;
	next = NULL;
}
Dugum::Dugum(Sayi* sayiPointer,Dugum* next1){
	Sayilar = sayiPointer;
	next = next1;
}