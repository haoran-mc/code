(define ls '(#\1 #\2 #\3 #\4 #\5 #\6 #\7 #\8 #\9 #\0)) ;必须使用引用, 必须是字符
(write ls)
(display (list->string (reverse ls))) ;list->string使表中元素转化为字符串
(exit)
