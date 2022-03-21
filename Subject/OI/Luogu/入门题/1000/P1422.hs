import Text.Printf

main :: IO ()
main = (read <$> getLine :: IO Double) >>= \x -> 
  printf "%.1f" $ f x
  where f x
          | x <= 150 = 0.4463 * x
          | x <= 400 = 0.4663 * (x - 150) + f 150
          | otherwise = 0.5663 * (x - 400) + f 400
