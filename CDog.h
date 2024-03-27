// --------------------------------------------------------------------------------
// Name: CDog
// Abstract: This class is a simple example of classes and encapsulation
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Include this file only once even if referenced multiple times

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;

class CDog
{
	static const long lngSTRING_MAXIMUM_SIZE = 50;

	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
		
		const char* m_pstrName;
		float m_sngWeight;
		int m_intAge;
	private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
	public:
		CDog();
		CDog(const char* pstrName);
		CDog(const char* pstrName, int intAge);
		CDog(const char* pstrName, int intAge, float sngWeight);
		~CDog();
		// Name
		void SetName(const char* pstrNewName );
		const char* GetName( );

		// Weight
		void SetWeight(const float sngNewWeight );
		const float GetWeight( ) ;

		//Age
		void SetAge(const int intNewAge);
		const int GetAge();

		void Bark( );
		void Print();

	protected:
		void Initialize( const char* pstrName, int intAge, float sngWeight);
		void CleanUp();
	private:

};

