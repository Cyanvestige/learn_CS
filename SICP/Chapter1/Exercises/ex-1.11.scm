(define (recursion n)
		(if (< n 3) 
			n 
			(+ (+ (recursion (- n 1))(* 2 (recursion (- n 2))) (* 3 (recursion (- n 3)))))))

(define (iteration n)(iter-helper 2 1 0 n))
(define (iter-helper x y z n)
		(if (= n 0)
			z
			(iter-helper (+ (+ x (* 2 y)) (* 3 z)) x y (- n 1))))	

(iteration 10)		
(recursion 10)
(iteration 30)
(recursion 30)