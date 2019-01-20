import System.Environment

main = do
  args <- getArgs
  putStr $ unlines $ hello (map head args)) $ args

hello::String -> String -> String
hello h a = 
  unlines $ map 
hello name = "Hello, " ++ name ++ "!"

