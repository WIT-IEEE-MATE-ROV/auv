// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from auv:msg/ArbitraryPcaCommands.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__STRUCT_H_
#define AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__STRUCT_H_

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

// Struct defined in msg/ArbitraryPcaCommands in the package auv.
typedef struct auv__msg__ArbitraryPcaCommands
{
  std_msgs__msg__Header header;
  bool set_thruster;
  bool set_channel_pwm;
  bool set_channel_pwm_send_count;
  bool kill_thruster;
  bool unkill_thruster;
  rosidl_runtime_c__String thruster;
  uint8_t channel;
  uint16_t count;
  float pwm;
} auv__msg__ArbitraryPcaCommands;

// Struct for a sequence of auv__msg__ArbitraryPcaCommands.
typedef struct auv__msg__ArbitraryPcaCommands__Sequence
{
  auv__msg__ArbitraryPcaCommands * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} auv__msg__ArbitraryPcaCommands__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__STRUCT_H_
