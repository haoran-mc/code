(setq my-var 1)
(setq my-var (+ 1 my-var))

(defmacro inc1 (var)
  (list `setq var (list `1+ var)))

(inc1 my-var) ;;add a new language

(macroexpand `(inc1 my-var)) ;;expand macro

(defun inc-var (var)
  (setq var (1+ var)))

(inc-var my-var)


;;----------------------------------------------------------------

(defun my-print-1 (number)
  (message "This is a number: %d" number))

(my-print-1 2)
(my-print-1 (+ 2 3))

(defmacro my-print-2 (number)
  `(message "This is a number: %d" ,number))

(my-print-2 2)
(my-print-2 (+ 2 3))

(setq my-var 2)
(inc1 my-var)

(defmacro inc2 (var1 var2)
  (list `progn (list `inc1 var1) (list `inc1 var2)))

(macroexpand `(inc2 my-var my-var))
(macroexpand-all `(inc2 my-var my-var))

(defun prelude-search (query-url prompt)
  "Open the search url constructed with the QUERY-URL.
PROMPT sets the `read-string prompt."
  (browse-url
   (concat query-url
           (url-hexify-string
            (if mark-active
                (buffer-substring (region-beginning) (region-end))
              (read-string prompt))))))

(defmacro prelude-install-search-engine (search-engine-name search-engine-url search-engine-prompt)
  "Given some information regarding a search engine, install the interactive command to search through them"
  `(defun ,(intern (format "prelude-%s" search-engine-name)) ()
       ,(format "Search %s with a query or region if any." search-engine-name)
       (interactive)
       (prelude-search ,search-engine-url ,search-engine-prompt)))

(prelude-install-search-engine "google"     "http://www.google.com/search?q="              "Google: ")
(prelude-install-search-engine "youtube"    "http://www.youtube.com/results?search_query=" "Search YouTube: ")
(prelude-install-search-engine "github"     "https://github.com/search?q="                 "Search GitHub: ")
(prelude-install-search-engine "duckduckgo" "https://duckduckgo.com/?t=lm&q="              "Search DuckDuckGo: ")

(pp (macroexpand `(.....)))
