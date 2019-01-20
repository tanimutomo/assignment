main = do
    cs <- getContents
    putStr $ concatMap toSfc cs

toSfc :: Char -> String
toSfc 'S' = "Shonan "
toSfc 'F' = "Fujisawa "
toSfc 'C' = "Campus "
toSfc c = [c]
