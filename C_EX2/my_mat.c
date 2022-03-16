#include <stdio.h> 
#include "my_mat.h"
int temp[V][V];//Global variable
int copyMat();
int FloydWarshallalgorithm ();
/**
A function that picks up a two-dimensional array and initializes the auxiliary array according to the algorithm
**/
int inputMatrix()
{
    for(int i =0;i<V;i++)
    {
         for(int j=0;j<V;j++)
         {
             scanf("%d",&matrix[i][j]);
         }
    }
    FloydWarshallalgorithm ();
    return 0;
}
/**
A function checks whether there is a trajectory according to the algorithm
**/
int isRouteGraph()
{   
    int i=0;
    int j=0;
    scanf("%d%d",&i,&j);
    if((temp[i][j] != INF)&&(temp[i][j]!=0))
    {
        printf("True");
    } else
    {
        printf("False");
    }
        printf("\n");
    return 0;
    
}
/**
The function finds the shortest trajectory according to the algorithm
**/
int isMinRouteGraph()
{   
    int i=0;
    int j=0;
    scanf("%d%d",&i,&j);
    if((temp[i][j] != INF) && (temp[i][j]!=0))
    {
        printf("%d", temp[i][j]);
    } else
    {
        printf("%d",-1);
    }
        printf("\n");
    return 0;

}

/**
The function calculates the shortest route according to the Floyd – Warshall_algorithm algorithm
https://www.youtube.com/watch?v=oNI0rf2P9gE

**/

int FloydWarshallalgorithm ()
{
    copyMat(temp);
    for (int p = 0; p < V; p++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if ((temp[i][j] > (temp[i][p] + temp[p][j])) && (temp[i][p] != INF) && (temp[p][j] != INF))
                {
                 temp[i][j] =temp[i][p] + temp[p][j];
                }
            }
        }
    }
    return 0;
}
/**
A function copies the array and initializes variables to infinity if there is no trajectory
**/
int copyMat()
{
    for(int i=0; i<V; i++)
    {
        for(int j=0; j<V; j++) 
        {
            temp[i][j] = matrix[i][j];
            if((i!=j)&&(matrix[i][j] == 0))
            {
                temp[i][j] = INF;
            }
        }
    }
    return 0;
}
