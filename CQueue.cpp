// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 2
// Abstract: Homework 10
// --------------------------------------------------------------------------------

#include "CNode.h"
#include "CQueue.h"

//Name: Constructor
//Abstract: No parameter Constructor
CQueue::CQueue()	// Default constructor
{
	Initialize();
}

//Name: Constructor
//Abstract: Deep copy
CQueue::CQueue(const CQueue& clsOriginalToCopy)	// Deep copy!
{
	Initialize();
	*this = clsOriginalToCopy;
}

//Name: Destructor
//Abstract: calls clean up
CQueue::~CQueue()	// Clean up any allocated memory
{
	CleanUp();
}

//Name: CleanUp
//Abstract: executes clean up
void CQueue::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}

//Name: Initialize
//Abstract: executes initialization
void CQueue::Initialize()
{
	m_pclsHeadNode = 0;
	m_pclsTailNode = 0;
}
//	operator=(const CQueue& clsOriginalToCopy)	// Deep copy!

//Name: Push
//Abstract: pushes value to Queue
void CQueue::Push(int intValue)	// Add 1 value to the end of the queue
{
	CNode* pclsNewNode = 0;

	pclsNewNode = new CNode(intValue);

	if (IsEmpty() == true) {
		m_pclsHeadNode = pclsNewNode;
		m_pclsTailNode = pclsNewNode;
	}
	else {
		m_pclsTailNode->SetNextNode(pclsNewNode);
		m_pclsTailNode = pclsNewNode;
	}
}

//Name: operator =
//Abstract:Deep copy
void CQueue::operator = (const CQueue& clsOriginalToCopy)	// Deep copy!
{
	if (this != &clsOriginalToCopy) {
		CleanUp();
		DeepCopy(clsOriginalToCopy);

	}
}

//Name: Pop
//Abstract: removes value from Queue in FIFO order
int CQueue::Pop()	// Remove 1 value from the front of the queue
{
	int intValue = 0;
	CNode* pclsNextNode = 0;

	// Empty List?
	if (IsEmpty() == false)
	{
		// No, get value
		intValue = m_pclsHeadNode->GetValue();

		// Get next
		pclsNextNode = m_pclsHeadNode->GetNextNode();

		// Delete
		delete m_pclsHeadNode;
		m_pclsHeadNode = 0;

		// Move to next
		m_pclsHeadNode = pclsNextNode;

		// what was last node
		if (IsEmpty() == true) {
			// clear tail node
			m_pclsTailNode = 0;
		}
	}
	return intValue;
}
//Name: IsEmpty
//Abstract: returns boolean telling if empty
bool CQueue::IsEmpty() const	// Return true if head node pointer is zero
{
	bool blnIsEmty = false;
	if (m_pclsHeadNode == 0) {
		blnIsEmty = true;
	}
	return blnIsEmty;
}
//Name: Print
//Abstract: Prints Queue values with index/location
void CQueue::Print(const char* pstrCaption) const	// This will print the whole list. 
{
	int intIndex = 0;
	CNode* pudtCurrentNode = 0; // m_pclsHeadNode;

	cout << pstrCaption << "------------------------" << endl;

	//CNode pudtNextNode;
	//printf("\n");
	//printf("%s\n", "val");
	//printf("----------------------------------------\n");
	if (IsEmpty() == false) {
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
			pudtCurrentNode = pudtCurrentNode->GetNextNode();
		}
	}
	else {
		cout << "emty Queue" << endl;
	}
}
//Name: DeepCopy
//Abstract: executes DeepCopy
void CQueue::DeepCopy(const CQueue& clsOriginalToCopy)
{ 
	CNode* pclsCurrentOriginal = 0;
	int intValue = 0;
	CNode* pclsNextNode = 0;

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
	/* 
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
	*/
	//return clsOriginalToCopy;
}



