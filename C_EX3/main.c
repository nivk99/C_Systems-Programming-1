
#include "my_string.h"
int main() 
{

      char *_txt=NULL,*_word=NULL,*txt=NULL,*word=NULL;

      txt=(char*)calloc(TXT+1,sizeof(char));
      _txt=(char*)calloc(TXT+1,sizeof(char));
      word=(char*)calloc(WORD+1,sizeof(char));
      _word=(char*)calloc(WORD+1,sizeof(char));

      if(!txt||!_txt||!word||!_word){

            exit(1);
      }

      txt[TXT]=END;
      _txt[TXT]=END;
      word[WORD]=END;
      _word[WORD]=END;

      int sum=0;
      char ch = 0;
      for(int i=0; i<WORD; i++)
      {
            scanf("%c",&ch);
            _word[i]=ch;
            word[i]=ch;
            if(!ch || ch == ' ' || ch == '\n' || ch == '\t')
            {
                  _word[i]=END;
                  word[i]=END;
                  break;
            }
            if(_word[i] >= 'a' && 'z' >= _word[i])
            {
                  _word[i]-=32;
            }
            if(_word[i] >= 'A' && 'Z' >= _word[i])
            {
                  sum += (_word[i]-('A'-1));
            }
      }

      ch =0;
      for(int i=0;i<TXT;i++)
      {
            scanf("%c",&ch);

            txt[i]=ch;
            _txt[i]=ch;
             if(ch == '~')
            {
                   txt[i]=END;
                  _txt[i]=END;
                  break;
            }
            
            if(_txt[i]>='a'&&'z'>=_txt[i])
            {
                  _txt[i]-=32;
            }
      }



GematriaSequences(txt,_txt,sum);
AtbashSequences(txt,_txt,_word);
AnagramSequences(txt,_txt,word);

free(txt);
free(_txt);
free(word);
free(_word);

return 0;
}
