// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from snuboat_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice
#include "snuboat_msgs/msg/detail/obstacles__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `label`
// Member `r`
// Member `phi`
// Member `x`
// Member `y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
snuboat_msgs__msg__Obstacles__init(snuboat_msgs__msg__Obstacles * msg)
{
  if (!msg) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__double__Sequence__init(&msg->label, 0)) {
    snuboat_msgs__msg__Obstacles__fini(msg);
    return false;
  }
  // r
  if (!rosidl_runtime_c__double__Sequence__init(&msg->r, 0)) {
    snuboat_msgs__msg__Obstacles__fini(msg);
    return false;
  }
  // phi
  if (!rosidl_runtime_c__double__Sequence__init(&msg->phi, 0)) {
    snuboat_msgs__msg__Obstacles__fini(msg);
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->x, 0)) {
    snuboat_msgs__msg__Obstacles__fini(msg);
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->y, 0)) {
    snuboat_msgs__msg__Obstacles__fini(msg);
    return false;
  }
  return true;
}

void
snuboat_msgs__msg__Obstacles__fini(snuboat_msgs__msg__Obstacles * msg)
{
  if (!msg) {
    return;
  }
  // label
  rosidl_runtime_c__double__Sequence__fini(&msg->label);
  // r
  rosidl_runtime_c__double__Sequence__fini(&msg->r);
  // phi
  rosidl_runtime_c__double__Sequence__fini(&msg->phi);
  // x
  rosidl_runtime_c__double__Sequence__fini(&msg->x);
  // y
  rosidl_runtime_c__double__Sequence__fini(&msg->y);
}

bool
snuboat_msgs__msg__Obstacles__are_equal(const snuboat_msgs__msg__Obstacles * lhs, const snuboat_msgs__msg__Obstacles * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->label), &(rhs->label)))
  {
    return false;
  }
  // r
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->r), &(rhs->r)))
  {
    return false;
  }
  // phi
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->phi), &(rhs->phi)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->x), &(rhs->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->y), &(rhs->y)))
  {
    return false;
  }
  return true;
}

bool
snuboat_msgs__msg__Obstacles__copy(
  const snuboat_msgs__msg__Obstacles * input,
  snuboat_msgs__msg__Obstacles * output)
{
  if (!input || !output) {
    return false;
  }
  // label
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->label), &(output->label)))
  {
    return false;
  }
  // r
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->r), &(output->r)))
  {
    return false;
  }
  // phi
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->phi), &(output->phi)))
  {
    return false;
  }
  // x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->x), &(output->x)))
  {
    return false;
  }
  // y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->y), &(output->y)))
  {
    return false;
  }
  return true;
}

snuboat_msgs__msg__Obstacles *
snuboat_msgs__msg__Obstacles__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  snuboat_msgs__msg__Obstacles * msg = (snuboat_msgs__msg__Obstacles *)allocator.allocate(sizeof(snuboat_msgs__msg__Obstacles), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(snuboat_msgs__msg__Obstacles));
  bool success = snuboat_msgs__msg__Obstacles__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
snuboat_msgs__msg__Obstacles__destroy(snuboat_msgs__msg__Obstacles * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    snuboat_msgs__msg__Obstacles__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
snuboat_msgs__msg__Obstacles__Sequence__init(snuboat_msgs__msg__Obstacles__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  snuboat_msgs__msg__Obstacles * data = NULL;

  if (size) {
    data = (snuboat_msgs__msg__Obstacles *)allocator.zero_allocate(size, sizeof(snuboat_msgs__msg__Obstacles), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = snuboat_msgs__msg__Obstacles__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        snuboat_msgs__msg__Obstacles__fini(&data[i - 1]);
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
snuboat_msgs__msg__Obstacles__Sequence__fini(snuboat_msgs__msg__Obstacles__Sequence * array)
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
      snuboat_msgs__msg__Obstacles__fini(&array->data[i]);
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

snuboat_msgs__msg__Obstacles__Sequence *
snuboat_msgs__msg__Obstacles__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  snuboat_msgs__msg__Obstacles__Sequence * array = (snuboat_msgs__msg__Obstacles__Sequence *)allocator.allocate(sizeof(snuboat_msgs__msg__Obstacles__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = snuboat_msgs__msg__Obstacles__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
snuboat_msgs__msg__Obstacles__Sequence__destroy(snuboat_msgs__msg__Obstacles__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    snuboat_msgs__msg__Obstacles__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
snuboat_msgs__msg__Obstacles__Sequence__are_equal(const snuboat_msgs__msg__Obstacles__Sequence * lhs, const snuboat_msgs__msg__Obstacles__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!snuboat_msgs__msg__Obstacles__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
snuboat_msgs__msg__Obstacles__Sequence__copy(
  const snuboat_msgs__msg__Obstacles__Sequence * input,
  snuboat_msgs__msg__Obstacles__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(snuboat_msgs__msg__Obstacles);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    snuboat_msgs__msg__Obstacles * data =
      (snuboat_msgs__msg__Obstacles *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!snuboat_msgs__msg__Obstacles__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          snuboat_msgs__msg__Obstacles__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!snuboat_msgs__msg__Obstacles__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
