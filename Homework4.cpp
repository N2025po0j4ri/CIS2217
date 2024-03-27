#include <string>
#include <stdlib.h>
#include <iostream>
#include "CAnimal.h"
#include "CDog.h"
#include "CCow.h"
#include "CDragon.h"
#include <string.h>

using namespace std;

int main()
{
    CDog clsBuster;
    char name[] = "Buster";
    char dogtype[] = "Dog";
    //strcpy_s(name, "Buster");
    char* ptrName = name;
    char* ptsType = dogtype;
    clsBuster.SetName(ptrName);
    //clsBuster.SetName("Buster");
    clsBuster.SetType(dogtype);

    cout << "Name : " << clsBuster.GetName() << endl;
    cout << "Type: " << clsBuster.GetType() << endl;

    clsBuster.MakeNoise();
    cout << endl;
    cout << endl;

    CCow cow;
    char cowName[] = "Bela";
    char cowtype[] = "Cow";
    //strcpy_s(name, "Buster");
    char* ptrCowName = cowName;
    char* ptsCowType = cowtype;
    cow.SetName(ptrCowName);
    //clsBuster.SetName("Buster");
    cow.SetType(ptsCowType);

    cout << "Name : " << cow.GetName() << endl;
  //  cout << "Weight: " << clsBuster.GetType() << endl;

    cow.MakeNoise();
    cout << endl;
    cout << endl;

    CDragon clsDragon;
    char dragonName[] = "Giant";
    char dragontype[] = "Dragon";
    //strcpy_s(name, "Buster");
    char* ptrDragonName = dragonName;
    char* ptsDragonType = dragontype;
    clsDragon.SetName(ptrDragonName);
    clsDragon.SetType(ptsDragonType);

    cout << "Name : " << clsDragon.GetName() << endl;
    cout << "Type: " << clsDragon.GetType() << endl;

    clsDragon.MakeNoise();
    cout << endl;
    cout << endl;

    //step 3
    CAnimal* paclsZoo = new CAnimal[5];
    paclsZoo[0] = (CAnimal)clsBuster;
    paclsZoo[1] = (CAnimal)cow;
    paclsZoo[2] = (CAnimal)clsDragon;

    //step 4
    for (int i = 0; i < 5; i++) {
        if ( NULL == (paclsZoo + i)) {
        }
        else {
            cout << "Name : " << paclsZoo[i].GetName() << endl;
            cout << "Type : " << paclsZoo[i].GetType() << endl;
            // cout << "MakeNoise : ";
           // paclsZoo[i].MakeNoise();
        }
    }
    
    //step 5
    cout << "Step 5" << endl;
    for (int i = 0; i < 5; i++) {
        if (NULL == (paclsZoo + i)) {
        }
        else {
            if (i == 0 || i == 1 || i == 2) {
                cout << "Name : " << paclsZoo[i].GetName() << endl;
                cout << "Type : " << paclsZoo[i].GetType() << endl;

                if (strcmp(paclsZoo[i].GetType(),"Cow")) {
                    CCow* castCow = (CCow *) &paclsZoo[i];
                    (*castCow).Graze();
                   // DerivedType* m_derivedType = (DerivedType*)&m_baseType;
                }else if (strcmp(paclsZoo[i].GetType(), "Dog")) {
                    CDog* castDog = (CDog*)&paclsZoo[i];
                    (*castDog).Fetch();
                    
                }if (strcmp(paclsZoo[i].GetType(), "Dragon")) {
                    CDragon* castDragon = (CDragon*)&paclsZoo[i];
                    (*castDragon).BreathFire();
                    
                }
                // cout << "MakeNoise : ";
               // paclsZoo[i].MakeNoise();
            }
        }
    }
return 1;
}