// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__STRUCT_H_
#define B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'order_info'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/DB in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__msg__DB
{
  rosidl_runtime_c__String__Sequence order_info;
} b4_serv_robot_interface__msg__DB;

// Struct for a sequence of b4_serv_robot_interface__msg__DB.
typedef struct b4_serv_robot_interface__msg__DB__Sequence
{
  b4_serv_robot_interface__msg__DB * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__msg__DB__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // B4_SERV_ROBOT_INTERFACE__MSG__DETAIL__DB__STRUCT_H_
