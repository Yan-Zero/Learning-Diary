
main :: IO ()
main = do
  x <- readLn :: IO Int
  let cI = x `mod` 2 == 0
  let cII = x > 4 && x <= 12
  putStrLn . unwords $ map (\f -> if f then "1" else "0") [cI && cII, cI || cII, cI /= cII, (not cI) && (not cII)]

