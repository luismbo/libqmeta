;;;; -*- indent-tabs-mode: nil -*-

(defpackage :libqmeta
  (:use :cl :cffi))

(in-package :libqmeta)

#+nil
(progn
  (ql:quickload :cffi)

  (setf (uiop:getenv "LD_LIBRARY_PATH") "/usr/local/Qt-5.14.0/lib")
  (setf (uiop:getenv "QT_DEBUG_PLUGINS") "1")
  (cffi:load-foreign-library "/usr/local/Qt-5.14.0/lib/libQt5Widgets.so.5")
  (cffi:load-foreign-library "/home/luis/src/qt/build-libqmetaobject-Desktop_usr_local_Qt_5_14_0-Release/liblibqmetaobject.so")

  (setf (uiop:getenv "PATH")
        (format nil "D:\\opt\\Qt\\5.12.6\\mingw73_64\\bin;~a" (uiop:getenv "PATH")))
  (cffi:load-foreign-library "D:/opt/Qt/5.12.6/mingw73_64/bin/Qt5Cored.dll")
  (cffi:load-foreign-library "D:/opt/Qt/5.12.6/mingw73_64/bin/Qt5Widgetsd.dll")
  (cffi:load-foreign-library "Z:/src/qt-projects/build-libqmetaobject-Desktop_Qt_5_12_6_MinGW_64_bit-Debug/debug/libqmetaobject.dll")

  (cffi:foreign-funcall "qVersion" :string))

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

(defun find-meta-object (type-name &key (if-does-not-exist :error))
  (check-type if-does-not-exist (member nil :error))
  (let ((type (q-meta-type-type (format nil "~a*" type-name))))
    (if (plusp type)
        (let ((p (q-meta-type-meta-object-for-type type)))
          (when (and (eq if-does-not-exist :error)
                     (null-pointer-p p))
            (error "couldn't find meta object for ~s (type: ~a)"
                   type-name type))
          p)
        (when (eq if-does-not-exist :error)
          (error "couldn't find type ~s" type-name)))))

(defcfun "q_meta_make_q_application" :pointer)

(defun qapplication ()
  (q-meta-make-q-application))

(defun proof-of-concept ()
  (let* ((app (qapplication))
         (mo (find-meta-object "QMainWindow"))
         (window (q-meta-object-new-instance mo 0 (null-pointer) (null-pointer))))
    (q-meta-object-invoke-method window "show" :direct "void" (null-pointer) 0 (null-pointer) (null-pointer))
    (q-meta-object-invoke-method app "exec" :direct "void" (null-pointer) 0 (null-pointer) (null-pointer))))

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

(defcfun "q_meta_method_parameter_count" :int
  (meta-method :pointer))

(defcfun "q_meta_method_parameter_type" :int
  (meta-method :pointer)
  (index :int))

;;;; QMetaProperty

(defcfun "q_meta_property_name" :string
  (meta-property :pointer))


;;;; Utilities

(defun list-constructors (type-name)
  (let* ((mo (find-meta-object type-name))
         (count (q-meta-object-constructor-count mo)))
    (loop for i below count
          for constructor = (q-meta-object-constructor mo i)
          collect (q-meta-method-method-signature constructor))))

(defun list-methods (type-name)
  (let* ((mo (find-meta-object type-name))
         (count (q-meta-object-method-count mo)))
    (loop for i below count
          for constructor = (q-meta-object-method mo i)
          collect (q-meta-method-method-signature constructor))))
