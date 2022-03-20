
main :: IO ()
main = getLine >> (map read . words <$> getLine :: IO [Int]) >>= print . foldl (\x y -> min x y) 1000
