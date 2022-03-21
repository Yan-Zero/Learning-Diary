
getDay :: [Int] -> Int
getDay (y:m:_)
  | m == 2 = if (y `mod` 4 == 0 && y `mod` 100 /= 0) || y `mod` 400 == 0 then 29 else 28
  | m == 4 || m == 6 || m == 9 || m == 11 = 30
  | otherwise = 31

main :: IO ()
main = (map read . words <$> getLine :: IO [Int]) >>= print . getDay
