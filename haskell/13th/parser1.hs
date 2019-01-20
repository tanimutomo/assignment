import Control.Applicative

instance Functor Parser where
  fmap f p = Parser (\cs -> do (v, cs1) <- parse p cs 
                               return (f v, cs1))
