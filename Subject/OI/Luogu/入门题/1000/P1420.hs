f (x, y, z) w 
  | w == x + 1 && y + 1 >= z = (w, y + 1, y + 1)
  | w == x + 1 && y + 1 < z = (w, y + 1, z)
  | w /= x + 1 = (w, 1, z)
main=getLine>>(map read.words)<$>getLine>>=trd.foldl f (0,0,0) where trd (a,b,c) = print c