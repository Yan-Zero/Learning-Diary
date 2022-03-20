
main :: IO ()
main = do
  (a: b: c: d: _) <- map read . words <$> getLine :: IO [Int]
  let dm = (d - b) `mod` 60
      dh = (c - a) + (d - b) `div` 60
  in  putStrLn $ show dh ++ " " ++ show dm
