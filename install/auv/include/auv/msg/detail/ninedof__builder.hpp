// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/Ninedof.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__NINEDOF__BUILDER_HPP_
#define AUV__MSG__DETAIL__NINEDOF__BUILDER_HPP_

#include "auv/msg/detail/ninedof__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_Ninedof_orientation
{
public:
  explicit Init_Ninedof_orientation(::auv::msg::Ninedof & msg)
  : msg_(msg)
  {}
  ::auv::msg::Ninedof orientation(::auv::msg::Ninedof::_orientation_type arg)
  {
    msg_.orientation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::Ninedof msg_;
};

class Init_Ninedof_translation
{
public:
  explicit Init_Ninedof_translation(::auv::msg::Ninedof & msg)
  : msg_(msg)
  {}
  Init_Ninedof_orientation translation(::auv::msg::Ninedof::_translation_type arg)
  {
    msg_.translation = std::move(arg);
    return Init_Ninedof_orientation(msg_);
  }

private:
  ::auv::msg::Ninedof msg_;
};

class Init_Ninedof_header
{
public:
  Init_Ninedof_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ninedof_translation header(::auv::msg::Ninedof::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Ninedof_translation(msg_);
  }

private:
  ::auv::msg::Ninedof msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::Ninedof>()
{
  return auv::msg::builder::Init_Ninedof_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__NINEDOF__BUILDER_HPP_
