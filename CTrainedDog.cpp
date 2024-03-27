// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CTrainedDog.h"

CTrainedDog::CTrainedDog():CDog()
{
	//Initialize(0, 1, 10);
}

CTrainedDog::CTrainedDog(const char* pstrName):CDog( pstrName)
{
	//Initialize(pstrName, 1, 10);
}

CTrainedDog::CTrainedDog(const char* pstrName, int intAge) :CDog(pstrName, intAge)
{

	//Initialize(pstrName, intAge, 10);
}
CTrainedDog::CTrainedDog(const char* pstrName, int intAge, float sngWeight) :CDog(pstrName, intAge, sngWeight)
{
	//Initialize(pstrName, intAge, sngWeight);
}
void CTrainedDog::Print()
{
	CDog::Print();
}

// --------------------------------------------------------------------------------
// Name: Fetch
// Abstract: Get the stick
// --------------------------------------------------------------------------------
void CTrainedDog::Fetch( )
{
	cout << "Fetching the tasty stick\n";
}


// --------------------------------------------------------------------------------
// Name: PlayDead
// Abstract: *Bang*, you got me!
// --------------------------------------------------------------------------------
void CTrainedDog::PlayDead( )
{
	cout << "*Bang*, you got me!\n";
}


