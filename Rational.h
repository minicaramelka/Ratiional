#include <iostream>

class Rat{
    public:
        Rat() {};
        Rat(long long int ch, long long int zn);
        ~Rat() {};
        void setRat(long long int, long long int);
        void sumRat(Rat, Rat);
        void diffRat(Rat, Rat);
        void prodRat(Rat, Rat);
        void quoRat(Rat, Rat);
        Rat operator+ (Rat);
        Rat operator- (Rat);
        Rat operator* (Rat);
        Rat operator/ (Rat);
        long long int nodRat(long long int, long long int);
        long long int nokRat(long long int, long long int);
        long long int numer;
        long long int denom;
};
