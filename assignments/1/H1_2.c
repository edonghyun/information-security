#include <stdio.h>

int main(void)
{
    char str[] = "WTAADLDGASXCUDGBPIXDCHTRJGXIN";
    char str2[29] ;

    int i= 0;
    int b=  0;

    for(b=0; b<26 ; b ++){
        for (i= 0 ; i <29 ; i++)
        {
           str2[i]=65+ (str[i]-b)%26; 
        }
        printf("insert %d : %s\n",b,str2);
    }
    return 0;

}

