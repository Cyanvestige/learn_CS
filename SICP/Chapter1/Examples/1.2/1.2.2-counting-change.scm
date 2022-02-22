(define (count-change amount) (cc amount 5)) ; user api(public method)
(define (cc amount kinds-of-coins)
  (cond ((= amount 0) 1) ; if we want to get 0, there is only one way
        ; if the amount we want to get is less than 0 or there are no any coins at all, there is no way for the condition
        ((or (< amount 0) (= kinds-of-coins 0)) 0) 
        ; the total number of the ways to get the value with given coins equals to 
        ; number of ways that we use any of the coin X + number of ways that we do not use any of the coin X
        (else (+ (cc amount
                     (- kinds-of-coins 1))
                 (cc (- amount 
                           (first-denomination
                            kinds-of-coins))
                        kinds-of-coins)))))
(define (first-denomination kinds-of-coins)
  (cond ((= kinds-of-coins 1) 1)
        ((= kinds-of-coins 2) 5)
        ((= kinds-of-coins 3) 10)
        ((= kinds-of-coins 4) 25)
        ((= kinds-of-coins 5) 50)))

(count-change 5)

