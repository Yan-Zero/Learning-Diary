
quickSort :: (Ord a) => [a] -> [a]
quickSort [] = []
quickSort (x:xs) = quickSort [y | y <- xs, y <= x] ++ [x] ++ quickSort [y | y <- xs, y > x]

main :: IO ()
main = (map read.words<$>getContents::IO [Int])>>= \(t) -> do
  let (a:b:c:_) = quickSort t
  let ok b s = if x then putStrLn s else return ()
  if a + b <= c then putStrLn "Not triangle" else do
    ok (a^2 + b^2 == c^2) "Right triangle"
    ok (a^2 + b^2 < c^2)  "Obtuse triangle"
    ok (a^2 + b^2 > c^2)  "Acute triangle"
    ok (a == b || b == c) "Isosceles triangle"
    ok (a == b && b == c) "Equilateral triangle"
