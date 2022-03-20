
main :: IO ()
main = getLine >>= putStrLn . reverse . (filter ((not).(`elem` "\n\r\t ")))
