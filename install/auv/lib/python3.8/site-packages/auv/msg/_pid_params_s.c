// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auv:msg/PidParams.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "auv/msg/detail/pid_params__struct.h"
#include "auv/msg/detail/pid_params__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool auv__msg__pid_params__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[30];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("auv.msg._pid_params.PidParams", full_classname_dest, 29) == 0);
  }
  auv__msg__PidParams * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // p
    PyObject * field = PyObject_GetAttrString(_pymsg, "p");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // i
    PyObject * field = PyObject_GetAttrString(_pymsg, "i");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->i = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // d
    PyObject * field = PyObject_GetAttrString(_pymsg, "d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->d = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auv__msg__pid_params__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PidParams */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auv.msg._pid_params");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PidParams");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auv__msg__PidParams * ros_message = (auv__msg__PidParams *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // i
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->i);
    {
      int rc = PyObject_SetAttrString(_pymessage, "i", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
