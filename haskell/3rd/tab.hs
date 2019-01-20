main = do
    cs <- getContents
    putStr $ unlines $ map addTab $ lines cs

addTab :: String -> String
addTab ss = "\t" ++ ss

