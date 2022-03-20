
main :: IO ()
main = (map read . words <$> getLine :: IO [Int]) >>= \(a: b: c: _) ->
        print $ (a * 2 + b * 3 + c * 5) `div` 10
