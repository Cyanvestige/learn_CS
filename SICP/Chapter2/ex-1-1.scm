(define (make-rat2 n d) 
  
  (let ((g (gcd (abs n) (abs d))))
  (if (or (and (< 0 n)(< 0 d))
          (and (> 0 n)(< 0 d))) 
      (cons  (/ (- n) g) (/ (- d) g))
      (cons ( / n g) (/ d g)))))

(define (make-rat n d) 
        (define g (gcd n d)) 
        (let        ((simple-n (abs (/ n g))) 
                    (simple-d (abs (/ d g)))) 
                (cond 
                        ((> (* n d) 0) (cons simple-n simple-d)) 
                        ((< (* n d) 0) (cons (- simple-n) simple-d))))) 
(define (numer x) (car x))

(define (denom x) (cdr x))

(define (print-rat x)
  (newline)
  (display (numer x))
  (display "/")
  (display (denom x)))

(define one-half (make-rat 2 (- 4)))

(print-rat one-half)