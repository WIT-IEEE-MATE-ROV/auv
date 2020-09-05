// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auv:msg/MultistepTrajectory.idl
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
#include "auv/msg/detail/multistep_trajectory__struct.h"
#include "auv/msg/detail/multistep_trajectory__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "auv/msg/detail/trajectory__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);
bool auv__msg__trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * auv__msg__trajectory__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool auv__msg__multistep_trajectory__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[50];
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
    assert(strncmp("auv.msg._multistep_trajectory.MultistepTrajectory", full_classname_dest, 49) == 0);
  }
  auv__msg__MultistepTrajectory * ros_message = _ros_message;
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
  {  // length
    PyObject * field = PyObject_GetAttrString(_pymsg, "length");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->length = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // trajectories
    PyObject * field = PyObject_GetAttrString(_pymsg, "trajectories");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'trajectories'");
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
    if (!auv__msg__Trajectory__Sequence__init(&(ros_message->trajectories), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create auv__msg__Trajectory__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    auv__msg__Trajectory * dest = ros_message->trajectories.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!auv__msg__trajectory__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
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
PyObject * auv__msg__multistep_trajectory__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of MultistepTrajectory */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auv.msg._multistep_trajectory");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "MultistepTrajectory");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auv__msg__MultistepTrajectory * ros_message = (auv__msg__MultistepTrajectory *)raw_ros_message;
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
  {  // length
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->length);
    {
      int rc = PyObject_SetAttrString(_pymessage, "length", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // trajectories
    PyObject * field = NULL;
    size_t size = ros_message->trajectories.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    auv__msg__Trajectory * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->trajectories.data[i]);
      PyObject * pyitem = auv__msg__trajectory__convert_to_py(item);
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
      int rc = PyObject_SetAttrString(_pymessage, "trajectories", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
