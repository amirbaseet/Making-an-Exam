// cppproje2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
using namespace std;
//OGRENCI SINIFI OLUSTURUP GEREKEN VERILER TANITIM
class Ogrenci
{
public:
	int Tc;
	string Ad;
	string Sefre;

	void bilgi_al()//disardan Ogreninin bilgilerinin girdirilme Metodu
	{
		cout << "\nOgrencinin Tcesi girin :"; 
		cin >> Tc;
		cout << "\nOgrencinin Adi giriniz :";
		cin >> Ad;
		cout << "\nOgrencinin Sefresi giriniz :";
		cin >> Sefre;
		cout << endl;
	}
	void bilgi_Yazdir() //Ogrencinin Var Olan bilgileri Yazdirma
	{
		cout << "Ogrencinin Tc esi :\t" << Tc
			<< "\t Ad :\t" << Ad
			<< "\t Sefresi :\t" << Sefre
			<< endl;

	}
}Ogrenci_Test;//Ogrenci Sininfindan bir nesne Olusturdum

fstream Ogrenci_islem;//Fstream sinifindan bir nesne olusturdum (OKUMAk,YAZMAk)Icin
bool Ogrenci_Varmi(int silenecek_Tc)//Ogrenci Veri tabana BakIp var olup olmadigini Kontrol eden Bir metoddur
{
	bool test = false;
	int sayac = 0;
	Ogrenci_islem.open("Ogrenci0.txt", ios::in);
	while (Ogrenci_islem.read((char*)&Ogrenci_Test, sizeof(Ogrenci_Test)))//Dosy okuma hale getirip Ogrenci_Test Nesnesi char araayi donusturmaktadir
	{
		if (silenecek_Tc == Ogrenci_Test.Tc)//Eger Eklenecek Ogrencinin TC esi eklenecek Tcesi Ayni ise Sayaca bire eklenecek
		{
			sayac++;
		}
	}
	Ogrenci_islem.close();
	if (sayac == 0)
		test = false;//yoksa Test =False
	else
		test = true;//Varsa Test = true

	return test;

}
void Oturum_AC(int Tc,string Sefere)
{

	bool test = Ogrenci_Varmi(Tc);
	if (test ==true)
	{
		Ogrenci_islem.open("Ogrenci0.txt", ios::in);
		while (Ogrenci_islem.read((char*)&Ogrenci_Test, sizeof(Ogrenci_Test)))//Dosy okuma hale getirip Ogrenci_Test Nesnesi char araayi donusturmaktadir
		{
			if ((Tc == Ogrenci_Test.Tc )&& (Sefere == Ogrenci_Test.Sefre))//Eger Eklenecek Ogrencinin TC esi eklenecek Tcesi Ayni ise Sayaca bire eklenecek
			{
				cout << "Hos Geldiniz :\t"<< Ogrenci_Test.Ad;
			}
			else if ((Tc == Ogrenci_Test.Tc) && (Sefere != Ogrenci_Test.Sefre))
			{
				cout << "Girdiginiz Sefre Hatali\n";
			}
		}
		Ogrenci_islem.close();
	}
	else
	{
		cout << "Oturum acilmaz girdiginiz Tc veri tabanda bulumamaktadir\n";
	}
}
void Ogrenci_ekle() //Veri tabana Ogrenci Ekleme Metodu
{
	Ogrenci Eklen_Ogr;//Ogrenci Sininfindan bir nesne Olusturdum
	Eklen_Ogr.bilgi_al();//Disardan alacak bilgileri cagirdim
	
	bool test = Ogrenci_Varmi(Eklen_Ogr.Tc);//Ogrenci veri tabanda var olup olmadigini bir metod Cagirdim
	
	if (test == false)//Yoksa EKlenecek
	{
		cout << "Ogrenci Ekliyorum\n";
		Ogrenci_islem.open("Ogrenci0.txt", ios::app);
		Ogrenci_islem.write((char*)&Eklen_Ogr, sizeof(Eklen_Ogr));
		Ogrenci_islem.close();
	}
	else
	{
		cout << "Ekleme Yapilmaz Ogreci veri tabanda bulundu\n";
	}
}

//	void Ogrenci_ekle() 
//{
//	Ogrenci Eklen_Ogr;
//	int sayac = 0;
//
//	//Ogrenci_Test.bilgi_al();
//	Eklen_Ogr.bilgi_al();
//	Ogrenci_islem.open("Ogrenci0.txt", ios::in);
//	while (Ogrenci_islem.read((char*)&Ogrenci_Test, sizeof(Ogrenci_Test)))
//	{
//		if (Eklen_Ogr.Tc == Ogrenci_Test.Tc)
//		{
//			sayac++;
//		}
//	}
//	Ogrenci_islem.close();
//
//	if (sayac == 0)
//	{
//		cout << "Ogrenci Ekliyorum\n";
//		Ogrenci_islem.open("Ogrenci0.txt", ios::app);
//		Ogrenci_islem.write((char*)&Eklen_Ogr, sizeof(Eklen_Ogr));
//		Ogrenci_islem.close();
//	}
//	else
//	{
//		cout << "Ekleme Yapilmaz Ogreci veri tabanda bulundu\n";
//	}
//	}
void Ogrenci_listele() //Veri tabanda Tum verileri Yazdirma
{
	Ogrenci_islem.open("Ogrenci0.txt", ios::in);
	while(Ogrenci_islem.read((char*)&Ogrenci_Test, sizeof(Ogrenci_Test)))
	{
		Ogrenci_Test.bilgi_Yazdir();
		cout << " ============================================== \n";
	}
	Ogrenci_islem.close();
}
void Ogrenci_silme(int silenecek_TC) //Veri Tabandan Silenecek Ogrenci Metodu
{
	bool test = Ogrenci_Varmi(silenecek_TC);//Ogrenci veri tabanda var olup olmadigini bir metod Cagirdim

	if (test == true) {//Varsa Silenecek Yoksa Silenmez

		Ogrenci_islem.open("Ogrenci0.txt", ios::in | ios::out);
		fstream silme;
		silme.open("silenecek.txt", ios::out);
		Ogrenci_islem.seekg(0, ios::beg);
		while (Ogrenci_islem.read((char*)&Ogrenci_Test, sizeof(Ogrenci_Test)))
		{
			if (Ogrenci_Test.Tc != silenecek_TC)
			{
				silme.write((char*)&Ogrenci_Test, sizeof(Ogrenci_Test));
			}
		}
		silme.close();
		Ogrenci_islem.close();
		remove("Ogrenci0.txt");
		int a = rename("silenecek.txt", "Ogrenci0.txt");
		if (a == 0)
			cout << "\islem basarli";
		else
			cout << "\n islem basarsizdir";
	}
	else
	{
		cout << "silme Yapilmaz Ogrenci veri tabanda bulunmadi\n";
	}
}

class Sinav
{
public:
	string isim;
	int Suresi;
	string Soru_sayisi;
	int Tc_Sinavagirecekler;



};
class Soru 
{
public :
	string SoruText;
	string Secenekler[5];
	string Cevap;
	double Puan;
	string ZorlukSeviye;
};

int main()
{
	Ogrenci_listele();
	cout << "Tc ve Sefre giriniz : \t";
	int tc;
	string sefre;
	cin >> tc;
	cin >> sefre;
	Oturum_AC(tc, sefre);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
