// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from auv:msg/ThrusterSensor.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_SENSOR__BUILDER_HPP_
#define AUV__MSG__DETAIL__THRUSTER_SENSOR__BUILDER_HPP_

#include "auv/msg/detail/thruster_sensor__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace auv
{

namespace msg
{

namespace builder
{

class Init_ThrusterSensor_estop
{
public:
  explicit Init_ThrusterSensor_estop(::auv::msg::ThrusterSensor & msg)
  : msg_(msg)
  {}
  ::auv::msg::ThrusterSensor estop(::auv::msg::ThrusterSensor::_estop_type arg)
  {
    msg_.estop = std::move(arg);
    return std::move(msg_);
  }

private:
  ::auv::msg::ThrusterSensor msg_;
};

class Init_ThrusterSensor_current
{
public:
  explicit Init_ThrusterSensor_current(::auv::msg::ThrusterSensor & msg)
  : msg_(msg)
  {}
  Init_ThrusterSensor_estop current(::auv::msg::ThrusterSensor::_current_type arg)
  {
    msg_.current = std::move(arg);
    return Init_ThrusterSensor_estop(msg_);
  }

private:
  ::auv::msg::ThrusterSensor msg_;
};

class Init_ThrusterSensor_rpm
{
public:
  explicit Init_ThrusterSensor_rpm(::auv::msg::ThrusterSensor & msg)
  : msg_(msg)
  {}
  Init_ThrusterSensor_current rpm(::auv::msg::ThrusterSensor::_rpm_type arg)
  {
    msg_.rpm = std::move(arg);
    return Init_ThrusterSensor_current(msg_);
  }

private:
  ::auv::msg::ThrusterSensor msg_;
};

class Init_ThrusterSensor_thruster
{
public:
  explicit Init_ThrusterSensor_thruster(::auv::msg::ThrusterSensor & msg)
  : msg_(msg)
  {}
  Init_ThrusterSensor_rpm thruster(::auv::msg::ThrusterSensor::_thruster_type arg)
  {
    msg_.thruster = std::move(arg);
    return Init_ThrusterSensor_rpm(msg_);
  }

private:
  ::auv::msg::ThrusterSensor msg_;
};

class Init_ThrusterSensor_header
{
public:
  Init_ThrusterSensor_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ThrusterSensor_thruster header(::auv::msg::ThrusterSensor::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ThrusterSensor_thruster(msg_);
  }

private:
  ::auv::msg::ThrusterSensor msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::auv::msg::ThrusterSensor>()
{
  return auv::msg::builder::Init_ThrusterSensor_header();
}

}  // namespace auv

#endif  // AUV__MSG__DETAIL__THRUSTER_SENSOR__BUILDER_HPP_
