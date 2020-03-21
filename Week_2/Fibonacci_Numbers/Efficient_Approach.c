#include<stdio.h>
#include<stdlib.h>
unsigned long fibonacci(int n);
unsigned long fibonacci(int n)
{
    unsigned long* f=(unsigned long*) malloc(n*sizeof(unsigned long));
    unsigned long result;
    int i=2;
    f[0]=0;
    f[1]=1;
    for(i=2;i<n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    result=f[n-1];
    return result;
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
