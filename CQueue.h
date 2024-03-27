// --------------------------------------------------------------------------------
// Name: CQueue
// Abstract: This is Queue class 
// --------------------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>
using namespace std;
#include "CNode.h"
#ifndef CQUEUE_H
#define CQUEUE_H

template<typename GenericDataType>
class CQueue
{

public:			// Never make public properties.  
				// Make protected or private with public get/set methods

protected:

	
	GenericDataType m_intValue;
	CNode<GenericDataType>* m_pclsNextNode;

private:
	CNode<GenericDataType>*	m_pclsHeadNode;
	CNode<GenericDataType>*	m_pclsTailNode;

//Methods
public:
	CQueue();
	CQueue(const CQueue& clsOriginalToCopy);	// Deep copy!
		~CQueue();	// Clean up any allocated memory
		void operator=(const CQueue& clsOriginalToCopy);	// Deep copy!
		void Push(GenericDataType intValue);	// Add 1 value to the end of the queue
		GenericDataType Pop();	// Remove 1 value from the front of the queue
		bool IsEmpty() const;	// Return true if head node pointer is zero
		void Print(const char* pstrCaption) const;	// This will print the whole list. 
		// It is non-destructive.  
		// You can call it over and over
		
private:
	void Initialize();	// Set class properties to zero.
	void DeepCopy(const CQueue& clsOriginalToCopy);
	void CleanUp();					// Delete the list


};


//Name: Constructor
//Abstract: No parameter Constructor
template<typename GenericDataType>
CQueue<GenericDataType>::CQueue<GenericDataType>()	// Default constructor
{
	Initialize();
}

//Name: Constructor
//Abstract: Deep copy
template<typename GenericDataType>
CQueue<GenericDataType>::CQueue<GenericDataType>(const CQueue<GenericDataType>& clsOriginalToCopy)	// Deep copy!
{
	Initialize();
	*this = clsOriginalToCopy;
}

//Name: Destructor
//Abstract: calls clean up
template<typename GenericDataType>
CQueue<GenericDataType>::~CQueue<GenericDataType>()	// Clean up any allocated memory
{
	CleanUp();
}

//Name: CleanUp
//Abstract: executes clean up
template<typename GenericDataType>
void CQueue<GenericDataType>::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}

//Name: Initialize
//Abstract: executes initialization
template<typename GenericDataType>
void CQueue<GenericDataType>::Initialize()
{
	m_pclsHeadNode = 0;
	m_pclsTailNode = 0;
}
//	operator=(const CQueue& clsOriginalToCopy)	// Deep copy!

//Name: Push
//Abstract: pushes value to Queue
template<typename GenericDataType>
void CQueue<GenericDataType>::Push(GenericDataType intValue)	// Add 1 value to the end of the queue
{
	CNode<GenericDataType>* pclsNewNode = 0;

	pclsNewNode = new CNode<GenericDataType>(intValue);

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
template<typename GenericDataType>
void CQueue<GenericDataType>::operator = (const CQueue<GenericDataType>& clsOriginalToCopy)	// Deep copy!
{
	if (this != &clsOriginalToCopy) {
		CleanUp();
		DeepCopy(clsOriginalToCopy);

	}
}

//Name: Pop
//Abstract: removes value from Queue in FIFO order
template<typename GenericDataType>
GenericDataType CQueue<GenericDataType>::Pop()	// Remove 1 value from the front of the queue
{
	GenericDataType intValue = 0;
	CNode<GenericDataType>* pclsNextNode = 0;

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
template<typename GenericDataType>
bool CQueue<GenericDataType>::IsEmpty() const	// Return true if head node pointer is zero
{
	bool blnIsEmty = false;
	if (m_pclsHeadNode == 0) {
		blnIsEmty = true;
	}
	return blnIsEmty;
}
//Name: Print
//Abstract: Prints Queue values with index/location
template<typename GenericDataType>
void CQueue<GenericDataType>::Print(const char* pstrCaption) const	// This will print the whole list. 
{
	int intIndex = 0;
	CNode<GenericDataType>* pudtCurrentNode = 0; // m_pclsHeadNode;

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
template<typename GenericDataType>
void CQueue<GenericDataType>::DeepCopy(const CQueue<GenericDataType>& clsOriginalToCopy)
{
	CNode<GenericDataType>* pclsCurrentOriginal = 0;
	int intValue = 0;
	CNode<GenericDataType>* pclsNextNode = 0;

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
#endif