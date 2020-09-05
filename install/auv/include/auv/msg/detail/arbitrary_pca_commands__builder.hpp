// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/ArbitraryPcaCommands.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__BUILDER_HPP_
#define AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__BUILDER_HPP_

#include "auv/msg/detail/arbitrary_pca_commands__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_ArbitraryPcaCommands_pwm
{
public:
  explicit Init_ArbitraryPcaCommands_pwm(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  ::auv::msg::ArbitraryPcaCommands pwm(::auv::msg::ArbitraryPcaCommands::_pwm_type arg)
  {
    msg_.pwm = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_count
{
public:
  explicit Init_ArbitraryPcaCommands_count(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_pwm count(::auv::msg::ArbitraryPcaCommands::_count_type arg)
  {
    msg_.count = std::move(arg);
    return Init_ArbitraryPcaCommands_pwm(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_channel
{
public:
  explicit Init_ArbitraryPcaCommands_channel(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_count channel(::auv::msg::ArbitraryPcaCommands::_channel_type arg)
  {
    msg_.channel = std::move(arg);
    return Init_ArbitraryPcaCommands_count(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_thruster
{
public:
  explicit Init_ArbitraryPcaCommands_thruster(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_channel thruster(::auv::msg::ArbitraryPcaCommands::_thruster_type arg)
  {
    msg_.thruster = std::move(arg);
    return Init_ArbitraryPcaCommands_channel(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_unkill_thruster
{
public:
  explicit Init_ArbitraryPcaCommands_unkill_thruster(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_thruster unkill_thruster(::auv::msg::ArbitraryPcaCommands::_unkill_thruster_type arg)
  {
    msg_.unkill_thruster = std::move(arg);
    return Init_ArbitraryPcaCommands_thruster(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_kill_thruster
{
public:
  explicit Init_ArbitraryPcaCommands_kill_thruster(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_unkill_thruster kill_thruster(::auv::msg::ArbitraryPcaCommands::_kill_thruster_type arg)
  {
    msg_.kill_thruster = std::move(arg);
    return Init_ArbitraryPcaCommands_unkill_thruster(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_set_channel_pwm_send_count
{
public:
  explicit Init_ArbitraryPcaCommands_set_channel_pwm_send_count(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_kill_thruster set_channel_pwm_send_count(::auv::msg::ArbitraryPcaCommands::_set_channel_pwm_send_count_type arg)
  {
    msg_.set_channel_pwm_send_count = std::move(arg);
    return Init_ArbitraryPcaCommands_kill_thruster(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_set_channel_pwm
{
public:
  explicit Init_ArbitraryPcaCommands_set_channel_pwm(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_set_channel_pwm_send_count set_channel_pwm(::auv::msg::ArbitraryPcaCommands::_set_channel_pwm_type arg)
  {
    msg_.set_channel_pwm = std::move(arg);
    return Init_ArbitraryPcaCommands_set_channel_pwm_send_count(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_set_thruster
{
public:
  explicit Init_ArbitraryPcaCommands_set_thruster(::auv::msg::ArbitraryPcaCommands & msg)
  : msg_(msg)
  {}
  Init_ArbitraryPcaCommands_set_channel_pwm set_thruster(::auv::msg::ArbitraryPcaCommands::_set_thruster_type arg)
  {
    msg_.set_thruster = std::move(arg);
    return Init_ArbitraryPcaCommands_set_channel_pwm(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

class Init_ArbitraryPcaCommands_header
{
public:
  Init_ArbitraryPcaCommands_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ArbitraryPcaCommands_set_thruster header(::auv::msg::ArbitraryPcaCommands::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ArbitraryPcaCommands_set_thruster(msg_);
  }

private:
  ::auv::msg::ArbitraryPcaCommands msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::ArbitraryPcaCommands>()
{
  return auv::msg::builder::Init_ArbitraryPcaCommands_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__BUILDER_HPP_
