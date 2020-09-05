// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from auv:msg/ArbitraryPcaCommands.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__TRAITS_HPP_
#define AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__TRAITS_HPP_

#include "auv/msg/detail/arbitrary_pca_commands__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<auv::msg::ArbitraryPcaCommands>()
{
  return "auv::msg::ArbitraryPcaCommands";
}

template<>
struct has_fixed_size<auv::msg::ArbitraryPcaCommands>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<auv::msg::ArbitraryPcaCommands>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<auv::msg::ArbitraryPcaCommands>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUV__MSG__DETAIL__ARBITRARY_PCA_COMMANDS__TRAITS_HPP_
