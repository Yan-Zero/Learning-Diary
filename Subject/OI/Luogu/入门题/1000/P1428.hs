solve :: [Int] -> [Int] -> [Int]
solve [] _ = []
solve (x:xs) ls = (foldl (\a t -> if t < x then a + 1 else a) 0 ls): solve xs (x:ls)

main=getLine>>(map read.words)<$>getLine>>=putStrLn.unwords.map show.((flip solve) [])
