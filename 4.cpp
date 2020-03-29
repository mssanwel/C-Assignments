#include<iostream>
#include<string>
#include<math.h>
using namespace std;
string typ;
bool boo;
struct out
{
    double x,y,w,h;
};
//generating points for point structure    
out pointset()
{
    int n,c,c2;
    cin>>n;
    double maxx=-1,maxy=-1,point[n][2], avg[2]={0,0};
    for (c=0; c<n; c++)
    {
        cin>>point[c][0]>>point[c][1];
    }
    for (c=0; c<n; c++)
    {
        for (c2=0; c2<n; c2++)
        {
            if (maxx<fabs(point[c][0]-point[c2][0]))
            {
                maxx=fabs(point[c][0]-point[c2][0]);
                avg[0]=(point[c][0]+point[c2][0]);
            }
            if (maxy<fabs(point[c][1]-point[c2][1]))
            {
                maxy=fabs(point[c][1]-point[c2][1]);
                avg[1]=(point[c][1]+point[c2][1]);
            }
        }
    }
    avg[0]=avg[0]/2;
    avg[1]=avg[1]/2;
    //cout<<avg[0]<<" "<<avg[1]<<" "<<maxx<<" "<<maxy<<endl;
    out outpoint =  {avg[0], avg[1], maxx, maxy};
    return outpoint;
    
}
//generating points for circle
out circle()
{
    double x,y,r;
    cin>>x>>y>>r;
    //cout<<x<<" "<<y<<" "<<r*2<<" "<<r*2<<endl;
    out outcircle = {x,y,r*2,r*2};
    return outcircle;
}
//generating points for rectangle
out rectangle()
{
    double x,y,w,h;
    cin>>x>>y>>w>>h;
    //cout<<x<<" "<<y<<" "<<w<<" "<<h;
    out outrectangle = {x,y,w,h};
    return outrectangle;
}
//Comparing all point to find the outlier points and using them to find center
int main()
{
    out box;
    struct maxpoint{
        double l,r,t,b;
    };
    maxpoint maxlen;
    cin>>typ;
    while (typ != "#"){
    if (typ == "R")
    {
        box=rectangle();   
    }
    if (typ == "C")
    {
        box=circle();
    }
    if (typ == "P")
    {
        box=pointset();
    }
    if (boo)
    {
        maxlen.l = (box.x-box.w/2);
        maxlen.r = (box.x+box.w/2);
        maxlen.b = (box.y-box.h/2);
        maxlen.t = (box.y+box.h/2);
        boo=false;
    }
    if (maxlen.l > (box.x-box.w/2))
    {
        maxlen.l = (box.x-box.w/2);
    }
    if (maxlen.r < (box.x+box.w/2))
    {
        maxlen.r = (box.x+box.w/2);
    }
    if (maxlen.b > (box.y-box.h/2))
    {
        maxlen.b = (box.y-box.h/2);
    }
    if (maxlen.t < (box.y+box.h/2))
    {
        maxlen.t = (box.y+box.h/2);
    }
    cin>>typ;
    }
    cout<<(maxlen.l+maxlen.r)/2<<" "<<(maxlen.t+maxlen.b)/2<<" "<<fabs((maxlen.l-maxlen.r))<<" "<<fabs((maxlen.t-maxlen.b))<<endl;
}
