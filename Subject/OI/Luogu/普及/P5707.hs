import Text.Printf

main :: IO ()
main = (map read . words <$> getLine :: IO [Double]) >>= \(s:v:_) ->
  let t = ceiling (s / v + 10) :: Int
      b = if t `mod` 60 == 0 then 0 else 1
  in  if t > 480 
        then let t' = t - 480
                 h = 24 - t' `div` 60 - b
                 m = 60 * b - t' + 60 * (t' `div` 60)
              in putStrLn $ printf "%02d:%02d" h m
        else putStrLn $ printf "%02d:%02d" (8 - t `div` 60 - b) (60 * b - t `mod` 60)

