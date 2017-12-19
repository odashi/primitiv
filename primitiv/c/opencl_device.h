/* Copyright 2017 The primitiv Authors. All Rights Reserved. */

#ifndef PRIMITIV_C_OPENCL_DEVICE_H_
#define PRIMITIV_C_OPENCL_DEVICE_H_

#include <primitiv/c/define.h>
#include <primitiv/c/device.h>
#include <primitiv/c/status.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Creates a new Device object.
 * @param device Pointer to receive a handler.
 * @param platform_id Platform ID.
 * @param device_id Device ID on the selected platform.
 * @param rng_seed Seed value of the random number generator.
 * @return Status code.
 */
CAPI extern primitiv_Status primitiv_OpenCL_new(
    primitiv_Device **device, uint32_t platform_id, uint32_t device_id);

/**
 * Creates a new Device object.
 * @param device Pointer to receive a handler.
 * @param platform_id Platform ID.
 * @param device_id Device ID on the selected platform.
 * @param rng_seed Seed value of the random number generator.
 * @return Status code.
 */
CAPI extern primitiv_Status primitiv_OpenCL_new_with_seed(
    primitiv_Device **device, uint32_t platform_id, uint32_t device_id,
    uint32_t rng_seed);

/**
 * Deletes the Device object.
 * @param device Pointer of a handler.
 */
CAPI extern void primitiv_OpenCL_delete(primitiv_Device *device);

/**
 * Retrieves the number of active platforms.
 * @return Number of active platforms.
 */
CAPI extern uint32_t primitiv_OpenCL_num_platforms();

/**
 * Retrieves the number of active devices on the specified platform.
 * @param platform_id Platform ID.
 *                    This value should be between 0 to num_platforms() - 1.
 * @return Number of active devices.
 */
CAPI extern uint32_t primitiv_OpenCL_num_devices(uint32_t platform_id);

/**
 * Prints device description to stderr.
 * @param device Pointer of a handler.
 */
CAPI extern void primitiv_OpenCL_dump_description(
    const primitiv_Device *device);

#ifdef __cplusplus
}  // end extern "C"
#endif

#endif  // PRIMITIV_C_OPENCL_DEVICE_H_
