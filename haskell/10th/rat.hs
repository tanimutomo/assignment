import System.Environment

data Rat = Rat Integer Integer

instance Show Rat where
    show x = show (num x) ++ "/" ++ show (num y)

instance Num Rat where
    (+) :: a -> a -> a
    (Rat x y) + (Rat u v) = Rat (x * u + y * v) (y * v)

    (*) :: a -> a -> a
    (Rat x y) * (Rat u v) = Rat (x * u) (y * v)

    negate :: a -> a
    negate (Rat x y) = Rat (- x) y

    abs :: a -> a
    abs (Rat x y) = Rat (abs x) (abs y)

    signum :: a -> a
    signum (Rat x y) | x == 0    = fromInteger
                     | x * y > 0 = fromInteger 1
                     | otherwise = fromInteger (-1)

    fromInteger :: Integer -> a
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
