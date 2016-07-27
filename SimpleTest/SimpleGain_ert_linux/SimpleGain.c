/*
 * File: SimpleGain.c
 *
 * Code generated for Simulink model 'SimpleGain'.
 *
 * Model version                  : 1.8
 * Simulink Coder version         : 8.6 (R2014a) 27-Dec-2013
 * C/C++ source code generated on : Wed Apr 27 16:52:19 2016
 *
 * Target selection: ert_linux.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "SimpleGain.h"
#include "SimpleGain_private.h"

/* External inputs (root inport signals with auto storage) */
ExtU_SimpleGain_T SimpleGain_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_SimpleGain_T SimpleGain_Y;

/* Real-time model */
RT_MODEL_SimpleGain_T SimpleGain_M_;
RT_MODEL_SimpleGain_T *const SimpleGain_M = &SimpleGain_M_;

/* Model step function */
void SimpleGain_step(void)
{
  /* Outport: '<Root>/Out1' incorporates:
   *  Gain: '<Root>/Gain'
   *  Inport: '<Root>/In1'
   */
  SimpleGain_Y.Out1 = SimpleGain_P.Gain_Gain * SimpleGain_U.In1;
}

/* Model initialize function */
void SimpleGain_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(SimpleGain_M, (NULL));

  /* external inputs */
  SimpleGain_U.In1 = 0.0;

  /* external outputs */
  SimpleGain_Y.Out1 = 0.0;
}

/* Model terminate function */
void SimpleGain_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
