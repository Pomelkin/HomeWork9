#include "pt4.h"
#include <fstream>
#include <string>
using namespace std;

int mesto(string s)
{
    if (s.find("-") != -1) return s.find("-");
    else return s.find("+");
}

void Solve()
{
    Task("Five5");
    char in[250], t[250], out[250];
    pt >> in;
    OemToChar(in, t);

    fstream FileIn(t);

    pt >> out;
    OemToChar(out, t);

    ofstream FileOut(t);

    while(!FileIn.eof())
    {
        string Numbers;
        FileIn >> Numbers;
        
        string s;
        
        s.replace(0, mesto(Numbers), Numbers, 0, mesto(Numbers));
        int Num1 = stoi(s);
        s.erase(0);
        
        s.replace(0, Numbers.size() - mesto(Numbers) - 1, Numbers, mesto(Numbers)+1, Numbers.size() - mesto(Numbers) - 2);
        int Num2 = stoi(s);
        
        int Sum;
        
        if (s.find("-") != -1) Sum=Num1-Num2;
        else Sum = Num1 + Num2;

        Numbers += to_string(Sum);

        FileOut << Numbers << endl;
    }
    FileIn.close();
    FileOut.close();
}
