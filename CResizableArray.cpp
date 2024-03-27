// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: Class method definitions
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
using namespace std;
#include "CResizableArray.h"

//Name: Constructor taking no args
//Abstract: calls Initialize
CResizableArray::CResizableArray()
{
	Initialize(1,0);

}
//Name: Constructor taking 1 arg
//Abstract: calls Initialize
CResizableArray::CResizableArray(long lngInitialSize)
{
	Initialize(lngInitialSize, 0);
}

//Name: Constructor taking 2 args
//Abstract: calls Initialize
CResizableArray::CResizableArray(long lngInitialSize, long lngDefaultValue)
{
	Initialize(lngInitialSize, lngDefaultValue);
} 

CResizableArray::CResizableArray(const CResizableArray& clsOriginalToCopy)
{
	Initialize(1, 0);
	*this = clsOriginalToCopy;
}

//Name: Destructor
//Abstract: calls Cleanup
CResizableArray::~CResizableArray()
{
	Cleanup();
}
//Name: Cleanup
//Abstract: Cleanup
void CResizableArray::Cleanup()
{
	SetSize(0);
}
//Name: DeepCopy
//Abstract: DeepCopy
void CResizableArray::DeepCopy(const CResizableArray& clsOriginalToCopy)
{
	SetSize(clsOriginalToCopy.m_lngArraySize);
}

void CResizableArray::operator [] ( long lngIndex)
{
	SetValueAt( lngIndex,0);
}
void CResizableArray::operator = (const CResizableArray& clsOriginalToCopy)
{
	// Self assignment?  Compare instance addresses
	if (this != &clsOriginalToCopy)
	{
		// No, copy
		Cleanup();
		DeepCopy(clsOriginalToCopy.m_lngArraySize);
	}

}
void CResizableArray::operator += (const CResizableArray& clsOriginalToAppend)
{
	if (m_lngArraySize > 0 && clsOriginalToAppend.m_lngArraySize > m_lngArraySize)
	{
		long* m_palngValuesTemp = new long[clsOriginalToAppend.m_lngArraySize + m_lngArraySize];

		for (long lngIndex = 0; lngIndex < m_lngArraySize; lngIndex += 1)
		{
			*(m_palngValuesTemp + lngIndex) = *(m_palngValues + lngIndex);
		}
		long lngIndex = m_lngArraySize;
		
		for (long origIndex = 0; origIndex < clsOriginalToAppend.m_lngArraySize; origIndex += 1)
		{
			*(m_palngValuesTemp + lngIndex) = *(clsOriginalToAppend.m_palngValues + origIndex);
		}
		delete m_palngValues;
		m_palngValues = m_palngValuesTemp;
		m_lngArraySize = m_lngArraySize + clsOriginalToAppend.m_lngArraySize;
	}
}
CResizableArray CResizableArray::operator + (const CResizableArray& clsRight) const
{
	if (m_lngArraySize > 0 && clsRight.m_lngArraySize > m_lngArraySize)
	{
		long* m_palngValuesTemp = new long[clsRight.m_lngArraySize + m_lngArraySize];

		for (long lngIndex = 0; lngIndex < m_lngArraySize; lngIndex += 1)
		{
			*(m_palngValuesTemp + lngIndex) = *(m_palngValues + lngIndex);
		}
		long lngIndex = m_lngArraySize;

		for (long origIndex = 0; origIndex < clsRight.m_lngArraySize; origIndex += 1)
		{
			*(m_palngValuesTemp + lngIndex) = *(clsRight.m_palngValues + origIndex);
		}
		//delete m_palngValues;
//		m_palngValues = m_palngValuesTemp;
//		m_lngArraySize = m_lngArraySize + clsRight.m_lngArraySize;
	}
	return *this;
}
//Name: SetName
//Abstract: Set Name
void CResizableArray::Initialize(long lngInitialSize, long lngDefaultValue)
{
	long lngIndex = 0;
	SetSize(lngInitialSize);
	// Initialize array
	for (lngIndex = 0; lngIndex < m_lngArraySize; lngIndex += 1)
	{
		*(m_palngValues + lngIndex) = lngDefaultValue;
	}

}

//Name: GetSize
//Abstract: GetSize
const long CResizableArray::GetSize()
{
	return m_lngArraySize;
}

//Name: SetSize
//Abstract: SetSize
void CResizableArray::SetSize(long lngNewSize)
{
	if (lngNewSize < 0)
	{
		lngNewSize = 0;
	}
	
	if (m_lngArraySize > 0 && lngNewSize > m_lngArraySize)
	{
		long* m_palngValuesTemp = new long[lngNewSize];
		
		for (long lngIndex = 0; lngIndex < m_lngArraySize ; lngIndex += 1)
		{
			*(m_palngValuesTemp + lngIndex) = *(m_palngValues + lngIndex );
		}
		
		for (long lngIndex = m_lngArraySize; lngIndex < lngNewSize; lngIndex += 1)
		{
			*(m_palngValuesTemp + lngIndex) = 0;
		}
		delete m_palngValues;
		m_palngValues = m_palngValuesTemp;
		m_lngArraySize = lngNewSize;
	}
	else {
		m_lngArraySize = lngNewSize;
		// Make array
		m_palngValues = new long[m_lngArraySize];
	}
}

//Name: GetWeight
//Abstract: Get Weight
const long CResizableArray::GetValueAt(long lngIndex)
{
	if (lngIndex < 0)
	{
		lngIndex = 0;
	}
	return *(m_palngValues + lngIndex);
}

void CResizableArray::SetValueAt(long lngValue, long lngIndex)
{
	if (lngIndex < 0)
	{
		lngIndex = 0;
	}
	else if (lngIndex >= m_lngArraySize) {
		lngIndex = m_lngArraySize - 1;
	}
	*(m_palngValues + lngIndex) = lngValue;
}

void CResizableArray::AddValueToFront(long lngValue) {
	long* m_palngValuesTemp = new long[m_lngArraySize +1 ];
	*(m_palngValuesTemp) = lngValue;
	for (long lngIndex = 1; lngIndex < m_lngArraySize +1; lngIndex += 1)
	{
		*(m_palngValuesTemp + lngIndex) = *(m_palngValues + lngIndex -1);
	}
	delete m_palngValues;
	m_palngValues = m_palngValuesTemp;
	m_lngArraySize = m_lngArraySize + 1;
}
void CResizableArray::AddValueToEnd(long lngValue) {
	long* m_palngValuesTemp = new long[m_lngArraySize + 1];
	
	for (long lngIndex = 0; lngIndex < m_lngArraySize ; lngIndex += 1)
	{
		*(m_palngValuesTemp + lngIndex) = *(m_palngValues + lngIndex );
	}
	for (long lngIndex = 0; lngIndex < m_lngArraySize ; lngIndex += 1)
	*(m_palngValuesTemp + m_lngArraySize) = lngValue;
	delete m_palngValues;
	m_palngValues = m_palngValuesTemp;
	m_lngArraySize = m_lngArraySize + 1;
}
void CResizableArray::InsertValueAt(long lngValue, long lngIndex) {
	long* m_palngValuesTemp = new long[m_lngArraySize + 1];
	if (lngIndex < 0)
	{
		lngIndex = 0;
	}
	else if (lngIndex >= m_lngArraySize) {
		lngIndex = m_lngArraySize - 1;
	}
	for (long i = 0; i < lngIndex; i += 1)
	{
		*(m_palngValuesTemp + i) = *(m_palngValues + i);
	}
	*(m_palngValuesTemp + lngIndex) = lngValue;
	for (long i = lngIndex ; i < m_lngArraySize; i += 1)
	{
		*(m_palngValuesTemp + i + 1) = *(m_palngValues + i);
	}
	delete m_palngValues;
	m_palngValues = m_palngValuesTemp;
	m_lngArraySize = m_lngArraySize + 1;
}
void CResizableArray::RemoveAt(long lngIndex) {
	if (lngIndex < 0)
	{
		lngIndex = 0;
	}
	else if (lngIndex >= m_lngArraySize) {
		lngIndex = m_lngArraySize - 1;
	}
	long* m_palngValuesTemp = new long[m_lngArraySize - 1];
	for (long i = 0; i < lngIndex; i += 1)
	{
		*(m_palngValuesTemp + i) = *(m_palngValues + i);
	}
	for (long i = lngIndex; i < m_lngArraySize -1; i += 1)
	{
		*(m_palngValuesTemp + i ) = *(m_palngValues + i+1);
	}
	delete m_palngValues;
	m_palngValues = m_palngValuesTemp;
	m_lngArraySize = m_lngArraySize - 1;
}

const void CResizableArray::Print() {
	long lngIndex = 0;

	// Print array
	cout << "Print Array: " << endl;
	for (lngIndex = 0; lngIndex < m_lngArraySize; lngIndex += 1)
	{
		cout << "Value[ " << lngIndex  << " ] = " << *(m_palngValues + lngIndex) << endl;
	}
	cout << endl;

}
