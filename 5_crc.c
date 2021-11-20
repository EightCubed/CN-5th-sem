#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define size 4

int divisor[size]={1,1,0,1},dividend[size],remdr[size],msg[100],counter=0;

void print_remdr()
{
    printf("\nRemainder: ");
    for(int i=0;i<size;i++)
        printf("%d",remdr[i]);
}

void perform_xor()
{
    for(int i=0;i<size;i++)
    {
        remdr[i]=dividend[i]^divisor[i];
        dividend[i]=remdr[i];
    }
}

void perform_crc(int len)
{
    for(int i=0;i<size;i++)
        dividend[i]=msg[i];
    
    for(int i=0;i<len-size;i++)
    {
        if(dividend[0]==divisor[0])
            perform_xor();

        for(int temp=0;temp<size-1;temp++)
            dividend[temp]=dividend[temp+1];
        dividend[size-1]=msg[i+size];
    }
}

void convert(char c)
{
    char str[8]="";

    if(isalpha(c))
    {
        strcat(str,"011");
        int num=(c-'a')+1;
        for(int i=7;i>=3;i--)
        {
            if(num%2==1)
                str[i]='1';
            else
                str[i]='0';

            num=num/2;
        }
    }

    else if(c==' ')
        strcat(str,"00100000");

    else if(isdigit(c))
    {
        strcat(str,"0011");
        int num=(c-'0');
        for(int i=7;i>=4;i--)
        {
            if(num%2==1)
                str[i]='1';
            else
                str[i]='0';

            num=num/2;
        }
    }

    for(int i=0;i<8;i++,counter++)
    {
        if(str[i]=='1')
            msg[counter]=1;
        else
            msg[counter]=0;
    }
}

void main()
{
    char str[25]="",divis[size]="1101";
    printf("\nEnter Message : ");
    fgets(str,sizeof(str),stdin);

    int len=strlen(str);

    for(int i=0;i<len;i++)
        convert(str[i]);

    for(int i=0;i<counter-8;i++)
    {
        if(i%8==0)
            printf("\t");
        printf("%d",msg[i]);
    }
    perform_crc(counter);

    print_remdr();
}