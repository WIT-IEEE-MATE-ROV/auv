// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__SURFACE_COMMAND__STRUCT_H_
#define AUV__MSG__DETAIL__SURFACE_COMMAND__STRUCT_H_

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
// Member 'desired_trajectory'
#include "auv/msg/detail/trajectory__struct.h"
// Member 'io_requests'
#include "auv/msg/detail/io_request__struct.h"

// Struct defined in msg/SurfaceCommand in the package auv.
typedef struct auv__msg__SurfaceCommand
{
  std_msgs__msg__Header header;
  auv__msg__Trajectory desired_trajectory;
  auv__msg__IoRequest__Sequence io_requests;
} auv__msg__SurfaceCommand;

// Struct for a sequence of auv__msg__SurfaceCommand.
typedef struct auv__msg__SurfaceCommand__Sequence
{
  auv__msg__SurfaceCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__SurfaceCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__SURFACE_COMMAND__STRUCT_H_
