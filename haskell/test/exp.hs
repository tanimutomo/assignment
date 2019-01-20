-- import System.Environment
-- 
-- main = do
--   args <- getArgs
--   print $ head $ head args
-- 
import System.Environment

main = do
  args <- getArgs
  putStr $ space $ map head args


space::String -> String
space c = c ++ ' '



