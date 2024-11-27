// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from b4_serv_robot_interface:srv/Order.idl
// generated code does not contain a copyright notice
#include "b4_serv_robot_interface/srv/detail/order__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `table_num`
// Member `order_info`
// Member `order_time`
#include "rosidl_runtime_c/string_functions.h"

bool
b4_serv_robot_interface__srv__Order_Request__init(b4_serv_robot_interface__srv__Order_Request * msg)
{
  if (!msg) {
    return false;
  }
  // table_num
  if (!rosidl_runtime_c__String__init(&msg->table_num)) {
    b4_serv_robot_interface__srv__Order_Request__fini(msg);
    return false;
  }
  // order_info
  if (!rosidl_runtime_c__String__Sequence__init(&msg->order_info, 0)) {
    b4_serv_robot_interface__srv__Order_Request__fini(msg);
    return false;
  }
  // order_time
  if (!rosidl_runtime_c__String__init(&msg->order_time)) {
    b4_serv_robot_interface__srv__Order_Request__fini(msg);
    return false;
  }
  return true;
}

void
b4_serv_robot_interface__srv__Order_Request__fini(b4_serv_robot_interface__srv__Order_Request * msg)
{
  if (!msg) {
    return;
  }
  // table_num
  rosidl_runtime_c__String__fini(&msg->table_num);
  // order_info
  rosidl_runtime_c__String__Sequence__fini(&msg->order_info);
  // order_time
  rosidl_runtime_c__String__fini(&msg->order_time);
}

bool
b4_serv_robot_interface__srv__Order_Request__are_equal(const b4_serv_robot_interface__srv__Order_Request * lhs, const b4_serv_robot_interface__srv__Order_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // table_num
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->table_num), &(rhs->table_num)))
  {
    return false;
  }
  // order_info
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->order_info), &(rhs->order_info)))
  {
    return false;
  }
  // order_time
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->order_time), &(rhs->order_time)))
  {
    return false;
  }
  return true;
}

bool
b4_serv_robot_interface__srv__Order_Request__copy(
  const b4_serv_robot_interface__srv__Order_Request * input,
  b4_serv_robot_interface__srv__Order_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // table_num
  if (!rosidl_runtime_c__String__copy(
      &(input->table_num), &(output->table_num)))
  {
    return false;
  }
  // order_info
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->order_info), &(output->order_info)))
  {
    return false;
  }
  // order_time
  if (!rosidl_runtime_c__String__copy(
      &(input->order_time), &(output->order_time)))
  {
    return false;
  }
  return true;
}

b4_serv_robot_interface__srv__Order_Request *
b4_serv_robot_interface__srv__Order_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__srv__Order_Request * msg = (b4_serv_robot_interface__srv__Order_Request *)allocator.allocate(sizeof(b4_serv_robot_interface__srv__Order_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(b4_serv_robot_interface__srv__Order_Request));
  bool success = b4_serv_robot_interface__srv__Order_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
b4_serv_robot_interface__srv__Order_Request__destroy(b4_serv_robot_interface__srv__Order_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    b4_serv_robot_interface__srv__Order_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
b4_serv_robot_interface__srv__Order_Request__Sequence__init(b4_serv_robot_interface__srv__Order_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__srv__Order_Request * data = NULL;

  if (size) {
    data = (b4_serv_robot_interface__srv__Order_Request *)allocator.zero_allocate(size, sizeof(b4_serv_robot_interface__srv__Order_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = b4_serv_robot_interface__srv__Order_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        b4_serv_robot_interface__srv__Order_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
b4_serv_robot_interface__srv__Order_Request__Sequence__fini(b4_serv_robot_interface__srv__Order_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      b4_serv_robot_interface__srv__Order_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

b4_serv_robot_interface__srv__Order_Request__Sequence *
b4_serv_robot_interface__srv__Order_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__srv__Order_Request__Sequence * array = (b4_serv_robot_interface__srv__Order_Request__Sequence *)allocator.allocate(sizeof(b4_serv_robot_interface__srv__Order_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = b4_serv_robot_interface__srv__Order_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
b4_serv_robot_interface__srv__Order_Request__Sequence__destroy(b4_serv_robot_interface__srv__Order_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    b4_serv_robot_interface__srv__Order_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
b4_serv_robot_interface__srv__Order_Request__Sequence__are_equal(const b4_serv_robot_interface__srv__Order_Request__Sequence * lhs, const b4_serv_robot_interface__srv__Order_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!b4_serv_robot_interface__srv__Order_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
b4_serv_robot_interface__srv__Order_Request__Sequence__copy(
  const b4_serv_robot_interface__srv__Order_Request__Sequence * input,
  b4_serv_robot_interface__srv__Order_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(b4_serv_robot_interface__srv__Order_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    b4_serv_robot_interface__srv__Order_Request * data =
      (b4_serv_robot_interface__srv__Order_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!b4_serv_robot_interface__srv__Order_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          b4_serv_robot_interface__srv__Order_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!b4_serv_robot_interface__srv__Order_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
b4_serv_robot_interface__srv__Order_Response__init(b4_serv_robot_interface__srv__Order_Response * msg)
{
  if (!msg) {
    return false;
  }
  // is_order
  return true;
}

void
b4_serv_robot_interface__srv__Order_Response__fini(b4_serv_robot_interface__srv__Order_Response * msg)
{
  if (!msg) {
    return;
  }
  // is_order
}

bool
b4_serv_robot_interface__srv__Order_Response__are_equal(const b4_serv_robot_interface__srv__Order_Response * lhs, const b4_serv_robot_interface__srv__Order_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // is_order
  if (lhs->is_order != rhs->is_order) {
    return false;
  }
  return true;
}

bool
b4_serv_robot_interface__srv__Order_Response__copy(
  const b4_serv_robot_interface__srv__Order_Response * input,
  b4_serv_robot_interface__srv__Order_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // is_order
  output->is_order = input->is_order;
  return true;
}

b4_serv_robot_interface__srv__Order_Response *
b4_serv_robot_interface__srv__Order_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__srv__Order_Response * msg = (b4_serv_robot_interface__srv__Order_Response *)allocator.allocate(sizeof(b4_serv_robot_interface__srv__Order_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(b4_serv_robot_interface__srv__Order_Response));
  bool success = b4_serv_robot_interface__srv__Order_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
b4_serv_robot_interface__srv__Order_Response__destroy(b4_serv_robot_interface__srv__Order_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    b4_serv_robot_interface__srv__Order_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
b4_serv_robot_interface__srv__Order_Response__Sequence__init(b4_serv_robot_interface__srv__Order_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__srv__Order_Response * data = NULL;

  if (size) {
    data = (b4_serv_robot_interface__srv__Order_Response *)allocator.zero_allocate(size, sizeof(b4_serv_robot_interface__srv__Order_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = b4_serv_robot_interface__srv__Order_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        b4_serv_robot_interface__srv__Order_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
b4_serv_robot_interface__srv__Order_Response__Sequence__fini(b4_serv_robot_interface__srv__Order_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      b4_serv_robot_interface__srv__Order_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

b4_serv_robot_interface__srv__Order_Response__Sequence *
b4_serv_robot_interface__srv__Order_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__srv__Order_Response__Sequence * array = (b4_serv_robot_interface__srv__Order_Response__Sequence *)allocator.allocate(sizeof(b4_serv_robot_interface__srv__Order_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = b4_serv_robot_interface__srv__Order_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
b4_serv_robot_interface__srv__Order_Response__Sequence__destroy(b4_serv_robot_interface__srv__Order_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    b4_serv_robot_interface__srv__Order_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
b4_serv_robot_interface__srv__Order_Response__Sequence__are_equal(const b4_serv_robot_interface__srv__Order_Response__Sequence * lhs, const b4_serv_robot_interface__srv__Order_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!b4_serv_robot_interface__srv__Order_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
b4_serv_robot_interface__srv__Order_Response__Sequence__copy(
  const b4_serv_robot_interface__srv__Order_Response__Sequence * input,
  b4_serv_robot_interface__srv__Order_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(b4_serv_robot_interface__srv__Order_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    b4_serv_robot_interface__srv__Order_Response * data =
      (b4_serv_robot_interface__srv__Order_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!b4_serv_robot_interface__srv__Order_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          b4_serv_robot_interface__srv__Order_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!b4_serv_robot_interface__srv__Order_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
