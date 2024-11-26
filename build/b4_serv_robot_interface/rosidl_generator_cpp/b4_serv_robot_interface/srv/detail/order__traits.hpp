// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from b4_serv_robot_interface:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__TRAITS_HPP_
#define B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "b4_serv_robot_interface/srv/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace b4_serv_robot_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Order_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: table_num
  {
    out << "table_num: ";
    rosidl_generator_traits::value_to_yaml(msg.table_num, out);
    out << ", ";
  }

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
  const Order_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: table_num
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "table_num: ";
    rosidl_generator_traits::value_to_yaml(msg.table_num, out);
    out << "\n";
  }

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

inline std::string to_yaml(const Order_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::srv::Order_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::srv::Order_Request & msg)
{
  return b4_serv_robot_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::srv::Order_Request>()
{
  return "b4_serv_robot_interface::srv::Order_Request";
}

template<>
inline const char * name<b4_serv_robot_interface::srv::Order_Request>()
{
  return "b4_serv_robot_interface/srv/Order_Request";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::srv::Order_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::srv::Order_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<b4_serv_robot_interface::srv::Order_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace b4_serv_robot_interface
{

namespace srv
{

inline void to_flow_style_yaml(
  const Order_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: is_order
  {
    out << "is_order: ";
    rosidl_generator_traits::value_to_yaml(msg.is_order, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Order_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: is_order
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "is_order: ";
    rosidl_generator_traits::value_to_yaml(msg.is_order, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Order_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::srv::Order_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::srv::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::srv::Order_Response & msg)
{
  return b4_serv_robot_interface::srv::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::srv::Order_Response>()
{
  return "b4_serv_robot_interface::srv::Order_Response";
}

template<>
inline const char * name<b4_serv_robot_interface::srv::Order_Response>()
{
  return "b4_serv_robot_interface/srv/Order_Response";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::srv::Order_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::srv::Order_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<b4_serv_robot_interface::srv::Order_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<b4_serv_robot_interface::srv::Order>()
{
  return "b4_serv_robot_interface::srv::Order";
}

template<>
inline const char * name<b4_serv_robot_interface::srv::Order>()
{
  return "b4_serv_robot_interface/srv/Order";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::srv::Order>
  : std::integral_constant<
    bool,
    has_fixed_size<b4_serv_robot_interface::srv::Order_Request>::value &&
    has_fixed_size<b4_serv_robot_interface::srv::Order_Response>::value
  >
{
};

template<>
struct has_bounded_size<b4_serv_robot_interface::srv::Order>
  : std::integral_constant<
    bool,
    has_bounded_size<b4_serv_robot_interface::srv::Order_Request>::value &&
    has_bounded_size<b4_serv_robot_interface::srv::Order_Response>::value
  >
{
};

template<>
struct is_service<b4_serv_robot_interface::srv::Order>
  : std::true_type
{
};

template<>
struct is_service_request<b4_serv_robot_interface::srv::Order_Request>
  : std::true_type
{
};

template<>
struct is_service_response<b4_serv_robot_interface::srv::Order_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__TRAITS_HPP_
