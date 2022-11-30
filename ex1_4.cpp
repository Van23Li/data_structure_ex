#include <iostream>
#include <vector>

using namespace std;

template <class T>
void make2dArray(T ** &x, int numberOfRows, vector <int> rowSize){
    x = new T * [numberOfRows];
      
   for (int i = 0; i < numberOfRows; i++)
      x[i] = new T [rowSize[i]];
}

template <class T>
void changeLength1D(T * &x,  int oldLength, int newLength){
    T *temp = new T [newLength];
    // int oldLength = oldArray.size();
    int number = min(oldLength, newLength);
    copy(x, x + number, temp);
    x = temp;
}

void ex_12(){
   int **a;
   vector <int> rowSize(2);
   rowSize[0] = 2;
   rowSize[1] = 3;

   // make a 2 x 2 array
   make2dArray(a,2,rowSize);

   // assign values to all elements of the array
   a[0][0] = 1; a[0][1] = 2; a[1][0] = 3; a[1][1] = 4; a[1][2] = 5;

   // output assigned values
   cout << a[0][0] << ' ' << a[0][1] << endl;
   cout << a[1][0] << ' ' << a[1][1] << ' ' << a[1][2]  << endl;
}

void ex_13(){
   int *oldArray;
   oldArray = new int [3];
   oldArray[0] = 1;
   oldArray[1] = 2;
   oldArray[3] = 3;

    // cout << "ads" << oldArray[2] << "\n";
   changeLength1D(oldArray, 3, 2);
   cout << oldArray[0] << ' ' << oldArray[1] << ' ' << oldArray[2] << endl;
}

int main(){
    // ex_12();
    ex_13();
}