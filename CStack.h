// --------------------------------------------------------------------------------
// Name: CStack
// Abstract: This class ...
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Pre-compiler Directives
// --------------------------------------------------------------------------------

//#pragma once
#include "CNode.h"
/* 
//Declare only once even if included multiple times
#ifndef CNODE_H
#define CNODE_H

template<typename GenericDataType>
class CNode
{

public:			// Never make public properties.  
				// Make protected or private with public get/set methods
	CNode();// Default constructor
	CNode(GenericDataType intValue);// Parameterized constructor #1
	CNode(GenericDataType intValue, CNode* pclsNextNode);	// Parameterized constructor #2
	CNode(const CNode& clsOriginalToCopy);	// Copy constructor with shallow copy! 
	~CNode();
	void Initialize(GenericDataType intValue, CNode* pclsNextNode);
	void SetValue(GenericDataType intNewValue);
	GenericDataType GetValue();
	void SetNextNode(CNode* pclsNextNode);
	CNode* GetNextNode();
	//CNode ShallowCopy(const CNode& clsOriginalToCopy);
	void operator = (const CNode& clsOriginalToCopy);	// Shallow copy! 
	void CleanUp();

protected:

	//char m_strName[50];
	//float m_sngWeight;
	GenericDataType m_intValue;
	CNode* m_pclsNextNode;

private:
	void ShallowCopy(const CNode<GenericDataType>& clsOriginalToCopy);

};
//Name: Constructor
//Abstract: No parameter Constructor
template<typename GenericDataType>
CNode<GenericDataType>::CNode<GenericDataType>()	// Default constructor
{
	//m_intValue = 0;
	//m_pclsNextNode = 0;
	Initialize(0, 0);
}
//Name: Constructor
//Abstract:Parameterized constructor #1
template<typename GenericDataType>
CNode<GenericDataType>::CNode<GenericDataType>(GenericDataType intValue)	// Parameterized constructor #1
{
	//m_intValue = intValue;
	//m_pclsNextNode = 0;
	Initialize(intValue, 0);
}
//Name: Constructor
//Abstract:Parameterized constructor #2
template<typename GenericDataType>
CNode<GenericDataType>::CNode<GenericDataType>(GenericDataType intValue, CNode* pclsNextNode)	// Parameterized constructor #2
{
	//m_intValue = intValue;
	//m_pclsNextNode = pclsNextNode;
	Initialize(intValue, pclsNextNode);
}
//Name: Copy Constructor
//Abstract:shallow copy
template<typename GenericDataType>
CNode<GenericDataType>::CNode<GenericDataType>(const CNode<GenericDataType>& clsOriginalToCopy)	// Copy constructor with shallow copy! 
{
	//m_intValue = clsOriginalToCopy.m_intValue;
	//m_pclsNextNode = clsOriginalToCopy.m_pclsNextNode;
	Initialize(0, 0);
	*this = clsOriginalToCopy;

}
//Name: CleanUp
//Abstract: executes clean up
template<typename GenericDataType>
void CNode<GenericDataType>::CleanUp()
{

}
//Name: Destructor
//Abstract: calls clean up
template<typename GenericDataType>
CNode<GenericDataType> :: ~CNode<GenericDataType>()
{
	CleanUp();
}
//Name: Initialize
//Abstract: executes initialization
template<typename GenericDataType>
void CNode<GenericDataType>::Initialize(GenericDataType intNewValue, CNode<GenericDataType>* pclsNextNode)	// 
{
	// CNode::SetValue(intValue);
	//CNode::SetNextNode( pclsNextNode); 
	m_intValue = intNewValue;
	m_pclsNextNode = pclsNextNode;
}
//Name: operator =
//Abstract:Shallow copy! 
template<typename GenericDataType>
void CNode<GenericDataType> :: operator = (const CNode<GenericDataType>& clsOriginalToCopy)	// Shallow copy! 
{
	ShallowCopy(clsOriginalToCopy);

}
//Name: SetValue
//Abstract:Set Value
template<typename GenericDataType>
void CNode<GenericDataType>::SetValue(GenericDataType intNewValue)
{
	m_intValue = intNewValue;
}
//Name: GetValue
//Abstract:Get Value
template<typename GenericDataType>
GenericDataType CNode<GenericDataType>::GetValue()
{
	return m_intValue;
}

//Name: SetNextNode
//Abstract:Set Next Node
template<typename GenericDataType>
void CNode<GenericDataType>::SetNextNode(CNode<GenericDataType>* pclsNextNode)
{
	m_pclsNextNode = pclsNextNode;
}
//Name: GetNextNode
//Abstract:Get Next Node
template<typename GenericDataType>
CNode<GenericDataType>* CNode<GenericDataType>::GetNextNode()
{
	return m_pclsNextNode;
}


//Name: ShallowCopy 
//Abstract:ShallowCopy
template<typename GenericDataType>
void CNode<GenericDataType>::ShallowCopy(const CNode<GenericDataType>& clsOriginalToCopy) {
	//CNode *pclsNewNode = new CNode(clsOriginalToCopy);
	//return *pclsNewNode;
	m_intValue = clsOriginalToCopy.m_intValue;
	m_pclsNextNode = clsOriginalToCopy.m_pclsNextNode;
}
#endif
*/
#ifndef CSTACK_H
#define CSTACK_H

template<typename GenericDataType>
class CStack
{

protected:
	CNode<GenericDataType>* m_pclsHeadNode;

public:			// Never make public properties.  
				// Make protected or private with public get/set methods
	CStack();
	CStack(const CStack& clsOriginalToCopy);	// Deep copy!
	~CStack();	// Clean up any allocated memory
	void operator=(const CStack& clsOriginalToCopy);	// Deep copy!

	void Push(GenericDataType intValue);	// Add 1 value to the top of the stack
	GenericDataType Pop(); // Remove 1 value from the top of the stack
	bool IsEmpty() const;	// Return true if head node pointer is zero
	void Print(const char* pstrCaption) const;	// This will print the whole list. 

protected:

	

private:
	
	//CNode m_pclsTailNode;
	
	void Initialize();	// Set class properties to zero.
	void DeepCopy(const CStack& clsOriginalToCopy);
	void CleanUp();				// Delete the list


};
//Name: Constructor
//Abstract: No parameter Constructor
template<typename GenericDataType>
CStack<GenericDataType>::CStack<GenericDataType>()	// Default constructor
{
	//isEmpty = true;
	Initialize();
}

//Name: Constructor
//Abstract: Deep copy
template<typename GenericDataType>
CStack<GenericDataType>::CStack<GenericDataType>(const CStack<GenericDataType>& clsOriginalToCopy)	// Deep copy!
{
	Initialize();
	*this = clsOriginalToCopy;
}

//Name: Destructor
//Abstract: calls clean up
template<typename GenericDataType>
CStack<GenericDataType>::~CStack<GenericDataType>() // Clean up any allocated memory
{
	CleanUp();
}
//Name: Initialize
//Abstract: executes initialization
template<typename GenericDataType>
void CStack<GenericDataType>::Initialize()
{
	m_pclsHeadNode = 0;
}

//Name: operator =
//Abstract: Deep copy
template<typename GenericDataType>
void CStack<GenericDataType>::operator = (const CStack<GenericDataType>& clsOriginalToCopy)	// Deep copy!
{
	if (this != &clsOriginalToCopy) {
		CleanUp();
		DeepCopy(clsOriginalToCopy);

	}
}
//Name: CleanUp
//Abstract: executes clean up
template<typename GenericDataType>
void CStack<GenericDataType>::CleanUp()
{
	while (IsEmpty() == false) {
		Pop();
	}
}
//Name: Push
//Abstract: pushes value to Stack
template<typename GenericDataType>
void CStack<GenericDataType>::Push(GenericDataType intValue)	// Add 1 value to the top of the stack
{

	CNode<GenericDataType>* pclsNewNode = 0;

	pclsNewNode = new CNode<GenericDataType>(intValue);

	pclsNewNode->SetNextNode(m_pclsHeadNode);
	m_pclsHeadNode = pclsNewNode; /*
	CNode* pclsNewNode = new CNode(intValue, m_pclsHeadNode);
	m_pclsHeadNode = pclsNewNode; */
}
//Name: Pop
//Abstract: removes value from Stack in LIFO order
template<typename GenericDataType>
GenericDataType CStack<GenericDataType>::Pop()	// Remove 1 value from the top of the stack
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
	}
	return intValue;

}
//Name: IsEmpty
//Abstract: returns boolean telling if empty
template<typename GenericDataType>
bool CStack<GenericDataType>::IsEmpty() const	// Return true if head node pointer is zero
{
	bool blnIsEmty = false;
	if (m_pclsHeadNode == 0) {
		blnIsEmty = true;
	}
	return blnIsEmty;
}
//Name: Print
//Abstract: Prints Stack values with index/location
template<typename GenericDataType>
void CStack<GenericDataType>::Print(const char* pstrCaption) const	// This will print the whole list.
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
		cout << "emty stack" << endl;
	}
}
// It is non-destructive.  
// You can call it over and over

//Name: DeepCopy
//Abstract: executes DeepCopy
template<typename GenericDataType>
void CStack<GenericDataType>::DeepCopy(const CStack<GenericDataType>& clsOriginalToCopy)
{
	CNode<GenericDataType>* pclsCurrentOriginal = 0;
	GenericDataType intValue = 0;
	CNode<GenericDataType>* pclsNextNode = 0;

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


#endif