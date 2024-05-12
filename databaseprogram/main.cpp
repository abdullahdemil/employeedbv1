#include <filesystem>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
static int idKayit;
class Calisan{
    public:
        static int idSayac; /*HOCAM ÖNEMLİ*/
        int calisanid;
        string ad;
        string soyad;
        int dogduguYil;
        int yas;
        int calismayaBasladigiYil;
        int calismayaBasladigiAy;
        int calismayaBasladigiGun;
        int calistigiYil;
        int pozisyon;
        string pozisyonadi;
        int maas;
// /////////////////////////////////////////////////////
       int idOlustur() {
           ++idSayac;
           return idSayac;
           };
       Calisan(){
           idOlustur();
           };

// //////////////////////////////////////////////////////
    int calisanEkleme (ofstream& dosya){
        cout << "Yeni bir calisan ise alma ekranina hos geldiniz!" << endl;
        calisanid = idOlustur();
        cout << "Calisanin adini giriniz : " <<endl;
        cin.ignore();
        getline(cin, ad);
        cout << "Calisanin soyadini giriniz : " << endl;
        cin.ignore();
        getline(cin, soyad, '\n');
        cout << "Calisanin dogdugu yili giriniz: " << endl;
        cin >> dogduguYil ;
        cin.ignore();
        cout << "Calisanin yasini giriniz: " << endl;
        cin >> yas;
        cout << "Calismaya basladigi yili giriniz: " << endl;
        cin >> calismayaBasladigiYil;
        cout << "Calismaya basladigi ayi sayi cinsinden giriniz: " << endl;
        cin >> calismayaBasladigiAy;
        cout << "Calismaya basladigi gunu sayi cinsinden giriniz: " << endl;
        cin >> calismayaBasladigiGun;
        cout << "Calisanin sirket icindeki deneyim suresini giriniz: " << endl;
        cin >> calistigiYil;
        cout << "Maasini giriniz: " << endl;
        cin >> maas;
        while (1){
        cout << "Calisanin pozisyonunu belirlemek icin seciniz: \n Calisan: 1 \n Proje Lideri: 2 \n Mudur: 3 \n";
        cin >> pozisyon;
        if (pozisyon !=1 && pozisyon != 2 && pozisyon != 3){
            cout << "\n !!!! Gecerli bir pozisyon giriniz!!!: ";
        }
        else {
            break;
            }
        }
        if (pozisyon == 1){ pozisyonadi = "Calisan";}
        if (pozisyon == 2){ pozisyonadi = "Proje Lideri";}
        if (pozisyon == 3){ pozisyonadi = "Mudur";}
        dosya << "Id: " << calisanid << ", ";
        dosya << "Calisan adi: " << ad << ", ";
        dosya << "Calisan soyadi: " << soyad << ", ";
        dosya << "Calisanin yasi: " << yas << ", ";
        dosya << "Calismaya basladigi tarih: " << calismayaBasladigiGun << "-" << calismayaBasladigiAy << "-" << calismayaBasladigiYil << ", ";
        dosya << "Calisan Maasi: " << maas << ", " ;
        dosya << "Calistigi yil: " << calistigiYil << ", ";
        dosya << "Calistigi pozisyon: " << pozisyonadi << ", " <<endl;
        cout << "\nDosya yazma islemi tamamlanmistir!...\n";
        cout << "-----------------------------------------\n";
        dosya.close();
// //////////////////////////////////////////////////////
   }
};
void renameFile(const std::string& oldFileName, const std::string& newFileName){
     std::fstream dosya(oldFileName);

     dosya.seekg(0, std::ios::beg); // Dosyanın başına git
     cout << "dosyanin basina gitmek basarili ";
     std::string yeniIcerik = "Yeni içerik"; // Yeni içeriği tanımla
    cout << "yeni icerik tanimlama basarili ";
     dosya.write(yeniIcerik.c_str(), yeniIcerik.length()); // Yeni içeriği dosyaya yaz
    cout << "yeni icerigi dosyaya yazmak basarili sanirim";
     dosya.close(); // Dosyayı kapat
}
void deleteEmployeeById(int id) { // BU KISMI YAPAY ZEKADAN (Ç)ALDIM
    // Geçici dosyayı oluşturmak için bir geçici ofstream nesnesi oluşturun
    ofstream tempFile("data/temp_database.txt");
    // Orijinal dosyayı okumak için bir ifstream nesnesi oluşturun
    ifstream originalFile("data/database.txt");
    // Dosyanın açılıp açılmadığını kontrol edin
    if (!tempFile || !originalFile) {
        cerr << "Dosya açılamadı." << endl;
        return;
    }
    string line;
    bool deleted = false;
    // Orijinal dosyadan satır okuyun
    while (getline(originalFile, line)) {
        // Satırı parçalayın ve ID'yi alın
        stringstream ss(line);
        string token;
        int currentId = -1; // ID'nin -1'e eşit olduğunu varsayalım
        while (getline(ss, token, ',')) {
            if (token.find("Id:") != string::npos) {
                currentId = stoi(token.substr(token.find(":") + 1)); // ID'yi bulun
                break;
            }
        }
        // Silinecek ID'yi bulduysanız, o satırı geçin
        if (currentId == id) {
            deleted = true;
            continue;
        }
        // Geçici dosyaya satırı yazın
        tempFile << line << endl;
    }
    // Dosyaları kapatın
    tempFile.close();
    originalFile.close();
    // Silinmiş bir satır olup olmadığını kontrol edin
    if (!deleted) {
        cout << "ID bulunamadı." << endl;
        // Geçici dosyayı silin
        remove("data/temp_database.txt");
        return;
    }
    // Orijinal dosyayı silin
    remove("data/database.txt");

    // Geçici dosyayı yeniden adlandırarak orijinal dosyayı oluşturun
    rename("data/temp_database.txt", "data/database.txt");

    cout << "ID başarıyla silindi." << endl;
}
int idOlusturma(){ // Bu fonkisoynun amacı, id'yi sürekli resetlememek ve devamlı bir yerde kayıtlı tutmak.
    ifstream calisanIdKayit("idkayit.txt"); // elimle oluşturduğum "idkayit.txt"i okutuyorum.
    if (calisanIdKayit.is_open()){ // eğer dosya açılmışsa program tarafından sorunsuzca
        calisanIdKayit >> idKayit;// dosyanın içinde yazan sayıyı al benim int idKayit'imin içine at
        idKayit ++; // ve idKayit'i 1 arttır. 1 arttır ki devamlı değişsin içindeki sayı
    }
    calisanIdKayit.close(); // sonra dosyayı kapa da başımıza iş almayalım kullanmasak nolur idk
    ofstream calisanIdGuncelle("idkayit.txt", ios::out); // aynı dosyayı bi de YAZMAK için açalım bakalım
    if (calisanIdGuncelle.is_open()){ // eğer dosya sorunsuzca açılmışsa
        calisanIdGuncelle << idKayit;// daha demin 1 arttırdığım idKayit geri dosyaya yaz eskisini silerek.
    }
    calisanIdGuncelle.close(); // askim isiklari kapa
    return idKayit; // BU FONKSİYON İŞİ BİTTİĞİNDE "nesneNum" SAYISINI İFADE EDİYOR VE BU MUHTEŞEM BİŞEY.
}
int Calisan::idSayac = idOlusturma();

int idBul(ifstream& dosyas, int id) {
    string satir;
    int satirSayaci = 0;
    bool bulundu = false;

    while (getline(dosyas, satir)) {
        satirSayaci++;
        if (satir.find("Id: " + to_string(id)) != string::npos) {
        cout << "Satiriniz: " << satir;
        bulundu = true;
        break;
            }
        }
    if (!bulundu) {
        cout << "Uyari: Aradiginiz ID'li satir bulunamadi." << endl;
        return 0;
    }
        dosyas.close();
    }
int main(){
    ofstream verigir("data/database.txt", ios::app);
    ifstream verial("data/database.txt");
    Calisan calisan1;
    string filename = "data/database.txt";
    int idToDelete;
    while(idOlusturma()){
    int anaMenuSecim;
    cout << "\nAna menuye hos geldiniz! \n\nYeni bir calisan eklemek icin 1'i\nId ile bir calisan aramak icin 2'yi\nId no ile calisan silmek icin 3'u seciniz...\n:"; // cok büyük ucubelik biliyorum, bana bilmediğim bir şey söyle.
    cin >> anaMenuSecim;
    while(1){ // bu while döngüsünün amacı, eğer ki kullanıcı menüde yazmayan bir sayı girerse;;;
        if(anaMenuSecim != 1 && anaMenuSecim != 2 && anaMenuSecim !=3) // if ve AND(&&) kapısı ile bunu kontrol etsin;;;
        {
            cout << "Lutfen menudeki bir secenegi giriniz...: "; // ve yer yanlis giriste tekrar tekrar uyarsın;;;
            cin >> anaMenuSecim; // ve yeniden anaMenuSecim degeri istesin bizden ;;;
        }
        else {
            cout << "Secim basarili! Islem gerceklestiriliyor...\n";
            cout << "--------------------------------------------\n";
            break; //taa ki kullanıcının girdiği değer 1 2 ve 3ten biri olana dek;;;
        }
    }
        if (anaMenuSecim == 1){
            calisan1.calisanEkleme(verigir);
            verigir.close();
        }
        if (anaMenuSecim == 2){
            int idarama;
            cout << "Bulmak istediginiz Id'i giriniz..: ";
            cin >> idarama;
            idBul(verial,idarama);
            verial.close();
        }
        if (anaMenuSecim == 3){
            verigir.close();
            verial.close(); 
            cout << "Enter the ID of the employee to delete: ";
            cin >> idToDelete;
            deleteEmployeeById(idToDelete);
            }
        }
    }