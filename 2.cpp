//
//  Assignment 2 Task 2 template
//  Copyright © 2019 HKU ENGG1340. All rights reserved.
//


#include <iostream>

using namespace std;

const int MAX_SIZE = 1000;
bool con=false;


///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers already provided to you
//             It means that you will need to use the function headers as is


// You may implement additional functions here



// Function: find the smallest number of steps to go from the starting point
//           to the destination in a given map.
//
// Input: int map[][]: 2D-array map
//        int map_h: the height of the map
//        int map_w: the width of the map
// Output: return true if a path is found, and store the smallest number of
//                      steps taken in &num_steps (pass-by-reference)
//         return false if there is no path
// ==============================================================
void travel(int map[][MAX_SIZE], int d, int c, int count=2)
  {
    
  }
bool FindPath(int map[][MAX_SIZE], int map_h, int map_w, int &num_steps)
{
  //find one
  int ind[2];
  for (int c=0; c<map_h; c++)
  {
    for (int d=0; d<map_w; d++)
        {
            if (map[d][c] == 1)
            {
                //cout<<d<<" "<<c<<endl;
                ind[0] = d;
                ind[1] = c;
            }
        }
  }
 
//search for closest zero from current position and update map array
int counter=1;
bool bol=true;
while (bol)
{
    bol=false;
    for (int c=0; c<map_h; c++)
    {
        for (int d=0; d<map_w; d++)
        {
            if (map[c][d] == counter)
            {
                //Plus direction
                 if (map[c+1][d] == 0)
                    map[c+1][d]=counter+1;
                 if (map[c-1][d] == 0)
                    map[c-1][d]=counter+1;
                 if (map[c][d+1] == 0)
                    map[c][d+1]=counter+1;
                 if (map[c][d-1] == 0)
                    map[c][d-1]=counter+1;
                 bol=true;
            }
        }
    }
    counter++;
}
//Identifying the least number of steps 
  int min=MAX_SIZE;
  bool bol2=false;
  for (int c=0; c<map_h; c++)
  {
    for (int d=0; d<map_w; d++)
        {
            if (map[c][d] == -2)
            {
                bol2=true;
                if ((map[c+1][d]<=0) and (map[c-1][d]<=0) and (map[c][d+1]<=0) and (map[c][d-1]<=0))
                    bol2=false;
                else
                {
                    {
                    if ((c+1)>=0 and (c+1)<MAX_SIZE)    
                    if (map[c+1][d] < min and map[c+1][d] > 0)
                        min=map[c+1][d];
                    if ((c-1)>=0 and (c-1)<MAX_SIZE)
                    if (map[c-1][d] < min and map[c-1][d] > 0)
                        min=map[c-1][d];
                    if ((d+1)>=0 and (d+1)<MAX_SIZE)
                    if (map[c][d+1] < min and map[c][d+1] > 0)
                        min=map[c][d+1];
                    if ((d-1)>=0 and (d-1)<MAX_SIZE)
                    if (map[c][d-1] < min and map[c][d-1] > 0)
                        min=map[c][d-1];
                    }
                }
            }
        }
  }

  
  //Display map
 /* for (int c=0; c<map_h; c++)
  {
    for (int d=0; d<map_w; d++)
        {
            cout<<map[c][d]<<" ";
        }
        cout<<endl;
  }
  */
    num_steps=min;
    return bol2;
  
}


///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
  int map_h;
  int map_w;
  cin >> map_h >> map_w;

  int map[MAX_SIZE][MAX_SIZE];

  // initialize map
  for (int i=0; i<MAX_SIZE; i++)
    for (int j=0; j<MAX_SIZE; j++)
      map[i][j] = -1;

  // read map from standard input
  for (int i=0; i<map_h; i++)
    for (int j=0; j<map_w; j++)
      cin >> map[i][j];

  int steps;
  // print to screen number of steps if a path is found, otherwise print "No"
  if (FindPath(map, map_h, map_w, steps))
    cout << steps << endl;
  else
    cout << "No" << endl;

}
