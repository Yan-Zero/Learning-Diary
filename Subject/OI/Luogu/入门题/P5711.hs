
main :: IO ()
main = readLn >>= print.(\x->if x then 1 else 0).(\x->(x `mod` 4 == 0 && x `mod` 100 /= 0)||(x `mod` 400 == 0))
