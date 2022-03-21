
main :: IO ()
main = readLn >>= \n -> 
  let a = 1: map ((2*).(+1)) a
  in print $ a !! (n - 1)
