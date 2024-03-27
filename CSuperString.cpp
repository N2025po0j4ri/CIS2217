#define _CRT_SECURE_NO_WARNINGS
#include "CSuperString.h"
#include "CQueue.h"

//----------------------------------
// Name: Constructor
// Abstract: Default Constructor
//----------------------------------
CSuperString::CSuperString()
{
	Initialize("");
}
//----------------------------------
// Name: Parameterized Constructor #1
// Abstract: const char*
//----------------------------------
CSuperString::CSuperString(const char* pstrStringToCopy)
{
	Initialize(pstrStringToCopy);
	*this = pstrStringToCopy;
}


//----------------------------------
// Name: Parameterized Constructor #2
// Abstract: boolean
//----------------------------------
CSuperString::CSuperString(const bool blnBooleanToCopy)
{
	Initialize("");
	/* if (blnBooleanToCopy == true)
	{
		*this = "true";
	}
	else
	{
		*this = "false";
	}*/
	*this = blnBooleanToCopy;
}

//----------------------------------
// Name: Parameterized Constructor #3
// Abstract: char
//----------------------------------
CSuperString::CSuperString(const char chrLetterToCopy)
{
	//char strSource[2] = { chrLetterToCopy ,0 };
	//Initialize(chrLetterToCopy);
	Initialize("");
	*this = chrLetterToCopy;
}

//----------------------------------
// Name: Parameterized Constructor #4
// Abstract: short
//----------------------------------
CSuperString::CSuperString(const short shtShortToCopy)
{
	//32767 = 5 digits + 1 digit for sign (+/-) + 1 digit for terminator + 1 for caution = 8
	/* char strSource[8] = "";
	sprintf_s(strSource, "%hd", shtShortToCopy); */
	//Initialize(shtShortToCopy);
	Initialize("");
	*this = shtShortToCopy;
}

//----------------------------------
// Name: Parameterized Constructor #5
// Abstract: int
//----------------------------------
CSuperString::CSuperString(const int intIntegerToCopy)
{
	//2147483647 = 10 digits + 1 digit for sign (+/-) + 1 digit for terminator + 1 for caution = 13
	/* char strSource[13] = "";
	sprintf_s(strSource, "%d", intIntegerToCopy);
	Initialize(strSource); */
	Initialize("");
	*this = intIntegerToCopy;
}

//----------------------------------
// Name: Parameterized Constructor #6
// Abstract: long
//----------------------------------
CSuperString::CSuperString(const long lngLongToCopy)
{
	/* char strSource[13] = "";
	sprintf_s(strSource, "%ld", lngLongToCopy);
	Initialize(strSource); */
	Initialize("");
	*this = lngLongToCopy;
}

//----------------------------------
// Name: Parameterized Constructor #7
// Abstract: float
//----------------------------------
CSuperString::CSuperString(const float sngFloatToCopy)
{
	/* char strSource[100] = "";
	sprintf_s(strSource, "%f", sngFloatToCopy);
	Initialize(strSource); */
	Initialize("");
	*this = sngFloatToCopy;
}

//----------------------------------
// Name: Parameterized Constructor #8
// Abstract: double
//----------------------------------
CSuperString::CSuperString(const double dblDoubleToCopy)
{
	/* char strSource[100] = "";
	sprintf_s(strSource, "%9.5e", dblDoubleToCopy);
	Initialize(strSource); */
	Initialize("");
	*this = dblDoubleToCopy;
}


//----------------------------------
// Name: Constructor
// Abstract: Copy Constructor
//----------------------------------
CSuperString::CSuperString( const CSuperString &ssStringToCopy)
{
	Initialize(ssStringToCopy.ToString());
}
//----------------------------------
// Name: Initialize
// Abstract: 
//----------------------------------
void CSuperString:: Initialize(const char* pstrSource) // called by Constructor
{
	DeepCopy(pstrSource);
//	m_pstrSuperString = 0;
	m_pstrToUpperCase = 0;
	m_pstrToLowerCase = 0;
	m_pstrTrimLeft = 0;
	m_pstrTrimRight = 0;
	m_pstrTrim = 0;
	m_pstrReverse = 0;
	m_pstrLeft = 0;
	//*this = pstrSource;
}

//----------------------------------
// Name: Length
// Abstract: 
//----------------------------------
long CSuperString::Length() const// called by Constructor
{
	long lngLength = 0;
	lngLength = (long)strlen(m_pstrSuperString);
	return lngLength;
}
//----------------------------------
// Name: operator = 
// Abstract: 
//----------------------------------
CSuperString &CSuperString::operator = (const char* pstrStringToCopy)
{
//	if (m_pstrSuperString != pstrStringToCopy)
//	{
		//CleanUp();
		DeepCopy(pstrStringToCopy);
//	}
	return *this;
}
CSuperString &CSuperString::operator = (const bool blnBooleanToCopy)
{
	if (blnBooleanToCopy == true)
	{
		CleanUp();
		DeepCopy("true");
	}
	else
	{
		CleanUp();
		DeepCopy("false");
	}
	return *this;
}
//----------------------------------
// Name: 
// Abstract: 
//----------------------------------
CSuperString& CSuperString::operator = (const char chrLetterToCopy)
{
	char strSource[2] = { chrLetterToCopy ,0 };
	DeepCopy(strSource);
	return *this;
}
CSuperString& CSuperString::operator = (const int intIntegerToCopy)
{
	char strSource[13] = "";
	sprintf_s(strSource, "%d", intIntegerToCopy);
	DeepCopy(strSource);
	return *this;
}
CSuperString& CSuperString::operator = (const short shtShortToCopy)
{
	char strSource[8] = "";
	sprintf_s(strSource, "%hd", shtShortToCopy);
	DeepCopy(strSource);
	return *this;
}
CSuperString& CSuperString::operator = (const long lngLongToCopy)
{
	char strSource[13] = "";
	sprintf_s(strSource, "%ld", lngLongToCopy);
	DeepCopy(strSource);
	return *this;
}
CSuperString& CSuperString::operator = (const float sngFloatToCopy)
{
	char strSource[100] = "";
	sprintf_s(strSource, "%f", sngFloatToCopy);
	DeepCopy(strSource);
	return *this;
}
CSuperString& CSuperString::operator = (const double dblDoubleToCopy)
{
	char strSource[100] = "";
	sprintf_s(strSource, "%9.5e", dblDoubleToCopy);
	DeepCopy(strSource);
	return *this;
}
CSuperString& CSuperString::operator = (const CSuperString& ssStringToCopy)
{
	DeepCopy(ssStringToCopy.m_pstrSuperString);
	return *this;
}
//----------------------------------
// Name: operator = DeepCopy
// Abstract: 
//----------------------------------
void CSuperString::DeepCopy(const char* pstrSource)
{
	char* pstrCopyOfSource = 0;
	pstrCopyOfSource = CloneString(pstrSource);
//	CleanUp();
	m_pstrSuperString = pstrCopyOfSource;
}
//----------------------------------
// Name: operator = CloneString
// Abstract: 
//----------------------------------
char* CSuperString::CloneString(const char* pstrSource)
{
	char* pstrClone = 0;
	long lngLength = 0;
	if (pstrSource != 0)
	{
		lngLength = (long)strlen(pstrSource);
		pstrClone = new char[lngLength + 1];
		strcpy_s(pstrClone, lngLength + 1, pstrSource);

	}
	else
	{
		pstrClone = new char[1];
		*(pstrClone + 0) = 0;
	}
	return pstrClone;
}
//----------------------------------
// Name: Destructor
// Abstract: 
//----------------------------------
CSuperString::~CSuperString()
{
	CleanUp();
}
//----------------------------------
// Name: CleanUp
// Abstract: 
//----------------------------------
void CSuperString::CleanUp()
{
	DeleteString(m_pstrToUpperCase);
	DeleteString(m_pstrSuperString);
	/* DeleteString(m_pstrToLowerCase);
	DeleteString(m_pstrTrimLeft);
	DeleteString(m_pstrTrimRight);
	DeleteString(m_pstrTrim);
	DeleteString(m_pstrReverse);
	DeleteString(m_pstrLeft); */
}
//----------------------------------
// Name: DeleteString
// Abstract: 
//----------------------------------
void CSuperString::DeleteString(const char* pstrSource)
{
	if (pstrSource !=0) {
		delete pstrSource;
		pstrSource = 0;
	}
}
//----------------------------------
// Name: ToString
// Abstract: 
//----------------------------------
const char* CSuperString::ToString() const
{
	return m_pstrSuperString;
}
//----------------------------------
// Name: TrimLeft
// Abstract: 
//----------------------------------
const char* CSuperString::TrimLeft()
{
	DeleteString(m_pstrTrimLeft);
	//char* pstrLowerCase = 0;
	//pstrLowerCase = CloneString(m_pstrSuperString);
	m_pstrTrimLeft = CloneString(m_pstrSuperString);
	while (isspace(*m_pstrTrimLeft)) m_pstrTrimLeft++;
	
	//_strlwr_s(m_pstrTrimLeft = trim_left(m_pstrSuperString), strlen(m_pstrSuperString) + 1);
	return m_pstrTrimLeft;
}
//----------------------------------
// Name: TrimLeft
// Abstract: 
//----------------------------------
const char* CSuperString::TrimRight()
{
	DeleteString(m_pstrTrimRight);
	//char* pstrLowerCase = 0;
	//pstrLowerCase = CloneString(m_pstrSuperString);
	long lngLength = (long)strlen(m_pstrSuperString);
	m_pstrTrimRight = new char[lngLength + 1];
		
	char ch = *m_pstrSuperString ;
	int j = 0;
	for(int i = 0; i< lngLength;i++)
	{
		ch = *(m_pstrSuperString + i);
		if (isspace(ch))
		{

		} else
		{
			*(m_pstrTrimRight+j) = ch;
			j++;
		}
	}
	while (j < lngLength)
	{
		*(m_pstrTrimRight + j) = '\0';
		j++;
	}
	

	return m_pstrTrimRight;
}
//----------------------------------
// Name: TrimLeft
// Abstract: 
//----------------------------------
const char* CSuperString::Trim()
{
	DeleteString(m_pstrTrim);
	//char* pstrLowerCase = 0;
	//pstrLowerCase = CloneString(m_pstrSuperString);
	
	long lngLength = (long)strlen(m_pstrSuperString);
	m_pstrTrim = new char[lngLength + 1];

	char ch = *m_pstrSuperString;
	int j = 0;
	for (int i = 0; i < lngLength; i++)
	{
		ch = *(m_pstrSuperString + i);
		if (isspace(ch))
		{

		}
		else
		{
			*(m_pstrTrim + j) = ch;
			j++;
		}
	}
	while (j < lngLength)
	{
		*(m_pstrTrim + j) = '\0';
		j++;
	}
	while (isspace(*m_pstrTrim)) m_pstrTrim++;
	
	return  m_pstrTrim;
}
//----------------------------------
// Name: 
// Abstract: 
//----------------------------------
const char* CSuperString::Reverse()
{
	DeleteString(m_pstrReverse);
	long lngLength = (long)strlen(m_pstrSuperString);
	m_pstrReverse = new char[lngLength + 1];

	char ch = *(m_pstrSuperString + lngLength -1);
	int j = 0;
	for (int i = lngLength-1 ; i >0; i--)
	{
		*(m_pstrReverse + j) = *(m_pstrSuperString + i);
		j++;
		
	} 
	*(m_pstrReverse + j) = '\0';
	return m_pstrReverse;
 }
//----------------------------------
// Name: Left
// Abstract: Return pointer to left N-most characters
// Following code works 
//----------------------------------
/* const char* CSuperString::Left(long lngCharactersToCopy)
{
	long lngLength = (long)strlen(m_pstrSuperString);
	if (lngCharactersToCopy < 0) {
		lngCharactersToCopy = 0;
	}
	if (lngCharactersToCopy > lngLength) {
		lngCharactersToCopy = lngLength;
	}
// 	char* m_pstrLeft2 = 0;
//	if (m_pstrLeft != 0) {
//		m_pstrLeft2 = new char[lngCharactersToCopy + 1];
//		strncpy_s(m_pstrLeft2, lngCharactersToCopy + 1, m_pstrSuperString, lngCharactersToCopy);
//		*(m_pstrLeft2 + lngCharactersToCopy) = 0;
//		return m_pstrLeft2;
//	} else 
 //	DeleteString(m_pstrLeft);
	m_pstrLeft = new char[lngCharactersToCopy + 1];
	strncpy_s(m_pstrLeft, lngCharactersToCopy + 1, m_pstrSuperString, lngCharactersToCopy);
	*(m_pstrLeft + lngCharactersToCopy) = 0;
	return m_pstrLeft;
	 //}
} */
//----------------------------------
// Name: Left
// Abstract: Return pointer to left N-most characters
// Following code works 
//----------------------------------
CSuperString CSuperString::Left(long lngCharactersToCopy)
{
	CSuperString ssLeft;
	long lngLength = (long)strlen(m_pstrSuperString);
	if (lngCharactersToCopy < 0) {
		lngCharactersToCopy = 0;
	}
	if (lngCharactersToCopy > lngLength) {
		lngCharactersToCopy = lngLength;
	}
// 	char* m_pstrLeft2 = 0;
//	if (m_pstrLeft != 0) {
//		m_pstrLeft2 = new char[lngCharactersToCopy + 1];
//		strncpy_s(m_pstrLeft2, lngCharactersToCopy + 1, m_pstrSuperString, lngCharactersToCopy);
//		*(m_pstrLeft2 + lngCharactersToCopy) = 0;
//		return m_pstrLeft2;
//	} else
 //	DeleteString(m_pstrLeft);
	m_pstrLeft = new char[lngCharactersToCopy + 1];
	strncpy_s(m_pstrLeft, lngCharactersToCopy + 1, m_pstrSuperString, lngCharactersToCopy);
	*(m_pstrLeft + lngCharactersToCopy) = 0;

	ssLeft.CleanUp();
	ssLeft.m_pstrSuperString = m_pstrLeft;
	return ssLeft;
	 //}
} 
/* 
CSuperString CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
	CSuperString ssReplace;
	char* strReplace = 0;
	long i = 0;
	long lngLength = (long)strlen(m_pstrSuperString);
	long lngReplaceLng = (long)strlen(pstrReplace);
	long startIndex = -1;
	long startAgain = 0;
	while (i < lngLength) {
		long j = 0;
		bool start = true;
		while (*(m_pstrSuperString + i) == *(pstrFind + j)) {
			if (start == true) {
				startIndex = i;
				start = false;
			}
			i++;
			j++;
		}
		i++;
	}
	i = 0;
	if (startIndex >=0) {
		strReplace = new char[lngLength + lngReplaceLng +1];
		while (i < startIndex) {
			*(strReplace + i) = *(m_pstrSuperString + i);
			i++;
		}
		long j = 0;
		startAgain = i;
		while (j < lngReplaceLng) {
			*(strReplace + i) = *(pstrReplace + j);
			i++;
			j++;
		}
		j = startAgain;
		while (j < lngLength) {
			*(strReplace + i) = *(m_pstrSuperString + j);
			i++;
			j++;
		}
	}
	ssReplace.CleanUp();
	ssReplace.m_pstrSuperString = strReplace;
	return ssReplace;

}
*/
// Following works for Test 2
/*
CSuperString CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
	CSuperString ssReplace;
	char* strReplace = 0;
	CQueue<int> clsQueue1;
	long i = 0;
	long lngLength = (long)strlen(m_pstrSuperString);
	long lngReplaceLng = (long)strlen(pstrReplace);
	long startIndex = -1;
	long startAgain = 0;
	int count = 0;
	while (i < lngLength) {
		long j = 0;
		bool start = true;
		while (*(m_pstrSuperString + i) == *(pstrFind + j)) {
			if (start == true) {
				count++;
				clsQueue1.Push(i);
				startIndex = i;
				start = false;
			}
			i++;
			j++;

		}
		start = true;
		i++;
	}
	i = 0;
	
	if (count > 0)
	{
		strReplace = new char[lngLength + count * lngReplaceLng + 1];
	}
	
	
	startIndex = clsQueue1.Pop();
	count--;
	if( i ==0)
	{
		while (i < startIndex) {
			*(strReplace + i) = *(m_pstrSuperString + i);
			i++;
		}
	}
	long j = 0;
	startAgain = i + (long)strlen(pstrFind); 
//	while (count > -1) {
		while (j < lngReplaceLng) {
			*(strReplace + i) = *(pstrReplace + j);
			i++;
			j++;
		}
		
		if (count == 0)
		{
			startIndex = lngLength;
		}
		else
		{
			startIndex = clsQueue1.Pop();
		}
		j = startAgain;
		while (j < startIndex) {
			*(strReplace + i) = *(m_pstrSuperString + j);
			i++;
			j++;
		}
		startAgain = j + (long)strlen(pstrFind);
		j = 0;
		while (j < lngReplaceLng) {
			*(strReplace + i) = *(pstrReplace + j);
			i++;
			j++;
		}
		
		j = startAgain;
		while (j < lngLength) {
			*(strReplace + i) = *(m_pstrSuperString + j);
			i++;
			j++;
		}
		*(strReplace + i) = '\0';
	//	}
	//}
	ssReplace.CleanUp();
	ssReplace.m_pstrSuperString = strReplace;
	return ssReplace;

} */
CSuperString CSuperString::Replace(const char* pstrFind, const char* pstrReplace)
{
	CSuperString ssReplace;
	char* strReplace = 0;
	CQueue<int> clsQueue1;
	long i = 0;
	long lngLength = (long)strlen(m_pstrSuperString);
	long lngReplaceLng = (long)strlen(pstrReplace);
	long startIndex = -1;
	long startAgain = 0;
	int count = 0;
	//count number of occurrence of search string pstrFind
	while (i < lngLength) {
		long j = 0;
		bool start = true;
		while (*(m_pstrSuperString + i) == *(pstrFind + j)) {
			if (start == true) {
				count++;
				clsQueue1.Push(i);
				startIndex = i;
				start = false;
			}
			i++;
			j++;

		}
		start = true;
		i++;
	}
	i = 0;

	if (count > 0)
	{
		strReplace = new char[lngLength + count * lngReplaceLng + 1];
	}

	// Copy starting chars until first occurence of search string pstrFind
	startIndex = clsQueue1.Pop();
	count--;
	if (i == 0)
	{
		while (i < startIndex) {
			*(strReplace + i) = *(m_pstrSuperString + i);
			i++;
		}
	}
	long j = 0;
	// set index in way not to copy characters of pstrFind
	startAgain = i + (long)strlen(pstrFind);
	while (count >= 0) {
		j = 0;
		// Copy every character of pstrReplace
		while (j < lngReplaceLng) {
			*(strReplace + i) = *(pstrReplace + j);
			i++;
			j++;
		}
		// retrieve index of original string for 
		// next occurence of pstrFind
		if (count == 0)
		{
			startIndex = lngLength;
			break;
		}
		else
		{
			startIndex = clsQueue1.Pop();
			count--;
		}
		j = startAgain;
		// copy characters from original string
		// until next occurence of pstrFind
		while (j < startIndex) {
			*(strReplace + i) = *(m_pstrSuperString + j);
			i++;
			j++;
		}
		startAgain = j + (long)strlen(pstrFind);
	}
	
	
	// copy characters from original string
	// until end
	j = startAgain;
	while (j < lngLength) {
		*(strReplace + i) = *(m_pstrSuperString + j);
		i++;
		j++;
	}
	*(strReplace + i) = '\0';
	//	}
	//}
	ssReplace.CleanUp();
	ssReplace.m_pstrSuperString = strReplace;
	return ssReplace;

}
//----------------------------------
// Name: ToLowerCase
// Abstract: 
//----------------------------------
const char* CSuperString::ToLowerCase()
{
	DeleteString(m_pstrToLowerCase);
	//char* pstrLowerCase = 0;
	//pstrLowerCase = CloneString(m_pstrSuperString);
	m_pstrToLowerCase = CloneString(m_pstrSuperString);
	_strlwr_s(m_pstrToLowerCase = _strdup(m_pstrSuperString), strlen(m_pstrSuperString) + 1);
	return m_pstrToLowerCase;
}
//----------------------------------
// Name: ToUpperCase
// Abstract: 
//----------------------------------
/* const char* CSuperString::ToUpperCase()
{
	DeleteString(m_pstrToUpperCase);
	//char* pstrUpperCase = 0;
	//pstrUpperCase = CloneString(m_pstrSuperString);
	m_pstrToUpperCase = CloneString(m_pstrSuperString);
	//_strupr_s(pstrUpperCase = _strdup(m_pstrSuperString), strlen(m_pstrSuperString) + 1);
	_strupr_s(m_pstrToUpperCase = _strdup(m_pstrSuperString), strlen(m_pstrSuperString) + 1);
	return m_pstrToUpperCase;
} */
//----------------------------------
// Name: ToUpperCase
// Abstract: 
//----------------------------------
CSuperString CSuperString::ToUpperCase()
{
	CSuperString ssToUpperCase;
	ssToUpperCase = m_pstrSuperString;
	_strupr(ssToUpperCase.m_pstrSuperString);
	//_strupr_s(ssToUpperCase.m_pstrToUpperCase = _strdup(ssToUpperCase.m_pstrSuperString), strlen(ssToUpperCase.m_pstrSuperString) + 1);
	//cout << " 1a) - ToUpperCase  = '" << ssToUpperCase.ToUpperCase().ToString() << "'" << endl;
	return ssToUpperCase;
}
//----------------------------------
// Name: ToBoolean
// Abstract: 
//----------------------------------
bool CSuperString::ToBoolean()
{
	bool blnValue = false;
	//if (strcmp(ToLowerCase(), "true") == 0)
	if (strcmp(m_pstrSuperString, "true") == 0)
	{
		blnValue = true;
	}
	//else if (strcmp(ToLowerCase(), "1") == 0)
	else if (strcmp(m_pstrSuperString, "1") == 0)
	{
		blnValue = true;
	}
	return blnValue;
}

//----------------------------------
// Name: ToShort
// Abstract: 
//----------------------------------
short CSuperString::ToShort()
{
	short shtValue = 0;
	shtValue = (short)atoi(m_pstrSuperString);
	return shtValue;
}
//----------------------------------
// Name: ToInteger
// Abstract: 
//----------------------------------
int CSuperString::ToInteger()
{
	int intValue = 0;
	intValue = (int)atoi(m_pstrSuperString);
	return intValue;
}
//----------------------------------
// Name: ToLong
// Abstract: 
//----------------------------------
long CSuperString::ToLong()
{
	long lngValue = 0;
	lngValue = (long)atol(m_pstrSuperString);
	return lngValue;
}
//----------------------------------
// Name: ToFloat
// Abstract: 
//----------------------------------
float CSuperString::ToFloat()
{
	float sngValue = 0;
	sngValue = (float)atof(m_pstrSuperString);
	return sngValue;
}
//----------------------------------
// Name: ToDouble
// Abstract: 
//----------------------------------
double CSuperString::ToDouble()
{
	double dblValue = 0;
	dblValue = (double)atof(m_pstrSuperString);
	return dblValue;
}

//----------------------------------
// Name: Print
// Abstract: 
//----------------------------------
void CSuperString::Print(const char* pstrCaption)
{
	cout << endl;
	cout << pstrCaption << endl;
	cout <<"----------------------------------" << endl;
	// Length not 0?
	if (Length() > 0)
	{
		//Yes print String
		cout << m_pstrSuperString << endl;

	}
	else
	{
		// No print empty String
		printf("-Empty string\n");
	}
	cout << endl;
}
