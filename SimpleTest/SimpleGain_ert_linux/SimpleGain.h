/*
 * File: SimpleGain.h
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

#ifndef RTW_HEADER_SimpleGain_h_
#define RTW_HEADER_SimpleGain_h_
#include <stddef.h>
#ifndef SimpleGain_COMMON_INCLUDES_
# define SimpleGain_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* SimpleGain_COMMON_INCLUDES_ */

#include "SimpleGain_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
} ExtU_SimpleGain_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
} ExtY_SimpleGain_T;

/* Parameters (auto storage) */
struct P_SimpleGain_T_ {
  real_T Gain_Gain;                    /* Expression: 20
                                        * Referenced by: '<Root>/Gain'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_SimpleGain_T {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_SimpleGain_T SimpleGain_P;

/* External inputs (root inport signals with auto storage) */
extern ExtU_SimpleGain_T SimpleGain_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_SimpleGain_T SimpleGain_Y;

/* Model entry point functions */
extern void SimpleGain_initialize(void);
extern void SimpleGain_step(void);
extern void SimpleGain_terminate(void);

/* Real-time Model object */
extern RT_MODEL_SimpleGain_T *const SimpleGain_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'SimpleGain'
 */
#endif                                 /* RTW_HEADER_SimpleGain_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
