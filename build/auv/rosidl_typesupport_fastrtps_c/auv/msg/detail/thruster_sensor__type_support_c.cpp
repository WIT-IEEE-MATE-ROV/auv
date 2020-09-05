// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from auv:msg/ThrusterSensor.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/thruster_sensor__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "auv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auv/msg/detail/thruster_sensor__struct.h"
#include "auv/msg/detail/thruster_sensor__functions.h"
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


using _ThrusterSensor__ros_msg_type = auv__msg__ThrusterSensor;

static bool _ThrusterSensor__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _ThrusterSensor__ros_msg_type * ros_message = static_cast<const _ThrusterSensor__ros_msg_type *>(untyped_ros_message);
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

  // Field name: rpm
  {
    cdr << ros_message->rpm;
  }

  // Field name: current
  {
    cdr << ros_message->current;
  }

  // Field name: estop
  {
    cdr << (ros_message->estop ? true : false);
  }

  return true;
}

static bool _ThrusterSensor__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _ThrusterSensor__ros_msg_type * ros_message = static_cast<_ThrusterSensor__ros_msg_type *>(untyped_ros_message);
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

  // Field name: rpm
  {
    cdr >> ros_message->rpm;
  }

  // Field name: current
  {
    cdr >> ros_message->current;
  }

  // Field name: estop
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->estop = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t get_serialized_size_auv__msg__ThrusterSensor(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _ThrusterSensor__ros_msg_type * ros_message = static_cast<const _ThrusterSensor__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name thruster
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->thruster.size + 1);
  // field.name rpm
  {
    size_t item_size = sizeof(ros_message->rpm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name current
  {
    size_t item_size = sizeof(ros_message->current);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name estop
  {
    size_t item_size = sizeof(ros_message->estop);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _ThrusterSensor__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_auv__msg__ThrusterSensor(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t max_serialized_size_auv__msg__ThrusterSensor(
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
  // member: rpm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }
  // member: current
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: estop
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _ThrusterSensor__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_auv__msg__ThrusterSensor(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_ThrusterSensor = {
  "auv::msg",
  "ThrusterSensor",
  _ThrusterSensor__cdr_serialize,
  _ThrusterSensor__cdr_deserialize,
  _ThrusterSensor__get_serialized_size,
  _ThrusterSensor__max_serialized_size
};

static rosidl_message_type_support_t _ThrusterSensor__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_ThrusterSensor,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, ThrusterSensor)() {
  return &_ThrusterSensor__type_support;
}

#if defined(__cplusplus)
}
#endif
