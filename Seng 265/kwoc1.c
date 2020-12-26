/*

Name: Gurik Manshahia

Student ID: V00863509

Assignment 1: kwoc1.c

Class: Seng265

Date: 2020/02/13

*/

 

#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <stdio.h>

#define MAXCHAR 1000

#define LINE_LENGTH 1000

#define KEYS_LENGTH 1000

#define PHRASE_LENGTH 1000

 

int num_words = 0;

int num_keys = 0;

char words[PHRASE_LENGTH][LINE_LENGTH];

char key[PHRASE_LENGTH][LINE_LENGTH];

 

 

void store_the_words(char *line){

  char buffer[MAXCHAR];

  char *t;

 

  strncpy(buffer,line,MAXCHAR);

  t = strtok(buffer," \n");

  while(t != NULL){

    strncpy(words[num_words],t,MAXCHAR);

    num_words++;

    t = strtok(NULL, " \n");

  }

}

void store_the_keys(char *line){

  char buffers[MAXCHAR];

  char *m;

  strncpy(buffers,line,MAXCHAR);

  m = strtok(buffers," \n");

  while(m != NULL){

    strncpy(key[num_keys],m,MAXCHAR);

    num_keys++;

    m = strtok(NULL, " \n");

  }

}

int word_compare(char *haystack, char *needle){

char buf[MAXCHAR];

char *w;

int num_occur = 0;

strncpy(buf,haystack,MAXCHAR);

w = strtok(buf, " ");

while(w != NULL){

  if(strcmp(needle,w) == 0){

    return 1;

  }

  w = strtok(NULL, " ");

 

 }

return 0;

}

 

int num_occurrences(char *haystacks, char *needles)

{

    char buff[MAXCHAR];

    char *q;

    int  num_occurs = 0;

 

    strncpy(buff, haystacks, MAXCHAR);

 

    q = strtok(buff, " ");

    while (q != NULL) {

        if (strcmp(needles, q) == 0) {

            num_occurs++;

        }

        q = strtok(NULL, " ");

    }

 

    return (num_occurs);

}

 

 

int compare_int(const void* a,const void*b){

  return strcmp((const char *)a, (const char *)b);

}

 

char *uppercase(char *wordd){

 

  char *s = wordd;

     while(*s)

    {

        *s = (*s >= 'a' && *s <= 'z') ? *s-32 : *s;

        s++;

    }

    return wordd;

}

char *lowercase(char *lower){

  char *y = lower;

  while(*y){

    *y = (*y >= 'A' && *y <= 'Z') ? *y+32 : *y;

        y++;

 }

}

 

int main(int argc, char *argv[]) {

    int num_occur =0;

    int j =0;

    char str[MAXCHAR];

    char strsentence[MAXCHAR][LINE_LENGTH];

    char str1[MAXCHAR];

    int count = 0;

    FILE *fptr,*fp2;

    char new_word [MAXCHAR][MAXCHAR];

 

    fptr = fopen(argv[3],"r");

    fp2 = fopen(argv[2],"r");

    //sentence

  if(strcmp(argv[1], "-e") == 0){

    while(fgets(str,MAXCHAR,fptr) != NULL){

      strncpy(strsentence[count],strtok(str, "\n"),MAXCHAR);

      count++;

 

    }

 

    //put exclusion words in an array

    char keys[MAXCHAR][LINE_LENGTH];

    int main_idx = 0;

    while(fgets(str1,MAXCHAR,fp2) != NULL){

      strncpy(keys[main_idx],str1,MAXCHAR);

      main_idx++;

    }

  

 

    while(j<count){

    store_the_words(strsentence[j]);

    j++;

    }

    j=0;

    while(j<main_idx){

      store_the_keys(keys[j]);

      j++;

    }

 

      int x = 0;

      int y = 0;

      int r = 0;

      int in_eng = 0;

             int count2 =0;

    while(x<num_words){

          y=0;

      while(y<main_idx){

        if(strcmp(words[x],key[y]) ==  0) {

          in_eng = 1;

        }

        y++;

      }

      if (in_eng == 0 && strcmp(words[x], " ") != 0){

        strncpy(new_word[r],words[x],1000);

        count2++;

        r++;

      }

      x++;

      in_eng = 0;

    }

 

    qsort(new_word,count2,sizeof(*new_word),compare_int);

char dup [MAXCHAR][MAXCHAR];

int counter3 = 0;

for(int x = 0;x<count2;x++){

 if(strcmp(new_word[x],dup[x-1]) != 0) {

    strncpy(dup[x],new_word[x],1000);

counter3++;

  }

}

 

for(int i = 0;i<counter3+3;i++){

  for(int j =0;j<count;j++){

  

     if(word_compare(strsentence[j],dup[i]) != 0){

      num_occur = num_occurrences(strsentence[j],dup[i]);

    if(num_occur>1){

   printf("%s    %s  (%d*)\n",uppercase(dup[i]), strsentence[j],j+1);

    }

else{

   printf("%s    %s  (%d)\n",uppercase(dup[i]), strsentence[j],j+1);

      }

      lowercase(dup[i]);

     if(word_compare(strsentence[j],dup[i]) == 0){

      break;

     }

    }

 

  }

}

}

 

    fclose(fp2);

    fclose(fptr);

    return 0;

 

}
