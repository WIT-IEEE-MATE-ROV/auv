// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from auv:msg/MultistepTrajectory.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "auv/msg/detail/multistep_trajectory__rosidl_typesupport_introspection_c.h"
#include "auv/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "auv/msg/detail/multistep_trajectory__functions.h"
#include "auv/msg/detail/multistep_trajectory__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `trajectories`
#include "auv/msg/trajectory.h"
// Member `trajectories`
#include "auv/msg/detail/trajectory__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  auv__msg__MultistepTrajectory__init(message_memory);
}

void MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_fini_function(void * message_memory)
{
  auv__msg__MultistepTrajectory__fini(message_memory);
}

size_t MultistepTrajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__trajectories(
  const void * untyped_member)
{
  const auv__msg__Trajectory__Sequence * member =
    (const auv__msg__Trajectory__Sequence *)(untyped_member);
  return member->size;
}

const void * MultistepTrajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__trajectories(
  const void * untyped_member, size_t index)
{
  const auv__msg__Trajectory__Sequence * member =
    (const auv__msg__Trajectory__Sequence *)(untyped_member);
  return &member->data[index];
}

void * MultistepTrajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__trajectories(
  void * untyped_member, size_t index)
{
  auv__msg__Trajectory__Sequence * member =
    (auv__msg__Trajectory__Sequence *)(untyped_member);
  return &member->data[index];
}

bool MultistepTrajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__trajectories(
  void * untyped_member, size_t size)
{
  auv__msg__Trajectory__Sequence * member =
    (auv__msg__Trajectory__Sequence *)(untyped_member);
  auv__msg__Trajectory__Sequence__fini(member);
  return auv__msg__Trajectory__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_member_array[3] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__MultistepTrajectory, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "length",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__MultistepTrajectory, length),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "trajectories",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv__msg__MultistepTrajectory, trajectories),  // bytes offset in struct
    NULL,  // default value
    MultistepTrajectory__rosidl_typesupport_introspection_c__size_function__Trajectory__trajectories,  // size() function pointer
    MultistepTrajectory__rosidl_typesupport_introspection_c__get_const_function__Trajectory__trajectories,  // get_const(index) function pointer
    MultistepTrajectory__rosidl_typesupport_introspection_c__get_function__Trajectory__trajectories,  // get(index) function pointer
    MultistepTrajectory__rosidl_typesupport_introspection_c__resize_function__Trajectory__trajectories  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_members = {
  "auv__msg",  // message namespace
  "MultistepTrajectory",  // message name
  3,  // number of fields
  sizeof(auv__msg__MultistepTrajectory),
  MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_member_array,  // message members
  MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_init_function,  // function to initialize message memory (memory has to be allocated)
  MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_type_support_handle = {
  0,
  &MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_auv
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, MultistepTrajectory)() {
  MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, auv, msg, Trajectory)();
  if (!MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_type_support_handle.typesupport_identifier) {
    MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MultistepTrajectory__rosidl_typesupport_introspection_c__MultistepTrajectory_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
