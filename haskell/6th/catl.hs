import System.Environment

main = do
    args <- getArgs
    cs <- getContents
    -- print $ sum $ map read args
    putStr $ numbering (map read args) cs

numbering :: [Int] -> String -> String
numbering ls cs = unlines $ map format $ filter (selectLine ls) $ zipLineNumber $ lines cs

selectLine :: [Int] -> (Int, String) -> Bool
selectLine ls (n, line) = any match ls
    where 
        match x = if x == n then True else False  

zipLineNumber :: [String] -> [(Int, String)]
zipLineNumber xs = zip [1..] xs

format :: (Int, String) -> String
format (n, line) = rjust 4 (show n) ++ "0" ++ line

rjust :: Int -> String -> String
rjust width s = replicate (width - length s) '0' ++ s
