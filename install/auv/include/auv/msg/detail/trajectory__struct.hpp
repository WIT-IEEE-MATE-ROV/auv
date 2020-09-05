// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_
#define AUV__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_

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
// Member 'orientation'
#include "auv/msg/detail/orientation__struct.hpp"
// Member 'translation'
#include "auv/msg/detail/translation__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__auv__msg__Trajectory __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__Trajectory __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Trajectory_
{
  using Type = Trajectory_<ContainerAllocator>;

  explicit Trajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    orientation(_init),
    translation(_init)
  {
    (void)_init;
  }

  explicit Trajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    orientation(_alloc, _init),
    translation(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _orientation_type =
    auv::msg::Orientation_<ContainerAllocator>;
  _orientation_type orientation;
  using _translation_type =
    auv::msg::Translation_<ContainerAllocator>;
  _translation_type translation;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__orientation(
    const auv::msg::Orientation_<ContainerAllocator> & _arg)
  {
    this->orientation = _arg;
    return *this;
  }
  Type & set__translation(
    const auv::msg::Translation_<ContainerAllocator> & _arg)
  {
    this->translation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::Trajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::Trajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::Trajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::Trajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::Trajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::Trajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::Trajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::Trajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::Trajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::Trajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__Trajectory
    std::shared_ptr<auv::msg::Trajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__Trajectory
    std::shared_ptr<auv::msg::Trajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Trajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->orientation != other.orientation) {
      return false;
    }
    if (this->translation != other.translation) {
      return false;
    }
    return true;
  }
  bool operator!=(const Trajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Trajectory_

// alias to use template instance with default allocator
using Trajectory =
  auv::msg::Trajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__TRAJECTORY__STRUCT_HPP_
