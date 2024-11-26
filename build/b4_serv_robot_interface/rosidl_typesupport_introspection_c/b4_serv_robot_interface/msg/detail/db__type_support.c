// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "b4_serv_robot_interface/msg/detail/db__rosidl_typesupport_introspection_c.h"
#include "b4_serv_robot_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "b4_serv_robot_interface/msg/detail/db__functions.h"
#include "b4_serv_robot_interface/msg/detail/db__struct.h"


// Include directives for member types
// Member `order_info`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  b4_serv_robot_interface__msg__DB__init(message_memory);
}

void b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_fini_function(void * message_memory)
{
  b4_serv_robot_interface__msg__DB__fini(message_memory);
}

size_t b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__size_function__DB__order_info(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__get_const_function__DB__order_info(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__get_function__DB__order_info(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__fetch_function__DB__order_info(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__get_const_function__DB__order_info(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__assign_function__DB__order_info(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__get_function__DB__order_info(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__resize_function__DB__order_info(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_member_array[1] = {
  {
    "order_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(b4_serv_robot_interface__msg__DB, order_info),  // bytes offset in struct
    NULL,  // default value
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__size_function__DB__order_info,  // size() function pointer
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__get_const_function__DB__order_info,  // get_const(index) function pointer
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__get_function__DB__order_info,  // get(index) function pointer
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__fetch_function__DB__order_info,  // fetch(index, &value) function pointer
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__assign_function__DB__order_info,  // assign(index, value) function pointer
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__resize_function__DB__order_info  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_members = {
  "b4_serv_robot_interface__msg",  // message namespace
  "DB",  // message name
  1,  // number of fields
  sizeof(b4_serv_robot_interface__msg__DB),
  b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_member_array,  // message members
  b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_init_function,  // function to initialize message memory (memory has to be allocated)
  b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_type_support_handle = {
  0,
  &b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_b4_serv_robot_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, b4_serv_robot_interface, msg, DB)() {
  if (!b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_type_support_handle.typesupport_identifier) {
    b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &b4_serv_robot_interface__msg__DB__rosidl_typesupport_introspection_c__DB_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
