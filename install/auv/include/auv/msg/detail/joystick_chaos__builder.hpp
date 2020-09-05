// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/JoystickChaos.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__JOYSTICK_CHAOS__BUILDER_HPP_
#define AUV__MSG__DETAIL__JOYSTICK_CHAOS__BUILDER_HPP_

#include "auv/msg/detail/joystick_chaos__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_JoystickChaos_thruster
{
public:
  explicit Init_JoystickChaos_thruster(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  ::auv::msg::JoystickChaos thruster(::auv::msg::JoystickChaos::_thruster_type arg)
  {
    msg_.thruster = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_unkill_thruster
{
public:
  explicit Init_JoystickChaos_unkill_thruster(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_thruster unkill_thruster(::auv::msg::JoystickChaos::_unkill_thruster_type arg)
  {
    msg_.unkill_thruster = std::move(arg);
    return Init_JoystickChaos_thruster(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_kill_thruster
{
public:
  explicit Init_JoystickChaos_kill_thruster(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_unkill_thruster kill_thruster(::auv::msg::JoystickChaos::_kill_thruster_type arg)
  {
    msg_.kill_thruster = std::move(arg);
    return Init_JoystickChaos_unkill_thruster(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_lag_seconds
{
public:
  explicit Init_JoystickChaos_lag_seconds(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_kill_thruster lag_seconds(::auv::msg::JoystickChaos::_lag_seconds_type arg)
  {
    msg_.lag_seconds = std::move(arg);
    return Init_JoystickChaos_kill_thruster(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_magnitude_lever_correction
{
public:
  explicit Init_JoystickChaos_magnitude_lever_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_lag_seconds magnitude_lever_correction(::auv::msg::JoystickChaos::_magnitude_lever_correction_type arg)
  {
    msg_.magnitude_lever_correction = std::move(arg);
    return Init_JoystickChaos_lag_seconds(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_magnitude_twist_correction
{
public:
  explicit Init_JoystickChaos_magnitude_twist_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_magnitude_lever_correction magnitude_twist_correction(::auv::msg::JoystickChaos::_magnitude_twist_correction_type arg)
  {
    msg_.magnitude_twist_correction = std::move(arg);
    return Init_JoystickChaos_magnitude_lever_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_magnitude_vertical_correction
{
public:
  explicit Init_JoystickChaos_magnitude_vertical_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_magnitude_twist_correction magnitude_vertical_correction(::auv::msg::JoystickChaos::_magnitude_vertical_correction_type arg)
  {
    msg_.magnitude_vertical_correction = std::move(arg);
    return Init_JoystickChaos_magnitude_twist_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_magnitude_horizontal_correction
{
public:
  explicit Init_JoystickChaos_magnitude_horizontal_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_magnitude_vertical_correction magnitude_horizontal_correction(::auv::msg::JoystickChaos::_magnitude_horizontal_correction_type arg)
  {
    msg_.magnitude_horizontal_correction = std::move(arg);
    return Init_JoystickChaos_magnitude_vertical_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_shift_lever_correction
{
public:
  explicit Init_JoystickChaos_shift_lever_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_magnitude_horizontal_correction shift_lever_correction(::auv::msg::JoystickChaos::_shift_lever_correction_type arg)
  {
    msg_.shift_lever_correction = std::move(arg);
    return Init_JoystickChaos_magnitude_horizontal_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_shift_twist_correction
{
public:
  explicit Init_JoystickChaos_shift_twist_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_shift_lever_correction shift_twist_correction(::auv::msg::JoystickChaos::_shift_twist_correction_type arg)
  {
    msg_.shift_twist_correction = std::move(arg);
    return Init_JoystickChaos_shift_lever_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_shift_vertical_correction
{
public:
  explicit Init_JoystickChaos_shift_vertical_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_shift_twist_correction shift_vertical_correction(::auv::msg::JoystickChaos::_shift_vertical_correction_type arg)
  {
    msg_.shift_vertical_correction = std::move(arg);
    return Init_JoystickChaos_shift_twist_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_shift_horizontal_correction
{
public:
  explicit Init_JoystickChaos_shift_horizontal_correction(::auv::msg::JoystickChaos & msg)
  : msg_(msg)
  {}
  Init_JoystickChaos_shift_vertical_correction shift_horizontal_correction(::auv::msg::JoystickChaos::_shift_horizontal_correction_type arg)
  {
    msg_.shift_horizontal_correction = std::move(arg);
    return Init_JoystickChaos_shift_vertical_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

class Init_JoystickChaos_header
{
public:
  Init_JoystickChaos_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickChaos_shift_horizontal_correction header(::auv::msg::JoystickChaos::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_JoystickChaos_shift_horizontal_correction(msg_);
  }

private:
  ::auv::msg::JoystickChaos msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::JoystickChaos>()
{
  return auv::msg::builder::Init_JoystickChaos_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__JOYSTICK_CHAOS__BUILDER_HPP_
