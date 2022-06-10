#include <iostream>
#include <iomanip>
using namespace std;
struct Buku
{
    string judul;
    string penulis;
    string kode;
    int stok;
    int harga;
    int no;
    int totalharga;
    int dibeli=0;
};
void inputBuku(Buku buku[],int &y){
	cin.ignore();
	cout<<"Masukkan Judul Buku   : ";getline(cin,buku[y].judul);
	cout<<"Masukkan Penulis Buku : ";getline(cin,buku[y].penulis);
	cout<<"Masukkan Stok Buku    : ";cin>>buku[y].stok;
	cout<<"Masukkan Kode Buku    : ";cin>>buku[y].kode;
	cout<<"Masukkan Harga Buku   : ";cin>>buku[y].harga;
	buku[y].no=(y+1);
	y++;
	system("cls");
}
void tampilBuku(Buku buku[],int y){
	for(int i=0;i<y;i++){
		cout<<setiosflags(ios::left);
		cout<<"= ";
		cout<<setw(3)<<buku[i].no;
		cout<<" | "<<setw(20)<<buku[i].judul;
		cout<<" | "<<setw(15)<<buku[i].penulis;
		cout<<" | "<<setw(5)<<buku[i].stok;
		cout<<" | "<<setw(6)<<buku[i].kode;
		cout<<" | "<<setw(8)<<buku[i].harga;
		cout<<" ="<<endl;
	}
}
void keranjang(Buku buku[],int y,int banyakBuku[],int x,int &totalBelanja){
	for(int i=0;i<y;i++){
		if(banyakBuku[i]>0){
			cout<<setiosflags(ios::left);
			cout<<"= ";
			cout<<setw(3)<<(x);
			cout<<" | "<<setw(20)<<buku[i].judul;
			cout<<" | "<<setw(15)<<buku[i].penulis;
			cout<<" | "<<setw(8)<<buku[i].harga;
			cout<<" | "<<setw(3)<<banyakBuku[i];
			cout<<" | "<<setw(8)<<buku[i].totalharga;
			cout<<" ="<<endl;
			totalBelanja = totalBelanja + buku[i].totalharga;
			x += 1;
		}
	}
}
int main(){
	int pilihMenu;
	string pass;
	char kondisi;
	int x=1,y=0,z,Qty,ubahData,totalBelanja=0;
	Buku buku[1000];
	int banyakBuku[1000];
	//Data Tester aja
	buku[0].no=1;
	buku[0].judul="Laskar Pelangi";
	buku[0].penulis="Andrea Hirata";
	buku[0].stok=10000;
	buku[0].kode="1AE3BF";
	buku[0].harga=10000000;
	y=1;
	//Sampe sini
	do{
		menuUtama:
		cout<<"============================================================================\n";
    	cout<<"=                Selamat Datang Di Self Machine Book Store                 =\n";
    	cout<<"============================================================================\n";
    	cout<<"=                          Silahkan Pilih Menu                             =\n";
    	cout<<"= 1. Pembelian Buku                                                        =\n";
    	cout<<"= 2. Admin Mode                                                            =\n";
    	cout<<"= 3. Exit/Keluar                                                           =\n";
    	cout<<"============================================================================\n";
    	cout<<"  Masukan Pilihan : ";
    	cin>>pilihMenu;
    	system("cls");
    	switch(pilihMenu){
    		case 1:
    			if(y<1){
    				cout<<"Menu Buku Kosong!\n";
        			cout<<"Silahkan Isi Terlebih Dahulu!\n\n";
        			system("pause");
        			system("cls");
        			goto menuUtama;
    			}else{
    				beli:
    				cout<<"============================================================================\n";
            		cout<<"=                              Pembelian Buku                              =\n";
            		cout<<"============================================================================\n";
            		cout<<"= No  |      Judul Buku      |     Penulis     | Stok  |  Kode  |  Harga   =\n";
            		cout<<"============================================================================\n";
            		tampilBuku(buku,y);
            		cout<<"============================================================================\n";
            		cout<<"= 0   | Kembali Ke Menu Utama                                              =\n";
            		cout<<"============================================================================\n";
            		cout<<"\nPilih buku yang akan dibeli : ";cin>>Qty;
            		for (int i=0;i<y;i++){
            			if(Qty==(i+1)){
            				cout<<"Banyak buku : ";cin>>banyakBuku[i];
            				buku[i].totalharga=banyakBuku[i]*buku[i].harga;
            				buku[i].stok=buku[i].stok - banyakBuku[i];
            			}else if(Qty==0){
            				system("cls");
            				goto menuUtama;
            			}else{
            				system("cls");
            				goto beli;
            			}
            		}
            		cout<<"Ingin membeli buku lain? (y/t) : ";cin>>kondisi;
            		if (kondisi=='y')
            		{
            			goto beli;
            		}else{
            			system("cls");
            			cout<<"============================================================================\n";
            			cout<<"=                                 Keranjang                                =\n";
            			cout<<"============================================================================\n";
            			cout<<"= No  |      Judul Buku      |     Penulis     |  Harga   | Qty |  Total   =\n";
            			cout<<"============================================================================\n";
            			keranjang(buku,y,banyakBuku,x,totalBelanja);
            			cout<<"============================================================================\n";
            			cout<<"=                          Total Belanja                        | "<<setw(8)<<totalBelanja<<" =\n";
            			cout<<"============================================================================\n";
            			system("pause");
            			system("cls");
            		}
    			}
    			break;
    		case 2:
    			cout<<"Masukkan password : ";cin>>pass;
    			system("cls");
    			if(pass=="admint"){
    				admin:
    				cout<<"1. Menambah data buku\n";
    				cout<<"2. Mengubah data buku\n";
    				cout<<"0. Kembali           \n";
    				cout<<"=====================\n";
    				cout<<"Masukkan pilihan : ";cin>>z;
    				if(z==1){
    					system("cls");
    					inputBuku(buku,y);
    				}else if(z==2){
    					ubahdata:
    					system("cls");
    					cout<<"============================================================================\n";
            			cout<<"=                              Ubah Data Buku                              =\n";
            			cout<<"============================================================================\n";
            			cout<<"= No  |      Judul Buku      |     Penulis     | Stok  |  Kode  |  Harga   =\n";
            			cout<<"============================================================================\n";
            			tampilBuku(buku,y);
            			cout<<"============================================================================\n";
            			cout<<"= 0   | Kembali Ke Menu Utama                                              =\n";
            			cout<<"============================================================================\n";
            			cout<<"\nPilih buku yang akan diubah : ";cin>>ubahData;
            			for(int i=0;i<y;i++){
            				if (ubahData == buku[i].no){
        	        			cin.ignore();
            	    			cout<<"Masukan Judul Buku Yang Baru	   : ";getline(cin,buku[i].judul);
            	    			cout<<"Masukan Penulis Buku Yang Baru  : ";getline(cin,buku[i].penulis);
            	    			cout<<"Masukan Stok Buku Yang Baru 	   : ";cin>>buku[i].stok;
            	    			cout<<"Masukan Kode Buku Yang Baru     : ";cin>>buku[i].kode;
								cout<<"Masukan Harga Buku Yang Baru    : ";cin>>buku[i].harga;
								system("cls");
            	    			cout << "Pengisian Buku Berhasil!\n";
            	    			system("pause");
            	    			system("cls");
            	    			goto menuUtama;
							}else if (ubahData == 0){
								system("cls");
            	    			goto menuUtama;
							}else{
								system("cls");
            	    			goto ubahdata;
							}
						}
    				}else if(z==0){
    					system("cls");
    					goto menuUtama;
    				}else{
    					system("cls");
    					goto admin;
    				}	
    			}else{
    				cout<<"Password Salah!\n";
            		system("pause");
        		    system("cls");
            		goto menuUtama;
    			}
    			break;
    	}
	}while (pilihMenu!=3);
		system("cls");
    	system("pause");
    	return 0;
	
}
   

