Examples:

>fancyDiv :: Int -> Int -> (Int, Int)

>fancyDiv n m = if (m==0)
>		then error "Tried to divide by zero"
>		else (n `quot` m, n `rem` m)

Using 'where' keyword to define division

>fancyDiv2 :: Int -> Int -> (Int, Int)
>fancyDiv2 n m = if (m==0)
>			then error "Tried to divide by zero\n"
>			else (quotient, remainder)
>		where
>			quotient = n `quot` m
>			remainder = n `rem` m

>fst :: (a, b) -> a
>fst (x, y) = x

>snd :: (a, b) -> b
>snd (x, y) = y

revHead ls = (head (tail ls)) : ((head ls) : (tail (tail ls)))

>revHead l = if length l < 2
>		then l
>		else e2 : (e1 : t2)
>	where
>		e1 = head l
>		t1 = tail l
>		e2 = head t1
>		t2 = tail t1

Example 6

>revH :: [a] -> [a]
>revH []	= []
>revH [x]	= [x]
>revH (x:y:rest)= y:x:rest

Example 7

>insert' :: Int -> [Int] -> [Int]
>insert' n [] = [n]
>insert' n (x:rest) = 
>          if n < x then n:x:rest
>                   else x: (insert' n rest)

Problme 6:
1.
This program implement a function that will take three integer parameters,
representing the coefficients of a quadratic equation, and return the two
roots of the equation, if there are any. If there is no real roots, an error
message will be given.

>roots :: Int -> Int -> Int -> (Float, Float)
>roots x y z = if ((b *b -4* a*c)<0)
>			then error "No real roots\n"
>			else ((-b+sqrt(b*b-4*a*c))/(2*a), (-b-sqrt(b*b-4*a*c))/(2*a))
>		where
>			a = fromIntegral x
>			b = fromIntegral y
>			c = fromIntegral z

2.
This program implement a function that will return all the complex roots.

>allRoots :: Int -> Int -> Int -> ((Float, Float),(Float, Float))
>allRoots x y z = let a = fromIntegral x
>                     b = fromIntegral y
>                     c = fromIntegral z in
>		  let d = (b*b-4*a*c) in
>		  if (d<0)
>                 then let realP = (-b/(2*a))
>		           realN = realP
>			   imaginaryP = sqrt(-d)/(2*a)
>			   imaginaryN = -sqrt(-d)/(2*a) in
>			((realP, imaginaryP),(realN, imaginaryN))
>                 else let realP = (-b+sqrt(d))/(2*a)
>			   realN = (-b-sqrt(d))/(2*a)
>			   imaginaryP = 0.0
>			   imaginaryN = 0.0 in
> 			((realP, imaginaryP),(realN, imaginaryN))        

Problem 7:
The number of reductions for head [1..10]; head [1..100] and head [1..1000]
stayed the same at 60. However, the number of reduction for tail [1..n] increases
with n. But after we test head (tail [1..n]) the reduction number go back to
a constant number 58. This indicate the excessive reduction of tail [1..n] is
caused by print on the terminal.

Problem 8:
1.

>firstLast :: [a] -> [a]
>firstLast l = if length l == 0
>                 then error "Invalid input"
>                 else if length (tail l) == 0
>                         then []
>                         else init (tail l)

2:

>strip :: Int -> [a] -> [a]
>strip n l = if length l < (2*n)
>               then error "Invalid input"
>               else take nl (drop n l)
>            where nl = (length l) - 2*n

3:

>mrg :: [Int] -> [Int] -> [Int]
>mrg n m
>      | length n == 0 = m
>      | length m == 0 = n
>      | head n < head m = head n : (mrg (tail n) m)
>      | otherwise = head m : (mrg n (tail m))

Problem 9:
Pattern    Argument   Succeeds?        Bindings
   1          1          yes            1 = 1
   2          1           no
   x          1          yes            x = 1
  x:y        [1,2]       yes        x = 1, y = [2]
  x:y       [[1,2]]      yes      x = [1,2], y = []
  x:y      "Bucknell"    yes      x = 'B', y = "ucknell"
  x:y     ["Bucknell"]   yes      x = Bucknell, y = []
 x:y:z    [1,2,3,4,5]    yes      x = 1, y = 2, z = [3,4,5]
   x          []         yes            x = []
 [1,x]      [2,2]         no
   []       [2,2]         no
 (x,y)    [1,2,3,4]       no
((x:y),(z:w))            yes         x = 1, y = [],
       ([1],"Bucknell")             z = 'B', w = "ucknell"

Problem 10:

1:

>canon :: (Int, Int) -> (Int, Int)
>canon (_, 0) = error "Can't divide by zero!"
>canon (a, b) = (div a (gcd a b), div b (gcd a b))

>addRat :: (Int, Int) -> (Int, Int) -> (Int, Int)
>addRat (_, 0) (_, _) = error "Can't divide by zero!"
>addRat (_, _) (_, 0) = error "Can't divide by zero!"
>addRat (a, b) (c, d) = canon ((a*d + c*b),(b*d))

2: 

>mrg' :: [Int] -> [Int] -> [Int]
>mrg' [] m = m
>mrg' n [] = n
>mrg' (n:ns) (m:ms) =
>        if n < m then n:(mrg' ns (m:ms))
>                 else m:(mrg' (n:ns) ms)

Problem 11: 
1. Base case:
        For a singleton list [x], the list is sorted.
   Recursive case: 
        If the head is smaller then the head of the sorted tail,
        the list is sorted. Otherwise it's not.

>sorted :: [Int] -> Bool
>sorted [] = True
>sorted [x] = True
>sorted (l:ls) = 
>            if sorted ls && l < head ls then True
>            else False

2. Base case:
        For an empty list, sum is 0
   Recursive case:
        The sum is head plus the sum of the tail.

>mySum :: [Int] -> Int
>mySum [] = 0
>mySum (l:ls) = l + (mySum ls)
