// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#ifndef STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "stamp_markerarray/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "stamp_markerarray/msg/detail/stamped_marker_array__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace stamp_markerarray
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stamp_markerarray
cdr_serialize(
  const stamp_markerarray::msg::StampedMarkerArray & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stamp_markerarray
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  stamp_markerarray::msg::StampedMarkerArray & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stamp_markerarray
get_serialized_size(
  const stamp_markerarray::msg::StampedMarkerArray & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stamp_markerarray
max_serialized_size_StampedMarkerArray(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace stamp_markerarray

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_stamp_markerarray
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, stamp_markerarray, msg, StampedMarkerArray)();

#ifdef __cplusplus
}
#endif

#endif  // STAMP_MARKERARRAY__MSG__DETAIL__STAMPED_MARKER_ARRAY__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
