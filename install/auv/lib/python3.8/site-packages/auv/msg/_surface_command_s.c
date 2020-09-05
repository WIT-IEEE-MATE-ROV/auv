// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auv:msg/SurfaceCommand.idl
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
#include "auv/msg/detail/surface_command__struct.h"
#include "auv/msg/detail/surface_command__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "auv/msg/detail/io_request__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool auv__msg__trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * auv__msg__trajectory__convert_to_py(void * raw_ros_message);
bool auv__msg__io_request__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * auv__msg__io_request__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool auv__msg__surface_command__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
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
    assert(strncmp("auv.msg._surface_command.SurfaceCommand", full_classname_dest, 39) == 0);
  }
  auv__msg__SurfaceCommand * ros_message = _ros_message;
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
  {  // desired_trajectory
    PyObject * field = PyObject_GetAttrString(_pymsg, "desired_trajectory");
    if (!field) {
      return false;
    }
    if (!auv__msg__trajectory__convert_from_py(field, &ros_message->desired_trajectory)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // io_requests
    PyObject * field = PyObject_GetAttrString(_pymsg, "io_requests");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'io_requests'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!auv__msg__IoRequest__Sequence__init(&(ros_message->io_requests), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create auv__msg__IoRequest__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    auv__msg__IoRequest * dest = ros_message->io_requests.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!auv__msg__io_request__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auv__msg__surface_command__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of SurfaceCommand */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auv.msg._surface_command");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "SurfaceCommand");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auv__msg__SurfaceCommand * ros_message = (auv__msg__SurfaceCommand *)raw_ros_message;
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
  {  // desired_trajectory
    PyObject * field = NULL;
    field = auv__msg__trajectory__convert_to_py(&ros_message->desired_trajectory);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "desired_trajectory", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // io_requests
    PyObject * field = NULL;
    size_t size = ros_message->io_requests.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    auv__msg__IoRequest * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->io_requests.data[i]);
      PyObject * pyitem = auv__msg__io_request__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "io_requests", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
