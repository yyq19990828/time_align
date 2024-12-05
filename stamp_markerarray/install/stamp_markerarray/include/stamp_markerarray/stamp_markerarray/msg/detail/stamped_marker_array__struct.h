// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#ifndef STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__STRUCT_H_
#define STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'markers'
#include "visualization_msgs/msg/detail/marker__struct.h"

/// Struct defined in msg/StampedMarkerArray in the package stamp_markerarray.
typedef struct stamp_markerarray__msg__StampedMarkerArray
{
  std_msgs__msg__Header header;
  visualization_msgs__msg__Marker__Sequence markers;
} stamp_markerarray__msg__StampedMarkerArray;

// Struct for a sequence of stamp_markerarray__msg__StampedMarkerArray.
typedef struct stamp_markerarray__msg__StampedMarkerArray__Sequence
{
  stamp_markerarray__msg__StampedMarkerArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} stamp_markerarray__msg__StampedMarkerArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__STRUCT_H_
