#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define size 5

int input[size]={4,5,3,1,2},output_rate=2,bucket_size[5],top=-1,dumped=0;

int bucket_full_check()
{
    if(top<size-1)
        return 0;
    printf("\nBucket FULL!");
    return 1;
}

int bucket_empty()
{
    if(top==-1)
        return 1;
    return 0;
}

void main()
{
    for(int i=0;i<size;i++)
    {
        printf("\n\nTIME : %d",i+1);
        while( input[i]>0 )
        {
            if (bucket_full_check()==0)
            {
                bucket_size[++top]=1;
                input[i]--;
                printf("\nElement Added into Bucket");
            }
            else
            {
                printf("\nElement DUMPED!");
                input[i]--;
                dumped++;
            }
        }

        int k=0;
        
        while( (bucket_empty()==0) && k<output_rate )
        {
            printf("\nElement Popped out of Bucket");
            k++;
            top--;
        }
        printf("\nElements in Bucket = %d",top+1);
        char x=getch();
    }
    printf("\n\nElements Dumped : %d",dumped);
}