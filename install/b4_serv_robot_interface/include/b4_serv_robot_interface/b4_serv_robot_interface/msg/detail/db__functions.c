// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from b4_serv_robot_interface:msg/DB.idl
// generated code does not contain a copyright notice
#include "b4_serv_robot_interface/msg/detail/db__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `order_info`
#include "rosidl_runtime_c/string_functions.h"

bool
b4_serv_robot_interface__msg__DB__init(b4_serv_robot_interface__msg__DB * msg)
{
  if (!msg) {
    return false;
  }
  // order_info
  if (!rosidl_runtime_c__String__Sequence__init(&msg->order_info, 0)) {
    b4_serv_robot_interface__msg__DB__fini(msg);
    return false;
  }
  return true;
}

void
b4_serv_robot_interface__msg__DB__fini(b4_serv_robot_interface__msg__DB * msg)
{
  if (!msg) {
    return;
  }
  // order_info
  rosidl_runtime_c__String__Sequence__fini(&msg->order_info);
}

bool
b4_serv_robot_interface__msg__DB__are_equal(const b4_serv_robot_interface__msg__DB * lhs, const b4_serv_robot_interface__msg__DB * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // order_info
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->order_info), &(rhs->order_info)))
  {
    return false;
  }
  return true;
}

bool
b4_serv_robot_interface__msg__DB__copy(
  const b4_serv_robot_interface__msg__DB * input,
  b4_serv_robot_interface__msg__DB * output)
{
  if (!input || !output) {
    return false;
  }
  // order_info
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->order_info), &(output->order_info)))
  {
    return false;
  }
  return true;
}

b4_serv_robot_interface__msg__DB *
b4_serv_robot_interface__msg__DB__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__msg__DB * msg = (b4_serv_robot_interface__msg__DB *)allocator.allocate(sizeof(b4_serv_robot_interface__msg__DB), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(b4_serv_robot_interface__msg__DB));
  bool success = b4_serv_robot_interface__msg__DB__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
b4_serv_robot_interface__msg__DB__destroy(b4_serv_robot_interface__msg__DB * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    b4_serv_robot_interface__msg__DB__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
b4_serv_robot_interface__msg__DB__Sequence__init(b4_serv_robot_interface__msg__DB__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__msg__DB * data = NULL;

  if (size) {
    data = (b4_serv_robot_interface__msg__DB *)allocator.zero_allocate(size, sizeof(b4_serv_robot_interface__msg__DB), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = b4_serv_robot_interface__msg__DB__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        b4_serv_robot_interface__msg__DB__fini(&data[i - 1]);
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
b4_serv_robot_interface__msg__DB__Sequence__fini(b4_serv_robot_interface__msg__DB__Sequence * array)
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
      b4_serv_robot_interface__msg__DB__fini(&array->data[i]);
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

b4_serv_robot_interface__msg__DB__Sequence *
b4_serv_robot_interface__msg__DB__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  b4_serv_robot_interface__msg__DB__Sequence * array = (b4_serv_robot_interface__msg__DB__Sequence *)allocator.allocate(sizeof(b4_serv_robot_interface__msg__DB__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = b4_serv_robot_interface__msg__DB__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
b4_serv_robot_interface__msg__DB__Sequence__destroy(b4_serv_robot_interface__msg__DB__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    b4_serv_robot_interface__msg__DB__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
b4_serv_robot_interface__msg__DB__Sequence__are_equal(const b4_serv_robot_interface__msg__DB__Sequence * lhs, const b4_serv_robot_interface__msg__DB__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!b4_serv_robot_interface__msg__DB__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
b4_serv_robot_interface__msg__DB__Sequence__copy(
  const b4_serv_robot_interface__msg__DB__Sequence * input,
  b4_serv_robot_interface__msg__DB__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(b4_serv_robot_interface__msg__DB);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    b4_serv_robot_interface__msg__DB * data =
      (b4_serv_robot_interface__msg__DB *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!b4_serv_robot_interface__msg__DB__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          b4_serv_robot_interface__msg__DB__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!b4_serv_robot_interface__msg__DB__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
