;define an expression
(define (square x)(* x x))
(square 5)
(square (+ 1 7))
(define (sum-of-square x y)
  (+ (square x)(square y)))
(sum-of-square 3 4)