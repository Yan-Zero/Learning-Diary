

reverse' :: [a] -> [a]
reverse' xs = foldl (flip (:)) [] xs
-- flip (:) := \xs x -> x : xs

reverse'' :: [a] -> [a]
reverse'' xs = 
  helper xs []
  where
    helper [] ys = ys
    helper (x:xs) ys = helper xs (x:ys)

