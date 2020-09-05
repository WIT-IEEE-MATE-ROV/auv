// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__TRAJECTORY__STRUCT_H_
#define AUV__MSG__DETAIL__TRAJECTORY__STRUCT_H_

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
// Member 'orientation'
#include "auv/msg/detail/orientation__struct.h"
// Member 'translation'
#include "auv/msg/detail/translation__struct.h"

// Struct defined in msg/Trajectory in the package auv.
typedef struct auv__msg__Trajectory
{
  std_msgs__msg__Header header;
  auv__msg__Orientation orientation;
  auv__msg__Translation translation;
} auv__msg__Trajectory;

// Struct for a sequence of auv__msg__Trajectory.
typedef struct auv__msg__Trajectory__Sequence
{
  auv__msg__Trajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__Trajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__TRAJECTORY__STRUCT_H_
