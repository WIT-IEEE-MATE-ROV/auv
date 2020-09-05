// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from auv:msg/MultistepTrajectory.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/multistep_trajectory__rosidl_typesupport_fastrtps_cpp.hpp"
#include "auv/msg/detail/multistep_trajectory__struct.hpp"

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
bool cdr_serialize(
  const auv::msg::Trajectory &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  auv::msg::Trajectory &);
size_t get_serialized_size(
  const auv::msg::Trajectory &,
  size_t current_alignment);
size_t
max_serialized_size_Trajectory(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace auv


namespace auv
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
cdr_serialize(
  const auv::msg::MultistepTrajectory & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: length
  cdr << ros_message.length;
  // Member: trajectories
  {
    size_t size = ros_message.trajectories.size();
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; i++) {
      auv::msg::typesupport_fastrtps_cpp::cdr_serialize(
        ros_message.trajectories[i],
        cdr);
    }
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  auv::msg::MultistepTrajectory & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: length
  cdr >> ros_message.length;

  // Member: trajectories
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    ros_message.trajectories.resize(size);
    for (size_t i = 0; i < size; i++) {
      auv::msg::typesupport_fastrtps_cpp::cdr_deserialize(
        cdr, ros_message.trajectories[i]);
    }
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
get_serialized_size(
  const auv::msg::MultistepTrajectory & ros_message,
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
  // Member: length
  {
    size_t item_size = sizeof(ros_message.length);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: trajectories
  {
    size_t array_size = ros_message.trajectories.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        auv::msg::typesupport_fastrtps_cpp::get_serialized_size(
        ros_message.trajectories[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_auv
max_serialized_size_MultistepTrajectory(
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

  // Member: length
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: trajectories
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        auv::msg::typesupport_fastrtps_cpp::max_serialized_size_Trajectory(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static bool _MultistepTrajectory__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const auv::msg::MultistepTrajectory *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MultistepTrajectory__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<auv::msg::MultistepTrajectory *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MultistepTrajectory__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const auv::msg::MultistepTrajectory *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MultistepTrajectory__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MultistepTrajectory(full_bounded, 0);
}

static message_type_support_callbacks_t _MultistepTrajectory__callbacks = {
  "auv::msg",
  "MultistepTrajectory",
  _MultistepTrajectory__cdr_serialize,
  _MultistepTrajectory__cdr_deserialize,
  _MultistepTrajectory__get_serialized_size,
  _MultistepTrajectory__max_serialized_size
};

static rosidl_message_type_support_t _MultistepTrajectory__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MultistepTrajectory__callbacks,
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
get_message_type_support_handle<auv::msg::MultistepTrajectory>()
{
  return &auv::msg::typesupport_fastrtps_cpp::_MultistepTrajectory__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, auv, msg, MultistepTrajectory)() {
  return &auv::msg::typesupport_fastrtps_cpp::_MultistepTrajectory__handle;
}

#ifdef __cplusplus
}
#endif
