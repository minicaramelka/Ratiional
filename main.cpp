#include <iostream>
#include <cmath>
#include "Rational.h"

using namespace std;

Rat PiRat(int n){          
    if (((2 * n + 1) * pow(3, n)) < pow(10, 5)){                  
        return((Rat(pow(-1, n), (2 * n + 1) * pow(3, n)) + PiRat(n + 1)));     
    }     
    else return Rat(0,1); 
}

int main()
{
    Rat a(5,7);
    Rat b(6,3);
    long long int koren = sqrt(12)*10000;
    Rat pi(koren, 10000);
    Rat c;
    c = PiRat(0)*pi;
    Rat sum, diff, prod, quo;
    sum = a + b;
    diff = a - b;
    prod = a * b;
    quo = a / b;
    cout << "a = (" << a.numer << ", " << a.denom << ")" << endl;
    cout << "b = (" << b.numer << ", " << b.denom << ")" << endl;
    cout << "sum = (" << sum.numer << ", " << sum.denom << ")" << endl;
    cout << "diff = (" << diff.numer << ", " << diff.denom << ")" << endl;
    cout << "prod = (" << prod.numer << ", " << prod.denom << ")" << endl;
    cout << "quo = (" << quo.numer << ", " << quo.denom << ")" << endl;
    cout << "c = (" << c.numer << ", " << c.denom << ")" << endl;
    cout << "Pi = " << float(c.numer)/c.denom;
    return 0;
}
