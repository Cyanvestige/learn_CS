; sqrt
; when x is smaller than 0.0001 the original sqrt procedure test fails
; when x is bigger than 1e^58, the original sqrt procedure test fails

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

;new implementation of "good-enough?":
(define (good-enough? guess x)
  (< (/ (abs (- (improve guess x) guess)) guess) 0.001))

(define (sqrt-iter guess x)
  (if(good-enough? guess x)
    guess
    (sqrt-iter (improve guess x) x)))

(define (sqrt x)
  (sqrt-iter 1.0 x))

(sqrt 0.00001)
(sqrt 10000000000000000000000000000000000000000000000000000000000) 
