// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auv:msg/IoRequest.idl
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
#include "auv/msg/detail/io_request__struct.h"
#include "auv/msg/detail/io_request__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool auv__msg__io_request__convert_from_py(PyObject * _pymsg, void * _ros_message)
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
    assert(strncmp("auv.msg._io_request.IoRequest", full_classname_dest, 29) == 0);
  }
  auv__msg__IoRequest * ros_message = _ros_message;
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
  {  // executor
    PyObject * field = PyObject_GetAttrString(_pymsg, "executor");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->executor, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // number
    PyObject * field = PyObject_GetAttrString(_pymsg, "number");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->number = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // boolean
    PyObject * field = PyObject_GetAttrString(_pymsg, "boolean");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->boolean = (Py_True == field);
    Py_DECREF(field);
  }
  {  // int32
    PyObject * field = PyObject_GetAttrString(_pymsg, "int32");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->int32 = (int32_t)PyLong_AsLong(field);
    Py_DECREF(field);
  }
  {  // string
    PyObject * field = PyObject_GetAttrString(_pymsg, "string");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->string, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auv__msg__io_request__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of IoRequest */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auv.msg._io_request");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "IoRequest");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auv__msg__IoRequest * ros_message = (auv__msg__IoRequest *)raw_ros_message;
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
  {  // executor
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->executor.data,
      strlen(ros_message->executor.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "executor", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // number
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->number);
    {
      int rc = PyObject_SetAttrString(_pymessage, "number", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // boolean
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->boolean ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "boolean", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // int32
    PyObject * field = NULL;
    field = PyLong_FromLong(ros_message->int32);
    {
      int rc = PyObject_SetAttrString(_pymessage, "int32", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // string
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->string.data,
      strlen(ros_message->string.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "string", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
