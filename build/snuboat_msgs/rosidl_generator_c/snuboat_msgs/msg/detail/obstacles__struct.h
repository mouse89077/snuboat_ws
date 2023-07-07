// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from snuboat_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#ifndef SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_H_
#define SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'label'
// Member 'r'
// Member 'phi'
// Member 'x'
// Member 'y'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/Obstacles in the package snuboat_msgs.
typedef struct snuboat_msgs__msg__Obstacles
{
  rosidl_runtime_c__double__Sequence label;
  rosidl_runtime_c__double__Sequence r;
  rosidl_runtime_c__double__Sequence phi;
  rosidl_runtime_c__double__Sequence x;
  rosidl_runtime_c__double__Sequence y;
} snuboat_msgs__msg__Obstacles;

// Struct for a sequence of snuboat_msgs__msg__Obstacles.
typedef struct snuboat_msgs__msg__Obstacles__Sequence
{
  snuboat_msgs__msg__Obstacles * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} snuboat_msgs__msg__Obstacles__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // SNUBOAT_MSGS__MSG__DETAIL__OBSTACLES__STRUCT_H_
