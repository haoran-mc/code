;尾递归其实就是一个循环
;函数调用不需要另一个函数在此函数之前声明
(define (fact-tail n)
  (fact-rec n n))

(define (fact-rec n p)
  (if (= n 1)
      p
      (let ((m (- n 1)))
    (fact-rec m (* p m)))))

(display (fact-tail 5))
(exit)
