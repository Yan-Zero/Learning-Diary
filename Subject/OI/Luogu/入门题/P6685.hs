
main :: IO ()
main = (map read.words<$>getLine::IO [Double])>>=(\[n,m]->print.floor $ n ** (1/m))
