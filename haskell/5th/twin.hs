main = print $ take 20 $ filter istwin $ map pair [1..]

pair :: Int -> (Int, Int)
pair x = (x, x+2)

istwin :: (Int, Int) -> Bool
istwin (x, y) = and[isprime x, isprime y]

factors n = filter divisible [1..n]
    where divisible m = n `mod` m == 0

isprime n = length(factors n) == 2

-- main = print $ take 20 $ map pair [1..]
-- 
-- pair :: Int -> (Int, Int)
-- pair x = (x, x+2)
-- 
-- istwin :: (Int, Int) -> Bool
-- istwin (x, y) = check m
-- 
-- check1 m = filter divisible n
--     where n = fst m
-- 
-- check2 m = filter divisible n
--     where n = snd m
-- 
-- divisible n = n `mod` [1..n] == 0
-- 
-- main = print $ take 20 $ filter istwin $ map pair [1..]
-- 
-- pair :: Int -> (Int, Int)
-- pair x = (x, x+2)
-- 
-- istwin :: (Int, Int) -> Bool
-- istwin (x, y) = filter divisible [x..y]
--     where divisible m = and[y `mod` m == 0, x `mod` m == 0]

-- istwin (x, y) = filter divisible [1..x] [1..y]
--     where divisible m n = and[x `mod` m == 0, y `mod` n == 0]

-- main = print $ take 100 $ map pair $ filter isprime [1..]
-- 
-- factors n = filter divisible [1..n]
--     where divisible m = n `mod` m == 0
-- 
-- isprime n = length(factors n) == 2
-- 
-- 
-- main = print $ take 100 $ filter isprime [1..]
-- 
-- factors n = filter divisible [1..n]
--     where divisible m = n `mod` m == 0
-- 
-- isprime n = length(factors n) == 2
