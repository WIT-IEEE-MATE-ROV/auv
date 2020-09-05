// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/PidParams.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__PID_PARAMS__BUILDER_HPP_
#define AUV__MSG__DETAIL__PID_PARAMS__BUILDER_HPP_

#include "auv/msg/detail/pid_params__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_PidParams_d
{
public:
  explicit Init_PidParams_d(::auv::msg::PidParams & msg)
  : msg_(msg)
  {}
  ::auv::msg::PidParams d(::auv::msg::PidParams::_d_type arg)
  {
    msg_.d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::PidParams msg_;
};

class Init_PidParams_i
{
public:
  explicit Init_PidParams_i(::auv::msg::PidParams & msg)
  : msg_(msg)
  {}
  Init_PidParams_d i(::auv::msg::PidParams::_i_type arg)
  {
    msg_.i = std::move(arg);
    return Init_PidParams_d(msg_);
  }

private:
  ::auv::msg::PidParams msg_;
};

class Init_PidParams_p
{
public:
  explicit Init_PidParams_p(::auv::msg::PidParams & msg)
  : msg_(msg)
  {}
  Init_PidParams_i p(::auv::msg::PidParams::_p_type arg)
  {
    msg_.p = std::move(arg);
    return Init_PidParams_i(msg_);
  }

private:
  ::auv::msg::PidParams msg_;
};

class Init_PidParams_header
{
public:
  Init_PidParams_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PidParams_p header(::auv::msg::PidParams::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PidParams_p(msg_);
  }

private:
  ::auv::msg::PidParams msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::PidParams>()
{
  return auv::msg::builder::Init_PidParams_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__PID_PARAMS__BUILDER_HPP_
