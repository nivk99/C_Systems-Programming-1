
#define false 0
#define true 1
int powloop(int x,int y);
int someDigitsloop(int num);
////////////////////////////////////////////////////////////////
//Checks the number of digits and also checks pow and finally checks if it is equal
int isArmstrong(int num){
    int some=someDigitsloop(num);
    int ans=0;
    int temp=num;
    while(temp>0){
        ans=ans+powloop(temp%10,some);
        temp=temp/10;
    }
    if (ans==num){
         return true;
    }

    return false;
}
//Calculate the number of digits in the form of a loop by dividing the digits
int someDigitsloop(int num){
    int ans =1;
    while(num/10!=0){
        num=num/10;
        ans=ans+1;
    }
    return ans;
}

// Power of 2 numbers in the form of a loop by multiplying
int powloop(int x,int y){
    int i=1;
    int ans=1;
    while(i<=y){
      ans=ans*x;
      i=i+1;
    }
    return ans;
}

/////////////////////////////////////////////////////////////////
//Reverses the number and checks whether it is equal
int isPalindrome(int num){
    int ans=0;
    int temp=num;
    while(temp>0){
        ans=ans*10;
        ans=ans+(temp%10);
        temp=temp/10;
    }
    if (ans==num){
        return true;
    }
    return false;
}
