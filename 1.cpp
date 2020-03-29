//Question 1

#include <iostream>
#include <cstdlib> 
using namespace std;
int n, x,count=0, queenie[2];

int main()
{
    cin>>queenie[0]>>queenie[1];
    cin>>n;
    int puppies[n][2];
    //input location of puppies
	for (x=0; x<n; x++)
    {
        cin>>puppies[x][0]>>puppies[x][1];
    }
	//checking distance and output
    for (x=0; x<n; x++)
    {
        if ((abs(queenie[0]-puppies[x][0])+abs(queenie[1]-puppies[x][1]))>10)
        {
            if (count==0)
            {
                cout<<"Puppy "<<x+1;
            }
            else
            {
                cout<<" and Puppy "<<x+1;
            }
            count+=1;
        }
    }
    if (count>0)
    {
        cout<<" too far away"<<endl<<"Total "<<count<<" puppies too far away"<<endl;    
    }
    else
    {
        cout<<"No puppies too far away"<<endl;
    }
    
    
    return 0;
}
