/*
 * File: rpi_dc_motor_control.h
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

#ifndef RTW_HEADER_rpi_dc_motor_control_h_
#define RTW_HEADER_rpi_dc_motor_control_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef rpi_dc_motor_control_COMMON_INCLUDES_
# define rpi_dc_motor_control_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif                                 /* rpi_dc_motor_control_COMMON_INCLUDES_ */

#include "rpi_dc_motor_control_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T ManualPWMControl;             /* '<Root>/Manual PWM Control' */
  real_T In;                           /* '<S3>/In' */
  int32_T IRC0;                        /* '<Root>/IRC0' */
  uint8_T Toint;                       /* '<Root>/To int' */
} BlockIO_rpi_dc_motor_control;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Int1_DSTATE;                  /* '<S1>/Int1' */
  real_T UnitDelay_DSTATE;             /* '<S1>/Unit Delay' */
  real_T Memory_PreviousInput;         /* '<S2>/Memory' */
  real_T PWMwDir_RWORK;                /* '<Root>/PWMwDir' */
  int_T PWMwDir_IWORK[5];              /* '<Root>/PWMwDir' */
  int_T IRC0_IWORK[8];                 /* '<Root>/IRC0' */
  int8_T Int1_PrevResetState;          /* '<S1>/Int1' */
} D_Work_rpi_dc_motor_control;

/* Parameters (auto storage) */
struct Parameters_rpi_dc_motor_control_ {
  real_T SubsysPSD_D;                  /* Mask Parameter: SubsysPSD_D
                                        * Referenced by: '<S1>/  Derivative'
                                        */
  real_T SubsysPSD_I;                  /* Mask Parameter: SubsysPSD_I
                                        * Referenced by: '<S1>/Integrative'
                                        */
  real_T SubsysPSD_P;                  /* Mask Parameter: SubsysPSD_P
                                        * Referenced by: '<S1>/Proportional'
                                        */
  real_T _Y0;                          /* Expression: 0
                                        * Referenced by: '<S3>/ '
                                        */
  real_T PWMwDir_P1_Size[2];           /* Computed Parameter: PWMwDir_P1_Size
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  real_T PWMwDir_P1;                   /* Expression: chn-1
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  real_T PWMwDir_P2_Size[2];           /* Computed Parameter: PWMwDir_P2_Size
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  real_T PWMwDir_P2;                   /* Expression: pwm_freq
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  real_T PWMwDir_P3_Size[2];           /* Computed Parameter: PWMwDir_P3_Size
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  real_T PWMwDir_P3;                   /* Expression: dir_do_bit-1
                                        * Referenced by: '<Root>/PWMwDir'
                                        */
  real_T RESET_Value;                  /* Expression: 0
                                        * Referenced by: '<Root>/  RESET'
                                        */
  real_T PositionRequest_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/Position Request'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S2>/Memory'
                                        */
  real_T Periodtime_Value;             /* Expression: 8
                                        * Referenced by: '<S2>/Period time'
                                        */
  real_T DLookupTable_tableData[6];    /* Expression: [0 2000 500 500 0    0]
                                        * Referenced by: '<S2>/1-D Lookup Table'
                                        */
  real_T DLookupTable_bp01Data[6];     /* Expression: [0 3      5     6     6.1 8]
                                        * Referenced by: '<S2>/1-D Lookup Table'
                                        */
  real_T IRC0_P1_Size[2];              /* Computed Parameter: IRC0_P1_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P1;                      /* Expression: Ts
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P2_Size[2];              /* Computed Parameter: IRC0_P2_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P2;                      /* Expression: chn-1
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P3_Size[2];              /* Computed Parameter: IRC0_P3_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P3;                      /* Expression: mode-1
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P4_Size[2];              /* Computed Parameter: IRC0_P4_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P4;                      /* Expression: gating-2
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P5_Size[2];              /* Computed Parameter: IRC0_P5_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P5;                      /* Expression: resetctrl-2
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P6_Size[2];              /* Computed Parameter: IRC0_P6_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P6;                      /* Expression: digfilter
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P7_Size[2];              /* Computed Parameter: IRC0_P7_Size
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T IRC0_P7;                      /* Expression: reset_at_startup
                                        * Referenced by: '<Root>/IRC0'
                                        */
  real_T Int1_gainval;                 /* Computed Parameter: Int1_gainval
                                        * Referenced by: '<S1>/Int1'
                                        */
  real_T Int1_IC;                      /* Expression: 0
                                        * Referenced by: '<S1>/Int1'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S1>/Unit Delay'
                                        */
  real_T ActiveOutputRange_Start;      /* Expression: -1
                                        * Referenced by: '<Root>/Active Output Range'
                                        */
  real_T ActiveOutputRange_End;        /* Expression: 1
                                        * Referenced by: '<Root>/Active Output Range'
                                        */
  real_T AntiWindup_Gain;              /* Expression: 10000
                                        * Referenced by: '<Root>/Anti Windup'
                                        */
  real_T ManualPWM_Value;              /* Expression: -0.01
                                        * Referenced by: '<Root>/Manual PWM'
                                        */
  uint8_T Position_CurrentSetting;     /* Computed Parameter: Position_CurrentSetting
                                        * Referenced by: '<Root>/Position'
                                        */
  uint8_T ManualPWMControl_CurrentSetting;/* Computed Parameter: ManualPWMControl_CurrentSetting
                                           * Referenced by: '<Root>/Manual PWM Control'
                                           */
};

/* Real-time Model Data Structure */
struct tag_RTM_rpi_dc_motor_control {
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[2];
    SimStruct *childSFunctionPtrs[2];
    struct _ssBlkInfo2 blkInfo2[2];
    struct _ssSFcnModelMethods2 methods2[2];
    struct _ssSFcnModelMethods3 methods3[2];
    struct _ssStatesInfo2 statesInfo2[2];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern Parameters_rpi_dc_motor_control rpi_dc_motor_control_P;

/* Block signals (auto storage) */
extern BlockIO_rpi_dc_motor_control rpi_dc_motor_control_B;

/* Block states (auto storage) */
extern D_Work_rpi_dc_motor_control rpi_dc_motor_control_DWork;

/* Model entry point functions */
extern void rpi_dc_motor_control_initialize(void);
extern void rpi_dc_motor_control_step(void);
extern void rpi_dc_motor_control_terminate(void);

/* Real-time Model object */
extern RT_MODEL_rpi_dc_motor_control *const rpi_dc_motor_control_M;

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
 * '<Root>' : 'rpi_dc_motor_control'
 * '<S1>'   : 'rpi_dc_motor_control/Subsys PSD'
 * '<S2>'   : 'rpi_dc_motor_control/Trajectory'
 * '<S3>'   : 'rpi_dc_motor_control/Trajectory/Latch'
 */
#endif                                 /* RTW_HEADER_rpi_dc_motor_control_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
