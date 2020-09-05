// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/MultistepTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__BUILDER_HPP_
#define AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__BUILDER_HPP_

#include "auv/msg/detail/multistep_trajectory__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_MultistepTrajectory_trajectories
{
public:
  explicit Init_MultistepTrajectory_trajectories(::auv::msg::MultistepTrajectory & msg)
  : msg_(msg)
  {}
  ::auv::msg::MultistepTrajectory trajectories(::auv::msg::MultistepTrajectory::_trajectories_type arg)
  {
    msg_.trajectories = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::MultistepTrajectory msg_;
};

class Init_MultistepTrajectory_length
{
public:
  explicit Init_MultistepTrajectory_length(::auv::msg::MultistepTrajectory & msg)
  : msg_(msg)
  {}
  Init_MultistepTrajectory_trajectories length(::auv::msg::MultistepTrajectory::_length_type arg)
  {
    msg_.length = std::move(arg);
    return Init_MultistepTrajectory_trajectories(msg_);
  }

private:
  ::auv::msg::MultistepTrajectory msg_;
};

class Init_MultistepTrajectory_header
{
public:
  Init_MultistepTrajectory_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultistepTrajectory_length header(::auv::msg::MultistepTrajectory::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MultistepTrajectory_length(msg_);
  }

private:
  ::auv::msg::MultistepTrajectory msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::MultistepTrajectory>()
{
  return auv::msg::builder::Init_MultistepTrajectory_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__BUILDER_HPP_
