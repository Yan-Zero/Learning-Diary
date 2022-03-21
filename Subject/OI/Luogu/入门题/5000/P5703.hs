 
main :: IO ()
main = (map read . words <$> getLine :: IO [Int]) >>= print . (\[a,b] -> a * b)
