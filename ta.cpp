#include <iostream>
#include <string.h>
#include <iomanip>
#include "suntikbuku.h"
using namespace std;
int main(){
    int pilihMenu;
    string pass;
    char kondisi;
    int beliBuku,nomer=1,triggerArray=0,pilihUbahdata,pilihSort,Qty,ubahData,totalBelanja=0;
    Buku buku[1000];
    int banyakBuku[1000];
    suntikBuku(buku,triggerArray);
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
        cout<<"  Masukan Pilihan : ";cin>>pilihMenu;
        system("cls");
        switch(pilihMenu){
            case 1:
                if(triggerArray<1){
                    cout<<"Menu Buku Kosong!\n";
                    cout<<"Silahkan Isi Terlebih Dahulu!\n\n";
                    system("pause");
                    system("cls");
                    goto menuUtama;
                }else{
                    beli:
                    cout<<"============================================================================\n";
                    cout<<"=                      Silahkan Pilih Jenis Sorting                        =\n";
                    cout<<"============================================================================\n";
                    cout<<"= 1. Sorting dari judul (A/Z)                                              =\n";
                    cout<<"= 2. Sorting dari penulis (A/Z)                                            =\n";
                    cout<<"= 3. Sorting dari harga (Low/High)                                         =\n";
                    cout<<"============================================================================\n";
                    cout<<"  Masukan Pilihan : ";cin>>pilihSort;
                    system("cls");
                    if(pilihSort==1){
                        sortingJudul(buku,triggerArray);
                    }else if(pilihSort==2){
                        sortingPenulis(buku,triggerArray);
                    }else if(buku,triggerArray){
                        sortingHarga(buku,triggerArray);
                    }else{
                        
                    }
                    Checkpointbuku:
                    cout<<"============================================================================\n";
                    cout<<"=                              Pembelian Buku                              =\n";
                    cout<<"============================================================================\n";
                    cout<<"= No  |      Judul Buku      |     Penulis     | Stok  |  Kode  |  Harga   =\n";
                    cout<<"============================================================================\n";
                    tampilBuku(buku,triggerArray,nomer);
                    cout<<"============================================================================\n";
                    cout<<"= 0   | Kembali Ke Menu Utama                                              =\n";
                    cout<<"============================================================================\n";
                    cout<<"\nPilih buku yang akan dibeli : ";cin>>beliBuku;
                    for (int i=0;i<triggerArray;i++){
                        if(beliBuku==(i+1)){
                            cout<<"Banyak buku : ";cin>>banyakBuku[i];
                            if(buku[i].stok<banyakBuku[i]){
                                cout<<"\nStok buku tidak mencukupi, silahkan pilih buku yang lain!\n";
                                system("pause");
                                system("cls");
                                goto Checkpointbuku;
                            }else {
                                buku[i].stok=buku[i].stok - banyakBuku[i];
                                buku[i].totalharga=banyakBuku[i]*buku[i].harga;
                            }                       
                        }else if(beliBuku==0){
                            system("cls");
                            goto menuUtama;
                        }else{
                            
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
                        keranjang(buku,triggerArray,banyakBuku,nomer,totalBelanja);
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
                    cout<<"Masukkan pilihan : ";cin>>pilihUbahdata;
                    if(pilihUbahdata==1){
                        system("cls");
                        inputBuku(buku,triggerArray);
                        ubahHurufBesar(buku,triggerArray);
                    }else if(pilihUbahdata==2){
                        ubahdata:
                        system("cls");
                        cout<<"============================================================================\n";
                        cout<<"=                              Ubah Data Buku                              =\n";
                        cout<<"============================================================================\n";
                        cout<<"= No  |      Judul Buku      |     Penulis     | Stok  |  Kode  |  Harga   =\n";
                        cout<<"============================================================================\n";
                        tampilBuku(buku,triggerArray,nomer);
                        cout<<"============================================================================\n";
                        cout<<"= 0   | Kembali Ke Menu Utama                                              =\n";
                        cout<<"============================================================================\n";
                        cout<<"\nPilih buku yang akan diubah : ";cin>>ubahData;
                        for(int i=0;i<triggerArray;i++){
                            if (ubahData == buku[i].no){
                                cin.ignore();
                                cout<<"Masukan Judul Buku Yang Baru    : ";getline(cin,buku[i].judul);
                                cout<<"Masukan Penulis Buku Yang Baru  : ";getline(cin,buku[i].penulis);
                                cout<<"Masukan Stok Buku Yang Baru     : ";cin>>buku[i].stok;
                                cout<<"Masukan Kode Buku Yang Baru     : ";cin>>buku[i].kode;
                                //ubahHurufBesar(buku,triggerArray);
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
                    }else if(pilihUbahdata==0){
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
   

