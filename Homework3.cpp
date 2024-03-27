#include <stdlib.h>
#include <iostream>
#include "CDog.h"
#include "CTrainedDog.h"
using namespace std;


int main()
{

CDog clsBuster;
char name[] = "Buster";

//strcpy_s(name, "Buster");
char* ptrName = name;
clsBuster.SetName(ptrName);
//clsBuster.SetName("Buster");
clsBuster.SetWeight(-40); 

cout << "Name : " << clsBuster.GetName() << endl;
cout << "Weight: " << clsBuster.GetWeight() << endl;

clsBuster.Bark();
cout << endl;
cout << endl;

CTrainedDog clsUnderDog;
char name2[] = "UnderDog";
char* ptrName2 = name2;
clsUnderDog.SetName(ptrName2);
//clsUnderDog.SetName("UnderDog");
clsUnderDog.SetWeight(-40);

cout << "Name : " << clsUnderDog.GetName() << endl;
cout << "Weight: " << clsUnderDog.GetWeight() << endl;

clsUnderDog.Bark();
clsUnderDog.Fetch();
clsUnderDog.PlayDead();
cout << endl;
cout << endl; 
// system("pause");



return 1;
} 