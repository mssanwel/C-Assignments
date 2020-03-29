/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<stdio.h>
#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;

double sigmoid(double x)
{
    return 1/(1+pow(2.72,x*-1));
}
double tanH(double num)
{
    return 2*sigmoid(2*num)-1;
}
double ComputeH(double x, double h)
{
    return tanH(0.5*x - 2*h);
}
double ComputeO(double x, double h)
{
    return sigmoid(0.1*x + 1.5*h);
}
void PrintSeqs(double xO[], int n)
{
    for (int c=0; c<n;c++)
    {
        cout<<setprecision(10);
        cout<<xO[c]<<" ";
    }
}

int main()
{
    int n;
    double x,h;
    double xO[n];
    //loop : times the number of nodes
    cin>>n;
    cin>>h;
    for (int c=0; c<n; c++)
    {
        cin>>x;
        double x1=ComputeO(x,h);
        double h1=ComputeH(x,h);
        h=h1;
        cout<<fixed;
        cout<<setprecision(10);
        cout<<h<<" ";
        xO[c]=x1;
    }
    //PrintSeqs(xO, n);
    cout<<endl;
    for (int c=0; c<n;c++)
    {
        cout<<fixed;
        cout<<setprecision(10);
        cout<<xO[c]<<" ";
    }
    return 0;
}




