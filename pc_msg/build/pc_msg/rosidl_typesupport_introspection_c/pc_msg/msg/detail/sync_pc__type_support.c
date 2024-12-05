// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "pc_msg/msg/detail/sync_pc__rosidl_typesupport_introspection_c.h"
#include "pc_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "pc_msg/msg/detail/sync_pc__functions.h"
#include "pc_msg/msg/detail/sync_pc__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `pointclouds`
#include "sensor_msgs/msg/point_cloud2.h"
// Member `pointclouds`
#include "sensor_msgs/msg/detail/point_cloud2__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  pc_msg__msg__SyncPc__init(message_memory);
}

void pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_fini_function(void * message_memory)
{
  pc_msg__msg__SyncPc__fini(message_memory);
}

size_t pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__size_function__SyncPc__pointclouds(
  const void * untyped_member)
{
  const sensor_msgs__msg__PointCloud2__Sequence * member =
    (const sensor_msgs__msg__PointCloud2__Sequence *)(untyped_member);
  return member->size;
}

const void * pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__get_const_function__SyncPc__pointclouds(
  const void * untyped_member, size_t index)
{
  const sensor_msgs__msg__PointCloud2__Sequence * member =
    (const sensor_msgs__msg__PointCloud2__Sequence *)(untyped_member);
  return &member->data[index];
}

void * pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__get_function__SyncPc__pointclouds(
  void * untyped_member, size_t index)
{
  sensor_msgs__msg__PointCloud2__Sequence * member =
    (sensor_msgs__msg__PointCloud2__Sequence *)(untyped_member);
  return &member->data[index];
}

void pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__fetch_function__SyncPc__pointclouds(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const sensor_msgs__msg__PointCloud2 * item =
    ((const sensor_msgs__msg__PointCloud2 *)
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__get_const_function__SyncPc__pointclouds(untyped_member, index));
  sensor_msgs__msg__PointCloud2 * value =
    (sensor_msgs__msg__PointCloud2 *)(untyped_value);
  *value = *item;
}

void pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__assign_function__SyncPc__pointclouds(
  void * untyped_member, size_t index, const void * untyped_value)
{
  sensor_msgs__msg__PointCloud2 * item =
    ((sensor_msgs__msg__PointCloud2 *)
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__get_function__SyncPc__pointclouds(untyped_member, index));
  const sensor_msgs__msg__PointCloud2 * value =
    (const sensor_msgs__msg__PointCloud2 *)(untyped_value);
  *item = *value;
}

bool pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__resize_function__SyncPc__pointclouds(
  void * untyped_member, size_t size)
{
  sensor_msgs__msg__PointCloud2__Sequence * member =
    (sensor_msgs__msg__PointCloud2__Sequence *)(untyped_member);
  sensor_msgs__msg__PointCloud2__Sequence__fini(member);
  return sensor_msgs__msg__PointCloud2__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pc_msg__msg__SyncPc, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pointclouds",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pc_msg__msg__SyncPc, pointclouds),  // bytes offset in struct
    NULL,  // default value
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__size_function__SyncPc__pointclouds,  // size() function pointer
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__get_const_function__SyncPc__pointclouds,  // get_const(index) function pointer
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__get_function__SyncPc__pointclouds,  // get(index) function pointer
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__fetch_function__SyncPc__pointclouds,  // fetch(index, &value) function pointer
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__assign_function__SyncPc__pointclouds,  // assign(index, value) function pointer
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__resize_function__SyncPc__pointclouds  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_members = {
  "pc_msg__msg",  // message namespace
  "SyncPc",  // message name
  2,  // number of fields
  sizeof(pc_msg__msg__SyncPc),
  pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_member_array,  // message members
  pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_init_function,  // function to initialize message memory (memory has to be allocated)
  pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_type_support_handle = {
  0,
  &pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_members,
  get_message_typesupport_handle_function,
  &pc_msg__msg__SyncPc__get_type_hash,
  &pc_msg__msg__SyncPc__get_type_description,
  &pc_msg__msg__SyncPc__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_pc_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, pc_msg, msg, SyncPc)() {
  pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, PointCloud2)();
  if (!pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_type_support_handle.typesupport_identifier) {
    pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &pc_msg__msg__SyncPc__rosidl_typesupport_introspection_c__SyncPc_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
