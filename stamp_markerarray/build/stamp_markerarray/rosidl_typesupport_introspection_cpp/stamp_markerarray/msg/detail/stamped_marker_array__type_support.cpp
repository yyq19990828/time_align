// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "stamp_markerarray/msg/detail/stamped_marker_array__functions.h"
#include "stamp_markerarray/msg/detail/stamped_marker_array__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace stamp_markerarray
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void StampedMarkerArray_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) stamp_markerarray::msg::StampedMarkerArray(_init);
}

void StampedMarkerArray_fini_function(void * message_memory)
{
  auto typed_message = static_cast<stamp_markerarray::msg::StampedMarkerArray *>(message_memory);
  typed_message->~StampedMarkerArray();
}

size_t size_function__StampedMarkerArray__markers(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<visualization_msgs::msg::Marker> *>(untyped_member);
  return member->size();
}

const void * get_const_function__StampedMarkerArray__markers(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<visualization_msgs::msg::Marker> *>(untyped_member);
  return &member[index];
}

void * get_function__StampedMarkerArray__markers(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<visualization_msgs::msg::Marker> *>(untyped_member);
  return &member[index];
}

void fetch_function__StampedMarkerArray__markers(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const visualization_msgs::msg::Marker *>(
    get_const_function__StampedMarkerArray__markers(untyped_member, index));
  auto & value = *reinterpret_cast<visualization_msgs::msg::Marker *>(untyped_value);
  value = item;
}

void assign_function__StampedMarkerArray__markers(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<visualization_msgs::msg::Marker *>(
    get_function__StampedMarkerArray__markers(untyped_member, index));
  const auto & value = *reinterpret_cast<const visualization_msgs::msg::Marker *>(untyped_value);
  item = value;
}

void resize_function__StampedMarkerArray__markers(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<visualization_msgs::msg::Marker> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember StampedMarkerArray_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stamp_markerarray::msg::StampedMarkerArray, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "markers",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<visualization_msgs::msg::Marker>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(stamp_markerarray::msg::StampedMarkerArray, markers),  // bytes offset in struct
    nullptr,  // default value
    size_function__StampedMarkerArray__markers,  // size() function pointer
    get_const_function__StampedMarkerArray__markers,  // get_const(index) function pointer
    get_function__StampedMarkerArray__markers,  // get(index) function pointer
    fetch_function__StampedMarkerArray__markers,  // fetch(index, &value) function pointer
    assign_function__StampedMarkerArray__markers,  // assign(index, value) function pointer
    resize_function__StampedMarkerArray__markers  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers StampedMarkerArray_message_members = {
  "stamp_markerarray::msg",  // message namespace
  "StampedMarkerArray",  // message name
  2,  // number of fields
  sizeof(stamp_markerarray::msg::StampedMarkerArray),
  StampedMarkerArray_message_member_array,  // message members
  StampedMarkerArray_init_function,  // function to initialize message memory (memory has to be allocated)
  StampedMarkerArray_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t StampedMarkerArray_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &StampedMarkerArray_message_members,
  get_message_typesupport_handle_function,
  &stamp_markerarray__msg__StampedMarkerArray__get_type_hash,
  &stamp_markerarray__msg__StampedMarkerArray__get_type_description,
  &stamp_markerarray__msg__StampedMarkerArray__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace stamp_markerarray


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<stamp_markerarray::msg::StampedMarkerArray>()
{
  return &::stamp_markerarray::msg::rosidl_typesupport_introspection_cpp::StampedMarkerArray_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, stamp_markerarray, msg, StampedMarkerArray)() {
  return &::stamp_markerarray::msg::rosidl_typesupport_introspection_cpp::StampedMarkerArray_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
