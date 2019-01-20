main = do
    cs <- getContents
    putStr $ numbering cs

numbering cs = unlines $ map format $ zipLineNumber $ lines cs

zipLineNumber xs = zip [1..] xs

format (n, line) = rjust 4 (show n) ++ " " ++ line

rjust width s = replicate (width - length s) ' ' ++ s
