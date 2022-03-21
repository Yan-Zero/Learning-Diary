
main :: IO ()
main = readLn >>= putStrLn.(\x -> if x >= 6 then "Luogu" else "Local")
