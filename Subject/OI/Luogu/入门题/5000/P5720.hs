
main :: IO ()
main = (readLn::IO Int)>>=print.floor.(+1).logBase 2.fromIntegral
