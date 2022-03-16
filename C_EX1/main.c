#include <stdio.h> 
#include "NumClass.h"
/**
There is an input from the user and checks if the number is initial,isArmstrong,isPalindrome
and isStrong.And prints the number to the screen
*/
int main() 
{ 
    int min,max;
    if(scanf("%d%d",&max,&min)!=2){
         return 1;
    }
    if(max<min){
          int temp=max;
          max=min;
          min=temp;
    }
    printf("The Armstrong numbers are:"); 
    for(int i=min;i<=max;i++){
          if(isArmstrong(i)==1){
               printf(" %d",i); 
          }
    }
    printf("\n"); 
    printf("The Palindromes are:"); 
    for(int i=min;i<=max;i++){
          if(isPalindrome(i)==1){
                printf(" %d",i); 
          }
    }
    printf("\n"); 
    printf("The Prime numbers are:"); 
    for(int i=min;i<=max;i++){
          if(isPrime(i)==1){
                printf(" %d",i); 
          }
    }
    printf("\n"); 
    printf("The Strong numbers are:"); 
    for(int i=min;i<=max;i++){
          if(isStrong(i)==1){
                 printf(" %d",i); 
          }
    }
    printf("\n"); 
    return 0;
}
