// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auv:msg/Trajectory.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
#define AUV__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_

#include "auv/msg/detail/trajectory__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'orientation'
#include "auv/msg/detail/orientation__traits.hpp"
// Member 'translation'
#include "auv/msg/detail/translation__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auv::msg::Trajectory>()
{
  return "auv::msg::Trajectory";
}

template<>
struct has_fixed_size<auv::msg::Trajectory>
  : std::integral_constant<bool, has_fixed_size<auv::msg::Orientation>::value && has_fixed_size<auv::msg::Translation>::value && has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<auv::msg::Trajectory>
  : std::integral_constant<bool, has_bounded_size<auv::msg::Orientation>::value && has_bounded_size<auv::msg::Translation>::value && has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<auv::msg::Trajectory>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUV__MSG__DETAIL__TRAJECTORY__TRAITS_HPP_
