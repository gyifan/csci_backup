>data MyList a = Empty |
>                Node a (MyList a)
>                deriving Show

>myHead :: MyList a -> a
>myHead (Node n rest) = n

>myTail :: MyList a -> MyList a
>myTail (Node n rest) = rest
