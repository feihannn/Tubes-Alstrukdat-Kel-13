/* File : ListLlinier.h */
/* contoh ADT ListL berkait dengan representasi fisik pointer  */
/* Representasi addressListL dengan pointer */
/* infotypeListL adalah integer */

#ifndef ListL_H
#define ListL_H

#include "boolean.h"

typedef int infotypeListL;
typedef struct tElmtListL *addressListL;
typedef struct tElmtListL {
	infotypeListL info;
	addressListL next;
} ElmtListL;
typedef struct {
	addressListL First;
} ListL;

/* Definisi ListL : */
/* ListL kosong : First(L) = Nil */
/* Setiap elemen dengan addressListL P dapat diacu Info(P), Next(P) */
/* Elemen terakhir ListL : jika addressnya Last, maka Next(Last)=Nil */

#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST ListL KOSONG ******************/
boolean IsListLEmpty (ListL L);
/* Mengirim true jika ListL kosong */

/****************** PEMBUATAN ListL KOSONG ******************/
void CreateEmptyListL (ListL *L);
/* I.S. sembarang             */
/* F.S. Terbentuk ListL kosong */

/****************** Manajemen Memori ******************/
addressListL Alokasi (infotypeListL X);
/* Mengirimkan addressListL hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addressListL tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressListL *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addressListL P */

/****************** PENCARIAN SEBUAH ELEMEN ListL ******************/
addressListL Search (ListL L, infotypeListL X);
/* Mencari apakah ada elemen ListL dengan Info(P)= X */
/* Jika ada, mengirimkan addressListL elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (ListL *L, infotypeListL X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (ListL *L, infotypeListL X);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListL di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (ListL *L, infotypeListL *X);
/* I.S. ListL L tidak kosong  */
/* F.S. Elemen pertama ListL dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (ListL *L, infotypeListL *X);
/* I.S. ListL tidak kosong */
/* F.S. Elemen terakhir ListL dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirstL (ListL *L, addressListL P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-addressListL P sebagai elemen pertama */
void InsertAfter (ListL *L, addressListL P, addressListL Prec);
/* I.S. Prec pastilah elemen ListL dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLastL (ListL *L, addressListL P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (ListL *L, addressListL *P);
/* I.S. ListL tidak kosong */
/* F.S. P adalah alamat elemen pertama ListL sebelum penghapusan */
/*      Elemen ListL berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (ListL *L, infotypeListL X);
/* I.S. Sembarang */
/* F.S. Jika ada elemen ListL beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari ListL dan di-dealokasi */
/* Jika ada lebih dari satu elemen ListL dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen ListL dengan Info(P)=X, maka ListL tetap */
/* ListL mungkin menjadi kosong karena penghapusan */
void DelLast (ListL *L, addressListL *P);
/* I.S. ListL tidak kosong */
/* F.S. P adalah alamat elemen terakhir ListL sebelum penghapusan  */
/*      Elemen ListL berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (ListL *L, addressListL *Pdel, addressListL Prec);
/* I.S. ListL tidak kosong. Prec adalah anggota ListL  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen ListL yang dihapus  */

/****************** PROSES SEMUA ELEMEN ListL ******************/
void PrintInfo (ListL L);
/* I.S. ListL mungkin kosong */
/* F.S. Jika ListL tidak kosong, iai ListL dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika ListL kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmtL (ListL L);
/* Mengirimkan banyaknya elemen ListL; mengirimkan 0 jika ListL kosong */

/****************** PROSES TERHADAP ListL ******************/
void Konkat1 (ListL *L1, ListL *L2, ListL *L3);
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah ListL : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen ListL L1 dan L2) */
/* dan L1 serta L2 menjadi ListL kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */

#endif