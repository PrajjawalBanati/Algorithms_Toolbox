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
