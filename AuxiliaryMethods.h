#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
//#include <bits/stdc++.h>

using namespace std;

class AuxiliaryMethods{

public:
   static string loadLine();
   static string replaceCommaWithDot(string textString);
   static double conversionStringToDouble(string textString);
   static int conversionStringToInt(string textString);
};

#endif
