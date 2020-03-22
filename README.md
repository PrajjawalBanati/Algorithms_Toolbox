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
        ![img](https://github.com/PrajjawalBanati/Algorithms_Toolbox/blob/week_2/Capture.PNG)
      - So in the above picture we are calculating the nth fibonacci number, so to calculate it will follow a recursive tree strategy. The thing which we are doing wrong here is we are calculating some values again and again. Looking at the figure you could see that F(n-4) is calculated constantly for 5 times which is <b>making the algorithm slow and time consuming</b>.
