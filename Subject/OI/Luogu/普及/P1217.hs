isPrime :: Int -> [Int] -> Bool
isPrime x table = x >= 2 && all ((/= 0) . (x `rem`)) (takeWhile (\y -> y * y <= x) table)

merge :: Ord a => [a] -> [a] -> [a]
merge (x:xs) (y:ys)
  | x <= y = x : merge xs (y:ys)
  | x > y = y : merge (x:xs) ys
merge [] ys = ys
merge xs [] = xs

main :: IO ()
main = do
  (a: b: _) <- map read . words <$> getLine :: IO [Int]
  let evens = map ((\t -> read $ t ++ (reverse $ t)) . show) [1..] :: [Int]
  let odds = map ((\t -> read $ t ++ drop 1 (reverse $ t)) . show) [1..] :: [Int]
  let primeTable = let s (p:l) = p: s[x | x <- l, mod x p/=0]
                     in s [2..]
  let p = filter (\x -> x >= a && isPrime x primeTable) $ takeWhile (<= b) (merge evens odds)
  putStrLn . unlines $ map show p
