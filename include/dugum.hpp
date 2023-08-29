/** 
* @file Veri Yapilari Odev
* @description Programımız bir liste oluşturur ve pointer yardımıyla Liste üyeleri aralarında işlem yapmamızı sağlar
* @course 2.Ogretim-C Grubu
* @assignment 1.Odev
* @author Yavuz ARSLAN G201210087 yavuz.arslan5@ogr.sakarya.edu.tr
*/

#include <string>
#ifndef dugum_hpp
#define dugum_hpp
using namespace std;
class dugum
{
public:
    dugum* sonraki;
    dugum* onceki;
    string veri;
    dugum(string veri);
};
#endif