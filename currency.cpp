# include <iostream>
# include "currency.h"

using namespace std;

int main(){
   currency g, h(Plus, 3, 50), i, j;

    g.setValue(Minus, 2, 25);
    i.setValue(-6.45);

    j = h.add(g);
    h.output();
    cout << " + ";
    g.output();
    cout << " = ";
    j.output();
    cout << endl;

   j = i.add(g).add(h);
   i.output();
   cout << " + ";
   g.output();
   cout << " + ";
   h.output();
   cout << " = ";
   j.output(); cout << endl;

   cout << "Increment ";
   i.output();
   cout << " by ";
   g.output();
   cout << " and then add ";
   h.output();
   cout << endl << "Result is ";
   j = i.increment(g).add(h);
   j.output(); cout << endl;
   cout << "Incremented object is ";
   i.output(); cout << endl;

   cout << "Attempting to initialize with cents = 152" << endl;
   try {i.setValue(Plus, 3, 152);}
   catch (illegalParameterValue e)
   {
       cout << "Caught thrown exception" << endl;
       e.outputMessage();
   }
   return 0;
}