// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/Translation.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__TRANSLATION__STRUCT_H_
#define AUV__MSG__DETAIL__TRANSLATION__STRUCT_H_

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

// Struct defined in msg/Translation in the package auv.
typedef struct auv__msg__Translation
{
  std_msgs__msg__Header header;
  float x;
  float y;
  float z;
} auv__msg__Translation;

// Struct for a sequence of auv__msg__Translation.
typedef struct auv__msg__Translation__Sequence
{
  auv__msg__Translation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__Translation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__TRANSLATION__STRUCT_H_
