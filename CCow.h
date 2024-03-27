// --------------------------------------------------------------------------------
// Name: CClassName
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

class CCow :public CAnimal
{
	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
		
		char color[50];
		


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
		void Graze();

	protected:

	private:

};
