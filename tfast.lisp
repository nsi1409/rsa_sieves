(defparameter *hash* (make-hash-table))

(print "enter integer value: ")
(setf n (read))
(setf found 0)

(setf low n)
(setf run_val 0)
(setf inc_val -1)

(defun check (temp temp_i)
	(if (not (gethash temp *hash*))
		(progn
			(setf (gethash temp *hash*) temp_i)
			)
		(progn
			(print "::") 
			(setf cur (solv temp_i (gethash temp *hash*) temp))
			(print cur)
			(handl cur)
			(print ":: low ::")
			(print low)
			)
		)
	)


(defun handl (inpt)
	(if (< inpt low)
		(setf low inpt)
		)
	)


(defun solv (fin_i0 fin_i1 fin_off)
	(setf outp (mod (- (* fin_i0 fin_i1) fin_off)  n))
	outp
	)


(defun psu_mod (npt)
	(if (>= npt n)
		(setf npt (- npt n))
		)
	npt
	) 


(defun set_run ()
	(setf inc_val (+ inc_val 2))
	(setf inc_val (psu_mod inc_val))
	(setf run_val (+ run_val inc_val))
	(setf run_val (psu_mod run_val))
	)

;(/ n 2) => (sqrt n) => n
(loop for i from 1 to n
	do (set_run)
	(check run_val i)
	)


