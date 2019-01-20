import System.Environment
import Data.List

main = do
    args <- getArgs
    cs <- getContents
    putStr $ fgrepm args cs

fgrepm patterns cs = unlines $ filter matchAll $ lines cs
    where
        matchAll line = all matchone patterns
            where
                -- match :: String -> Bool
                matchone pattern = any prefixp $ tails line
                    where
                        -- prefixp :: String -> Bool
                        prefixp line = isPrefixOf ps $ line
