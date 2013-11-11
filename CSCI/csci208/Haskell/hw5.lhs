>ack :: Int -> Int -> [Int]  -> Int
>ack 0 n l = case l of
>                 []       -> (n+1)
>                 (x:ls)   -> ack x (n+1) ls
>ack m 0 l = ack (m-1) 1 l
>ack m n l = ack m (n-1) ((m-1):l)
