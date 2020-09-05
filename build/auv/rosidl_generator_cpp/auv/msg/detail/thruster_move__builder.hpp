// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/ThrusterMove.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_MOVE__BUILDER_HPP_
#define AUV__MSG__DETAIL__THRUSTER_MOVE__BUILDER_HPP_

#include "auv/msg/detail/thruster_move__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_ThrusterMove_back_right
{
public:
  explicit Init_ThrusterMove_back_right(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  ::auv::msg::ThrusterMove back_right(::auv::msg::ThrusterMove::_back_right_type arg)
  {
    msg_.back_right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_back_left
{
public:
  explicit Init_ThrusterMove_back_left(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_back_right back_left(::auv::msg::ThrusterMove::_back_left_type arg)
  {
    msg_.back_left = std::move(arg);
    return Init_ThrusterMove_back_right(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_front_right
{
public:
  explicit Init_ThrusterMove_front_right(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_back_left front_right(::auv::msg::ThrusterMove::_front_right_type arg)
  {
    msg_.front_right = std::move(arg);
    return Init_ThrusterMove_back_left(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_front_left
{
public:
  explicit Init_ThrusterMove_front_left(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_front_right front_left(::auv::msg::ThrusterMove::_front_left_type arg)
  {
    msg_.front_left = std::move(arg);
    return Init_ThrusterMove_front_right(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_top_right
{
public:
  explicit Init_ThrusterMove_top_right(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_front_left top_right(::auv::msg::ThrusterMove::_top_right_type arg)
  {
    msg_.top_right = std::move(arg);
    return Init_ThrusterMove_front_left(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_top_left
{
public:
  explicit Init_ThrusterMove_top_left(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_top_right top_left(::auv::msg::ThrusterMove::_top_left_type arg)
  {
    msg_.top_left = std::move(arg);
    return Init_ThrusterMove_top_right(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_top_back
{
public:
  explicit Init_ThrusterMove_top_back(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_top_left top_back(::auv::msg::ThrusterMove::_top_back_type arg)
  {
    msg_.top_back = std::move(arg);
    return Init_ThrusterMove_top_left(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_top_front
{
public:
  explicit Init_ThrusterMove_top_front(::auv::msg::ThrusterMove & msg)
  : msg_(msg)
  {}
  Init_ThrusterMove_top_back top_front(::auv::msg::ThrusterMove::_top_front_type arg)
  {
    msg_.top_front = std::move(arg);
    return Init_ThrusterMove_top_back(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

class Init_ThrusterMove_header
{
public:
  Init_ThrusterMove_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ThrusterMove_top_front header(::auv::msg::ThrusterMove::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ThrusterMove_top_front(msg_);
  }

private:
  ::auv::msg::ThrusterMove msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::ThrusterMove>()
{
  return auv::msg::builder::Init_ThrusterMove_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__THRUSTER_MOVE__BUILDER_HPP_
