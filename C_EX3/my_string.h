#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#define END '\0'
#define TXT 1024
#define WORD 30
int GematriaSequences(const char *txt, char *_txt, int sum);
int AtbashSequences(const char *txt,char *_txt,char *_word);
int AnagramSequences(const char *txt,char *_txt,const char *word);