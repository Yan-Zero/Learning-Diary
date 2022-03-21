
main :: IO ()
main = (map read.words<$>getLine :: IO [Int]) >>= \([n, i]) ->
  let ch  = head $ show i
  in print $ foldl (\t y -> foldl (\t z-> if z==ch then t+1 else t) t (show y)) 0 [1..n]
