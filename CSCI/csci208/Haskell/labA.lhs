This file contains the definition for the factorial function.

fact :: Int -> Int  --this specifies the type of the function fact

>fact 0 = 1
>fact n = n * fact (n-1)

Problem 1

1) Expression: div (fact 10) ((fact 5)*(fact (10-5)))

2) a)
    After commenting out fact 0 = 1, the fact function does not a base case. As a result, when
    we evaluate fact 4, GHC comes to a infinite loop.

   b)
    If we didn't have parentheses around fact (n-1), GHC will still evaluate fact (n-1) first.
    However, if we didn't have parentheses around n-1, GHC will do fact n first and then minus 1.

3) 

>choose :: Int -> Int -> Int
>choose n k = div (fact n) ((fact k)*(fact (n-k)))

4) fact 50 gives a large negative number. And choose 50 5 gives a 0.

5) 

choose2 :: Int -> Int -> Int

>choose2 0 k = 0
>choose2 n 1 = n
>choose2 n k = (choose2 (n-1) (k-1)) + (choose2 (n-1) k)

6) Yes, it works if we comment out the type description. Otherwise fact 50 is too big. It also
   takes a little longer to computer since there are a lot of recursive calls.

7) They work. This is because GHC will assign the type while interpreting the code.

8) 

>fib :: Int -> Int
>fib 0 = 1
>fib 1 = 1
>fib n = fib (n-1) + fib (n-2)

Problem 2

>fibsel :: Int -> Int
>fibsel n = if (n==0)||(n==1)
>              then 1
>              else fibsel (n-1) + fibsel (n-2)

Problem 3

>fibcase :: Int -> Int
>fibcase n = case n of
>                 0 -> 1
>                 1 -> 1
>                 n -> fibcase (n-1) + fibcase (n-2)

Problem 4
1)

>grade :: Int -> Char
>grade n
>      | ((n>=0)&&(n<=59))   = 'F'
>      | ((n>=60)&&(n<=69))  = 'D'
>      | ((n>=70)&&(n<=79))  = 'C'
>      | ((n>=80)&&(n<=89))  = 'B'
>      | ((n>=90)&&(n<=100)) = 'A'
>      | otherwise           = 'E'

2)

>abs2 :: Int -> Int
>abs2 n
>     | n<0       = (-n)
>     | otherwise = n

Problem 5

>hyp :: Int -> Int -> Float
>hyp a b = sqrt (fromIntegral (a*a) + fromIntegral (b*b))






