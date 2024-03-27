// --------------------------------------------------------------------------------
// Name: CResizableArray
// Abstract: A resizeable array class with all the inner workings hidden.
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;

//Declare only once even if included multiple times
#ifndef CRESIZABLE_ARRAY_H
#define CRESIZABLE_ARRAY_H

template<typename GenericDataType>
class CResizableArray
{
	// --------------------------------------------------------------------------------
	// Constants
	// --------------------------------------------------------------------------------

	// --------------------------------------------------------------------------------
	// Properties
	// --------------------------------------------------------------------------------
	public:			// Never make public properties.  
					// Make protected or private with public get/set methods

	protected:
			long m_lngArraySize;
			GenericDataType* m_palngValues;//long* m_palngValues;

	private:

	// --------------------------------------------------------------------------------
	// Methods
	// --------------------------------------------------------------------------------
	public:
			// Constructors
			CResizableArray( );
			CResizableArray( long lngInitialSize );
			CResizableArray( long lngInitialSize, GenericDataType lngDefaultValue );
			CResizableArray( const CResizableArray &clsOriginalToCopy );

			// Destructor
			~CResizableArray( );

			// Assignment Operator
			void operator = ( const CResizableArray &clsOriginalToCopy );

			// Subscript Operator
			GenericDataType &operator[ ]( long lngIndex );				// Set
			const GenericDataType &operator[ ]( long lngIndex ) const;	// Get - read only

			// Plus Equal +=
			void operator += ( const CResizableArray &clsOriginalToAppend );

			// Plus +
			CResizableArray operator + ( const CResizableArray &clsRight ) const;

			// Set/Get Size
			void SetSize( long lngNewSize );
			void SetSize( long lngNewSize, GenericDataType lngDefaultValue );
			long GetSize( ) const;

			// Set/Get Value
			void SetValueAt(GenericDataType lngValue, long lngIndex );
			GenericDataType GetValueAt( long lngIndex ) const;

			// Add to Front/End
			void AddValueToFront(GenericDataType lngValueToAdd );
			void AddValueToEnd(GenericDataType lngValueToAdd );
			
			// Insert At
			void InsertValueAt(GenericDataType lngValueToInsert, long lngInsertAtIndex );

			// Remove At
			void RemoveAt( long lngRemoveAtIndex );

			// Print
			void Print( ) const;
			void Print( const char* pstrCaption ) const;

	protected:
			// Can't touch this
			void Initialize( long lngInitialSize, GenericDataType lngDefaultValue );
			void DeepCopy( const CResizableArray &clsOriginalToCopy );
			void CleanUp( );

	private:

};
//#include "CResizableArray.cpp"
#include <stdlib.h>
#include <iostream>
// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Default constructor
// --------------------------------------------------------------------------------
template<typename GenericDataType>
CResizableArray<GenericDataType> ::CResizableArray<GenericDataType>()
{
	Initialize(0, 0);
}


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Parameterized constructor
// --------------------------------------------------------------------------------
template<typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray<GenericDataType>(long lngInitialSize)
{
	Initialize(lngInitialSize, 0);
}


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Parameterized constructor
// --------------------------------------------------------------------------------
template<typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray<GenericDataType>(long lngInitialSize, GenericDataType lngDefaultValue)
{
	Initialize(lngInitialSize, lngDefaultValue);
}


// --------------------------------------------------------------------------------
// Name: Constructor
// Abstract: Parameterized constructor
// --------------------------------------------------------------------------------
template<typename GenericDataType>
CResizableArray<GenericDataType>::CResizableArray<GenericDataType>(const CResizableArray<GenericDataType>& clsOriginalToCopy)
{
	Initialize(0, 0);

	*this = clsOriginalToCopy;
}


// --------------------------------------------------------------------------------
// Name: Initialize
// Abstract: Set class properties to zero
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::Initialize(long lngInitialSize, GenericDataType lngDefaultValue)
{
	m_lngArraySize = 0;
	m_palngValues = 0;

	SetSize(lngInitialSize, lngDefaultValue);
}


// --------------------------------------------------------------------------------
// Name: Assignment operator
// Abstract: Perform a deep copy
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::operator = (const CResizableArray<GenericDataType>& clsOriginalToCopy)
{
	// Self assignment?  Compare instance addresses
	if (this != &clsOriginalToCopy)
	{
		// No, clean up and copy
		CleanUp();
		DeepCopy(clsOriginalToCopy);
	}
}


// --------------------------------------------------------------------------------
// Name: DeepCopy
// Abstract: Because we have pointers to dynamically allocated memory
//		we must manually allocate duplicate blocks and copy all of the values
//		in the original blocks of memory to the copy instance.  This is
//		known as a deep copy.  The default behavior is a shallow copy.
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::DeepCopy(const CResizableArray<GenericDataType>& clsOriginalToCopy)
{
	long lngSize = 0;
	long lngIndex = 0;

	// How big?
	lngSize = clsOriginalToCopy.GetSize();

	// Allocate space
	SetSize(lngSize);

	// Deep copy
	for (lngIndex = 0; lngIndex < lngSize; lngIndex += 1)
	{
		(*this)[lngIndex] = clsOriginalToCopy[lngIndex];
	}
}


// --------------------------------------------------------------------------------
// Name: Destructor
// Abstract: Destructor
// --------------------------------------------------------------------------------
template<typename GenericDataType>
CResizableArray<GenericDataType>::~CResizableArray<GenericDataType>()
{
	CleanUp();
}


// --------------------------------------------------------------------------------
// Name: CleanUp
// Abstract: This place is a mess.
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::CleanUp()
{
	SetSize(0, 0);
}


// --------------------------------------------------------------------------------
// Name: subscript operator - set
// Abstract: return pointer to long 
// --------------------------------------------------------------------------------
template<typename GenericDataType>
GenericDataType& CResizableArray<GenericDataType>::operator[ ](long lngIndex)
{
	GenericDataType* plngValue = 0;

	// Size not 0?
	if (m_lngArraySize > 0)
	{
		// Yes, boundary check the index
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		// Get the address
		plngValue = m_palngValues + lngIndex;
	}

	return *plngValue;
}


// --------------------------------------------------------------------------------
// Name: subscript operator - get
// Abstract: return const pointer to long - read only
// --------------------------------------------------------------------------------
template<typename GenericDataType>
const GenericDataType& CResizableArray<GenericDataType>::operator[ ](long lngIndex) const
{
	GenericDataType* plngValue = 0;

	// Size not 0?
	if (m_lngArraySize > 0)
	{
		// Yes, boundary check the index
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		// Get the address
		plngValue = m_palngValues + lngIndex;
	}

	return *plngValue;
}


// --------------------------------------------------------------------------------
// Name: Plus Equal
// Abstract: Append the other array
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::operator += (const CResizableArray<GenericDataType>& clsOriginalToAppend)
{
	long lngNewSize = 0;
	GenericDataType* palngNewValues = 0;
	long lngSourceIndex = 0;
	long lngDestinationIndex = 0;

	// New size?
	lngNewSize = GetSize() + clsOriginalToAppend.GetSize();

	// Do not call SetSize because could be appending self

	// Allocate space
	palngNewValues = new GenericDataType[lngNewSize];	// Not a string so no +1 for terminator

	// Copy 1st half
	for (lngSourceIndex = 0; lngSourceIndex < GetSize(); lngSourceIndex += 1)
	{
		palngNewValues[lngDestinationIndex] = (*this)[lngSourceIndex];
		lngDestinationIndex += 1;
	}

	// Copy 2nd half
	for (lngSourceIndex = 0; lngSourceIndex < clsOriginalToAppend.GetSize(); lngSourceIndex += 1)
	{
		palngNewValues[lngDestinationIndex] = clsOriginalToAppend[lngSourceIndex];
		lngDestinationIndex += 1;
	}

	// Delete old memory
	CleanUp();

	// Assign new array
	m_palngValues = palngNewValues;
	m_lngArraySize = lngNewSize;
}


// --------------------------------------------------------------------------------
// Name: Plus
// Abstract: Append the other array
// --------------------------------------------------------------------------------
template<typename GenericDataType>
CResizableArray<GenericDataType> CResizableArray<GenericDataType>::operator + (const CResizableArray<GenericDataType>& clsRight) const
{
	CResizableArray<GenericDataType> clsLeftAndRight;

	clsLeftAndRight = *this;		// Left
	clsLeftAndRight += clsRight;	// Right

	return clsLeftAndRight;
}


// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Resize the array
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::SetSize(long lngNewSize)
{
	SetSize(lngNewSize, 0);
}


// --------------------------------------------------------------------------------
// Name: SetSize
// Abstract: Resize the array
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::SetSize(long lngNewSize, GenericDataType lngDefaultValue)
{
	GenericDataType* palngNewValues = 0;
	long lngIndex = 0;
	long lngStop = 0;

	// Boundary check inputs
	if (lngNewSize < 0) lngNewSize = 0;
	if (lngNewSize > 100000) lngNewSize = 100000;

	// Did the size change?
	if (lngNewSize != m_lngArraySize)
	{
		// Yes, is it larger than 0?
		if (lngNewSize > 0)
		{
			// Yes, allocate space
			palngNewValues = new GenericDataType[lngNewSize];
		}

		// Initialize new memory
		for (lngIndex = 0; lngIndex < lngNewSize; lngIndex += 1)
		{
			// (Base pointer + offset)
			*(palngNewValues + lngIndex) = lngDefaultValue;
		}

		// How many values can we preserve?
		if (lngNewSize < m_lngArraySize) lngStop = lngNewSize;
		else							  lngStop = m_lngArraySize;

		// Copy values from old array into new array
		for (lngIndex = 0; lngIndex < lngStop; lngIndex += 1)
		{
			*(palngNewValues + lngIndex) = *(m_palngValues + lngIndex);
		}

		// Delete old array
		if (m_palngValues != 0)
		{
			delete[] m_palngValues;
			m_palngValues = 0;
		}

		// Assign new array
		m_palngValues = palngNewValues;

		// Assign new size
		m_lngArraySize = lngNewSize;
	}

}


// --------------------------------------------------------------------------------
// Name: GetSize
// Abstract: How big is the array
// --------------------------------------------------------------------------------
template<typename GenericDataType>
long CResizableArray<GenericDataType>::GetSize() const
{
	return m_lngArraySize;
}


// --------------------------------------------------------------------------------
// Name: SetValueAt
// Abstract: Set the value at the specified location
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::SetValueAt(GenericDataType lngValue, long lngIndex)
{
	// Size not 0?
	if (m_lngArraySize > 0)
	{
		// Yes, boundary check the index
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		// Set the value
		*(m_palngValues + lngIndex) = lngValue;
	}
}


// --------------------------------------------------------------------------------
// Name: GetValueAt
// Abstract: Return the value at the specified location
// --------------------------------------------------------------------------------
template<typename GenericDataType>
GenericDataType CResizableArray<GenericDataType>::GetValueAt(long lngIndex) const
{
	GenericDataType lngValue = 0;

	// Size not 0?
	if (m_lngArraySize > 0)
	{
		// Yes, boundary check the index
		if (lngIndex < 0) lngIndex = 0;
		if (lngIndex > m_lngArraySize - 1) lngIndex = m_lngArraySize - 1;

		// Get the value
		lngValue = *(m_palngValues + lngIndex);
	}

	return lngValue;
}


// --------------------------------------------------------------------------------
// Name: AddValueToFront
// Abstract: Add a value to the front
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::AddValueToFront(GenericDataType lngValueToAdd)
{
	InsertValueAt(lngValueToAdd, 0);
}



// --------------------------------------------------------------------------------
// Name: AddValueToEnd
// Abstract: Add a value to the End
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::AddValueToEnd(GenericDataType lngValueToAdd)
{
	InsertValueAt(lngValueToAdd, GetSize());
}



// --------------------------------------------------------------------------------
// Name: InsertValueAt
// Abstract: Insert a value in the middle
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::InsertValueAt(GenericDataType lngValueToInsert, long lngInsertAtIndex)
{
	long* palngNewValues = 0;
	long lngIndex = 0;

	// Boundary check index
	if (lngInsertAtIndex < 0) lngInsertAtIndex = 0;
	if (lngInsertAtIndex > m_lngArraySize) lngInsertAtIndex = m_lngArraySize;

	// Make a new array of size one larger
	palngNewValues = new long[GetSize() + 1];

	// Copy 1st half of values from old array into new array
	for (lngIndex = 0; lngIndex < lngInsertAtIndex; lngIndex += 1)
	{
		// Old-school C pointer way
		*(palngNewValues + lngIndex) = *(m_palngValues + lngIndex);
	}

	// Insert
	*(palngNewValues + lngInsertAtIndex) = lngValueToInsert;

	// Copy 2nd half of values from old array into new array
	for (lngIndex = lngInsertAtIndex; lngIndex < GetSize(); lngIndex += 1)
	{
		// Old-school C pointer way
		*(palngNewValues + lngIndex + 1) = *(m_palngValues + lngIndex);
	}

	// Delete old array
	delete[] m_palngValues;
	m_palngValues = 0;

	// Assign new array
	m_palngValues = palngNewValues;

	// Assign size
	m_lngArraySize += 1;
}


// --------------------------------------------------------------------------------
// Name: RemoveAt
// Abstract: Remove a value at the specified index
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::RemoveAt(long lngRemoveAtIndex)
{
	long* palngNewValues = 0;
	long lngIndex = 0;

	// Is there anything to remove?
	if (GetSize() > 0)
	{
		// Yes

		// Boundary check index
		if (lngRemoveAtIndex < 0) lngRemoveAtIndex = 0;
		if (lngRemoveAtIndex > m_lngArraySize - 1) lngRemoveAtIndex = m_lngArraySize - 1;

		// Make a new array of size one smaller
		palngNewValues = new long[GetSize() - 1];

		// Copy 1st half of values from old array into new array
		for (lngIndex = 0; lngIndex < lngRemoveAtIndex; lngIndex += 1)
		{
			// Old-school C pointer way
			*(palngNewValues + lngIndex) = *(m_palngValues + lngIndex);
		}

		// Copy 2nd half of values from old array into new array
		for (lngIndex = lngRemoveAtIndex + 1; lngIndex < GetSize(); lngIndex += 1)
		{
			// Old-school C pointer way
			*(palngNewValues + lngIndex - 1) = *(m_palngValues + lngIndex);
		}

		// Delete old array
		delete[] m_palngValues;
		m_palngValues = 0;

		// Assign new array
		m_palngValues = palngNewValues;

		// Assign size
		m_lngArraySize -= 1;
	}
}


// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Print all the values
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::Print() const
{
	Print("Print Array");
}


// --------------------------------------------------------------------------------
// Name: Print
// Abstract: Print all the values
// --------------------------------------------------------------------------------
template<typename GenericDataType>
void CResizableArray<GenericDataType>::Print(const char* pstrCaption) const
{
	long lngIndex = 0;

	// Caption
	cout << endl;
	cout << pstrCaption << " ----------" << endl;

	// Size not 0?
	if (m_lngArraySize > 0)
	{

		// Print each cell
		for (lngIndex = 0; lngIndex < GetSize(); lngIndex += 1)
		{
			cout << "Location[ " << (lngIndex + 1) << " ] = "
				<< GetValueAt(lngIndex) << endl;
		}
	}
	else
	{
		printf("-Empty array\n");
	}

	cout << endl;

}


#endif
