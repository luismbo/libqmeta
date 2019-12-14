(defpackage :libqmeta
  (:use :cl :cffi))

(in-package :libqmeta)

#+nil
(progn
  (ql:quickload :cffi)
  (setf (uiop:getenv "PATH")
	(format nil "D:\\opt\\Qt\\5.12.6\\mingw73_64\\bin;~a" (uiop:getenv "PATH")))
  (cffi:load-foreign-library "D:/opt/Qt/5.12.6/mingw73_64/bin/Qt5Cored.dll")
  (cffi:load-foreign-library "D:/opt/Qt/5.12.6/mingw73_64/bin/Qt5Widgetsd.dll")
  (cffi:load-foreign-library "Z:/src/qt-projects/build-libqmetaobject-Desktop_Qt_5_12_6_MinGW_64_bit-Debug/debug/libqmetaobject.dll"))

(define-foreign-library libqmeta
  (t (:default "libqmetaobject")))

;;;; QMetaType

(defcfun "q_meta_type_type" :int
  (name :string))

(defcfun "q_meta_type_meta_object_for_type" :pointer
  (type :int))

(defcfun "q_meta_type_type_name" :string
  (type :int))

;;;; QMetaObject

(defcfun "q_meta_object_new_instance" :pointer
  (meta-object :pointer)
  (argc :int)
  (types :pointer)
  (data :pointer))

(defcenum connection-type
  :auto
  :direct
  :queued
  :blocking-queued
  (:unique #x80))

(defcfun "q_meta_object_invoke_method" :boolean
  (object :pointer)
  (member :string)
  (mode connection-type)
  (return-type-name :string)
  (return-data :pointer)
  (argc :int)
  (types :pointer)
  (data :pointer))

(defvar *qapplication* nil)

#+nil
(defun make-qapplication (&rest args)
  (cond (*qapplication*)
        (t
         (let ((instance (#_QCoreApplication::instance)))
           (setf *qapplication*
                 (if (null-qobject-p instance)
                     (%make-qapplication (cons "argv0dummy" args))
                     instance)))
         *qapplication*)))

#+nil
(defun %make-qapplication (args &optional (guip t))
  (unless args
    (error "argv[0] not specified"))
  (mapc (lambda (arg) (check-type arg string)) args)
  (let* ((args (coerce args 'simple-vector))
         (argv
	   ;; Memory leak: This array must not be freed earlier than the
	   ;; QApplication.  Let's just leak it.
           (string-vector-to-char** args))
         (&argc
	   ;; Apparently this, too, needs to have extent for more than the ctor.
           (cffi:foreign-alloc :int)))
    (setf (cffi:mem-aref &argc :int) (length args))
    (let* ((qapplication
             (if guip
                 (#_new QApplication &argc argv)
                 (#_new QCoreApplication &argc argv)))
           (updated-argc (cffi:mem-aref &argc :int)))
      (values qapplication
              (char**-to-string-vector argv updated-argc nil)))))

(defun find-meta-object (type-name)
  (let ((type (q-meta-type-type (format nil "~a*" type-name))))
    (when (plusp type)
      (q-meta-type-meta-object-for-type type))))

(defun make-qapplication ()
  (let* ((type (q-meta-type-type "QApplication*"))
	 (mo (q-meta-type-meta-object-for-type type)))
    mo))

(defcfun "q_meta_object_class_name" :string
  (meta-object :pointer))

(defcfun "q_meta_object_super_class" :pointer
  (meta-object :pointer))

(defcfun "q_meta_object_method" :pointer
  (meta-object :pointer)
  (index :int))

(defcfun "q_meta_object_method_count" :int
  (meta-object :pointer))

(defcfun "q_meta_object_method_offset" :int
  (meta-object :pointer))

(defcfun "q_meta_object_index_of_method" :int
  (meta-object :pointer)
  (name :string))

(defcfun "q_meta_object_constructor" :pointer
  (meta-object :pointer)
  (index :int))

(defcfun "q_meta_object_constructor_count" :int
  (meta-object :pointer))

(defcfun "q_meta_object_index_of_constructor" :int
  (meta-object :pointer)
  (name :string))

(defcfun "q_meta_object_property" :int
  (meta-object :pointer)
  (index :int))

(defcfun "q_meta_object_property_count" :int
  (meta-object :pointer))

(defcfun "q_meta_object_property_offset" :int
  (meta-object :pointer))

(defcfun "q_meta_object_index_of_property" :int
  (meta-object :pointer)
  (name :string))

;;;; QMetaMethod

(defcfun "q_meta_method_method_signature" :string
  (meta-method :pointer))

;;;; QMetaProperty

(defcfun "q_meta_property_name" :string
  (meta-property :pointer))
