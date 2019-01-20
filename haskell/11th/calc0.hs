module Token(Token(..),tokens) where

import Data.Char

data Token = Num Integer | Add | Sub | Mul | Div
             deriving Show
data Rat = Rat Integer Integer

tokens::String -> [Token]
tokens [] = []
tokens ('+':cs) = Add:(tokens cs)
tokens ('-':cs) = Sub:(tokens cs)
tokens ('*':cs) = Mul:(tokens cs)
tokens ('/':cs) = Div:(tokens cs)
tokens (c:cs) | isDigit c = let (ds,rs) = span isDigit (c:cs)
                            in Num(read ds):(tokens rs)

data ParseTree = Number Integer |
                 Invert Integer |
                 Plus ParseTree ParseTree |
                 Minus ParseTree ParseTree |
                 Time ParseTree ParseTree |
                 Divide ParseTree ParseTree
                 deriving Show

type Parser = [Token] -> (ParseTree, [Token])

parseNumber::Parser
parseNumber (Num x:l) = (Number x, l)

parseTerm::Parser
parseTerm l = nextNumber $ parseNumber l
    where nextNumber x = x

parseExpr::Parser
parseExpr l = nextTerm $ parseTerm l
    where nextTerm (p1, Mul:l1) = let (p2, l2) = parseTerm l1
                                  in nextTerm(Time p1 p2, l2)
          nextTerm (p1, Div:l1) = let (p2, l2) = parseTerm l1
                                  in nextTerm(Divide p1 p2, l2)
          nextTerm (p1, Add:l1) = let (p2, l2) = parseTerm l1
                                  in nextTerm(Plus p1 p2, l2)
          nextTerm (p1, Sub:l1) = let (p2, l2) = parseTerm l1
                                  in nextTerm(Minus p1 p2, l2)
          nextTerm x = x

-- 乗算と除算を最初に計算するように実装できなかった．

instance Show Rat where
    show (Rat x 1) = show x
    show (Rat x y) = show x ++ "/" ++ show y

instance Num Rat where
    (Rat x y) + (Rat u v) = Rat (x * v + y * u) (y * v)
    (Rat x y) * (Rat u v) = Rat (x * u) (y * v)
    -- (Rat x y) `div` (Rat u v) = Rat (x * v) (y * u)
    negate (Rat x y) = Rat (-x) y
    abs (Rat x y) = Rat (abs x) (abs y)
    signum (Rat x y) | x == 0    = fromInteger 0
                     | x * y > 0 = fromInteger 1
                     | otherwise = fromInteger (-1)
    fromInteger x = Rat x 1

eval::ParseTree -> Rat
eval(Number x) = Rat x 1
eval(Invert x) = Rat 1 x
eval(Plus p1 p2) = eval p1 + eval p2
eval(Minus p1 p2) = eval p1 - eval p2
eval(Time p1 p2) = eval p1 * eval p2
eval(Divide p1 p2) = eval p1 * Invert (eval p2)
-- eval(Divide p1 p2) = eval p1 `div` eval p2

-- Divideをどう書けばいいかわからないです．Numクラスに新しく定義するのはできないですよね？

main = do
    cs <- getContents
    putStr $ unlines $ map (show . fst . parseExpr . tokens) $ lines cs
