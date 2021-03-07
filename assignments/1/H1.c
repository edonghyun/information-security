#include <stdio.h>

int main(void)
{
    char str[] = "WTAADLDGASXCUDGBPIXDCHTRJGXIN";
    int i= 0;
    int b=  0;

    for(b=0; b<26 ; b ++){
    for (i= 0 ; i <29 ; i++)
    {
        if(str[i]+1 > 90)
        {
          str[i]=64+(str[i]+1-90);   
        }else{
          str[i]=str[i]+1;
        }
    }
        printf("insert %d : %s\n",b,str);
    }
    return 0;

}

