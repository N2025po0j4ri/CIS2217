// --------------------------------------------------------------------------------
// Name: Nirupama Poojari
// Class: C++ 2
// Abstract: Homework 10
// --------------------------------------------------------------------------------

#include "CNode.h"


//Name: Constructor
//Abstract: No parameter Constructor
CNode :: CNode()	// Default constructor
{
	//m_intValue = 0;
	//m_pclsNextNode = 0;
	Initialize(0, 0);
}
//Name: Constructor
//Abstract:Parameterized constructor #1
CNode :: CNode(int intValue)	// Parameterized constructor #1
{
	//m_intValue = intValue;
	//m_pclsNextNode = 0;
	Initialize(intValue, 0);
}
//Name: Constructor
//Abstract:Parameterized constructor #2
CNode :: CNode(int intValue, CNode* pclsNextNode)	// Parameterized constructor #2
{
	//m_intValue = intValue;
	//m_pclsNextNode = pclsNextNode;
	Initialize(intValue, pclsNextNode);
}
//Name: Copy Constructor
//Abstract:shallow copy
CNode :: CNode(const CNode& clsOriginalToCopy)	// Copy constructor with shallow copy! 
{
	//m_intValue = clsOriginalToCopy.m_intValue;
	//m_pclsNextNode = clsOriginalToCopy.m_pclsNextNode;
	Initialize(0,0);
	*this = clsOriginalToCopy;
	
}
//Name: CleanUp
//Abstract: executes clean up
void CNode::CleanUp()
{
	
}
//Name: Destructor
//Abstract: calls clean up
CNode :: ~CNode()
{
	CleanUp();
}
//Name: Initialize
//Abstract: executes initialization
void CNode :: Initialize(int intNewValue, CNode* pclsNextNode)	// 
{
	/* CNode::SetValue(intValue);
	CNode::SetNextNode( pclsNextNode); */
	m_intValue = intNewValue;
	m_pclsNextNode = pclsNextNode;
}
//Name: operator =
//Abstract:Shallow copy! 
void CNode :: operator = (const CNode &clsOriginalToCopy)	// Shallow copy! 
{
	ShallowCopy(clsOriginalToCopy);
	
} 
//Name: SetValue
//Abstract:Set Value
void CNode::SetValue(int intNewValue)
{
	m_intValue = intNewValue;
}
//Name: GetValue
//Abstract:Get Value
int CNode::GetValue()
{
	return m_intValue;
}

//Name: SetNextNode
//Abstract:Set Next Node

void CNode::SetNextNode(CNode * pclsNextNode)
{
	m_pclsNextNode = pclsNextNode;
}
//Name: GetNextNode
//Abstract:Get Next Node
CNode* CNode:: GetNextNode()
{
	return m_pclsNextNode;
}


//Name: ShallowCopy 
//Abstract:ShallowCopy
void CNode:: ShallowCopy(const CNode& clsOriginalToCopy) {
	//CNode *pclsNewNode = new CNode(clsOriginalToCopy);
	//return *pclsNewNode;
	m_intValue = clsOriginalToCopy.m_intValue;
	m_pclsNextNode = clsOriginalToCopy.m_pclsNextNode;
}
