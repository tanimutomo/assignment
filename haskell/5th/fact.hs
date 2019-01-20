main = print $ map fact [1..100]

fact 0 = 1
fact n = n * (fact (n - 1))
