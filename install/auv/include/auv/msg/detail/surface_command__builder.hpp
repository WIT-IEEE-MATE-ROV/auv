// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__SURFACE_COMMAND__BUILDER_HPP_
#define AUV__MSG__DETAIL__SURFACE_COMMAND__BUILDER_HPP_

#include "auv/msg/detail/surface_command__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_SurfaceCommand_io_requests
{
public:
  explicit Init_SurfaceCommand_io_requests(::auv::msg::SurfaceCommand & msg)
  : msg_(msg)
  {}
  ::auv::msg::SurfaceCommand io_requests(::auv::msg::SurfaceCommand::_io_requests_type arg)
  {
    msg_.io_requests = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::SurfaceCommand msg_;
};

class Init_SurfaceCommand_desired_trajectory
{
public:
  explicit Init_SurfaceCommand_desired_trajectory(::auv::msg::SurfaceCommand & msg)
  : msg_(msg)
  {}
  Init_SurfaceCommand_io_requests desired_trajectory(::auv::msg::SurfaceCommand::_desired_trajectory_type arg)
  {
    msg_.desired_trajectory = std::move(arg);
    return Init_SurfaceCommand_io_requests(msg_);
  }

private:
  ::auv::msg::SurfaceCommand msg_;
};

class Init_SurfaceCommand_header
{
public:
  Init_SurfaceCommand_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SurfaceCommand_desired_trajectory header(::auv::msg::SurfaceCommand::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SurfaceCommand_desired_trajectory(msg_);
  }

private:
  ::auv::msg::SurfaceCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::SurfaceCommand>()
{
  return auv::msg::builder::Init_SurfaceCommand_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__SURFACE_COMMAND__BUILDER_HPP_
