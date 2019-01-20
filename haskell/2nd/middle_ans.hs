main = do
    cs <- getContents
    putStr $ unlines $ middleNLines 10 $ lines cs

takeNLines n ss = take n ss
lastNLines n ss = reverse $ take n $ reverse ss
countLines ss = length ss
middleNLines n ss = takeNLines n $ lastNLines ((countLines ss) `div` 2 + n `div` 2 ) ss
    
