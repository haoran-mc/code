(define ls (list 0 1 2 3 4 5 6 7 8 9))
(display (car ls))
(display (cdr ls))

(define ls '((1 2) (3 4 5) (6 7 8 9)))
(display (car ls))
(display (cdr ls))

(define tree '((1 2) (3 4 5) (6 7 8 9)))
(write "")
(display (car tree))
(display (cdr tree))
(write "")

(set-car! (car tree) 100)  ;(set-car! '(1 2) 100)
(display tree)
(set-cdr! (third tree) '(a b c)) ; changing  '(7 8 9) to '(a b c)
(display tree)

(exit)
