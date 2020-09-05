// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from auv:msg/ThrusterSensor.idl
// generated code does not contain a copyright notice

#ifndef AUV__MSG__DETAIL__THRUSTER_SENSOR__FUNCTIONS_H_
#define AUV__MSG__DETAIL__THRUSTER_SENSOR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "auv/msg/rosidl_generator_c__visibility_control.h"

#include "auv/msg/detail/thruster_sensor__struct.h"

/// Initialize msg/ThrusterSensor message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * auv__msg__ThrusterSensor
 * )) before or use
 * auv__msg__ThrusterSensor__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
bool
auv__msg__ThrusterSensor__init(auv__msg__ThrusterSensor * msg);

/// Finalize msg/ThrusterSensor message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__ThrusterSensor__fini(auv__msg__ThrusterSensor * msg);

/// Create msg/ThrusterSensor message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * auv__msg__ThrusterSensor__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
auv__msg__ThrusterSensor *
auv__msg__ThrusterSensor__create();

/// Destroy msg/ThrusterSensor message.
/**
 * It calls
 * auv__msg__ThrusterSensor__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__ThrusterSensor__destroy(auv__msg__ThrusterSensor * msg);


/// Initialize array of msg/ThrusterSensor messages.
/**
 * It allocates the memory for the number of elements and calls
 * auv__msg__ThrusterSensor__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
bool
auv__msg__ThrusterSensor__Sequence__init(auv__msg__ThrusterSensor__Sequence * array, size_t size);

/// Finalize array of msg/ThrusterSensor messages.
/**
 * It calls
 * auv__msg__ThrusterSensor__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__ThrusterSensor__Sequence__fini(auv__msg__ThrusterSensor__Sequence * array);

/// Create array of msg/ThrusterSensor messages.
/**
 * It allocates the memory for the array and calls
 * auv__msg__ThrusterSensor__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
auv__msg__ThrusterSensor__Sequence *
auv__msg__ThrusterSensor__Sequence__create(size_t size);

/// Destroy array of msg/ThrusterSensor messages.
/**
 * It calls
 * auv__msg__ThrusterSensor__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_auv
void
auv__msg__ThrusterSensor__Sequence__destroy(auv__msg__ThrusterSensor__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // AUV__MSG__DETAIL__THRUSTER_SENSOR__FUNCTIONS_H_
