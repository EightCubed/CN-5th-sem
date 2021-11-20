#include<stdio.h>
#include<stdlib.h>
#define size 5

int table[size][size],sum[size];

void initialize()
{
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            table[i][j]=0;
}

void print_table()
{
    printf("MSG :\n");
    for(int i=0;i<size;i++)
    {   
        for(int j=0;j<size;j++)
            printf("\t%d",table[i][j]);
        printf("\n");
    }
}

void print_checksum(char str[])
{
    printf("\n%s:\n",str);
    for(int i=0;i<size;i++)
        printf("\t%d",sum[i]);
}

void ones_complement()
{
    for(int i=0;i<size;i++)
    {
        if(sum[i]==0)
            sum[i]=1;
        else
            sum[i]=0;
    }
    int carry=1;

    for(int i=size-1;i>0;i--)
    {
        sum[i]+=carry;
        carry=0;
        if(sum[i]>=2)
            {carry=1;
             sum[i]=sum[i]%2;}
    }
    print_checksum("CHECKSUM");
}

void perform_checksum(char msg[])
{
    int k=0,carry=0;

    for(int i=0;i<size;i++)
        for(int j=0;j<size&&msg[k]!='\0';j++)
            {
                if(msg[k]=='0')
                    table[i][j]=0;
                else
                    table[i][j]=1;
                k++;
            }

    print_table();

    for(int i=size-1;i>=0;i--)
    {
        sum[i]+=carry;
        carry=0;
        for(int j=0;j<size;j++)
                sum[i]+=table[j][i];
        if(sum[i]>=2)
            {carry=1;
             sum[i]=sum[i]%2;}
    }
    print_checksum("SUM");
}

void main()
{
    char msg[100]="011110000100001";

    initialize();

    printf("\nEnter Message : \n");
    //scanf("%s",&msg);

    perform_checksum(msg);

    ones_complement();
}