import System.Environment

main = do
    args <- getArgs
    print $ mysort $ map read args

myinsert :: Int -> [Int] -> [Int]
myinsert x [] = [x]
myinsert x (y:ys) = if x < y then x:y:ys else y:myinsert x ys

mysort :: [Int] -> [Int]
mysort = foldr myinsert []
