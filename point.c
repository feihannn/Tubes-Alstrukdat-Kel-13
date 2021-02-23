/* File: Point.c */
/* Nama	: Anastasia Beatrice Caroline */
/* NIM	: 18219081 */
/* Tanggal: 17 September 2020 */

#include <stdio.h>
#include "point.h"
#include <math.h>

Point MakePoint(int X, int Y)
{
    Point P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void TulisPoint(Point P)
{
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

boolean EQ(Point P1, Point P2)
{
    return ((Absis(P1) == Absis(P2)) && ((Ordinat(P1) == (Ordinat(P2)))));
}

boolean NEQ(Point P1, Point P2)
{
    return ((Absis(P1) != Absis(P2)) || ((Ordinat(P1) != (Ordinat(P2)))));
}

boolean IsOrigin(Point P)
{
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX(Point P)
{
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(Point P)
{
    return (Absis(P) == 0);
}

int Kuadran(Point P)
{
    if ((Absis(P) > 0) && (Ordinat(P) > 0))
        return 1;
    else
    {
        if ((Absis(P) > 0) && (Ordinat(P) < 0))
            return 4;
        else
        {
            if (((Absis(P) < 0) && (Ordinat(P) > 0)))
                return 2;
            else
            {
                return 3;
            }
        }
    }
}

Point PlusDelta(Point P, int deltaX, int deltaY)
{
    Point q = MakePoint((Absis(P) + deltaX), (Ordinat(P) + deltaY));
    return q;
}

void Geser(Point *P, int deltaX, int deltaY)
{
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}

