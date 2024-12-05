// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from stamp_markerarray:msg/StampedMarkerArray.idl
// generated code does not contain a copyright notice
#include "stamp_markerarray/msg/detail/stamped_marker_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `markers`
#include "visualization_msgs/msg/detail/marker__functions.h"

bool
stamp_markerarray__msg__StampedMarkerArray__init(stamp_markerarray__msg__StampedMarkerArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    stamp_markerarray__msg__StampedMarkerArray__fini(msg);
    return false;
  }
  // markers
  if (!visualization_msgs__msg__Marker__Sequence__init(&msg->markers, 0)) {
    stamp_markerarray__msg__StampedMarkerArray__fini(msg);
    return false;
  }
  return true;
}

void
stamp_markerarray__msg__StampedMarkerArray__fini(stamp_markerarray__msg__StampedMarkerArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // markers
  visualization_msgs__msg__Marker__Sequence__fini(&msg->markers);
}

bool
stamp_markerarray__msg__StampedMarkerArray__are_equal(const stamp_markerarray__msg__StampedMarkerArray * lhs, const stamp_markerarray__msg__StampedMarkerArray * rhs)
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
  // markers
  if (!visualization_msgs__msg__Marker__Sequence__are_equal(
      &(lhs->markers), &(rhs->markers)))
  {
    return false;
  }
  return true;
}

bool
stamp_markerarray__msg__StampedMarkerArray__copy(
  const stamp_markerarray__msg__StampedMarkerArray * input,
  stamp_markerarray__msg__StampedMarkerArray * output)
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
  // markers
  if (!visualization_msgs__msg__Marker__Sequence__copy(
      &(input->markers), &(output->markers)))
  {
    return false;
  }
  return true;
}

stamp_markerarray__msg__StampedMarkerArray *
stamp_markerarray__msg__StampedMarkerArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stamp_markerarray__msg__StampedMarkerArray * msg = (stamp_markerarray__msg__StampedMarkerArray *)allocator.allocate(sizeof(stamp_markerarray__msg__StampedMarkerArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(stamp_markerarray__msg__StampedMarkerArray));
  bool success = stamp_markerarray__msg__StampedMarkerArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
stamp_markerarray__msg__StampedMarkerArray__destroy(stamp_markerarray__msg__StampedMarkerArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    stamp_markerarray__msg__StampedMarkerArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
stamp_markerarray__msg__StampedMarkerArray__Sequence__init(stamp_markerarray__msg__StampedMarkerArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stamp_markerarray__msg__StampedMarkerArray * data = NULL;

  if (size) {
    data = (stamp_markerarray__msg__StampedMarkerArray *)allocator.zero_allocate(size, sizeof(stamp_markerarray__msg__StampedMarkerArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = stamp_markerarray__msg__StampedMarkerArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        stamp_markerarray__msg__StampedMarkerArray__fini(&data[i - 1]);
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
stamp_markerarray__msg__StampedMarkerArray__Sequence__fini(stamp_markerarray__msg__StampedMarkerArray__Sequence * array)
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
      stamp_markerarray__msg__StampedMarkerArray__fini(&array->data[i]);
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

stamp_markerarray__msg__StampedMarkerArray__Sequence *
stamp_markerarray__msg__StampedMarkerArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  stamp_markerarray__msg__StampedMarkerArray__Sequence * array = (stamp_markerarray__msg__StampedMarkerArray__Sequence *)allocator.allocate(sizeof(stamp_markerarray__msg__StampedMarkerArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = stamp_markerarray__msg__StampedMarkerArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
stamp_markerarray__msg__StampedMarkerArray__Sequence__destroy(stamp_markerarray__msg__StampedMarkerArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    stamp_markerarray__msg__StampedMarkerArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
stamp_markerarray__msg__StampedMarkerArray__Sequence__are_equal(const stamp_markerarray__msg__StampedMarkerArray__Sequence * lhs, const stamp_markerarray__msg__StampedMarkerArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!stamp_markerarray__msg__StampedMarkerArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
stamp_markerarray__msg__StampedMarkerArray__Sequence__copy(
  const stamp_markerarray__msg__StampedMarkerArray__Sequence * input,
  stamp_markerarray__msg__StampedMarkerArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(stamp_markerarray__msg__StampedMarkerArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    stamp_markerarray__msg__StampedMarkerArray * data =
      (stamp_markerarray__msg__StampedMarkerArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!stamp_markerarray__msg__StampedMarkerArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          stamp_markerarray__msg__StampedMarkerArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!stamp_markerarray__msg__StampedMarkerArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
