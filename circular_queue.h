/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) */

#ifndef __circular_queue_h__
#define __circular_queue_h__

#include "boolean.h"
#include "stack.h"

/* Nilai untuk indeks yang tidak terdefinisi */
#define NIL -1
/* Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */
typedef struct {
    int nomor;
    int pelanggan;
    int biaya;
    Stack orderstack;
} Elemen;
/*Definisi Queue kosong: HEAD = Nil; TAIL = Nil */

typedef struct {
    Elemen *T; /* tabel penyimpanan elemen */
    address HEAD; /* alamat penghapusan */
    address TAIL; /* alamat penambahan */
    int Max;/* Max elemen queue */
} Queue;

/* Q.T[Q.HEAD].nomor*/

/*********** AKSES (Selektor) **********/
/* Jika Q adalah Queue, maka akses elemen : */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoNomorHead(Q) (Q).T[(Q).HEAD].nomor
#define InfoPelangganHead(Q) (Q).T[(Q).HEAD].pelanggan
#define InfoBiayaHead(Q) (Q).T[(Q).HEAD].biaya
#define InfoStackHead(Q) (Q).T[(Q).HEAD].orderstack
#define InfoNomorTail(Q) (Q).T[(Q).TAIL].nomor
#define InfoPelangganTail(Q) (Q).T[(Q).TAIL].pelanggan
#define InfoBiayaTail(Q) (Q).T[(Q).TAIL].biaya
#define InfoStackTail(Q) (Q).T[(Q).TAIL].orderstack
#define Max(Q) (Q).Max

/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQueue(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int LengthQueue(Queue Q);
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLengthQueue(Queue Q);
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue(int Max);
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Primitif Add/Delete *** */
void PushQueue(Queue *Q, int no, int customer, int pay, Stack *S);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
void PopQueue(Queue *Q);
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
/* *** Utilitas *** */
Queue CopyQueue(Queue Q);
/* Proses: Mengembalikan Queue baru dengan isi antrean sama seperti Q */
/* I.S. Q pernah dialokasi */
/* F.S. Queue baru dengan nilai isi antrean sama seperti Q;
        HEAD pada Queue baru dimulai dari 0 */

#endif