// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "stamp_markerarray/msg/detail/stamped_marker_array__rosidl_typesupport_introspection_c.h"
#include "stamp_markerarray/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "stamp_markerarray/msg/detail/stamped_marker_array__functions.h"
#include "stamp_markerarray/msg/detail/stamped_marker_array__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"
// Member `markers`
#include "visualization_msgs/msg/marker.h"
// Member `markers`
#include "visualization_msgs/msg/detail/marker__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  stamp_markerarray__msg__StampedMarkerArray__init(message_memory);
}

void stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_fini_function(void * message_memory)
{
  stamp_markerarray__msg__StampedMarkerArray__fini(message_memory);
}

size_t stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__size_function__StampedMarkerArray__markers(
  const void * untyped_member)
{
  const visualization_msgs__msg__Marker__Sequence * member =
    (const visualization_msgs__msg__Marker__Sequence *)(untyped_member);
  return member->size;
}

const void * stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__get_const_function__StampedMarkerArray__markers(
  const void * untyped_member, size_t index)
{
  const visualization_msgs__msg__Marker__Sequence * member =
    (const visualization_msgs__msg__Marker__Sequence *)(untyped_member);
  return &member->data[index];
}

void * stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__get_function__StampedMarkerArray__markers(
  void * untyped_member, size_t index)
{
  visualization_msgs__msg__Marker__Sequence * member =
    (visualization_msgs__msg__Marker__Sequence *)(untyped_member);
  return &member->data[index];
}

void stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__fetch_function__StampedMarkerArray__markers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const visualization_msgs__msg__Marker * item =
    ((const visualization_msgs__msg__Marker *)
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__get_const_function__StampedMarkerArray__markers(untyped_member, index));
  visualization_msgs__msg__Marker * value =
    (visualization_msgs__msg__Marker *)(untyped_value);
  *value = *item;
}

void stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__assign_function__StampedMarkerArray__markers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  visualization_msgs__msg__Marker * item =
    ((visualization_msgs__msg__Marker *)
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__get_function__StampedMarkerArray__markers(untyped_member, index));
  const visualization_msgs__msg__Marker * value =
    (const visualization_msgs__msg__Marker *)(untyped_value);
  *item = *value;
}

bool stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__resize_function__StampedMarkerArray__markers(
  void * untyped_member, size_t size)
{
  visualization_msgs__msg__Marker__Sequence * member =
    (visualization_msgs__msg__Marker__Sequence *)(untyped_member);
  visualization_msgs__msg__Marker__Sequence__fini(member);
  return visualization_msgs__msg__Marker__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stamp_markerarray__msg__StampedMarkerArray, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "markers",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stamp_markerarray__msg__StampedMarkerArray, markers),  // bytes offset in struct
    NULL,  // default value
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__size_function__StampedMarkerArray__markers,  // size() function pointer
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__get_const_function__StampedMarkerArray__markers,  // get_const(index) function pointer
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__get_function__StampedMarkerArray__markers,  // get(index) function pointer
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__fetch_function__StampedMarkerArray__markers,  // fetch(index, &value) function pointer
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__assign_function__StampedMarkerArray__markers,  // assign(index, value) function pointer
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__resize_function__StampedMarkerArray__markers  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_members = {
  "stamp_markerarray__msg",  // message namespace
  "StampedMarkerArray",  // message name
  2,  // number of fields
  sizeof(stamp_markerarray__msg__StampedMarkerArray),
  stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_member_array,  // message members
  stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_init_function,  // function to initialize message memory (memory has to be allocated)
  stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_type_support_handle = {
  0,
  &stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_members,
  get_message_typesupport_handle_function,
  &stamp_markerarray__msg__StampedMarkerArray__get_type_hash,
  &stamp_markerarray__msg__StampedMarkerArray__get_type_description,
  &stamp_markerarray__msg__StampedMarkerArray__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_stamp_markerarray
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, stamp_markerarray, msg, StampedMarkerArray)() {
  stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, visualization_msgs, msg, Marker)();
  if (!stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_type_support_handle.typesupport_identifier) {
    stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &stamp_markerarray__msg__StampedMarkerArray__rosidl_typesupport_introspection_c__StampedMarkerArray_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
