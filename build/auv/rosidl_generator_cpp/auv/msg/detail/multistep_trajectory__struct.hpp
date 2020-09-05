// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/MultistepTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__STRUCT_HPP_
#define AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__STRUCT_HPP_

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
// Member 'trajectories'
#include "auv/msg/detail/trajectory__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__auv__msg__MultistepTrajectory __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__MultistepTrajectory __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MultistepTrajectory_
{
  using Type = MultistepTrajectory_<ContainerAllocator>;

  explicit MultistepTrajectory_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->length = 0;
    }
  }

  explicit MultistepTrajectory_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->length = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _length_type =
    uint8_t;
  _length_type length;
  using _trajectories_type =
    std::vector<auv::msg::Trajectory_<ContainerAllocator>, typename ContainerAllocator::template rebind<auv::msg::Trajectory_<ContainerAllocator>>::other>;
  _trajectories_type trajectories;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__length(
    const uint8_t & _arg)
  {
    this->length = _arg;
    return *this;
  }
  Type & set__trajectories(
    const std::vector<auv::msg::Trajectory_<ContainerAllocator>, typename ContainerAllocator::template rebind<auv::msg::Trajectory_<ContainerAllocator>>::other> & _arg)
  {
    this->trajectories = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::MultistepTrajectory_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::MultistepTrajectory_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::MultistepTrajectory_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::MultistepTrajectory_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__MultistepTrajectory
    std::shared_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__MultistepTrajectory
    std::shared_ptr<auv::msg::MultistepTrajectory_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MultistepTrajectory_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->length != other.length) {
      return false;
    }
    if (this->trajectories != other.trajectories) {
      return false;
    }
    return true;
  }
  bool operator!=(const MultistepTrajectory_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MultistepTrajectory_

// alias to use template instance with default allocator
using MultistepTrajectory =
  auv::msg::MultistepTrajectory_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__STRUCT_HPP_
