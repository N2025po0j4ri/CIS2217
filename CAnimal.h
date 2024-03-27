// --------------------------------------------------------------------------------
// Name: CAnimal
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
#include <iostream>
using namespace std;

class CAnimal
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
		
		char m_strName[50];
		char m_strType[50];


	private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
	public:
		char* GetName();
		void SetName(char* pstrName);
		char* GetType();
		void SetType(char* pstrType);
		void MakeNoise();

	protected:

	private:

};
