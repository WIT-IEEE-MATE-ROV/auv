// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/ThrusterMove.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_MOVE__STRUCT_HPP_
#define AUV__MSG__DETAIL__THRUSTER_MOVE__STRUCT_HPP_

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
# define DEPRECATED__auv__msg__ThrusterMove __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__ThrusterMove __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ThrusterMove_
{
  using Type = ThrusterMove_<ContainerAllocator>;

  explicit ThrusterMove_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->top_front = 0.0f;
      this->top_back = 0.0f;
      this->top_left = 0.0f;
      this->top_right = 0.0f;
      this->front_left = 0.0f;
      this->front_right = 0.0f;
      this->back_left = 0.0f;
      this->back_right = 0.0f;
    }
  }

  explicit ThrusterMove_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->top_front = 0.0f;
      this->top_back = 0.0f;
      this->top_left = 0.0f;
      this->top_right = 0.0f;
      this->front_left = 0.0f;
      this->front_right = 0.0f;
      this->back_left = 0.0f;
      this->back_right = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _top_front_type =
    float;
  _top_front_type top_front;
  using _top_back_type =
    float;
  _top_back_type top_back;
  using _top_left_type =
    float;
  _top_left_type top_left;
  using _top_right_type =
    float;
  _top_right_type top_right;
  using _front_left_type =
    float;
  _front_left_type front_left;
  using _front_right_type =
    float;
  _front_right_type front_right;
  using _back_left_type =
    float;
  _back_left_type back_left;
  using _back_right_type =
    float;
  _back_right_type back_right;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__top_front(
    const float & _arg)
  {
    this->top_front = _arg;
    return *this;
  }
  Type & set__top_back(
    const float & _arg)
  {
    this->top_back = _arg;
    return *this;
  }
  Type & set__top_left(
    const float & _arg)
  {
    this->top_left = _arg;
    return *this;
  }
  Type & set__top_right(
    const float & _arg)
  {
    this->top_right = _arg;
    return *this;
  }
  Type & set__front_left(
    const float & _arg)
  {
    this->front_left = _arg;
    return *this;
  }
  Type & set__front_right(
    const float & _arg)
  {
    this->front_right = _arg;
    return *this;
  }
  Type & set__back_left(
    const float & _arg)
  {
    this->back_left = _arg;
    return *this;
  }
  Type & set__back_right(
    const float & _arg)
  {
    this->back_right = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::ThrusterMove_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::ThrusterMove_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::ThrusterMove_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::ThrusterMove_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::ThrusterMove_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::ThrusterMove_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::ThrusterMove_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::ThrusterMove_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::ThrusterMove_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::ThrusterMove_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__ThrusterMove
    std::shared_ptr<auv::msg::ThrusterMove_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__ThrusterMove
    std::shared_ptr<auv::msg::ThrusterMove_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ThrusterMove_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->top_front != other.top_front) {
      return false;
    }
    if (this->top_back != other.top_back) {
      return false;
    }
    if (this->top_left != other.top_left) {
      return false;
    }
    if (this->top_right != other.top_right) {
      return false;
    }
    if (this->front_left != other.front_left) {
      return false;
    }
    if (this->front_right != other.front_right) {
      return false;
    }
    if (this->back_left != other.back_left) {
      return false;
    }
    if (this->back_right != other.back_right) {
      return false;
    }
    return true;
  }
  bool operator!=(const ThrusterMove_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ThrusterMove_

// alias to use template instance with default allocator
using ThrusterMove =
  auv::msg::ThrusterMove_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__THRUSTER_MOVE__STRUCT_HPP_
