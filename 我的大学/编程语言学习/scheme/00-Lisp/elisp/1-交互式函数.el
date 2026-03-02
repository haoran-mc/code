(setq world "world") ;;定义一个变量

(defun hello ()
  (interactive) ;;交互式函数
  (message "hello %s" world))

(hello) ;;调用函数

(global-set-key (kbd "<f3>") 'hello) ;;绑定一个全局快捷键
