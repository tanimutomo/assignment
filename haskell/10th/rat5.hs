class Num a where
    (+) :: a -> a -> a
    (*) :: a -> a -> a
    negate :: a -> a
    abs :: a -> a
    signum :: a -> a
    fromInteger :: Integer -> a 

instance Num Rat where
    (Rat x y) + (Rat u v) = Rat (x * u + y * v) (y * v)
    (Rat x y) * (Rat u v) = Rat (x * u) (y * v)
    negate (Rat x y) = Rat (- x) y
    abs (Rat x y) = Rat (abs x) (abs y)
    signum (Rat x y) | x == 0 = fromInteger 0
                     | x * y > 0 = fromInteger 1
                     | otherwise = fromInteger (-1)
    fromInteger x = Rat x 1

main = print $ Rat 1 2 + Rat 1 6
