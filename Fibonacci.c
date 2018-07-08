#include<stdio.h>
int fibonacci(int x)
{
    if (x<=1)
        return 1;
    else
        return ( fibonacci(x-1) + fibonacci(x-2) );
}

int main()
{
    int a,temp=0,count;

    printf("Enter how many sequence: ");
    scanf("%d",&a);
    for ( count = 1; count <= a ; count++ )
    {
        printf("%d", fibonacci(temp));
        printf(" ");
        temp=temp+1;
    }
    return 0;
}




