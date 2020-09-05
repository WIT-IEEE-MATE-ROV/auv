// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auv:msg/MultistepTrajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__TRAITS_HPP_
#define AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__TRAITS_HPP_

#include "auv/msg/detail/multistep_trajectory__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auv::msg::MultistepTrajectory>()
{
  return "auv::msg::MultistepTrajectory";
}

template<>
struct has_fixed_size<auv::msg::MultistepTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<auv::msg::MultistepTrajectory>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<auv::msg::MultistepTrajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUV__MSG__DETAIL__MULTISTEP_TRAJECTORY__TRAITS_HPP_
