(define (mult-iter a b)
	(define (mult-iter a b res)
		(cond ((= b 0) res)
		      ; if b is even, halve b and double a to implement "a times 2"
		      ((even? b) (mult-iter (double a) (halve b) res))
			  ; if b is odd, add the current a to result and decrement b
			  (else (mult-iter a (- b 1) (+ res a)))))
	(mult-iter a b 0))

;Russian Peasant Algorithm
(define (russian-peasant-mult a b)
	(define (mult-iter a b res)
		(cond ((= b 0) res)
			  ((even? b) (mult-iter (double a) (halve b) res))
			  (else (mult-iter (double a) (- (halve b) 0.5) (+ res a)))))
	(mult-iter a b 0))


(define (double a)
	(+ a a))

(define (halve a)
	(/ a 2))

(russian-peasant-mult 23 5)
(mult-iter 3 5)