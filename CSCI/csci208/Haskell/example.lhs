Yifan Ge
CSCI 208
Haskell D - 4/19/2012

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
>calculate n prog = foldl operate mem prog
>                   where mem = [ 0 | x <- [1..n]]

>convert :: Command -> (Int -> Int -> Int, Int, Int)
>convert (Add a b) = ( (+), a, b)
>convert (Sub a b) = ( (-), a, b)
>convert (Mul a b) = ( (*), a, b)
>convert (Div a b) = ( quot, a, b)
>convert (Exp a b) = ( (^), a ,b)
>convert (Mod a b) = ( rem, a, b)

>operate :: Memory -> Command -> Memory
>operate mem comm = h ++ [v] ++ t
>                   where
>                        h = take n mem -- n comes from 'comm'
>                        t = drop (n+1) mem
>                        v = op (mem !! n) a
>                        (op,n,a) = convert comm

>getALine :: String -> IO ()
>getALine str = do putStr str
>                  line <- getLine
>                  putStrLn line
