import System.Environment

main = do
    args <- getArgs
    print $ mysort $ map read args

mysort :: [Int] -> [Int]
mysort [] = []
mysort (x:xs) = myinsert x (mysort xs)

myinsert :: Int -> [Int] -> [Int]
myinsert x [] = [x]
myinsert x (y:ys) = if x > y then y:(myinsert x ys) else x:y:ys
