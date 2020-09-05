// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from auv:msg/ThrusterMove.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/thruster_move__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "auv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auv/msg/detail/thruster_move__struct.h"
#include "auv/msg/detail/thruster_move__functions.h"
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

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
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


using _ThrusterMove__ros_msg_type = auv__msg__ThrusterMove;

static bool _ThrusterMove__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ThrusterMove__ros_msg_type * ros_message = static_cast<const _ThrusterMove__ros_msg_type *>(untyped_ros_message);
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

  // Field name: top_front
  {
    cdr << ros_message->top_front;
  }

  // Field name: top_back
  {
    cdr << ros_message->top_back;
  }

  // Field name: top_left
  {
    cdr << ros_message->top_left;
  }

  // Field name: top_right
  {
    cdr << ros_message->top_right;
  }

  // Field name: front_left
  {
    cdr << ros_message->front_left;
  }

  // Field name: front_right
  {
    cdr << ros_message->front_right;
  }

  // Field name: back_left
  {
    cdr << ros_message->back_left;
  }

  // Field name: back_right
  {
    cdr << ros_message->back_right;
  }

  return true;
}

static bool _ThrusterMove__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ThrusterMove__ros_msg_type * ros_message = static_cast<_ThrusterMove__ros_msg_type *>(untyped_ros_message);
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

  // Field name: top_front
  {
    cdr >> ros_message->top_front;
  }

  // Field name: top_back
  {
    cdr >> ros_message->top_back;
  }

  // Field name: top_left
  {
    cdr >> ros_message->top_left;
  }

  // Field name: top_right
  {
    cdr >> ros_message->top_right;
  }

  // Field name: front_left
  {
    cdr >> ros_message->front_left;
  }

  // Field name: front_right
  {
    cdr >> ros_message->front_right;
  }

  // Field name: back_left
  {
    cdr >> ros_message->back_left;
  }

  // Field name: back_right
  {
    cdr >> ros_message->back_right;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t get_serialized_size_auv__msg__ThrusterMove(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ThrusterMove__ros_msg_type * ros_message = static_cast<const _ThrusterMove__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name top_front
  {
    size_t item_size = sizeof(ros_message->top_front);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name top_back
  {
    size_t item_size = sizeof(ros_message->top_back);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name top_left
  {
    size_t item_size = sizeof(ros_message->top_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name top_right
  {
    size_t item_size = sizeof(ros_message->top_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name front_left
  {
    size_t item_size = sizeof(ros_message->front_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name front_right
  {
    size_t item_size = sizeof(ros_message->front_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name back_left
  {
    size_t item_size = sizeof(ros_message->back_left);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name back_right
  {
    size_t item_size = sizeof(ros_message->back_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ThrusterMove__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_auv__msg__ThrusterMove(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t max_serialized_size_auv__msg__ThrusterMove(
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
  // member: top_front
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: top_back
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: top_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: top_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: front_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: front_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: back_left
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: back_right
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static size_t _ThrusterMove__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_auv__msg__ThrusterMove(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ThrusterMove = {
  "auv::msg",
  "ThrusterMove",
  _ThrusterMove__cdr_serialize,
  _ThrusterMove__cdr_deserialize,
  _ThrusterMove__get_serialized_size,
  _ThrusterMove__max_serialized_size
};

static rosidl_message_type_support_t _ThrusterMove__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ThrusterMove,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, ThrusterMove)() {
  return &_ThrusterMove__type_support;
}

#if defined(__cplusplus)
}
#endif
