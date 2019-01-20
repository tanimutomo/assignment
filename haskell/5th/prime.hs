main = print $ take 100 $ filter isprime [1..]

factors n = filter divisible [1..n]
    where divisible m = n `mod` m == 0

isprime n = length(factors n) == 2
