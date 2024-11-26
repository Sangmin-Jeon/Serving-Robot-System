// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice
#include "b4_serv_robot_interface/msg/detail/db__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "b4_serv_robot_interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "b4_serv_robot_interface/msg/detail/db__struct.h"
#include "b4_serv_robot_interface/msg/detail/db__functions.h"
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

#include "rosidl_runtime_c/string.h"  // order_info
#include "rosidl_runtime_c/string_functions.h"  // order_info

// forward declare type support functions


using _DB__ros_msg_type = b4_serv_robot_interface__msg__DB;

static bool _DB__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _DB__ros_msg_type * ros_message = static_cast<const _DB__ros_msg_type *>(untyped_ros_message);
  // Field name: order_info
  {
    size_t size = ros_message->order_info.size;
    auto array_ptr = ros_message->order_info.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
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
  }

  return true;
}

static bool _DB__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _DB__ros_msg_type * ros_message = static_cast<_DB__ros_msg_type *>(untyped_ros_message);
  // Field name: order_info
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->order_info.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->order_info);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->order_info, size)) {
      fprintf(stderr, "failed to create array for field 'order_info'");
      return false;
    }
    auto array_ptr = ros_message->order_info.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'order_info'\n");
        return false;
      }
    }
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_b4_serv_robot_interface
size_t get_serialized_size_b4_serv_robot_interface__msg__DB(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _DB__ros_msg_type * ros_message = static_cast<const _DB__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name order_info
  {
    size_t array_size = ros_message->order_info.size;
    auto array_ptr = ros_message->order_info.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }

  return current_alignment - initial_alignment;
}

static uint32_t _DB__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_b4_serv_robot_interface__msg__DB(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_b4_serv_robot_interface
size_t max_serialized_size_b4_serv_robot_interface__msg__DB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: order_info
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = b4_serv_robot_interface__msg__DB;
    is_plain =
      (
      offsetof(DataType, order_info) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _DB__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_b4_serv_robot_interface__msg__DB(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_DB = {
  "b4_serv_robot_interface::msg",
  "DB",
  _DB__cdr_serialize,
  _DB__cdr_deserialize,
  _DB__get_serialized_size,
  _DB__max_serialized_size
};

static rosidl_message_type_support_t _DB__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_DB,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, b4_serv_robot_interface, msg, DB)() {
  return &_DB__type_support;
}

#if defined(__cplusplus)
}
#endif
