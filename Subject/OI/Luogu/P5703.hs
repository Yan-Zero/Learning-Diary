-- readInts :: IO [Int]
-- readInts = map read . words <$> getLine
import Data.Char(toUpper)

main :: IO ()
main = do
  (c: _) <- getLine
  print $ toUpper c:[]