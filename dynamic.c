#include "dynamic.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk List kosong dengan ukuran InitialSize
 */
List MakeList() {
    List list;
    list.A = (ElType *) malloc(InitialSize * sizeof(ElType));
    list.Capacity = InitialSize;
    list.Neff = 0;
    return list;
}

void DeallocateList(List *list) {
    free(list->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu list kosong.
 * Prekondisi: list terdefinisi
 */
boolean IsEmptyDynamic(List list) {
    return list.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif list, 0 jika tabel kosong.
 * Prekondisi: list terdefinisi
 */
int Length(List list) {
    return list.Neff;
}

/**
 * Mengembalikan elemen list L yang ke-I (indeks lojik).
 * Prekondisi: list tidak kosong, i di antara 0..Length(list).
 */
ElType Get(List list, IdxType i) {
    return list.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: list terdefinisi
 */
int GetCapacity(List list) {
    return list.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: list terdefinisi, i di antara 0..Length(list).
 */
void InsertAt(List *list, int no, char *kat,char *brg,int jumlah, IdxType i) {
    int length = Length(*list);
    int capacity = GetCapacity(*list);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        ElType *array = (ElType *) malloc(desiredCapacity * sizeof(ElType));
        for (int a = 0; a < length; a++) {
            array[a] = Get(*list, a);
        }
        free(list->A);
        
        list->A = array;
        list->Capacity = desiredCapacity;
    }
    if (length>1){
        for (int a = length - 1; a >= i; a--) {
            list->A[a + 1] = list->A[a];
        }
    }
    

    list->A[i].nomor= no;
    list->A[i].kategori=kat;
    list->A[i].barang=brg;
    list->A[i].kuantitas= jumlah;
    list->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir list.
 * Prekondisi: list terdefinisi
 */
void InsertLast(List *list, int no, char *kat,char *brg,int jumlah) {
    int insertAt = Length(*list);
    InsertAt(list, no,kat,brg,jumlah, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal list.
 * Prekondisi: list terdefinisi
 */
void InsertFirst(List *list, int no, char *kat,char *brg,int jumlah) {
    InsertAt(list, no,kat,brg,jumlah, 0);
}
void DeleteElemen(List *list,int a){
    if (!IsEmptyDynamic(*list)){
        if (((*list).Neff==1)&&(a==0)){
            (*list)=MakeList();
        }
        else if(a==Length(*list)-1){
            (*list).A[a].nomor=-999;
            (*list).A[a].kategori=NULL;
            (*list).A[a].barang=NULL;
            (*list).A[a].kuantitas=-999;
            (*list).Neff--;
        }
        else{
            for (int i=a+1;i<Length(*list);i++){
                (*list).A[i-1].nomor=(*list).A[i].nomor;
                (*list).A[i-1].kategori=(*list).A[i].kategori;
                (*list).A[i-1].barang=(*list).A[i].barang;
                (*list).A[i-1].kuantitas=(*list).A[i].kuantitas;
            }
            (*list).Neff--;
        }
        
    }
}