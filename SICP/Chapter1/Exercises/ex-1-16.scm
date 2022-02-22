(define (fast-expt-iter b n)
	(define (iter-helper n b a)
		(cond ((= n 0) a) 
		      ((even? n) (iter-helper (/ n 2) (square b) a))
			  (else (iter-helper (- n 1) b (* a b)))))
	(iter-helper n b 1))

	
(fast-expt-iter 2 5)