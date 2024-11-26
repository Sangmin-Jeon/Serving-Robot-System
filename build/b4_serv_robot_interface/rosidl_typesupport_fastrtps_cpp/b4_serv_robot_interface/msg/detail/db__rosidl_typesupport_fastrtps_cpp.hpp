// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "b4_serv_robot_interface/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "b4_serv_robot_interface/msg/detail/db__struct.hpp"

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

#include "fastcdr/Cdr.h"

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
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  b4_serv_robot_interface::msg::DB & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
get_serialized_size(
  const b4_serv_robot_interface::msg::DB & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
max_serialized_size_DB(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace b4_serv_robot_interface

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_b4_serv_robot_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, b4_serv_robot_interface, msg, DB)();

#ifdef __cplusplus
}
#endif

#endif  // B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
