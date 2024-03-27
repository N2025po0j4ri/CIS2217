// --------------------------------------------------------------------------------
// Name: CTrainedDog
// Abstract: This class is a simple example of inheritance
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Include this file only once even if referenced multiple times

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CDog.h"


class CTrainedDog : public CDog
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
		
	private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
	public:
		CTrainedDog();
		CTrainedDog(const char* pstrName);
		CTrainedDog(const char* pstrName, int intAge);
		CTrainedDog(const char* pstrName, int intAge, float sngWeight);
		void Fetch( );
		void PlayDead( );
		void Print();

	protected:

	private:

};
