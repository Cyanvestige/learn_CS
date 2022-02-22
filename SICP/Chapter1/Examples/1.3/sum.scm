(define (sum term a next b)
	(if (> a b)
			0
			(+ (term a) (sum term (next a) next b))))

(define (ident x) x)
  (define (sum-int a b)
	(sum (lambda(x) x) a 1+ b))

(sum-int 1 4)