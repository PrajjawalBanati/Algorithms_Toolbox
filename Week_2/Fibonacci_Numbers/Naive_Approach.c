#include<stdio.h>
#include<stdlib.h>
int fibonacci(int n);
int fibonacci(int n)
{
    if(n<=1)
    {
        return n;
    }
    else
    {
        return fibonacci(n-1)+fibonacci(n-2);
    }
}
int main()
{
    int n;
    unsigned long result;
    printf("Enter the position\n");
    scanf("%d",&n);
    result=fibonacci(n);
    printf("Fibonacci number at %d is %lu",n,result);

}
