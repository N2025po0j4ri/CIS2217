// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CDog.h"

// --------------------------------------------------------------------------------
// Name: Constructor that takes no parameter
// Abstract: calls Initialize 
// --------------------------------------------------------------------------------
CDog::CDog()
{
	Initialize(0, 1, 10);
}

// --------------------------------------------------------------------------------
// Name: Constructor that takes name as parameter
// Abstract: calls Initialize using parameter
// --------------------------------------------------------------------------------
CDog::CDog(const char* pstrName)
{
	Initialize(pstrName, 1, 10);
}
// --------------------------------------------------------------------------------
// Name: Constructor that takes name and age as parameters
// Abstract: calls Initialize using parameters
// --------------------------------------------------------------------------------
CDog::CDog(const char* pstrName, int intAge)
{

	Initialize(pstrName, intAge, 10);
}

// --------------------------------------------------------------------------------
// Name: Constructor that takes name, age and weight as parameters
// Abstract: calls Initialize using parameters
// --------------------------------------------------------------------------------
CDog::CDog(const char* pstrName, int intAge, float sngWeight)
{
	Initialize(pstrName, intAge, sngWeight);
}


// --------------------------------------------------------------------------------
// Name: Destructor
// Abstract: calls CleanUp
// --------------------------------------------------------------------------------
CDog::~CDog()
{
	CleanUp();
}

// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: Deletes char* properties
// --------------------------------------------------------------------------------
void CDog::CleanUp()
{
	//delete m_pstrName;
}

// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Initialize properties
// --------------------------------------------------------------------------------
void CDog::Initialize(const char* pstrName, int intAge, float sngWeight)
{
	SetName(pstrName);
	SetAge(intAge);
	SetWeight(sngWeight);
}
// --------------------------------------------------------------------------------
// Name: SetName
// Abstract: Set the name
// --------------------------------------------------------------------------------
void CDog::SetName(const char* pstrNewName )
{
	// Boundary check
	if( strlen( pstrNewName ) < 50 )
	{
		m_pstrName = pstrNewName;
	}
}


// --------------------------------------------------------------------------------
// Name: GetName
// Abstract: Get the name
// --------------------------------------------------------------------------------
const char* CDog::GetName( )
{
	return m_pstrName;
}


// --------------------------------------------------------------------------------
// Name: SetWeight
// Abstract: Don't let the weight be negative
// --------------------------------------------------------------------------------
void CDog::SetWeight( float sngNewWeight ) 
{
	// Negative?
	if( sngNewWeight < 0.0f )
	{
		// Yes, clip it
		 sngNewWeight = 0.0f;
	}
	m_sngWeight = sngNewWeight;
}


// --------------------------------------------------------------------------------
// Name: GetWeight
// Abstract: How much do you weigh?
// --------------------------------------------------------------------------------
const float CDog::GetWeight( )
{
	return m_sngWeight;
}

// --------------------------------------------------------------------------------
// Name: SetAge
// Abstract: Don't let the weight be negative
// --------------------------------------------------------------------------------
void CDog::SetAge(int intNewAge)
{
	// Negative?
	if (intNewAge < 0)
	{
		// Yes, clip it
		m_intAge = 0;
	}
	m_intAge = intNewAge;
}


// --------------------------------------------------------------------------------
// Name: GetAge
// Abstract: How much is your age
// --------------------------------------------------------------------------------
const int CDog::GetAge()
{
	return m_intAge;
}



// --------------------------------------------------------------------------------
// Name: Bark
// Abstract: Speak, Fido!
// --------------------------------------------------------------------------------
void CDog::Bark( )
{
	// Ankle biter?
	if( m_sngWeight < 15.0f )
	{
		// Yes
		cout << "yip, yip, yip\n";
	}
	else
	{
		// No, big dog
		cout << "Woof, woof\n";
	}
}

// --------------------------------------------------------------------------------
// Name: Print
// Abstract: prints outs out all the properties and calls all the methods 
// --------------------------------------------------------------------------------
void CDog::Print()
{
	// Get Methods
	cout << "Name  : " << GetName() << endl;
	cout << "Weight: " << GetWeight() << endl;
	cout << "Age: " << GetAge() << endl;

	// Methods
	Bark();
	cout << endl;
	cout << endl;
}

