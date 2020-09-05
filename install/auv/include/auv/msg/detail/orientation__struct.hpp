// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ORIENTATION__STRUCT_HPP_
#define AUV__MSG__DETAIL__ORIENTATION__STRUCT_HPP_

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
# define DEPRECATED__auv__msg__Orientation __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__Orientation __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Orientation_
{
  using Type = Orientation_<ContainerAllocator>;

  explicit Orientation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  explicit Orientation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->roll = 0.0f;
      this->pitch = 0.0f;
      this->yaw = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _roll_type =
    float;
  _roll_type roll;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _yaw_type =
    float;
  _yaw_type yaw;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::Orientation_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::Orientation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::Orientation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::Orientation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::Orientation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::Orientation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::Orientation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::Orientation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::Orientation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::Orientation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__Orientation
    std::shared_ptr<auv::msg::Orientation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__Orientation
    std::shared_ptr<auv::msg::Orientation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Orientation_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    return true;
  }
  bool operator!=(const Orientation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Orientation_

// alias to use template instance with default allocator
using Orientation =
  auv::msg::Orientation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__ORIENTATION__STRUCT_HPP_
