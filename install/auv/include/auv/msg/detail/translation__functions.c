// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auv:msg/Translation.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/translation__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
auv__msg__Translation__init(auv__msg__Translation * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    auv__msg__Translation__fini(msg);
    return false;
  }
  // x
  // y
  // z
  return true;
}

void
auv__msg__Translation__fini(auv__msg__Translation * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // x
  // y
  // z
}

auv__msg__Translation *
auv__msg__Translation__create()
{
  auv__msg__Translation * msg = (auv__msg__Translation *)malloc(sizeof(auv__msg__Translation));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auv__msg__Translation));
  bool success = auv__msg__Translation__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
auv__msg__Translation__destroy(auv__msg__Translation * msg)
{
  if (msg) {
    auv__msg__Translation__fini(msg);
  }
  free(msg);
}


bool
auv__msg__Translation__Sequence__init(auv__msg__Translation__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  auv__msg__Translation * data = NULL;
  if (size) {
    data = (auv__msg__Translation *)calloc(size, sizeof(auv__msg__Translation));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auv__msg__Translation__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auv__msg__Translation__fini(&data[i - 1]);
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
auv__msg__Translation__Sequence__fini(auv__msg__Translation__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auv__msg__Translation__fini(&array->data[i]);
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

auv__msg__Translation__Sequence *
auv__msg__Translation__Sequence__create(size_t size)
{
  auv__msg__Translation__Sequence * array = (auv__msg__Translation__Sequence *)malloc(sizeof(auv__msg__Translation__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = auv__msg__Translation__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
auv__msg__Translation__Sequence__destroy(auv__msg__Translation__Sequence * array)
{
  if (array) {
    auv__msg__Translation__Sequence__fini(array);
  }
  free(array);
}
