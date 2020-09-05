// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/ThrusterSensor.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_SENSOR__STRUCT_HPP_
#define AUV__MSG__DETAIL__THRUSTER_SENSOR__STRUCT_HPP_

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
# define DEPRECATED__auv__msg__ThrusterSensor __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__ThrusterSensor __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ThrusterSensor_
{
  using Type = ThrusterSensor_<ContainerAllocator>;

  explicit ThrusterSensor_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->thruster = "";
      this->rpm = 0;
      this->current = 0.0f;
      this->estop = false;
    }
  }

  explicit ThrusterSensor_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    thruster(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->thruster = "";
      this->rpm = 0;
      this->current = 0.0f;
      this->estop = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _thruster_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _thruster_type thruster;
  using _rpm_type =
    uint16_t;
  _rpm_type rpm;
  using _current_type =
    float;
  _current_type current;
  using _estop_type =
    bool;
  _estop_type estop;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__thruster(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->thruster = _arg;
    return *this;
  }
  Type & set__rpm(
    const uint16_t & _arg)
  {
    this->rpm = _arg;
    return *this;
  }
  Type & set__current(
    const float & _arg)
  {
    this->current = _arg;
    return *this;
  }
  Type & set__estop(
    const bool & _arg)
  {
    this->estop = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::ThrusterSensor_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::ThrusterSensor_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::ThrusterSensor_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::ThrusterSensor_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::ThrusterSensor_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::ThrusterSensor_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::ThrusterSensor_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::ThrusterSensor_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::ThrusterSensor_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::ThrusterSensor_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__ThrusterSensor
    std::shared_ptr<auv::msg::ThrusterSensor_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__ThrusterSensor
    std::shared_ptr<auv::msg::ThrusterSensor_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ThrusterSensor_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->thruster != other.thruster) {
      return false;
    }
    if (this->rpm != other.rpm) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    if (this->estop != other.estop) {
      return false;
    }
    return true;
  }
  bool operator!=(const ThrusterSensor_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ThrusterSensor_

// alias to use template instance with default allocator
using ThrusterSensor =
  auv::msg::ThrusterSensor_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__THRUSTER_SENSOR__STRUCT_HPP_
