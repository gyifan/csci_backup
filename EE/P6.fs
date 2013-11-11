// CSCI 208 Term Project F# - Phase 6
// Yifan Ge
// 4/22/2012

// This program is designed to demonstrate higher order function property of F#.
//
// In F#, similarly to other functional languages, functions are first-class values,
// meaning that htey can be used in a same ways as any other types. The following
// example defines a fold right functoin, an insert function, and an insert sort 
// function. The fold right function takes an function as input and returns an output.
// In the insert sort case, we pass insert as a parameter to fold right function
// to accomplish the purpose of insert sort.

let rec foldr f z list = 
    match list with 
    | []        -> z
    | h::tail   -> f h (foldr f z tail)

let rec insert e list =
    match list with
    | []        -> [e]
    | h::tail   -> if e<h then e::h::tail
                   else h::(insert e tail)

let insertionSort l = foldr insert [] l

let l = insertionSort [1;9;7;2;6]

System.Console.WriteLine(sprintf "%A" l)

// The output is the sorted list: [1;2;6;7;9]

(* References: 
    1. en.wikibooks.org/wiki/F_Sharp_Programming/Higher_Order_Functions
    2. http://tomasp.net/blog
    3. msdn.microsoft.com Microsoft F# Language Reference
*)