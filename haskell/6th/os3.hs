main = print $ os 99

os n = if n == 1 then 1 else map (n ^ 2 + (n - 1) ^ 2) $ [1..n]
