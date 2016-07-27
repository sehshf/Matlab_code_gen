/*
 * File: rpi_dc_motor_control.c
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

/* Block signals (auto storage) */
BlockIO_rpi_dc_motor_control rpi_dc_motor_control_B;

/* Block states (auto storage) */
D_Work_rpi_dc_motor_control rpi_dc_motor_control_DWork;

/* Real-time model */
RT_MODEL_rpi_dc_motor_control rpi_dc_motor_control_M_;
RT_MODEL_rpi_dc_motor_control *const rpi_dc_motor_control_M =
  &rpi_dc_motor_control_M_;
real_T look1_binlxpw(real_T u0, const real_T bp0[], const real_T table[],
                     uint32_T maxIndex)
{
  real_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Interpolation 1-D
     Interpolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

/* Model step function */
void rpi_dc_motor_control_step(void)
{
  /* local block i/o variables */
  real_T rtb_DigitalClock;
  real_T rtb_ActiveOutputRange;
  real_T rtb_Sum1;
  real_T rtb_Sum3;
  real_T tmp;

  /* Level2 S-Function Block: '<Root>/PWMwDir' (sfPWMwDirOutput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* DigitalClock: '<S2>/Digital Clock' */
  rtb_DigitalClock = rpi_dc_motor_control_M->Timing.t[0];

  /* Outputs for Enabled SubSystem: '<S2>/Latch' incorporates:
   *  EnablePort: '<S3>/Enable'
   */
  /* RelationalOperator: '<S2>/ToBolean' incorporates:
   *  Constant: '<S2>/Period time'
   *  Inport: '<S3>/In'
   *  Memory: '<S2>/Memory'
   */
  if (rpi_dc_motor_control_DWork.Memory_PreviousInput >
      rpi_dc_motor_control_P.Periodtime_Value) {
    rpi_dc_motor_control_B.In = rtb_DigitalClock;
  }

  /* End of RelationalOperator: '<S2>/ToBolean' */
  /* End of Outputs for SubSystem: '<S2>/Latch' */

  /* Sum: '<S2>/Sum3' */
  rtb_Sum3 = rtb_DigitalClock - rpi_dc_motor_control_B.In;

  /* Lookup_n-D: '<S2>/1-D Lookup Table' */
  rtb_ActiveOutputRange = look1_binlxpw(rtb_Sum3,
    rpi_dc_motor_control_P.DLookupTable_bp01Data,
    rpi_dc_motor_control_P.DLookupTable_tableData, 5U);

  /* ManualSwitch: '<Root>/Position' incorporates:
   *  Constant: '<Root>/Position Request'
   */
  if (rpi_dc_motor_control_P.Position_CurrentSetting == 1) {
    rtb_ActiveOutputRange = rpi_dc_motor_control_P.PositionRequest_Value;
  }

  /* End of ManualSwitch: '<Root>/Position' */

  /* Level2 S-Function Block: '<Root>/IRC0' (sfIRCInput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[1];
    sfcnOutputs(rts, 0);
  }

  /* Sum: '<S1>/(eFi1-4)' incorporates:
   *  DataTypeConversion: '<Root>/IRC int32 to Real'
   */
  rtb_ActiveOutputRange -= (real_T)rpi_dc_motor_control_B.IRC0;

  /* DiscreteIntegrator: '<S1>/Int1' incorporates:
   *  Constant: '<Root>/  RESET'
   */
  if ((rpi_dc_motor_control_P.RESET_Value != 0.0) ||
      (rpi_dc_motor_control_DWork.Int1_PrevResetState != 0)) {
    rpi_dc_motor_control_DWork.Int1_DSTATE = rpi_dc_motor_control_P.Int1_IC;
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  DiscreteIntegrator: '<S1>/Int1'
   *  Gain: '<S1>/  Derivative'
   *  Gain: '<S1>/Integrative'
   *  Gain: '<S1>/Proportional'
   *  Sum: '<S1>/Sum'
   *  UnitDelay: '<S1>/Unit Delay'
   */
  rtb_Sum1 = (rpi_dc_motor_control_P.SubsysPSD_P * rtb_ActiveOutputRange +
              rpi_dc_motor_control_P.SubsysPSD_I *
              rpi_dc_motor_control_DWork.Int1_DSTATE) + (rtb_ActiveOutputRange -
    rpi_dc_motor_control_DWork.UnitDelay_DSTATE) *
    rpi_dc_motor_control_P.SubsysPSD_D;

  /* ManualSwitch: '<Root>/Manual PWM Control' incorporates:
   *  Constant: '<Root>/Manual PWM'
   */
  if (rpi_dc_motor_control_P.ManualPWMControl_CurrentSetting == 1) {
    rpi_dc_motor_control_B.ManualPWMControl = rtb_Sum1;
  } else {
    rpi_dc_motor_control_B.ManualPWMControl =
      rpi_dc_motor_control_P.ManualPWM_Value;
  }

  /* End of ManualSwitch: '<Root>/Manual PWM Control' */

  /* DataTypeConversion: '<Root>/To int' incorporates:
   *  Constant: '<Root>/  RESET'
   */
  tmp = floor(rpi_dc_motor_control_P.RESET_Value);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 256.0);
  }

  rpi_dc_motor_control_B.Toint = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)
    -(int8_T)(uint8_T)-tmp : (int32_T)(uint8_T)tmp);

  /* End of DataTypeConversion: '<Root>/To int' */

  /* Update for Memory: '<S2>/Memory' */
  rpi_dc_motor_control_DWork.Memory_PreviousInput = rtb_Sum3;

  /* Level2 S-Function Block: '<Root>/IRC0' (sfIRCInput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[1];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Update for DiscreteIntegrator: '<S1>/Int1' incorporates:
   *  Constant: '<Root>/  RESET'
   *  Gain: '<Root>/Anti Windup'
   *  Sum: '<S1>/AL sub'
   */
  if (rpi_dc_motor_control_P.RESET_Value == 0.0) {
    /* DeadZone: '<Root>/Active Output Range' */
    if (rtb_Sum1 > rpi_dc_motor_control_P.ActiveOutputRange_End) {
      rtb_Sum1 -= rpi_dc_motor_control_P.ActiveOutputRange_End;
    } else if (rtb_Sum1 >= rpi_dc_motor_control_P.ActiveOutputRange_Start) {
      rtb_Sum1 = 0.0;
    } else {
      rtb_Sum1 -= rpi_dc_motor_control_P.ActiveOutputRange_Start;
    }

    /* End of DeadZone: '<Root>/Active Output Range' */
    rpi_dc_motor_control_DWork.Int1_DSTATE += (rtb_ActiveOutputRange -
      rpi_dc_motor_control_P.AntiWindup_Gain * rtb_Sum1) *
      rpi_dc_motor_control_P.Int1_gainval;
  }

  if (rpi_dc_motor_control_P.RESET_Value > 0.0) {
    rpi_dc_motor_control_DWork.Int1_PrevResetState = 1;
  } else if (rpi_dc_motor_control_P.RESET_Value < 0.0) {
    rpi_dc_motor_control_DWork.Int1_PrevResetState = -1;
  } else if (rpi_dc_motor_control_P.RESET_Value == 0.0) {
    rpi_dc_motor_control_DWork.Int1_PrevResetState = 0;
  } else {
    rpi_dc_motor_control_DWork.Int1_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1>/Int1' */

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  rpi_dc_motor_control_DWork.UnitDelay_DSTATE = rtb_ActiveOutputRange;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   */
  rpi_dc_motor_control_M->Timing.t[0] =
    (++rpi_dc_motor_control_M->Timing.clockTick0) *
    rpi_dc_motor_control_M->Timing.stepSize0;
}

/* Model initialize function */
void rpi_dc_motor_control_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)rpi_dc_motor_control_M, 0,
                sizeof(RT_MODEL_rpi_dc_motor_control));
  rtsiSetSolverName(&rpi_dc_motor_control_M->solverInfo,"FixedStepDiscrete");
  rpi_dc_motor_control_M->solverInfoPtr = (&rpi_dc_motor_control_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = rpi_dc_motor_control_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    rpi_dc_motor_control_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    rpi_dc_motor_control_M->Timing.sampleTimes =
      (&rpi_dc_motor_control_M->Timing.sampleTimesArray[0]);
    rpi_dc_motor_control_M->Timing.offsetTimes =
      (&rpi_dc_motor_control_M->Timing.offsetTimesArray[0]);

    /* task periods */
    rpi_dc_motor_control_M->Timing.sampleTimes[0] = (0.001);

    /* task offsets */
    rpi_dc_motor_control_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(rpi_dc_motor_control_M, &rpi_dc_motor_control_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = rpi_dc_motor_control_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    rpi_dc_motor_control_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(rpi_dc_motor_control_M, -1);
  rpi_dc_motor_control_M->Timing.stepSize0 = 0.001;
  rpi_dc_motor_control_M->solverInfoPtr = (&rpi_dc_motor_control_M->solverInfo);
  rpi_dc_motor_control_M->Timing.stepSize = (0.001);
  rtsiSetFixedStepSize(&rpi_dc_motor_control_M->solverInfo, 0.001);
  rtsiSetSolverMode(&rpi_dc_motor_control_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &rpi_dc_motor_control_B), 0,
                sizeof(BlockIO_rpi_dc_motor_control));

  /* states (dwork) */
  (void) memset((void *)&rpi_dc_motor_control_DWork, 0,
                sizeof(D_Work_rpi_dc_motor_control));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &rpi_dc_motor_control_M->NonInlinedSFcns.sfcnInfo;
    rpi_dc_motor_control_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(rpi_dc_motor_control_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &rpi_dc_motor_control_M->Sizes.numSampTimes);
    rpi_dc_motor_control_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (rpi_dc_motor_control_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,rpi_dc_motor_control_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(rpi_dc_motor_control_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(rpi_dc_motor_control_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (rpi_dc_motor_control_M));
    rtssSetStepSizePtr(sfcnInfo, &rpi_dc_motor_control_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (rpi_dc_motor_control_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &rpi_dc_motor_control_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &rpi_dc_motor_control_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &rpi_dc_motor_control_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &rpi_dc_motor_control_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &rpi_dc_motor_control_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &rpi_dc_motor_control_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &rpi_dc_motor_control_M->solverInfoPtr);
  }

  rpi_dc_motor_control_M->Sizes.numSFcns = (2);

  /* register each child */
  {
    (void) memset((void *)
                  &rpi_dc_motor_control_M->NonInlinedSFcns.childSFunctions[0], 0,
                  2*sizeof(SimStruct));
    rpi_dc_motor_control_M->childSfunctions =
      (&rpi_dc_motor_control_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    rpi_dc_motor_control_M->childSfunctions[0] =
      (&rpi_dc_motor_control_M->NonInlinedSFcns.childSFunctions[0]);
    rpi_dc_motor_control_M->childSfunctions[1] =
      (&rpi_dc_motor_control_M->NonInlinedSFcns.childSFunctions[1]);

    /* Level2 S-Function Block: rpi_dc_motor_control/<Root>/PWMwDir (sfPWMwDirOutput) */
    {
      SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &rpi_dc_motor_control_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      ssSetRTWSfcnInfo(rts, rpi_dc_motor_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &rpi_dc_motor_control_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &rpi_dc_motor_control_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &rpi_dc_motor_control_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &rpi_dc_motor_control_B.ManualPWMControl);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PWMwDir");
      ssSetPath(rts, "rpi_dc_motor_control/PWMwDir");
      ssSetRTModel(rts,rpi_dc_motor_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rpi_dc_motor_control_P.PWMwDir_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rpi_dc_motor_control_P.PWMwDir_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rpi_dc_motor_control_P.PWMwDir_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &rpi_dc_motor_control_DWork.PWMwDir_RWORK);
      ssSetIWork(rts, (int_T *) &rpi_dc_motor_control_DWork.PWMwDir_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rpi_dc_motor_control_DWork.PWMwDir_RWORK);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 5);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &rpi_dc_motor_control_DWork.PWMwDir_IWORK[0]);
      }

      /* registration */
      sfPWMwDirOutput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: rpi_dc_motor_control/<Root>/IRC0 (sfIRCInput) */
    {
      SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &rpi_dc_motor_control_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      ssSetRTWSfcnInfo(rts, rpi_dc_motor_control_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &rpi_dc_motor_control_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &rpi_dc_motor_control_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &rpi_dc_motor_control_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &rpi_dc_motor_control_B.Toint);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((int32_T *)
            &rpi_dc_motor_control_B.IRC0));
        }
      }

      /* path info */
      ssSetModelName(rts, "IRC0");
      ssSetPath(rts, "rpi_dc_motor_control/IRC0");
      ssSetRTModel(rts,rpi_dc_motor_control_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)rpi_dc_motor_control_P.IRC0_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)rpi_dc_motor_control_P.IRC0_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)rpi_dc_motor_control_P.IRC0_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)rpi_dc_motor_control_P.IRC0_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)rpi_dc_motor_control_P.IRC0_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)rpi_dc_motor_control_P.IRC0_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)rpi_dc_motor_control_P.IRC0_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &rpi_dc_motor_control_DWork.IRC0_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &rpi_dc_motor_control_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 8);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &rpi_dc_motor_control_DWork.IRC0_IWORK[0]);
      }

      /* registration */
      sfIRCInput(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Level2 S-Function Block: '<Root>/PWMwDir' (sfPWMwDirOutput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<S2>/Latch' */
  /* VirtualOutportStart for Outport: '<S3>/ ' */
  rpi_dc_motor_control_B.In = rpi_dc_motor_control_P._Y0;

  /* End of Start for SubSystem: '<S2>/Latch' */
  /* Level2 S-Function Block: '<Root>/IRC0' (sfIRCInput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<Root>/PWMwDir' (sfPWMwDirOutput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Memory: '<S2>/Memory' */
  rpi_dc_motor_control_DWork.Memory_PreviousInput =
    rpi_dc_motor_control_P.Memory_X0;

  /* Level2 S-Function Block: '<Root>/IRC0' (sfIRCInput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[1];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for DiscreteIntegrator: '<S1>/Int1' */
  rpi_dc_motor_control_DWork.Int1_DSTATE = rpi_dc_motor_control_P.Int1_IC;
  rpi_dc_motor_control_DWork.Int1_PrevResetState = 0;

  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay' */
  rpi_dc_motor_control_DWork.UnitDelay_DSTATE =
    rpi_dc_motor_control_P.UnitDelay_InitialCondition;
}

/* Model terminate function */
void rpi_dc_motor_control_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/PWMwDir' (sfPWMwDirOutput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<Root>/IRC0' (sfIRCInput) */
  {
    SimStruct *rts = rpi_dc_motor_control_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
