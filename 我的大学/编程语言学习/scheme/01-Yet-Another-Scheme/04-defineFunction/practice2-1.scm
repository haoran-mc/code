;;;Convert angle system to radian system

(define Pi (* 4 (atan 1.0)))

(define change
  (lambda (parameter)
    (* (/ parameter 180) Pi)))