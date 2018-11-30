#include <primitiv/config.h>

#include <primitiv/internal/opencl/utils.h>
#include <primitiv/devices/opencl/ops/common.h>

namespace primitiv {
namespace devices {

void OpenCL::max_fw_impl(const Tensor &x, std::uint32_t dim, Tensor &y) {
  if (!state_->max_fw_kernel.initialized()) {
    state_->initialize_kernel(state_->max_fw_kernel, std::string({
#include "primitiv/devices/opencl/kernels/max.inc"
    }), "max_fw_kernel");
  }
  const std::uint32_t n = x.shape()[dim];
  const std::uint32_t r = y.shape().size();
  const std::uint32_t s = y.shape().lower_volume(dim);
  state_->max_fw_kernel.kernel().setArg(0, CDATA(x));
  state_->max_fw_kernel.kernel().setArg(1, s);
  state_->max_fw_kernel.kernel().setArg(2, n);
  state_->max_fw_kernel.kernel().setArg(3, MDATA(y));
  state_->queue.enqueueNDRangeKernel(
      state_->max_fw_kernel.kernel(), cl::NullRange,
      cl::NDRange(r * state_->max_fw_kernel.group_size()[0]),
      cl::NDRange(state_->max_fw_kernel.group_size()[0]));
}

void OpenCL::max_bw_impl(
    const Tensor &x, const Tensor &y, const Tensor &gy,
    std::uint32_t dim, Tensor &gx) {
  if (!state_->max_bw_kernel.initialized()) {
    state_->initialize_kernel(state_->max_bw_kernel, std::string({
#include "primitiv/devices/opencl/kernels/max.inc"
    }), "max_bw_kernel");
  }
  const std::uint32_t n = x.shape()[dim];
  const std::uint32_t r = y.shape().size();
  const std::uint32_t s = y.shape().lower_volume(dim);
  state_->max_bw_kernel.kernel().setArg(0, CDATA(x));
  state_->max_bw_kernel.kernel().setArg(1, CDATA(y));
  state_->max_bw_kernel.kernel().setArg(2, CDATA(gy));
  state_->max_bw_kernel.kernel().setArg(3, s);
  state_->max_bw_kernel.kernel().setArg(4, n);
  state_->max_bw_kernel.kernel().setArg(5, MDATA(gx));
  state_->queue.enqueueNDRangeKernel(
      state_->max_bw_kernel.kernel(), cl::NullRange,
      cl::NDRange(r * state_->max_bw_kernel.group_size()[0]),
      cl::NDRange(state_->max_bw_kernel.group_size()[0]));
}

}  // namespace devices
}  // namespace primitiv