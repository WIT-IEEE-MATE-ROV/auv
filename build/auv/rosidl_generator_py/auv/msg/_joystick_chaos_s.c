// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from auv:msg/JoystickChaos.idl
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
#include "auv/msg/detail/joystick_chaos__struct.h"
#include "auv/msg/detail/joystick_chaos__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool auv__msg__joystick_chaos__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[38];
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
    assert(strncmp("auv.msg._joystick_chaos.JoystickChaos", full_classname_dest, 37) == 0);
  }
  auv__msg__JoystickChaos * ros_message = _ros_message;
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
  {  // shift_horizontal_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "shift_horizontal_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->shift_horizontal_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // shift_vertical_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "shift_vertical_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->shift_vertical_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // shift_twist_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "shift_twist_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->shift_twist_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // shift_lever_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "shift_lever_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->shift_lever_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // magnitude_horizontal_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnitude_horizontal_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->magnitude_horizontal_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // magnitude_vertical_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnitude_vertical_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->magnitude_vertical_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // magnitude_twist_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnitude_twist_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->magnitude_twist_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // magnitude_lever_correction
    PyObject * field = PyObject_GetAttrString(_pymsg, "magnitude_lever_correction");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->magnitude_lever_correction = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // lag_seconds
    PyObject * field = PyObject_GetAttrString(_pymsg, "lag_seconds");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->lag_seconds = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // kill_thruster
    PyObject * field = PyObject_GetAttrString(_pymsg, "kill_thruster");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->kill_thruster = (Py_True == field);
    Py_DECREF(field);
  }
  {  // unkill_thruster
    PyObject * field = PyObject_GetAttrString(_pymsg, "unkill_thruster");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->unkill_thruster = (Py_True == field);
    Py_DECREF(field);
  }
  {  // thruster
    PyObject * field = PyObject_GetAttrString(_pymsg, "thruster");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->thruster, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * auv__msg__joystick_chaos__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of JoystickChaos */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("auv.msg._joystick_chaos");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "JoystickChaos");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  auv__msg__JoystickChaos * ros_message = (auv__msg__JoystickChaos *)raw_ros_message;
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
  {  // shift_horizontal_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->shift_horizontal_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shift_horizontal_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shift_vertical_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->shift_vertical_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shift_vertical_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shift_twist_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->shift_twist_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shift_twist_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // shift_lever_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->shift_lever_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "shift_lever_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // magnitude_horizontal_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->magnitude_horizontal_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "magnitude_horizontal_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // magnitude_vertical_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->magnitude_vertical_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "magnitude_vertical_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // magnitude_twist_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->magnitude_twist_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "magnitude_twist_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // magnitude_lever_correction
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->magnitude_lever_correction);
    {
      int rc = PyObject_SetAttrString(_pymessage, "magnitude_lever_correction", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // lag_seconds
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->lag_seconds);
    {
      int rc = PyObject_SetAttrString(_pymessage, "lag_seconds", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // kill_thruster
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->kill_thruster ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "kill_thruster", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // unkill_thruster
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->unkill_thruster ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "unkill_thruster", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // thruster
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->thruster.data,
      strlen(ros_message->thruster.data),
      "strict");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "thruster", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
