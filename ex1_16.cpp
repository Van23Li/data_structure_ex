# include <iostream>
# include "currency.h"

using namespace std;

int main(){
   currency g, h(Plus, 3, 50);

    g.input();
    cout << "the value is set as: ";
    g.output(); cout << endl;

    g.output();
    cout << " - ";
    h.output();
    cout << "=";
    g.subtract(h).output(); cout << endl;

    g.output();
    cout << " * 10% = ";
    g.percent(10).output(); cout << endl;

   g.output();
   cout << " * 10 = ";
   g.multiply(10).output(); cout << endl;
   return 0;
}