// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from b4_serv_robot_interface:srv/Order.idl
// generated code does not contain a copyright notice

#ifndef B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__FUNCTIONS_H_
#define B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "b4_serv_robot_interface/msg/rosidl_generator_c__visibility_control.h"

#include "b4_serv_robot_interface/srv/detail/order__struct.h"

/// Initialize srv/Order message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__srv__Order_Request
 * )) before or use
 * b4_serv_robot_interface__srv__Order_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Request__init(b4_serv_robot_interface__srv__Order_Request * msg);

/// Finalize srv/Order message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Request__fini(b4_serv_robot_interface__srv__Order_Request * msg);

/// Create srv/Order message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__srv__Order_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__srv__Order_Request *
b4_serv_robot_interface__srv__Order_Request__create();

/// Destroy srv/Order message.
/**
 * It calls
 * b4_serv_robot_interface__srv__Order_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Request__destroy(b4_serv_robot_interface__srv__Order_Request * msg);

/// Check for srv/Order message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Request__are_equal(const b4_serv_robot_interface__srv__Order_Request * lhs, const b4_serv_robot_interface__srv__Order_Request * rhs);

/// Copy a srv/Order message.
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
b4_serv_robot_interface__srv__Order_Request__copy(
  const b4_serv_robot_interface__srv__Order_Request * input,
  b4_serv_robot_interface__srv__Order_Request * output);

/// Initialize array of srv/Order messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__srv__Order_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Request__Sequence__init(b4_serv_robot_interface__srv__Order_Request__Sequence * array, size_t size);

/// Finalize array of srv/Order messages.
/**
 * It calls
 * b4_serv_robot_interface__srv__Order_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Request__Sequence__fini(b4_serv_robot_interface__srv__Order_Request__Sequence * array);

/// Create array of srv/Order messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__srv__Order_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__srv__Order_Request__Sequence *
b4_serv_robot_interface__srv__Order_Request__Sequence__create(size_t size);

/// Destroy array of srv/Order messages.
/**
 * It calls
 * b4_serv_robot_interface__srv__Order_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Request__Sequence__destroy(b4_serv_robot_interface__srv__Order_Request__Sequence * array);

/// Check for srv/Order message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Request__Sequence__are_equal(const b4_serv_robot_interface__srv__Order_Request__Sequence * lhs, const b4_serv_robot_interface__srv__Order_Request__Sequence * rhs);

/// Copy an array of srv/Order messages.
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
b4_serv_robot_interface__srv__Order_Request__Sequence__copy(
  const b4_serv_robot_interface__srv__Order_Request__Sequence * input,
  b4_serv_robot_interface__srv__Order_Request__Sequence * output);

/// Initialize srv/Order message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * b4_serv_robot_interface__srv__Order_Response
 * )) before or use
 * b4_serv_robot_interface__srv__Order_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Response__init(b4_serv_robot_interface__srv__Order_Response * msg);

/// Finalize srv/Order message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Response__fini(b4_serv_robot_interface__srv__Order_Response * msg);

/// Create srv/Order message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * b4_serv_robot_interface__srv__Order_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__srv__Order_Response *
b4_serv_robot_interface__srv__Order_Response__create();

/// Destroy srv/Order message.
/**
 * It calls
 * b4_serv_robot_interface__srv__Order_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Response__destroy(b4_serv_robot_interface__srv__Order_Response * msg);

/// Check for srv/Order message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Response__are_equal(const b4_serv_robot_interface__srv__Order_Response * lhs, const b4_serv_robot_interface__srv__Order_Response * rhs);

/// Copy a srv/Order message.
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
b4_serv_robot_interface__srv__Order_Response__copy(
  const b4_serv_robot_interface__srv__Order_Response * input,
  b4_serv_robot_interface__srv__Order_Response * output);

/// Initialize array of srv/Order messages.
/**
 * It allocates the memory for the number of elements and calls
 * b4_serv_robot_interface__srv__Order_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Response__Sequence__init(b4_serv_robot_interface__srv__Order_Response__Sequence * array, size_t size);

/// Finalize array of srv/Order messages.
/**
 * It calls
 * b4_serv_robot_interface__srv__Order_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Response__Sequence__fini(b4_serv_robot_interface__srv__Order_Response__Sequence * array);

/// Create array of srv/Order messages.
/**
 * It allocates the memory for the array and calls
 * b4_serv_robot_interface__srv__Order_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
b4_serv_robot_interface__srv__Order_Response__Sequence *
b4_serv_robot_interface__srv__Order_Response__Sequence__create(size_t size);

/// Destroy array of srv/Order messages.
/**
 * It calls
 * b4_serv_robot_interface__srv__Order_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
void
b4_serv_robot_interface__srv__Order_Response__Sequence__destroy(b4_serv_robot_interface__srv__Order_Response__Sequence * array);

/// Check for srv/Order message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_b4_serv_robot_interface
bool
b4_serv_robot_interface__srv__Order_Response__Sequence__are_equal(const b4_serv_robot_interface__srv__Order_Response__Sequence * lhs, const b4_serv_robot_interface__srv__Order_Response__Sequence * rhs);

/// Copy an array of srv/Order messages.
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
b4_serv_robot_interface__srv__Order_Response__Sequence__copy(
  const b4_serv_robot_interface__srv__Order_Response__Sequence * input,
  b4_serv_robot_interface__srv__Order_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // B4_SERV_ROBOT_INTERFACE__SRV__DETAIL__ORDER__FUNCTIONS_H_
