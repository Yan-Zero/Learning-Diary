
main :: IO ()
main = (map read . words <$> getLine :: IO [Int]) >>= \(m: t: s: _) -> 
        if t == 0 then print 0 else print $ max 0 (m - s `div` t - 1 * (s `mod` t))
