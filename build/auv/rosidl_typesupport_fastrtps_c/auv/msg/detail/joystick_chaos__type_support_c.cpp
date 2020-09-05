// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from auv:msg/JoystickChaos.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/joystick_chaos__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "auv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auv/msg/detail/joystick_chaos__struct.h"
#include "auv/msg/detail/joystick_chaos__functions.h"
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

#include "rosidl_runtime_c/string.h"  // thruster
#include "rosidl_runtime_c/string_functions.h"  // thruster
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


using _JoystickChaos__ros_msg_type = auv__msg__JoystickChaos;

static bool _JoystickChaos__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _JoystickChaos__ros_msg_type * ros_message = static_cast<const _JoystickChaos__ros_msg_type *>(untyped_ros_message);
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

  // Field name: shift_horizontal_correction
  {
    cdr << ros_message->shift_horizontal_correction;
  }

  // Field name: shift_vertical_correction
  {
    cdr << ros_message->shift_vertical_correction;
  }

  // Field name: shift_twist_correction
  {
    cdr << ros_message->shift_twist_correction;
  }

  // Field name: shift_lever_correction
  {
    cdr << ros_message->shift_lever_correction;
  }

  // Field name: magnitude_horizontal_correction
  {
    cdr << ros_message->magnitude_horizontal_correction;
  }

  // Field name: magnitude_vertical_correction
  {
    cdr << ros_message->magnitude_vertical_correction;
  }

  // Field name: magnitude_twist_correction
  {
    cdr << ros_message->magnitude_twist_correction;
  }

  // Field name: magnitude_lever_correction
  {
    cdr << ros_message->magnitude_lever_correction;
  }

  // Field name: lag_seconds
  {
    cdr << ros_message->lag_seconds;
  }

  // Field name: kill_thruster
  {
    cdr << (ros_message->kill_thruster ? true : false);
  }

  // Field name: unkill_thruster
  {
    cdr << (ros_message->unkill_thruster ? true : false);
  }

  // Field name: thruster
  {
    const rosidl_runtime_c__String * str = &ros_message->thruster;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _JoystickChaos__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _JoystickChaos__ros_msg_type * ros_message = static_cast<_JoystickChaos__ros_msg_type *>(untyped_ros_message);
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

  // Field name: shift_horizontal_correction
  {
    cdr >> ros_message->shift_horizontal_correction;
  }

  // Field name: shift_vertical_correction
  {
    cdr >> ros_message->shift_vertical_correction;
  }

  // Field name: shift_twist_correction
  {
    cdr >> ros_message->shift_twist_correction;
  }

  // Field name: shift_lever_correction
  {
    cdr >> ros_message->shift_lever_correction;
  }

  // Field name: magnitude_horizontal_correction
  {
    cdr >> ros_message->magnitude_horizontal_correction;
  }

  // Field name: magnitude_vertical_correction
  {
    cdr >> ros_message->magnitude_vertical_correction;
  }

  // Field name: magnitude_twist_correction
  {
    cdr >> ros_message->magnitude_twist_correction;
  }

  // Field name: magnitude_lever_correction
  {
    cdr >> ros_message->magnitude_lever_correction;
  }

  // Field name: lag_seconds
  {
    cdr >> ros_message->lag_seconds;
  }

  // Field name: kill_thruster
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->kill_thruster = tmp ? true : false;
  }

  // Field name: unkill_thruster
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->unkill_thruster = tmp ? true : false;
  }

  // Field name: thruster
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->thruster.data) {
      rosidl_runtime_c__String__init(&ros_message->thruster);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->thruster,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'thruster'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t get_serialized_size_auv__msg__JoystickChaos(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _JoystickChaos__ros_msg_type * ros_message = static_cast<const _JoystickChaos__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name shift_horizontal_correction
  {
    size_t item_size = sizeof(ros_message->shift_horizontal_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shift_vertical_correction
  {
    size_t item_size = sizeof(ros_message->shift_vertical_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shift_twist_correction
  {
    size_t item_size = sizeof(ros_message->shift_twist_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name shift_lever_correction
  {
    size_t item_size = sizeof(ros_message->shift_lever_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnitude_horizontal_correction
  {
    size_t item_size = sizeof(ros_message->magnitude_horizontal_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnitude_vertical_correction
  {
    size_t item_size = sizeof(ros_message->magnitude_vertical_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnitude_twist_correction
  {
    size_t item_size = sizeof(ros_message->magnitude_twist_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name magnitude_lever_correction
  {
    size_t item_size = sizeof(ros_message->magnitude_lever_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name lag_seconds
  {
    size_t item_size = sizeof(ros_message->lag_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name kill_thruster
  {
    size_t item_size = sizeof(ros_message->kill_thruster);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name unkill_thruster
  {
    size_t item_size = sizeof(ros_message->unkill_thruster);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name thruster
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->thruster.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _JoystickChaos__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_auv__msg__JoystickChaos(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t max_serialized_size_auv__msg__JoystickChaos(
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
  // member: shift_horizontal_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: shift_vertical_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: shift_twist_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: shift_lever_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: magnitude_horizontal_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: magnitude_vertical_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: magnitude_twist_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: magnitude_lever_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: lag_seconds
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: kill_thruster
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: unkill_thruster
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: thruster
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _JoystickChaos__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_auv__msg__JoystickChaos(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_JoystickChaos = {
  "auv::msg",
  "JoystickChaos",
  _JoystickChaos__cdr_serialize,
  _JoystickChaos__cdr_deserialize,
  _JoystickChaos__get_serialized_size,
  _JoystickChaos__max_serialized_size
};

static rosidl_message_type_support_t _JoystickChaos__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_JoystickChaos,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, JoystickChaos)() {
  return &_JoystickChaos__type_support;
}

#if defined(__cplusplus)
}
#endif
