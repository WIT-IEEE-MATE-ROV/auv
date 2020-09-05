// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from auv:msg/ThrusterMove.idl
// generated code does not contain a copyright notice
#include "auv/msg/detail/thruster_move__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
auv__msg__ThrusterMove__init(auv__msg__ThrusterMove * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    auv__msg__ThrusterMove__fini(msg);
    return false;
  }
  // top_front
  // top_back
  // top_left
  // top_right
  // front_left
  // front_right
  // back_left
  // back_right
  return true;
}

void
auv__msg__ThrusterMove__fini(auv__msg__ThrusterMove * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // top_front
  // top_back
  // top_left
  // top_right
  // front_left
  // front_right
  // back_left
  // back_right
}

auv__msg__ThrusterMove *
auv__msg__ThrusterMove__create()
{
  auv__msg__ThrusterMove * msg = (auv__msg__ThrusterMove *)malloc(sizeof(auv__msg__ThrusterMove));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(auv__msg__ThrusterMove));
  bool success = auv__msg__ThrusterMove__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
auv__msg__ThrusterMove__destroy(auv__msg__ThrusterMove * msg)
{
  if (msg) {
    auv__msg__ThrusterMove__fini(msg);
  }
  free(msg);
}


bool
auv__msg__ThrusterMove__Sequence__init(auv__msg__ThrusterMove__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  auv__msg__ThrusterMove * data = NULL;
  if (size) {
    data = (auv__msg__ThrusterMove *)calloc(size, sizeof(auv__msg__ThrusterMove));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = auv__msg__ThrusterMove__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        auv__msg__ThrusterMove__fini(&data[i - 1]);
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
auv__msg__ThrusterMove__Sequence__fini(auv__msg__ThrusterMove__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      auv__msg__ThrusterMove__fini(&array->data[i]);
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

auv__msg__ThrusterMove__Sequence *
auv__msg__ThrusterMove__Sequence__create(size_t size)
{
  auv__msg__ThrusterMove__Sequence * array = (auv__msg__ThrusterMove__Sequence *)malloc(sizeof(auv__msg__ThrusterMove__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = auv__msg__ThrusterMove__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
auv__msg__ThrusterMove__Sequence__destroy(auv__msg__ThrusterMove__Sequence * array)
{
  if (array) {
    auv__msg__ThrusterMove__Sequence__fini(array);
  }
  free(array);
}
