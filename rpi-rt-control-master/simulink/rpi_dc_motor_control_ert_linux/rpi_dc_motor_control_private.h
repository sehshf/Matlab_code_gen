/*
 * File: rpi_dc_motor_control_private.h
 *
 * Code generated for Simulink model 'rpi_dc_motor_control'.
 *
 * Model version                  : 1.160
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Apr 27 14:15:09 2016
 *
 * Target selection: ert_linux.tlc
 * Embedded hardware selection: Intel->x86-64
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rpi_dc_motor_control_private_h_
#define RTW_HEADER_rpi_dc_motor_control_private_h_
#include "rtwtypes.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef __RTWTYPES_H__
#error This file requires rtwtypes.h to be included
#endif                                 /* __RTWTYPES_H__ */

extern real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
  uint32_T maxIndex);
extern void sfPWMwDirOutput(SimStruct *rts);
extern void sfIRCInput(SimStruct *rts);

#endif                                 /* RTW_HEADER_rpi_dc_motor_control_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
