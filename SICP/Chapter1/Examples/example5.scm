;conditional expressions and predicates
(define (abs x)
(cond ((> x 0) x)
((= x 0) 0)
((< x 0) (- x))))
;(cond (⟨p1⟩⟨e1⟩)
      ;(⟨p2⟩⟨e2⟩)
      ;...
      ;(⟨pn⟩⟨en⟩))
      ;Clauses->first expression is interpreted as ture or false)

;with "else"
(define (abs x)
  (cond ((< x 0) (- x))
    (else x)))

;use "if":
(define (abs x)
  (if (< x 0) 
    (- x)
      x))