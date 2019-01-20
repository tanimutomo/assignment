import System.Environment

data Rat = Rat Integer Integer

instance Show Rat where
    show (Rat x y) = show x ++ "/" ++ show y

instance Num Rat where
    (Rat x y) + (Rat u v) = Rat (x * v + y * u) (y * v)
    (Rat x y) * (Rat u v) = Rat (x * u) (y * v)
    negate (Rat x y) = Rat (-x) y
    abs (Rat x y) = Rat (abs x) (abs y)
    signum (Rat x y) | x == 0    = fromInteger 0
                     | x * y > 0 = fromInteger 1
                     | otherwise = fromInteger (-1)
    fromInteger x = Rat x 1

main = do
    args <- getArgs
    let x = read (args !! 0)
    let y = read (args !! 1)
    let u = read (args !! 2)
    let v = read (args !! 3)
    print $ Rat x y + Rat u v
    print $ Rat x y - Rat u v
    print $ Rat x y * Rat u v
