#include<iostream>
#include<math.h>
using namespace std;
int m,n,c,x,y,count;

int main()
{
    cin>>m>>n;
   //going from perimeter m to n
	for (c=m; c<=n; c++)
    {
		//generating possible triangles: x side and y side of triangle 
        for (x=1; x<=c; x++)
        {
            for (y=x; y<=c; y++)
            {
				//checking if right angled triangle and checking perimeter
                if ((pow((x*x+y*y),0.5)+x+y) == c)
                {
                    count=count+1;
                }
            }
        }
        if (count!=0)
            cout<<c<<" "<<count<<endl;
        count=0;
    }
}

