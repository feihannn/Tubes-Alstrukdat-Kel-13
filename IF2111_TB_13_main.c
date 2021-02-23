/*TUGAS BESAR IF2111 ALGORITMA DAN STRUKTUR DATA*/
/*DISUSUN OLEH KELOMPOK 13*/
/*1. Anastasia Beatrice Caroline / 18219081*/
/*2. Elisabeth Gunawan / 18219031*/
/*3. Rahmat Pujiatno / 18219062*/
/*4. Marcelino Feihan / 18219006*/
/*5. Muhammad Husnul Daffa / 18219010*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"mesin_kata.h"
#include"mesin_kar.h"
#include"point.h"
#include"matriks.h"
#include"listlinier.h"
#include"graph.h"
#include"stack.h"
#include"dynamic.h"
#include"circular_queue.h"
/*ASUMSI*/
/*Graph dengan Info(G)=1 menandakan B, Graph dengan Info(G)=2 menandakan S*/

/*PERSIAPAN VARIABEL GLOBAL*/
int baris,kolom,pion,x,y,graphpoint,batas,pindah,uang=5000,infoharga1 = 0,tele=0,ctmember=0;
char check;/*Untuk menyimpan jenis pion pada file konfigurasi(Contoh B,C,S)*/
Point B,P,S,C1,C2,C3,C4,C5,C6,C7;/*Untuk menyimpan data B(Base),P(Player),S(Shop),C(Customer)*/ /*<x,y>*/
MATRIKS m;/*Menyimpan data matriks*/
Graph G;/*Graph untuk path pemain*/
addressGraph Awal,PosisiP;/*Untuk menginisialisasi pemanggilan graph dan menyatakan letak pemain pada graph*/
Stack stemp,orderbaru;/*stemp merupakan stack isi component dari add/removecomponent, orderbaru merupakan stack berisi orderan pelanggan*/
List L/*Inventory*/,shop/*shop*/;
Queue Q/*menyimpan urutan order game*/;
infostack buang/*variabel untuk menyimpan hasil pop stack*/;
boolean sedangbuild = false/*menyatakan sedang melakukan build atau tidak*/,masihlanjut=true/*untuk lanjut/exit dari game*/,member=false/*menyatakan member atau tidak*/; 

/*FUNGSI-FUNGSI PEMBANTU*/
int convertint(Kata CKata){
    /*Mengubah tipe Kata menjadi sebuah bilangan*/
    /*Digunakan untuk menyimpan data baris,kolom,dll*/
    int convert=0,ubah;
    for (int i=0;i<CKata.Length;i++){
        if(CKata.TabKata[i]=='1'){
            ubah=1;
        }
        else if(CKata.TabKata[i]=='2'){
            ubah=2;
        }
        else if(CKata.TabKata[i]=='3'){
            ubah=3;
        }
        else if(CKata.TabKata[i]=='4'){
            ubah=4;
        }
        else if(CKata.TabKata[i]=='5'){
            ubah=5;
        }
        else if(CKata.TabKata[i]=='6'){
            ubah=6;
        }
        else if(CKata.TabKata[i]=='7'){
            ubah=7;
        }
        else if(CKata.TabKata[i]=='8'){
            ubah=8;
        }
        else if(CKata.TabKata[i]=='9'){
            ubah=9;
        }
        else{
            ubah=0;
        }
        convert=10*convert+ubah;
    }
    return convert;
}
char convertchar(Kata CKata){
    /*Mengubah tipe Kata menjadi sebuah karakter*/
    /*Digunakan untuk menyimpan data Base,Shop,Customer*/
    if (CKata.TabKata[0]=='B'){
        return 'B';
    }
    else if (CKata.TabKata[0]=='S'){
        return 'S';
    }
    else{
        return 'C';
    }
    
}
Stack generateorder(int a){
    /*Membuat orderan pelanggan secara random*/
    Stack S1,S2,S3,S4,S5,S6;
    CreateEmptyStack(&S1);
    CreateEmptyStack(&S2);
    CreateEmptyStack(&S3);
    CreateEmptyStack(&S4);
    CreateEmptyStack(&S5);
    CreateEmptyStack(&S6);

    
    Push(&S1,"Asus ROG Maximus XII HERO","MotherBoard");
    Push(&S1,"AMD Ryzen 5 5600X","CPU");
    Push(&S1,"Corsair Vengeance LED","Memory");
    Push(&S1,"Noctua NH-D15","CPU Cooler");
    Push(&S1,"Armageddon Nimitz TR5000","Case");
    Push(&S1,"Nvidia GeForce RTX 2080 Super","GPU");
    Push(&S1,"Samsung 970 Evo Plus","Storage");
    Push(&S1,"EVGA SuperNOVA 1600 T2","PSU");
    /*Yang didapat:  3325
    Asli: 2825
    */
    Push(&S2,"Aorus X570 Master","MotherBoard");
    Push(&S2,"Intel Core i7-10700K","CPU");
    Push(&S2,"G.Skill Trident Z RGB","Memory");
    Push(&S2,"GamerStorm Deep Cool Assassin III","CPU Cooler");
    Push(&S2,"Cube Gamin Cabazon","Case");
    Push(&S2,"AMD Radeon VII","GPU");
    Push(&S2,"WD Black 3D","Storage");
    Push(&S2,"Seasonic Prime 1000W Titanium","PSU");
    
    /*Yang didapat:  2575
    Asli: 2075
    */
    Push(&S3,"Asus ROG Strix B550-E Gaming","MotherBoard");
    Push(&S3,"AMD Ryzen 5 3400G","CPU");
    Push(&S3,"Kingston HyperX Fury","Memory");
    Push(&S3,"Corsair H115i RGB Platinum","CPU Cooler");
    Push(&S3,"NZXT H510","Case");
    Push(&S3,"ZOTAC GeForce GTX 1080 Ti AMP Edition","GPU");
    Push(&S3,"Samsung SSD 960 Pro","Storage");
    Push(&S3,"Corsair CX550","PSU");
    
    /*Yang didapat:  2075
    Asli: 1575
    */

    Push(&S4,"Asus ROG Strix B550-E Gaming","MotherBoard");
    Push(&S4,"AMD Ryzen 5 3400G","CPU");
    Push(&S4,"Corsair Vengeance LED","Memory");
    Push(&S4,"Noctua NH-D15","CPU Cooler");
    Push(&S4,"Cube Gamin Cabazon","Case");
    Push(&S4,"AMD Radeon VII","GPU");
    Push(&S4,"Samsung SSD 960 Pro","Storage");
    Push(&S4,"Corsair CX550","PSU");
    
    /*Yang didapat:  2425
    Asli: 1925
    */

    Push(&S5,"Asus ROG Maximus XII HERO","MotherBoard");
    Push(&S5,"AMD Ryzen 5 5600X","CPU");
    Push(&S5,"G.Skill Trident Z RGB","Memory");
    Push(&S5,"GamerStorm Deep Cool Assassin III","CPU Cooler");
    Push(&S5,"NZXT H510","Case");
    Push(&S5,"ZOTAC GeForce GTX 1080 Ti AMP Edition","GPU");
    Push(&S5,"Samsung 970 Evo Plus","Storage");
    Push(&S5,"EVGA SuperNOVA 1600 T2","PSU");
    
    /*Yang didapat: 2850  
    Asli: 2350
    */
    Push(&S6,"Aorus X570 Master","MotherBoard");
    Push(&S6,"Intel Core i7-10700K","CPU");
    Push(&S6,"Kingston HyperX Fury","Memory");
    Push(&S6,"Corsair H115i RGB Platinum","CPU Cooler");
    Push(&S6,"Armageddon Nimitz TR5000","Case"); 
    Push(&S6,"Nvidia GeForce RTX 2080 Super","GPU");
    Push(&S6,"WD Black 3D","Storage");
    Push(&S6,"Seasonic Prime 1000W Titanium","PSU");
    
    /*Yang didapat: 2700
    Asli: 2200
    */
    if (a==1){
        return S1;
    }
    else if (a==2){
        return S2;
    }
    else if(a==3){
        return S3;
    }
    else if (a==4){
        return S4;
    }
    else if (a==5){
        return S5;
    }
    else{
        return S6;
    }
}
void SETUP(){
    /*Mempersiapkan semua data yang diperlukan*/
    /*Melakukan import file, membuat matriks,dll*/

    /*MEMBUKA FILE*/
    /*File yang dibuka dianggap selalu bernama "konfigurasi.txt"*/
    STARTKATA();
    /*Pada Tahap ini, maka sudah ada kata pertama yang disimpan sehingga bisa langsung diproses untuk tahap berikutnya(Membuat matriks)*/

    /*PENYIAPAN DAN PEMBUATAN MATRIKS*/
    baris=convertint(CKata);
    ADVKATA();
    kolom=convertint(CKata);
    MakeMATRIKS(baris,kolom,&m);
    ADVKATA();

    /*PENYIAPAN POSISI SETIAP PION*/
    pion=convertint(CKata);
    ADVKATA();

    /*PENYIAPAN POINT B DAN P*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    B=MakePoint(x,y);
    P=MakePoint(x,y);/*Karena pada posisi awal, P akan berada pada titik yang sama dengan B*/

    /*PENYIAPAN POINT S*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    S=MakePoint(x,y);

     /*PENYIAPAN POINT C1*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C1=MakePoint(x,y);

     /*PENYIAPAN POINT C2*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C2=MakePoint(x,y);

     /*PENYIAPAN POINT C3*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C3=MakePoint(x,y);

    /*PENYIAPAN POINT C4*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C4=MakePoint(x,y);

     /*PENYIAPAN POINT C5*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C5=MakePoint(x,y);

     /*PENYIAPAN POINT C6*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C6=MakePoint(x,y);

     /*PENYIAPAN POINT C7*/
    check=convertchar(CKata);
    ADVKATA();
    y=convertint(CKata);
    ADVKATA();
    x=convertint(CKata);
    ADVKATA();
    C7=MakePoint(x,y);

    /*SETTING PETA BARU*/
    IsiMARTRIKS(&m,Ordinat(B),Absis(B),'B');
    IsiMARTRIKS(&m,Ordinat(S),Absis(S),'S');
    IsiMARTRIKS(&m,Ordinat(C1),Absis(C1),'1');
    IsiMARTRIKS(&m,Ordinat(C2),Absis(C2),'2');
    IsiMARTRIKS(&m,Ordinat(C3),Absis(C3),'3');
    IsiMARTRIKS(&m,Ordinat(C4),Absis(C4),'4');
    IsiMARTRIKS(&m,Ordinat(C5),Absis(C5),'5');
    IsiMARTRIKS(&m,Ordinat(C6),Absis(C6),'6');
    IsiMARTRIKS(&m,Ordinat(C7),Absis(C7),'7');
    
    /*PERSIAPAN GRAPH*/
    CreateEmptyGraph(&G);
    initGraph(&G,pion);
    for (int i=1;i<=pion;i++){
        for (int j=1;j<=pion;j++){
            graphpoint=convertint(CKata);
            if(graphpoint==1){
                AddLink(&G,i,j);
            }
            ADVKATA();
        }
    }
    /*PERSIAPAN SHOP*/
    shop=MakeList();
    InsertLast(&shop,1,"MotherBoard","Asus ROG Maximus XII HERO",500);
    InsertLast(&shop,2,"MotherBoard","Aorus X570 Master",300);
    InsertLast(&shop,3,"MotherBoard","Asus ROG Strix B550-E Gaming",150);
    InsertLast(&shop,4,"CPU","AMD Ryzen 5 5600X",350);
    InsertLast(&shop,5,"CPU","Intel Core i7-10700K",325);
    InsertLast(&shop,6,"CPU","AMD Ryzen 5 3400G",250);
    InsertLast(&shop,7,"Memory","Corsair Vengeance LED",325);
    InsertLast(&shop,8,"Memory","G.Skill Trident Z RGB",275);
    InsertLast(&shop,9,"Memory","Kingston HyperX Fury",200);
    InsertLast(&shop,10,"CPU Cooler","Noctua NH-D15",400);
    InsertLast(&shop,11,"CPU Cooler","GamerStorm Deep Cool Assassin III",300);
    InsertLast(&shop,12,"CPU Cooler","Corsair H115i RGB Platinum",250);
    InsertLast(&shop,13,"Case","Armageddon Nimitz TR5000",175);
    InsertLast(&shop,14,"Case","Cube Gamin Cabazon",125);
    InsertLast(&shop,15,"Case","NZXT H510",100);
    InsertLast(&shop,16,"GPU","Nvidia GeForce RTX 2080 Super",650);
    InsertLast(&shop,17,"GPU","AMD Radeon VII",450);
    InsertLast(&shop,18,"GPU","ZOTAC GeForce GTX 1080 Ti AMP Edition",400);
    InsertLast(&shop,19,"Storage","Samsung 970 Evo Plus",225);
    InsertLast(&shop,20,"Storage","WD Black 3D",150);
    InsertLast(&shop,21,"Storage","Samsung SSD 960 Pro",125);
    InsertLast(&shop,22,"PSU","EVGA SuperNOVA 1600 T2",200);
    InsertLast(&shop,23,"PSU","Seasonic Prime 1000W Titanium",150);
    InsertLast(&shop,24,"PSU","Corsair CX550",100);
    
    /*PERSIAPAN URUTAN ORDER PELANGGAN*/
    Q=CreateQueue(5);
    srand(time(NULL));
    for(int i=0;i<3;i++){
        /*Merandom pesanan pelanggan*/
        int RandomStack = rand()%(6-1) + 1;
        int RandomPelanggan = rand()%(7-1)+1;
        orderbaru=generateorder(RandomStack);
        if (i==0){
            if (RandomStack == 1){
                PushQueue(&Q, 1, RandomPelanggan, 3325, &orderbaru);
            }
            else if (RandomStack == 2){
                PushQueue(&Q, 1, RandomPelanggan, 2575, &orderbaru);
            }
            else if (RandomStack == 3){
                PushQueue(&Q, 1, RandomPelanggan, 2075, &orderbaru);
            }
            else if (RandomStack == 4){
                PushQueue(&Q, 1, RandomPelanggan, 2425, &orderbaru);
            }
            else if (RandomStack == 5){
                PushQueue(&Q, 1 ,RandomPelanggan, 2850, &orderbaru);
            }
            else{ //RandomStack == 6
                PushQueue(&Q, 1, RandomPelanggan, 2700, &orderbaru);
            }
        }
        else
        {
            if (RandomStack == 1){
                PushQueue(&Q, Q.T[i-1].nomor+1, RandomPelanggan, 3325, &orderbaru);
            }
            else if (RandomStack == 2){
                PushQueue(&Q, Q.T[i-1].nomor+1, RandomPelanggan, 2575, &orderbaru);
            }
            else if (RandomStack == 3){
                PushQueue(&Q, Q.T[i-1].nomor+1, RandomPelanggan, 2075, &orderbaru);
            }
            else if (RandomStack == 4){
                PushQueue(&Q, Q.T[i-1].nomor+1, RandomPelanggan, 2425, &orderbaru);
            }
            else if (RandomStack == 5){
                PushQueue(&Q, Q.T[i-1].nomor+1 ,RandomPelanggan, 2850, &orderbaru);
            }
            else{ //RandomStack == 6
                PushQueue(&Q, 1, RandomPelanggan, 2700, &orderbaru);
            }
        }
        
    }
    /*MEMBUAT INVENTORY KOSONG*/
    L=MakeList();
    /*MENGINISIALISASI KEADAAN SEDANGBUILD*/
    sedangbuild=false;
}
/*FUNGSI-FUNGSI UTAMA*/
void MOVE(){
    ListL L;
    addressListL pertama;
    int opsi,no=1,i=1;
    Awal=FirstGraph(G);
    /*PENAMPILAN POSISI PEMAIN SEKARANG*/
    printf("Kamu berada pada ");
    if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
        printf("base.");
        batas=1;
    }
    else if ((Absis(P)==Absis(S))&&(Ordinat(P)==Ordinat(S))){
        printf("shop."); 
        batas=2;
    }
    else if ((Absis(P)==Absis(C1))&&(Ordinat(P)==Ordinat(C1))){
        printf("Pelanggan 1.");
        batas=3;
    }
    else if ((Absis(P)==Absis(C2))&&(Ordinat(P)==Ordinat(C2))){
        printf("Pelanggan 2.");
        batas=4;
    }
    else if ((Absis(P)==Absis(C3))&&(Ordinat(P)==Ordinat(C3))){
        printf("Pelanggan 3.");
        batas=5;
    }
    else if ((Absis(P)==Absis(C4))&&(Ordinat(P)==Ordinat(C4))){
        printf("Pelanggan 4.");
        batas=6;
    }
    else if ((Absis(P)==Absis(C5))&&(Ordinat(P)==Ordinat(C5))){
        printf("Pelanggan 5.");
        batas=7;
    }
    else if ((Absis(P)==Absis(C6))&&(Ordinat(P)==Ordinat(C6))){
        printf("Pelanggan 6.");
        batas=8;
    }
    else if ((Absis(P)==Absis(C7))&&(Ordinat(P)==Ordinat(C7))){
        printf("Pelanggan 7.");
        batas=9;
    }
    else{
        printf("Tempat tidak ditemukkan");
    }

    printf("\n");
    /*PENAMPILAN TUJUAN YANG BISA DICAPAI OLEH PEMAIN DARI POSISI PEMAIN*/
    printf("Daftar lokasi yang dapat dicapai: ");
    while (InfoGraph(Awal)<batas){
        Awal=Next(Awal);
    }
    PosisiP=Awal;
    L=Link(Awal);
    printf("\n");
    pertama=First(L);
    if (!IsListLEmpty(L)){
        while (pertama!=NULL){
            printf("%d. ",no);
            if (Info(pertama)==1){
                printf("Base");
            }
            else if(Info(pertama)==2){
                printf("Shop");
            }
            else{
                printf("Pelanggan %d",Info(pertama)-2);
            }
            printf("\n");
            no++;
            pertama=Next(pertama);
        }
    }
    /*MENERIMA DAN MEMVALIDASI NOMOR TUJUAN PEMAIN*/
    printf("Nomor tujuan: ");
    scanf("%d",&opsi);
    while ((opsi<1)||(opsi>no-1)){
        printf("Pilihan tidak valid. Masukkan Nomor Tujuan ulang: ");
        scanf("%d",&opsi);
    }
    /*PENYESUAIAN POSISI PEMAIN SETELAH MENERIMA INPUT TUJUAN*/
    pertama=First(L);
    while (i<opsi){
        pertama=Next(pertama);
        i++;
    }
    while (InfoGraph(Awal)<Info(pertama)){
        Awal=Next(Awal);
    }
    PosisiP=Awal;
    /*PENYAMPAIAN PESAN BILA PEMAIN SUDAH MENCAPAI TITIK TUJUANNYA*/
    printf("Kamu telah mencapai lokasi ");
    if (Info(pertama)==1){
        P=MakePoint(Absis(B),Ordinat(B));
        printf("Base!");
    }
    else if(Info(pertama)==2){
        P=MakePoint(Absis(S),Ordinat(S));
        printf("Shop!");
    }
    else if(Info(pertama)==3){
        P=MakePoint(Absis(C1),Ordinat(C1));
        printf("Pelanggan 1!");
    }
    else if(Info(pertama)==4){
        P=MakePoint(Absis(C2),Ordinat(C2));
        printf("Pelanggan 2!");
    }
    else if(Info(pertama)==5){
        P=MakePoint(Absis(C3),Ordinat(C3));
        printf("Pelanggan 3!");
    }
    else if(Info(pertama)==6){
        P=MakePoint(Absis(C4),Ordinat(C4));
        printf("Pelanggan 4!");
    }
    else if(Info(pertama)==7){
        P=MakePoint(Absis(C5),Ordinat(C5));
        printf("Pelanggan 5!");
    }
    else if(Info(pertama)==8){
        P=MakePoint(Absis(C6),Ordinat(C6));
        printf("Pelanggan 6!");
    }
    else if(Info(pertama)==9){
        P=MakePoint(Absis(C7),Ordinat(C7));
        printf("Pelanggan 7!");
    }
    else{
        printf("Error");
    }
    printf("\n");
}
void STATUS (Queue Q, List L){
    /*Kamus Lokal*/
    int i;
    /*Algoritma*/
    printf("Uang tersisa: $%i\n",uang);
    printf("Build yang sedang dikerjakan: pesanan %d untuk pelanggan %d\n", InfoNomorHead(Q), InfoPelangganHead(Q));
    /*PENAMPILAN LOKASI PEMAIN*/
    printf("Lokasi: pemain sedang berada pada ");
    if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
        printf("base.");
        batas=1;
    }
    else if ((Absis(P)==Absis(S))&&(Ordinat(P)==Ordinat(S))){
        printf("shop."); 
        batas=2;
    }
    else if ((Absis(P)==Absis(C1))&&(Ordinat(P)==Ordinat(C1))){
        printf("Pelanggan 1.");
        batas=3;
    }
    else if ((Absis(P)==Absis(C2))&&(Ordinat(P)==Ordinat(C2))){
        printf("Pelanggan 2.");
        batas=4;
    }
    else if ((Absis(P)==Absis(C3))&&(Ordinat(P)==Ordinat(C3))){
        printf("Pelanggan 3.");
        batas=5;
    }
    else if ((Absis(P)==Absis(C4))&&(Ordinat(P)==Ordinat(C4))){
        printf("Pelanggan 4.");
        batas=6;
    }
    else if ((Absis(P)==Absis(C5))&&(Ordinat(P)==Ordinat(C5))){
        printf("Pelanggan 5.");
        batas=7;
    }
    else if ((Absis(P)==Absis(C6))&&(Ordinat(P)==Ordinat(C6))){
        printf("Pelanggan 6.");
        batas=8;
    }
    else if ((Absis(P)==Absis(C7))&&(Ordinat(P)==Ordinat(C7))){
        printf("Pelanggan 7.");
        batas=9;
    }
    else{
        printf("Tempat tidak ditemukkan");
    }
    printf("\n");
    /*PENAMPILAN INVENTORY PEMAIN*/
    printf("Inventory anda:\n");
    if (IsEmptyDynamic(L)){
        printf("Inventory Kosong\n");
    }
    else{
        i = 0;
        while (i < L.Neff){
            printf("%d. %s (%d)\n", i+1,L.A[i].barang, L.A[i].kuantitas);
            i++;
        }
    }
}
void CHECKORDER(){
    /*MENAMPILKAN ORDER YANG SEDANG/DAPAT DIKERJAKAN OLEH PEMAIN*/
    if(!IsEmptyQueue(Q)){
        printf("Nomor Order: %d\n",InfoNomorHead(Q));
        printf("Pemesan: %d\n",InfoPelangganHead(Q));
        printf("Invoice: $%d\n",InfoBiayaHead(Q));
        for (int i=0;i<8;i++){
            printf("%d. %s\n",i+1,InfoStackHead(Q).T[i].nama);
        }
    }
    else
    {
        printf("Sedang tidak ada pesanan. Silahkan ENDDAY untuk mendapatkan pesanan baru\n");
    }
    
   
}
void STARTBUILD(){
    /*MEMULAI BUILD PEMAIN*/
    /*HANYA BISA DILAKUKAN BILA SUDAH DI BASE*/
    if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
        if (sedangbuild == false){
            /*JIKA BELUM MELAKUKAN BUILD, MAKA PROGRAM DAPAT BERJALAN*/
            sedangbuild = true;
            CreateEmptyStack(&stemp);
            printf("Kamu telah memulai pesanan ");
            printf("%d ",InfoNomorHead(Q));
            printf("untuk pelanggan ");
            printf("%d\n",InfoPelangganHead(Q));
        }
        else{
            /*JIKA SEDANG MELAKUKAN BUILD, MAKA PROGRAM TIDAK DAPAT DIGUNAKAN*/
            printf("Anda sedang melakukan build! Silahkan selesaikan pesanan anda terlebih dahulu!\n");
        }
    }
    else{
        /*BILA PEMAIN TIDAK BERADA DI BASE, MAKA TIDAK BISA DIJALANKAN*/
        printf("Anda harus berada di Base untuk melakukan STARTBUILD!\n");
    }
    
}
void FINISHBUILD(Stack *S, Queue Q, List *L) /*S: temporary stack*/
{
    /*MENGAKHIRI STATUS SEDANGBUILD PEMAIN DAN MEMINDAHKANNYA KE INVENTORY*/
    /*HANYA BISA DILAKUKAN DI BASE*/
    if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
        boolean found;
        found = false;
        /*PENGECHECKAN APABILA SEMUA ELEMEN ORDER DAN BUILD PEMAIN SUDAH SAMA*/
        if ((*S).TOP==7)
        {
            if (InfoStackHead(Q).T[0].nama == (*S).T[0].nama)
            {
                if (InfoStackHead(Q).T[1].nama == (*S).T[1].nama)
                {
                    if (InfoStackHead(Q).T[2].nama == (*S).T[2].nama)
                    {
                        if (InfoStackHead(Q).T[3].nama == (*S).T[3].nama)
                        {
                            if (InfoStackHead(Q).T[4].nama == (*S).T[4].nama)
                            {
                                if (InfoStackHead(Q).T[5].nama == (*S).T[5].nama)
                                {
                                    if (InfoStackHead(Q).T[6].nama == (*S).T[6].nama)
                                    {
                                        if (InfoStackHead(Q).T[7].nama == (*S).T[7].nama)
                                        {
                                            found = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        /*JIKA SUDAH SAMA, MAKA DILAKUKAN PEMINDAHAN KE INVENTORY,PENGOSONGAN STACK DAN MELAKUKAN PEMBACAAN ORDER BERIKUTNYA*/
        if (found == true)
        {
            sedangbuild=false;
            /*PENGOSONGAN STACK*/
            for (int i=0;i<8;i++){
                (*S).T[i].kategori=NULL;
                (*S).T[i].nama=NULL;
            }
            /*PENGISIAN KE INVENTORY*/
            if (InfoPelangganHead(Q)==1){
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 1", 1);
            }
            else if (InfoPelangganHead(Q)==2){
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 2", 1);
            }
            else if (InfoPelangganHead(Q)==3){
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 3", 1);
            }
            else if (InfoPelangganHead(Q)==4){
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 4", 1);
            }
            else if (InfoPelangganHead(Q)==5){
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 5", 1);
            }
            else if (InfoPelangganHead(Q)==6){
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 6", 1);
            }
            else {
                InsertLast(L,(*L).Neff+1,"Paket","Pesanan Pelanggan 7", 1);
            }
            /*MENYIMPAN UANG HASIL ORDERAN KE VARIABEL*/
            if (infoharga1 == 0)
            {
                infoharga1 = InfoBiayaHead(Q);
            }
            printf("Pesanan %d telah selesai. Silahkan antar ke pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
            PopQueue(&Q);
        }
        else
        {
            printf("Komponen yang dipasangkan belum sesuai dengan pesanan, build belum dapat diselesaikan.\n");
        }
    }
    else
    {
        printf("Anda harus berada pada Base untuk melakukan FINISHBUILD\n");
    }
    
}
void ADDCOMPONENT(){
    /*MELAKUKAN PENAMBAHAN KOMPONEN KE STACK*/
    /*HANYA BISA DILAKUKAN DI BASE*/
    if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
        /*HANYA BISA DILAKUKAN BILA SEDANG MELAKUKAN BUILD*/
        if (sedangbuild==true){
            int pilihan,countops=0,hitung=0;
            /*MENAMPILKAN KOMPONEN YANG SUDAH TERPASANG*/
            printf("Komponen yang telah terpasang: \n");
            for (int i=0;i<8;i++){
                if ((stemp.T[i].nama!=NULL)&&(stemp.TOP!=-1)){
                    printf("%d. %s\n",i+1,stemp.T[i].nama);
                    countops++;
                }
            }
            if (countops==0){
                printf("{Kosong}\n");
            }
            /*MENAMPILKAN KEADAAN INVENTORY SEKARANG*/
            printf("Komponen yang tersedia: \n");
            for (int i=0;i<Length(L);i++){
                printf("%d. %s\n",i+1,L.A[i].barang);
                hitung++;
            }
            if (hitung==0){
                printf("{Kosong}\n");
                printf("Belum ada barang yang bisa ditambahkan. Silahkan pergi ke Shop terlebih dahulu.\n");
            }
            /*JIKA INVENTORY TIDAK KOSONG, MAKA DAPAT DILAKUKAN PENAMBAHAN KE STACK*/
            else{
                printf("Komponen yang ingin dipasang: ");
                /*MENERIMA DAN MEMVALIDASI INPUT KOMPONEN DARI PEMAIN*/
                scanf("%d",&pilihan);
                while((pilihan<1)||(pilihan>hitung)){
                    printf("Input tidak valid, Silahkan lakukan input ulang: ");
                    scanf("%d",&pilihan);
                }
                pilihan--;
                boolean found=false;
                /*MELAKUKAN PENGECHECKAN APAKAH KATEGORI KOMPONEN TERSEBUT SUDAH ADA DI STACK*/
                for (int i=0;i<=TOP(stemp);i++){
                    if(stemp.T[TOP(stemp)].kategori==L.A[pilihan].kategori){
                        found=true;
                    }
                }
                if (found==false){
                    /*BILA BELUM ADA KATEGORI TERSEBUT DISTACK, MELAKUKAN PUSH PADA STACK*/
                    Push(&stemp,L.A[pilihan].barang,L.A[pilihan].kategori);
                    /*JIKA PADA INVENTORY TERDAPAT BARANG DENGAN NAMA YANG SAMA DENGAN JUMLAH LEBIH DARI 1, MAKA KUANTITASNYA DIKURANGI*/
                    if (L.A[pilihan].kuantitas>1){
                        L.A[pilihan].kuantitas--;
                    }
                    /*JIKA PADA INVENTORY HANYA ADA 1 BARANG TERSEBUT, MAKA DIHAPUS DARI INVENTORY*/
                    else{
                        DeleteElemen(&L,pilihan);
                    }
                    printf("Komponen berhasil dipasang!\n");
                }
                else{
                    /*BILA KATEGORI KOMPONEN YANG DIPUSH SUDAH ADA DISTACK, MAKA PUSH GAGAL*/
                    printf("Komponen dengan kategori tersebut sudah dipasang\n");
                }
            }  
        }
        else{
            /*BILA BELUM MELAKUKAN BUILD, MAKA PROGRAM TIDAK BERJALAN*/
            printf("Anda sedang tidak melakukan build! Silahkan STARTBUILD terlebih dahulu\n");
        }
    }
    else
    {
        /*BILA PEMAIN TIDAK DI BASE, MAKA PROGRAM TIDAK BERJALAN*/
        printf("Anda harus berada di Base dan sedang melakukan build!Silahkan gunakan fungsi Move ke Base dan memulai build!.\n");
    }
    
}

void REMOVECOMPONENT(){
    /*HANYA BISA DILAKUKAN DI BASE*/
    /*MEM-POP STACK KOMPONEN YANG DIPASANG PEMAIN*/
    if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
        /*HANYA BISA DILAKUKAN BILA SEDANG MELAKUKAN BUILD*/
        if(sedangbuild==true){
            boolean ada=false,dor=false;
            /* JIKA STACK TIDAK KOSONG, MAKA POP DILAKUKAN*/
            if (!IsEmptyStack(stemp)){
                Pop(&stemp,&buang);  
                dor=true;
            }
            /*BILA POP BERHASIL DILAKUKAN, MAKA DILAKUKAN PENAMBAHAN KE INVENTORY*/
            if (dor==true){
                for (int i=0;i<Length(L);i++){
                    /*BILA BARANG SUDAH ADA DI INVENTORY, MAKA HANYA KUANTITASNYA YANG DITAMBAHKAN*/
                    if (L.A[i].barang==buang.nama){
                        ada=true;
                        L.A[i].kuantitas = L.A[i].kuantitas + 1;
                    }
                }
                if (ada == false){
                    /*BILA BELUM ADA BARANG TERSEBUT PADA INVENTORY, MAKA LAKUKAN INSERT PADA INVENTORY*/
                    if (IsEmptyDynamic(L)){  
                        InsertFirst(&L,1,buang.kategori,buang.nama,1);
                    }
                    else
                    {
                        InsertLast(&L,1,buang.kategori,buang.nama,1);
                    }
                }  
                printf("Komponen %s berhasil dicopot!\n",L.A[L.Neff-1].barang);
            }
            else{
                /*BILA POP GAGAL AKIBAR STACK KOSONG, MENAMPILKAN ERROR*/
                printf("Belum ada barang yang ditambahkan ke stack. Silahkan gunakan ADDCOMPONENT terlebih dahulu.\n");
            }
        }
        else{
            /*BILA BELUM MELAKUKAN BUILD, TAMPILKAN PESAN ERROR*/
            printf("Anda sedang tidak melakukan build! Silahkan STARTBUILD terlebih dahulu\n");
        }
        
    }
    else{
        /*BILA SEDANG TIDAK DI BASE, TAMPILKAN PESAN ERROR*/
        printf("Anda harus berada di Base dan sedang melakukan build!Silahkan gunakan fungsi Move ke Base dan memulai build!.\n");
    }
}
void SHOP(){
    /*HANYA BISA DILAKUKAN BILA POSISI PEMAIN DI SHOP*/
    /*MEMBELI BARANG SESUAI PERMINTAAN PEMAIN*/
    int beli,jumlah,bayar,titik;
    if ((Absis(P)==Absis(S))&&(Ordinat(P)==Ordinat(S))){
        /*MENAMPILKAN DAFTAR BARANG YANG DAPAT DIBELI*/
        printf("Komponen yang tersedia:\n");
        for (int i=0;i<Length(shop);i++){
            if(shop.A[i].kategori==shop.A[i+2].kategori){
                printf("Kategori %s:\n",shop.A[i].kategori);
            }
            printf("%d. %s - $%d\n",shop.A[i].nomor,shop.A[i].barang,shop.A[i].kuantitas);
            if(shop.A[i].kategori!=shop.A[i+1].kategori){
                printf("\n");
            }
        }
        printf("0. Batal\n");
        /*MENERIMA INPUT PEMAIN TENTANG BARANG YANG INGIN DIBELI*/
        printf("Komponen yang ingin dibeli: ");
        scanf("%d",&beli);
        if(beli<1||beli>24){
            printf("Pembelian dibatalkan\n");
        }
        else{
            /*BILA INPUT VALID, MAKA AKAN DILAKUKAN TRANSAKSI*/
            printf("Masukkan jumlah yang ingin dibeli: ");
            scanf("%d",&jumlah);
            beli--;
            /*PENENTUAN BIAYA*/
            bayar=jumlah*(shop.A[beli].kuantitas);
            if(member==true){
                /*BILA MEMBER, AKAN MENDAPATKAN POTONGAN HARGA*/
                printf("Anda merupakan Member! Mendapatkan potongan harga $50\n");
                bayar-=50;
                printf("Harga yang anda bayarkan: %d\n",bayar);
            }
            /*JIKA UANG MENCUKUPI, MAKA TRANSAKSI DILANJUTKAN*/
            if (uang>=bayar){
                uang-=bayar;
                char *cek=shop.A[beli].barang;
                boolean ada=false;
                /*BILA BARANG SUDAH ADA DI INVENTORY, MAKA LAKUKAN PENAMBAHAN KUANTITAS*/
                for (int i=0;i<Length(L);i++){
                    if(L.A[i].barang==cek){
                        ada=true;
                        titik=i;
                    }
                }
                if(ada==true){
                    L.A[titik].kuantitas++;
                }
                /*BILA BELUM ADA BARANG TERSEBUT PADA INVENTORY, LAKUKAN PENAMBAHAN PADA INVENTORY*/
                else{
                    if (IsEmptyDynamic(L)){
                        InsertLast(&L,1,shop.A[beli].kategori,shop.A[beli].barang,jumlah);
                    }
                    else
                    {
                        InsertLast(&L,L.A[Length(L)-1].nomor,shop.A[beli].kategori,shop.A[beli].barang,jumlah);
                    }
                }
                /*BILA TRANSAKSI BERHASIL, PESAN DITAMPILKAN*/
                printf("Komponen berhasil dibeli!\n");
            }
            else{
                /*SAAT UANG TIDAK CUKUP, PEMBELIAN AKAN GAGAL*/
                printf("Uang tidak cukup!\n");
            }
        }  
    }
    else
    {
        /*BILA PEMAIN TIDAK ADA DI SHOP, MAKA PROGRAM TIDAK DAPAT BERJALAN*/
        printf("Anda belum berada di Shop. Gunakan MOVE untuk pindah ke Shop terlebih dahulu.\n");
    }
    
}
void DELIVER()
{
    int batas,hapus;
    boolean found=false;
    char *banding;
    /* MENCARI POSISI PEMAIN SEKARANG DAN MEMASANG MARKER(BERUPA 'batas') */
    if ((Absis(P)==Absis(C1))&&(Ordinat(P)==Ordinat(C1))){
        batas=1;
    }
    else if ((Absis(P)==Absis(C2))&&(Ordinat(P)==Ordinat(C2))){
        batas=2;
    }
    else if ((Absis(P)==Absis(C3))&&(Ordinat(P)==Ordinat(C3))){
        batas=3;
    }
    else if ((Absis(P)==Absis(C4))&&(Ordinat(P)==Ordinat(C4))){
        batas=4;
    }
    else if ((Absis(P)==Absis(C5))&&(Ordinat(P)==Ordinat(C5))){
        batas=5;
    }
    else if ((Absis(P)==Absis(C6))&&(Ordinat(P)==Ordinat(C6))){
        batas=6;
    }
    else if ((Absis(P)==Absis(C7))&&(Ordinat(P)==Ordinat(C7))){
        batas=7;
    }
    else{
        batas=0;
    }
    /*PENGECHECKAN KASUS POSISI PEMAIN*/
    if (batas==1){
        /*BILA BERADA PADA BATAS 1, MENCARI BARANG 'Pesanan Pelanggan 1'*/
        banding="Pesanan Pelanggan 1";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
        /*BILA TERDAPAT PESANAN PELANGGAN 1 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
        if (found==true){
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        /*BILA BELUM ADA PESANAN PELANGGAN 1, TAMPILKAN PESAN ERROR*/
        else{
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else if (batas==2){
         /*BILA BERADA PADA BATAS 2, MENCARI BARANG 'Pesanan Pelanggan 2'*/
        banding="Pesanan Pelanggan 2";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
         /*BILA TERDAPAT PESANAN PELANGGAN 2 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
        if (found==true){
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        else{
        /*BILA BELUM ADA PESANAN PELANGGAN 2, TAMPILKAN PESAN ERROR*/
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else if (batas==3){
         /*BILA BERADA PADA BATAS 3, MENCARI BARANG 'Pesanan Pelanggan 3'*/
        banding="Pesanan Pelanggan 3";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
        if (found==true){
         /*BILA TERDAPAT PESANAN PELANGGAN 3 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        else{
        /*BILA BELUM ADA PESANAN PELANGGAN 3, TAMPILKAN PESAN ERROR*/
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else if (batas==4){
         /*BILA BERADA PADA BATAS 4, MENCARI BARANG 'Pesanan Pelanggan 4'*/
        banding="Pesanan Pelanggan 4";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
        if (found==true){
         /*BILA TERDAPAT PESANAN PELANGGAN 4 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        else{
        /*BILA BELUM ADA PESANAN PELANGGAN 4, TAMPILKAN PESAN ERROR*/
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else if (batas==5){
         /*BILA BERADA PADA BATAS 5, MENCARI BARANG 'Pesanan Pelanggan 5'*/
        banding="Pesanan Pelanggan 5";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
        if (found==true){
         /*BILA TERDAPAT PESANAN PELANGGAN 5 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        else{
        /*BILA BELUM ADA PESANAN PELANGGAN 5, TAMPILKAN PESAN ERROR*/
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else if (batas==6){
           /*BILA BERADA PADA BATAS 6, MENCARI BARANG 'Pesanan Pelanggan 6'*/
        banding="Pesanan Pelanggan 6";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
        if (found==true){
         /*BILA TERDAPAT PESANAN PELANGGAN 6 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        else{
        /*BILA BELUM ADA PESANAN PELANGGAN 6, TAMPILKAN PESAN ERROR*/
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else if (batas==7){
        /*BILA BERADA PADA BATAS 7, MENCARI BARANG 'Pesanan Pelanggan 7'*/
        banding="Pesanan Pelanggan 7";
        for (int i=0;i<Length(L);i++){
            if(L.A[i].barang==banding){
                found=true;
                hapus=i;
            }
        }
        if (found==true){
        /*BILA TERDAPAT PESANAN PELANGGAN 7 PADA INVENTORY, DILAKUKAN PENGHAPUSAN PESANAN TERSEBUT DARI INVENTORY*/
            DeleteElemen(&L,hapus);
            ctmember++;
            printf("Pesanan #%d berhasil diantarkan kepada pelanggan %d\n",InfoNomorHead(Q),InfoPelangganHead(Q));
        }
        else{
            /*BILA BELUM ADA PESANAN PELANGGAN 7, TAMPILKAN PESAN ERROR*/
            printf("Belum ada pesanan yang sesuai dengan pelanggan %d\n",InfoPelangganHead(Q));
        }
    }
    else{
        /*BILA PEMAIN INGIN MELAKUKAN DELIVER DI BASE/SHOP, MAKA DITAMPILKAN ERROR*/
        printf("Lokasi tidak valid. Silahkan lakukan 'MOVE' terlebih dahulu\n");
    }
    if (found==true)
    {
        /*PENAMBAHAN UANG PEMAIN SESUAI BAYARAN DARI PESANAN*/
        if (infoharga1 != 0)
        {
            uang = uang + infoharga1;
            infoharga1=0;
        }
        PopQueue(&Q);
    }

}

void ENDDAY(){
    /*MELAKUKAN PENGISIAN ULANG ORDER DARI PELANGGAN SECARA RANDOM*/
    while (!IsFullQueue(Q)){
        srand(time(NULL));
        int RandomStack = rand()%(6-1) + 1;
        int RandomPelanggan = rand()%(7-1)+1;
        orderbaru=generateorder(RandomStack);
        /*MELAKUKAN PUSH KE QUEUE SESUAI HASIL RANDOM*/
        if (RandomStack == 1){
            PushQueue(&Q, InfoNomorTail(Q)+1, RandomPelanggan, 3325, &orderbaru);
        }
        else if (RandomStack == 2){
            PushQueue(&Q, InfoNomorTail(Q)+1, RandomPelanggan, 2575, &orderbaru);
        }
        else if (RandomStack == 3){
            PushQueue(&Q, InfoNomorTail(Q)+1, RandomPelanggan, 2075, &orderbaru);
        }
        else if (RandomStack == 4){
            PushQueue(&Q, InfoNomorTail(Q)+1, RandomPelanggan, 2425, &orderbaru);
        }
        else if (RandomStack == 5){
            PushQueue(&Q, InfoNomorTail(Q)+1, RandomPelanggan, 2850, &orderbaru);
        }
        else{ //RandomStack == 6
            PushQueue(&Q, InfoNomorTail(Q)+1, RandomPelanggan, 2700, &orderbaru);
        }
    }
    /*MENYATAKAN/MERISET BERBAGAI COUNTER PROGRAM PADA HARI TERSEBUT*/
    /*sedangbuild=false;*/
    tele=0;
    ctmember=0;
    member=false;
    printf("<<< NEW DAY, NEW HOPE , NEW SPIRIT >>>\n");
}
void MAP(){
    /*MENYIMPAN KARAKTER YANG INGIN DITEMPATI PLAYER.*/
    /*CTH: PEMAIN INGIN KE SHOP, MAKA KARAKTER 'S' AKAN DISIMPAN*/
    char sebelum;
    int i=Absis(P),j=Ordinat(P);
    sebelum=m.Mem[j][i];
    /*PENGISIAN TITIK TUJUAN DENGAN POSISI PEMAIN*/
    IsiMARTRIKS(&m,j,i,'P');
    /*MENAMPILKAN PETA PEMAIN*/
    TulisMATRIKS(m);
    printf("\n");
    /*PENGISIAN KEMBALI TITIK P DENGAN KARAKTER PADA TEMPAT ITU SEBELUMNYA*/
    IsiMARTRIKS(&m,j,i,sebelum);
}
void EXIT(){
    /*MELAKUKAN EXIT PROGRAM*/
    masihlanjut=false;
}
/*FUNGSI-FUNGSI TAMBAHAN*/
void REMAINING(){
    /*MENAMPILKAN SISA ORDER PADA HARI TERSEBUT YANG BELUM DIKERJAKAN(ORDER YANG BELUM SELESAI AKAN IKUT TERHITUNG)*/
    printf("Jumlah order yang belum selesai: %d\n",LengthQueue(Q));
    if(LengthQueue(Q)==0){
        printf("Kamu hebat! Silahkan masukkan END_DAY untuk order baru atau EXIT untuk keluar ^_^\n");
    }
    else
    {
        printf("Semangat! Ingat 'Sabar ya, satu per satu'-anak indie pasti tau\n");
    }
}
void TELEPORT(){
    /*MELAKUKAN TELEPORTASI KE SALAH SATU TITIK TUJUAN PEMAIN*/
    /*HANYA BISA DILAKUKAN 1X PER HARI*/
    if(tele==0){
        int pindah;
        boolean gagal=false;
        /*PENAMPILAN DAFTAR TUJUAN PEMAIN*/
        printf("Pilih Lokasi yang anda ingin tuju!\n");
        printf("1. Base\n");
        printf("2. Shop\n");
        printf("3. Pelanggan 1\n");
        printf("4. Pelanggan 2\n");
        printf("5. Pelanggan 3\n");
        printf("6. Pelanggan 4\n");
        printf("7. Pelanggan 5\n");
        printf("8. Pelanggan 6\n");
        printf("9. Pelanggan 7\n");
        printf("Masukkan pilihan anda: ");
        scanf("%d",&pindah);
        /*MELAKUKAN PENGECHECKAN TUJUAN PEMAIN DAN PENGUBAHAN TITIK PEMAIN SESUAI DENGAN INPUT*/
        if(pindah==1){
            Absis(P)=Absis(B);
            Ordinat(P)=Ordinat(B);
        }
        else if(pindah==2){
            Absis(P)=Absis(S);
            Ordinat(P)=Ordinat(S);
        }
        else if(pindah==3){
            Absis(P)=Absis(C1);
            Ordinat(P)=Ordinat(C1); 
        }
        else if(pindah==4){
            Absis(P)=Absis(C2);
            Ordinat(P)=Ordinat(C2);
        }
        else if(pindah==5){
            Absis(P)=Absis(C3);
            Ordinat(P)=Ordinat(C3);
        }
        else if(pindah==6){
            Absis(P)=Absis(C4);
            Ordinat(P)=Ordinat(C4);
        }
        else if(pindah==7){
            Absis(P)=Absis(C5);
            Ordinat(P)=Ordinat(C5);
        }
        else if(pindah==8){
            Absis(P)=Absis(C6);
            Ordinat(P)=Ordinat(C6);
        }
        else if(pindah==9){
            Absis(P)=Absis(C7);
            Ordinat(P)=Ordinat(C7);
        }
        else{
            /*JIKA TERJADI ERROR, TELEPORT AKAN GAGAL*/
            gagal=true;
            printf("Terjadi kesalahan input, silahkan coba lagi\n");
        }
        if(gagal==false){
            /*PENAMPILAN APABILA TELEPORTASI BERHASIL DILAKUKAN*/
            if ((Absis(P)==Absis(B))&&(Ordinat(P)==Ordinat(B))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Base!\n");
            }
            else if ((Absis(P)==Absis(S))&&(Ordinat(P)==Ordinat(S))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Shop!\n"); 
            }
            else if ((Absis(P)==Absis(C1))&&(Ordinat(P)==Ordinat(C1))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 1!\n");
            }
            else if ((Absis(P)==Absis(C2))&&(Ordinat(P)==Ordinat(C2))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 2!\n");
            }
            else if ((Absis(P)==Absis(C3))&&(Ordinat(P)==Ordinat(C3))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 3!\n");
            }
            else if ((Absis(P)==Absis(C4))&&(Ordinat(P)==Ordinat(C4))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 4!\n");
            }
            else if ((Absis(P)==Absis(C5))&&(Ordinat(P)==Ordinat(C5))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 5!\n");
            }
            else if ((Absis(P)==Absis(C6))&&(Ordinat(P)==Ordinat(C6))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 6!\n");
            }
            else if ((Absis(P)==Absis(C7))&&(Ordinat(P)==Ordinat(C7))){
                printf("Selamat! Anda berhasil melakukan teleportasi ke Pelanggan 7!\n");
            }
            else{
                printf("Maaf teleportasi gagal. Coba lagi lain waktu :( \n");
            }
            /*COUNTER MENGHITUNG JUMLAH TELEPORTASI PADA HARI TERSEBUT*/
            tele++;
        }
    }
    else{
        /*BILA PADA HARI ITU SUDAH DILAKUKAN TELEPORT, MAKA AKAN DILAKUKAN ERROR*/
        printf("Maaf, teleportasi hanya bisa digunakan 1x per hari :(\n");
    }
}
void LEGEND(){
    /*MENAMPILKAN DAFTAR COMMAND YANG VALID SERTA PETA DARI PEMAIN SEKARANG*/
    printf("FITUR UTAMA: \n");
    printf("1. MOVE\n");
    printf("2. STATUS\n");
    printf("3. CHECKORDER\n");
    printf("4. STARTBUILD\n");
    printf("5. FINISHBUILD\n");
    printf("6. ADDCOMPONENT\n");
    printf("7. REMOVECOMPONENT\n");
    printf("8. SHOP\n");
    printf("9. DELIVER\n");
    printf("10. END_DAY\n");
    printf("11. MAP\n");
    printf("12. EXIT\n");
    printf("\n");
    printf("FITUR TAMBAHAN: \n");
    printf("13. REMAINING\n");
    printf("14. TELEPORT\n");
    printf("15. LEGEND\n");
    printf("16. CHECKCOMPONENT\n");
    printf("17. DAYMEMBER\n");
    printf("\n");
    printf("PETA SEKARANG\n");
    MAP();
}
void CHECKCOMPONENT(){
    /*MENAMPILKAN DAFTAR KOMPONEN YANG ADA DI STACK TANPA PERLU MELAKUKAN ADDCOMPONENT TERLEBIH DAHULU*/
    int count=0;
    printf("Komponen yang telah terpasang: \n");
    for (int i=0;i<8;i++){
        if ((stemp.T[i].nama!=NULL)&&(stemp.TOP!=-1)){
            printf("%d. %s\n",i+1,stemp.T[i].nama);
            count++;
        }
    }
    if(count==0){
        printf("{Kosong}\n");
    }
}
void DAYMEMBER(){
    /*MEMBUAT PLAYER MENJADI MEMBER PADA HARI TERSEBUT*/
    /*MENJADI MEMBER HARUS DIVALIDASI TERLEBIH DAHULU DENGAN MEMENUHI SYARAT MENGANTARKAN 2 PESANAN PELANGGAN PADA HARI TERSEBUT*/
    if(ctmember>=2){
        member=true;
    }
    if (member==true){
        /*JIKA MENJADI MEMBER, AKAN DITAMPILKAN PESAN BERHASIL*/
        printf("Selamat! Anda sudah menjadi member. Mendapatkan potongan $50 di setiap komponen yang dibeli di Shop.\n");
    }
    else{
        /*JIKA BELUM MEMENUHI 2 PESANAN PADA HARI ITU, LAKUKAN PESAN ERROR*/
        printf("Anda belum menjadi member untuk hari ini. Selesaikan 2 pesanan pelanggan pada hari ini terlebih dahulu\n");
    }
}
/*PROGRAM UTAMA*/
int main(){
    /*PENAMPILAN UTAMA DARI PROGRAM*/
    printf(" ____   __   __ _  ____  __     ____  _  _  ___  __    __   __ _  _   \n");
    printf("/ ___) / _ |(  ( |(_  _)|  |   (_  _)( || )| __)/  |  /  | (  ( || | \n");
    printf("|___ |/    |/    /  )( (  O )    )(   )  /( (__(  O )(  O )/    /|_|  \n");
    printf("(____/|_/|_||_)__) (__) |__|    (__) (__/  |___)|__/  |__| |_)__)(_) \n");
    printf("                     _            __   _____ \n");
    printf("                    | |         /  | |____ |\n");
    printf("                    | | ________`| |     / /\n");
    printf("                    | |/ /______|| |     | |\n");
    printf("                    |   <       _| |_.___/ /\n");
    printf("                    |_||_|      |___/|____/ \n");
    printf("SILAHKAN PILIH & MASUKKAN COMMAND LINE BERIKUT INI\n");
    printf("FITUR UTAMA: \n");
    printf("1. MOVE\n");
    printf("2. STATUS\n");
    printf("3. CHECKORDER\n");
    printf("4. STARTBUILD\n");
    printf("5. FINISHBUILD\n");
    printf("6. ADDCOMPONENT\n");
    printf("7. REMOVECOMPONENT\n");
    printf("8. SHOP\n");
    printf("9. DELIVER\n");
    printf("10. END_DAY\n");
    printf("11. MAP\n");
    printf("12. EXIT\n");
    printf("FITUR TAMBAHAN: \n");
    printf("13. REMAINING\n");
    printf("14. TELEPORT\n");
    printf("15. LEGEND\n");
    printf("16. CHECKCOMPONENT\n");
    printf("17. DAYMEMBER\n");
    /*MELAKUKAN PEMBACAAN DAN SETUP*/
    /*FILE KONFIGURASI SELALU DIANGGAP BERNAMA 'konfigurasi,txt'*/
    SETUP();
    /*SELAMA GAME MASIH BERLANJUT, PEMAIN DIMINTA MELAKUKAN INPUT SECARA TERUS MENERUS SAMPAI MELAKUKAN EXIT*/
    while(masihlanjut==true){
        printf("ENTER COMMAND: ");
        char pilihan[255];
        char move[255]="MOVE";
        char status[255]="STATUS";
        char checkorder[255]="CHECKORDER";
        char startbuild[255]="STARTBUILD";
        char finishbuild[255]="FINISHBUILD";
        char addcomponent[255]="ADDCOMPONENT";
        char removecomponent[255]="REMOVECOMPONENT";
        char shopi[255]="SHOP";
        char deliver[255]="DELIVER";
        char endday[255]="END_DAY";
        char map[255]="MAP";
        char exit[255]="EXIT";
        char remaining[255]="REMAINING";
        char teleport[255]="TELEPORT";
        char legend[255]="LEGEND";
        char checkcomponent[255]="CHECKCOMPONENT";
        char daymember[255]="DAYMEMBER";
        scanf("%s",pilihan);
        if (strcmp(pilihan,move)==0){
            MOVE();
        }
        else if(strcmp(pilihan,status)==0){
            STATUS(Q,L);
        }
        else if(strcmp(pilihan,checkorder)==0){
            CHECKORDER();
        }
        else if(strcmp(pilihan,startbuild)==0){
            STARTBUILD();
        }
        else if(strcmp(pilihan,finishbuild)==0){
            FINISHBUILD(&stemp,Q,&L);
        }
        else if(strcmp(pilihan,addcomponent)==0){
            ADDCOMPONENT();
        }
        else if(strcmp(pilihan,removecomponent)==0){
            REMOVECOMPONENT();
        }
        else if(strcmp(pilihan,shopi)==0){
            SHOP();
        }
        else if(strcmp(pilihan,deliver)==0){
            DELIVER();
        }
         else if(strcmp(pilihan,endday)==0){
            ENDDAY();
        }
        else if(strcmp(pilihan,map)==0){
            MAP();
        }
        else if(strcmp(pilihan,exit)==0){
            EXIT();
        }
        else if(strcmp(pilihan,remaining)==0){
            REMAINING();
        }
        else if(strcmp(pilihan,teleport)==0){
            TELEPORT();
        }
        else if(strcmp(pilihan,legend)==0){
            LEGEND();
        }
        else if(strcmp(pilihan,checkcomponent)==0){
            CHECKCOMPONENT();
        }
        else if(strcmp(pilihan,daymember)==0){
            DAYMEMBER();
        }
        else {
            printf("Command line tidak valid! Silahkan input ulang command line anda!\n");
        }
    }
    if(masihlanjut==false){
        /*BILA GAME SUDAH SELESAI, TAMPILKAN PESAN GAME SUDAH SELESAI*/
        printf(" _   _                 _           __                   _             _             \n");
        printf("| | | |               | |         / _|                 | |           (_)            \n");
        printf("| |_| |__   __ _ _ __ | | _____  | |_ ___  _ __   _ __ | | __ _ _   _ _ _ __   __ _ \n");
        printf("| __| '_ | / _` | '_ || |/ / __| |  _/ _ || '__| | '_ || |/ _` | | | | | '_ | / _` |\n");
        printf("| |_| | | | (_| | | | |   <|__ | | || (_) | |    | |_) | | (_| | |_| | | | | | (_| |\n");
        printf("|__|_| |_||__,_|_| |_|_||_|___/ |_| |___/|_|    | .__/|_||__,_||__, |_|_| |_||__, |\n");
        printf("                                                 | |             __/ |         __/ |\n");
        printf("                                                 |_|            |___/         |___/ \n");
        printf("                                                          _       _                 \n");
        printf("                                                         (_)     | |                \n");
        printf("                ___  ___  ___   _   _    __ _  __ _  __ _ _ _ __ | |                \n");
        printf("               / __|/ _ || _ | | | | |  / _` |/ _` |/ _` | | '_ || |                \n");
        printf("               |__ |  __/  __/ | |_| | | (_| | (_| | (_| | | | | |_|                \n");
        printf("               |___/|___||___|  |__,_|  |__,_||__, ||__,_|_|_| |_(_)                \n");
        printf("                                               __/ |                                \n");
        printf("                                              |___/                                 \n");
    }
    return 0;
}