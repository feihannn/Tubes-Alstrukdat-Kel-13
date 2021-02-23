#include <stdio.h>
#include "matriks.h"
#include "boolean.h"

void MakeMATRIKS (int NB, int NK, MATRIKS * M){
    M->NBrsEff = NB+2;
    M->NKolEff = NK+2;
    
    int i,j;
    for (i = 0; i < NB+2; i++){
        for (j = 0; j < NK+2; j++){
            if(i==0||i==NB+1){
                M->Mem[i][j]=(char)'*';
            }
            else if(j==0||j==NK+1){
                M->Mem[i][j]=(char)'*';
            }
            else{
                M->Mem[i][j]=(char)' ';
            }
        }
    }
}

boolean IsIdxValid (int i, int j){
    return (i >= BrsMin && i <= BrsMax && j >= KolMin && j <= KolMax);
}

indeks GetFirstIdxBrs (MATRIKS M){
    return BrsMin;
}

indeks GetFirstIdxKol (MATRIKS M){
    return KolMin;
}

indeks GetLastIdxBrs (MATRIKS M){
    return M.NBrsEff-1;
}

indeks GetLastIdxKol (MATRIKS M){
    return M.NKolEff-1;
}

boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
    return (i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M) && j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M));
}

void BacaMATRIKS (MATRIKS * M, int NB, int NK){
    MakeMATRIKS(NB, NK, M);

    int i,j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++){
            scanf("%s", &(M->Mem[i][j]));
        }
    }
}

void TulisMATRIKS (MATRIKS M){
    int i,j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++){
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++){
            printf("%c",M.Mem[i][j]);
        }
        printf("\n");
    }
}
void IsiMARTRIKS(MATRIKS *M, indeks i, indeks j,char x){
/*Mengisi M[i][j] dengan char X*/
    (*M).Mem[i][j]=x;
}
                              