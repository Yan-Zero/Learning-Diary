
main :: IO ()
main = readLn >>= putStrLn.unwords.(\x -> ["Today, I ate", show x, if x <= 1 then "apple." else "apples."])
