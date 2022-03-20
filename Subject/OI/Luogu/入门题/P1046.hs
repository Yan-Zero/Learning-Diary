
main :: IO ()
main = do
  ls <- map read . words <$> getLine :: IO [Int]
  heigth <- (readLn :: IO Int)
  print $ sum (map (\x -> if x <= heigth + 30 then 1 else 0) ls)
