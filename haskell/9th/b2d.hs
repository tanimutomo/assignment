import System.Environment

main = do
    args <- getArgs
    print $ b2d $ head args

bit::Char -> Int
bit '0' = 0
bit '1' = 1

b2d::String -> [Int]
b2d n = map  $ map bit n


