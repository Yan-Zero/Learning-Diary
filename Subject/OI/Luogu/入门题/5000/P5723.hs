primeTable = let s (p:l) = p: s[x | x <- l, mod x p/=0]
             in s [2..]

tp _ [] = []
tp n (x:xs) = if (x <= n) then x : tp (n-x) xs else []

main :: IO ()
main = (readLn :: IO Int) >>= \n -> do
  let l = tp n primeTable
  putStr $ unlines $ map show l
  print $ length l
