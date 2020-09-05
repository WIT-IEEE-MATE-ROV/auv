// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auv:msg/Orientation.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ORIENTATION__TRAITS_HPP_
#define AUV__MSG__DETAIL__ORIENTATION__TRAITS_HPP_

#include "auv/msg/detail/orientation__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auv::msg::Orientation>()
{
  return "auv::msg::Orientation";
}

template<>
struct has_fixed_size<auv::msg::Orientation>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<auv::msg::Orientation>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<auv::msg::Orientation>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUV__MSG__DETAIL__ORIENTATION__TRAITS_HPP_
