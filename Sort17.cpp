#include "pt4.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void Solve()
{
    Task("Sort17");
    
    char in[250], t[250];
    pt >> in;
    OemToChar(in, t);

    vector <int> mass;

    ifstream FileIn(t);

    int i = 0;
    
    while (!FileIn.eof())
    {
        string s;
        FileIn >> s;
        mass.push_back(stoi(s));
        i++;
    }

    int keyOut = -1;
    int l = 0; // ����� �������
    int r = i-1; // ������ �������
    int mid,key;
    
    pt >> key;
    
    while ((l <= r) && (keyOut == -1)) {
        mid = (l + r) / 2; // ��������� ��������� ������ ������� [l,r]

        if (mass[mid] == key) keyOut = mid; //��������� ���� �� ���������� ���������
        if (mass[mid] < key) r = mid - 1; // ���������, ����� ����� ����� ���������
        else l = mid + 1;
    }
    
    if (keyOut == 0)
    pt << keyOut;
    else
    {
        for (int i = keyOut; i >= 0; i--)
        {
            if (i == 0) keyOut = i;
            else
            if (mass[i] != mass[keyOut])
            {
                keyOut = i + 1;
                break;
            }
        }
        pt << keyOut;
    }
}
