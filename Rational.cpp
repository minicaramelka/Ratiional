#include <iostream>
#include "Rational.h"

using namespace std;

Rat::Rat(long long int ch, long long int zn)
{
    setRat(ch, zn);
}

void Rat::setRat(long long int ch, long long int zn)
{
    int nod;
    if (ch >= zn)
        nod = nodRat(ch, zn);
    else
        nod = nodRat(zn, ch);
    if (!zn)
        cout << "Деление на \"0\" невозможно." << endl;
    else
        if (ch < 0 && zn < 0){
            numer = (ch / nod) * -1;
            denom = (zn / nod) * -1;
        }
        else{
            numer = ch / nod;
            denom = zn / nod;
        }
    
}

long long int Rat::nodRat(long long int x, long long int y)
{
    if ( y == 0 )
        return x;
    else
        return nodRat(y, x % y);
}
 
long long int Rat::nokRat(long long int x, long long int y)
{
    for (int i = 1; i > 0; i++)
        if (i % x == 0 && i % y == 0)
            return i;
    return 1;
}

void Rat::sumRat(Rat x, Rat y)
{
    int nok = nokRat(x.denom, y.denom);
    setRat((x.numer * (nok / x.denom)) + (y.numer * (nok / y.denom)), nok);
}
 
void Rat::diffRat(Rat x, Rat y)
{
    int nok = nokRat(x.denom, y.denom);
    setRat((x.numer * (nok / x.denom)) - (y.numer * (nok / y.denom)), nok);
}
 
void Rat::prodRat(Rat x, Rat y)
{
    setRat(x.numer * y.numer, x.denom * y.denom);
}
 
void Rat::quoRat(Rat x, Rat y)
{
    setRat(x.numer * y.denom, x.denom * y.numer);
}

Rat Rat::operator+(Rat right)
{
    Rat temp = *this;
    temp.sumRat(temp, right);
    return temp;
}
 
Rat Rat::operator-(Rat right)
{
    Rat temp = *this;
    temp.diffRat(temp, right);
    return temp;
}
 
Rat Rat::operator*(Rat right)
{
    Rat temp = *this;
    temp.prodRat(temp, right);
    return temp;
}
 
Rat Rat::operator/(Rat right)
{
    Rat temp = *this;
    temp.quoRat(temp, right);
    return temp;
}
