#include<stdio.h>
#include<stdlib.h>

#define size 5

int queue[size]={0,0,0,0,0},top=-1;

void sort()
{
    int min,pos;
    for(int i=0;i<=top;i++)
    {
        min=queue[i];
        pos=i;
        for(int j=i+1;j<=top;j++)
        {
            if(min>queue[j])
            {
                min=queue[j];
                pos=j;
            }
        }
        int temp=queue[i];
        queue[i]=queue[pos];
        queue[pos]=temp;
    }
}

void main()
{
    int choice=0;
    
    do{
    printf("\nMENU:");
    printf("\n1) Insert");
    printf("\n2) Delete");
    printf("\n3) Display");
    printf("\n4) Exit");
    printf("\nEnter Choice : ");
    scanf("%d",&choice);
    
        switch (choice)
        {
        case 1: if(top==size-1)
                    break;
                
                int data;
                printf("\nEnter Data : ");
                scanf("%d",&data);
                
                if(top==-1)
                    queue[++top]=data;
                
                else{
                    queue[++top]=data;
                    sort();
                }

                break;

        case 2: if(top==-1)
                    printf("Underflow!");
                else{
                    for(int i=0;i<=top;i++)
                        queue[i]=queue[i+1];
                    top--;
                }
                break;

        case 3: if(top==-1)
                    printf("\nEmpty");
                else    
                    for(int i=0;i<=top;i++)
                        printf("%d\t",queue[i]);
                break;

        case 4: exit(0);

        default: printf("\nInvalid Choice");
        }
    }while(1);
}