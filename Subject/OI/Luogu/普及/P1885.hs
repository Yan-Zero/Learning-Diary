
get_char :: Int -> Int -> [Int] -> String
get_char 1 x _ = if x == 1 then "m" else "o"
get_char i x ls
  | x <= b = get_char (i-1) x ls
  | a <= b = get_char (i-1) (b-a) ls
  | otherwise = if x - b == 1 then "m" else "o"
  where a = ls !! (i - 1) - x
        b = ls !! (i - 2)

main :: IO ()
main = do
  (x: _) <- map read . words <$> getLine :: IO [Int]
  let t = map (\n -> 8 * 2^n - n - 5) [0..]
  let len = length (takeWhile (< x) t) + 1
  putStrLn $ get_char len x t
