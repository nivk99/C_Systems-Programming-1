
#include "my_string.h"
int Gematr_print(int j,int bo, const char *txt,char *_txt,int sum);
int Atbash_print(char *t,char *w,char *rv_w,const char *txt);

/////////////1//////////////////////////
int GematriaSequences( const char *txt, char *_txt, int sum)
{
      printf("Gematria Sequences: ");  
       int bo=0;
      for(int i=0;txt[i]!=END;i++)
      {
            if(_txt[i]>='A'&&'Z'>=_txt[i]&&Gematr_print(i,0,txt,_txt,sum))
            {    
                  if(bo)
                  {
                        printf("~");
                        Gematr_print(i,1,txt,_txt,sum);
                  }
                  else{
                       Gematr_print(i,1,txt,_txt,sum);
                       bo=1;  
                  }
            }
      } 
      printf("\n");
      return 0;
}

////////////////1a////////////////////
int Gematr_print(int j,int bo, const char *txt,char *_txt,int sum)
{
      int k=0;
      int sum_txt=0;
      for(int i=j;txt[i]!=END;i++){
            
            if(_txt[i]>='A'&&'Z'>_txt[i])
            {
                   sum_txt+=(_txt[i]-('A'-1));
            }
            if(sum_txt==sum)
            {
                  if(bo){

                         k=j;
                        printf("%c",txt[k]);
                         while(k!=i)
                         {

                               printf("%c",txt[++k]);
                        }
                  }

                  return 1;
            }
            if(sum_txt>sum)
            {
                  return 0;
            }
      }
      return 0;

}

///////////////////2//////////////////////

int AtbashSequences(const char *txt,char *_txt,char *_word)
{
      char *atbash=(char*)strdup(_txt);
      if(!atbash){
            exit(1);
      }
      for(int i=0;txt[i]!=END;i++)
      {
            if(atbash[i]>='A'&&'Z'>=atbash[i])
            {
                atbash[i]=('Z'-(atbash[i]-'A'));
            }


      }
      char *rvers_word=(char*)strdup(_word);
       if(!rvers_word){
            exit(1);
      }
      for (int i = 0,length=strlen(_word)-1; length>=0; i++,length--)
      {
        rvers_word[i] = _word[length];
      }
      printf("Atbash Sequences: ");    
      Atbash_print(atbash,_word,rvers_word,txt);
      printf("\n");
      free(atbash);
      free(rvers_word);
      return 0;

}

//////////////////2a////////////////////
int Atbash_print(char *t,char *w,char *rv_w,const char *txt)
{
      char *ans=(char*)calloc(TXT+1,sizeof(char));
      if(!ans){
            exit(1);
      }
      ans[TXT]=END;
        char lm[]="~";
        int sum=0;
for(int i=0;t[i]!=END;i++)
{
      if(t[i]==' '){
            continue;
      }

      if(t[i]==w[0])
      {
            int som=strlen(rv_w);
            int bo=0;
            char *pr=(char*)calloc(TXT+1,sizeof(char));
            if(!pr){
                  exit(1);
            }
            pr[TXT]=END;
            int k=0;
            for(int j=0,ii=i;j<strlen(rv_w)&&t[ii]!=END;j++,k++,ii++)
            {
                  bo=1;
                  pr[k]=txt[ii];
                  som--;
                  if(t[ii]==' '){
                       som++;
                       j--;
                       continue;
                        
                  }
                  if(t[ii]!=w[j]){
                        bo=0;
                        break;
                  }


            }
            pr[k]=END;
            if(bo&&som==0){
                  sum+=1+strlen(pr);
                  strcat(ans,lm);
                  strcat(ans,pr);
            }
            free(pr);

      }
      if(t[i]==rv_w[0])
      {
            int som=strlen(rv_w);
            int bo=0;
             char *pr=(char*)calloc(TXT+1,sizeof(char));
            if(!pr){
                  exit(1);
            }
            pr[TXT]=END;
            int k=0;
            for(int j=0,ii=i;j<strlen(rv_w)&&t[ii]!=END;j++,k++,ii++)
            {
                  bo=1;
                  pr[k]=txt[ii];
                  som--;
                  if(txt[ii]==' '){
                      j--;
                      som++;
                      continue;
                  }
                  if(t[ii]!=rv_w[j]){
                        bo=0;
                        break;
                  }
            }
            pr[k]=END;
            if(bo&&!som)
            {
                  sum+=1+strlen(pr);
                  strcat(ans,lm);
                  strcat(ans,pr);
            }
            free(pr);


      }

}
ans[sum]=END;
for(int i=1;ans[i]!=END;i++){
      printf("%c",ans[i]);
}
free(ans);
return 0;
      


}

/////////////////3/////////////////
int AnagramSequences(const char *txt,char *_txt,const char *word)
{
      printf("Anagram Sequences: ");
      int bo=0;
      int total=0;
      for(int i=0;i<strlen(word);i++)
      {
            total+=(int)(word[i]);
      }
         for(int i=0;txt[i]!=END;i++)
      {
            if(!(_txt[i]>='A'&&'Z'>=_txt[i]))
            {
                  continue;
            }
            int ii=i;
            int com=0;
            for(int j=0;word[j]!=END&&txt[ii]!=END;j++,ii++)
            {
                  if(txt[ii]==' ')
                  {
                        ii++;
                  }
                  char *check=strchr(word,txt[ii]);
                  if(!check){
                        com=-1;
                        break;
                  }
                  com+=(int)(txt[ii]);

            }
            if(com==total)
            {
                  if(bo)
                  {
                   printf("~");
                  }
                  for(int j=i;j<ii;j++)
                  {
                        bo=1;
                        printf("%c",txt[j]);
                  }
            }


      }
      return 0;


}
