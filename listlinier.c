#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"
/* Definisi ListL : */
/* ListL kosong : First(L) = NULL */
/* Setiap elemen dengan addressListL P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListL : jika addressnya Last, maka Next(Last)=NULL */

// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST ListL KOSONG ******************/
boolean IsListLEmpty (ListL L)
/* Mengirim true jika ListL kosong */
{
    return (First(L) == NULL);
}

/****************** PEMBUATAN ListL KOSONG ******************/
void CreateEmptyListL (ListL *L)
/* I.S. sembarang             */
/* F.S. Terbentuk ListL kosong */
{
    First(*L) = NULL;
}

/****************** Manajemen Memori ******************/
addressListL Alokasi (infotypeListL X)
/* Mengirimkan addressListL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressListL tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
{
    addressListL P;
    P = NULL;
    P = (ElmtListL *) malloc (sizeof(ElmtListL));
    if (P != NULL) {
        Info(P) = X;
        Next(P) = NULL;
    }
    return P;
}
void Dealokasi (addressListL *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressListL P */
{
    free(*P);
    *P = NULL;
}

/****************** PENCARIAN SEBUAH ELEMEN ListL ******************/
addressListL Search (ListL L, infotypeListL X)
/* Mencari apakah ada elemen ListL dengan Info(P)= X */
/* Jika ada, mengirimkan addressListL elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */
{
    addressListL P = First(L);
    boolean found = false;
    while (P != NULL && !found) {
        if (Info(P) == X) found = true;
        else P = Next(P);
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListL *L, infotypeListL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    addressListL P;
    if (IsListLEmpty(*L)) {
        First(*L) = Alokasi(X);
    } else {
        P = Alokasi(X);
        if (P != NULL) {
            Next(P) = First(*L);
            First(*L) = P;
        }
    }
}
void InsVLast (ListL *L, infotypeListL X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListL di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    addressListL P, c;
    if (IsListLEmpty(*L)) {
        First(*L) = Alokasi(X);
    } else {
        P = First(*L);
        while (Next(P) != NULL){
            P = Next(P);            
        }
        // kalo udah nemu yang nil
        c = Alokasi(X);
        Next(P) = c;
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListL *L, infotypeListL *X)
/* I.S. ListL L tidak kosong  */
/* F.S. Elemen pertama ListL dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    addressListL P = First(*L);
    *X = Info(First(*L));
    First(*L) = Next(First(*L));
    Dealokasi(&P);
}

void DelVLast (ListL *L, infotypeListL *X)
/* I.S. ListL tidak kosong */
/* F.S. Elemen terakhir ListL dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    addressListL P;
    DelLast(L, &P);
    *X = Info(P);
    Dealokasi(&P);
}

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstL (ListL *L, addressListL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressListL P sebagai elemen pertama */
{
    if (IsListLEmpty(*L)) {
        First(*L) = P;
        Next(First(*L)) = NULL;
    } else {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
void InsertAfter (ListL *L, addressListL P, addressListL Prec)
/* I.S. Prec pastilah elemen ListL dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    addressListL c = First(*L);
    while (c != Prec) {
        c = Next(c);
    }
    // c = Prec
    Next(P) = Next(c);
    Next(c) = P;
}
void InsertLastL (ListL *L, addressListL P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{   
    addressListL c = First(*L);
    if (c == NULL) {
        First(*L) = P;
        Next(First(*L)) = NULL;
    } else {
        while (Next(c) != NULL) {
            c = Next(c);
        }
        Next(c) = P;
        Next(P) = NULL;
    }
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListL *L, addressListL *P)
/* I.S. ListL tidak kosong */
/* F.S. P adalah alamat elemen pertama ListL sebelum penghapusan */
/*      Elemen ListL berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    First(*L) = Next(First(*L));
}
void DelP (ListL *L, infotypeListL X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListL beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari ListL dan di-dealokasi */
/* Jika ada lebih dari satu elemen ListL dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen ListL dengan Info(P)=X, maka ListL tetap */
/* ListL mungkin menjadi kosong karena penghapusan */
{
    addressListL N;
    addressListL P = First(*L);
    boolean found = false;
    while (P != NULL && !found) {
        if (Info(P) == X) found = true;
        else P = Next(P);
    }
    if (found) {
        if (P == First(*L)) {
            First(*L) = Next(First(*L));
        } else {
            N = First(*L);
            while (Next(N) != P) {
                N = Next(N);
            }
            Next(N) = Next(P);
        }
        Dealokasi(&P);
    }
}
void DelLast (ListL *L, addressListL *P)
/* I.S. ListL tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListL sebelum penghapusan  */
/*      Elemen ListL berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
{
    addressListL c = First(*L);
    addressListL last = First(*L);
    while (Next(c) != NULL) {
        c = Next(c);
    }
    *P = c;
    if (c == First(*L)) {
        First(*L) = NULL;
    } else {
        while (Next(last) != c)
        {
            last = Next(last);
        }
        Next(last) = NULL;
    }
}
void DelAfter (ListL *L, addressListL *Pdel, addressListL Prec)
/* I.S. ListL tidak kosong. Prec adalah anggota ListL  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListL yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
}

/****************** PROSES SEMUA ELEMEN ListL ******************/
void PrintInfo (ListL L)
/* I.S. ListL mungkin kosong */
/* F.S. Jika ListL tidak kosong, iai ListL dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListL kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    addressListL P = First(L);
    printf("[");
    if (!IsListLEmpty(L)) {
        printf("%d", Info(P));
        P = Next(P);
        while (P != NULL) {
            printf(",%d", Info(P));
            P = Next(P);
        }
    }
    printf("]");
}
int NbElmtL (ListL L)
/* Mengirimkan banyaknya elemen ListL; mengirimkan 0 jika ListL kosong */
{
    int count = 0;
    addressListL P = First(L);
    if (!IsListLEmpty(L)) {
        while (P != NULL) {
            count++;
            P = Next(P);
        }
    }
    return count;
}

/****************** PROSES TERHADAP ListL ******************/
void Konkat1 (ListL *L1, ListL *L2, ListL *L3)
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah ListL : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen ListL L1 dan L2) */
/* dan L1 serta L2 menjadi ListL kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */
{
    addressListL P = First(*L1);
    if (P == NULL) {
        First(*L3) = First(*L2);
    } else {
        while (Next(P) != NULL) {
            P = Next(P);
        }
        First(*L3) = First(*L1);
        Next(P) = First(*L2);
    }
    First(*L1) = NULL;
    First(*L2) = NULL;
}
