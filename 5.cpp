#include<iostream>
#include<sstream>
#include<string>
#include<list>
using namespace std;

//checking for palindrome structure
bool checkpalindrome(int num)
{
    int c;
    bool boo = true;
    string numstring;
    stringstream temp;
    temp<<num;
    temp>>numstring;
    for (c=0; c<=(numstring.size()); c++)
    {
        if (numstring[c]!=numstring[numstring.size()-c-1])
            boo = false;
    }
    return boo;
}
//generating possible values and checking through palindrome function
int main()
{
    int c1, c2,m,n;
    list<int> nlist;
    list<int>::iterator pos=nlist.end();
    cin>>m>>n;
    for (c1=100; c1<=999; c1++)
    {
        for (c2=c1; c2<=999; c2++)
            {
                if (m<=c1*c2 && c1*c2<=n)
                {
                    if (checkpalindrome(c1*c2))
                        nlist.insert(pos, c1*c2);
                }
            }
    }
    nlist.sort();
    nlist.unique();
    for (pos=nlist.begin(); pos!=nlist.end(); pos++)
    {
        cout<<*pos<<endl;
    }
}



