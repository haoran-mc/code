(define (read-file file-name)
  (let ((p (open-input-file file-name)))        ;p是端口
    (let loop((ls1 '()) (c (read-char p)))
      (if (eof-object? c)
          (begin
            (close-input-port p)
            (list->string (reverse ls1)))       ;reverse倒置表, list->string将表中元素以字符串形式输出
          (loop (cons c ls1) (read-char p)))))) ;呼应上文let中的loop

(display (read-file "hello.txt"))
(exit)
