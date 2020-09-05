// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ORIENTATION__STRUCT_H_
#define AUV__MSG__DETAIL__ORIENTATION__STRUCT_H_

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

// Struct defined in msg/Orientation in the package auv.
typedef struct auv__msg__Orientation
{
  std_msgs__msg__Header header;
  float roll;
  float pitch;
  float yaw;
} auv__msg__Orientation;

// Struct for a sequence of auv__msg__Orientation.
typedef struct auv__msg__Orientation__Sequence
{
  auv__msg__Orientation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__Orientation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__ORIENTATION__STRUCT_H_
