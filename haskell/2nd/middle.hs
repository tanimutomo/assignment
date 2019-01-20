main = do 
    cs <- getContents
    putStr $ unlines $ takeNLines 10 $ lines cs

takeNLines n ss = take n ss
lastNLines n ss = reverse $ take n $ reverse ss
countLines ss = length ss
middleNLines n ss = takeNLines n $ lastNLines ((countLines ss) `div` 2 + n `div` 2 ) ss
    putStr $ takeNLines 10 (((length $ lines cs) `div` 2) + 5) cs

takeNLines n m cs = unlines $ reverse $ take 10 $ reverse $ take m $ lines cs

