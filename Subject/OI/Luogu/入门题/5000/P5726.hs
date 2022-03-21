import Text.Printf

mergeSort :: [Int] -> [Int]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort left) (mergeSort right)
  where
    (left, right) = splitAt (length xs `div` 2) xs
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys)
      | x < y = x : merge xs (y:ys)
      | otherwise = y : merge (x:xs) ys

divf :: Integral a => a -> Int -> Double
divf x n = fromIntegral x / fromIntegral n

main=getLine>>(map read.words)<$>getLine>>=printf "%.2f".(\t->divf (sum t) (length t)).tail.init.mergeSort
