// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 2
// Abstract: Homework 7
// --------------------------------------------------------------------------------

//Step 3 – A Mystery - Test 1 and Test 2 in this case seem to produce same results even though
// difference of pass by Ref vs value

#include <stdlib.h>
#include <iostream>
#include "CResizableArray.h"
using namespace std;

//void Test1(CResizableArray& clsValues);		// By Reference
//void Test2(CResizableArray clsValues);		// By Value
// --------------------------------------------------------------------------------
// Name: Test1
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void Test1(CResizableArray& clsValues)
{
    printf("Test 1 ------------------------------\n");
    clsValues.Print();
}


// --------------------------------------------------------------------------------
// Name: Test2
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void Test2(CResizableArray clsValues)
{
    printf("Test 2 ------------------------------\n");
    clsValues.Print();
}


int main()
{
    // step 1 starts here
     
    CResizableArray clsArray;
    clsArray.Print();
    CResizableArray clsArray1(2,2);
    clsArray1.Print();
    
    cout << "SetSize 3" << endl;
    clsArray.SetSize(3);
    cout << "Initialize and then print";
   // clsArray.Initialize();
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

    
    
    //step 2 starts here
    CResizableArray clsValues;

    // Create the array
    clsValues.SetSize(4);

    // Populate Array (value, index)
    clsValues.SetValueAt(2, 0);
    clsValues.SetValueAt(4, 1);
    clsValues.SetValueAt(6, 2);
    clsValues.SetValueAt(8, 3);

    // Test 1
    Test1(clsValues);
    printf("After Test 1 ------------------------------\n");
    clsValues.Print();

    // Test 2
    Test2(clsValues);
    printf("After Test 2 ------------------------------\n");
    clsValues.Print();



return 1;
}