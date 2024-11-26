// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from b4_serv_robot_interface:action/Monitor.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__STRUCT_H_
#define B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_Goal
{
  float goal;
} b4_serv_robot_interface__action__Monitor_Goal;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_Goal.
typedef struct b4_serv_robot_interface__action__Monitor_Goal__Sequence
{
  b4_serv_robot_interface__action__Monitor_Goal * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_Goal__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/string.h"

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_Result
{
  rosidl_runtime_c__String status;
} b4_serv_robot_interface__action__Monitor_Result;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_Result.
typedef struct b4_serv_robot_interface__action__Monitor_Result__Sequence
{
  b4_serv_robot_interface__action__Monitor_Result * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_Result__Sequence;


// Constants defined in the message

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_Feedback
{
  float pos;
} b4_serv_robot_interface__action__Monitor_Feedback;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_Feedback.
typedef struct b4_serv_robot_interface__action__Monitor_Feedback__Sequence
{
  b4_serv_robot_interface__action__Monitor_Feedback * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_Feedback__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'goal'
#include "b4_serv_robot_interface/action/detail/monitor__struct.h"

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_SendGoal_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
  b4_serv_robot_interface__action__Monitor_Goal goal;
} b4_serv_robot_interface__action__Monitor_SendGoal_Request;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_SendGoal_Request.
typedef struct b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence
{
  b4_serv_robot_interface__action__Monitor_SendGoal_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__struct.h"

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_SendGoal_Response
{
  bool accepted;
  builtin_interfaces__msg__Time stamp;
} b4_serv_robot_interface__action__Monitor_SendGoal_Response;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_SendGoal_Response.
typedef struct b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence
{
  b4_serv_robot_interface__action__Monitor_SendGoal_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_GetResult_Request
{
  unique_identifier_msgs__msg__UUID goal_id;
} b4_serv_robot_interface__action__Monitor_GetResult_Request;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_GetResult_Request.
typedef struct b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence
{
  b4_serv_robot_interface__action__Monitor_GetResult_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.h"

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_GetResult_Response
{
  int8_t status;
  b4_serv_robot_interface__action__Monitor_Result result;
} b4_serv_robot_interface__action__Monitor_GetResult_Response;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_GetResult_Response.
typedef struct b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence
{
  b4_serv_robot_interface__action__Monitor_GetResult_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__struct.h"
// Member 'feedback'
// already included above
// #include "b4_serv_robot_interface/action/detail/monitor__struct.h"

/// Struct defined in action/Monitor in the package b4_serv_robot_interface.
typedef struct b4_serv_robot_interface__action__Monitor_FeedbackMessage
{
  unique_identifier_msgs__msg__UUID goal_id;
  b4_serv_robot_interface__action__Monitor_Feedback feedback;
} b4_serv_robot_interface__action__Monitor_FeedbackMessage;

// Struct for a sequence of b4_serv_robot_interface__action__Monitor_FeedbackMessage.
typedef struct b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence
{
  b4_serv_robot_interface__action__Monitor_FeedbackMessage * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__STRUCT_H_
