// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auv:msg/Orientation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auv/msg/detail/orientation__rosidl_typesupport_introspection_c.h"
#include "auv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auv/msg/detail/orientation__functions.h"
#include "auv/msg/detail/orientation__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Orientation__rosidl_typesupport_introspection_c__Orientation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auv__msg__Orientation__init(message_memory);
}

void Orientation__rosidl_typesupport_introspection_c__Orientation_fini_function(void * message_memory)
{
  auv__msg__Orientation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Orientation__rosidl_typesupport_introspection_c__Orientation_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Orientation, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "roll",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Orientation, roll),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pitch",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Orientation, pitch),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "yaw",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Orientation, yaw),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Orientation__rosidl_typesupport_introspection_c__Orientation_message_members = {
  "auv__msg",  // message namespace
  "Orientation",  // message name
  4,  // number of fields
  sizeof(auv__msg__Orientation),
  Orientation__rosidl_typesupport_introspection_c__Orientation_message_member_array,  // message members
  Orientation__rosidl_typesupport_introspection_c__Orientation_init_function,  // function to initialize message memory (memory has to be allocated)
  Orientation__rosidl_typesupport_introspection_c__Orientation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Orientation__rosidl_typesupport_introspection_c__Orientation_message_type_support_handle = {
  0,
  &Orientation__rosidl_typesupport_introspection_c__Orientation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, Orientation)() {
  Orientation__rosidl_typesupport_introspection_c__Orientation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!Orientation__rosidl_typesupport_introspection_c__Orientation_message_type_support_handle.typesupport_identifier) {
    Orientation__rosidl_typesupport_introspection_c__Orientation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Orientation__rosidl_typesupport_introspection_c__Orientation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
