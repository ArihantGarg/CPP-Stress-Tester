#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

string getfile(string s)
{
    std::ifstream file(s);
    std::string str;
    string a="";
    while (getline(file,str))
        a+=str;
    return a;
}

template <typename T>
void startProcess(T path)
{
    STARTUPINFO s = {sizeof (STARTUPINFO)};
    PROCESS_INFORMATION p;
    CreateProcess(path, NULL,
        0, 0, 0, 0, 0, 0, &s, &p );
    WaitForSingleObject( p.hProcess, INFINITE );
}

void s1()
{
    while(1)
    {
        cout<<"Next"<<endl;
        startProcess("C:\\Users\\ariha\\Desktop\\Programs\\Contest\\TestCaseChecker\\generator.exe");
        startProcess("C:\\Users\\ariha\\Desktop\\Programs\\Contest\\TestCaseChecker\\bruteforce.exe");
        startProcess("C:\\Users\\ariha\\Desktop\\Programs\\Contest\\TestCaseChecker\\check.exe");
        string a=getfile("ac.txt");
        string b=getfile("ad.txt");
        if(a!=b)
        {
            cout<<"Unsuccessful"<<endl;
            break;
        }
    }
}

int main()
{
    s1();
}
