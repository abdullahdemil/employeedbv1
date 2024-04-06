#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Calisan{
    public:
        static int idSayac; /*HOCAM ÖNEMLİ*/
        int calisanid;
        string isim;
        int yas;
        int maas;
        string adres;
//////////////////////////////////////////////////////
        Calisan(){
        calisanid = ++idSayac;
        }
        int idOlustur() {
        return idSayac;
        }
/////////////////////////////////////////////////////

    int calisanEkleme (ofstream& dosya){
        cout << "Yeni bir calisan ise alma ekranina hos geldiniz!" << endl;
        calisanid = idOlustur();
        cout << "Calisanin ismini giriniz :" <<endl;
        cin >> isim;
        cout << "Maasini giriniz: " << endl;
        cin >> maas;
        cout << "Adresini giriniz: "<< endl;
        cin >> adres;
        dosya << "Id: " << calisanid << ", ";
        dosya << "Calisan İsmi: " << isim << ", ";
        dosya << "Calisan Maasi: " << maas << ", " ;
        dosya << "Calisan adresi: " << adres << ", ";
        cout << "Dosya yazma islemi tamamlanmistir!...";
        return calisanid;
   }
};
int Calisan::idSayac = 0;
int main(){
Calisan calisan1;
ofstream verigir("yeni.txt", ios::app);
verigir << endl << calisan1.calisanEkleme(verigir);
return 0;
}




















/*cout << calisan1.calisanid <<endl;
cout << calisan1.isim <<endl;
cout << calisan1.maas <<endl;
cout << calisan1.adres <<endl; */




    /*calisan calisan1 = {a,b,c};
    ofstream dosyayayaz;
    dosyayayaz.open("yeni.txt");
    dosyayayaz << calisan1.isim << " " << calisan1.yas << " " << calisan1.maas <<endl; */
