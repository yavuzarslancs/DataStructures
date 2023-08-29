/** 
* @file Veri Yapilari Odev
* @description Programımız bir liste oluşturur ve pointer yardımıyla Liste üyeleri aralarında işlem yapmamızı sağlar
* @course 2.Ogretim-C Grubu
* @assignment 1.Odev
* @author Yavuz ARSLAN G201210087 yavuz.arslan5@ogr.sakarya.edu.tr
*/

#include "dugum.hpp"
#include <string>
using namespace std;

dugum::dugum(string veri )
{
    this -> veri=veri;
    onceki=nullptr;
    sonraki=nullptr;
}