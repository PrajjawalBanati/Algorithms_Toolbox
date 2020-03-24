#include<stdio.h>
#include<stdlib.h>
int GreatestCommonDivisor(int firstnumber,int secondnumber);
int GreatestCommonDivisor(int firstnumber,int secondnumber)
{
    int gcd,remainder;
    if(firstnumber>secondnumber)
    {
        if(secondnumber==0)
        {
            gcd=firstnumber;
        }
        else
        {
            remainder=firstnumber%secondnumber;
            gcd=GreatestCommonDivisor(secondnumber,remainder);
        }
    }
    else
    {
        GreatestCommonDivisor(secondnumber,firstnumber);
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
