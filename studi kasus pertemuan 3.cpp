#include <iostream>
#include <fstream>
using namespace std;

class rumahmakan{
    friend istream& operator>>(istream&, rumahmakan&);
    public:
    	void jumlahharga();
    	void potongan();
    	void tampilan();
    	void membayar();
   	private :
        int pilih1,bayar,kembalian,harga,total,menu,jarak,ongkir,makan;
	    float diskon;
};

void rumahmakan::jumlahharga()
{
    ofstream hsl;
	hsl.open("strok.txt", ios::out);
  
	cout << "       RUMAH MAKAN        " << endl;
	cout << "==========================" << endl;
	cout << "Menu Makanan dan Harga :  " << endl;
	cout << "1. Ayam Geprek  : Rp21.000" << endl;
	cout << "2. Ayam Goreng  : Rp17.000" << endl;
	cout << "3. Udang Goreng : Rp19.000" << endl;
	cout << "4. Cumi Goreng  : Rp20.000" << endl;
	cout << "5. Ayam Bakar   : Rp25.000" << endl;
	
	//memasukan menu yg dipilih
	cout <<"\nBanyak pesanan : ";
	cin >> menu;
  
	hsl << "======================"<< endl;
	hsl << "menu yang di pesan: "<<endl;
	hsl.close(); 
	for(int a=1;a<=menu;++a){
		cout << "\nSilahkan Pilih Menu Anda : ";
		cin >> pilih1;
		if (pilih1==1){
			cout << "1. Ayam Geprek : Rp21.000" << endl;
	    	harga=harga+21000;
			ofstream hsl;
			hsl.open("struct.txt", ios::app);
			hsl << "1. Ayam Geprek : Rp21.000"<<endl;
			hsl.close(); 
		}
		else if(pilih1==2){
	    	cout << "2. Ayam Goreng : Rp17.000" << endl;
		    harga=harga+17000;
		    hsl.open("struct.txt", ios::app);
		    hsl << "2. Ayam Goreng : Rp17.000"<<endl;
		    hsl.close(); 
		}
		else if(pilih1==3){
		    cout << "3. Udang Goreng : Rp19.000" << endl;
		    harga=harga+19000;
		    hsl.open("struct.txt", ios::app);
		    hsl << "3. Udang Goreng : Rp19.000"<<endl;
		    hsl.close(); 
		}
		else if(pilih1==4){
		    cout << "4. Cumi Goreng : Rp20.000" << endl;
		    harga=harga+20000;
		    hsl.open("struct.txt", ios::app);
		    hsl << "4. Cumi Goreng : Rp20.000"<<endl;
		    hsl.close(); 
		}
		else if(pilih1==5){
		    cout << "5. Ayam Bakar : Rp25.000" << endl;
		    harga=harga+25000;
		    hsl.open("struct.txt", ios::app);
		    hsl << "5. Ayam Bakar : Rp25.000"<<endl;
		    hsl.close(); 
		}
	}
}

void rumahmakan::potongan()
{
    cout << "Masukkan Jarak dari Restoran ke Rumah Anda (dalam KM) : ";
	cin >> jarak;
	cout << "Jarak dari Restoran ke Rumah Anda adalah " << jarak << " Kilometer.";
  
	if (jarak <= 3){
	    ongkir=15000;
		if (harga <= 25000){
	    	total = harga + ongkir;
	    }
	    else  if (harga > 25000){
	    	cout << "\nAnda mendapatkan potongan ongkir sebesar Rp3.000";
	    	total = harga + ongkir-3000;
	    }
	    else if (harga > 50000){
	    	cout << "\nAnda mendapatkan potongan diskon sebesar 15% dan ongkir sebesar Rp5.000";
	    	diskon = harga * 0.15;
	    	total = harga - diskon + ongkir-5000;
	    }
	    else if ((harga > 150000)){
			cout << "\nAnda mendapatkan potongan diskon sebesar 35% dan ongkir sebesar Rp8.000";
	    	diskon = harga * 0.35;
	    	total = harga - diskon + ongkir-8000;
	    }
  	}

	else if (jarak > 3){
		ongkir=25000;
    	if (harga <= 25000){
			total = harga + 25000;
	    }
	    if ((harga > 25000) && (harga <= 50000)){
			cout << "\nAnda mendapatkan potongan ongkir sebesar Rp3.000";
	    	total = harga + 22000;
	    }
	    else if ((harga > 50000) && (harga <= 150000)){
	    	cout << "\nAnda mendapatkan potongan diskon sebesar 15% dan ongkir sebesar Rp5.000";
	    	diskon = harga * 0.15;
	    	total = harga - diskon + 20000;
	  	}
	    else if ((harga > 150000)){
	    	cout << "\nAnda mendapatkan potongan diskon sebesar 35% dan ongkir sebesar Rp8.000";
	    	diskon = harga * 0.35;
	    	total = harga - diskon + 17000;
	    }
	}
}

void rumahmakan::membayar()
{
	cout << "        RUMAH MAKAN        " << endl;
	cout << "===========================" << endl;
	cout << "Menu Makanan dan Harga :   " << endl;
	cout << "1. Ayam Geprek  : Rp21.000" << endl;
	cout << "2. Ayam Goreng  : Rp17.000" << endl;
	cout << "3. Udang Goreng : Rp19.000" << endl;
	cout << "4. Cumi Goreng  : Rp20.000" << endl;
	cout << "5. Ayam Bakar   : Rp25.000" << endl;
    cout << "\n=========================\n";
    cout << "Harga pesanan anda : "<<harga<<endl;
   	cout << "\nOngkir sebesar : "<<ongkir<<endl;
	
	if (harga > 25000){
		cout << "\nAnda mendapatkan potongan ongkir sebesar Rp3.000"<<endl;
		cout << "\nTotal Harga : " << total<<endl;
		cout << "\nUang anda : ";cin>>bayar;
		cout << "\nKembalian : " << bayar - total<<endl;
	}
	else if (harga > 50000){
		cout << "\nAnda mendapatkan potongan ongkir sebesar Rp5.000"<<endl;
		cout << "\nTotal Harga : " << total<<endl;
		cout << "\nUang anda : ";cin>>bayar;
		cout << "\nKembalian : " << bayar - total<<endl;
	}
	else if (harga > 150000){
	    cout << "\nAnda mendapatkan potongan diskon sebesar 35% dan ongkir sebesar Rp8.000"<<endl;
	    cout << "\nTotal Harga : " << total<<endl;
	    cout << "\nUang anda : ";cin>>bayar;
		cout << "\nKembalian : " << bayar - total<<endl;
	}
	else if (harga>0&&harga<=25000){
		cout << "\nTotal Harga : " << total<<endl;
		cout << "\nUang anda : ";cin>>bayar;
		cout << "\nKembalian : " << bayar - total<<endl;
	}
}	
void rumahmakan::tampilan()
{
    ofstream hsl;
	hsl.open("strok.txt", ios::out);
	hsl << "        RUMAH MAKAN        " << endl;
	hsl << "===========================" << endl;
	hsl << "Menu Makanan dan Harga :   " << endl;
	hsl << "1. Ayam Geprek  : Rp21.000" << endl;
	hsl << "2. Ayam Goreng  : Rp17.000" << endl;
	hsl << "3. Udang Goreng : Rp19.000" << endl;
	hsl << "4. Cumi Goreng  : Rp20.000" << endl;
	hsl << "5. Ayam Bakar   : Rp25.000" << endl;
    hsl << "\n=========================\n";
    hsl << "Harga pesanan anda : "<<harga<<endl;
   	hsl << "\nOngkir sebesar : "<<ongkir<<endl;
   	hsl << "\nUang Anda :"<<bayar<<endl;
	
	if (harga > 25000){
		hsl << "\nAnda mendapatkan potongan ongkir sebesar Rp3.000"<<endl;
		hsl << "\nTotal Harga : " << total<<endl;
		hsl << "\nUang anda : " << bayar<<endl;
		hsl << "\nKembalian : " << bayar - total<<endl;
		hsl.close();
	}
	else if (harga > 50000){
		hsl << "\nAnda mendapatkan potongan diskon sebesar 15% dan ongkir sebesar Rp5.000"<<endl;
		hsl << "\nTotal Harga : " << total<<endl;
		hsl << "\nUang anda : " << bayar<<endl;
		hsl << "\nKembalian : " << bayar - total<<endl;
		hsl.close();
	}
	else if ((harga > 150000)){
	    hsl << "\nAnda mendapatkan potongan diskon sebesar 35% dan ongkir sebesar Rp8.000"<<endl;
	    hsl << "\nTotal Harga : " << total<<endl;
	    hsl << "\nUang anda : " << bayar<<endl;
		hsl << "\nKembalian : " << bayar - total<<endl;
		hsl.close();
	}
	else 
	hsl << "\nTotal Harga : " << total<<endl;
	hsl << "\nUang anda : " << bayar<<endl;
	hsl << "\nKembalian : " << bayar - total<<endl;
	hsl.close();
}	
	
int main (){
	rumahmakan x;
	x.jumlahharga();
	x.potongan();
	x.membayar();
	x.tampilan();
	return 0;
}
