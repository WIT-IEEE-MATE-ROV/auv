// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/IoRequest.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__IO_REQUEST__BUILDER_HPP_
#define AUV__MSG__DETAIL__IO_REQUEST__BUILDER_HPP_

#include "auv/msg/detail/io_request__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_IoRequest_string
{
public:
  explicit Init_IoRequest_string(::auv::msg::IoRequest & msg)
  : msg_(msg)
  {}
  ::auv::msg::IoRequest string(::auv::msg::IoRequest::_string_type arg)
  {
    msg_.string = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::IoRequest msg_;
};

class Init_IoRequest_int32
{
public:
  explicit Init_IoRequest_int32(::auv::msg::IoRequest & msg)
  : msg_(msg)
  {}
  Init_IoRequest_string int32(::auv::msg::IoRequest::_int32_type arg)
  {
    msg_.int32 = std::move(arg);
    return Init_IoRequest_string(msg_);
  }

private:
  ::auv::msg::IoRequest msg_;
};

class Init_IoRequest_boolean
{
public:
  explicit Init_IoRequest_boolean(::auv::msg::IoRequest & msg)
  : msg_(msg)
  {}
  Init_IoRequest_int32 boolean(::auv::msg::IoRequest::_boolean_type arg)
  {
    msg_.boolean = std::move(arg);
    return Init_IoRequest_int32(msg_);
  }

private:
  ::auv::msg::IoRequest msg_;
};

class Init_IoRequest_number
{
public:
  explicit Init_IoRequest_number(::auv::msg::IoRequest & msg)
  : msg_(msg)
  {}
  Init_IoRequest_boolean number(::auv::msg::IoRequest::_number_type arg)
  {
    msg_.number = std::move(arg);
    return Init_IoRequest_boolean(msg_);
  }

private:
  ::auv::msg::IoRequest msg_;
};

class Init_IoRequest_executor
{
public:
  explicit Init_IoRequest_executor(::auv::msg::IoRequest & msg)
  : msg_(msg)
  {}
  Init_IoRequest_number executor(::auv::msg::IoRequest::_executor_type arg)
  {
    msg_.executor = std::move(arg);
    return Init_IoRequest_number(msg_);
  }

private:
  ::auv::msg::IoRequest msg_;
};

class Init_IoRequest_header
{
public:
  Init_IoRequest_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_IoRequest_executor header(::auv::msg::IoRequest::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_IoRequest_executor(msg_);
  }

private:
  ::auv::msg::IoRequest msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::IoRequest>()
{
  return auv::msg::builder::Init_IoRequest_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__IO_REQUEST__BUILDER_HPP_
