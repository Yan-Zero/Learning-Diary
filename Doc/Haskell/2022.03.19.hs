reverse' :: [a] -> [a]
reverse' xs = foldl (flip (:)) [] xs
-- flip (:) := \xs x -> x : xs

reverse'' :: [a] -> [a]
reverse'' xs = 
  helper xs []
  where
    helper [] ys = ys
    helper (x:xs) ys = helper xs (x:ys)


cutList :: [a] -> [Int] -> [[a]]
cutList xs (i:is) = 
  let (ys, zs) = splitAt i xs
  in ys : cutList zs is
cutList [] _ = []


data Tree a = Empty | Leaf a | Node Int (Tree a) (Tree a) deriving (Show)

buildTree :: [a] -> Tree a
buildTree [] = Empty
buildTree [x] = Leaf x
buildTree xs = 
  let (ys, zs) = splitAt (length xs `div` 2) xs
  in Node (length xs) (buildTree ys) (buildTree zs)
