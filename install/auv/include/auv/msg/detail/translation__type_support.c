// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auv:msg/Translation.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auv/msg/detail/translation__rosidl_typesupport_introspection_c.h"
#include "auv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auv/msg/detail/translation__functions.h"
#include "auv/msg/detail/translation__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Translation__rosidl_typesupport_introspection_c__Translation_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auv__msg__Translation__init(message_memory);
}

void Translation__rosidl_typesupport_introspection_c__Translation_fini_function(void * message_memory)
{
  auv__msg__Translation__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Translation__rosidl_typesupport_introspection_c__Translation_message_member_array[4] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Translation, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Translation, x),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Translation, y),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__Translation, z),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Translation__rosidl_typesupport_introspection_c__Translation_message_members = {
  "auv__msg",  // message namespace
  "Translation",  // message name
  4,  // number of fields
  sizeof(auv__msg__Translation),
  Translation__rosidl_typesupport_introspection_c__Translation_message_member_array,  // message members
  Translation__rosidl_typesupport_introspection_c__Translation_init_function,  // function to initialize message memory (memory has to be allocated)
  Translation__rosidl_typesupport_introspection_c__Translation_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Translation__rosidl_typesupport_introspection_c__Translation_message_type_support_handle = {
  0,
  &Translation__rosidl_typesupport_introspection_c__Translation_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, Translation)() {
  Translation__rosidl_typesupport_introspection_c__Translation_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!Translation__rosidl_typesupport_introspection_c__Translation_message_type_support_handle.typesupport_identifier) {
    Translation__rosidl_typesupport_introspection_c__Translation_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Translation__rosidl_typesupport_introspection_c__Translation_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
