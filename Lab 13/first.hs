--Comment
{- jiejf
 - efe
 - goijegiejgifej
 - eiojgifejfe
 -}
--Comment
{- jiejf
 - efe
 - goijegiejgifej
 - eiojgifejfe
 -}
import Data.List
import System.IO

maxint :: Int
maxint = maxBound::Int

--Float
--Double
--Bool
--Char
--Tuple


sumOfNums :: Integer
sumOfNums = sum[1..2133]

modabc :: Integer
modabc = mod 34 12

sumsd :: Integer
sumsd = 5+ (-4)

-- && || not()
-- :t to show info about various functions


{-
Typing practice nvm.
so what we are going to do today class is to go over various different parts of the lecture in a step by step manner and then discuss the programs.
-}

-- lists are singly linked and can only add elements to the end rather than to the beginning

-- Lists store many elements of the same type
primeNumbers :: [Integer]
primeNumbers = [3,5,7,11]
 
-- Concatenate lists (Can be slow if your using a large list)
morePrimes :: [Integer]
morePrimes = primeNumbers ++ [13,17,19,23,29]
 
-- You can use the cons operator to construct a list
favNums :: [Integer]
favNums = 2 : 7 : 21 : 66 : [] --seems like this is a retarded method

 
-- You can make a list of lists
multList :: [[Integer]]
multList = [[3,5,7],[11,13,17]]
 
-- Quick way to add 1 value to the front of a list
morePrimes2 :: [Integer]
morePrimes2 = 2 : morePrimes

lenPrime :: Int
lenPrime = length morePrimes2

{-
reverse
null
listname !! index, this returns the number at that index

just see the cheatsheet

Also, can create infinite lists but they are actually created only when needed/called

repeat value
and 
replicate times value
and
cycle

filter and map in a list. Good functions
sort
-}
-- You could perform operations on all values in a list
-- Cycle through the list storing each value in x which is multiplied by 2 and
-- then stored in a new list
listTimes2 :: [Integer]
listTimes2 = [x * 2 | x <- [1..10]]
 
-- We can filter the results with conditions
listTimes3 :: [Integer]
listTimes3 = [x * 3 | x <- [1..20], x*3 <= 50]
 
-- Return all values that are divisible by 13 and 9
divisBy9N13 :: [Integer]
divisBy9N13 = [x | x <- [1..500], x `mod` 13 == 0, x `mod` 9 == 0]
 
-- Sort a list
sortedList = sort [9,1,8,3,4,7,6]


{-
All functions begin with small letters and must return something





-}
