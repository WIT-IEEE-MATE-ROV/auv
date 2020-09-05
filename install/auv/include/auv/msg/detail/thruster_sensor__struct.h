// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/ThrusterSensor.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_SENSOR__STRUCT_H_
#define AUV__MSG__DETAIL__THRUSTER_SENSOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'thruster'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/ThrusterSensor in the package auv.
typedef struct auv__msg__ThrusterSensor
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String thruster;
  uint16_t rpm;
  float current;
  bool estop;
} auv__msg__ThrusterSensor;

// Struct for a sequence of auv__msg__ThrusterSensor.
typedef struct auv__msg__ThrusterSensor__Sequence
{
  auv__msg__ThrusterSensor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__ThrusterSensor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__THRUSTER_SENSOR__STRUCT_H_
