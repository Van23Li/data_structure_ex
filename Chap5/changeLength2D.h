# ifndef changeLength2D_
# define changeLength2D_

#include "myExceptions.h"

using namespace std;


template <class T>
void changeLength2D(T **& a, int oldRows, int newRows, int oldColumns, int newColumns){
    if (newRows < 0 || newColumns < 0)
        throw illegalParameterValue("new dimensions are too small");

    T** temp = new T * [newRows];
    for (int i = 0; i < newColumns; i++)
        temp [i] = new T [newColumns];

    int copyRows = min (newRows, oldRows);
    int copyColumns = min (newColumns, oldColumns);

    for (int i = 0; i < copyRows; i++){
        copy(a[i], a[i] + copyColumns, temp[i]);
        delete [] a[i];
    }

    for (int i = copyRows; i < oldRows; i++)
        delete [] a[i];
    delete [] a;
    a = temp;
}



# endif