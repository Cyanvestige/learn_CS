; a procedure to compute the exponential of a number modulo another number 
(define (expmod base exp m)
  (cond ((= exp 0) 1)
        ((even? exp)
         (remainder 
           (square (expmod base (/ exp 2) m))
          m))
        (else
          (remainder
            (* base (expmod base (- exp 1) m))
        m))))
  
(define (fermat-test n)
  (define (try-it a)
    (= (expmod a n n) a))
  (try-it (+ 1 (random (- n 1)))))

(define (fast-prime? n times)
  (cond ((= times 0) true)
        ((fermat-test n) (fast-prime? n (- times 1)))
        (else false)))

(fast-prime? 6 10000)
https://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@github.com/Cyanvestige/my-website.git



$git clone https://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@github.com/Cyanvestige/my-website.git
