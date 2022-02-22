;recursively
(define (pascal-recur r c)
  (if (or (= c 0) (= c r)) 
      1
      (+ (pascal-recur (- r 1) (- c 1)) (pascal-recur (- r 1) c))))



;iteratively
(define (factorial n)
    (fact-iter 1 1 n))

(define (fact-iter product counter max-count)
    (if (> counter max-count)
        product
        (fact-iter (* counter product)
                   (+ counter 1)
                   max-count)))

(define (pascal-iter row col)
    (/ (factorial row) 
        (* (factorial col) 
           (factorial (- row col)))))

(pascal-iter 10 6)

(pascal-recur 10 6)

(pascal-iter 50 6)

(pascal-recur 50 6)