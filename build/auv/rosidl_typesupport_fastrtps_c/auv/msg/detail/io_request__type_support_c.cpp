// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from auv:msg/IoRequest.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/io_request__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "auv/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "auv/msg/detail/io_request__struct.h"
#include "auv/msg/detail/io_request__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // executor, string
#include "rosidl_runtime_c/string_functions.h"  // executor, string
#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_auv
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_auv
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_auv
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _IoRequest__ros_msg_type = auv__msg__IoRequest;

static bool _IoRequest__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _IoRequest__ros_msg_type * ros_message = static_cast<const _IoRequest__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: executor
  {
    const rosidl_runtime_c__String * str = &ros_message->executor;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: number
  {
    cdr << ros_message->number;
  }

  // Field name: boolean
  {
    cdr << (ros_message->boolean ? true : false);
  }

  // Field name: int32
  {
    cdr << ros_message->int32;
  }

  // Field name: string
  {
    const rosidl_runtime_c__String * str = &ros_message->string;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _IoRequest__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _IoRequest__ros_msg_type * ros_message = static_cast<_IoRequest__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: executor
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->executor.data) {
      rosidl_runtime_c__String__init(&ros_message->executor);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->executor,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'executor'\n");
      return false;
    }
  }

  // Field name: number
  {
    cdr >> ros_message->number;
  }

  // Field name: boolean
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->boolean = tmp ? true : false;
  }

  // Field name: int32
  {
    cdr >> ros_message->int32;
  }

  // Field name: string
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->string.data) {
      rosidl_runtime_c__String__init(&ros_message->string);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->string,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'string'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t get_serialized_size_auv__msg__IoRequest(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _IoRequest__ros_msg_type * ros_message = static_cast<const _IoRequest__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name executor
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->executor.size + 1);
  // field.name number
  {
    size_t item_size = sizeof(ros_message->number);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name boolean
  {
    size_t item_size = sizeof(ros_message->boolean);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name int32
  {
    size_t item_size = sizeof(ros_message->int32);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name string
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->string.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _IoRequest__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_auv__msg__IoRequest(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_auv
size_t max_serialized_size_auv__msg__IoRequest(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_std_msgs__msg__Header(
        full_bounded, current_alignment);
    }
  }
  // member: executor
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }
  // member: number
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: boolean
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }
  // member: int32
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: string
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _IoRequest__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_auv__msg__IoRequest(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_IoRequest = {
  "auv::msg",
  "IoRequest",
  _IoRequest__cdr_serialize,
  _IoRequest__cdr_deserialize,
  _IoRequest__get_serialized_size,
  _IoRequest__max_serialized_size
};

static rosidl_message_type_support_t _IoRequest__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_IoRequest,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, auv, msg, IoRequest)() {
  return &_IoRequest__type_support;
}

#if defined(__cplusplus)
}
#endif
