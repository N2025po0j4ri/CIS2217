// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 
// Assignment: SuperString – Final Project 
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CSuperString.h"
void ConstCharReturnTests();
void ToDataTypeTests();
void CSuperStringTests();
void ConstructorTests();
void AssignmentOperatorTests();
void MuahahahTest1();
void MuahahahTest2();
void MuahahahTest3();
//----------------------------------
// Name: main
// Abstract: 
//----------------------------------
int  main()
{
	ConstructorTests();
	ToDataTypeTests();
	AssignmentOperatorTests();
	ConstCharReturnTests();
	MuahahahTest1();
	MuahahahTest2();
	MuahahahTest3();
	
	//CSuperStringTests();
	//system("pause");
	return 1;
}
void MuahahahTest1()
{
	CSuperString ssTest;
	cout << " Muahahah Test #1: " << ssTest.ToString() << endl;
}
void MuahahahTest2()
{
	CSuperString ssTest = "I Love Star Wars and I Love Star Trek";

	ssTest = ssTest.Replace("Love", "Really Love Love");

	cout << "Muahahah Test #2: " << ssTest.ToString() << endl;
}
void MuahahahTest3()
{
	CSuperString ssTest = "I Love Star Wars and I Love Star Trek and I Love C++";

	ssTest = ssTest.Replace("Love", "Really Love Love");

	cout << "Muahahah Test #3: " << ssTest.ToString() << endl;
}
void ConstCharReturnTests()
{
	CSuperString ssSource1 = "I Love Star Trek  ";
	cout << "#4 - Const Char Return Tests" << endl;
	ssSource1.ToUpperCase();
	cout << " 1a) - ToUpperCase  = '" << ssSource1.ToUpperCase().ToString() << "'" << endl;
//	ssSource1 = ssSource1.ToUpperCase().ToString();
//	cout << " 1b) - ToUpperCase  = '" << ssSource1.ToUpperCase().ToString() << "'" << endl;
	cout << " 2) - ToLowerCase  = '" << ssSource1.ToLowerCase() << "'" << endl;
	cout << " 3) - TrimLeft  = '" << ssSource1.TrimLeft() << "'" << endl;
	cout << "original= '" << ssSource1.ToString() << "'" << endl;
	cout << " 4) - TrimRight  = '" << ssSource1.TrimRight() << "'" << endl;
	cout << " 4) - Trim  = '" << ssSource1.Trim() << "'" << endl;
	cout << " 5) - Reverse  = '" << ssSource1.Reverse() << "'" << endl;
	cout << " 6) - Left  = '" << ssSource1.Left(2).ToString() << "'" << endl;
	cout << " 6) - Left  = '" << ssSource1.Left(4).ToString() << "'" << endl;
	cout << " 6) - Left(2)  = '" << ssSource1.Left(2).ToString() << "',Left(4) ='"  << ssSource1.Left(4).ToString() << "'" << endl;
}
void AssignmentOperatorTests()
{
	CSuperString ssSource1;
	cout << "#3 - Assignment Operator" << endl;
	ssSource1 = "I Love Star Trek";
	cout << " 1) - I Love Star Trek = '" << ssSource1.ToString() << "'" << endl;
	//cout << " 1) - I Love Star Trek = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = true;
	cout << " 2a) - boolean true  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = false;
	cout << " 2a) - boolean false  = '" << ssSource1.ToString() << "'" << endl;
	//ssSource1 = false;
	//cout << " 2a) - boolean false  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = (short)10;
	cout << " 3) - Short 10  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = (int)11;
	cout << " 4) - Integer 11  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = (long)12;
	cout << " 5) - Long 12  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = (float)13.1;
	cout << " 6) - Float 13.1  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = (double)14.2;
	cout << " 6) - Double 14.2  = '" << ssSource1.ToString() << "'" << endl;
	ssSource1 = 'A';
	cout << " 8) - Character A  = '" << ssSource1.ToString() << "'" << endl;

}
void ConstructorTests()
{
	CSuperString ssSource1;
	CSuperString ssSource2("I Love Star Trek!");
	CSuperString ssSource3a(true);
	CSuperString ssSource3b(false);
	CSuperString ssSource4('X');
	CSuperString ssSource5a((short)SHRT_MIN);
	CSuperString ssSource5b((short)SHRT_MAX);
     CSuperString ssSource6a((int)INT_MIN);
	CSuperString ssSource6b((int)INT_MAX);
	CSuperString ssSource7a((long)LONG_MIN);
	CSuperString ssSource7b((long)LONG_MAX);
	CSuperString ssSource8a((float)FLT_MIN);
	CSuperString ssSource8b((float)FLT_MAX);
	CSuperString ssSource9a((double)DBL_MIN);
	CSuperString ssSource9b((double)DBL_MAX); 
	CSuperString ssSource10(ssSource2);
	CSuperString ssSource11("1");
	//----------------------------------
	// Constructors
	//----------------------------------
	cout << "Constructors\n" << endl;
	cout << "----------------------------------" << endl;
	cout << " 1)  - Default		" << ssSource1.ToString() << endl;
	cout << " 2)  - char*		" << ssSource2.ToString() << endl;
	cout << " 3a) - bool		" << ssSource3a.ToString() << endl;
	cout << " 3b) - bool		" << ssSource3b.ToString() << endl;
		cout << " 4)  - char		" << ssSource4.ToString() << endl;
	cout << " 5a) - short		" << ssSource5a.ToString() << endl;
	cout << " 5b) - short		" << ssSource5b.ToString() << endl;
		cout << " 6a) - int		    " << ssSource6a.ToString() << endl;
	cout << " 6b) - int		    " << ssSource6b.ToString() << endl;
		  cout << " 7a) - long		" << ssSource7a.ToString() << endl;
	cout << " 7b) - long		" << ssSource7b.ToString() << endl;
		cout << " 8a) - float		" << ssSource8a.ToString() << endl;
	cout << " 8b) - float		" << ssSource8b.ToString() << endl;
	 cout << " 9a) - double		" << ssSource9a.ToString() << endl;
	cout << " 9b) - double		" << ssSource9b.ToString() << endl; 

	cout << " 10) - SuperString	" << ssSource10.ToString() << endl;

//	cout << " 11) - ToBoolean true	" << ssSource3a.ToBoolean() << endl;
//	cout << " 11) - ToBoolean 1	" << ssSource11.ToBoolean() << endl;
}
void ToDataTypeTests()
{
	CSuperString ssSource1a(true);
	CSuperString ssSource1b(false);
	CSuperString ssSource2a((short)SHRT_MIN);
	CSuperString ssSource2b((short)SHRT_MAX);
	CSuperString ssSource3a((int)INT_MIN);
	CSuperString ssSource3b((int)INT_MAX);
	CSuperString ssSource4a((long)LONG_MIN);
	CSuperString ssSource4b((long)LONG_MAX);
	CSuperString ssSource5a((float)FLT_MIN);
	CSuperString ssSource5b((float)FLT_MAX);
	CSuperString ssSource6a((double)DBL_MIN);
	CSuperString ssSource6b((double)DBL_MAX);
	
	//----------------------------------
	// Constructors
	//----------------------------------
	cout << "To<DataType>" << endl;
	cout << "----------------------------------" << endl;
	cout << " 1a)  - bool		" << ssSource1a.ToBoolean() << endl;
	cout << " 1b)  - bool		" << ssSource1b.ToBoolean() << endl;
	cout << " 2a) - short		" << ssSource2a.ToShort() << endl;
	cout << " 2b) - short		" << ssSource2b.ToShort() << endl;
	cout << " 3a)  - int		" << ssSource3a.ToInteger() << endl;
	cout << " 3b) - int 		" << ssSource3b.ToInteger() << endl;
	cout << " 4a) - long		" << ssSource4a.ToLong() << endl;
	cout << " 4b) - long		" << ssSource4b.ToLong() << endl;
	cout << " 5a) - float		" << ssSource5a.ToFloat() << endl;
	cout << " 5b) - float		" << ssSource5b.ToFloat() << endl;
	cout << " 6a) - double		" << ssSource6a.ToDouble() << endl;
	cout << " 6b) - double		" << ssSource6b.ToDouble() << endl;


	//	cout << " 11) - ToBoolean true	" << ssSource3a.ToBoolean() << endl;
	//	cout << " 11) - ToBoolean 1	" << ssSource11.ToBoolean() << endl;
}
void CSuperStringTests()
{
	cout << "----------------------------------" << endl;
	cout << "CSuperString Tests" << endl;

	cout << "----------------------------------" << endl;

	// #1 Constructor
	CSuperString ssSource1;
	ssSource1.Print("#1 - Default Constructor");

	// #2 - Assignment Operator
	ssSource1 = "I Love Star Trek";
	ssSource1.Print("#2 - Assignment Operator");

	// #3 - Length
	cout << "#3 - Length:16?" << ssSource1.Length() << endl;

	// #4 - Parameterized constructor: const char*
	{
		CSuperString ssSource2("I Love Star Trek!");
		ssSource2.Print("#4 - Parameterized constructor: const char*");
	}

	// #5 - Parameterized constructor: boolean
	{
		CSuperString ssSource2(true);
		CSuperString ssSource3(false);
		ssSource2.Print("#5 - Parameterized constructor:boolean");
		ssSource3.Print("#5 - Parameterized constructor:boolean");
	}
	// #6 - Parameterized constructor:  char
	{
		CSuperString ssSource2('I');
		ssSource2.Print("#6 - Parameterized constructor: char");
	}
	// #7 - Parameterized constructor:  short
	{
		CSuperString ssSource2((short)32767);
		CSuperString ssSource3((short)-32767);
		ssSource2.Print("#7 - Parameterized constructor: short");
		ssSource3.Print("#7 - Parameterized constructor: short");
	}
	// #8 Copy Constructor - in block by itself so destructor for copy is called when block ends
	{
		CSuperString ssSource2(ssSource1);
		ssSource2.Print("#8a - copy Constructor");
	}
	ssSource1.Print("#8b - Original unaffected");
}