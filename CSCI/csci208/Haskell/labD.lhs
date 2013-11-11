Yifan Ge
CSCI 208
Haskell D - 4/19/2012

>import Data.Char

Problem 17

>type Memory = [Int]
>
>type Program = [Command]
>
>data Command = Add Int Int |
>               Sub Int Int |
>               Mul Int Int |
>               Div Int Int |
>               Exp Int Int |
>               Mod Int Int 
>               deriving (Show)

>calculate :: Int -> Program -> Memory
>calculate n prog = foldr operate mem prog
>                   where mem = [ 0 | x <- [1..n]]

>convert :: Command -> (Int -> Int -> Int, Int, Int)
>convert (Add a b) = ( (+), a, b)
>convert (Sub a b) = ( (-), a, b)
>convert (Mul a b) = ( (*), a, b)
>convert (Div a 0) = error "Dividing by zero!"
>convert (Div a b) = (quot, a, b)
>convert (Exp a b) =
>            if b<0 then error "Raising to a negative power!"
>            else ( quot, a, b)
>convert (Mod a 0) = error "Diving by zero!"
>convert (Mod a b) = ( rem, a, b)

>operate :: Command -> Memory -> Memory
>operate comm mem = 
>        if (length mem) < n then error "illegal memrory address!"
>        else h ++ [v] ++ t
>                   where
>                        h = take n mem -- n comes from 'comm'
>                        t = drop (n+1) mem
>                        v = op (mem !! n) a
>                        (op,n,a) = convert comm

Problem 18

>fact 0 = 1
>fact n = n * fact (n-1)
>choose :: Int -> Int -> Int
>choose n k = div (fact n) ((fact k)*(fact (n-k)))

>zeroStrip :: [Char] -> [Char]
>zeroStrip [] = [];
>zeroStrip (x:xs) =
>            if (x == '0') then zeroStrip xs
>                          else x:xs

>string2Int :: Int -> Char -> Int
>string2Int i x = (digitToInt x)+i*10

>stringToInt :: [Char] -> Int
>stringToInt l = foldl string2Int 0 (zeroStrip l)

>iChoose :: IO ()
>iChoose = do num1 <- getLine
>             num2 <- getLine
>             let answer = choose (stringToInt num1) (stringToInt num2)
>             putStrLn (show answer)

Problem 19

>countChar :: String -> IO()
>countChar str = putStr (show (length str))

>countWord :: String -> IO()
>countWord str = putStr (show (length (words str)))

>countLine :: String -> IO()
>countLine str = putStr (show (length (lines str)))

>wc :: String -> IO()
>wc name = do line <- readFile name
>             countLine line
>             putStr "\t"
>             countWord line
>             putStr "\t"
>             countChar line
>             putStr (" " ++ name)

Problem 20
1. a) Empty
   b) Node 5 Empty
   c) Node 5 (Node 3 (Node 1 Empty))
   d) Node 'H' (Node 'e' (Node 'l' (Node 'p' (Node '!' Empty))))

2. 
   Main> myHead (Node 1 (Node 2 Empty))
   1
   Main> myTail (Node 1 (Node 2 Empty))
   Node 2 Empty

3. 

>data MyList a = Empty |
>                Node a (MyList a)
>                deriving Show

>myHead :: MyList a -> a
>myHead (Node n rest) = n

>myTail :: MyList a -> MyList a
>myTail (Node n rest) = rest

>myFilter :: (a -> Bool) -> (MyList a) -> (MyList a)
>myFilter f Empty = Empty
>myFilter f (Node n Empty) = if (f n) then (Node n Empty) else Empty
>myFilter f (Node n rest) = if (f n) then (Node n (myFilter f rest))
>                           else (myFilter f rest)

>funtion :: Int -> Bool
>funtion t = if t > 0 then True else False

4.

>myDrop :: Int -> (MyList a) -> (MyList a)
>myDrop 0 a = a
>myDrop t Empty = if (t /= 0) then error "not enough elements"
>                 else Empty
>myDrop t (Node n rest) = myDrop (t-1) rest

Problem 21

>data Tree a = Null |
>              Branch a (Tree a) (Tree a)
>              deriving Show

>treeInsert :: (Ord a) => Tree a -> a -> Tree a
>treeInsert Null v = Branch v Null Null
>treeInsert t@(Branch n ltree rtree) v
>            | v < n     = Branch n (treeInsert ltree v) rtree
>            | v > n     = Branch n ltree (treeInsert rtree v)
>            | otherwise = t

>treeBuild' :: (Ord a) => Tree a -> [a] -> Tree a 
>treeBuild' tree [] = tree
>treeBuild' tree (v:vs) = treeBuild' (treeInsert tree v) vs

>treeBuild :: (Ord a) => [a] -> Tree a
>treeBuild = treeBuild' Null

1.

>listBuild :: (Ord a) => Tree a -> [a]
>listBuild Null = []
>listBuild (Branch n ltree rtree) = (listBuild ltree)
>                                   ++ [n]
>                                   ++ (listBuild rtree)

2.

>sort :: (Ord a) => [a] -> [a]
>sort list = listBuild (treeBuild list)

3.

>treeMap :: (a -> b) -> (Tree a) -> (Tree b)
>treeMap f Null = Null
>treeMap f (Branch a ltree rtree) = Branch (f a) (treeMap f ltree) (treeMap f rtree)
