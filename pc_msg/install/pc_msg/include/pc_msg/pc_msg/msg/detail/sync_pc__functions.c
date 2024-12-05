// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pc_msg:msg/SyncPc.idl
// generated code does not contain a copyright notice
#include "pc_msg/msg/detail/sync_pc__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `pointclouds`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"

bool
pc_msg__msg__SyncPc__init(pc_msg__msg__SyncPc * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pc_msg__msg__SyncPc__fini(msg);
    return false;
  }
  // pointclouds
  if (!sensor_msgs__msg__PointCloud2__Sequence__init(&msg->pointclouds, 0)) {
    pc_msg__msg__SyncPc__fini(msg);
    return false;
  }
  return true;
}

void
pc_msg__msg__SyncPc__fini(pc_msg__msg__SyncPc * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // pointclouds
  sensor_msgs__msg__PointCloud2__Sequence__fini(&msg->pointclouds);
}

bool
pc_msg__msg__SyncPc__are_equal(const pc_msg__msg__SyncPc * lhs, const pc_msg__msg__SyncPc * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // pointclouds
  if (!sensor_msgs__msg__PointCloud2__Sequence__are_equal(
      &(lhs->pointclouds), &(rhs->pointclouds)))
  {
    return false;
  }
  return true;
}

bool
pc_msg__msg__SyncPc__copy(
  const pc_msg__msg__SyncPc * input,
  pc_msg__msg__SyncPc * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // pointclouds
  if (!sensor_msgs__msg__PointCloud2__Sequence__copy(
      &(input->pointclouds), &(output->pointclouds)))
  {
    return false;
  }
  return true;
}

pc_msg__msg__SyncPc *
pc_msg__msg__SyncPc__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pc_msg__msg__SyncPc * msg = (pc_msg__msg__SyncPc *)allocator.allocate(sizeof(pc_msg__msg__SyncPc), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pc_msg__msg__SyncPc));
  bool success = pc_msg__msg__SyncPc__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pc_msg__msg__SyncPc__destroy(pc_msg__msg__SyncPc * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pc_msg__msg__SyncPc__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pc_msg__msg__SyncPc__Sequence__init(pc_msg__msg__SyncPc__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pc_msg__msg__SyncPc * data = NULL;

  if (size) {
    data = (pc_msg__msg__SyncPc *)allocator.zero_allocate(size, sizeof(pc_msg__msg__SyncPc), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pc_msg__msg__SyncPc__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pc_msg__msg__SyncPc__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pc_msg__msg__SyncPc__Sequence__fini(pc_msg__msg__SyncPc__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pc_msg__msg__SyncPc__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pc_msg__msg__SyncPc__Sequence *
pc_msg__msg__SyncPc__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pc_msg__msg__SyncPc__Sequence * array = (pc_msg__msg__SyncPc__Sequence *)allocator.allocate(sizeof(pc_msg__msg__SyncPc__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pc_msg__msg__SyncPc__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pc_msg__msg__SyncPc__Sequence__destroy(pc_msg__msg__SyncPc__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pc_msg__msg__SyncPc__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pc_msg__msg__SyncPc__Sequence__are_equal(const pc_msg__msg__SyncPc__Sequence * lhs, const pc_msg__msg__SyncPc__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pc_msg__msg__SyncPc__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pc_msg__msg__SyncPc__Sequence__copy(
  const pc_msg__msg__SyncPc__Sequence * input,
  pc_msg__msg__SyncPc__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pc_msg__msg__SyncPc);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pc_msg__msg__SyncPc * data =
      (pc_msg__msg__SyncPc *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pc_msg__msg__SyncPc__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pc_msg__msg__SyncPc__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pc_msg__msg__SyncPc__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
