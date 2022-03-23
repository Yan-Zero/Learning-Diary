
main=readLn>>=(\(x, k)->print x>>print k).last.(\(a)->[(x, k)|x<-[1..100], k<-[1..100], x+3*k==a]).(`div` 364)
