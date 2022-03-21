
main :: IO ()
main = getContents >>= return.zip [1..].map(sum.map (read::String->Int).words).lines
   >>= print.fst.foldr (\(j,y) (i,x) -> if x > y then (i,x) else (j,y)) (0,9)

-- WHY WILL IT REPLACE WHEN X EQUALS 9?