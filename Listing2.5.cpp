// Listing2.5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/* 
#include <iostream>
using namespace std;
int DemoConsoleOutput()
{
    //std::cout << "Hello World!\n";
    cout << "This is a simple string literal" << endl;
    cout << "Writing number five: " << 5 << endl;
    cout << "Performing division 10/5 = " << 10 / 5 << endl;

    return 0;
}

int main() {

    return DemoConsoleOutput();
}
*/

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
//    ifstream myfile("C:\\Users\ypooj\\source\\repos\\TweakProgram\\TweakProgram\\example.txt");
 //   myfile.open();
    std::ifstream ifs;

    ifs.open("C:\\Users\ypooj\\source\\repos\\TweakProgram\\TweakProgram\\example.txt", std::ifstream::in);
    std::string line;
    std::getline(ifs, line);

  //  std::ifstream filein("Hey.txt");
 //   for (std::string line; std::getline(ifs, line); ) {
        std::cout << line << std::endl
  //  }
  
    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
