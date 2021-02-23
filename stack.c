#include<stdio.h>
#include<string.h>
#include "stack.h"

void CreateEmptyStack(Stack *S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
    S->TOP = NilStack;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong*/
/* Ciri stack kosong : TOP bernilai Nil */
{
    return S.TOP == NilStack;
}

boolean IsFullStack(Stack S)
/* Mengirim true jika stack S penuh */
/* Ciri stack penuh : TOP bernilai MaxEl */
{
    return S.TOP == MaxEl;
}
/* ********** Operator Dasar Stack ********* */
void Push(Stack *S, char *name, char *category)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, S tidak penuh */
/*F.S. X menjadi element TOP yang baru, TOP bertambah 1 */
{
    S->TOP++;
    Kategori(*S)=category;
    Nama(*S)=name; 
}
void Pop(Stack *S, infostack *X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X).kategori=Kategori(*S);
    (*X).nama=Nama(*S);
    (*S).T[S->TOP].nama=NULL;
    (*S).T[S->TOP].kategori=NULL;
    S->TOP--;
}
void copystack(Stack *S,Stack *S1){
    
    for (int i=0;i<=TOP(*S);i++){
        (*S1).T[i].nama=(*S).T[i].nama;
        (*S1).T[i].kategori=(*S).T[i].kategori;
    }
    (*S1).TOP=(*S).TOP;
}