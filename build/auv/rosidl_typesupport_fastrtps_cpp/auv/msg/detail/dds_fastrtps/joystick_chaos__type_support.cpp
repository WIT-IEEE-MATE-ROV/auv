// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from auv:msg/JoystickChaos.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/joystick_chaos__rosidl_typesupport_fastrtps_cpp.hpp"
#include "auv/msg/detail/joystick_chaos__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace auv
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
cdr_serialize(
  const auv::msg::JoystickChaos & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: shift_horizontal_correction
  cdr << ros_message.shift_horizontal_correction;
  // Member: shift_vertical_correction
  cdr << ros_message.shift_vertical_correction;
  // Member: shift_twist_correction
  cdr << ros_message.shift_twist_correction;
  // Member: shift_lever_correction
  cdr << ros_message.shift_lever_correction;
  // Member: magnitude_horizontal_correction
  cdr << ros_message.magnitude_horizontal_correction;
  // Member: magnitude_vertical_correction
  cdr << ros_message.magnitude_vertical_correction;
  // Member: magnitude_twist_correction
  cdr << ros_message.magnitude_twist_correction;
  // Member: magnitude_lever_correction
  cdr << ros_message.magnitude_lever_correction;
  // Member: lag_seconds
  cdr << ros_message.lag_seconds;
  // Member: kill_thruster
  cdr << (ros_message.kill_thruster ? true : false);
  // Member: unkill_thruster
  cdr << (ros_message.unkill_thruster ? true : false);
  // Member: thruster
  cdr << ros_message.thruster;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  auv::msg::JoystickChaos & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: shift_horizontal_correction
  cdr >> ros_message.shift_horizontal_correction;

  // Member: shift_vertical_correction
  cdr >> ros_message.shift_vertical_correction;

  // Member: shift_twist_correction
  cdr >> ros_message.shift_twist_correction;

  // Member: shift_lever_correction
  cdr >> ros_message.shift_lever_correction;

  // Member: magnitude_horizontal_correction
  cdr >> ros_message.magnitude_horizontal_correction;

  // Member: magnitude_vertical_correction
  cdr >> ros_message.magnitude_vertical_correction;

  // Member: magnitude_twist_correction
  cdr >> ros_message.magnitude_twist_correction;

  // Member: magnitude_lever_correction
  cdr >> ros_message.magnitude_lever_correction;

  // Member: lag_seconds
  cdr >> ros_message.lag_seconds;

  // Member: kill_thruster
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.kill_thruster = tmp ? true : false;
  }

  // Member: unkill_thruster
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.unkill_thruster = tmp ? true : false;
  }

  // Member: thruster
  cdr >> ros_message.thruster;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
get_serialized_size(
  const auv::msg::JoystickChaos & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: shift_horizontal_correction
  {
    size_t item_size = sizeof(ros_message.shift_horizontal_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: shift_vertical_correction
  {
    size_t item_size = sizeof(ros_message.shift_vertical_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: shift_twist_correction
  {
    size_t item_size = sizeof(ros_message.shift_twist_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: shift_lever_correction
  {
    size_t item_size = sizeof(ros_message.shift_lever_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnitude_horizontal_correction
  {
    size_t item_size = sizeof(ros_message.magnitude_horizontal_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnitude_vertical_correction
  {
    size_t item_size = sizeof(ros_message.magnitude_vertical_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnitude_twist_correction
  {
    size_t item_size = sizeof(ros_message.magnitude_twist_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: magnitude_lever_correction
  {
    size_t item_size = sizeof(ros_message.magnitude_lever_correction);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: lag_seconds
  {
    size_t item_size = sizeof(ros_message.lag_seconds);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: kill_thruster
  {
    size_t item_size = sizeof(ros_message.kill_thruster);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: unkill_thruster
  {
    size_t item_size = sizeof(ros_message.unkill_thruster);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: thruster
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.thruster.size() + 1);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
max_serialized_size_JoystickChaos(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: shift_horizontal_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: shift_vertical_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: shift_twist_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: shift_lever_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: magnitude_horizontal_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: magnitude_vertical_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: magnitude_twist_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: magnitude_lever_correction
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: lag_seconds
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: kill_thruster
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: unkill_thruster
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: thruster
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

static bool _JoystickChaos__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const auv::msg::JoystickChaos *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _JoystickChaos__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<auv::msg::JoystickChaos *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _JoystickChaos__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const auv::msg::JoystickChaos *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _JoystickChaos__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_JoystickChaos(full_bounded, 0);
}

static message_type_support_callbacks_t _JoystickChaos__callbacks = {
  "auv::msg",
  "JoystickChaos",
  _JoystickChaos__cdr_serialize,
  _JoystickChaos__cdr_deserialize,
  _JoystickChaos__get_serialized_size,
  _JoystickChaos__max_serialized_size
};

static rosidl_message_type_support_t _JoystickChaos__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_JoystickChaos__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace auv

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_auv
const rosidl_message_type_support_t *
get_message_type_support_handle<auv::msg::JoystickChaos>()
{
  return &auv::msg::typesupport_fastrtps_cpp::_JoystickChaos__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, auv, msg, JoystickChaos)() {
  return &auv::msg::typesupport_fastrtps_cpp::_JoystickChaos__handle;
}

#ifdef __cplusplus
}
#endif
