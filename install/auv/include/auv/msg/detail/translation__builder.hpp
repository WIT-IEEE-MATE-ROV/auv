// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/Translation.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__TRANSLATION__BUILDER_HPP_
#define AUV__MSG__DETAIL__TRANSLATION__BUILDER_HPP_

#include "auv/msg/detail/translation__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_Translation_z
{
public:
  explicit Init_Translation_z(::auv::msg::Translation & msg)
  : msg_(msg)
  {}
  ::auv::msg::Translation z(::auv::msg::Translation::_z_type arg)
  {
    msg_.z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::Translation msg_;
};

class Init_Translation_y
{
public:
  explicit Init_Translation_y(::auv::msg::Translation & msg)
  : msg_(msg)
  {}
  Init_Translation_z y(::auv::msg::Translation::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Translation_z(msg_);
  }

private:
  ::auv::msg::Translation msg_;
};

class Init_Translation_x
{
public:
  explicit Init_Translation_x(::auv::msg::Translation & msg)
  : msg_(msg)
  {}
  Init_Translation_y x(::auv::msg::Translation::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Translation_y(msg_);
  }

private:
  ::auv::msg::Translation msg_;
};

class Init_Translation_header
{
public:
  Init_Translation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Translation_x header(::auv::msg::Translation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Translation_x(msg_);
  }

private:
  ::auv::msg::Translation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::Translation>()
{
  return auv::msg::builder::Init_Translation_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__TRANSLATION__BUILDER_HPP_
