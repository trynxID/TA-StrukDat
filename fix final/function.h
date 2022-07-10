struct Buku //Struct buku
{
    string judul,penulis,kode;
    int stok,harga,no,totalharga;
};
void inputBuku(Buku buku[],int &triggerArray){ //Fungsi untuk pengisian buku (menggunakan parameter struct buku dan pointer triggerArray)
    cin.ignore();
    cout<<"Masukkan Judul Buku   : ";getline(cin,buku[triggerArray].judul);
    cout<<"Masukkan Penulis Buku : ";getline(cin,buku[triggerArray].penulis);
    cout<<"Masukkan Stok Buku    : ";cin>>buku[triggerArray].stok;
    cout<<"Masukkan Kode Buku    : ";cin>>buku[triggerArray].kode;
    cout<<"Masukkan Harga Buku   : ";cin>>buku[triggerArray].harga;
    buku[triggerArray].no=(triggerArray+1); //Penambahan nomer secara otomatis
    triggerArray++; //Penambahan nilai triggerArray yang digunakan sebagai index
}
void ubahBuku(Buku buku[],int nomer){ //Fungsi untuk mengubah data buku 
    nomer -= 1; //Untuk menyesuaikan agar nomer memiliki nilai yang sama dengan index
    cout<<"\n--> "<<buku[nomer].judul<<" <--\n"; //Judul buku yang dipilih
    cin.ignore();
    cout<<"Masukkan Judul Buku   : ";getline(cin,buku[nomer].judul);
    cout<<"Masukkan Penulis Buku : ";getline(cin,buku[nomer].penulis);
    cout<<"Masukkan Stok Buku    : ";cin>>buku[nomer].stok;
    cout<<"Masukkan Kode Buku    : ";cin>>buku[nomer].kode;
    cout<<"Masukkan Harga Buku   : ";cin>>buku[nomer].harga;
}
void tampilBuku(Buku buku[],int triggerArray,int nomer){ //Fungsi untuk menampilkan daftar buku
    for(int i=0;i<triggerArray;i++){
        cout<<setiosflags(ios::left); //Mengeset agar tampilan rata kiri
        cout<<"= ";
        cout<<setw(3)<<nomer; //Mengeset agar lebar tampilan menjadi 3 character
        cout<<" | "<<setw(20)<<buku[i].judul;//Mengeset agar lebar tampilan menjadi 20 character
        cout<<" | "<<setw(15)<<buku[i].penulis;//Mengeset agar lebar tampilan menjadi 15 character
        cout<<" | "<<setw(5)<<buku[i].stok;//Mengeset agar lebar tampilan menjadi 5 character
        cout<<" | "<<setw(6)<<buku[i].kode;//Mengeset agar lebar tampilan menjadi 6 character
        cout<<" | "<<setw(8)<<buku[i].harga;//Mengeset agar lebar tampilan menjadi 8 character
        cout<<" ="<<endl;
        nomer++;//Agar nomer berubah secara increment
    }
}
void keranjang(Buku buku[],int triggerArray,int banyakBuku[],int nomer,int &totalBelanja){//Fungsi untuk menampilkan buku apa saja yang kita beli(menggunakan pointer totalBelanja)
    for(int i=0;i<triggerArray;i++){
        if(banyakBuku[i]>0){
            cout<<setiosflags(ios::left);//Mengeset agar tampilan rata kiri
            cout<<"= ";
            cout<<setw(3)<<(nomer);//Mengeset agar lebar tampilan menjadi 3 character
            cout<<" | "<<setw(20)<<buku[i].judul;//Mengeset agar lebar tampilan menjadi 20 character
            cout<<" | "<<setw(15)<<buku[i].penulis;//Mengeset agar lebar tampilan menjadi 15 character
            cout<<" | "<<setw(8)<<buku[i].harga;//Mengeset agar lebar tampilan menjadi 8 character
            cout<<" | "<<setw(3)<<banyakBuku[i];//Mengeset agar lebar tampilan menjadi 3 character
            cout<<" | "<<setw(8)<<buku[i].totalharga;//Mengeset agar lebar tampilan menjadi 8 character
            cout<<" ="<<endl;
            totalBelanja = totalBelanja + buku[i].totalharga; //Membuat value untuk total belanja buku
            nomer += 1;//Agar nomer berubah secara increment
        }
    }
}
void ubahKeranjang(Buku buku[],int triggerArray,int banyakBuku[],int nomer){//Fungsi untuk mengubah data dari keranjang pembelian
    for(int i=0;i<triggerArray;i++){
        if(banyakBuku[i]>0){
            cout<<setiosflags(ios::left);//Mengeset agar tampilan rata kiri
            cout<<"= ";
            cout<<setw(3)<<(nomer);//Mengeset agar lebar tampilan menjadi 3 character
            cout<<" | "<<setw(20)<<buku[i].judul;//Mengeset agar lebar tampilan menjadi 20 character
            cout<<" | "<<setw(15)<<buku[i].penulis;//Mengeset agar lebar tampilan menjadi 15 character
            cout<<" | "<<setw(8)<<buku[i].harga;//Mengeset agar lebar tampilan menjadi 8 character
            cout<<" | "<<setw(3)<<banyakBuku[i];//Mengeset agar lebar tampilan menjadi 3 character
            cout<<" | "<<setw(8)<<buku[i].totalharga;//Mengeset agar lebar tampilan menjadi 8 character
            cout<<" ="<<endl;
            nomer += 1;//Agar nomer berubah secara increment
        }
    }
}
void struk(Buku buku[],int triggerArray,int banyakBuku[],int nomer){//Fungsi untuk membuat tampilan struk dari pembelian
    for(int i=0;i<triggerArray;i++){
        if(banyakBuku[i]>0){
            cout<<setiosflags(ios::left);//Mengeset agar tampilan rata kiri
            cout<<"= ";
            cout<<setw(3)<<(nomer);//Mengeset agar lebar tampilan menjadi 3 character
            cout<<" | "<<setw(20)<<buku[i].judul;//Mengeset agar lebar tampilan menjadi 20 character
            cout<<" | "<<setw(8)<<buku[i].harga;//Mengeset agar lebar tampilan menjadi 15 character
            cout<<" | "<<setw(3)<<banyakBuku[i];//Mengeset agar lebar tampilan menjadi 3 character
            cout<<" | "<<setw(8)<<buku[i].totalharga;//Mengeset agar lebar tampilan menjadi 8 character
            cout<<" ="<<endl;
            nomer += 1;//Agar nomer berubah secara increment
        }
    }
}
void sortingJudul(Buku buku[],int triggerArray){//Fungsi untuk melakukan sorting berdasarkan judul
    for (int i=0;i<triggerArray;i++){
        for(int j=0;j<triggerArray-i-1;j++){
            if (buku[j].judul.compare(buku[j + 1].judul) > 0 ){ //Melakukan perbandingan antara judul satu dan judul lainnya
                swap(buku[j].judul,buku[j+1].judul);//Mengubah posisi judul dengan menyesuakan dengan array Judul
                swap(buku[j].penulis,buku[j+1].penulis);//Mengubah posisi judul dengan menyesuakan dengan array Judul
                swap(buku[j].harga,buku[j+1].harga);//Mengubah posisi harga dengan menyesuakan dengan array Judul
                swap(buku[j].kode,buku[j+1].kode);//Mengubah posisi kode dengan menyesuakan dengan array Judul
                swap(buku[j].stok,buku[j+1].stok);//Mengubah posisi stok dengan menyesuakan dengan array Judul
            }
        }
    }
}
void sortingPenulis(Buku buku[],int triggerArray){//Fungsi untuk melakukan sorting berdasarkan penulis
    for (int i=0;i<triggerArray;i++){
        for(int j=0;j<triggerArray-i-1;j++){
            if (buku[j].penulis.compare(buku[j + 1].penulis) > 0 ){ //Melakukan perbandingan antara penulis satu dan penulis lainnya
                swap(buku[j].judul,buku[j+1].judul); //Mengubah posisi judul dengan menyesuakan dengan array Penulis
                swap(buku[j].penulis,buku[j+1].penulis);//Mengubah posisi judul dengan menyesuakan dengan array Penulis
                swap(buku[j].harga,buku[j+1].harga);//Mengubah posisi harga dengan menyesuakan dengan array Penulis
                swap(buku[j].kode,buku[j+1].kode);//Mengubah posisi kode dengan menyesuakan dengan array Penulis
                swap(buku[j].stok,buku[j+1].stok);//Mengubah posisi stok dengan menyesuakan dengan array Penulis
            }
        }
    } 
}
void sortingHarga(Buku buku[],int triggerArray){//Fungsi untuk melakukan sorting berdasarkan harga
    for (int i=0;i<triggerArray;i++){
        for(int j=0;j<triggerArray-i-1;j++){
            if (buku[j].harga > (buku[j + 1].harga)){ //Melakukan perbandingan antara harga satu dan harga lainnya
                swap(buku[j].judul,buku[j+1].judul);//Mengubah posisi judul dengan menyesuakan dengan array Harga
                swap(buku[j].penulis,buku[j+1].penulis);//Mengubah posisi judul dengan menyesuakan dengan array Harga
                swap(buku[j].harga,buku[j+1].harga);//Mengubah posisi harga dengan menyesuakan dengan array Harga
                swap(buku[j].kode,buku[j+1].kode);//Mengubah posisi kode dengan menyesuakan dengan array Harga
                swap(buku[j].stok,buku[j+1].stok);//Mengubah posisi stok dengan menyesuakan dengan array Harga
            }
        }
    }
}
void ubahKode(Buku buku[],int triggerArray){//Fungsi untuk melakukan penyesuaian kode agar menjadi uppercase
    triggerArray = triggerArray -1;//Digunakan untuk menyamakan index yang akan dkigunakan
    string hurufBesar = buku[triggerArray].kode;
    int lebar = hurufBesar.length();//fungsi yang diguhnakan untuk mengukur lebar character dari string
    for (int i=0;i<=lebar;i++){
        hurufBesar[i] = toupper(hurufBesar[i]);//Fungsi yang digunakan untuk mengubah character menjadi uppercase
    }
    buku[triggerArray].kode = hurufBesar;
}
void ubahJudul(Buku buku[],int triggerArray){//Fungsi untuk melakukan penyesuaian judul agar menjadi kapital
    triggerArray = triggerArray -1;//Digunakan untuk menyamakan index yang akan dkigunakan
    string kecil = buku[triggerArray].judul;
    int lebar = kecil.length();//fungsi yang diguhnakan untuk mengukur lebar character dari string
    for (int i=0;i<=lebar;i++){
        kecil[i] = tolower(kecil[i]);//Fungsi yang digunakan untuk mengubah characer menjadi lowercase
    }
    string kapital = kecil;
    for (int i=0;i<=lebar;i++){
        char a = toupper(kapital[0]);//Fungsi yang digunakan untuk mengubah character menjadi uppercase pada index ke-0
        string timpa(1,a);//Agar hanya 1 character saja yang digunakan
        kapital = kapital.replace(0,1,timpa);//0 yang pertama merupakan posisi yang akan ditimpa,angka 1 merupakan hanya 1 angka yang akan ditimpa
        if (isspace (kapital[i])){ //ketika menemukan spasi maka akan diubah menjadi kapital juga
            char b= toupper(kapital[i+1]);//Fungsi yang digunakan untuk mengubah character pada urutan ke i+1 menjadi kapital
            string tindas(1,b);//Agar hanya 1 angka yang digunakan
            kapital.replace(i+1,1,tindas);//Untuk mereplace character setelah ada spasi menjadi kapital
        }
    }
    buku[triggerArray].judul=kapital;
}
void sesuaikanJudul(string &UbahDataKeranjang){//Fungsi untuk melakukan menyesuaikan judul agar menjadi kapital (dengan pointerUbahDataKeranjang untuk membuat nilai balik)
    string kecil = UbahDataKeranjang;
    int lebar = kecil.length();//fungsi yang diguhnakan untuk mengukur lebar character dari string
    for (int i=0;i<=lebar;i++){
            kecil[i] = tolower(kecil[i]);//Fungsi yang digunakan untuk mengubah characer menjadi lowercase
    }
    string kapital = kecil;
    for (int i=0;i<=lebar;i++){
        char a = toupper(kapital[0]);//Fungsi yang digunakan untuk mengubah character menjadi uppercase pada index ke-0
        string timpa(1,a);//Agar hanya 1 character saja yang digunakan
        kapital = kapital.replace(0,1,timpa);//0 yang pertama merupakan posisi yang akan ditimpa,angka 1 merupakan hanya 1 angka yang akan ditimpa
        if (isspace (kapital[i])){//ketika menemukan spasi maka akan diubah menjadi kapital juga
            char b= toupper(kapital[i+1]);//Fungsi yang digunakan untuk mengubah character pada urutan ke i+1 menjadi kapital
            string tindas(1,b);//Agar hanya 1 angka yang digunakan
            kapital.replace(i+1,1,tindas);//Untuk mereplace character setelah ada spasi menjadi kapital
        }
    }
    UbahDataKeranjang=kapital;
}
void ubahPenulis(Buku buku[],int triggerArray){//Fungsi untuk melakukan menyesuaikan Penulis agar menjadi kapital
    triggerArray = triggerArray -1;//Digunakan untuk menyamakan index yang akan dkigunakan
    string kecil = buku[triggerArray].penulis;
    int lebar = kecil.length();//fungsi yang diguhnakan untuk mengukur lebar character dari string
    for (int i=0;i<=lebar;i++){
        kecil[i] = tolower(kecil[i]);//Fungsi yang digunakan untuk mengubah characer menjadi lowercase
    }
    string kapital = kecil;
    for (int i=0;i<=lebar;i++){
        char a = toupper(kapital[0]);//Fungsi yang digunakan untuk mengubah character menjadi uppercase pada index ke-0
        string timpa(1,a);//Agar hanya 1 character saja yang digunakan
        kapital = kapital.replace(0,1,timpa);//0 yang pertama merupakan posisi yang akan ditimpa,angka 1 merupakan hanya 1 angka yang akan ditimpa
        if (isspace (kapital[i]) ){//ketika menemukan spasi  maka akan diubah menjadi kapital juga
            char b= toupper(kapital[i+1]);//Fungsi yang digunakan untuk mengubah character pada urutan ke i+1 menjadi kapital
            string tindas(1,b);//Agar hanya 1 angka yang digunakan
            kapital.replace(i+1,1,tindas);//Untuk mereplace character setelah ada spasi menjadi kapital
        }
    }
    buku[triggerArray].penulis=kapital;
}
void kodePembayaran(){//Fungsi yang digunakan untuk membuat kode pembayaran
    const char data[] = {"0123456789""ABCDEFGHIJKLMNOPQRSTUVWXYZ""abcdefghijklmnopqrstuvwxyz"};//Membuat database untuk data kode
    int size = sizeof(data)-1;//Mengukur lebar dari char array data
    int length = 16;//Membuat agar lebar data yang akan dibuat menjadi 16 character
    srand(time(0));//Membuat nilai awal dengan srand agar tidak berulang dan berdasarkan waktu dari komputer pertama kali dinyalakan
    for(int i=0;i<length;i++){
        cout<<data[rand()%size]; //Melakukan random data untuk memperolah kodep pembayaran
    }
}