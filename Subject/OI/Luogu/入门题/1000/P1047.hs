readInts :: IO [Int]
readInts = map read . words <$> getLine

loop :: [Int] -> Int -> IO ()
loop x i = do
  if i == 0
    then print $ length x
    else do
      t <- readInts
      let (l: r: _) = t
      let y = filter (\x -> x < l || x > r) x
      loop y $ i-1

main :: IO ()
main = do
  (n: m: _) <- readInts
  let l = [0..n]
  loop l m
