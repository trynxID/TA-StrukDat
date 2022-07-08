#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <iomanip>
#include <conio.h>
#include "function.h"
#include "injectBook.h"
using namespace std;
int main(){
    int pilihMenu;
    string pass,UbahDataKeranjang;
    char kondisi,dt;
    int beliBuku,nomer=1,triggerArray=0,pilihAdmin,pilihSort,pilihKeranjang,Qty,ubahDataBuku,totalBelanja=0;
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
                    cout<<"Silahkan Isi Terlebih Dahulu!";
                    getch();
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
                                cout<<"\nStok buku tidak mencukupi, silahkan pilih buku yang lain!";
                                getch();
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
                        system("cls");
                        goto Checkpointbuku;
                    }else{
                        system("cls");
                        cpKeranjang:
                        cout<<"============================================================================\n";
                        cout<<"=                                 Keranjang                                =\n";
                        cout<<"============================================================================\n";
                        cout<<"= No  |      Judul Buku      |     Penulis     |  Harga   | Qty |  Total   =\n";
                        cout<<"============================================================================\n";
                        keranjang(buku,triggerArray,banyakBuku,nomer,totalBelanja);
                        cout<<"============================================================================\n";
                        cout<<"=                          Total Belanja                        | "<<setw(8)<<totalBelanja<<" =\n";
                        cout<<"============================================================================\n";
                        cout<<"1. Pembayaran\n";
                        cout<<"2. Menghapus isi keranjang\n";
                        cout<<"Masukkan Pilihan : ";cin>>pilihKeranjang;
                        system("cls");
                        if (pilihKeranjang==1){
                            cout<<"==========================================================\n";
                            cout<<"=                    Struk Pembayaran                    =\n";
                            cout<<"==========================================================\n";
                            cout<<"= No  |      Judul Buku      |  Harga   | Qty |  Total   =\n";
                            cout<<"==========================================================\n";
                            struk(buku,triggerArray,banyakBuku,nomer);
                            cout<<"==========================================================\n";
                            cout<<"=                Total Belanja                | "<<setw(8)<<totalBelanja<<" =\n";
                            cout<<"==========================================================\n";
                            cout<<"= Kode Pembayaran : ";kodePembayaran();cout<<"                     =\n"; 
                            cout<<"==========================================================\n";
                            cout<<"=                 Silahkan Pergi ke Kasir                =\n";
                            cout<<"=               Untuk Melakukan Pembayaran               =\n";
                            cout<<"==========================================================\n";
                            memset(banyakBuku, 0, sizeof(banyakBuku));
                            getch();
                            system("cls");
                        }else if (pilihKeranjang==2){
                            UbahKeranjang:
                            cout<<"============================================================================\n";
                            cout<<"=                          Menghapus Isi Keranjang                         =\n";
                            cout<<"============================================================================\n";
                            cout<<"= No  |      Judul Buku      |     Penulis     |  Harga   | Qty |  Total   =\n";
                            cout<<"============================================================================\n";
                            ubahKeranjang(buku,triggerArray,banyakBuku,nomer);
                            cout<<"============================================================================\n";
                            cout<<"Masukkan Judul buku yang akan diubah : ";
                            cin.ignore();
                            getline(cin,UbahDataKeranjang);
                            sesuaikanJudul(UbahDataKeranjang);
                            for(int i=0;i<triggerArray;i++){
                                if (UbahDataKeranjang == buku[i].judul){
                                    buku[i].stok += banyakBuku[i]; 
                                    banyakBuku[i]=0;
                                    buku[i].totalharga=0;
                                    totalBelanja=0;
                                    cout << "Buku Berhasil Dihapus!";
                                    getch();
                                    system("cls");
                                }
                            }
                            goto cpKeranjang;
                        }else{
                            system("cls");
                            goto cpKeranjang;
                        }
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
                    cout<<"Masukkan pilihan : ";cin>>pilihAdmin;
                    if(pilihAdmin==1){
                        system("cls");
                        inputBuku(buku,triggerArray);
                        ubahJudul(buku,triggerArray);
                        ubahPenulis(buku,triggerArray);
                        ubahKode(buku,triggerArray);
                        system("cls");
                    }else if(pilihAdmin==2){
                        ubahDataBuku:
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
                        cout<<"\nPilih buku yang akan diubah : ";cin>>ubahDataBuku;
                        for(int i=0;i<triggerArray;i++){
                            if (nomer == ubahDataBuku){
                                ubahBuku(buku,nomer);
                                ubahJudul(buku,nomer);
                                ubahPenulis(buku,nomer);
                                ubahKode(buku,nomer);
                                system("cls");
                                cout << "Pengisian Buku Berhasil!";
                                getch();
                                system("cls");
                            }else if (ubahDataBuku == 0){
                                system("cls");
                            }
                            nomer += 1;
                        }
                        nomer=1;
                        goto menuUtama;
                    }else if(pilihAdmin==0){
                        system("cls");
                        goto menuUtama;
                    }else{
                        system("cls");
                        goto admin;
                    }   
                }else{
                    cout<<"Password Salah!";
                    getch();
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
   

