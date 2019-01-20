import System.Environment
main = do
    args <- getArgs
    putStrLn $ roman $ read $ head args

roman :: int -> String

roman n | n >= 100 = "M" ++ roman (n - 1000)
        | n 

