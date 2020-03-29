#include<iostream>
#include<iomanip>
using namespace std;
int c,x,n;
double fct=1,xpow=1,sum=0;

int main()
{
    cin>>x>>n;
    for (c=0; c<=n; c++)
    {
		//calculating power of x nd factorials
		if (c!=0)
        {
            xpow*=x;
            fct*=c;
        }
	//summation
    sum+=xpow/fct;
    cout<<fixed<<setprecision(10);
    cout<<c<<" "<<sum<<endl;
    }
}