
main :: IO ()
main = (map read.words<$>getLine::IO [Int])>>=\t->
  let maxi = maximum t
      mini = minimum t
      gcd' = gcd maxi mini
  in  putStrLn $ show (maxi `div` gcd') ++ "/" ++ show (mini `div` gcd')
