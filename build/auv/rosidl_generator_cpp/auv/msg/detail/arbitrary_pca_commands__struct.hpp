// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/ArbitraryPcaCommands.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__STRUCT_HPP_
#define AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__auv__msg__ArbitraryPcaCommands __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__ArbitraryPcaCommands __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ArbitraryPcaCommands_
{
  using Type = ArbitraryPcaCommands_<ContainerAllocator>;

  explicit ArbitraryPcaCommands_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_thruster = false;
      this->set_channel_pwm = false;
      this->set_channel_pwm_send_count = false;
      this->kill_thruster = false;
      this->unkill_thruster = false;
      this->thruster = "";
      this->channel = 0;
      this->count = 0;
      this->pwm = 0.0f;
    }
  }

  explicit ArbitraryPcaCommands_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    thruster(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->set_thruster = false;
      this->set_channel_pwm = false;
      this->set_channel_pwm_send_count = false;
      this->kill_thruster = false;
      this->unkill_thruster = false;
      this->thruster = "";
      this->channel = 0;
      this->count = 0;
      this->pwm = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _set_thruster_type =
    bool;
  _set_thruster_type set_thruster;
  using _set_channel_pwm_type =
    bool;
  _set_channel_pwm_type set_channel_pwm;
  using _set_channel_pwm_send_count_type =
    bool;
  _set_channel_pwm_send_count_type set_channel_pwm_send_count;
  using _kill_thruster_type =
    bool;
  _kill_thruster_type kill_thruster;
  using _unkill_thruster_type =
    bool;
  _unkill_thruster_type unkill_thruster;
  using _thruster_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _thruster_type thruster;
  using _channel_type =
    uint8_t;
  _channel_type channel;
  using _count_type =
    uint16_t;
  _count_type count;
  using _pwm_type =
    float;
  _pwm_type pwm;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__set_thruster(
    const bool & _arg)
  {
    this->set_thruster = _arg;
    return *this;
  }
  Type & set__set_channel_pwm(
    const bool & _arg)
  {
    this->set_channel_pwm = _arg;
    return *this;
  }
  Type & set__set_channel_pwm_send_count(
    const bool & _arg)
  {
    this->set_channel_pwm_send_count = _arg;
    return *this;
  }
  Type & set__kill_thruster(
    const bool & _arg)
  {
    this->kill_thruster = _arg;
    return *this;
  }
  Type & set__unkill_thruster(
    const bool & _arg)
  {
    this->unkill_thruster = _arg;
    return *this;
  }
  Type & set__thruster(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->thruster = _arg;
    return *this;
  }
  Type & set__channel(
    const uint8_t & _arg)
  {
    this->channel = _arg;
    return *this;
  }
  Type & set__count(
    const uint16_t & _arg)
  {
    this->count = _arg;
    return *this;
  }
  Type & set__pwm(
    const float & _arg)
  {
    this->pwm = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::ArbitraryPcaCommands_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::ArbitraryPcaCommands_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::ArbitraryPcaCommands_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::ArbitraryPcaCommands_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__ArbitraryPcaCommands
    std::shared_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__ArbitraryPcaCommands
    std::shared_ptr<auv::msg::ArbitraryPcaCommands_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ArbitraryPcaCommands_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->set_thruster != other.set_thruster) {
      return false;
    }
    if (this->set_channel_pwm != other.set_channel_pwm) {
      return false;
    }
    if (this->set_channel_pwm_send_count != other.set_channel_pwm_send_count) {
      return false;
    }
    if (this->kill_thruster != other.kill_thruster) {
      return false;
    }
    if (this->unkill_thruster != other.unkill_thruster) {
      return false;
    }
    if (this->thruster != other.thruster) {
      return false;
    }
    if (this->channel != other.channel) {
      return false;
    }
    if (this->count != other.count) {
      return false;
    }
    if (this->pwm != other.pwm) {
      return false;
    }
    return true;
  }
  bool operator!=(const ArbitraryPcaCommands_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ArbitraryPcaCommands_

// alias to use template instance with default allocator
using ArbitraryPcaCommands =
  auv::msg::ArbitraryPcaCommands_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__STRUCT_HPP_
