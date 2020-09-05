// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/JoystickChaos.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__JOYSTICK_CHAOS__STRUCT_H_
#define AUV__MSG__DETAIL__JOYSTICK_CHAOS__STRUCT_H_

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

// Struct defined in msg/JoystickChaos in the package auv.
typedef struct auv__msg__JoystickChaos
{
  std_msgs__msg__Header header;
  float shift_horizontal_correction;
  float shift_vertical_correction;
  float shift_twist_correction;
  float shift_lever_correction;
  float magnitude_horizontal_correction;
  float magnitude_vertical_correction;
  float magnitude_twist_correction;
  float magnitude_lever_correction;
  float lag_seconds;
  bool kill_thruster;
  bool unkill_thruster;
  rosidl_runtime_c__String thruster;
} auv__msg__JoystickChaos;

// Struct for a sequence of auv__msg__JoystickChaos.
typedef struct auv__msg__JoystickChaos__Sequence
{
  auv__msg__JoystickChaos * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__JoystickChaos__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__JOYSTICK_CHAOS__STRUCT_H_
