// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auv:msg/ArbitraryPcaCommands.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auv/msg/detail/arbitrary_pca_commands__rosidl_typesupport_introspection_c.h"
#include "auv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auv/msg/detail/arbitrary_pca_commands__functions.h"
#include "auv/msg/detail/arbitrary_pca_commands__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `thruster`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auv__msg__ArbitraryPcaCommands__init(message_memory);
}

void ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_fini_function(void * message_memory)
{
  auv__msg__ArbitraryPcaCommands__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_member_array[10] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "set_thruster",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, set_thruster),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "set_channel_pwm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, set_channel_pwm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "set_channel_pwm_send_count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, set_channel_pwm_send_count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kill_thruster",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, kill_thruster),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "unkill_thruster",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, unkill_thruster),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "thruster",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, thruster),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "channel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, channel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "count",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, count),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pwm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__ArbitraryPcaCommands, pwm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_members = {
  "auv__msg",  // message namespace
  "ArbitraryPcaCommands",  // message name
  10,  // number of fields
  sizeof(auv__msg__ArbitraryPcaCommands),
  ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_member_array,  // message members
  ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_init_function,  // function to initialize message memory (memory has to be allocated)
  ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_type_support_handle = {
  0,
  &ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, ArbitraryPcaCommands)() {
  ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_type_support_handle.typesupport_identifier) {
    ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ArbitraryPcaCommands__rosidl_typesupport_introspection_c__ArbitraryPcaCommands_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
