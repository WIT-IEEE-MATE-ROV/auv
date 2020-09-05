// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ORIENTATION__BUILDER_HPP_
#define AUV__MSG__DETAIL__ORIENTATION__BUILDER_HPP_

#include "auv/msg/detail/orientation__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_Orientation_yaw
{
public:
  explicit Init_Orientation_yaw(::auv::msg::Orientation & msg)
  : msg_(msg)
  {}
  ::auv::msg::Orientation yaw(::auv::msg::Orientation::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::Orientation msg_;
};

class Init_Orientation_pitch
{
public:
  explicit Init_Orientation_pitch(::auv::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_yaw pitch(::auv::msg::Orientation::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_Orientation_yaw(msg_);
  }

private:
  ::auv::msg::Orientation msg_;
};

class Init_Orientation_roll
{
public:
  explicit Init_Orientation_roll(::auv::msg::Orientation & msg)
  : msg_(msg)
  {}
  Init_Orientation_pitch roll(::auv::msg::Orientation::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return Init_Orientation_pitch(msg_);
  }

private:
  ::auv::msg::Orientation msg_;
};

class Init_Orientation_header
{
public:
  Init_Orientation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Orientation_roll header(::auv::msg::Orientation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Orientation_roll(msg_);
  }

private:
  ::auv::msg::Orientation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::Orientation>()
{
  return auv::msg::builder::Init_Orientation_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__ORIENTATION__BUILDER_HPP_
