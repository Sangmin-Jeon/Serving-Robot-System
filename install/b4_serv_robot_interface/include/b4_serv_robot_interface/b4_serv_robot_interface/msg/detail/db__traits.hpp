// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__TRAITS_HPP_
#define B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "b4_serv_robot_interface/msg/detail/db__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace b4_serv_robot_interface
{

namespace msg
{

inline void to_flow_style_yaml(
  const DB & msg,
  std::ostream & out)
{
  out << "{";
  // member: order_info
  {
    if (msg.order_info.size() == 0) {
      out << "order_info: []";
    } else {
      out << "order_info: [";
      size_t pending_items = msg.order_info.size();
      for (auto item : msg.order_info) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DB & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: order_info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.order_info.size() == 0) {
      out << "order_info: []\n";
    } else {
      out << "order_info:\n";
      for (auto item : msg.order_info) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DB & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::msg::DB & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::msg::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::msg::DB & msg)
{
  return b4_serv_robot_interface::msg::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::msg::DB>()
{
  return "b4_serv_robot_interface::msg::DB";
}

template<>
inline const char * name<b4_serv_robot_interface::msg::DB>()
{
  return "b4_serv_robot_interface/msg/DB";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::msg::DB>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::msg::DB>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<b4_serv_robot_interface::msg::DB>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__TRAITS_HPP_
