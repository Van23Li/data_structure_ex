# ifndef changeLength1D_
# define changeLength1D_

#include "myExceptions.h"

using namespace std;

template <class T>
void changeLength1D(T *& a, int oldlength, int newlength){
    if (newlength < 0)
        throw illegalParameterValue("new length must be >= 0");

    T * temp = new T[newlength];
    int number = min (newlength, oldlength);
    copy(a, a + number, temp);
    delete [] a;
    a = temp;
}

# endif