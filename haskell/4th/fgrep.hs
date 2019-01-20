import System.Environment
import Data.List

main = do
    args <- getArgs
    cs <- getContents
    putStr $ fgrep (head args) cs

fgrep :: String -> String -> String
fgrep pattern cs = unlines $ filter match $ lines cs
    where
        match line = any prefixp $ tails line
        prefixp line = isPrefixOf pattern $ map lower line

lower::Char -> Char
lower 'A' = 'a'
lower 'B' = 'b'
lower 'C' = 'c'
lower 'D' = 'd'
lower 'E' = 'e'
lower 'F' = 'f'
lower 'G' = 'g'
lower 'H' = 'h'
lower 'I' = 'i'
lower 'L' = 'l'
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
