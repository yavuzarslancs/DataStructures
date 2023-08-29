/** 
* @file Veri Yapilari Odev
* @description Programımız bir liste oluşturur ve pointer yardımıyla Liste üyeleri aralarında işlem yapmamızı sağlar
* @course 2.Ogretim-C Grubu
* @assignment 1.Odev
* @author Yavuz ARSLAN G201210087 yavuz.arslan5@ogr.sakarya.edu.tr
*/

#include "bagliListe.hpp"
#include <iostream>

using namespace std;

bagliListe::bagliListe() // kurucu
{
    sayac=0;
    ilk=nullptr;
}

bagliListe::~bagliListe() // yok edici
{
    dugum* gecici = ilk; // ilk veriyi tutmak için geciciye atandı.

    while(gecici!=nullptr) // gecici 0 olana kadar 
    {
        dugum* sil = gecici;
        gecici= gecici->sonraki;
        delete sil;
    }           
}


void bagliListe::ekle(string veri)// ekle fonksiyonu
{
    dugum* yeni= new dugum(veri);
    sayac++;

    if(ilk==nullptr) // ilk var mı yok mu diye bakıyor
    {
        ilk=yeni;
        return;
    }

    dugum* gecici=ilk; // adresi kaybetmemek için atama yapıyoruz.

    while (gecici->sonraki!=nullptr)  // gecici üzerinden sonrakilere ulaşıyoruz
    { 
        gecici=gecici->sonraki;
    }

    gecici->sonraki=yeni;
    yeni->onceki = gecici;

}

void bagliListe::sil()
{
    if(ilk==nullptr) return;

    if(ilk->sonraki==nullptr)
    {
        delete ilk;
        ilk=nullptr;
        sayac--;
    }
    
    else
    {
        dugum* gecici=ilk;

        while(gecici->sonraki!=nullptr)  // son düğüme gitme
        {
            gecici=gecici->sonraki;
        }

        gecici->onceki->sonraki=nullptr;
        delete gecici;
        sayac--;

    }
}

void bagliListe::indiseEkle(int index, string sayi) // istenen indise ekleniyor.
{  
    ekle("");
    
    dugum* gecici=ilk; // adresi kaybetmemek için atama yapıyoruz.

    while(gecici->sonraki!=nullptr) // gecici üzerinden sonrakilere ulaşıyoruz
    {
        gecici=gecici->sonraki;
    }

    for(int i=sayac; i>index; i--)// öncekileri ve sonrakileri düzenliyor. kopyalanıyor.
    {
        gecici=gecici->onceki; 
        gecici->sonraki->veri=gecici->veri;
    }
    gecici->veri = sayi; // istenen indise veriyi ekliyor.
}

void bagliListe::indisiSil(int index) // istenen indisteki veriyi siler.
{
    if(ilk==nullptr) return;

    if(ilk->sonraki==nullptr)
    {
        delete ilk;
        ilk=nullptr;
        sayac--;
    }
    else
    {
        if(sayac<index) 
        {
            index=sayac;
            return indisiSil(index);
        }

        else
        {
            dugum* gecici=ilk;

            for(int i=0; i<index-1; i++) 
            {
               gecici=gecici->sonraki;
            }
            for(int i=index; i<sayac;i++) 
            {
                gecici->veri=gecici->sonraki->veri;
                gecici=gecici->sonraki;
            }
            gecici->onceki->sonraki=0;
            delete gecici;
            sayac--;
        }
    }    
}

void bagliListe::yazdir() // verileri yazdırır.
{
    dugum *yazdir = this->ilk; // yazdıra ilkin adresini atar.
    cout << yazdir->veri; // ilkini bastırır
    yazdir = yazdir->sonraki; //yazdırı sonrakine atar

    for (int i = 0; i < sayac - 1; i++) // döngü halinde  bastırır.
    {
        cout << " <--> " << yazdir->veri;
        yazdir = yazdir->sonraki;
    }
    cout << endl;
}
