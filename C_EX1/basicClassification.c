
#define false 0
#define true 1
int factorial(int fact);
///////////////////////////////////////////////////////////////
//Checks a prime number on the remainder of the division.
int isPrime(int num){
    if(num<=0){
        return false;
    }
    int i=2;
    while(i<num){
        if(num%i==0){
        return false;
        }
      i+=1;
    }
    return true;
}
/////////////////////////////////////////////////////////////////
//This function takes the digits of the number and checks them the factorial and finally checks whether it is equal
int isStrong(int num){
    int temp =num;
    int ans=0;
    while(temp>0){
        int x=temp%10;
        temp=temp/10;
        ans=ans+factorial(x);
    }
    if(ans==0){
        return false;
    }
    if(ans==num){
         return true;
    }
    return false;
}
//This function acts recursively on the number
int factorial(int fact){
    if(fact ==0){
        return true;
    }
    else{
        return fact*factorial(fact-1);
    }

}