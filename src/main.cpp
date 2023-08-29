/** 
* @file Veri Yapilari Odev
* @description Programımız bir liste oluşturur ve pointer yardımıyla Liste üyeleri aralarında işlem yapmamızı sağlar
* @course 2.Ogretim-C Grubu
* @assignment 1.Odev
* @author Yavuz ARSLAN G201210087 yavuz.arslan5@ogr.sakarya.edu.tr
*/

#include <iostream>
#include <fstream>
#include "bagliListe.hpp"
using namespace std;

int main()
{
    ifstream istenenDosya("doc\\Veri.txt"); 
    string istenenSatir;
    bagliListe *liste = new bagliListe();

    while (getline(istenenDosya, istenenSatir)) // girdileri getiriyor.
    {  
        
        
        if((char)tolower(istenenSatir[0])=='e')
        {

            string istenen = istenenSatir.substr(2, istenenSatir.length() - 3); // ekleme işlemini kontrol ediyor

            if (istenenSatir.find('#') != string::npos)
            {
                if(istenenSatir[2]=='-' || istenenSatir[2]=='0' || istenenSatir[2]==')') // indexin 0 , boş ve - olmasını kontrol ediyor
                    {
                        string istenen=istenenSatir.substr(istenenSatir.find('#')+1,istenenSatir.length()-istenenSatir.find('#')-2);
                        liste->ekle(istenen);
                    }

                else
                {
                    int i = 1; //indexi ayarlarken minimum 1 karakter ilerlemesi sağlıyor.
                    while ((char)istenenSatir[i] != '#') // diyez karakterine kadar bak.
                    {
                        i++;
                    }

                    int index = stoi(istenen.substr(0,i));
                    istenen = istenen.substr(i -1 ); // birinci harf 0 olduğu için -1 koyduk.
                    liste->indiseEkle(index, istenen);
                }
            
            }

            else
            {
                liste->ekle(istenen); 
            }  
                    
        }

        else if((char)tolower(istenenSatir[0])=='s' ) // büyük küçük harf duyarlılığı
        {
            if(istenenSatir[2]=='-' || istenenSatir[2]=='0'|| istenenSatir[2]==')')  // indexin 0 , boş ve - olmasını kontrol ediyor
            {
                liste->sil();
            }
            else
            {
                int index=stoi(istenenSatir.substr(2,istenenSatir.length()-3));
                liste->indisiSil(index);
            }
    
        }
    }
        liste->yazdir();
}

  