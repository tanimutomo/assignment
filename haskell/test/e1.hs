import System.Environment

main = do
  args <- getArgs
  putStr $ unlines $ map hello args

hello::String -> String
hello name = "Hello, " ++ name ++ "!"
