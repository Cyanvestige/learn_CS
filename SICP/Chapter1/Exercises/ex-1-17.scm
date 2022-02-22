;(define (mult-recur a b)
	;(define (mult-recur-helper a b res) 
		;(cond ((= 1 a) res)
			;  ((even? a) (mult-recur-helper (halve a) b (+ res (double b))))
			; (else (mult-recur-helper (- a 1) b (+ res b)))))
	;(mult-recur-helper a b 0))

(define (mult-recur a b)
	(cond ((= b 0) 0)
		  ((even? b) (double (mult-recur a (halve b))))
		  (else (+ a (mult-recur a (- b 1))))))

(define (double a)
	(+ a a))

(define (halve a)
	(/ a 2))

(mult-recur 3 5)