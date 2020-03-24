# Fibonacci Series
- Fibonacci series is a sequence of numbers in which each number is the sum of the previous all numbers. Series start with 0,1,1,2,3... and so on.
- Mathematically it could be shown as:-
  ``` 
         {0 if n=0
  F(n) = {1 if n=1
         {F(n-1)+F(n-2) if n>1
  
  ```
  - So to code the following algorithm we have two approaches:-
    - <b>Naive Approach</b> 
      - In Naive Approach we will simply follow a recursive strategy in which we will call the same function in the function defination itself.
      - So lets have a look at the function.
      ```
      unsigned long fibonacci(int n)
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
      ```
      - So lets know the reason why it will work slow when supplied with large arguements. As you can observe it is following a recursive strategy so in all cases it will calculate same value numerous times.
        ![img](https://github.com/PrajjawalBanati/Algorithms_Toolbox/blob/master/Capture.PNG)
      - So in the above picture we are calculating the nth fibonacci number, so to calculate it will follow a recursive tree strategy. The thing which we are doing wrong here is we are calculating some values again and again. Looking at the figure you could see that F(n-4) is calculated constantly for 5 times which is <b>making the algorithm slow and time consuming</b>.
    - <b>Efficient Approach</b>
      - In Efficient Approach we will try to store the previous values so that at the time of finding the next values we will not again calculate the previous values. So let us look at the function we designed.
      ```
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
      ```
      - So here at first we are allocating memory equal to the positon which is passed as an arguement to the function. So after allocating the memory we initialized the first two numbers as 0 and 1 in 1st and 2nd position as they will be the fist two fibonacci numbers.
      - After that we run a loop till `n` that keeps on calculating and storing the fibonacci numbers in the array. Here once the number is calculated and stored will be fetched if needed again as it will be on some positon in the array. This will definately reduce the time as we will not calculate same value again and again. 
# Greatest Common Divisor
- Greatest common divisor of two numbers is the number which divides both the numbers with no remainders left. Following the defination we can proceed to write the function and we have two approaches to solve the problem. They are described as follows:-
	- <b>Naive Approach</b>
		- In Naive Approach, Suppose we have two numbers and we want to calculate the GCD so what we will do is iterate from 0->(a+b) and try every possibilty and the number which is the greatest is stored in the variable and returned.
		- So lets have a look on the function.
		```
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
		```
		- Now this algo will definately will work slow when we have 20-digit numbers because you know the loop will last longer and thus trying each possiblity and storing will take time. So lets try different approach but to learn that approach you should be familiar with one mathematical Key Lemma that is.
		```
		Suppose that we have two numbers and let a' be the remainder when a is divided by b, then the gcd(a,b) is actually the same as the gcd(a',b), and also the same as the gcd(b, a').
		```
		- Lets discuss the Key Lemma First and then design our new approach.
	- <b>Key Lemma</b>
		- According to the statement we stated above is the KEY LEMMA which was designed by Euclid. It says that if we have two numbers a,b and on dividing a with b if we get a remainder a' then the gcd(a,b) and gcd(b,a') will be equal. So after a certain number of iterations there will be a point when we will be left with gcd(d,0) stating that d is the gcd. Lets look at the following example.
			![img](https://github.com/PrajjawalBanati/Algorithms_Toolbox/blob/master/Capture_1.PNG)
		- In the above picture you can see that we started with two numbers as 3918848 and 1653264. And following the lemma rule we arrived at our result. So lets do the coding part now.
	- <b>Efficient Approach</b>
		- So after we understood the lemma lets frame our function. We will simply write a condition that when second number is 0 return the first number as gcd otherwise divide the two numbers, store the remainder and at last pass the second number and remainder as two arguements in the same function. So yeah here we will follow the recursive strategy. So lets see the function now.
		```
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
		```
		- So yeah this will be more efficient as there will no long loops only some continous calls and the function will be in less recursions.
