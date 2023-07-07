// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from snuboat_msgs:msg/Obstacles.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "snuboat_msgs/msg/detail/obstacles__rosidl_typesupport_introspection_c.h"
#include "snuboat_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "snuboat_msgs/msg/detail/obstacles__functions.h"
#include "snuboat_msgs/msg/detail/obstacles__struct.h"


// Include directives for member types
// Member `label`
// Member `r`
// Member `phi`
// Member `x`
// Member `y`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  snuboat_msgs__msg__Obstacles__init(message_memory);
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_fini_function(void * message_memory)
{
  snuboat_msgs__msg__Obstacles__fini(message_memory);
}

size_t snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__label(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__label(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__label(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__label(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__label(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__label(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__label(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__label(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__r(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__r(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__r(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__r(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__r(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__r(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__r(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__r(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__phi(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__phi(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__phi(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__phi(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__phi(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__phi(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__phi(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__phi(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__x(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__x(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__x(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__y(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__y(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__y(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array[5] = {
  {
    "label",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(snuboat_msgs__msg__Obstacles, label),  // bytes offset in struct
    NULL,  // default value
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__label,  // size() function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__label,  // get_const(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__label,  // get(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__label,  // fetch(index, &value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__label,  // assign(index, value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__label  // resize(index) function pointer
  },
  {
    "r",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(snuboat_msgs__msg__Obstacles, r),  // bytes offset in struct
    NULL,  // default value
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__r,  // size() function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__r,  // get_const(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__r,  // get(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__r,  // fetch(index, &value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__r,  // assign(index, value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__r  // resize(index) function pointer
  },
  {
    "phi",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(snuboat_msgs__msg__Obstacles, phi),  // bytes offset in struct
    NULL,  // default value
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__phi,  // size() function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__phi,  // get_const(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__phi,  // get(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__phi,  // fetch(index, &value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__phi,  // assign(index, value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__phi  // resize(index) function pointer
  },
  {
    "x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(snuboat_msgs__msg__Obstacles, x),  // bytes offset in struct
    NULL,  // default value
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__x,  // size() function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__x,  // get_const(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__x,  // get(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__x,  // fetch(index, &value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__x,  // assign(index, value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__x  // resize(index) function pointer
  },
  {
    "y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(snuboat_msgs__msg__Obstacles, y),  // bytes offset in struct
    NULL,  // default value
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__size_function__Obstacles__y,  // size() function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_const_function__Obstacles__y,  // get_const(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__get_function__Obstacles__y,  // get(index) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__fetch_function__Obstacles__y,  // fetch(index, &value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__assign_function__Obstacles__y,  // assign(index, value) function pointer
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__resize_function__Obstacles__y  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_members = {
  "snuboat_msgs__msg",  // message namespace
  "Obstacles",  // message name
  5,  // number of fields
  sizeof(snuboat_msgs__msg__Obstacles),
  snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_member_array,  // message members
  snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_init_function,  // function to initialize message memory (memory has to be allocated)
  snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle = {
  0,
  &snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_snuboat_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, snuboat_msgs, msg, Obstacles)() {
  if (!snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle.typesupport_identifier) {
    snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &snuboat_msgs__msg__Obstacles__rosidl_typesupport_introspection_c__Obstacles_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
