import System.Environment

main = do
  args <- getArgs
  print $ romanChar $ head $ head args

romanChar :: Char -> Int
romanChar 'I' = 1
romanChar 'V' = 5
romanChar 'X' = 10
romanChar 'L' = 50
romanChar 'C' = 100
romanChar 'D' = 500
romanChar 'M' = 1000

