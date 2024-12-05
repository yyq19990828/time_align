// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "pc_msg/msg/detail/sync_pc__functions.h"
#include "pc_msg/msg/detail/sync_pc__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace pc_msg
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void SyncPc_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) pc_msg::msg::SyncPc(_init);
}

void SyncPc_fini_function(void * message_memory)
{
  auto typed_message = static_cast<pc_msg::msg::SyncPc *>(message_memory);
  typed_message->~SyncPc();
}

size_t size_function__SyncPc__pointclouds(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<sensor_msgs::msg::PointCloud2> *>(untyped_member);
  return member->size();
}

const void * get_const_function__SyncPc__pointclouds(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<sensor_msgs::msg::PointCloud2> *>(untyped_member);
  return &member[index];
}

void * get_function__SyncPc__pointclouds(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<sensor_msgs::msg::PointCloud2> *>(untyped_member);
  return &member[index];
}

void fetch_function__SyncPc__pointclouds(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const sensor_msgs::msg::PointCloud2 *>(
    get_const_function__SyncPc__pointclouds(untyped_member, index));
  auto & value = *reinterpret_cast<sensor_msgs::msg::PointCloud2 *>(untyped_value);
  value = item;
}

void assign_function__SyncPc__pointclouds(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<sensor_msgs::msg::PointCloud2 *>(
    get_function__SyncPc__pointclouds(untyped_member, index));
  const auto & value = *reinterpret_cast<const sensor_msgs::msg::PointCloud2 *>(untyped_value);
  item = value;
}

void resize_function__SyncPc__pointclouds(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<sensor_msgs::msg::PointCloud2> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember SyncPc_message_member_array[2] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pc_msg::msg::SyncPc, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "pointclouds",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<sensor_msgs::msg::PointCloud2>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(pc_msg::msg::SyncPc, pointclouds),  // bytes offset in struct
    nullptr,  // default value
    size_function__SyncPc__pointclouds,  // size() function pointer
    get_const_function__SyncPc__pointclouds,  // get_const(index) function pointer
    get_function__SyncPc__pointclouds,  // get(index) function pointer
    fetch_function__SyncPc__pointclouds,  // fetch(index, &value) function pointer
    assign_function__SyncPc__pointclouds,  // assign(index, value) function pointer
    resize_function__SyncPc__pointclouds  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers SyncPc_message_members = {
  "pc_msg::msg",  // message namespace
  "SyncPc",  // message name
  2,  // number of fields
  sizeof(pc_msg::msg::SyncPc),
  SyncPc_message_member_array,  // message members
  SyncPc_init_function,  // function to initialize message memory (memory has to be allocated)
  SyncPc_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t SyncPc_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &SyncPc_message_members,
  get_message_typesupport_handle_function,
  &pc_msg__msg__SyncPc__get_type_hash,
  &pc_msg__msg__SyncPc__get_type_description,
  &pc_msg__msg__SyncPc__get_type_description_sources,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace pc_msg


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<pc_msg::msg::SyncPc>()
{
  return &::pc_msg::msg::rosidl_typesupport_introspection_cpp::SyncPc_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, pc_msg, msg, SyncPc)() {
  return &::pc_msg::msg::rosidl_typesupport_introspection_cpp::SyncPc_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
