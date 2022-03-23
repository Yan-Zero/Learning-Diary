
main=readLn>>=putStrLn.unwords.map show.reverse.solve where solve x = if x==1 then [1] else if x`mod`2==0 then x:solve (x`div`2) else x:solve (x*3+1)
