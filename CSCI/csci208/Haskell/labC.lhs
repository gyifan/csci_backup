Yifan Ge
CSCI 208
Haskell C - 4/12/2012

Problem 12
1. map abs [Int]
2. map length [[Char]]

Problem 13

>import Data.Char

>zeroStrip :: [Char] -> [Char]
>zeroStrip [] = [];
>zeroStrip (x:xs) = 
>            if (x == '0') then zeroStrip xs
>                          else x:xs

string2Int :: [Char] -> Int -> Int
string2Int [] i = i;
string2Int (x:xs) i = (digitToInt x)*(10^(length xs)) + i

>string2Int :: Int -> Char -> Int
>string2Int i x = (digitToInt x)+i*10

>stringToInt :: [Char] -> Int
>stringToInt l = foldl string2Int 0 (zeroStrip l)

Problem 14

>stdDevExtend :: Float -> Float -> Float -> [Float] -> Float
>stdDevExtend sum sqSum num [] = sqrt (sqSumAv - sumAvSq)
>                   where sqSumAv = (1.0 / num) * sqSum
>                         sumAvSq = (sum / num) ^ 2
>stdDevExtend sum sqSum num (x:xs) = 
>                stdDevExtend (sum+x) (sqSum+(x^2)) (num+1.0) xs

>stdDev :: [Float] -> Float
>stdDev = stdDevExtend 0.0 0.0 0.0

Problem 15
1.

>insert :: Ord a => [a] -> a -> [a]
>insert ls x = [y | y <- ls, y <= x]
>              ++ [x]
>              ++ [y | y <- ls, y > x]

2.

>myMap :: (a -> b) -> [a] -> [b]
>myMap f ls = [y | x <- ls, let y = (f x)]

3.

>removemultiple :: [Int] -> Int -> [Int]
>removemultiple l x = filter (\y -> mod y x /= 0) l

>eratosthenes :: [Int] -> [Int]
>eratosthenes [] = []
>eratosthenes (x:xs) = x : eratosthenes (removemultiple xs x)

>prime :: Int -> [Int]
>prime m = 1 : (eratosthenes [2..m])

>factors :: Int -> [Int]
>factors x = [a | a <- (prime x), (mod x a) == 0]

Problem 16

>data Cplx = Complex Float Float
>
>addCplx :: Cplx -> Cplx -> Cplx
>
>addCplx (Complex r1 i1) (Complex r2 i2) = Complex r i
>          where r = r1 + r2
>                i = i1 + i2
>
>instance Show Cplx where
>  show (Complex r i) = "( " ++ (show r) ++ " + " ++ (show i) ++"i)"
>
>roots :: Int -> Int-> Int -> (Cplx, Cplx)
>roots x y z = let a = fromIntegral x
>                  b = fromIntegral y
>                  c = fromIntegral z in
>              let d = (b*b-4*a*c) in
>              if (d<0)
>              then let realP = (-b/(2*a))
>                       realN = realP
>                       imaginaryP = sqrt(-d)/(2*a)
>                       imaginaryN = -sqrt(-d)/(2*a) in
>                    (Complex realP imaginaryP,Complex realN imaginaryN)
>              else let realP = (-b+sqrt(d))/(2*a)
>                       realN = (-b-sqrt(d))/(2*a)
>                       imaginaryP = 0.0
>                       imaginaryN = 0.0 in
>                    (Complex realP imaginaryP, Complex realN imaginaryN)


