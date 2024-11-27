// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from b4_serv_robot_interface:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__STRUCT_H_
#define B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'table_num'
// Member 'order_info'
// Member 'order_time'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Order in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__srv__Order_Request
{
  rosidl_runtime_c__String table_num;
  rosidl_runtime_c__String__Sequence order_info;
  rosidl_runtime_c__String order_time;
} b4_serv_robot_interface__srv__Order_Request;

// Struct for a sequence of b4_serv_robot_interface__srv__Order_Request.
typedef struct b4_serv_robot_interface__srv__Order_Request__Sequence
{
  b4_serv_robot_interface__srv__Order_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__srv__Order_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/Order in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__srv__Order_Response
{
  bool is_order;
} b4_serv_robot_interface__srv__Order_Response;

// Struct for a sequence of b4_serv_robot_interface__srv__Order_Response.
typedef struct b4_serv_robot_interface__srv__Order_Response__Sequence
{
  b4_serv_robot_interface__srv__Order_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__srv__Order_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__STRUCT_H_
