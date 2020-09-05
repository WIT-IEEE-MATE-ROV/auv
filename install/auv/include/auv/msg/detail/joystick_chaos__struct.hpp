// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/JoystickChaos.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__JOYSTICK_CHAOS__STRUCT_HPP_
#define AUV__MSG__DETAIL__JOYSTICK_CHAOS__STRUCT_HPP_

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
# define DEPRECATED__auv__msg__JoystickChaos __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__JoystickChaos __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct JoystickChaos_
{
  using Type = JoystickChaos_<ContainerAllocator>;

  explicit JoystickChaos_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shift_horizontal_correction = 0.0f;
      this->shift_vertical_correction = 0.0f;
      this->shift_twist_correction = 0.0f;
      this->shift_lever_correction = 0.0f;
      this->magnitude_horizontal_correction = 0.0f;
      this->magnitude_vertical_correction = 0.0f;
      this->magnitude_twist_correction = 0.0f;
      this->magnitude_lever_correction = 0.0f;
      this->lag_seconds = 0.0f;
      this->kill_thruster = false;
      this->unkill_thruster = false;
      this->thruster = "";
    }
  }

  explicit JoystickChaos_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    thruster(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->shift_horizontal_correction = 0.0f;
      this->shift_vertical_correction = 0.0f;
      this->shift_twist_correction = 0.0f;
      this->shift_lever_correction = 0.0f;
      this->magnitude_horizontal_correction = 0.0f;
      this->magnitude_vertical_correction = 0.0f;
      this->magnitude_twist_correction = 0.0f;
      this->magnitude_lever_correction = 0.0f;
      this->lag_seconds = 0.0f;
      this->kill_thruster = false;
      this->unkill_thruster = false;
      this->thruster = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _shift_horizontal_correction_type =
    float;
  _shift_horizontal_correction_type shift_horizontal_correction;
  using _shift_vertical_correction_type =
    float;
  _shift_vertical_correction_type shift_vertical_correction;
  using _shift_twist_correction_type =
    float;
  _shift_twist_correction_type shift_twist_correction;
  using _shift_lever_correction_type =
    float;
  _shift_lever_correction_type shift_lever_correction;
  using _magnitude_horizontal_correction_type =
    float;
  _magnitude_horizontal_correction_type magnitude_horizontal_correction;
  using _magnitude_vertical_correction_type =
    float;
  _magnitude_vertical_correction_type magnitude_vertical_correction;
  using _magnitude_twist_correction_type =
    float;
  _magnitude_twist_correction_type magnitude_twist_correction;
  using _magnitude_lever_correction_type =
    float;
  _magnitude_lever_correction_type magnitude_lever_correction;
  using _lag_seconds_type =
    float;
  _lag_seconds_type lag_seconds;
  using _kill_thruster_type =
    bool;
  _kill_thruster_type kill_thruster;
  using _unkill_thruster_type =
    bool;
  _unkill_thruster_type unkill_thruster;
  using _thruster_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _thruster_type thruster;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__shift_horizontal_correction(
    const float & _arg)
  {
    this->shift_horizontal_correction = _arg;
    return *this;
  }
  Type & set__shift_vertical_correction(
    const float & _arg)
  {
    this->shift_vertical_correction = _arg;
    return *this;
  }
  Type & set__shift_twist_correction(
    const float & _arg)
  {
    this->shift_twist_correction = _arg;
    return *this;
  }
  Type & set__shift_lever_correction(
    const float & _arg)
  {
    this->shift_lever_correction = _arg;
    return *this;
  }
  Type & set__magnitude_horizontal_correction(
    const float & _arg)
  {
    this->magnitude_horizontal_correction = _arg;
    return *this;
  }
  Type & set__magnitude_vertical_correction(
    const float & _arg)
  {
    this->magnitude_vertical_correction = _arg;
    return *this;
  }
  Type & set__magnitude_twist_correction(
    const float & _arg)
  {
    this->magnitude_twist_correction = _arg;
    return *this;
  }
  Type & set__magnitude_lever_correction(
    const float & _arg)
  {
    this->magnitude_lever_correction = _arg;
    return *this;
  }
  Type & set__lag_seconds(
    const float & _arg)
  {
    this->lag_seconds = _arg;
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

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::JoystickChaos_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::JoystickChaos_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::JoystickChaos_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::JoystickChaos_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::JoystickChaos_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::JoystickChaos_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::JoystickChaos_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::JoystickChaos_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::JoystickChaos_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::JoystickChaos_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__JoystickChaos
    std::shared_ptr<auv::msg::JoystickChaos_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__JoystickChaos
    std::shared_ptr<auv::msg::JoystickChaos_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const JoystickChaos_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->shift_horizontal_correction != other.shift_horizontal_correction) {
      return false;
    }
    if (this->shift_vertical_correction != other.shift_vertical_correction) {
      return false;
    }
    if (this->shift_twist_correction != other.shift_twist_correction) {
      return false;
    }
    if (this->shift_lever_correction != other.shift_lever_correction) {
      return false;
    }
    if (this->magnitude_horizontal_correction != other.magnitude_horizontal_correction) {
      return false;
    }
    if (this->magnitude_vertical_correction != other.magnitude_vertical_correction) {
      return false;
    }
    if (this->magnitude_twist_correction != other.magnitude_twist_correction) {
      return false;
    }
    if (this->magnitude_lever_correction != other.magnitude_lever_correction) {
      return false;
    }
    if (this->lag_seconds != other.lag_seconds) {
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
    return true;
  }
  bool operator!=(const JoystickChaos_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct JoystickChaos_

// alias to use template instance with default allocator
using JoystickChaos =
  auv::msg::JoystickChaos_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__JOYSTICK_CHAOS__STRUCT_HPP_
