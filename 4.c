//
//  Assignment 2 Task 4 template
//  Copyright © 2019 HKU ENGG1340. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
const int MAX_INT_LENGTH = 100;

///////// DO NOT MODIFY ANYTHING ABOVE THIS LINE /////////

// IMPORTANT:  Do NOT change any of the function headers already provided to you
//             It means that you will need to use the function headers as is


// You may implement additional functions here






//
// AddTwoBigNumbers: to sum up two big numbers represented as digits in a char clear_char_array
//
// input:  char bigN[], char bigM[]:  two large numbers
// output the sum as a big number in the input array char sum[]

int sizeC( char M[])
{
    int n=0;
    while (M[n]!='\0')
    {
        n++;
    }
    return n;
}
void AddTwoBigNumbers(char bigN[], char bigM[], char sum[])
{
    int lenN=sizeC(bigN);
    int lenM=sizeC(bigM);
    char tempM[lenM];
    char tempN[lenN];
    char temp[MAX_INT_LENGTH];
    for (int n=0; n<lenM; n++)
       { 
           tempM[lenM-n-1]=bigM[n];
       }
       
    for (int n=0; n<lenN; n++)
       { 
           tempN[lenN-n-1]=bigN[n];
       }
    int add=0, loop=0, asc1, asc2;
    bool carry;
    carry=false;
    if (lenN>lenM)
    {
        loop=lenN;
        //char temp[lenN];
    }
    else
    {
        loop=lenM;
        //char temp[lenM];
    }
    for (int n=0; n<loop; n++)
       { 
         if (n>=lenN)
         asc1=48;
         else
         asc1=(tempN[n]);
         
         if (n>=lenM)
         asc2=48;
         else
         asc2=(tempM[n]);
         
         if (carry)
         add=asc1+asc2-48-48+1;
         else
         add=asc1+asc2-48-48;
         carry=false;
         if ((add)>=10)
            {
                carry=true;
                //printf("carry add\n");
            }
        if (carry)
            add=add-10;
        temp[n]=add+48;
        printf("%d %d %d\n", asc1-48, asc2-48, add);
       }
    if (carry)
      {
          //printf("1\n");
          temp[loop]=49;
          loop++;
      }
       
    //printf("%s\n", sum);
    for (int n=0; n<loop; n++)
       { 
           sum[n]=temp[loop-n-1];
       }
    sum[loop]='\0';
    
    printf("%s\n", temp);
}


///////// DO NOT MODIFY ANYTHING BELOW THIS LINE /////////

// Function: main function
// ==============================================================
int main()
{
  char bignum[2][MAX_INT_LENGTH]; // bignum[0] and bignum[1] are to store the digits of the two input number
  char sum[MAX_INT_LENGTH+1];     // to store the sum of the two big numbers

  // read in two numbers
  scanf("%s", bignum[0]);
  scanf("%s", bignum[1]);

  // calculate sum of the two numbers
  AddTwoBigNumbers(bignum[0], bignum[1], sum);

  // display the sum on screen
  printf("%s\n", sum);


  return 0;
}



