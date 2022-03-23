
main=(map read.words<$>getLine::IO [Int])>>=putStrLn.unwords.map show.tail.reverse
