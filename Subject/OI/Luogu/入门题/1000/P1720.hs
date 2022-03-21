
main=readLn>>=putStrLn.(++".00").show.(!!)fib where fib=0:1:zipWith(+)fib(tail fib)
