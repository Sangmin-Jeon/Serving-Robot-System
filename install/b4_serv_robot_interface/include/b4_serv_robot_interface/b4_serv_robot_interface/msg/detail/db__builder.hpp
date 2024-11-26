// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__BUILDER_HPP_
#define B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "b4_serv_robot_interface/msg/detail/db__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace b4_serv_robot_interface
{

namespace msg
{

namespace builder
{

class Init_DB_order_info
{
public:
  Init_DB_order_info()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::b4_serv_robot_interface::msg::DB order_info(::b4_serv_robot_interface::msg::DB::_order_info_type arg)
  {
    msg_.order_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::msg::DB msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::msg::DB>()
{
  return b4_serv_robot_interface::msg::builder::Init_DB_order_info();
}

}  // namespace b4_serv_robot_interface

#endif  // B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__BUILDER_HPP_
