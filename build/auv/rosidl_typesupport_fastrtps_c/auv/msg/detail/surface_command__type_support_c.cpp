// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/surface_command__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "auv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auv/msg/detail/surface_command__struct.h"
#include "auv/msg/detail/surface_command__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "auv/msg/detail/io_request__functions.h"  // io_requests
#include "auv/msg/detail/trajectory__functions.h"  // desired_trajectory
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
size_t get_serialized_size_auv__msg__IoRequest(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_auv__msg__IoRequest(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, IoRequest)();
size_t get_serialized_size_auv__msg__Trajectory(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_auv__msg__Trajectory(
  bool & full_bounded,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, Trajectory)();
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_auv
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_auv
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_auv
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _SurfaceCommand__ros_msg_type = auv__msg__SurfaceCommand;

static bool _SurfaceCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SurfaceCommand__ros_msg_type * ros_message = static_cast<const _SurfaceCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: desired_trajectory
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, auv, msg, Trajectory
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->desired_trajectory, cdr))
    {
      return false;
    }
  }

  // Field name: io_requests
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, auv, msg, IoRequest
      )()->data);
    size_t size = ros_message->io_requests.size;
    auto array_ptr = ros_message->io_requests.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_serialize(
          &array_ptr[i], cdr))
      {
        return false;
      }
    }
  }

  return true;
}

static bool _SurfaceCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SurfaceCommand__ros_msg_type * ros_message = static_cast<_SurfaceCommand__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: desired_trajectory
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, auv, msg, Trajectory
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->desired_trajectory))
    {
      return false;
    }
  }

  // Field name: io_requests
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, auv, msg, IoRequest
      )()->data);
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->io_requests.data) {
      auv__msg__IoRequest__Sequence__fini(&ros_message->io_requests);
    }
    if (!auv__msg__IoRequest__Sequence__init(&ros_message->io_requests, size)) {
      return "failed to create array for field 'io_requests'";
    }
    auto array_ptr = ros_message->io_requests.data;
    for (size_t i = 0; i < size; ++i) {
      if (!callbacks->cdr_deserialize(
          cdr, &array_ptr[i]))
      {
        return false;
      }
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t get_serialized_size_auv__msg__SurfaceCommand(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SurfaceCommand__ros_msg_type * ros_message = static_cast<const _SurfaceCommand__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name desired_trajectory

  current_alignment += get_serialized_size_auv__msg__Trajectory(
    &(ros_message->desired_trajectory), current_alignment);
  // field.name io_requests
  {
    size_t array_size = ros_message->io_requests.size;
    auto array_ptr = ros_message->io_requests.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_auv__msg__IoRequest(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SurfaceCommand__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_auv__msg__SurfaceCommand(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t max_serialized_size_auv__msg__SurfaceCommand(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: desired_trajectory
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_auv__msg__Trajectory(
        full_bounded, current_alignment);
    }
  }
  // member: io_requests
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_auv__msg__IoRequest(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _SurfaceCommand__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_auv__msg__SurfaceCommand(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_SurfaceCommand = {
  "auv::msg",
  "SurfaceCommand",
  _SurfaceCommand__cdr_serialize,
  _SurfaceCommand__cdr_deserialize,
  _SurfaceCommand__get_serialized_size,
  _SurfaceCommand__max_serialized_size
};

static rosidl_message_type_support_t _SurfaceCommand__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SurfaceCommand,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, SurfaceCommand)() {
  return &_SurfaceCommand__type_support;
}

#if defined(__cplusplus)
}
#endif
