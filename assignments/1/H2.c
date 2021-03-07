#include <stdio.h>

int main(void)
{
    char str[] = "EGPKQQMVSQPJWTQIVMWPWMEYZKXG";
    char str2[28] ;
    char key[]="AA@";

    int i= 0;
    int b=  0;
    while(1){
       key[2] ++; 
      if(key[2] =='[')
      {
        key[1]++;
        key[2] = 'A';
        
        printf("\n");
      }
      if(key[1] =='[')
      {
          key[0]++;
          key[1]='A';
      }
      if(key[0]=='[')
          break;
     
          for (i= 0 ; i <28 ; i++)
         {
             if((str[i]-key[i%3])<0)
             {
                str2[i] = 65 + (str[i]-key[i%3])%26 + 26; 
             }else{
                str2[i]=65 + (str[i]-key[(i%3)])%26; 
             }
         }
          if(str2[0] = 'W')
         {
              printf("Key : %s : %s\n",key,str2);
         }
    }

    return 0;

}

