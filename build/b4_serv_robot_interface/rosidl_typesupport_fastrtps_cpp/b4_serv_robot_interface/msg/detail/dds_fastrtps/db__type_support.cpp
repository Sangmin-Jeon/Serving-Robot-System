// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice
#include "b4_serv_robot_interface/msg/detail/db__rosidl_typesupport_fastrtps_cpp.hpp"
#include "b4_serv_robot_interface/msg/detail/db__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace b4_serv_robot_interface
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
cdr_serialize(
  const b4_serv_robot_interface::msg::DB & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: order_info
  {
    cdr << ros_message.order_info;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  b4_serv_robot_interface::msg::DB & ros_message)
{
  // Member: order_info
  {
    cdr >> ros_message.order_info;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
get_serialized_size(
  const b4_serv_robot_interface::msg::DB & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: order_info
  {
    size_t array_size = ros_message.order_info.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.order_info[index].size() + 1);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
max_serialized_size_DB(
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


  // Member: order_info
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
    using DataType = b4_serv_robot_interface::msg::DB;
    is_plain =
      (
      offsetof(DataType, order_info) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _DB__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const b4_serv_robot_interface::msg::DB *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _DB__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<b4_serv_robot_interface::msg::DB *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _DB__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const b4_serv_robot_interface::msg::DB *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _DB__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_DB(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _DB__callbacks = {
  "b4_serv_robot_interface::msg",
  "DB",
  _DB__cdr_serialize,
  _DB__cdr_deserialize,
  _DB__get_serialized_size,
  _DB__max_serialized_size
};

static rosidl_message_type_support_t _DB__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_DB__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace b4_serv_robot_interface

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_b4_serv_robot_interface
const rosidl_message_type_support_t *
get_message_type_support_handle<b4_serv_robot_interface::msg::DB>()
{
  return &b4_serv_robot_interface::msg::typesupport_fastrtps_cpp::_DB__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, msg, DB)() {
  return &b4_serv_robot_interface::msg::typesupport_fastrtps_cpp::_DB__handle;
}

#ifdef __cplusplus
}
#endif
