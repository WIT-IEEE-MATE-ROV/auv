// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/PidParams.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__PID_PARAMS__STRUCT_HPP_
#define AUV__MSG__DETAIL__PID_PARAMS__STRUCT_HPP_

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
# define DEPRECATED__auv__msg__PidParams __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__PidParams __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PidParams_
{
  using Type = PidParams_<ContainerAllocator>;

  explicit PidParams_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->p = 0.0f;
      this->i = 0.0f;
      this->d = 0.0f;
    }
  }

  explicit PidParams_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->p = 0.0f;
      this->i = 0.0f;
      this->d = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _p_type =
    float;
  _p_type p;
  using _i_type =
    float;
  _i_type i;
  using _d_type =
    float;
  _d_type d;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__p(
    const float & _arg)
  {
    this->p = _arg;
    return *this;
  }
  Type & set__i(
    const float & _arg)
  {
    this->i = _arg;
    return *this;
  }
  Type & set__d(
    const float & _arg)
  {
    this->d = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::PidParams_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::PidParams_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::PidParams_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::PidParams_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::PidParams_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::PidParams_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::PidParams_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::PidParams_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::PidParams_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::PidParams_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__PidParams
    std::shared_ptr<auv::msg::PidParams_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__PidParams
    std::shared_ptr<auv::msg::PidParams_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PidParams_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->p != other.p) {
      return false;
    }
    if (this->i != other.i) {
      return false;
    }
    if (this->d != other.d) {
      return false;
    }
    return true;
  }
  bool operator!=(const PidParams_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PidParams_

// alias to use template instance with default allocator
using PidParams =
  auv::msg::PidParams_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__PID_PARAMS__STRUCT_HPP_
