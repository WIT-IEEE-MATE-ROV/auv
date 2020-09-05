// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from auv:msg/SurfaceCommand.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__SURFACE_COMMAND__FUNCTIONS_H_
#define AUV__MSG__DETAIL__SURFACE_COMMAND__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "auv/msg/rosidl_generator_c__visibility_control.h"

#include "auv/msg/detail/surface_command__struct.h"

/// Initialize msg/SurfaceCommand message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auv__msg__SurfaceCommand
 * )) before or use
 * auv__msg__SurfaceCommand__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
bool
auv__msg__SurfaceCommand__init(auv__msg__SurfaceCommand * msg);

/// Finalize msg/SurfaceCommand message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__SurfaceCommand__fini(auv__msg__SurfaceCommand * msg);

/// Create msg/SurfaceCommand message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auv__msg__SurfaceCommand__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
auv__msg__SurfaceCommand *
auv__msg__SurfaceCommand__create();

/// Destroy msg/SurfaceCommand message.
/**
 * It calls
 * auv__msg__SurfaceCommand__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__SurfaceCommand__destroy(auv__msg__SurfaceCommand * msg);


/// Initialize array of msg/SurfaceCommand messages.
/**
 * It allocates the memory for the number of elements and calls
 * auv__msg__SurfaceCommand__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
bool
auv__msg__SurfaceCommand__Sequence__init(auv__msg__SurfaceCommand__Sequence * array, size_t size);

/// Finalize array of msg/SurfaceCommand messages.
/**
 * It calls
 * auv__msg__SurfaceCommand__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__SurfaceCommand__Sequence__fini(auv__msg__SurfaceCommand__Sequence * array);

/// Create array of msg/SurfaceCommand messages.
/**
 * It allocates the memory for the array and calls
 * auv__msg__SurfaceCommand__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
auv__msg__SurfaceCommand__Sequence *
auv__msg__SurfaceCommand__Sequence__create(size_t size);

/// Destroy array of msg/SurfaceCommand messages.
/**
 * It calls
 * auv__msg__SurfaceCommand__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__SurfaceCommand__Sequence__destroy(auv__msg__SurfaceCommand__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__SURFACE_COMMAND__FUNCTIONS_H_
