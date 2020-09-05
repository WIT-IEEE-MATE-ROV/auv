// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/MultistepTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__STRUCT_H_
#define AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__STRUCT_H_

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
// Member 'trajectories'
#include "auv/msg/detail/trajectory__struct.h"

// Struct defined in msg/MultistepTrajectory in the package auv.
typedef struct auv__msg__MultistepTrajectory
{
  std_msgs__msg__Header header;
  uint8_t length;
  auv__msg__Trajectory__Sequence trajectories;
} auv__msg__MultistepTrajectory;

// Struct for a sequence of auv__msg__MultistepTrajectory.
typedef struct auv__msg__MultistepTrajectory__Sequence
{
  auv__msg__MultistepTrajectory * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__MultistepTrajectory__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__STRUCT_H_
