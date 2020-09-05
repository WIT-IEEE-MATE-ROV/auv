// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/ThrusterMove.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_MOVE__STRUCT_H_
#define AUV__MSG__DETAIL__THRUSTER_MOVE__STRUCT_H_

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

// Struct defined in msg/ThrusterMove in the package auv.
typedef struct auv__msg__ThrusterMove
{
  std_msgs__msg__Header header;
  float top_front;
  float top_back;
  float top_left;
  float top_right;
  float front_left;
  float front_right;
  float back_left;
  float back_right;
} auv__msg__ThrusterMove;

// Struct for a sequence of auv__msg__ThrusterMove.
typedef struct auv__msg__ThrusterMove__Sequence
{
  auv__msg__ThrusterMove * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__ThrusterMove__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__THRUSTER_MOVE__STRUCT_H_
