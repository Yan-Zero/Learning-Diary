import Numeric

main :: IO ()
main = 
  (map read . words <$> getLine :: IO [Double]) >>= \(a: b: c: _) -> 
    let p = (a + b + c) / 2.0
    in putStrLn $ showFFloat (Just 1) ((p * (p - a) * (p - b) * (p - c)) ** 0.5) ""
