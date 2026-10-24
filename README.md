# Kütüphane Yönetim Sistemi

C++ ile yazılmış, komut satırında çalışan basit bir kütüphane yönetim uygulaması.

> **Not:** Bu proje bir **pratik yapma projesidir**. C++ öğrenme sürecimde sınıflar (class), `std::map` kullanımı ve kullanıcı girişi doğrulama konularını pekiştirmek için yazdım. Ticari veya üretim amaçlı bir yazılım değildir.

## Özellikler

Program, aşağıdaki menü üzerinden çalışır:

1. **Kitap Ekle:** Kitap ID, kitap adı, yazar adı ve raf numarası girilerek yeni kitap eklenir.
2. **Kitap Bilgileri Görüntüle:** Girilen ID'ye ait kitabın bilgileri gösterilir.
3. **Kitap Sil:** Girilen ID'ye ait kitap silinir, ardından güncel liste gösterilir.
4. **Kitapları Listele:** Kütüphanedeki tüm kitaplar ID sırasına göre listelenir.
5. **Çıkış:** Programdan çıkılır.

## Kullanılan Konular

- **Sınıflar (class):** `Kitap` sınıfı; kitap adı, yazar adı ve raf numarasını tutar. Varsayılan ve parametreli yapıcı fonksiyon (constructor) içerir.
- **`std::map<int, Kitap>`:** Kitaplar, ID'leri anahtar (key) olacak şekilde saklanır. Bu sayede ID'ye göre arama (`find`), silme (`erase`) ve sıralı listeleme kolaylaşır.
- **Kullanıcı girişi doğrulama:** `sayiOku` yardımcı fonksiyonu, sayı beklenen yerlerde harf girilirse hata mesajı verir ve doğru değer girilene kadar tekrar sorar (`cin.clear()` ve `cin.ignore()` kullanımı).
- **`cin` ve `getline` birlikte kullanımı:** Satır sonu karakteri temizlenerek boşluk içeren kitap ve yazar adlarının doğru okunması sağlanır.
- **`const` referans ile parametre geçirme:** Gereksiz kopyalamayı önlemek için `kitapListele` fonksiyonunda kullanılır.
- **Menü yapısı:** `do-while` döngüsü ve `switch-case` ile oluşturulmuştur.

## Derleme ve Çalıştırma

Bilgisayarında bir C++ derleyicisi (örneğin `g++`) kurulu olmalıdır.

```bash
g++ kutuphane.cpp -o kutuphane
./kutuphane
```

Windows'ta çalıştırmak için:

```bash
g++ kutuphane.cpp -o kutuphane.exe
kutuphane.exe
```

## Örnek Kullanım

```
=== Kutuphane Yonetim Sistemi ===
1. Kitap Ekle
2. Kitap Bilgileri Goruntule
3. Kitap Sil
4. Kitaplari Listele
5. Cikis
Lutfen Seciminizi Yapin: 1

Kitap ID: 1
Kitap Adi: Simyaci
Yazar Adi: Paulo Coelho
Raf No: 12
Kitap basariyla eklendi...
```

## Bilinen Eksikler ve Geliştirme Fikirleri

- Aynı ID ile kitap eklenirse eski kayıt üzerine yazılır. İleride ID kontrolü eklenebilir.
- Negatif ID veya raf numarası şu an kabul ediliyor.
- Kitaplar sadece program çalışırken bellekte tutulur. Kapatıldığında veriler silinir. Dosyaya kaydetme (ör. `fstream` ile) eklenebilir.
- Kitap adına veya yazara göre arama özelliği eklenebilir.

## Proje Yapısı

```
kutuphane/
├── kutuphane.cpp
└── README.md
```

## Lisans

Bu proje eğitim amaçlıdır; dilediğiniz gibi inceleyebilir ve kullanabilirsiniz.
