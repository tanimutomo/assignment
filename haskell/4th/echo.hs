import System.Environment

main = do
    args <- getArgs
    putStrLn $ concat args
