/** 
* @file Veri Yapilari Odev
* @description Programımız bir liste oluşturur ve pointer yardımıyla Liste üyeleri aralarında işlem yapmamızı sağlar
* @course 2.Ogretim-C Grubu
* @assignment 1.Odev
* @author Yavuz ARSLAN G201210087 yavuz.arslan5@ogr.sakarya.edu.tr
*/

#ifndef bagliListe_hpp
#define bagliListe_hpp
#include "dugum.hpp"

using namespace std;

class bagliListe
{
public:
    bagliListe(); // kurucu
    ~bagliListe(); // yok edici
    void ekle(string veri); // indis girilmediyse sona ekleyecek
    void indiseEkle(int index,string veri); // istediğin indise ekleyecek
    void sil(); // boş silince sondan silecek.
    void indisiSil(int index); // istediğin indistekini silecek
    void yazdir();// yazdiracak
    int sayac;
private:  
    dugum* ilk;
    
};
#endif