#include "Homework9.h"
/* 
udtNodeType* pudtNode1 = 0;
udtNodeType* pudtNode2 = 0;
udtNodeType* pudtNode3 = 0;

pudtNode1 = new udtNodeType;
pudtNode2 = new udtNodeType;
pudtNode3 = new udtNodeType;

pudtNode1->intValue = 10;
pudtNode2->intValue = 20;
pudtNode3->intValue = 30;

pudtNode1->pudtNextNode = pudtNode2;
pudtNode2->pudtNextNode = pudtNode3;
pudtNode3->pudtNextNode = 0;

udtNodeType* pudtCurrNode = 0;
pudtCurrNode = pudtNode1;

while (pudtCurrentNode != 0)
{
    cout << pudtCurrentNode->intValue;
    pudtCurrentNode = pudtCurrentNode->pudtNextNode;
}

delete pudtNode1;
pudtNode1 = 0;
delete pudtNode2;
pudtNode2 = 0;
delete pudtNode3;
pudtNode3 = 0;

}

-------- -
example unlimited values in list */

char* GetFileNameFromUser();
udtNodeType* LoadListFromFile(char* pstrFileName);

int main()
{
    char* pstrFileName = 0;
    int intUserValue = 0;
    udtNodeType* pudtHeadNode = 0;
    udtNodeType* pudtCurrentNode = 0;
    udtNodeType* pudtNextNode = 0;
    int intIndex = 0;

    //get File name
    pstrFileName = GetFileNameFromUser();

    //Load list
    pudtHeadNode = LoadListFromFile(pstrFileName);

    cout << "Please enter a number (-1 to end): ";
    cin >> intUserValue;

    while (intUserValue != -1)
    {
        pudtHeadNode = new udtNodeType;
        pudtHeadNode->intValue = intUserValue;
        pudtHeadNode->pudtNextNode = pudtNextNode;
        pudtNextNode = pudtHeadNode;

        cout << "Please enter a number (-1 to end): ";
        cin >> intUserValue;
    }


    pudtCurrentNode = pudtHeadNode;
    while (pudtCurrentNode != 0)
    {
        intIndex += 1;
        cout << "Value at node #" << intIndex
            << " is " << pudtCurrentNode->intValue << endl;

        pudtNextNode = pudtCurrentNode->pudtNextNode;

        pudtCurrentNode = pudtNextNode;
    }

    //delet list
    //loop until end of list (pointer to next node for last node will be 0)
    while (pudtHeadNode != 0)
    {
        pudtNextNode = pudtHeadNode->pudtNextNode;
        delete [] pudtHeadNode;  //sell house
        pudtHeadNode = 0;    // throw away key
        pudtHeadNode = pudtNextNode;
    }
    return 1;
}

char* GetFileNameFromUser()
{
    char strFileName[255] = "";
    int intLength = 0;
    char* pstrFileName = 0;

    cout << "Enter a file name:" << endl;
    cin >> strFileName;

    intLength = strlen(strFileName);
    pstrFileName = new char[intLength + 1];
    strcpy_s( pstrFileName, intLength, strFileName);
   // strcpy_s(dest, strlen(c) + 1, c);
    return pstrFileName;
}

udtNodeType* LoadListFromFile(char* pstrFileName)
{
    cout << "Loading list" << endl;
    return 0;
}

