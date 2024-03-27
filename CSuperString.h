#pragma once
//-----------------------------
//Compiler Directives
//----------------------------------
#ifndef CSUPER_STRING_H
#define CSUPER_STRING_H

//----------------------------------
// Includes
//----------------------------------
// --------------------------------------------------------------------------------
// Class: CSuperString 
// --------------------------------------------------------------------------------
#include <stdlib.h>
#include <iostream>
using namespace std;

class CSuperString
{
//-----------------------------
// Properties
//----------------------------------
public:
protected:
	char* m_pstrSuperString;
	char* m_pstrToUpperCase;
	char* m_pstrToLowerCase;
	char* m_pstrTrimLeft;
	char* m_pstrTrimRight;
	char* m_pstrTrim;
	char* m_pstrReverse;
	char* m_pstrLeft;
	//char* m_pstrLeft2;

private:
//-----------------------------
// Methods
//----------------------------------
public:
	// Constructors
	CSuperString();
	// Parameterized/Copy constructors
	// CSuperString ssBuffer( "I Love Star Trek" );
	// CSuperString ssBuffer( 3.14159f );
	CSuperString(const char* pstrStringToCopy);
	CSuperString(const bool blnBooleanToCopy);
	CSuperString(const char chrLetterToCopy);
	CSuperString(const short shtShortToCopy);
	CSuperString(const int intIntegerToCopy);
	CSuperString(const long lngLongToCopy);
	CSuperString(const float sngFloatToCopy);
	CSuperString(const double dblDoubleToCopy); 
	CSuperString(const CSuperString &ssStringToCopy);

	// Destructor
	virtual ~CSuperString();

	long Length() const;

	// Assignment Operators
	CSuperString &operator = (const char* pstrStringToCopy);
	CSuperString &operator = (const bool blnBooleanToCopy);
	CSuperString &operator = (const char chrLetterToCopy);
	CSuperString &operator = (const short shtShortToCopy);
	CSuperString &operator = (const int intIntegerToCopy);
	CSuperString &operator = (const long lngLongToCopy);
	CSuperString &operator = (const float sngFloatToCopy);
	CSuperString &operator = (const double dblDoubleToCopy);
	CSuperString &operator = (const CSuperString& ssStringToCopy);
//	CSuperString  operator = (const CSuperString ssStringToCopy);

	/*	void operator = (const CSuperString& ssStringToCopy);
	// Extra credit for numeric parameters

	// Concatenate operator
	void operator += (const char* pstrStringToAppend);
	void operator += (const char chrCharacterToAppend);
	void operator += (const CSuperString& ssStringToAppend);
	// Extra credit for numeric parameters

	friend CSuperString operator + (const CSuperString& ssLeft,
		const CSuperString& ssRight);
	friend CSuperString operator + (const char* pstrLeftSide,
		const CSuperString& ssRightString);
	friend CSuperString operator + (const CSuperString& ssLeftString,
		const char* pstrRightSide);

	long FindFirstIndexOf(const char chrLetterToFind);
	long FindFirstIndexOf(const char chrLetterToFind, long lngStartIndex);
	long FindLastIndexOf(const char chrLetterToFind);

	long FindFirstIndexOf(const char* pstrSubStringToFind);
	long FindFirstIndexOf(const char* pstrSubStringToFind, long lngStartIndex);
	long FindLastIndexOf(const char* pstrSubStringToFind); */

	// Do not change original string.  For example:
	// cout << ssBuffer.ToString( ) << endl;		// I Love Star Trek
	// cout << ssBuffer.ToUpperCase( ) << endl;	// I LOVE STAR TREK
	// cout << ssBuffer.ToString( ) << endl;		// I Love Star Trek
//	const char* ToUpperCase();
	CSuperString ToUpperCase();
	const char* ToLowerCase();
	const char* TrimLeft();
	const char* TrimRight();
	const char* Trim(); 
	const char* Reverse(); 

	CSuperString Left(long lngCharactersToCopy);
	CSuperString Replace(const char* pstrFind, const char* pstrReplace);
//	const char* Left(long lngCharactersToCopy);
/* 	const char* Right(long lngCharactersToCopy);
	const char* Substring(long lngStart, long lngSubStringLength);

	const char* Replace(char chrLetterToFind, char chrReplace);
	// Hard
	const char* Replace(const char* pstrFind, const char* pstrReplace);
	const char* Insert(const char chrLetterToInsert, long lngIndex);
	const char* Insert(const char* pstrSubString, long lngIndex);

	// Subscript operator
	char& operator [ ] (long lngIndex);
	const char& operator [ ] (long lngIndex) const; */

	const char* ToString() const;
	 bool ToBoolean();
	 short ToShort();
	int ToInteger();
	long ToLong();
	 float ToFloat();
	double ToDouble();
	/*
	// cin >> ssBuffer;
	// cout << ssBuffer;
	friend ostream& operator << (ostream& osOut, const CSuperString& ssOutput);
	friend istream& operator >> (istream& isIn, CSuperString& ssInput);

	// Don’t forget the comparison operators!!! */
	//void Print(const char* pstrCaption) const; not compiling
	void Print(const char* pstrCaption);
protected:
	void Initialize(const char* pstrSource); // called by Constructor
	void DeepCopy(const char* pstrSource); // called by assignment
	void CleanUp(); // called by Destructor
	void DeleteString(const char* pstrSource);
	//void DeleteString(const char*& pstrSource); not compiling
	//error C2664: 'void CSuperString::DeleteString(const char *&)': cannot convert argument 1 from 'char' to 'const char *&'
	char* CloneString(const char* pstrSource);
};

#endif