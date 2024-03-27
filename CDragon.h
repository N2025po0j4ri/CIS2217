// --------------------------------------------------------------------------------
// Name: CDragon
// Abstract: This class ...
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------
#pragma once		// Include this file only once even if referenced multiple times

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include "CAnimal.h"
#include <iostream>
using namespace std;

class CDragon :public CAnimal
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
		
		float AmountOfGold;
		


	private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
	public:
	//	char* GetName();
	//	void SetName(char* pstrName);
		//char* GetType();
		// void SetType(char* pstrType);
		void MakeNoise();
		void BreathFire();

	protected:

	private:

};
