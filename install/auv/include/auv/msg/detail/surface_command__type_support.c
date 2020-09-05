// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auv/msg/detail/surface_command__rosidl_typesupport_introspection_c.h"
#include "auv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auv/msg/detail/surface_command__functions.h"
#include "auv/msg/detail/surface_command__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `desired_trajectory`
#include "auv/msg/trajectory.h"
// Member `desired_trajectory`
#include "auv/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"
// Member `io_requests`
#include "auv/msg/io_request.h"
// Member `io_requests`
#include "auv/msg/detail/io_request__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auv__msg__SurfaceCommand__init(message_memory);
}

void SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_fini_function(void * message_memory)
{
  auv__msg__SurfaceCommand__fini(message_memory);
}

size_t SurfaceCommand__rosidl_typesupport_introspection_c__size_function__IoRequest__io_requests(
  const void * untyped_member)
{
  const auv__msg__IoRequest__Sequence * member =
    (const auv__msg__IoRequest__Sequence *)(untyped_member);
  return member->size;
}

const void * SurfaceCommand__rosidl_typesupport_introspection_c__get_const_function__IoRequest__io_requests(
  const void * untyped_member, size_t index)
{
  const auv__msg__IoRequest__Sequence * member =
    (const auv__msg__IoRequest__Sequence *)(untyped_member);
  return &member->data[index];
}

void * SurfaceCommand__rosidl_typesupport_introspection_c__get_function__IoRequest__io_requests(
  void * untyped_member, size_t index)
{
  auv__msg__IoRequest__Sequence * member =
    (auv__msg__IoRequest__Sequence *)(untyped_member);
  return &member->data[index];
}

bool SurfaceCommand__rosidl_typesupport_introspection_c__resize_function__IoRequest__io_requests(
  void * untyped_member, size_t size)
{
  auv__msg__IoRequest__Sequence * member =
    (auv__msg__IoRequest__Sequence *)(untyped_member);
  auv__msg__IoRequest__Sequence__fini(member);
  return auv__msg__IoRequest__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__SurfaceCommand, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "desired_trajectory",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__SurfaceCommand, desired_trajectory),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "io_requests",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__SurfaceCommand, io_requests),  // bytes offset in struct
    NULL,  // default value
    SurfaceCommand__rosidl_typesupport_introspection_c__size_function__IoRequest__io_requests,  // size() function pointer
    SurfaceCommand__rosidl_typesupport_introspection_c__get_const_function__IoRequest__io_requests,  // get_const(index) function pointer
    SurfaceCommand__rosidl_typesupport_introspection_c__get_function__IoRequest__io_requests,  // get(index) function pointer
    SurfaceCommand__rosidl_typesupport_introspection_c__resize_function__IoRequest__io_requests  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_members = {
  "auv__msg",  // message namespace
  "SurfaceCommand",  // message name
  3,  // number of fields
  sizeof(auv__msg__SurfaceCommand),
  SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_member_array,  // message members
  SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_type_support_handle = {
  0,
  &SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, SurfaceCommand)() {
  SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, Trajectory)();
  SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, IoRequest)();
  if (!SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_type_support_handle.typesupport_identifier) {
    SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &SurfaceCommand__rosidl_typesupport_introspection_c__SurfaceCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
