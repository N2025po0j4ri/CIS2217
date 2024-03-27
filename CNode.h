// --------------------------------------------------------------------------------
// Name: CNode
// Abstract: This is CNode class 
// --------------------------------------------------------------------------------

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