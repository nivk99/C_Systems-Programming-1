#include <stdio.h> 
#include "my_mat.h"
/**
This is the main function from which the commands are read
**/
int main() 
{
 char c =0;
  scanf(" %c", &c);
  while(c!='D')
  {
       if (c=='A')
       {
             inputMatrix();//Absorption of a two-dimensional array from the user
       }
      if (c=='B')
      {
            isRouteGraph();//Check if there is a route
      }
      if (c=='C')
      {
            isMinRouteGraph();//Finding the shortest route
      }
    scanf(" %c", &c);
}
      return 0;
}
