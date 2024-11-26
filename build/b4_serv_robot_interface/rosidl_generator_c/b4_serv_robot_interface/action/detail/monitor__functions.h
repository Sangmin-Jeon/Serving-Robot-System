// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from b4_serv_robot_interface:action/Monitor.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__FUNCTIONS_H_
#define B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "b4_serv_robot_interface/msg/rosidl_generator_c__visibility_control.h"

#include "b4_serv_robot_interface/action/detail/monitor__struct.h"

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_Goal
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Goal__init(b4_serv_robot_interface__action__Monitor_Goal * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Goal__fini(b4_serv_robot_interface__action__Monitor_Goal * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_Goal *
b4_serv_robot_interface__action__Monitor_Goal__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Goal__destroy(b4_serv_robot_interface__action__Monitor_Goal * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Goal__are_equal(const b4_serv_robot_interface__action__Monitor_Goal * lhs, const b4_serv_robot_interface__action__Monitor_Goal * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Goal__copy(
  const b4_serv_robot_interface__action__Monitor_Goal * input,
  b4_serv_robot_interface__action__Monitor_Goal * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Goal__Sequence__init(b4_serv_robot_interface__action__Monitor_Goal__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Goal__Sequence__fini(b4_serv_robot_interface__action__Monitor_Goal__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_Goal__Sequence *
b4_serv_robot_interface__action__Monitor_Goal__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Goal__Sequence__destroy(b4_serv_robot_interface__action__Monitor_Goal__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Goal__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_Goal__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_Goal__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Goal__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_Goal__Sequence * input,
  b4_serv_robot_interface__action__Monitor_Goal__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_Result
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Result__init(b4_serv_robot_interface__action__Monitor_Result * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Result__fini(b4_serv_robot_interface__action__Monitor_Result * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_Result *
b4_serv_robot_interface__action__Monitor_Result__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Result__destroy(b4_serv_robot_interface__action__Monitor_Result * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Result__are_equal(const b4_serv_robot_interface__action__Monitor_Result * lhs, const b4_serv_robot_interface__action__Monitor_Result * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Result__copy(
  const b4_serv_robot_interface__action__Monitor_Result * input,
  b4_serv_robot_interface__action__Monitor_Result * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Result__Sequence__init(b4_serv_robot_interface__action__Monitor_Result__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Result__Sequence__fini(b4_serv_robot_interface__action__Monitor_Result__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_Result__Sequence *
b4_serv_robot_interface__action__Monitor_Result__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Result__Sequence__destroy(b4_serv_robot_interface__action__Monitor_Result__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Result__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_Result__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_Result__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Result__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_Result__Sequence * input,
  b4_serv_robot_interface__action__Monitor_Result__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_Feedback
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Feedback__init(b4_serv_robot_interface__action__Monitor_Feedback * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Feedback__fini(b4_serv_robot_interface__action__Monitor_Feedback * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_Feedback *
b4_serv_robot_interface__action__Monitor_Feedback__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Feedback__destroy(b4_serv_robot_interface__action__Monitor_Feedback * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Feedback__are_equal(const b4_serv_robot_interface__action__Monitor_Feedback * lhs, const b4_serv_robot_interface__action__Monitor_Feedback * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Feedback__copy(
  const b4_serv_robot_interface__action__Monitor_Feedback * input,
  b4_serv_robot_interface__action__Monitor_Feedback * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Feedback__Sequence__init(b4_serv_robot_interface__action__Monitor_Feedback__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Feedback__Sequence__fini(b4_serv_robot_interface__action__Monitor_Feedback__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_Feedback__Sequence *
b4_serv_robot_interface__action__Monitor_Feedback__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_Feedback__Sequence__destroy(b4_serv_robot_interface__action__Monitor_Feedback__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Feedback__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_Feedback__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_Feedback__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_Feedback__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_Feedback__Sequence * input,
  b4_serv_robot_interface__action__Monitor_Feedback__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Request__init(b4_serv_robot_interface__action__Monitor_SendGoal_Request * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Request__fini(b4_serv_robot_interface__action__Monitor_SendGoal_Request * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_SendGoal_Request *
b4_serv_robot_interface__action__Monitor_SendGoal_Request__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Request__destroy(b4_serv_robot_interface__action__Monitor_SendGoal_Request * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Request__are_equal(const b4_serv_robot_interface__action__Monitor_SendGoal_Request * lhs, const b4_serv_robot_interface__action__Monitor_SendGoal_Request * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Request__copy(
  const b4_serv_robot_interface__action__Monitor_SendGoal_Request * input,
  b4_serv_robot_interface__action__Monitor_SendGoal_Request * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__init(b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__fini(b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence *
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__destroy(b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * input,
  b4_serv_robot_interface__action__Monitor_SendGoal_Request__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Response__init(b4_serv_robot_interface__action__Monitor_SendGoal_Response * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Response__fini(b4_serv_robot_interface__action__Monitor_SendGoal_Response * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_SendGoal_Response *
b4_serv_robot_interface__action__Monitor_SendGoal_Response__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Response__destroy(b4_serv_robot_interface__action__Monitor_SendGoal_Response * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Response__are_equal(const b4_serv_robot_interface__action__Monitor_SendGoal_Response * lhs, const b4_serv_robot_interface__action__Monitor_SendGoal_Response * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Response__copy(
  const b4_serv_robot_interface__action__Monitor_SendGoal_Response * input,
  b4_serv_robot_interface__action__Monitor_SendGoal_Response * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__init(b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__fini(b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence *
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__destroy(b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * input,
  b4_serv_robot_interface__action__Monitor_SendGoal_Response__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_GetResult_Request
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Request__init(b4_serv_robot_interface__action__Monitor_GetResult_Request * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Request__fini(b4_serv_robot_interface__action__Monitor_GetResult_Request * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_GetResult_Request *
b4_serv_robot_interface__action__Monitor_GetResult_Request__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Request__destroy(b4_serv_robot_interface__action__Monitor_GetResult_Request * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Request__are_equal(const b4_serv_robot_interface__action__Monitor_GetResult_Request * lhs, const b4_serv_robot_interface__action__Monitor_GetResult_Request * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Request__copy(
  const b4_serv_robot_interface__action__Monitor_GetResult_Request * input,
  b4_serv_robot_interface__action__Monitor_GetResult_Request * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__init(b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__fini(b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence *
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__destroy(b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * input,
  b4_serv_robot_interface__action__Monitor_GetResult_Request__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_GetResult_Response
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Response__init(b4_serv_robot_interface__action__Monitor_GetResult_Response * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Response__fini(b4_serv_robot_interface__action__Monitor_GetResult_Response * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_GetResult_Response *
b4_serv_robot_interface__action__Monitor_GetResult_Response__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Response__destroy(b4_serv_robot_interface__action__Monitor_GetResult_Response * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Response__are_equal(const b4_serv_robot_interface__action__Monitor_GetResult_Response * lhs, const b4_serv_robot_interface__action__Monitor_GetResult_Response * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Response__copy(
  const b4_serv_robot_interface__action__Monitor_GetResult_Response * input,
  b4_serv_robot_interface__action__Monitor_GetResult_Response * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__init(b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__fini(b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence *
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__destroy(b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * input,
  b4_serv_robot_interface__action__Monitor_GetResult_Response__Sequence * output);

/// Initialize action/Monitor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage
 * )) before or use
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_FeedbackMessage__init(b4_serv_robot_interface__action__Monitor_FeedbackMessage * msg);

/// Finalize action/Monitor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_FeedbackMessage__fini(b4_serv_robot_interface__action__Monitor_FeedbackMessage * msg);

/// Create action/Monitor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_FeedbackMessage *
b4_serv_robot_interface__action__Monitor_FeedbackMessage__create();

/// Destroy action/Monitor message.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_FeedbackMessage__destroy(b4_serv_robot_interface__action__Monitor_FeedbackMessage * msg);

/// Check for action/Monitor message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_FeedbackMessage__are_equal(const b4_serv_robot_interface__action__Monitor_FeedbackMessage * lhs, const b4_serv_robot_interface__action__Monitor_FeedbackMessage * rhs);

/// Copy a action/Monitor message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_FeedbackMessage__copy(
  const b4_serv_robot_interface__action__Monitor_FeedbackMessage * input,
  b4_serv_robot_interface__action__Monitor_FeedbackMessage * output);

/// Initialize array of action/Monitor messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__init(b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__fini(b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * array);

/// Create array of action/Monitor messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence *
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/Monitor messages.
/**
 * It calls
 * b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__destroy(b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * array);

/// Check for action/Monitor message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__are_equal(const b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * lhs, const b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/Monitor messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence__copy(
  const b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * input,
  b4_serv_robot_interface__action__Monitor_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // B4_SERV_ROBOT_INTERFACE__ACTION__DETAIL__MONITOR__FUNCTIONS_H_
