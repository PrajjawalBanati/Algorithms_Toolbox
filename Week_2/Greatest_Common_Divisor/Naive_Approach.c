#include<stdio.h>
#include<stdlib.h>
int GreatestCommonDivisor(int firstnumber,int secondnumber);
int GreatestCommonDivisor(int firstnumber,int secondnumber)
{
    int gcd=0,i;
    for(i=1;i<firstnumber+secondnumber;i++)
    {
        if((firstnumber%i==0) && (secondnumber%i==0))
        {
            gcd=i;
        }
    }
    return gcd;
}
int main()
{
    int firstnumber,secondnumber,gcd;
    printf("Enter Numerator and Denominator respectively. \n");
    scanf("%d",&firstnumber);
    scanf("%d",&secondnumber);
    gcd=GreatestCommonDivisor(firstnumber,secondnumber);
    printf("The greatest common divisor is %d",gcd);
}
