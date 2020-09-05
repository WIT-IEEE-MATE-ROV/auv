// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__SURFACE_COMMAND__STRUCT_HPP_
#define AUV__MSG__DETAIL__SURFACE_COMMAND__STRUCT_HPP_

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
// Member 'desired_trajectory'
#include "auv/msg/detail/trajectory__struct.hpp"
// Member 'io_requests'
#include "auv/msg/detail/io_request__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__auv__msg__SurfaceCommand __attribute__((deprecated))
#else
# define DEPRECATED__auv__msg__SurfaceCommand __declspec(deprecated)
#endif

namespace auv
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SurfaceCommand_
{
  using Type = SurfaceCommand_<ContainerAllocator>;

  explicit SurfaceCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    desired_trajectory(_init)
  {
    (void)_init;
  }

  explicit SurfaceCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    desired_trajectory(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _desired_trajectory_type =
    auv::msg::Trajectory_<ContainerAllocator>;
  _desired_trajectory_type desired_trajectory;
  using _io_requests_type =
    std::vector<auv::msg::IoRequest_<ContainerAllocator>, typename ContainerAllocator::template rebind<auv::msg::IoRequest_<ContainerAllocator>>::other>;
  _io_requests_type io_requests;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__desired_trajectory(
    const auv::msg::Trajectory_<ContainerAllocator> & _arg)
  {
    this->desired_trajectory = _arg;
    return *this;
  }
  Type & set__io_requests(
    const std::vector<auv::msg::IoRequest_<ContainerAllocator>, typename ContainerAllocator::template rebind<auv::msg::IoRequest_<ContainerAllocator>>::other> & _arg)
  {
    this->io_requests = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    auv::msg::SurfaceCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const auv::msg::SurfaceCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<auv::msg::SurfaceCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<auv::msg::SurfaceCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      auv::msg::SurfaceCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<auv::msg::SurfaceCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      auv::msg::SurfaceCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<auv::msg::SurfaceCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<auv::msg::SurfaceCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<auv::msg::SurfaceCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__auv__msg__SurfaceCommand
    std::shared_ptr<auv::msg::SurfaceCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__auv__msg__SurfaceCommand
    std::shared_ptr<auv::msg::SurfaceCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SurfaceCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->desired_trajectory != other.desired_trajectory) {
      return false;
    }
    if (this->io_requests != other.io_requests) {
      return false;
    }
    return true;
  }
  bool operator!=(const SurfaceCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SurfaceCommand_

// alias to use template instance with default allocator
using SurfaceCommand =
  auv::msg::SurfaceCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace auv

#endif  // AUV__MSG__DETAIL__SURFACE_COMMAND__STRUCT_HPP_
