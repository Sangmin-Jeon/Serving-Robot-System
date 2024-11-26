// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from b4_serv_robot_interface:action/Monitor.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__TRAITS_HPP_
#define B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "b4_serv_robot_interface/action/detail/monitor__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal
  {
    out << "goal: ";
    rosidl_generator_traits::value_to_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal: ";
    rosidl_generator_traits::value_to_yaml(msg.goal, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_Goal & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_Goal>()
{
  return "b4_serv_robot_interface::action::Monitor_Goal";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_Goal>()
{
  return "b4_serv_robot_interface/action/Monitor_Goal";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_Result & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_Result>()
{
  return "b4_serv_robot_interface::action::Monitor_Result";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_Result>()
{
  return "b4_serv_robot_interface/action/Monitor_Result";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos
  {
    out << "pos: ";
    rosidl_generator_traits::value_to_yaml(msg.pos, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos: ";
    rosidl_generator_traits::value_to_yaml(msg.pos, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_Feedback & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_Feedback>()
{
  return "b4_serv_robot_interface::action::Monitor_Feedback";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_Feedback>()
{
  return "b4_serv_robot_interface/action/Monitor_Feedback";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "b4_serv_robot_interface/action/detail/monitor__traits.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_SendGoal_Request & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_SendGoal_Request>()
{
  return "b4_serv_robot_interface::action::Monitor_SendGoal_Request";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_SendGoal_Request>()
{
  return "b4_serv_robot_interface/action/Monitor_SendGoal_Request";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<b4_serv_robot_interface::action::Monitor_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<b4_serv_robot_interface::action::Monitor_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_SendGoal_Response & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_SendGoal_Response>()
{
  return "b4_serv_robot_interface::action::Monitor_SendGoal_Response";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_SendGoal_Response>()
{
  return "b4_serv_robot_interface/action/Monitor_SendGoal_Response";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_SendGoal>()
{
  return "b4_serv_robot_interface::action::Monitor_SendGoal";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_SendGoal>()
{
  return "b4_serv_robot_interface/action/Monitor_SendGoal";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<b4_serv_robot_interface::action::Monitor_SendGoal_Request>::value &&
    has_fixed_size<b4_serv_robot_interface::action::Monitor_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<b4_serv_robot_interface::action::Monitor_SendGoal_Request>::value &&
    has_bounded_size<b4_serv_robot_interface::action::Monitor_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<b4_serv_robot_interface::action::Monitor_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<b4_serv_robot_interface::action::Monitor_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<b4_serv_robot_interface::action::Monitor_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_GetResult_Request & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_GetResult_Request>()
{
  return "b4_serv_robot_interface::action::Monitor_GetResult_Request";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_GetResult_Request>()
{
  return "b4_serv_robot_interface/action/Monitor_GetResult_Request";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__traits.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_GetResult_Response & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_GetResult_Response>()
{
  return "b4_serv_robot_interface::action::Monitor_GetResult_Response";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_GetResult_Response>()
{
  return "b4_serv_robot_interface/action/Monitor_GetResult_Response";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<b4_serv_robot_interface::action::Monitor_Result>::value> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<b4_serv_robot_interface::action::Monitor_Result>::value> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_GetResult>()
{
  return "b4_serv_robot_interface::action::Monitor_GetResult";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_GetResult>()
{
  return "b4_serv_robot_interface/action/Monitor_GetResult";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<b4_serv_robot_interface::action::Monitor_GetResult_Request>::value &&
    has_fixed_size<b4_serv_robot_interface::action::Monitor_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<b4_serv_robot_interface::action::Monitor_GetResult_Request>::value &&
    has_bounded_size<b4_serv_robot_interface::action::Monitor_GetResult_Response>::value
  >
{
};

template<>
struct is_service<b4_serv_robot_interface::action::Monitor_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<b4_serv_robot_interface::action::Monitor_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<b4_serv_robot_interface::action::Monitor_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__traits.hpp"

namespace b4_serv_robot_interface
{

namespace action
{

inline void to_flow_style_yaml(
  const Monitor_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Monitor_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Monitor_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace b4_serv_robot_interface

namespace rosidl_generator_traits
{

[[deprecated("use b4_serv_robot_interface::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const b4_serv_robot_interface::action::Monitor_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  b4_serv_robot_interface::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use b4_serv_robot_interface::action::to_yaml() instead")]]
inline std::string to_yaml(const b4_serv_robot_interface::action::Monitor_FeedbackMessage & msg)
{
  return b4_serv_robot_interface::action::to_yaml(msg);
}

template<>
inline const char * data_type<b4_serv_robot_interface::action::Monitor_FeedbackMessage>()
{
  return "b4_serv_robot_interface::action::Monitor_FeedbackMessage";
}

template<>
inline const char * name<b4_serv_robot_interface::action::Monitor_FeedbackMessage>()
{
  return "b4_serv_robot_interface/action/Monitor_FeedbackMessage";
}

template<>
struct has_fixed_size<b4_serv_robot_interface::action::Monitor_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<b4_serv_robot_interface::action::Monitor_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<b4_serv_robot_interface::action::Monitor_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<b4_serv_robot_interface::action::Monitor_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<b4_serv_robot_interface::action::Monitor_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<b4_serv_robot_interface::action::Monitor>
  : std::true_type
{
};

template<>
struct is_action_goal<b4_serv_robot_interface::action::Monitor_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<b4_serv_robot_interface::action::Monitor_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<b4_serv_robot_interface::action::Monitor_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__TRAITS_HPP_
