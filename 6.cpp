#include <stdio.h>
#include<iostream>
#include<string>
using namespace std;
char typ, inp;
int shift,asc;

void encrypt()
{
    cin>>shift;
    cin>>inp;
    while (inp!='!')
    {
        asc=inp;
		//checking if alphabet or not
        if (asc>=97 && asc<=122)
        {
            asc-=32;
            if ((asc+shift%26)<65)
            {
                inp=91-(65-(asc+shift%26));
            }
            else if((asc+shift%26)>90)
            {
                inp=64+((asc+shift%26)-90);
            }
            else
            {
             inp=asc+shift%26;   
            }
        }
        else if (asc>=65 && asc<=90)
        {
            asc+=32;
            if ((asc+shift%26)<97)
            {
                inp=123-(97-(asc+shift%26));
            }
            else if((asc+shift%26)>122)
            {
                inp=96+((asc+shift%26)-122);
            }
            else
            {
             inp=asc+shift%26;   
            }
        }
        cout<<inp;
        cin>>inp;
    }
    cout<<"!";
}
void decrypt()
{
    char temp;
    cin>>shift;
    cin>>inp;
    while (inp!='!')
    {
        asc=inp;
		//checking if alphabet or not
        if (asc>=65 && asc<=90)
        {
            if ((asc-shift%26)<65)
            {
                temp=123-(65-(asc-shift%26));
                cout<<temp;
            }
            else if((asc-shift%26)>90)
            {
                temp=96+((asc-shift%26)-90);
                cout<<temp;
            }
            else
            {
                temp=(asc-shift%26)+32;
                cout<<temp;
            }
        }
        else if (asc>=97 && asc<=122)
        {
            if ((asc-shift%26)<97)
            {
                temp=91-(97-(asc-shift%26));
                cout<<temp;
            }
            else if((asc-shift%26)>122)
            {
                temp=96+((asc-shift%26)-122);
                cout<<temp;
            }
            else
            {
                temp=(asc-shift%26)-32;
                cout<<temp;
            }
        }
        else
        {
            cout<<inp;
        }
        cin>>inp;
    }
    cout<<"!";
}
//check mode: e or d
int main()
{
    cin>>typ;
    if (typ=='e')
    {
        encrypt();
    }
    else if (typ=='d')
    {
        decrypt();
    }
}


