-- file: 03-13.hs
-- date: 2022/03/15

sum' :: Num a => [a] -> a
sum' [] = 0
sum' (x:xs) = x + sum' xs

last' :: [a] -> a
last' [] = error "The list is empty."
last' [x] = x
last' (_:xs) = last' xs

acc' :: Num a => a -> [a] -> [a]
acc' m (x:xs) = m : acc' (m+x) xs
acc' m _ = [m]

acc :: Num a => [a] -> [a]
acc = acc' 0

zip' :: [a] -> [b] -> [(a, b)]
zip' _ [] = []
zip' [] _ = []
zip' (a:as) (b:bs) = (a, b) : zip' as bs

comp :: (b->c) -> (a->b) -> a -> c
-- comp f g x = f (g x) or 
comp f g x = f $ g x

zipWith' :: (a -> b -> c) -> [a] -> [b] -> [c]
zipWith' f (a:as) (b:bs) = f a b : zipWith' f as bs
zipWith' _ _ [] = []
zipWith' _ [] _ = []

uncarry' :: (a->b->c) -> (a, b) -> c
uncarry' f (a, b) = f a b

fibs = 0 : 1 : zipWith (+) fibs (tail fibs)

fromTo :: Int -> Int -> [Int]
fromTo b e | b > e = []
           | otherwise = b : fromTo (b+1) e

length' :: [a] -> Int
length' [] = 0
length' (_:xs) = 1 + length' xs


data Expr a = Value a | Add (Expr a) (Expr a) | Sub (Expr a) (Expr a) | Mul (Expr a) (Expr a) deriving (Show)  

evaluate :: Num a => Expr a -> a
evaluate (Value a) = a
evaluate (Add a b) = evaluate a + evaluate b
evaluate (Sub a b) = evaluate a - evaluate b
evaluate (Mul a b) = evaluate a * evaluate b


data Tree a = Empty | Node a (Tree a) (Tree a) deriving (Show)

perorderTraversal :: Tree a -> [a]
perorderTraversal Empty = []
perorderTraversal (Node a l r) = a : perorderTraversal l ++ perorderTraversal r

middleorderTraversal :: Tree a -> [a]
middleorderTraversal Empty = []
middleorderTraversal (Node a l r) = perorderTraversal l ++ a : middleorderTraversal r

postorderTraversal :: Tree a -> [a]
postorderTraversal Empty = []
postorderTraversal (Node a l r) = postorderTraversal l ++ postorderTraversal r ++ [a]