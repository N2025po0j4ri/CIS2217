// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 2
// Abstract: Homework 10
// --------------------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>
# include "CStack.h"
#include "CQueue.h"

using namespace std;

void StackTests();
void StackTests1(CStack &clsOriginal);
void StackTests2(CStack clsCopy);

void QueueTests();
void QueueTests1(CQueue &clsOriginal);
void QueueTests2(CQueue clsCopy);

//Name: main
//Abstract: main
int main() {
	StackTests();
	QueueTests();
	return 1;
}

//Name: QueueTests
//Abstract: Tests on Queue
void QueueTests()
{
	CQueue clsQueue1;
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
//Abstract: Tests on Queue Pass By Ref
void QueueTests1(CQueue& clsOriginal)
{
	clsOriginal.Print("Queue Test 1 Pass By Ref");
}

//Name: QueueTest2
//Abstract: Tests on Queue Pass By value
void QueueTests2(CQueue clsCopy)
{
	clsCopy.Print("Queue Test 2 Pass By value");
}

//Name: StackTests
//Abstract: Tests on Stack
void StackTests()
{
	 CStack clsStack1;
	clsStack1.Print("Empty Stack");

	//Push
	clsStack1.Push(2);
	clsStack1.Push(4);
	clsStack1.Push(6);
	clsStack1.Push(8);
/* 	clsStack1.Print("after pushing 2,4,6");
	//clsStack1.Push();

	//Pop
	cout << "Pop() =" << clsStack1.Pop() << endl;
	clsStack1.Print("After popping 6");

	cout << "Pop() =" << clsStack1.Pop() << endl;
	cout << "Pop() =" << clsStack1.Pop() << endl;
	cout << "Pop() =" << clsStack1.Pop() << endl;
	clsStack1.Print("After popping all");

	//Push
	clsStack1.Push(8);
	clsStack1.Print("after pushing 8"); */
	clsStack1.Print("after pushing 2,4,6,8");
	// cout << "I like C++" << endl; 
	clsStack1.Print("Stack Test 1 Before Pass By Ref");
	StackTests1(clsStack1);
	clsStack1.Print("Stack Test 1 After Pass By Ref");


	clsStack1.Print("Stack Test 2 Before Pass By Value");
	StackTests2(clsStack1);
	clsStack1.Print("Stack Test2 After Pass By Value");
}

//Name: QueueTest1
//Abstract: Tests on Stack Pass By ref
void StackTests1(CStack &clsOriginal)
{
	clsOriginal.Print("Stack Test 1 Pass By Ref");

}

//Name: StackTest2
//Abstract: Tests on Stack Pass By value
void StackTests2(CStack clsCopy)
{
	clsCopy.Print("Stack Test 2 Pass By value");
}