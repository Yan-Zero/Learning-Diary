
main :: IO ()
main = readLn >>= print . (\n -> n * (n-1) *(n-2) * (n-3) `div` 24)
