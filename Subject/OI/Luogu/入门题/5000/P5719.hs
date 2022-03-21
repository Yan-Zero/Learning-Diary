import Text.Printf

main :: IO ()
main = (map read.words<$>getLine::IO [Integer]) >>= \([n,k])->
  let a = filter ((==0).(`mod`k)) [1..n]
      b = filter ((/=0).(`mod`k)) [1..n]
      divf :: Integral a => a -> Int -> Double
      divf x y = (fromIntegral x) / (fromIntegral y)
  in  printf "%.1f %.1f" (divf (sum a) (length a)) (divf (sum b) (length b))
