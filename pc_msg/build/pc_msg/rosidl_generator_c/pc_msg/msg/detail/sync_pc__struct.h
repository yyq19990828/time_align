// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice

#ifndef PC_MSG__MSG__DETAIL__SYNC_PC__STRUCT_H_
#define PC_MSG__MSG__DETAIL__SYNC_PC__STRUCT_H_

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
// Member 'pointclouds'
#include "sensor_msgs/msg/detail/point_cloud2__struct.h"

/// Struct defined in msg/SyncPc in the package pc_msg.
typedef struct pc_msg__msg__SyncPc
{
  std_msgs__msg__Header header;
  sensor_msgs__msg__PointCloud2__Sequence pointclouds;
} pc_msg__msg__SyncPc;

// Struct for a sequence of pc_msg__msg__SyncPc.
typedef struct pc_msg__msg__SyncPc__Sequence
{
  pc_msg__msg__SyncPc * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pc_msg__msg__SyncPc__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PC_MSG__MSG__DETAIL__SYNC_PC__STRUCT_H_
