// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "auv/msg/detail/surface_command__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace auv
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SurfaceCommand_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) auv::msg::SurfaceCommand(_init);
}

void SurfaceCommand_fini_function(void * message_memory)
{
  auto typed_message = static_cast<auv::msg::SurfaceCommand *>(message_memory);
  typed_message->~SurfaceCommand();
}

size_t size_function__SurfaceCommand__io_requests(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<auv::msg::IoRequest> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SurfaceCommand__io_requests(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<auv::msg::IoRequest> *>(untyped_member);
  return &member[index];
}

void * get_function__SurfaceCommand__io_requests(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<auv::msg::IoRequest> *>(untyped_member);
  return &member[index];
}

void resize_function__SurfaceCommand__io_requests(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<auv::msg::IoRequest> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SurfaceCommand_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv::msg::SurfaceCommand, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "desired_trajectory",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<auv::msg::Trajectory>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv::msg::SurfaceCommand, desired_trajectory),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "io_requests",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<auv::msg::IoRequest>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(auv::msg::SurfaceCommand, io_requests),  // bytes offset in struct
    nullptr,  // default value
    size_function__SurfaceCommand__io_requests,  // size() function pointer
    get_const_function__SurfaceCommand__io_requests,  // get_const(index) function pointer
    get_function__SurfaceCommand__io_requests,  // get(index) function pointer
    resize_function__SurfaceCommand__io_requests  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SurfaceCommand_message_members = {
  "auv::msg",  // message namespace
  "SurfaceCommand",  // message name
  3,  // number of fields
  sizeof(auv::msg::SurfaceCommand),
  SurfaceCommand_message_member_array,  // message members
  SurfaceCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  SurfaceCommand_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SurfaceCommand_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SurfaceCommand_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace auv


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<auv::msg::SurfaceCommand>()
{
  return &::auv::msg::rosidl_typesupport_introspection_cpp::SurfaceCommand_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, auv, msg, SurfaceCommand)() {
  return &::auv::msg::rosidl_typesupport_introspection_cpp::SurfaceCommand_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
