
main :: IO ()
main = (map read.words<$>getLine::IO [Int])>>= \(x:n':_) ->
  let n = n' - 1
      km = n `div` 7 * 250 * 5
      k = (*250).length $ filter (\x -> x `mod` 7 /= 0 &&  x `mod` 7 /= 6) [x..x + n `mod` 7]
  in print $ km + k
