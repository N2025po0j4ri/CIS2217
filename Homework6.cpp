// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 2
// Abstract: Homework 6
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
#include "CDog.h"
#include "CTrainedDog.h"
using namespace std;

// --------------------------------------------------------------------------------
// Constants
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// User Defined Types
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Function Prototypes
// --------------------------------------------------------------------------------


// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the action starts
// --------------------------------------------------------------------------------
int main( )
{
	

	// Set Methods
	char name[] = "Buster";
	char* ptrName = name;
	//clsBuster.SetName(ptrName);
	 CDog clsBuster(ptrName);
	//clsBuster.SetName( "123456789012345678901234567890123456789012345678901234567890" );
	clsBuster.SetWeight( 40 );
	clsBuster.SetAge(8);
	clsBuster.Print();
/* 
	// Get Methods
	cout << "Name  : " << clsBuster.GetName( )   << endl;
	cout << "Weight: " << clsBuster.GetWeight( ) << endl;
	cout << "Age: " << clsBuster.GetAge() << endl;

	// Methods
	clsBuster.Bark( );
	cout << endl;
	cout << endl; */

	char trnDogname[] = "Underdog";
	char* ptrTrnDogname = trnDogname;
	CTrainedDog clsUnderDog(ptrTrnDogname);

	// Set Methods
	//clsUnderDog.SetName( "" );
	//clsUnderDog.SetName( "123456789012345678901234567890123456789012345678901234567890" );
	clsUnderDog.SetWeight( -40 );

	clsUnderDog.Print();
	// Get Methods
	//cout << "Name  : " << clsUnderDog.GetName( )   << endl;
	//cout << "Weight: " << clsUnderDog.GetWeight( ) << endl;

	// Methods
	clsUnderDog.Bark( );
	clsUnderDog.Fetch( );
	clsUnderDog.PlayDead( );
	cout << endl;
	cout << endl;
	

	return 1;
	//system( "pause" );
}
