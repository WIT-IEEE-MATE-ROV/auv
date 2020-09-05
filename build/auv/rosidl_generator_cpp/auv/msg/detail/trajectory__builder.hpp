// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
#define AUV__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_

#include "auv/msg/detail/trajectory__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_Trajectory_translation
{
public:
  explicit Init_Trajectory_translation(::auv::msg::Trajectory & msg)
  : msg_(msg)
  {}
  ::auv::msg::Trajectory translation(::auv::msg::Trajectory::_translation_type arg)
  {
    msg_.translation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::Trajectory msg_;
};

class Init_Trajectory_orientation
{
public:
  explicit Init_Trajectory_orientation(::auv::msg::Trajectory & msg)
  : msg_(msg)
  {}
  Init_Trajectory_translation orientation(::auv::msg::Trajectory::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return Init_Trajectory_translation(msg_);
  }

private:
  ::auv::msg::Trajectory msg_;
};

class Init_Trajectory_header
{
public:
  Init_Trajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Trajectory_orientation header(::auv::msg::Trajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Trajectory_orientation(msg_);
  }

private:
  ::auv::msg::Trajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::Trajectory>()
{
  return auv::msg::builder::Init_Trajectory_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__TRAJECTORY__BUILDER_HPP_
