-- file: test.hs
-- date: 2022/03/13

g :: Num t => (t, t, t, t) -> t
g (a, b, c, d) = a * b + c - d
