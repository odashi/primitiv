#include <primitiv/config.h>

#include <primitiv/devices/eigen/device.h>
#include <primitiv/devices/eigen/ops/common.h>

namespace primitiv {
namespace devices {

EIGEN_DEV_FW_X(exp, x.exp());
EIGEN_DEV_BW_X(exp, gy * y);

}  // namespace devices
}  // namespace primitiv
