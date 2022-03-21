
main=reverse<$>getLine>>=print.(read::String->Int).(\n->if(last n)/='-' then n else(('-':).init)n)
