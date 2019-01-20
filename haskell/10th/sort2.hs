main = do
    args <- getArgs
    print $ mysort $ ((map read args)::[Int])

mysort::[Int] -> [Int]
mysort = foldl myinsert []

myinsert xs x = foldr f[x] xs
    where f z (y:ys) = if z > y then y:z:ys else z:y:ys
