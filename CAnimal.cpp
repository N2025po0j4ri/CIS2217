// --------------------------------------------------------------------------------
// Name: CClassName
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include "CAnimal.h"

//Name: SetName
//Abstract: Set Name
void CAnimal::SetName(char* pstrNewName)
{
	//Boundary check
	if (strlen(pstrNewName) < 50)
	{
		strcpy_s(m_strName, pstrNewName);
	}

}

//Name: GetName
//Abstract: Get Name
char* CAnimal::GetName()
{
	return m_strName;
}

//Name: SetType
//Abstract: Set Type
void CAnimal::SetType(char* pstrNewType)
{
	//Boundary check
	if (strlen(pstrNewType) < 50)
	{
		strcpy_s(m_strType, pstrNewType);
	}

}

//Name: GetType
//Abstract: Get Type
char* CAnimal::GetType()
{
	return m_strType;
}





