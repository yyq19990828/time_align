// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice

#ifndef PC_MSG__MSG__DETAIL__SYNC_PC__BUILDER_HPP_
#define PC_MSG__MSG__DETAIL__SYNC_PC__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pc_msg/msg/detail/sync_pc__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pc_msg
{

namespace msg
{

namespace builder
{

class Init_SyncPc_pointclouds
{
public:
  explicit Init_SyncPc_pointclouds(::pc_msg::msg::SyncPc & msg)
  : msg_(msg)
  {}
  ::pc_msg::msg::SyncPc pointclouds(::pc_msg::msg::SyncPc::_pointclouds_type arg)
  {
    msg_.pointclouds = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pc_msg::msg::SyncPc msg_;
};

class Init_SyncPc_header
{
public:
  Init_SyncPc_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SyncPc_pointclouds header(::pc_msg::msg::SyncPc::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_SyncPc_pointclouds(msg_);
  }

private:
  ::pc_msg::msg::SyncPc msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pc_msg::msg::SyncPc>()
{
  return pc_msg::msg::builder::Init_SyncPc_header();
}

}  // namespace pc_msg

#endif  // PC_MSG__MSG__DETAIL__SYNC_PC__BUILDER_HPP_
