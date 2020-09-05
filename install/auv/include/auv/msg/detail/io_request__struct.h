// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/IoRequest.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__IO_REQUEST__STRUCT_H_
#define AUV__MSG__DETAIL__IO_REQUEST__STRUCT_H_

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
// Member 'executor'
// Member 'string'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/IoRequest in the package auv.
typedef struct auv__msg__IoRequest
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String executor;
  float number;
  bool boolean;
  int32_t int32;
  rosidl_runtime_c__String string;
} auv__msg__IoRequest;

// Struct for a sequence of auv__msg__IoRequest.
typedef struct auv__msg__IoRequest__Sequence
{
  auv__msg__IoRequest * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__IoRequest__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__IO_REQUEST__STRUCT_H_
