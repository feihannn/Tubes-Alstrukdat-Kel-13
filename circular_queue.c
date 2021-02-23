#include <stdlib.h>
#include<stdio.h>
#include "circular_queue.h"
#include"stack.h"

/* ********* Prototype ********* */
boolean IsEmptyQueue(Queue Q)
{
    return Q.HEAD == NIL && Q.TAIL == NIL;
}
boolean IsFullQueue(Queue Q)
{
    return LengthQueue(Q) == Q.Max;
}
int LengthQueue(Queue Q)
{
    if (IsEmptyQueue(Q))
        return 0;
    else if (Q.HEAD > Q.TAIL)
        return 1+ Q.Max + Q.TAIL - Q.HEAD;
    else
        return 1+Q.TAIL - Q.HEAD;
}
int MaxLengthQueue(Queue Q)
{
    return Q.Max;
}

/* *** Kreator *** */
Queue CreateQueue(int Max)
{
    Queue Q;
    Q.T = (Elemen *)malloc(Max * sizeof(Elemen));
    Q.HEAD = NIL;
    Q.TAIL = NIL;
    Q.Max = Max;
    return Q;
}
/* *** Primitif Add/Delete *** */
void PushQueue(Queue *Q, int no, int customer, int pay, Stack *S)
{
    if (IsEmptyQueue(*Q))
    {
        Q->HEAD = 0;
        Q->TAIL = 0;
    }
    else{
        Q->TAIL++;
        if (Q->TAIL == Q->Max){
            Q->TAIL = 0;
        }
    }
    (*Q).T[Q->TAIL].nomor = no;
    (*Q).T[Q->TAIL].pelanggan= customer;
    (*Q).T[Q->TAIL].biaya = pay;
    (*Q).T[Q->TAIL].orderstack=(*S);

   
   
}
void PopQueue(Queue *Q)
{
    if (Q->HEAD == Q->TAIL)
    {
        Q->HEAD = NIL;
        Q->TAIL = NIL;
    }
    else{
         Q->HEAD++;
        if (Q->HEAD == Q->Max)
        {
            Q->HEAD = 0;
        }
    }
}
/* *** Utilitas *** */
Queue CopyQueue(Queue Q)
{
    Queue new = CreateQueue(Q.Max);
    if (!IsEmptyQueue(Q))
    {
        int tail = Q.HEAD;
        while (LengthQueue(new) != LengthQueue(Q))
        {
            PushQueue(&new, Q.T[tail].nomor,Q.T[tail].pelanggan,Q.T[tail].biaya,&Q.T[tail].orderstack);
            tail = (tail + 1) % Q.Max;
        }
    }
    return new;
}