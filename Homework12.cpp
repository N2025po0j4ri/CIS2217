// --------------------------------------------------------------------------------
// Name:	Nirupama Poojari
// Class:	C Programming 2
// Abstract:	Homework 12 – Recursion – Part 1
// --------------------------------------------------------------------------------

// --------------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int AddNumbers1To100Recursively(int intIndex);
int AddNumbersInRange(int start, int stop);
long factorial(long intNumber);
long fibonacci(long intNumber);


void magicSquareRecur(int num[6][6], int order, int xaxis, int yaxis);
void magicSquareRecurPrint(int num[6][6], int n);
void swap(int arr[6][6], int idxa, int idyb, int idxc, int idyd);


// --------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// --------------------------------------------------------------------------------
int main()
{  
    int intTotal = 0;
    long lngNum = 0;
    //Step 1 - 2)	100 is Maximum number of times a procedure can be called recursively on my machine.
    //Memory on my computer is  12 GB
    intTotal = AddNumbers1To100Recursively(0); 
    printf("AddNumbers1To100Recursively returns %d\n", intTotal);
    intTotal = AddNumbersInRange(1,3);
    printf("AddNumbersInRange 1 & 3 returns %d\n", intTotal);
    //Step 2 - 3)	 - Factorial of 12 is the largest factorial that can be computed with this method on my computer. 
    std::cout << "Factorial for values 1 - 20:" << std::endl;
    std::cout << "column 1-10 | column 11-20" << std::endl;
     for (long intNum = 1; intNum < 11; intNum += 1)
      {
          printf(" %d  |", factorial(intNum));
          printf(" %d  \n ", factorial(intNum + 10));

      } 
      
    
     lngNum = fibonacci(45);
     // Step 3 - 2)	 - 45 is the number for which the largest Fibonacci value can be computed with this method on my computer. 
     std::cout << "Fibonacci of 45 is " << lngNum << std::endl ; 
     
     
    int arr[6][6];
    magicSquareRecur(arr, 1,0,0);
    std::cout << "Magic square 6x6 : " << std::endl;
    magicSquareRecurPrint(arr, 6); 
    return 1;

}

// --------------------------------------------------------------------------------
// Name: AddNumbers1To100Recursively
// Abstract: Adds numbers 1 to 100 Recursively
// --------------------------------------------------------------------------------

int AddNumbers1To100Recursively(int intIndex)
{
    int intTotal = 0;
    intIndex += 1;

    intTotal += intIndex;

    if (intIndex < 100)
    {
        intTotal += AddNumbers1To100Recursively(intIndex);
    }
   // printf("intIndex = %d", intIndex); used to calculate maximum number
    //of times this procedure can be called recursively on my computer
    return intTotal;
}

// --------------------------------------------------------------------------------
// Name: AddNumbersInRange
// Abstract: AddNumbersInRange, that takes a starting value and a stop value as parameters.
// The procedure  recursively adds all the numbers (inclusive) in the range.
// --------------------------------------------------------------------------------

int AddNumbersInRange(int start , int stop)
{ 
    int intTotal = 0;
    intTotal += start;
    start += 1;

    

    if (start <= stop)
    {
        intTotal += AddNumbersInRange(start,stop);
    }
    return intTotal;

}

// --------------------------------------------------------------------------------
// Name: factorial
// Abstract: Returns factorial of given number recursively
// --------------------------------------------------------------------------------

long factorial(long intNumber)
{
    long intFactorial = intNumber;
  //  for (int intIndex = intNumber; intIndex > 1; intIndex -= 1)
 //   {
    if (intNumber > 1) {
        intFactorial = intFactorial * factorial(intNumber - 1);
    }
 //   }
    return intFactorial;
}

// --------------------------------------------------------------------------------
// Name: fibonacci
// Abstract: Returns fibonacci of given number recursively
// --------------------------------------------------------------------------------
long fibonacci(long intNumber)
{
    long intFib = intNumber;
    //  for (int intIndex = intNumber; intIndex > 1; intIndex -= 1)
   //   {
    if (intNumber > 2) {
        intFib = fibonacci(intNumber - 2) + fibonacci(intNumber - 1);
    }
    else 
    {
        intFib = 1;
    }
    
    //   }
    return intFib;
}
// --------------------------------------------------------------------------------
// Name: magicSquareRecur
// Abstract: populates 6x6 magic square recursively
// parameters: num - 6x6 magic square, 
// order - values 1-4 for  top left, bottom right,  top right , bottom left 3x3
// Correspomding 3x3 values of suqare are populated
// xaxis - xaxis start of 3x3 to be populated
// yaxis - yaxis start of 3x3 to be populated
// --------------------------------------------------------------------------------
void magicSquareRecur(int num[6][6], int order, int xaxis, int yaxis)
{
    int x = 0;// The diagonal, horizontal,vertical intersect number of 3x3
    int med = 0;//sum of any diagonal or horizontal or vertical line of 3x3
    if (order == 1) // top left 3x3
    {
        x = 5;
        med = 15;
    }
    else if (order == 2) //bottom right 3x3
    {
        x = 14;
        med = 42;
    }
    else if (order == 3) // top right 3x3
    {
        x = 23;
        med = 69;
    }
    else {  // bottom left 3x3
        x = 32;
        med = 96;
    }
    
    int n = xaxis + 3;
    int m = yaxis + 3;
    // populate centre and corner values of 3x3 corresponding to order
    for (int i = xaxis; i < n; i++)
    {
        for (int j = yaxis; j < m; j++)
        {

            if (i == xaxis + 1 && j == yaxis + 1) {
                num[i][j] = x;
            }
            else if (i == xaxis + 0 && j == yaxis + 0) {
                num[i][j] = x + 3; 
            }
            else if (i == xaxis + 0 && j == yaxis + 2) {
                num[i][j] = x + 1; 
            }
            else if (i == xaxis + 2 && j == yaxis + 0) {
                num[i][j] = x - 1;
            }
            else if (i == xaxis + 2 && j == yaxis + 2) {
                num[i][j] = x - 3; 
            }

        }
    }

    // populate rest of 3x3 corresponding to order
    for (int i = xaxis; i < n; i++)
    {
        for (int j = yaxis; j < m; j++)
        {

            if (i == xaxis + 0 && j == yaxis + 1) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis +0][yaxis+0] - num[xaxis+0][yaxis+2];
            }
            else if (i == xaxis + 1 && j == yaxis + 0) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis+0][yaxis+0] - num[xaxis+2][yaxis+0];
            }
            else if (i == xaxis + 2 && j == yaxis + 1) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis+2][yaxis+0] - num[xaxis+2][yaxis+2];
            }
            else if (i == xaxis + 1 && j == yaxis + 2) {
                num[i][j] = 0;
                num[i][j] = med - num[xaxis+1][yaxis+0] - num[xaxis+1][yaxis+1];
            }
        }
    }
    if (order ==1)
    { 
        magicSquareRecur(num, 2, xaxis +3, yaxis +3);
    }
    else if (order == 2) {
         magicSquareRecur(num, 3, xaxis-3 , yaxis );
    }
    else if (order == 3) {
        magicSquareRecur(num, 4, xaxis + 3, yaxis-3);
        swap(num, 0, 0, 3, 0);
       // swap(num, 1, 0, 4, 0);
        swap(num, 2, 0, 5, 0);
        swap(num, 1, 1, 4, 1);
    }
}
// --------------------------------------------------------------------------------
// Name: magicSquareRecur
// Abstract: displays 6x6 arr
    void magicSquareRecurPrint(int arr[6][6], int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    // --------------------------------------------------------------------------------
    // Name: magicSquareRecur
    // Abstract: swaps 2 values of arr
    void swap(int arr[6][6], int idxa, int idyb, int idxc, int idyd)
    {
        int tmp = arr[idxa][idyb];
        arr[idxa][idyb] = arr[idxc][idyd];
        arr[idxc][idyd] = tmp;
    }
