// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 2
// Abstract: Homework 10
// --------------------------------------------------------------------------------

//#include "CNode.h"
#include "CStack.h"
//Name: Constructor
//Abstract: No parameter Constructor
CStack::CStack()	// Default constructor
{
	//isEmpty = true;
	Initialize();
}

//Name: Constructor
//Abstract: Deep copy
CStack::CStack(const CStack& clsOriginalToCopy)	// Deep copy!
{
	Initialize();
	*this = clsOriginalToCopy;
}

//Name: Destructor
//Abstract: calls clean up
CStack::~CStack() // Clean up any allocated memory
{
	CleanUp();
}
//Name: Initialize
//Abstract: executes initialization
void CStack::Initialize()
{
	m_pclsHeadNode = 0;
}

//Name: operator =
//Abstract: Deep copy
void CStack::operator = (const CStack& clsOriginalToCopy)	// Deep copy!
{ 
	if (this != &clsOriginalToCopy) {
		CleanUp();
		DeepCopy(clsOriginalToCopy);

	}
}
//Name: CleanUp
//Abstract: executes clean up
void CStack::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}
//Name: Push
//Abstract: pushes value to Stack
void CStack::Push(int intValue)	// Add 1 value to the top of the stack
{
	
	CNode* pclsNewNode = 0;
		
	pclsNewNode = new CNode(intValue);

	pclsNewNode->SetNextNode(m_pclsHeadNode);
	m_pclsHeadNode = pclsNewNode; /* 
	CNode* pclsNewNode = new CNode(intValue, m_pclsHeadNode);
	m_pclsHeadNode = pclsNewNode; */
}
//Name: Pop
//Abstract: removes value from Stack in LIFO order
int CStack::Pop()	// Remove 1 value from the top of the stack
{
	int intValue = 0;
	CNode* pclsNextNode = 0;

	// Empty List?
	if (IsEmpty() == false)
	{
		// No, get value
		intValue = m_pclsHeadNode -> GetValue();

		// Get next
		pclsNextNode = m_pclsHeadNode -> GetNextNode();

		// Delete
	    delete m_pclsHeadNode;
		m_pclsHeadNode = 0;

		// Move to next
		m_pclsHeadNode = pclsNextNode;
	}
	return intValue;

}
//Name: IsEmpty
//Abstract: returns boolean telling if empty
bool CStack::IsEmpty() const	// Return true if head node pointer is zero
{
	bool blnIsEmty = false;
	if (m_pclsHeadNode == 0) {
		blnIsEmty = true;
	}
	return blnIsEmty;
}
//Name: Print
//Abstract: Prints Stack values with index/location
void CStack::Print(const char* pstrCaption) const	// This will print the whole list.
{
	int intIndex = 0;
	CNode* pudtCurrentNode = 0; // m_pclsHeadNode;

	cout << pstrCaption << "------------------------" << endl;

	//CNode pudtNextNode;
	//printf("\n");
	//printf("%s\n", "val");
	//printf("----------------------------------------\n");
	if(IsEmpty() == false){ 
		// Start at the top
		 pudtCurrentNode = m_pclsHeadNode;
		while (pudtCurrentNode != 0)
		{
			// Count
			intIndex += 1;

			// Display current value
			cout << "Value at node #" << intIndex
				<< " is " << pudtCurrentNode->GetValue() << endl;

			// Get next node
			

			// Move to next node
			pudtCurrentNode = pudtCurrentNode -> GetNextNode();
		}
	}
	else {
		cout << "emty stack" << endl;
	}
}
// It is non-destructive.  
// You can call it over and over

//Name: DeepCopy
//Abstract: executes DeepCopy
void CStack::DeepCopy(const CStack& clsOriginalToCopy)
{ 
	CNode* pclsCurrentOriginal = 0;
	int intValue = 0;
	CNode* pclsNextNode = 0;

	//Get top of original to copy
	pclsCurrentOriginal = clsOriginalToCopy.m_pclsHeadNode;

	while (pclsCurrentOriginal != 0)
	{
		//Get Value
		intValue = pclsCurrentOriginal->GetValue();

		// Copy/Push value
		Push(intValue);

		// Get next
		pclsNextNode = pclsCurrentOriginal->GetNextNode();

		//Move to next
		pclsCurrentOriginal = pclsNextNode;
	}

	//return clsOriginalToCopy;
}

