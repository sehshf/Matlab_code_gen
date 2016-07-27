/*
 * File: rpi_dc_motor_control_data.c
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

#include "rpi_dc_motor_control.h"
#include "rpi_dc_motor_control_private.h"

/* Block parameters (auto storage) */
Parameters_rpi_dc_motor_control rpi_dc_motor_control_P = {
  0.008,                               /* Mask Parameter: SubsysPSD_D
                                        * Referenced by: '<S1>/  Derivative'
                                        */
  0.004,                               /* Mask Parameter: SubsysPSD_I
                                        * Referenced by: '<S1>/Integrative'
                                        */
  0.0001,                              /* Mask Parameter: SubsysPSD_P
                                        * Referenced by: '<S1>/Proportional'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S3>/ '
                                        */

  /*  Computed Parameter: PWMwDir_P1_Size
   * Referenced by: '<Root>/PWMwDir'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: chn-1
                                        * Referenced by: '<Root>/PWMwDir'
                                        */

  /*  Computed Parameter: PWMwDir_P2_Size
   * Referenced by: '<Root>/PWMwDir'
   */
  { 1.0, 1.0 },
  20000.0,                             /* Expression: pwm_freq
                                        * Referenced by: '<Root>/PWMwDir'
                                        */

  /*  Computed Parameter: PWMwDir_P3_Size
   * Referenced by: '<Root>/PWMwDir'
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: dir_do_bit-1
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/  RESET'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Position Request'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  8.0,                                 /* Expression: 8
                                        * Referenced by: '<S2>/Period time'
                                        */

  /*  Expression: [0 2000 500 500 0    0]
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  { 0.0, 2000.0, 500.0, 500.0, 0.0, 0.0 },

  /*  Expression: [0 3      5     6     6.1 8]
   * Referenced by: '<S2>/1-D Lookup Table'
   */
  { 0.0, 3.0, 5.0, 6.0, 6.1, 8.0 },

  /*  Computed Parameter: IRC0_P1_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  0.001,                               /* Expression: Ts
                                        * Referenced by: '<Root>/IRC0'
                                        */

  /*  Computed Parameter: IRC0_P2_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: chn-1
                                        * Referenced by: '<Root>/IRC0'
                                        */

  /*  Computed Parameter: IRC0_P3_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: mode-1
                                        * Referenced by: '<Root>/IRC0'
                                        */

  /*  Computed Parameter: IRC0_P4_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: gating-2
                                        * Referenced by: '<Root>/IRC0'
                                        */

  /*  Computed Parameter: IRC0_P5_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  -1.0,                                /* Expression: resetctrl-2
                                        * Referenced by: '<Root>/IRC0'
                                        */

  /*  Computed Parameter: IRC0_P6_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  0.0,                                 /* Expression: digfilter
                                        * Referenced by: '<Root>/IRC0'
                                        */

  /*  Computed Parameter: IRC0_P7_Size
   * Referenced by: '<Root>/IRC0'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: reset_at_startup
                                        * Referenced by: '<Root>/IRC0'
                                        */
  0.001,                               /* Computed Parameter: Int1_gainval
                                        * Referenced by: '<S1>/Int1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Int1'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  -1.0,                                /* Expression: -1
                                        * Referenced by: '<Root>/Active Output Range'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Active Output Range'
                                        */
  10000.0,                             /* Expression: 10000
                                        * Referenced by: '<Root>/Anti Windup'
                                        */
  -0.01,                               /* Expression: -0.01
                                        * Referenced by: '<Root>/Manual PWM'
                                        */
  0U,                                  /* Computed Parameter: Position_CurrentSetting
                                        * Referenced by: '<Root>/Position'
                                        */
  1U                                   /* Computed Parameter: ManualPWMControl_CurrentSetting
                                        * Referenced by: '<Root>/Manual PWM Control'
                                        */
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
