// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auv:msg/Ninedof.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/ninedof__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `translation`
#include "auv/msg/detail/translation__functions.h"
// Member `orientation`
#include "auv/msg/detail/orientation__functions.h"

bool
auv__msg__Ninedof__init(auv__msg__Ninedof * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    auv__msg__Ninedof__fini(msg);
    return false;
  }
  // translation
  if (!auv__msg__Translation__init(&msg->translation)) {
    auv__msg__Ninedof__fini(msg);
    return false;
  }
  // orientation
  if (!auv__msg__Orientation__init(&msg->orientation)) {
    auv__msg__Ninedof__fini(msg);
    return false;
  }
  return true;
}

void
auv__msg__Ninedof__fini(auv__msg__Ninedof * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // translation
  auv__msg__Translation__fini(&msg->translation);
  // orientation
  auv__msg__Orientation__fini(&msg->orientation);
}

auv__msg__Ninedof *
auv__msg__Ninedof__create()
{
  auv__msg__Ninedof * msg = (auv__msg__Ninedof *)malloc(sizeof(auv__msg__Ninedof));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auv__msg__Ninedof));
  bool success = auv__msg__Ninedof__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
auv__msg__Ninedof__destroy(auv__msg__Ninedof * msg)
{
  if (msg) {
    auv__msg__Ninedof__fini(msg);
  }
  free(msg);
}


bool
auv__msg__Ninedof__Sequence__init(auv__msg__Ninedof__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  auv__msg__Ninedof * data = NULL;
  if (size) {
    data = (auv__msg__Ninedof *)calloc(size, sizeof(auv__msg__Ninedof));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auv__msg__Ninedof__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auv__msg__Ninedof__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
auv__msg__Ninedof__Sequence__fini(auv__msg__Ninedof__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auv__msg__Ninedof__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

auv__msg__Ninedof__Sequence *
auv__msg__Ninedof__Sequence__create(size_t size)
{
  auv__msg__Ninedof__Sequence * array = (auv__msg__Ninedof__Sequence *)malloc(sizeof(auv__msg__Ninedof__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = auv__msg__Ninedof__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
auv__msg__Ninedof__Sequence__destroy(auv__msg__Ninedof__Sequence * array)
{
  if (array) {
    auv__msg__Ninedof__Sequence__fini(array);
  }
  free(array);
}
