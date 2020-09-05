// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/IoRequest.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__IO_REQUEST__STRUCT_HPP_
#define AUV__MSG__DETAIL__IO_REQUEST__STRUCT_HPP_

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
# define DEPRECATED__auv__msg__IoRequest __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__IoRequest __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct IoRequest_
{
  using Type = IoRequest_<ContainerAllocator>;

  explicit IoRequest_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->executor = "";
      this->number = 0.0f;
      this->boolean = false;
      this->int32 = 0l;
      this->string = "";
    }
  }

  explicit IoRequest_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    executor(_alloc),
    string(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->executor = "";
      this->number = 0.0f;
      this->boolean = false;
      this->int32 = 0l;
      this->string = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _executor_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _executor_type executor;
  using _number_type =
    float;
  _number_type number;
  using _boolean_type =
    bool;
  _boolean_type boolean;
  using _int32_type =
    int32_t;
  _int32_type int32;
  using _string_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _string_type string;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__executor(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->executor = _arg;
    return *this;
  }
  Type & set__number(
    const float & _arg)
  {
    this->number = _arg;
    return *this;
  }
  Type & set__boolean(
    const bool & _arg)
  {
    this->boolean = _arg;
    return *this;
  }
  Type & set__int32(
    const int32_t & _arg)
  {
    this->int32 = _arg;
    return *this;
  }
  Type & set__string(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->string = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::IoRequest_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::IoRequest_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::IoRequest_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::IoRequest_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::IoRequest_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::IoRequest_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::IoRequest_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::IoRequest_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::IoRequest_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::IoRequest_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__IoRequest
    std::shared_ptr<auv::msg::IoRequest_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__IoRequest
    std::shared_ptr<auv::msg::IoRequest_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const IoRequest_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->executor != other.executor) {
      return false;
    }
    if (this->number != other.number) {
      return false;
    }
    if (this->boolean != other.boolean) {
      return false;
    }
    if (this->int32 != other.int32) {
      return false;
    }
    if (this->string != other.string) {
      return false;
    }
    return true;
  }
  bool operator!=(const IoRequest_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct IoRequest_

// alias to use template instance with default allocator
using IoRequest =
  auv::msg::IoRequest_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__IO_REQUEST__STRUCT_HPP_
