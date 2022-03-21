
main :: IO ()
main = readLn>>=(\(n)->print$sum$take n$mconcat$[replicate x x|x<-[1..]])
