
main=getLine>>(map read.words)<$>getLine>>=print.(\t->(maximum t)-(minimum t))
