
mergeSort :: Ord a => [a] -> [a]
mergeSort [a] = [a]
mergeSort [] = []

mergeSort xs = let
  mLen = length xs `div` 2
  l = mergeSort $ take mLen xs
  r = mergeSort $ drop mLen xs
  in merge l r

quickSort :: Ord a => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort [a|a<-xs,a<x] ++ (x:[a|a<-xs,a==x]) ++ quickSort [a|a<-xs,a>x]

isPrime :: Int -> Bool
isPrime x = x >= 2 && all ((/= 0) . (x `rem`)) (takeWhile (\y -> y * y <= x) [2..])

merge :: Ord a => [a] -> [a] -> [a]
merge (x:xs) (y:ys)
  | x <= y = x : merge xs (y:ys)
  | x > y = y : merge (x:xs) ys
merge [] ys = ys
merge xs [] = xs
