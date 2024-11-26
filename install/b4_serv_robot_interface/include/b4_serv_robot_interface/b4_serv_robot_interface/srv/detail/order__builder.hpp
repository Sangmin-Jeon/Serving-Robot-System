// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from b4_serv_robot_interface:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__BUILDER_HPP_
#define B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "b4_serv_robot_interface/srv/detail/order__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace b4_serv_robot_interface
{

namespace srv
{

namespace builder
{

class Init_Order_Request_order_info
{
public:
  explicit Init_Order_Request_order_info(::b4_serv_robot_interface::srv::Order_Request & msg)
  : msg_(msg)
  {}
  ::b4_serv_robot_interface::srv::Order_Request order_info(::b4_serv_robot_interface::srv::Order_Request::_order_info_type arg)
  {
    msg_.order_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::srv::Order_Request msg_;
};

class Init_Order_Request_table_num
{
public:
  Init_Order_Request_table_num()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Order_Request_order_info table_num(::b4_serv_robot_interface::srv::Order_Request::_table_num_type arg)
  {
    msg_.table_num = std::move(arg);
    return Init_Order_Request_order_info(msg_);
  }

private:
  ::b4_serv_robot_interface::srv::Order_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::srv::Order_Request>()
{
  return b4_serv_robot_interface::srv::builder::Init_Order_Request_table_num();
}

}  // namespace b4_serv_robot_interface


namespace b4_serv_robot_interface
{

namespace srv
{

namespace builder
{

class Init_Order_Response_is_order
{
public:
  Init_Order_Response_is_order()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::b4_serv_robot_interface::srv::Order_Response is_order(::b4_serv_robot_interface::srv::Order_Response::_is_order_type arg)
  {
    msg_.is_order = std::move(arg);
    return std::move(msg_);
  }

private:
  ::b4_serv_robot_interface::srv::Order_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::b4_serv_robot_interface::srv::Order_Response>()
{
  return b4_serv_robot_interface::srv::builder::Init_Order_Response_is_order();
}

}  // namespace b4_serv_robot_interface

#endif  // B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__BUILDER_HPP_
