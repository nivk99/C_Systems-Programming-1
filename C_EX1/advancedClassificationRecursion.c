
#define false 0
#define true 1
int helpIsArmstrong(int num,int temp,int some);
int someDigitsRec(int num);
int powRec(int x,int y);
int helpPlinfrome(int temp,int some);
//////////////////////////////////////////////////////////
//Checks the number of digits and also checks pow and finally checks if it is equal
int isArmstrong(int num){
    int ans= helpIsArmstrong(num,0, someDigitsRec(num));
    if (ans==num){
     return true;
    }
     return false;
}
//Auxiliary function for recursion
int helpIsArmstrong(int num,int temp,int some){
    if(num<=0){
        return temp;
    }
    temp=temp+powRec(num%10,some);
    num=num/10; 
    return helpIsArmstrong(num,temp,some);  
}
//Checking the number of digits recursively
int someDigitsRec(int num){
    if(num/10==0){
        return true;
    }
    return 1+someDigitsRec(num/10);
}

//Recursively power
int powRec(int x,int y){
    if(y==0){
        return true;
    }
    return x*powRec(x,y-1);
}
/////////////////////////////////////////////////////////////
//Reverses the number recursively and finally checks if it is equal
int isPalindrome(int num){
    int temp =num;
    if(num>=0&&num<=9){
    return true;
    }
    int x=0;
    int ans=helpPlinfrome(temp,x);
    if (ans==temp){
    return true;
    }
    return false;
}
//Helps reverse the number
int helpPlinfrome(int temp,int some){
    if(temp<=0){
    return some;
    }
    some=some*10;
    some=some+temp%10;
    temp=temp/10;
    return helpPlinfrome(temp,some);
}