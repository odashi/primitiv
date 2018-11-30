#ifndef GROUP_SIZE
  #define GROUP_SIZE 64
#endif

OPENCLDEV_KERNEL_FW_X(tanh, tanh(px[i]), GROUP_SIZE)
OPENCLDEV_KERNEL_BW_X(tanh, (1.f - py[i] * py[i]) * pgy[i], GROUP_SIZE)
