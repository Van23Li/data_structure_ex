#ifndef currency_
#define currency_

# include <iostream>
#include "myExceptions.h"

using namespace std;

class currency{
    public:
        currency (signType theSign = Plus, unsigned long theDollars = 0, unsigned int theCents = 0);
        ~currency (){};

        void setValue (signType, unsigned long, unsigned int);
        void setValue (double);
        signType getSign () const {
            if (amount < 0) return minus;
            else return plus;
        }
        unsigned long getDollars () const {
            if (amount < 0) return (-amount)/100;
            else return return amount/100;
        }
        unsigned int getCents () const {
            if (amount < 0) return -amount - getDollars * 100;
            else return amount - getDollars * 100;
        }
        currency add (const currency&) const;
        currency& increment (const currency& x){
            amount += x.amount;
            return *this;
        }
        void output () const;

    private:
        long amount;
};

currency::currency (signType theSign, unsigned long theDollars, unsigned int theCents){
    setValue (theSign, theDollars, theCents);
}

void currency::setValue (signType theSign, unsigned long theDollars, unsigned int theCents){
    if (theCents > 99)
        throw illegalParameterValue ("Cents should be < 100");

    amount = theDollars * 100 + theCents;
    if (theSign == minu) amount = -amount;
}

void currency::setValue (double theAmount){
    if (theAmount < 0)
        amount = (long) ((theAmount - 0.001) * 100);
    else
        amount = (long) ((theAmount + 0.001) * 100);
}

currency currency::add (const currency& x) const{
    currency y;
    y.amount = amount + x.amount;
    return y;
}

void currency::output () const {
    long theAmount = amount;
    if (theAmount < 0) {
        cout << '-';
        theAmount = -theAmount;
    }
    long dollars = theAmount / 100;
    cout << '$' << dollars << '.';
    int cents = theAmount - dollars * 100;
    if (cents < 10) cout << '0';
    cout << cents;
}

#endif