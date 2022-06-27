#include <iostream>
#include <stdlib.h>
#include <time.h>
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
void inputBuku(Buku buku[],int &triggerArray){
    cin.ignore();
    cout<<"Masukkan Judul Buku   : ";getline(cin,buku[triggerArray].judul);
    cout<<"Masukkan Penulis Buku : ";getline(cin,buku[triggerArray].penulis);
    cout<<"Masukkan Stok Buku    : ";cin>>buku[triggerArray].stok;
    cout<<"Masukkan Kode Buku    : ";cin>>buku[triggerArray].kode;
    cout<<"Masukkan Harga Buku   : ";cin>>buku[triggerArray].harga;
    buku[triggerArray].no=(triggerArray+1);
    triggerArray++;
}
void ubahBuku(Buku buku[],int nomer){
    nomer -= 1;
    cin.ignore();
    cout<<"Masukkan Judul Buku   : ";getline(cin,buku[nomer].judul);
    cout<<"Masukkan Penulis Buku : ";getline(cin,buku[nomer].penulis);
    cout<<"Masukkan Stok Buku    : ";cin>>buku[nomer].stok;
    cout<<"Masukkan Kode Buku    : ";cin>>buku[nomer].kode;
    cout<<"Masukkan Harga Buku   : ";cin>>buku[nomer].harga;
}
void tampilBuku(Buku buku[],int triggerArray,int nomer){
    for(int i=0;i<triggerArray;i++){
        cout<<setiosflags(ios::left);
        cout<<"= ";
        cout<<setw(3)<<nomer;
        cout<<" | "<<setw(20)<<buku[i].judul;
        cout<<" | "<<setw(15)<<buku[i].penulis;
        cout<<" | "<<setw(5)<<buku[i].stok;
        cout<<" | "<<setw(6)<<buku[i].kode;
        cout<<" | "<<setw(8)<<buku[i].harga;
        cout<<" ="<<endl;
        nomer++;
    }
}
void keranjang(Buku buku[],int triggerArray,int banyakBuku[],int nomer,int &totalBelanja){
    for(int i=0;i<triggerArray;i++){
        if(banyakBuku[i]>0){
            cout<<setiosflags(ios::left);
            cout<<"= ";
            cout<<setw(3)<<(nomer);
            cout<<" | "<<setw(20)<<buku[i].judul;
            cout<<" | "<<setw(15)<<buku[i].penulis;
            cout<<" | "<<setw(8)<<buku[i].harga;
            cout<<" | "<<setw(3)<<banyakBuku[i];
            cout<<" | "<<setw(8)<<buku[i].totalharga;
            cout<<" ="<<endl;
            totalBelanja = totalBelanja + buku[i].totalharga;
            nomer += 1;
        }
    }
}
void ubahKeranjang(Buku buku[],int triggerArray,int banyakBuku[],int nomer){
    for(int i=0;i<triggerArray;i++){
        if(banyakBuku[i]>0){
            cout<<setiosflags(ios::left);
            cout<<"= ";
            cout<<setw(3)<<(nomer);
            cout<<" | "<<setw(20)<<buku[i].judul;
            cout<<" | "<<setw(15)<<buku[i].penulis;
            cout<<" | "<<setw(8)<<buku[i].harga;
            cout<<" | "<<setw(3)<<banyakBuku[i];
            cout<<" | "<<setw(8)<<buku[i].totalharga;
            cout<<" ="<<endl;
            nomer += 1;
        }
    }
}
void struk(Buku buku[],int triggerArray,int banyakBuku[],int nomer){
    for(int i=0;i<triggerArray;i++){
        if(banyakBuku[i]>0){
            cout<<setiosflags(ios::left);
            cout<<"= ";
            cout<<setw(3)<<(nomer);
            cout<<" | "<<setw(20)<<buku[i].judul;
            cout<<" | "<<setw(8)<<buku[i].harga;
            cout<<" | "<<setw(3)<<banyakBuku[i];
            cout<<" | "<<setw(8)<<buku[i].totalharga;
            cout<<" ="<<endl;
            nomer += 1;
        }
    }
}
void sortingJudul(Buku buku[],int triggerArray){
    for (int i=0;i<triggerArray;i++){
        for(int j=0;j<triggerArray-i-1;j++){
            if (buku[j].judul.compare(buku[j + 1].judul) > 0 ){ 
                swap(buku[j].judul,buku[j+1].judul);
                swap(buku[j].penulis,buku[j+1].penulis);
                swap(buku[j].harga,buku[j+1].harga);
                swap(buku[j].kode,buku[j+1].kode);
                swap(buku[j].stok,buku[j+1].stok);
            }
        }
    }
}
void sortingPenulis(Buku buku[],int triggerArray){
    for (int i=0;i<triggerArray;i++){
        for(int j=0;j<triggerArray-i-1;j++){
            if (buku[j].penulis.compare(buku[j + 1].penulis) > 0 ){ 
                swap(buku[j].judul,buku[j+1].judul);
                swap(buku[j].penulis,buku[j+1].penulis);
                swap(buku[j].harga,buku[j+1].harga);
                swap(buku[j].kode,buku[j+1].kode);
                swap(buku[j].stok,buku[j+1].stok);
            }
        }
    } 
}
void sortingHarga(Buku buku[],int triggerArray){
    for (int i=0;i<triggerArray;i++){
        for(int j=0;j<triggerArray-i-1;j++){
            if (buku[j].harga > (buku[j + 1].harga)){ 
                swap(buku[j].judul,buku[j+1].judul);
                swap(buku[j].penulis,buku[j+1].penulis);
                swap(buku[j].harga,buku[j+1].harga);
                swap(buku[j].kode,buku[j+1].kode);
                swap(buku[j].stok,buku[j+1].stok);
            }
        }
    }
}
void ubahKode(Buku buku[],int triggerArray){
    triggerArray = triggerArray -1;
    string hurufBesar = buku[triggerArray].kode;
    int lebar = hurufBesar.length();
    for (int i=0;i<=lebar;i++){
        hurufBesar[i] = toupper(hurufBesar[i]);
    }
    buku[triggerArray].kode = hurufBesar;
}
void ubahJudul(Buku buku[],int triggerArray){
    triggerArray = triggerArray -1;
    string kecil = buku[triggerArray].judul;
    int lebar = kecil.length();
    for (int i=0;i<=lebar;i++){
        kecil[i] = tolower(kecil[i]);
    }
    string kapital = kecil;
    for (int i=0;i<=lebar;i++){
        char a = toupper(kapital[0]);
        string timpa(1,a);
        kapital = kapital.replace(0,1,timpa);
        if (isspace (kapital[i]) || ispunct (kapital[i])){
            char b= toupper(kapital[i+1]);
            string tindas(1,b);
            kapital.replace(i+1,1,tindas);
        }
    }
    buku[triggerArray].judul=kapital;
}
void sesuaikanJudul(string &UbahDataKeranjang){
    string kecil = UbahDataKeranjang;
    int lebar = kecil.length();
    for (int i=0;i<=lebar;i++){
            kecil[i] = tolower(kecil[i]);
    }
    string kapital = kecil;
    for (int i=0;i<=lebar;i++){
        char a = toupper(kapital[0]);
        string timpa(1,a);
        kapital = kapital.replace(0,1,timpa);
        if (isspace (kapital[i]) || ispunct (kapital[i])){
            char b= toupper(kapital[i+1]);
            string tindas(1,b);
            kapital.replace(i+1,1,tindas);
        }
    }
    UbahDataKeranjang=kapital;
}
void ubahPenulis(Buku buku[],int triggerArray){
    triggerArray = triggerArray -1;
    string kecil = buku[triggerArray].penulis;
    int lebar = kecil.length();
    for (int i=0;i<=lebar;i++){
        kecil[i] = tolower(kecil[i]);
    }
    string kapital = kecil;
    for (int i=0;i<=lebar;i++){
        char a = toupper(kapital[0]);
        string timpa(1,a);
        kapital = kapital.replace(0,1,timpa);
        if (isspace (kapital[i]) || ispunct (kapital[i])){
            char b= toupper(kapital[i+1]);
            string tindas(1,b);
            kapital.replace(i+1,1,tindas);
        }
    }
    buku[triggerArray].penulis=kapital;
}
void suntikBuku(Buku buku[],int &triggerArray){
    buku[0].no=1;
    buku[0].judul="Laskar Pelangi";
    buku[0].penulis="Andrea Hirata";
    buku[0].stok=10;
    buku[0].kode="LPAH50";
    buku[0].harga=100000;

    buku[1].no=2; 
    buku[1].judul="Bumi Manusia";
    buku[1].penulis="Pramudya Ananta";
    buku[1].stok=35;
    buku[1].kode="BMPA35";
    buku[1].harga=130000;

    buku[2].no=3;
    buku[2].judul="Negeri 5 Menara";
    buku[2].penulis="Ahmad Fuadi";
    buku[2].stok=40;
    buku[2].kode="N5MAF9";
    buku[2].harga=75000;

    buku[3].no=4;
    buku[3].judul="Perahu Kertas";
    buku[3].penulis="Dee Lestari";
    buku[3].stok=45;
    buku[3].kode="PKDL45";
    buku[3].harga=80000;

    buku[4].no=5;
    buku[4].judul="Koala Kumal";
    buku[4].penulis="Raditya Dika";
    buku[4].stok=100;
    buku[4].kode="KKRD10";
    buku[4].harga=65000;

    triggerArray=5;
}
void kodePembayaran(){
    const char data[] = {"0123456789""ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz"};
    int size = sizeof(data)-1;
    int length = 16;
    srand(time(0));
    for(int i=0;i<length;i++){
        cout<<data[rand()%size];
    }
}