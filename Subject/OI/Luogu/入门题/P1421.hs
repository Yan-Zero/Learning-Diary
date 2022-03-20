
main :: IO ()
main = (map read . words <$> getLine :: IO [Int]) >>= \(a: b: _) -> 
    let total = 10 * a + b
    in print $ total `div` 19
