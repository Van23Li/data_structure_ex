#include<iostream>
#include "changeLength2D.h"
#include "linearList.h"
#include "arrayList.h"

using namespace std;

void ex5_3(){
    int m=3,n=2;
	int**a=new int*[m];
	for(int i=0;i<m;i++){
	   a[i]=new int[n];
   }
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			a[i][j]=j;

    changeLength2D(a, 3, 4, 4, 6 );
    int aaa=2;
}

void ex5_7(){
    arrayList<int> y(2);
    y.insert(0, 2);
    y.insert(1, 6);
    int z = y[1];
    cout << "y = "
            << y << endl;
    cout << "z= "
            << z << endl;
}

void ex5_8_9(){
    arrayList<int> y(2), z(2);
    y.insert(0, 2);
    y.insert(1, 6);
    z.insert(0, 2);
    z.insert(1, 6);
    if (y != z){
        cout << "y != z" << endl;
    }
    else{
        cout << "y == z" << endl;
    }
    if (y == z){
        cout << "y == z" << endl;
    }
    else{
        cout << "y != z" << endl;
    }
}

void ex5_13(){
    arrayList<int> y(2), z(3);
    y.insert(0, 1);
    y.insert(1, 2);
    z.insert(0, 3);
    z.insert(1, 4);
    z.insert(2, 5);
    y.swapl(z);

    cout << "y = "
            << y << endl;
    cout << "z= "
            << z << endl;

}

void ex5_15(){
    arrayList<int> y(2);
    y.insert(0, 1);
    y.insert(1, 2);
    cout << "old y = "
            << y << endl;
    y.set(1,3);
    cout << "new y = "
            << y << endl;
}

void ex5_17(){
    arrayList<int> y(6);
    y.insert(0, 1);
    y.insert(1, 2);
    y.insert(1, 12);
    y.insert(1, 3);
    y.insert(1, 4);
    y.insert(1, 5);
    cout << "old y = "
            << y << endl;
    y.removeRange(2,5);
    cout << "new y = "
            << y << endl;

}

int main(){
    // ex5_3();
    // ex5_7();
    // ex5_8_9();
    // ex5_13();
    // ex5_15();
    ex5_17();
    return 0;
}