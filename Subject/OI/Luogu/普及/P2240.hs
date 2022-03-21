import Text.Printf

mergeSort :: Ord a => [(a, a)] -> [(a, a)]
mergeSort [] = []
mergeSort [x] = [x]
mergeSort xs = merge (mergeSort left) (mergeSort right)
  where
    (left, right) = splitAt (length xs `div` 2) xs
    merge :: Ord a => [(a, a)] -> [(a, a)] -> [(a, a)]
    merge [] ys = ys
    merge xs [] = xs
    merge (x:xs) (y:ys)
        | fst x > fst y = x : merge xs (y:ys)
        | otherwise = y : merge (x:xs) ys

main :: IO ()
main = splitAt 1.map(map(read::String->Double).words).lines<$>getContents >>= \([(_:t:_)], ls)->
  let ts = mergeSort $ map (\[m,v]->(v/m, m)) ls
      get_max_value :: Double -> [(Double, Double)] -> Double
      get_max_value x [] = 0
      get_max_value x ((v, m):ys)
          | m < x = get_max_value (x - m) ys + v * m
          | otherwise = v * x
  in printf "%.2f" $ get_max_value t ts
