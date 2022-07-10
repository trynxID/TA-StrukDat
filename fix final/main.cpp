#include <iostream> //Untuk Cout & CIN
#include <string.h> //Untuk memanipulasi String dan Array
#include <iomanip> //Untuk memanipulasi tampilan output
#include <conio.h> //Untuk Getch
using namespace std; //Untuk menghilangkan syntaks std::
#include "function.h" //Untuk memanggil library local "function.h"
#include "injectBook.h" //Untuk memanggil library local "injectBook.h"
int main(){
    string pass,UbahDataKeranjang; //Variabel dengan tipe data string
    char kondisi; //Variabel dengan tipe data char
    int pilihMenu,beliBuku,banyakBuku[1000],nomer=1,triggerArray=0,pilihAdmin,pilihSort,pilihKeranjang,Qty,ubahDataBuku,totalBelanja; //Variabel dengan tipe data int
    Buku buku[1000]; //Nama Struct Buku
    suntikBuku(buku,triggerArray); //Function untuk memanggil data buku (dummy)
    do{
        menuUtama: //Checkpoint menu utama
        memset(banyakBuku, 0, sizeof(banyakBuku)); //Mereset seluruh data array pada variabel banyakBuku
        totalBelanja=0; //Mereset value totalBelanja
        cout<<"============================================================================\n"; //Menampilkan menu utama dari program
        cout<<"=                Selamat Datang Di Self Machine Book Store                 =\n";
        cout<<"============================================================================\n";
        cout<<"=                          Silahkan Pilih Menu                             =\n";
        cout<<"= 1. Pembelian Buku                                                        =\n";
        cout<<"= 2. Admin Mode                                                            =\n";
        cout<<"= 3. Exit/Keluar                                                           =\n";
        cout<<"============================================================================\n";
        cout<<"  Masukan Pilihan : ";cin>>pilihMenu; //Menerima input dari user berupa pilihan menu
        system("cls");
        switch(pilihMenu){
            case 1: //Menu pembelian buku
                if(triggerArray<1){ //Melakukan pengecekan apakah buku sudah terisi
                    cout<<"Menu Buku Kosong!\n";
                    cout<<"Silahkan Isi Terlebih Dahulu!";
                    getch();
                    system("cls");
                    goto menuUtama;
                }else{ //Menampilkan pilihan sorting
                    cout<<"============================================================================\n";
                    cout<<"=                      Silahkan Pilih Jenis Sorting                        =\n";
                    cout<<"============================================================================\n";
                    cout<<"= 1. Sorting dari judul (A/Z)                                              =\n";
                    cout<<"= 2. Sorting dari penulis (A/Z)                                            =\n";
                    cout<<"= 3. Sorting dari harga (Low/High)                                         =\n";
                    cout<<"============================================================================\n";
                    cout<<"  Masukan Pilihan : ";cin>>pilihSort; //Menerima input dari user berupa pilihan sorting
                    system("cls");
                    if(pilihSort==1){
                        sortingJudul(buku,triggerArray); //Memanggil fungsi untuk sorting berdasarkan judul
                    }else if(pilihSort==2){
                        sortingPenulis(buku,triggerArray); //Memanggil fungsi untuk sorting berdasarkan penulis
                    }else if(buku,triggerArray){
                        sortingHarga(buku,triggerArray); //Memanggil fungsi untuk sorting berdasarkan harga
                    }else{
                        
                    }
                    Checkpointbuku: //Checkpoint untuk pembelian buku
                    cout<<"============================================================================\n"; //Menampilkan tampilan daftar buku yang dapat dibeli
                    cout<<"=                              Pembelian Buku                              =\n";
                    cout<<"============================================================================\n";
                    cout<<"= No  |      Judul Buku      |     Penulis     | Stok  |  Kode  |  Harga   =\n";
                    cout<<"============================================================================\n";
                    tampilBuku(buku,triggerArray,nomer); //Memanggil fungsi untuk menampilkan daftar buku
                    cout<<"============================================================================\n";
                    cout<<"= 0   | Kembali Ke Menu Utama                                              =\n";
                    cout<<"============================================================================\n";
                    cout<<"\nPilih buku yang akan dibeli : ";cin>>beliBuku; //Menerima input dari user berupa pilihan buku yang dibeli
                    for (int i=0;i<triggerArray;i++){
                        if(beliBuku==(i+1)){ //Melakukan pengecekan apakah daftar buku yang dipilih sesuai
                            cout<<"Banyak buku : ";cin>>banyakBuku[i]; //Menerima input dari user berupa banyak buku yang dibeli
                            if(buku[i].stok<banyakBuku[i]){ //Melakukan pengecekan apakah stok buku mencukupi
                                cout<<"\nStok buku tidak mencukupi, silahkan pilih buku yang lain!";
                                getch();
                                system("cls");
                                goto Checkpointbuku;
                            }else { //Melakukan validasi stok & totalharga
                                buku[i].stok=buku[i].stok - banyakBuku[i];
                                buku[i].totalharga=banyakBuku[i]*buku[i].harga;
                            }                       
                        }else if(beliBuku==0){ //Pilihan menu untuk kembali ke menu utama
                            system("cls");
                            goto menuUtama;
                        }else if(beliBuku>=triggerArray){ //Validasi pilihan buku yang ingin dibeli
                            system("cls");
                            goto Checkpointbuku;
                        }
                    }
                    cout<<"Ingin membeli buku lain? (y/t) : ";cin>>kondisi; //Menerima input dari user apakah ingin membeli buku lagi
                    if (kondisi=='y') //Menyesuaikan apakah kondisi sesuai dengan input yang diberikan
                    {
                        system("cls");
                        goto Checkpointbuku;
                    }else{
                        system("cls");
                        cpKeranjang: //Checkpoint untuk keranjang
                        cout<<"============================================================================\n"; //Menampilkan tampilan dari keranjang
                        cout<<"=                                 Keranjang                                =\n";
                        cout<<"============================================================================\n";
                        cout<<"= No  |      Judul Buku      |     Penulis     |  Harga   | Qty |  Total   =\n";
                        cout<<"============================================================================\n";
                        keranjang(buku,triggerArray,banyakBuku,nomer,totalBelanja); //Memanggil fungsi keranjang berupa buku yang telah dibeli
                        cout<<"============================================================================\n";
                        cout<<"=                          Total Belanja                        | "<<setw(8)<<totalBelanja<<" =\n";
                        cout<<"============================================================================\n";
                        cout<<"1. Pembayaran\n";
                        cout<<"2. Menghapus isi keranjang\n";
                        cout<<"Masukkan Pilihan : ";cin>>pilihKeranjang; //Menerima input dari user berupa pilihan untuk melanjutkan pembayaran atau pengubahan
                        system("cls");
                        if (pilihKeranjang==1){ //Menampilkan struk pembayaran
                            cout<<"==========================================================\n";
                            cout<<"=                    Struk Pembayaran                    =\n";
                            cout<<"==========================================================\n";
                            cout<<"= No  |      Judul Buku      |  Harga   | Qty |  Total   =\n";
                            cout<<"==========================================================\n";
                            struk(buku,triggerArray,banyakBuku,nomer); //Memanggil fungsi struk untuk menampilkan struk pembelanjaan
                            cout<<"==========================================================\n";
                            cout<<"=                Total Belanja                | "<<setw(8)<<totalBelanja<<" =\n";
                            cout<<"==========================================================\n";
                            cout<<"= Kode Pembayaran : ";kodePembayaran();cout<<"                     =\n";//Memanggil fungsi kode pembayaran  
                            cout<<"==========================================================\n";
                            cout<<"=                 Silahkan Pergi ke Kasir                =\n";
                            cout<<"=               Untuk Melakukan Pembayaran               =\n";
                            cout<<"==========================================================\n";
                            getch();
                            system("cls");
                        }else if (pilihKeranjang==2){
                            UbahKeranjang: //Checkpoint Mengubah isi keranjang
                            cout<<"============================================================================\n";//Menampilkan menu untuk menghapus isi keranjang
                            cout<<"=                          Menghapus Isi Keranjang                         =\n";
                            cout<<"============================================================================\n";
                            cout<<"= No  |      Judul Buku      |     Penulis     |  Harga   | Qty |  Total   =\n";
                            cout<<"============================================================================\n";
                            ubahKeranjang(buku,triggerArray,banyakBuku,nomer); //Memanggil fungsi untuk mengubah isi dari keranjang
                            cout<<"============================================================================\n";
                            cout<<"Masukkan Judul buku yang akan diubah : ";
                            cin.ignore(); //Syntax untuk mengabaikan input
                            getline(cin,UbahDataKeranjang); //Menerima input judul buku untuk disesuaikan dengan kondisi
                            sesuaikanJudul(UbahDataKeranjang); //Mengubah input yang diberikan menjadi kapital
                            for(int i=0;i<triggerArray;i++){ //Melakukan looping untuk mencari data yang ada pada struct array
                                if (UbahDataKeranjang == buku[i].judul){ //Melakukan pengecekan apakah judul yang diberikan sesuai
                                    buku[i].stok += banyakBuku[i]; //Stok buku ditambahkan kembali
                                    banyakBuku[i]=0; //Menghapus banyakBuku yang dibeli
                                    buku[i].totalharga=0; //Mengubah data totalharga
                                    totalBelanja=0; //Mengubah data totalBelanja
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
                cout<<"Masukkan password : ";cin>>pass; //Input password dari user untuk keamanan admin
                system("cls");
                if(pass=="admint"){//Melakukan validasi terhadap menu admin
                    admin: //Checkpoint menu admin
                    cout<<"1. Menambah data buku\n";
                    cout<<"2. Mengubah data buku\n";
                    cout<<"0. Kembali           \n";
                    cout<<"=====================\n";
                    cout<<"Masukkan pilihan : ";cin>>pilihAdmin; //Input pilihan dari user terhadap menu admin
                    system("cls");
                    if(pilihAdmin==1){
                        inputBuku(buku,triggerArray); //Memanggil fungsi inputBuku untuk pengisian buku
                        ubahJudul(buku,triggerArray); //Memanggil fungsi ubahJudul untuk membuat judul menjadi kapital
                        ubahPenulis(buku,triggerArray); //Memanggil fungsi ubahPenulis untuk membuat penulis menjadi kapital
                        ubahKode(buku,triggerArray); //Memanggil fungsi ubahKode untuk membuat kode menjadi kapital
                        system("cls");
                    }else if(pilihAdmin==2){
                        ubahDataBuku: //Checkpoint menu pengubahan data buku
                        cout<<"============================================================================\n"; // Menampilkan menu ubah data buku
                        cout<<"=                              Ubah Data Buku                              =\n";
                        cout<<"============================================================================\n";
                        cout<<"= No  |      Judul Buku      |     Penulis     | Stok  |  Kode  |  Harga   =\n";
                        cout<<"============================================================================\n";
                        tampilBuku(buku,triggerArray,nomer); //Memanggil fungsi tampilBuku
                        cout<<"============================================================================\n";
                        cout<<"= 0   | Kembali Ke Menu Utama                                              =\n";
                        cout<<"============================================================================\n";
                        cout<<"\nPilih buku yang akan diubah : ";cin>>ubahDataBuku;//Input pilihan dari user untuk menentukan buku mana yang akan diubah
                        for(int i=0;i<triggerArray;i++){
                            if (nomer == ubahDataBuku){
                                ubahBuku(buku,nomer);//Memanggil fungsi ubahBuku untuk mengubah isian dari buku
                                ubahJudul(buku,nomer);//Memanggil fungsi ubahJudul untuk membuat judul menjadi kapital
                                ubahPenulis(buku,nomer);//Memanggil fungsi ubahPenulis untuk membuat penulis menjadi kapital
                                ubahKode(buku,nomer);//Memanggil fungsi ubahKode untuk membuat kode menjadi kapital
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
                        goto menuUtama;
                    }else{
                        goto admin;
                    }   
                }else{
                    cout<<"Password Salah!"; //Balasan tampilan apabila password yang dimasukkan salah
                    getch();
                    system("cls");
                    goto menuUtama;
                }
                break;
        }
    }while (pilihMenu!=3);//Ketika ingin mengakhiri program
        system("cls");
        system("pause");
        return 0;
    
}
   

