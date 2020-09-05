// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from auv:msg/ArbitraryPcaCommands.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/arbitrary_pca_commands__rosidl_typesupport_fastrtps_cpp.hpp"
#include "auv/msg/detail/arbitrary_pca_commands__struct.hpp"

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
  const auv::msg::ArbitraryPcaCommands & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: set_thruster
  cdr << (ros_message.set_thruster ? true : false);
  // Member: set_channel_pwm
  cdr << (ros_message.set_channel_pwm ? true : false);
  // Member: set_channel_pwm_send_count
  cdr << (ros_message.set_channel_pwm_send_count ? true : false);
  // Member: kill_thruster
  cdr << (ros_message.kill_thruster ? true : false);
  // Member: unkill_thruster
  cdr << (ros_message.unkill_thruster ? true : false);
  // Member: thruster
  cdr << ros_message.thruster;
  // Member: channel
  cdr << ros_message.channel;
  // Member: count
  cdr << ros_message.count;
  // Member: pwm
  cdr << ros_message.pwm;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  auv::msg::ArbitraryPcaCommands & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: set_thruster
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.set_thruster = tmp ? true : false;
  }

  // Member: set_channel_pwm
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.set_channel_pwm = tmp ? true : false;
  }

  // Member: set_channel_pwm_send_count
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.set_channel_pwm_send_count = tmp ? true : false;
  }

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

  // Member: channel
  cdr >> ros_message.channel;

  // Member: count
  cdr >> ros_message.count;

  // Member: pwm
  cdr >> ros_message.pwm;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
get_serialized_size(
  const auv::msg::ArbitraryPcaCommands & ros_message,
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
  // Member: set_thruster
  {
    size_t item_size = sizeof(ros_message.set_thruster);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: set_channel_pwm
  {
    size_t item_size = sizeof(ros_message.set_channel_pwm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: set_channel_pwm_send_count
  {
    size_t item_size = sizeof(ros_message.set_channel_pwm_send_count);
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
  // Member: channel
  {
    size_t item_size = sizeof(ros_message.channel);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: count
  {
    size_t item_size = sizeof(ros_message.count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: pwm
  {
    size_t item_size = sizeof(ros_message.pwm);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
max_serialized_size_ArbitraryPcaCommands(
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

  // Member: set_thruster
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: set_channel_pwm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: set_channel_pwm_send_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
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

  // Member: channel
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: pwm
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _ArbitraryPcaCommands__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const auv::msg::ArbitraryPcaCommands *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _ArbitraryPcaCommands__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<auv::msg::ArbitraryPcaCommands *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _ArbitraryPcaCommands__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const auv::msg::ArbitraryPcaCommands *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _ArbitraryPcaCommands__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_ArbitraryPcaCommands(full_bounded, 0);
}

static message_type_support_callbacks_t _ArbitraryPcaCommands__callbacks = {
  "auv::msg",
  "ArbitraryPcaCommands",
  _ArbitraryPcaCommands__cdr_serialize,
  _ArbitraryPcaCommands__cdr_deserialize,
  _ArbitraryPcaCommands__get_serialized_size,
  _ArbitraryPcaCommands__max_serialized_size
};

static rosidl_message_type_support_t _ArbitraryPcaCommands__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_ArbitraryPcaCommands__callbacks,
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
get_message_type_support_handle<auv::msg::ArbitraryPcaCommands>()
{
  return &auv::msg::typesupport_fastrtps_cpp::_ArbitraryPcaCommands__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, auv, msg, ArbitraryPcaCommands)() {
  return &auv::msg::typesupport_fastrtps_cpp::_ArbitraryPcaCommands__handle;
}

#ifdef __cplusplus
}
#endif
