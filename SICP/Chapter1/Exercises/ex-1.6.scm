;sqrt

(define (new-if predicate then-clause else-clause)
	(cond (predicate then-clause)
		(else else-clause)))

(define (abs x)
  (if (< x 0)
    (- x)
      x))

(define (square x)
  (* x x))

(define (average x y)
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))

(define (good-enough? guess x)
  (< (abs(- (square guess) x)) 0.001))

(define (sqrt-iter guess x)
  (if(good-enough? guess x)
    guess
    (sqrt-iter (improve guess x) x)))

(define (sqrt x)
  (sqrt-iter 1.0 x))

(sqrt 4) 
(sqrt 0.00001)
(sqrt 1000000000000000000000000000000000000) 

; Aborting!: maximum recursion depth exceeded