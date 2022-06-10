#include <iostream>
#include <iomanip>
using namespace std;
struct Buku
{
    string judul;
    string penulis;
    string genre;
    string kode;
    int harga;
};
/*void inputBuku(int x){
	cout<<"Masukkan	Judul Buku   : ";getline(cin,buku[x].judul);
	cout<<"Masukkan Penulis Buku : ";getline(cin,buku[x].penulis);
	cout<<"Masukkan Genre Buku   : ";getline(cin,buku[x].genre);
	cout<<"Masukkan Kode Buku    : ";cin>>buku[x].kode;
	cout<<"Masukkan Harga Buku   : ";cin>>buku[x].harga;
}*/

int main(){
	int pilihMenu;
	string pass;
	int urutBuku=0,x=0;
    menuUtama:
	cout << "=========================================================================\n";
    cout << "=               Selamat Datang Di Self Machine Book Store               =\n";
    cout << "=========================================================================\n";
    cout << "=                          Silahkan Pilih Menu                          =\n";
    cout << "= 1. Pembelian Buku                                                     =\n";
    cout << "= 2. Admin Mode                                                     =\n";
    cout << "= 3. Exit/Keluar                                                        =\n";
    cout << "=========================================================================\n";
    cout << "  Masukan Pilihan : ";
    cin>>pilihMenu;
    system("cls");
    if (pilihMenu==1){
    	if(x!=1){
    		cout<<"Menu Buku Kosong!\n";
        	cout<<"Silahkan Isi Terlebih Dahulu!\n\n";
        	system("pause");
        	system("cls");
        	goto menuUtama;
    	}else{
    		cout<<"===========================================\n";
            cout<<"=             Pembelian Buku              =\n";
            cout<<"===========================================\n";
    	}
    }else if(pilihMenu==2){
    	cout<<"Masukkan password : ";cin>>pass;
    	system("cls");
    	if(pass=="admint"){
    		Buku buku1;
    		cin.ignore();
    		cout<<"Masukkan Judul Buku   : ";getline(cin,buku.judul);
			cout<<"Masukkan Penulis Buku : ";getline(cin,buku.penulis);
			cout<<"Masukkan Genre Buku   : ";getline(cin,buku.genre);
			cout<<"Masukkan Kode Buku    : ";cin>>buku.kode;
			cout<<"Masukkan Harga Buku   : ";cin>>buku.harga;
    		//inputBuku(x);
    	}else{
    		cout<<"Password Salah!\n";
            system("pause");
            system("cls");
            goto menuUtama;
    	}
    }else if(pilihMenu==3){
    	system("cls");
    	system("pause");
    	return 0;
    }else{
    	system("cls");

    	goto menuUtama;
    }
}
   

