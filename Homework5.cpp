#include <stdlib.h>
#include <iostream>
#include "CResizableArray.h"
using namespace std;

int main()
{
    CResizableArray clsArray;
    cout << "SetSize 3" << endl;
    clsArray.SetSize(3);
    cout << "Initialize and then print";
    clsArray.Initialize();
    clsArray.Print();
    
    cout << " SetValueAt(1, -1) and then print" << endl;
    clsArray.SetValueAt(1, -1);
    clsArray.Print();

    cout << "SetSize 5 and then print" << endl;
    clsArray.SetSize(5);
    clsArray.Print();

    cout << "GetSize: " << clsArray.GetSize() << endl;

    cout << "GetValueAt index -1 : " << clsArray.GetValueAt(-1) << endl;

  //  clsArray.SetSize(5);
  //  clsArray.Print();
    cout << "AddValueToFront(5)  and then print " << endl;
    clsArray.AddValueToFront(5);
    clsArray.Print();

    cout << "AddValueToEnd(6)  and then print " << endl;
    clsArray.AddValueToEnd(6);
    clsArray.Print();

    cout << "InsertValueAt(7, 2) and then print " << endl;
    clsArray.InsertValueAt(7, 2);
    clsArray.Print();

    cout << "RemoveAt(2) and then print " << endl;
    clsArray.RemoveAt(2);
    clsArray.Print();

    

return 1;
}