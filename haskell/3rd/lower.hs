main = do
    cs <- getContents
    putStr $ map lower cs

lower :: Char -> Char
lower 'A' = 'a'
lower 'B' = 'b'
lower 'C' = 'c'
lower 'D' = 'd'
lower 'E' = 'e'
lower 'F' = 'f'
lower 'G' = 'g'
lower 'H' = 'h'
lower 'I' = 'i'
lower 'J' = 'j'
lower 'K' = 'k'
lower 'L' = 'l'
lower 'M' = 'm'
lower 'N' = 'n'
lower 'O' = 'o'
lower 'P' = 'p'
lower 'Q' = 'q'
lower 'R' = 'r'
lower 'S' = 's'
lower 'T' = 't'
lower 'U' = 'u'
lower 'V' = 'v'
lower 'W' = 'w'
lower 'X' = 'x'
lower 'Y' = 'y'
lower 'Z' = 'z'
lower c = c
