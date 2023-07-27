#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#define N 100

using namespace std;
// MENÜ ÝÇÝN FONKSÝYONLAR
		int rezervasyon();
		int rezervasyon_iptali();
		int yolcu_aramak();
		int listeyi_yazdirmak();
		int durum_raporu();
		int rez_duzenle();
		
		struct coklu_havayolu {
		int secim; //MENÜ ÝÇÝN SEÇÝM YAPILDI
		int sinif; //CLASLAR TANIMLANDI
		int n,i;
		string num;
		// KÝÞÝ BÝLGÝLERÝ OLUÞTURULDU
		string isim;
		string soyisim;
		string tc;
		string yas;
		string telefon_no;
		string pasaport;
		string varis_noktasi;
		string e_mail; }yd;
		struct dizi{  
		string satir; };
		dizi str_s[N];
		int main() {	system("color 8"); // YAZI RENGÝ 
		//MENÜ OLURÞTURULDU
		do{	
		cout<<"********************************************"<<endl;
		cout<<"*           HAVAYOLLARI REZERVASYON        *"<<endl;
		cout<<"*                 SISTEMINE                *"<<endl;	
		cout<<"*                HOSGELDINIZ               *"<<endl;
		cout<<"********************************************"<<endl;		
		cout<<"*            MENU SECENEKLERI              *"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"*              1.REZERVASYON               *"<<endl;
		cout<<"*          2.REZERVASYON IPTALI            *"<<endl;	
		cout<<"*             3.YOLCU ARAMAK               *"<<endl;	
		cout<<"*      4.REZERVASYONDA DEGISIKLIK          *"<<endl;
		cout<<"*          5.LISTEYI YAZDIRMAK             *"<<endl;
		cout<<"*        6.DURUM RAPORU CIKARMAK           *"<<endl;
		cout<<"*                 7.CIKIS                  *"<<endl;
		cout<<"********************************************"<<endl;
		cout<<"LUTFEN YAPMAK ISTEDIGINIZ ISLEMI SECINIZ VE ENTER TUSUNA BASINIZ:";	cin>>yd.secim; //MENÜ SEÇÝMLERÝ SUNULDU
		// SEÇÝMLER
		switch(yd.secim)	{
		case 1:	rezervasyon();	break; //REZERVASYON YAPILDI
		case 2:	rezervasyon_iptali();	break; //REZERVASYON ÝPTAL EDÝLDÝ
		case 3: yolcu_aramak( );  break; //YOLCU ARANDI
		case 4: rez_duzenle(); break; //REZERVASYON DÜZENLENMESÝ YAPILDI
		case 5:	listeyi_yazdirmak();	break; //KÝÞÝ LÝSTESÝ YAZILDI
		case 6: durum_raporu();	break; //RAPOR ÇIKARILDI
		case 7:	cout << "\n   //....IYI GUNLER DILERIZ....//" << endl; break; //ÇIKIÞ YAPILDI
		default:	cout<<"Yanlis sectiniz !"; } 	}
		while(yd.secim!=7); // 1-7 ARASI HARÝCÝNE SEÇÝM YAPILMAMISINI BELIRTIR
		return 0;  }
int rezervasyon(){
		//REZERVASYON YAPIM FONKSIYONU
		system("cls");
		if(yd.secim==1){	
		cout<<"Kac Kisi Icin Rezervasyon Yapicaksiniz ?  :";	cin>>yd.n; 	fflush(stdin);
		for(yd.i=0; yd.i<yd.n; yd.i++){
		cout<<yd.i+1<<". Kisinin Rezervasyonu:"<<endl;
		cout<<"LUTFEN 1. EKONOMI  2.PREMIUM EKONOMI 3. BUSINESS CLASS SECINIZ :";	cin>>yd.sinif; //SINIF SEÇÝMÝ YAPTIRIR
        while(yd.sinif) {
   	    if(yd.sinif==1){ 
		cout<<"SINIFINIZ EKONOMI SINIFI "<<endl;
		cout<<"NUMARANIZ "<<yd.i+1<<endl;	break; }
		else if(yd.sinif==2)	{
		cout<<"SINIFINIZ PREMIUM EKONOMI SINIFI"<<endl;
		cout<<"NUMARANIZ "<<yd.i+1<<endl;	break; }
		else if(yd.sinif==3) {
		cout<<"SINIFINIZ BUSINESS CLASS"<<endl; 
		cout<<"NUMARANIZ "<<yd.i+1<<endl;	break; }
		else{
		cout<<"LUTFEN DOGRU  SECINIZ:"; 	cin>>yd.sinif;	} }
		//KÝÞÝ BÝLGÝLERÝNÝ DOSYAYA YAZDIRMA
		ofstream dosya("kayýtlar.txt",ios::app);
		cout<<"ISIM:";	cin>>yd.isim;  fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun Adi:"<<yd.isim<<endl;
		cout<<"SOYISIM:";	cin>>yd.soyisim;	fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun Soyadi:"<<yd.soyisim<<endl;
		cout<<"TC:";	cin>>yd.tc;  	fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun TC si:"<<yd.tc<<endl;
		cout<<"YAS:";   cin>>yd.yas;     fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun Yasi:"<<yd.yas<<endl;
		cout<<"TELEFON NUMARANIZ:"; 	cin>>yd.telefon_no; 	fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun Telefon Numarasi:"<<yd.telefon_no<<endl;
		cout<<"PASAPORT NUMARANIZ:";	cin>>yd.pasaport;	fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun Pasaport Numarasi:"<<yd.pasaport<<endl;
		cout<<"VARIS NOKTASINI YAZINIZ:"; 	cin>>yd.varis_noktasi; 	fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun Varis Noktasi:"<<yd.varis_noktasi<<endl;
		cout<<"E-MAIL:";	cin>>yd.e_mail;  fflush(stdin);
		dosya<<"\t"<<yd.i+1<<". Yolcunun E-maili:"<<yd.e_mail<<endl;
		dosya << "\n" << endl; 
  	    dosya.close();
  	    cout << "----------------------" << endl;
		 }}}
int rezervasyon_iptali()  {
//REZERVASYON ÝPTALÝ
		if(yd.secim==2){ system("cls");
		string sil_tc;
		cout<<"***RANDEVU IPTALI***"<<endl;
		cout<<"Silinecek Yolcunun TC sini Giriniz-->";   cin>>sil_tc;
		ifstream dosya;
		dosya.open("kayýtlar.txt", ios::in);	// YAZDIÐIMIZ DOSYANIN OKUMA MODUNU AÇAR.
		ofstream yenidosya;
		yenidosya.open("yeni_kullanici_kayitlarý.txt", ios::out); //YENÝ DOSYA AÇAR
		while(getline(dosya,str_s[yd.i].satir,'	'))	{
		size_t aranan = str_s[yd.i].satir.find(sil_tc);		
		if (aranan != string::npos)
    	continue;	
		//cout << str_s[i].satir << endl;
    	yenidosya << str_s[yd.i].satir << "\t";
    	yd.i+1;		}
		yenidosya.close();
		dosya.close();
		if(remove("kayýtlar.txt") != 0)	{
		cout << " Dosya Kaldirilamadi";	}
		else	{
		cout << "Rezervasyonunuz iptal edilmistir!!!" << endl;	}
		if(rename("yeni_kullanici_kayitlarý.txt","kayýtlar.txt") != 0) {
		cout << " Dosya Yeniden Adlandirilamadi";	}
		else	{
		cout  << endl; } } }
int yolcu_aramak() {
	if(yd.secim==3){
     cout<<"Aranilacak Kisinin Isim ve Soyismini Giriniz :";
	    cin>>yd.isim;   cin>>yd.soyisim; //ARANILACAK KÝÞÝNÝN BÝLGÝLERÝ ÝSTENÝR
		string ilk_isim = "ÝSÝM VE SOYÝSÝM: " +yd.isim+ " " +yd.soyisim;
		string son_isim = "	"; 
		ifstream dosya;
		dosya.open("kayýtlar.txt", ios::in);	//DOSYAYA GÝDER
		string line;
		string degis;
		string *ptr = &line;
		while(getline(dosya,line,'	')) 	{
		if(line == ilk_isim) {	 
		while(getline(dosya,degis))	{
		cout << degis << endl;	}
		/*cout << ilk_ad << endl;
		while(getline(dosya,line))	{
 		if(line == son_ad)	{			}	}*/
		exit(0);	}
		else	{
		cout << line;	}	}
		dosya.close();	exit(0); } }
int rez_duzenle()	{
	//REZERVASYON DÜZENLEME
		if(yd.secim==4){
		string sorgu_tc;
		system("cls");
		cout<<"------Yolcu Kaydi Duzenleme------"<<endl;
		ifstream dosyaOku;
		dosyaOku.open("kayýtlar.txt",ios::app);
		cout<<"Duzenlenecek Yolcunun TC Numarasi-->";  	cin>>sorgu_tc;
		if(yd.tc==sorgu_tc){
		dosyaOku.close();
		ofstream dosyaYaz;
		dosyaYaz.open("yeni_kullanici_kayitlarý.txt",ios::app);
		cout<<"========== Yolcu Bilgilerini Duzenleyiniz =========="<<endl;
		cout<<"\n Yolcu Adini Giriniz-->"; cin>>yd.isim;
		cout<<"\n Yolcu Soyadini Giriniz-->"; cin>>yd.soyisim;
		cout<<"\n Yolcu TC sini Giriniz-->"; cin>>yd.tc;
		cout<<"\n Yolcu Pasaport NO Giriniz-->"; cin>>yd.pasaport;
		cout<<"\n Yolcu Varis Noktasini Giriniz-->"; cin>>yd.varis_noktasi;
		cout<<"\n Yolcu Telefon NO Giriniz-->"; cin>>yd.telefon_no;
		cout<<"\n Yolcu Yasini Giriniz-->"; cin>>yd.yas;
		cout<<"\n Yolcu E-mail Giriniz-->"; cin>>yd.e_mail;
		dosyaYaz<<"\n"<<yd.isim<<"\n"<<yd.soyisim<<"\n"<<yd.tc<<"\n"<<yd.telefon_no<<"\n"<<yd.varis_noktasi<<"\n"<<yd.pasaport<<"\n"<<yd.yas<<"\n"<<yd.e_mail;
		dosyaYaz.close();		}
		else	{
		cout<<"Yolcu Bulunamadi"<<endl;	}
		remove("kayýtlar.txt");
		rename("yeni_kullanici_kayitlarý.txt","kayýtlar.txt");	}  }
int listeyi_yazdirmak()	{
		//LÝSTE YAZDIRMA
		system("cls");
		if(yd.secim==5) 	{
		cout<<"----------------------Ucaktaki Yolcularin Bilgileri----------------------"<<endl;
		ifstream dosya("kayýtlar.txt");
		string kelime;
		while(getline(dosya,kelime)){
		cout<<kelime << endl; 	}
		dosya.close();	}else return 0; 	}
int durum_raporu() 	{
		//RAPOR ÇIKARMA
		system("cls");
		if(yd.secim==6){
		cout<<"Lutfen Ucus Raporunu Gormek Istediginiz Yolcunun TC numarasini Giriniz:"; 	cin>>yd.num;
		if(yd.tc==yd.num){
		ifstream dosya("kayýtlar.txt");
		string satir;
		cout<<"-------------------TC'si Girilen Yolcunun Bilgileri----------------"<<endl;
		while(getline(dosya,satir)){
		cout<<satir<<endl;} 	}
		else 
		cout<<"Lutfen Gecerli TC giriniz!!!";	}  else return 0;	}
