#include<iostream>
#include "changeLength2D.h"

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


int main(){
    ex5_3();
    return 0;
}