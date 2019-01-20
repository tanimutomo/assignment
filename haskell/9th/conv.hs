-- (++) :: [a] -> [a] -> [a]
-- (++) [] ys = ys
-- (++) (x:xs) ys = xs : ((++) xs ys)

-- append xs ys = foldr (++) xs ys
--
main = do
    print $ sum2 $ [1, 2, 3]

sum2 = foldr (+) 0

