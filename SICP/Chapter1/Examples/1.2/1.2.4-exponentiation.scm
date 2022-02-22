(define (recursive-expt b n)
  (if (= n 0)
  1 ; if the exponent is 0, answer is b^0 = 1
  (* b (recursive-expt b (- n 1))))) ; otherwise, answer is b^n = b * b^(n-1)

(define (iterative-expt b n)(expt-iter b n 1))
(define (expt-iter b counter product)
        (if (= counter 0) 
         product
        (expt-iter b (- counter 1) (* b product))))

(define (fast-expt b n)
  (cond((= n 0) 1)
       ((even? n) (square (fast-expt b (/ n 2))))
       (else (* b (fast-expt b (- n 1)))))) 
(define (even? n)
  (= (remainder n 2) 0))

(recursive-expt 8 2)
(iterative-expt 8 2)
(fast-expt 8 2)