#include "pt4.h"
#include <fstream>
using namespace std;
void sort_vybor(int* a, int n)
{
    char in[250], t[250];
    pt >> in;
    OemToChar(in, t);

    ofstream FileOut(t);
    int k, m;
    for (int i = n - 1; i > 0; i--)
    {
        k = i; // запоминаем номер и
        m = a[i]; // значение текущего элемента
        for (int j = 0; j < i; j++) // поиск максимального элемента
            if (a[j] < m)
            {
                k = j;
                m = a[k];
            }
        if (k != i) 
        { 
        a[k] = a[i];
        a[i] = m;
        }
        for (int m = 0; m < n; m++)
        {
            FileOut << a[m] << " ";
            if (m + 1 == i) FileOut << "|" << " ";
        }
        FileOut << "\n";
    }
    FileOut.close();
}

void Solve()
{
    Task("Sort5");
    int n = 0;
    int Mass[60] = {};
    
    pt >> n;
    
    for (int i = 0; i < n; i++) pt >> *(Mass + i);
    
    sort_vybor(Mass, n);
}
