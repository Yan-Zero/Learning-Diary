import Numeric

main :: IO ()
main = do
  (str: str': []) <- words <$> getLine
  let t = (read str) :: Double
  let n = (read str') :: Double
  let result = t / n
  putStrLn $ showFFloat (Just 3) result "" 
  print $ round (n * 2)
