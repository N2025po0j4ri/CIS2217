// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 
// Assignment: Resizeable Arrays with deep copy
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#include "CResizableArray.h"
#include "CStack.h"
#include "CQueue.h"

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// User Defined Types
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Prototypes
// --------------------------------------------------------------------------------
void Test1( CResizableArray<long> &clsValues );		// By Reference
void Test2( CResizableArray<long> clsValues );		// By Value
void longTemplateTest();
void charTemplateTest();
void doubleTemplateTest();
void StackTests1(CStack<int>& clsOriginal);
void StackTests2(CStack<int> clsCopy);
void StackTests();
void QueueTests();
void QueueTests1(CQueue<int>& clsOriginal);
void QueueTests2(CQueue<int> clsCopy);
void charQueueTests();
void charQueueTests1(CQueue<char>& clsOriginal);
void charQueueTests2(CQueue<char> clsCopy);
// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts.
// --------------------------------------------------------------------------------
int main()
{   
	charQueueTests();
	//QueueTests(); //tested works
	// StackTests(); //tested works
	//longTemplateTest(); //tested works
	
	//charTemplateTest(); //tested works
	//doubleTemplateTest(); //tested works

	// system( "pause" );  
	return 1;

}
// --------------------------------------------------------------------------------
// Name: doubleTemplateTest
// Abstract:  Step 1 CResizableArray Template test with double
// --------------------------------------------------------------------------------
void doubleTemplateTest() {
	CResizableArray<double> clsValues(0);
	// Self assignment test
	clsValues = clsValues;
	clsValues.Print("After self assignment");

	CResizableArray<double> clsValues2;

	clsValues2 = clsValues;
	clsValues2.Print("After copy");

	clsValues += clsValues;
	clsValues.Print("After append self");

	clsValues += clsValues2;
	clsValues.Print("After append copy");

	CResizableArray<double> clsValues3;

	clsValues3 = clsValues + clsValues2;
	clsValues3.Print("After plus");

	clsValues = clsValues + clsValues2;
	clsValues.Print("After plus to self");
}
// --------------------------------------------------------------------------------
// Name: charTemplateTest
// Abstract:  Step 1 CResizableArray Template test with char
// --------------------------------------------------------------------------------
void charTemplateTest() {
	CResizableArray<char> clsValuesChar(4);

	// Populate Array (value, index)
	clsValuesChar[0] = 'd';
	clsValuesChar[1] = 'c';
	clsValuesChar[2] = 'x';
	clsValuesChar[3] = 'y';

	clsValuesChar.Print();

	// Self assignment test
	clsValuesChar = clsValuesChar;
	clsValuesChar.Print("After self assignment");

	CResizableArray<char> clsValues2;

	clsValues2 = clsValuesChar;
	clsValues2.Print("After copy");

	clsValuesChar += clsValuesChar;
	clsValuesChar.Print("After append self");

	clsValuesChar += clsValues2;
	clsValuesChar.Print("After append copy");

	CResizableArray<char> clsValues3;

	clsValues3 = clsValuesChar + clsValues2;
	clsValues3.Print("After plus");

	clsValuesChar = clsValuesChar + clsValues2;
	clsValuesChar.Print("After plus to self");
}
// --------------------------------------------------------------------------------
// Name: longTemplateTest
// Abstract:  Step 1 CResizableArray Template test with long
// --------------------------------------------------------------------------------
void longTemplateTest() {
	CResizableArray<long> clsValues(4);

	// Populate Array (value, index)
	clsValues[0] = 2;
	clsValues[1] = 4;
	clsValues[2] = 6;
	clsValues[3] = 8;

	clsValues.Print();
	
	// Self assignment test
	clsValues = clsValues;
	clsValues.Print("After self assignment");

	CResizableArray<long> clsValues2;

	clsValues2 = clsValues;
	clsValues2.Print("After copy");

	clsValues += clsValues;
	clsValues.Print("After append self");

	clsValues += clsValues2;
	clsValues.Print("After append copy");

	CResizableArray<long> clsValues3;

	clsValues3 = clsValues + clsValues2;
	clsValues3.Print("After plus");

	clsValues = clsValues + clsValues2;
	clsValues.Print("After plus to self");
}
/* 
// --------------------------------------------------------------------------------
// Name: Test1
// Abstract: Pass by reference
// --------------------------------------------------------------------------------
void Test1( CResizableArray<long>&clsValues )
{
	printf( "Test 1 ------------------------------\n" );
	clsValues.Print( );
}


// --------------------------------------------------------------------------------
// Name: Test2
// Abstract: Pass by value
// --------------------------------------------------------------------------------
void Test2( CResizableArray<long> clsCopyOfOriginal )
{
	printf( "Test 2 ------------------------------\n" );
	clsCopyOfOriginal.Print( );

} */

 
//Name: StackTests
//Abstract: Step 2 CStack Template test with int
void StackTests()
{
	CStack<int> clsStack1;
	clsStack1.Print("Empty Stack");

	//Push
	clsStack1.Push(2);
	clsStack1.Push(4);
	clsStack1.Push(6);
	clsStack1.Push(8);
	// 	clsStack1.Print("after pushing 2,4,6");
		//clsStack1.Push();

		//Pop
	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	clsStack1.Print("After popping 6");

	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	cout << "Pop() =" << clsStack1.Pop() << endl;
	//	clsStack1.Print("After popping all");

		//Push
	//	clsStack1.Push(8);
	//	clsStack1.Print("after pushing 8"); 
	clsStack1.Print("after pushing 2,4,6,8");
	// cout << "I like C++" << endl; 
	clsStack1.Print("Stack Test 1 Before Pass By Ref");
	StackTests1(clsStack1);
	clsStack1.Print("Stack Test 1 After Pass By Ref");


	clsStack1.Print("Stack Test 2 Before Pass By Value");
	StackTests2(clsStack1);
	clsStack1.Print("Stack Test2 After Pass By Value");
}

//Name: StackTests1
//Abstract: Tests on Stack template with int - Pass By ref
void StackTests1(CStack<int>& clsOriginal)
{
	clsOriginal.Print("Stack Test 1 Pass By Ref");

}

//Name: StackTest2
//Abstract: Tests on Stack template with int - Pass By value
void StackTests2(CStack<int> clsCopy)
{
	clsCopy.Print("Stack Test 2 Pass By value");
} 

//Name: charQueueTests
//Abstract: Step 3 CQueue Template test with int
void QueueTests()
{
	CQueue<int> clsQueue1;
	clsQueue1.Print("Empty Queue");

	//Push
	clsQueue1.Push(2);
	clsQueue1.Push(4);
	clsQueue1.Push(6);
	clsQueue1.Push(8);
	/* clsQueue1.Print("after pushing 2,4,6");
	//clsQueue1.Push();

	//Pop
	cout << "Pop() =" << clsQueue1.Pop() << endl;
	clsQueue1.Print("After popping 2");

	cout << "Pop() =" << clsQueue1.Pop() << endl;
	cout << "Pop() =" << clsQueue1.Pop() << endl;
	cout << "Pop() =" << clsQueue1.Pop() << endl;
	clsQueue1.Print("After popping all");

	//Push
	clsQueue1.Push(8);
	clsQueue1.Print("after pushing 8"); */
	clsQueue1.Print("after pushing 2,4,6,8");
	// cout << "I like C++" << endl; 

	clsQueue1.Print("Queue Test 1 Before Pass By Ref");
	QueueTests1(clsQueue1);
	clsQueue1.Print("Queue Test 1 After Pass By Ref");


	clsQueue1.Print("Queue Test 1 Before Pass By Value");
	QueueTests2(clsQueue1);
	clsQueue1.Print("Queue Test 1 After Pass By Value");
}

//Name: QueueTest1
//Abstract: Tests on Queue Template with int - Pass By Ref
void QueueTests1(CQueue<int>& clsOriginal)
{
	clsOriginal.Print("Queue Test 1 Pass By Ref");
}

//Name: QueueTest2
//Abstract: Tests on Queue Template with int - Pass By value
void QueueTests2(CQueue<int> clsCopy)
{
	clsCopy.Print("Queue Test 2 Pass By value");
}

//Name: charQueueTests
//Abstract: Step 3 CQueue Template test with char

void charQueueTests()
{
	CQueue<char> clsQueue1;
	clsQueue1.Print("Empty Queue");

	//Push
	clsQueue1.Push('c');
	clsQueue1.Push('d');
	clsQueue1.Push('a');
	clsQueue1.Push('b');
	/* clsQueue1.Print("after pushing 2,4,6");
	//clsQueue1.Push();

	//Pop
	cout << "Pop() =" << clsQueue1.Pop() << endl;
	clsQueue1.Print("After popping 2");

	cout << "Pop() =" << clsQueue1.Pop() << endl;
	cout << "Pop() =" << clsQueue1.Pop() << endl;
	cout << "Pop() =" << clsQueue1.Pop() << endl;
	clsQueue1.Print("After popping all");

	//Push
	clsQueue1.Push(8);
	clsQueue1.Print("after pushing 8"); */
	clsQueue1.Print("after pushing c,d,a,b");
	// cout << "I like C++" << endl; 

	clsQueue1.Print("Queue Test 1 Before Pass By Ref");
	charQueueTests1(clsQueue1);
	clsQueue1.Print("Queue Test 1 After Pass By Ref");


	clsQueue1.Print("Queue Test 1 Before Pass By Value");
	charQueueTests2(clsQueue1);
	clsQueue1.Print("Queue Test 1 After Pass By Value");
}

//Name: QueueTest1
//Abstract: Tests on Queue Pass By Ref
void charQueueTests1(CQueue<char>& clsOriginal)
{
	clsOriginal.Print("Queue Test 1 Pass By Ref");
}

//Name: QueueTest2
//Abstract: Tests on Queue Pass By value
void charQueueTests2(CQueue<char> clsCopy)
{
	clsCopy.Print("Queue Test 2 Pass By value");
}

//endif