#include <iostream>
#include <map>
#include <string>
#include <limits> // numeric_limits için gerekli
using namespace std;

class Kitap
{
public:
    string kitapAdi;
    string yazarAdi;
    int rafNo;

    Kitap()
    {
        kitapAdi = "";
        yazarAdi = "";
        rafNo = 0;
    }

    Kitap(string kitapAdi, string yazarAdi, int rafNo)
    {
        this->kitapAdi = kitapAdi;
        this->yazarAdi = yazarAdi;
        this->rafNo = rafNo;
    }
};

// Gecerli bir sayi girilene kadar tekrar sorar.
// Satir sonunu da temizledigi icin sonrasinda getline guvenle kullanilabilir.
int sayiOku(const string &mesaj)
{
    int deger;
    cout << mesaj;
    while (!(cin >> deger))
    {
        cout << "Hatali giris! Lutfen sayi girin: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return deger;
}

void kitapListele(const map<int, Kitap> &mkutuphane)
{
    if (mkutuphane.empty())
    {
        cout << "\nKutuphanede kayitli kitap bulunmuyor!\n";
        return;
    }

    cout << "\n* * * Kutuphanedeki Kitaplar: * * * *\n";
    /*
    for (auto it = mkutuphane.begin(); it != mkutuphane.end(); it++){
        int id = it->first;    //key
        const Kitap& kitap = it->second;    //value
        cout<<" Kitap ID: "<< id << " Ad: "<< kitap.kitapAdi
            <<" Yazar: " << kitap.yazarAdi << " Raf No: "<< kitap.rafNo << endl;

    }
    */
    for (const auto &kitapPair : mkutuphane)
    {
        cout << "Kitap ID: " << kitapPair.first
             << ", Kitap Adi: " << kitapPair.second.kitapAdi
             << ", Yazar: " << kitapPair.second.yazarAdi
             << ", Raf No: " << kitapPair.second.rafNo << endl;
    }
}

int main()
{
    map<int, Kitap> mkutuphane;
    int secim;

    do
    {
        // Menu
        cout << "\n=== Kutuphane Yonetim Sistemi ===\n";
        cout << "1. Kitap Ekle\n";
        cout << "2. Kitap Bilgileri Goruntule\n";
        cout << "3. Kitap Sil\n";
        cout << "4. Kitaplari Listele\n";
        cout << "5. Cikis\n";

        secim = sayiOku("Lutfen Seciminizi Yapin: ");

        switch (secim)
        {
        case 1:
        {
            // Kitap Ekleme
            string kitapAdi, yazarAdi;
            int kitapID = sayiOku("\nKitap ID: ");

            cout << "Kitap Adi: ";
            getline(cin, kitapAdi);
            cout << "Yazar Adi: ";
            getline(cin, yazarAdi);
            int rafNo = sayiOku("Raf No: ");

            mkutuphane[kitapID] = Kitap(kitapAdi, yazarAdi, rafNo);
            cout << "Kitap basariyla eklendi...\n";
            break;
        }

        case 2:
        {
            // Kitap Bilgileri Goruntuleme
            int kitapID = sayiOku("\nBilgileri Goruntulemek Istediginiz Kitap ID: ");
            auto it = mkutuphane.find(kitapID);
            if (it != mkutuphane.end())
            {
                const Kitap &kitap = it->second;
                cout << "Kitap Adi: " << kitap.kitapAdi << " , Yazari: " << kitap.yazarAdi << " , Raf No: "
                     << kitap.rafNo << endl;
            }
            else
            {
                cout << "Kitap bulunamadi!\n";
            }
            break;
        }

        case 3:
        {
            // Kitap Silme
            int kitapID = sayiOku("\nSilmek Istediginiz Kitap ID: ");
            if (mkutuphane.erase(kitapID))
            {
                cout << "Kitap basariyla silindi.\n";
                kitapListele(mkutuphane);
            }
            else
            {
                cout << "Kitap Bulunamadi!\n";
            }
            break;
        }
        case 4:
        {
            // Kitaplari listeleme
            kitapListele(mkutuphane);
            break;
        }

        case 5:
            cout << "\n Cikis yapiliyor , hoscakalin...\n";
            break;
        default:
            cout << "\nGecersiz bir secim yaptiniz.Lutfen 1-5 arasinda bir deger giriniz...\n";
        }

    } while (secim != 5);

    return 0;
}
