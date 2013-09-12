/*
******************************************************************************
aud_mmepp.c
******************************************************************************
PCM Post Processing on Decoded data
******************************************************************************
(C) Copyright STMicroelectronics - 2005
******************************************************************************
Owner : Audio Decoding Noida Team
Revision History (Latest modification on top)
Contact Point : udit-dlh.kumar@st.com
------------------+-----------+-----------------------------------------------
  Date            ! Initials  ! Comments
------------------+-----------+-----------------------------------------------
13/09/05			UK			Started
------------------+-----------+-----------------------------------------------

------------------+-----------+-----------------------------------------------
*/
//#define  STTBX_PRINT

/* POST PROCESSOR DEBUGGING MACRO */

/*To trace the errors from Post Process  Define following variable in the way
for OS21
#define STTBX_PRINTError(_x) printf _x

for Linux
#define STTBX_PRINTError(_x) printk _x

In case of Debugging with UART on OS21, define this variable as below and
On the top of file define STTBX_PRINT */

#define STTBX_PRINTError	STTBX_Print

#include "stos.h"
#include "aud_mmepp.h"
#include "aud_mmeaudiostreamdecoder.h"
#include "dolbydigital_decodertypes.h"
/* PostProcessor Instance Array */

ST_DeviceName_t PostProcss_DeviceName[] = {"PP0","PP1"};


/* Initialized PP list. New PP will be added to this list on initialization. */
PPControlBlockList_t	*PPQueueHead_p = NULL;

/*Debugging Tools  */
#define DUMP_OUTPUT_TO_FILE 0
#if DUMP_OUTPUT_TO_FILE
	#define FRAMES	200
	static char OutBuf[MAX_SAMPLES_PER_FRAME*4*2*FRAMES]; /* FRAMES of MP2 audio */
#endif

#define DUMP_INPUT_TO_FILE 0
#if DUMP_INPUT_TO_FILE
	#define FRAMES	200
	static char InBuf[MAX_SAMPLES_PER_FRAME*4*2*FRAMES]; /* FRAMES of MP2 audio */
#endif
/* }}} */

/* Private Local Functions */
static void TransformerCallback_AudioPP (MME_Event_t Event, MME_Command_t * CallbackData, void *UserData);

static MME_ERROR	UpdatePPParams(PPControlBlock_t	*ControlBlock);



static MME_ERROR		SetAndInitPP(PPControlBlock_t	*ControlBlock);
static ST_ErrorCode_t 	InitPPQueueInParams(	PPControlBlock_t	*TempDecBlock,	STAVMEM_PartitionHandle_t AVMEMPartition);
static ST_ErrorCode_t 	InitPPQueueOutParams(PPControlBlock_t	*TempDecBlock,STAVMEM_PartitionHandle_t AVMEMPartition);
static void				InitPPTransformFrameParams(PPControlBlock_t *TempDecBlock);

static void		DeInitPPQueueInParam(PPControlBlock_t PPControlBlock);
static void		DeInitPPQueueOutParam(PPControlBlock_t PPControlBlock);
static ST_ErrorCode_t 	SendCommand(MMEAudioPPStates_t	DesiredState,
									PPControlBlock_t *ControlBlock);
static ST_ErrorCode_t 	STAud_PPCheckState(MMEAudioPPStates_t	DesiredState,
									PPControlBlock_t *ControlBlock);

static void SetSamplingFrequency (U32 SamplingFreq, enum eAccFsCode *);

/* Control Block queue Updation functions */
static void 		STAud_PPQueueAdd(PPControlBlockList_t *QueueItem_p);
static void    		STAud_PPQueueRemove( PPControlBlockList_t	*QueueItem_p);
static PPControlBlockList_t *
				STAud_PPGetControlBlockFromName(const ST_DeviceName_t DeviceName);
static PPControlBlockList_t *
				STAud_PPGetControlBlockFromHandle(STAud_PPHandle_t Handle);
static BOOL 		STAud_PPIsInit(const ST_DeviceName_t DeviceName);

/* Main processing functions */
static ST_ErrorCode_t	ProcessInput(PPControlBlock_t	*ControlBlock);
static ST_ErrorCode_t	ProcessOutput(PPControlBlock_t	*ControlBlock, U32 BytesUsed);

/* MME Calback functions */
static ST_ErrorCode_t 	MMETransformCompleted(MME_Command_t * CallbackData , void *UserData);
static ST_ErrorCode_t 	MMESetGlobalTransformCompleted(MME_Command_t * CallbackData , void *UserData);
static ST_ErrorCode_t 	MMESendBufferCompleted(MME_Command_t * CallbackData, void *UserData);


/* Hack function */
static MME_ERROR acc_setAudioMixerTransformCmd(
                              MME_Command_t    * cmd,
							  MME_GenericParams_t params_p, MME_UINT params_size,
							  MME_GenericParams_t status_p, MME_UINT status_size,
                              MME_DataBuffer_t **buffer_array,
                              enum eAccCmdCode      playback_mode);

/*Local Functions*/
void 	STAud_SetEqparams(MME_EqualizerGlobalParams_t *Equalizer,MME_EqualizerGlobalParams_t val );
void	STAud_SetDelayparams(MME_DelayGlobalParams_t *Delay,MME_DelayGlobalParams_t val );
void 	STAud_SetBassMgtGlobalParams(MME_BassMgtGlobalParams_t *BassMgt, MME_BassMgtGlobalParams_t val);
void	STAud_SetDcrmGlobalParams(MME_DCRemoveGlobalParams_t *DcRemove, MME_DCRemoveGlobalParams_t val);
void 	STAud_SetTempoparams(MME_TempoGlobalParams_t *TempoControl, MME_TempoGlobalParams_t val);
void 	STAud_SetEncPPparams(MME_EncoderPPGlobalParams_t *EncControl, MME_EncoderPPGlobalParams_t val);
void 	STAud_SetSFCPPparams(MME_SfcPPGlobalParams_t *SfcControl, MME_SfcPPGlobalParams_t val);
void	STAud_SetLxMixerPCMParams( MME_LxPcmPostProcessingGlobalParameters_t *PcmParams, MME_LxPcmPostProcessingGlobalParameters_t val);
void	STAud_SetLxMixerOutConfig(MME_LxMixerOutConfig_t *OutConfig,  STAud_PPStartParams_t StartParams);
MME_ERROR	STAud_SetLxMixerInConfig(MME_LxMixerInConfig_t *InConfig,  STAud_PPStartParams_t StartParams);
MME_ERROR	STAud_SetLxMixerTransformerGlobalParams(MME_LxMixerTransformerGlobalParams_t *GlobalParams,  STAud_PPStartParams_t StartParams,
													MME_LxMixerTransformerGlobalParams_t val);
MME_ERROR	STAud_SetMixerInitParam(MME_GenericParams_t	*init_param, STAud_PPStartParams_t StartParams, MME_LxMixerTransformerInitParams_t Val);

/* For now local ,,, may be added in top level API for future */
ST_ErrorCode_t STAud_SetPP(STAud_PPHandle_t Handle, STAud_PPType_t type, STAud_PPValue_t value);

/******************************************************************************
 *  Function name 	: STAud_PPInit
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: This function will create the PP task, initialize MME PPs's In/out
 * 				  paramaters and will update main HAL structure with current values
 ***************************************************************************** */
ST_ErrorCode_t 	STAud_PPInit(const ST_DeviceName_t DeviceName,
                           const STAud_PPInitParams_t *InitParams)
{
	/* Local variables */
	ST_ErrorCode_t 			error = ST_NO_ERROR;
	PPControlBlockList_t	*PPCtrlBlock_p = NULL;
	partition_t 				*DriverPartition = NULL;
	PPControlBlock_t		*TempPPBlock;


	/* First Check if this PP is not already open */
	if(!STAud_PPIsInit(DeviceName))
	{
		/* PP not already initialized. So do the initialization */

		/* Allocate memory for new PP control block */
		DriverPartition = (partition_t *)InitParams->DriverPartition;

		PPCtrlBlock_p = (PPControlBlockList_t *)memory_allocate(
												DriverPartition,
												sizeof(PPControlBlockList_t));

		if(PPCtrlBlock_p == NULL)
		{
			/* Error No memory available */
			return ST_ERROR_NO_MEMORY;
		}
		memset(PPCtrlBlock_p,0, sizeof(PPControlBlockList_t));

		PPCtrlBlock_p->PPControlBlock.Handle    = 0;
		strncpy(	PPCtrlBlock_p->PPControlBlock.DeviceName,
				DeviceName	,
				ST_MAX_DEVICE_NAME);

		PPCtrlBlock_p->PPControlBlock.InitParams = *InitParams;

		/* Initialize MME Structure */
		TempPPBlock = &PPCtrlBlock_p->PPControlBlock;

		TempPPBlock->MMEinitParams.Priority = MME_PRIORITY_NORMAL;
		TempPPBlock->MMEinitParams.StructSize = sizeof (MME_TransformerInitParams_t);
		TempPPBlock->MMEinitParams.Callback = &TransformerCallback_AudioPP;
		TempPPBlock->MMEinitParams.CallbackUserData = NULL; /* To be Initialized in STAud_PPStart */
		TempPPBlock->MMEinitParams.TransformerInitParamsSize = sizeof(MME_LxMixerTransformerInitParams_t);
		TempPPBlock->MMEinitParams.TransformerInitParams_p = memory_allocate(DriverPartition,
													(sizeof(MME_LxMixerTransformerInitParams_t)));

		if(TempPPBlock->MMEinitParams.TransformerInitParams_p == NULL)
		{
			/* Error No memory available */
			return ST_ERROR_NO_MEMORY;
		}

		memset(TempPPBlock->MMEinitParams.TransformerInitParams_p, 0 , sizeof(MME_LxMixerTransformerInitParams_t));
		/*Set other Pointers */

		{
			MME_LxMixerTransformerInitParams_t *LXInit;
			LXInit=(MME_LxMixerTransformerInitParams_t *)TempPPBlock->MMEinitParams.TransformerInitParams_p;
			TempPPBlock->GlobalPcmParams=&LXInit->GlobalParams;
			TempPPBlock->BassMgt=&TempPPBlock->GlobalPcmParams->PcmParams.BassMgt;
			TempPPBlock->Equalizer=&TempPPBlock->GlobalPcmParams->PcmParams.Equalizer;
			TempPPBlock->TempoControl=&TempPPBlock->GlobalPcmParams->PcmParams.TempoControl;
			TempPPBlock->DcRemove=&TempPPBlock->GlobalPcmParams->PcmParams.DCRemove;
			TempPPBlock->Delay=&TempPPBlock->GlobalPcmParams->PcmParams.Delay;
			TempPPBlock->OutConfig = &TempPPBlock->GlobalPcmParams->OutConfig;
		}




		/* Create the PP Task Semaphore */
		TempPPBlock->PPTaskSem_p = STOS_SemaphoreCreateFifo(NULL,0);
		TempPPBlock->PPInState=MME_PP_INPUT_STATE_IDLE;
		TempPPBlock->PPQueueTail = TempPPBlock->PPQueueFront= 0;
		/* Create the Control Block Mutex */
		TempPPBlock->LockControlBlockMutex_p = STOS_MutexCreateFifo();

		TempPPBlock->CmdCompletedSem_p = STOS_SemaphoreCreateFifo(NULL,0);
		/* Fill in the details of our new control block */

		/* Initialize and Allocate PP Queue's buffer pointer */
		InitPPQueueInParams(TempPPBlock, InitParams->AVMEMPartition);
		InitPPQueueOutParams(TempPPBlock, InitParams->AVMEMPartition);
		InitPPTransformFrameParams(TempPPBlock);

		/* Set the PP Starting State */
		TempPPBlock->CurPPState = MME_PP_STATE_IDLE;
		TempPPBlock->NextPPState = MME_PP_STATE_IDLE;

		/* Create the PP Task */

		STOS_TaskCreate(PP_Task_Entry_Point,(void *)&(PPCtrlBlock_p->PPControlBlock), NULL, AUDIO_PP_TASK_STACK_SIZE,
                                        NULL,NULL,&TempPPBlock->PPTask ,NULL,AUDIO_PP_TASK_PRIORITY,"PPTask",0);



		if (TempPPBlock->PPTask == NULL)
		{
			/* Error */
			return ST_ERROR_NO_MEMORY;
		}

		/* Register with Buffer Manager */

		/* As Consumer of incoming data */
		TempPPBlock->consumerParam_s.Handle = (U32)PPCtrlBlock_p;
		TempPPBlock->consumerParam_s.sem    = PPCtrlBlock_p->PPControlBlock.PPTaskSem_p;

		/* Register to memory block manager as a consumer */
		PPCtrlBlock_p->PPControlBlock.InMemoryBlockManagerHandle=InitParams->InBufHandle;

		/*Register Later at Start
		error |= MemPool_RegConsumer(PPCtrlBlock_p->PPControlBlock.InMemoryBlockManagerHandle,TempPPBlock->consumerParam_s);
		*/

		/* As Producer of outgoing data */
		TempPPBlock->ProducerParam_s.Handle = (U32)PPCtrlBlock_p;
		TempPPBlock->ProducerParam_s.sem    = PPCtrlBlock_p->PPControlBlock.PPTaskSem_p;
		/* Register to memory block manager as a Producer */
		PPCtrlBlock_p->PPControlBlock.OutMemoryBlockManagerHandle=InitParams->OutBufHandle;

		/*Register at start
		error |= MemPool_RegProducer(PPCtrlBlock_p->PPControlBlock.OutMemoryBlockManagerHandle, TempPPBlock->ProducerParam_s);
		*/

		memset((void *)(&PPCtrlBlock_p->PPControlBlock.StartParams),0,sizeof(STAud_PPStartParams_t));
		/* Update the intitialized PP queue with current control block */
		PPCtrlBlock_p->PPControlBlock.NumChannels = InitParams->NumChannels;
		STAud_PPQueueAdd(PPCtrlBlock_p);

	}
	else
	{
		/* PP already initialized. */
		error = ST_ERROR_ALREADY_INITIALIZED;
	}

	return error;
}

/******************************************************************************
 *  Function name 	: STAud_PPTerm
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: This function will terminate the PP task, Free MME PPs's In/out
 * 				  paramaters and will update main HAL structure with current values
 ***************************************************************************** */
ST_ErrorCode_t 	STAud_PPTerm(STAud_PPHandle_t		Handle)
{
	/* Local Variable */
	ST_ErrorCode_t 			error = ST_NO_ERROR;
	PPControlBlockList_t		*PP_p;
	partition_t 				*DriverPartition = NULL;
	task_t					*TempTask_p;

	/* Obtain the PP control block associated with the device name */
	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		/* handle not found */
		return ST_ERROR_INVALID_HANDLE;
	}
		/* Terminate Decoder Task */
	TempTask_p = PP_p->PPControlBlock.PPTask;

	error = STAud_PPCheckState(MME_PP_STATE_TERMINATE, &PP_p->PPControlBlock);
	if(error == STAUD_ERROR_INVALID_STATE)
	{
		STTBX_PRINTError(("STAud_PPTerm: STAUD_ERROR_INVALID_STATE !!!\n "));
		return error;
	}

	SendCommand(MME_PP_STATE_TERMINATE, &PP_p->PPControlBlock);

	STOS_TaskWait(&TempTask_p,TIMEOUT_INFINITY);
       STOS_TaskDelete(TempTask_p,NULL,NULL,NULL);

	DriverPartition = PP_p->PPControlBlock.InitParams.DriverPartition;

	/* Free PP queue Structures */
	DeInitPPQueueInParam(PP_p->PPControlBlock);
	DeInitPPQueueOutParam(PP_p->PPControlBlock);


	memory_deallocate(DriverPartition, PP_p->PPControlBlock.MMEinitParams.TransformerInitParams_p);

	/* Terminate PP Semaphore */
	STOS_SemaphoreDelete(NULL,PP_p->PPControlBlock.PPTaskSem_p);
	/* Delete Mutex */
	STOS_MutexDelete(PP_p->PPControlBlock.LockControlBlockMutex_p);

	STOS_SemaphoreDelete(NULL,PP_p->PPControlBlock.CmdCompletedSem_p);



	/* Remove the Control Block from Queue */
	STAud_PPQueueRemove(PP_p);

	/*Free the Control Block */

	memory_deallocate(DriverPartition,PP_p);

	return ST_NO_ERROR;
}


/******************************************************************************
 *  Function name 	: STAud_PPOpen
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: This function will Open the PP
 ***************************************************************************** */
ST_ErrorCode_t 	STAud_PPOpen(const ST_DeviceName_t DeviceName,
									STAud_PPHandle_t *Handle)
{

	PPControlBlockList_t	*PP_p;

	/* Get the desired control block */
	PP_p = STAud_PPGetControlBlockFromName(DeviceName);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	/* Check nobody else has already opened it */
        if (PP_p->PPControlBlock.Handle == 0)
       {
		/* Set and return Handle */
		PP_p->PPControlBlock.Handle = (STAud_PPHandle_t)PP_p;
		*Handle = PP_p->PPControlBlock.Handle;
	}

	return ST_NO_ERROR;
}


/******************************************************************************
 *  Function name 	: STAud_PPClose
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: This function will close the task
 ***************************************************************************** */
ST_ErrorCode_t 	STAud_PPClose()
{
	/* Noting to do in Close*/
	return ST_NO_ERROR;
}

/******************************************************************************
 *  Function name 	: STAud_PPStart
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: This function will send init and play cmd to PP Task. This
 *  				   function should be called from DRStart() function
 ***************************************************************************** */
ST_ErrorCode_t 	STAud_PPStart(STAud_PPHandle_t		Handle,  STAud_PPStartParams_t *StartParams_p)
{
	ST_ErrorCode_t	Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t *PPControlBlock_p;
	U8 i,j;
	U32 OutPageSize=1;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		/* handle not found */
		return ST_ERROR_INVALID_HANDLE;
	}

	PPControlBlock_p = &PP_p->PPControlBlock;
	/* Check current PP State. */
	Error = STAud_PPCheckState(MME_PP_STATE_START, PPControlBlock_p);
	if(Error == STAUD_ERROR_INVALID_STATE)
	{
		STTBX_PRINTError(("STAud_PPStart: STAUD_ERROR_INVALID_STATE !!!\n "));
		return Error;
	}

	/*Register here*/
	if(PPControlBlock_p->InMemoryBlockManagerHandle)
	{
		Error |= MemPool_RegConsumer(PPControlBlock_p->InMemoryBlockManagerHandle,PPControlBlock_p->consumerParam_s);
	}

	if(PPControlBlock_p->OutMemoryBlockManagerHandle)
	{
		Error |= MemPool_RegProducer(PPControlBlock_p->OutMemoryBlockManagerHandle, PPControlBlock_p->ProducerParam_s);
	}


	/* Init callback data as Handle. It will help us find the PP from list of PPs in multi instance mode */
	PPControlBlock_p->MMEinitParams.CallbackUserData = (void *)(PPControlBlock_p->Handle);

	/*If downsampling is enabled then set only input frequency */
	if(PPControlBlock_p->StartParams.OutPutFrequency && PPControlBlock_p->DownSamplingEnabled == TRUE)
	{
		PPControlBlock_p->StartParams.InputFrequency=StartParams_p->Frequency;
	}
	else
	{
		PPControlBlock_p->StartParams.OutPutFrequency=PPControlBlock_p->StartParams.InputFrequency=StartParams_p->Frequency;
	}


	/*Copy Rest variable of start Parameters */
	// The NumChannels will be already there from the init params
	PPControlBlock_p->StartParams.Frequency=StartParams_p->Frequency;
	PPControlBlock_p->StartParams.NumChannels = PPControlBlock_p->NumChannels;

	OutPageSize=(MAX_SAMPLES_PER_FRAME*(PPControlBlock_p->NumChannels + 1)*4);
	/*Put the max size for the Output ScatterPage*/
	/*Fill the Output ScatterPage Size*/

	for(i = 0; i < PP_QUEUE_SIZE; i++)
      {
		  for(j=0;j<ACC_MIXER_OUTPUT_BUFFERS;j++)
		  {
				PPControlBlock_p->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->Size=OutPageSize;
				PPControlBlock_p->PPQueue[i].PPBufOut.BufferOut_p[j]->TotalSize=OutPageSize;
		  }
	  }

	/* Send the Start command to PP. */
	Error = SendCommand(MME_PP_STATE_START, PPControlBlock_p);

	//STOS_SemaphoreWait(PPControlBlock_p->CmdCompletedSem_p);

	return Error;
}

/******************************************************************************
 *  Function name 	: STAud_PPStop
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: This function will Send the Stop cmd to PP Task. This
 *  				   function should be called from DRStop() function
 ***************************************************************************** */
ST_ErrorCode_t 	STAud_PPStop(STAud_PPHandle_t		Handle)
{

	ST_ErrorCode_t	Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t *PPControlBlock_p;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		/* handle not found */
		return ST_ERROR_INVALID_HANDLE;
	}

	PPControlBlock_p = &PP_p->PPControlBlock;

	Error = STAud_PPCheckState(MME_PP_STATE_STOP, PPControlBlock_p);
	if(Error == STAUD_ERROR_INVALID_STATE)
	{
		STTBX_PRINTError(("STAud_PPStop: STAUD_ERROR_INVALID_STATE !!!\n "));
		return Error;
	}


	/* Send the Stop command to PP. */
	Error = SendCommand(MME_PP_STATE_STOP, PPControlBlock_p);

	STOS_SemaphoreWait(PPControlBlock_p->CmdCompletedSem_p);

	return Error;
}



/******************************************************************************
*						PP TASK										   *
******************************************************************************/
static MME_ERROR	StopPP(PPControlBlock_t	*ControlBlock);
/******************************************************************************
 *  Function name 	: PP_Task_Entry_Point
 *  Arguments    	:
 *       IN			:
 *       OUT    		: void
 *       INOUT		:
 *  Return       	: void
 *  Description   	: This function is the entry point for PP task. Ihe PP task will be in
 *  				   different states depending of the command received from upper/lower layers
 ***************************************************************************** */
void    PP_Task_Entry_Point(void* params)
{

	ST_ErrorCode_t Error = ST_NO_ERROR;
	MME_ERROR	Status;

	/* Get the PP control Block for this task */
	PPControlBlock_t	*ControlBlock = (PPControlBlock_t*)params;

	STOS_TaskEnter(params);
	while(1)
	{

		/* Wait on sema for start command */
		STOS_SemaphoreWait(ControlBlock->PPTaskSem_p);

		/* Check if some command is recevied. We check this by looking for next desired state of PP */
		if(ControlBlock->CurPPState != ControlBlock->NextPPState)
		{
			/* PP state need to be changed */
			STOS_MutexLock(ControlBlock->LockControlBlockMutex_p);
			ControlBlock->CurPPState = ControlBlock->NextPPState;
			STOS_MutexRelease(ControlBlock->LockControlBlockMutex_p);
		}

		switch(ControlBlock->CurPPState)
		{

			case MME_PP_STATE_IDLE:

				break;

			case MME_PP_STATE_UPDATE:
				Status = UpdatePPParams(ControlBlock);
				if(Status != MME_SUCCESS)
				{
					STTBX_PRINTError(("Audio PP :Update  failure\n"));
					break;
				}

				/* PP Initialized. Now Send Play Command to PP Task i.e. this task itself */
				Error = STAud_PPCheckState(MME_PP_STATE_PLAYING, ControlBlock);
				if(Error == ST_NO_ERROR)
				{
					SendCommand(MME_PP_STATE_PLAYING, ControlBlock);
				}
				else
				{
					STTBX_PRINTError(("MME_PP_STATE_UPDATE :Wrong State\n"));
				}
				break;


			case MME_PP_STATE_START:

				/* PP Initialized. Now Send Play Command to PP Task i.e. this task itself */
				Error = STAud_PPCheckState(MME_PP_STATE_PLAYING, ControlBlock);
				if(Error == ST_NO_ERROR)
				{
					SendCommand(MME_PP_STATE_PLAYING, ControlBlock);
				}
				else
				{
					STTBX_PRINTError(("From MME_PP_STATE_START to PLAYING :Wrong State\n"));
				}

				break;

			case MME_PP_STATE_PLAYING:

				/* Process incoming Data */
				if(ControlBlock->UpdateRequired == TRUE)
				{
					Status =UpdatePPParams(ControlBlock);
					if(Status != MME_SUCCESS)
					{
						STTBX_PRINTError(("Audio PP :Update  failure\n"));

					}
					else
					ControlBlock->UpdateRequired = FALSE;
				}
				Error = ProcessInput(ControlBlock);
				if(Error == ST_NO_ERROR)
				{
					STTBX_Print(("PP : Input Processed Success \n"));
				}
				else
				{
					STTBX_Print(("PP : Input Process Error = %d \n ", Error ));
				}

			break;

			case MME_PP_STATE_STOP:

				Error= StopPP(ControlBlock);

				Error = STAud_PPCheckState(MME_PP_STATE_STOPPED, ControlBlock);
				if(Error == ST_NO_ERROR)
				{
					SendCommand(MME_PP_STATE_STOPPED, ControlBlock);
				}
				else
				{
					STTBX_PRINTError(("From MME_PP_STATE_STOP to MME_PP_STATE_STOPPED :Wrong State\n"));
				}

			break;


			case MME_PP_STATE_TERMINATE:
				STOS_TaskExit(params);
#if defined( ST_OSLINUX )
                return;
#else
                task_exit(1);
#endif
			break;
			case MME_PP_STATE_STOPPED:
			case MME_PP_STATE_PAUSED:
			case MME_PP_STATE_TRICK:
			default:
				break;

		}

	}

}

static MME_ERROR	StopPP(PPControlBlock_t	*ControlBlock)
{
	MME_ERROR	Error=MME_SUCCESS;
	U32 count=1;
	PPInputBlocks_t *InputBlock;

	/* We should wait for both input queue and output queue to be freed before terminating the transformer*/
	while(ControlBlock->PPQueueFront != ControlBlock->PPQueueTail)
	{
#ifdef ST_OSWINCE
		Sleep(3);
#else
		AUD_TaskDelayMs(5); /* Gradually increase the sleep time as LX is not returning back */
#endif
		/* Make a bounded wait. */
		if((count/600))
		{
			/* We will come here only if LX is crashed so queueTails and Fronts will never be updated */
			/* Waited enough -- 5 * 600 = 3000ms = 3sec */
			STTBX_Print(("PPWaiting since %d ms \n",count*5 ));
			STTBX_Print(("PP::Wait Over, tail=%d, Front=%d \n", ControlBlock->PPQueueTail,ControlBlock->PPQueueFront));
			break;
		}
		count++;
	}

	/* If not able to get the Transform completed than Now we have some pb with current transfer abort it*/
#ifndef ST_OSLINUX
	if((ControlBlock->TranformHandlePP) && (ControlBlock->PPQueueFront != ControlBlock->PPQueueTail))
	{
		ControlBlock->CurrentBufferToOut = &ControlBlock->PPQueue[ControlBlock->PPQueueFront % PP_QUEUE_SIZE];
		Error = MME_AbortCommand(ControlBlock->TranformHandlePP,ControlBlock->CurrentBufferToOut->Cmd.CmdStatus.CmdId);
		AUD_TaskDelayMs(3);
	}
#endif
	if(ControlBlock->TranformHandlePP)
	{
		/* Try MME_TermTransformer few time as sometime LX return BUSY */
		Error = MME_TermTransformer(ControlBlock->TranformHandlePP);
	}

	if(Error != MME_SUCCESS)
	{
		STTBX_PRINTError(("ERROR!!!PostProcessor MME_TermTransformer::FAILED=0x%x \n",Error));
	}

	/* Return the input and output buffers to BM */
	ControlBlock->TranformHandlePP=0;
	ControlBlock->ForcedOutputSamples =0;

	memset((void *)&(ControlBlock->StartParams),0,sizeof(STAud_PPStartParams_t));
	/* Reset Decoder queues */
	ControlBlock->PPQueueFront = ControlBlock->PPQueueTail=0;
	ControlBlock->TargetBytes =0;
	ControlBlock->DownSamplingEnabled = FALSE;
	/*reset the Input States*/


	for(count=0;count<PP_QUEUE_SIZE;count++)
	{
		InputBlock=&ControlBlock->PPQueue[count].InputBlock;
		InputBlock->NumUsed=InputBlock->NumFreeBlock=InputBlock->TotalInputBytesNeededForTransform=
			InputBlock->TotalInputBytesRecevied=0;
		{
			/*Free the Input Block*/
			U32 j;
			for(j=0;j<INPUT_MAX_BLOCK_PER_TRANSFORM;j++)
			{
				InputBlock->PPInputBlock[j].InputBlockFromProducer=NULL;
				InputBlock->PPInputBlock[j].BytesUsed=0;
				InputBlock->PPInputBlock[j].FullyUsed=0;
			}
		}

	}
	ControlBlock->StartParams.InputFrequency=ControlBlock->StartParams.OutPutFrequency=0;

	/*Unregister here*/
	if(ControlBlock->InMemoryBlockManagerHandle)
	{
		Error |= MemPool_UnRegConsumer(ControlBlock->InMemoryBlockManagerHandle, ControlBlock->Handle);
	}

	if(ControlBlock->OutMemoryBlockManagerHandle)
	{
		Error |= MemPool_UnRegProducer(ControlBlock->OutMemoryBlockManagerHandle, ControlBlock->Handle);
	}

	/* Change PP states */

	ControlBlock->PPInState=MME_PP_INPUT_STATE_IDLE;
	ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_IDLE;

	STOS_SemaphoreSignal(ControlBlock->CmdCompletedSem_p);

	return Error;

}

/******************************************************************************
*						LOCAL FUNCTIONS										   *
******************************************************************************/
/******************************************************************************
 *  Function name 	: ProcessInput
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: Get the comressed input buffers, get empty PCM buffer,Update MME params
 *				   and send command to MME PP
 ***************************************************************************** */
ST_ErrorCode_t	ProcessInput(PPControlBlock_t	*ControlBlock)
{
	ST_ErrorCode_t		status = ST_NO_ERROR;
	U32					QueueTailIndex;

	switch(ControlBlock->PPInState)
	{
		case MME_PP_INPUT_STATE_IDLE:
			/* Intended fall through */
			ControlBlock->PPInState = MME_PP_INPUT_STATE_GET_OUTPUT_BUFFER;

		case MME_PP_INPUT_STATE_GET_OUTPUT_BUFFER:

			/* Get free output buffer */
			status = MemPool_GetOpBlk(ControlBlock->OutMemoryBlockManagerHandle,(U32 *)&ControlBlock->CurOutputBlockFromConsumer); // No Handle, ControlBlock->Handle);
			if(status != ST_NO_ERROR)	/* No  buffer available */
			{
				STTBX_Print(("ST Error=%d in output block manager \n",status));
				return status;
			}

			/* Intended fall through */
			ControlBlock->PPInState = MME_PP_GET_BUFFER_FROM_QUEUE;

		case MME_PP_GET_BUFFER_FROM_QUEUE:
			if(ControlBlock->PPQueueTail - ControlBlock->PPQueueFront < PP_QUEUE_SIZE)
			{
				QueueTailIndex = ControlBlock->PPQueueTail%PP_QUEUE_SIZE;
				ControlBlock->CurrentBufferToSend = &ControlBlock->PPQueue[QueueTailIndex];
				ControlBlock->CurrentBufferToSend->InputBlock.TotalInputBytesRecevied=0;
				ControlBlock->CurrentBufferToSend->InputBlock.TotalInputBytesNeededForTransform=0;
			}
			else
			{
					/* PP Queue Full */
				return ST_ERROR_NO_MEMORY;
			}

		ControlBlock->PPInState = MME_PP_INPUT_STATE_GET_INPUT_DATA;

		case MME_PP_INPUT_STATE_GET_INPUT_DATA:
			{

				U32 TargetBytes=0;
				U32 NumBlocks=0;
				U32 TotalBytesTaken=0;
				U32 Offset=0;
				U32 NumBytesInCurrentBlock;

				U32 NumBytesRemainingInCurrentBlock;
				PPCmdParam_t *CurrentBufferToSend ;
				PPInputBlocks_t *InputBlock;
				PPInBufParams_t *PPBufIn;
				/* Get the filled compressed buffer */

				TargetBytes=ControlBlock->TargetBytes;
				/*Set the target Bytes to some value , so that
				we can get the first block , to compute
				actual target bytes needed for one transform at input */
				if(!TargetBytes)
					TargetBytes=4*2;

				CurrentBufferToSend =  ControlBlock->CurrentBufferToSend;
				InputBlock = &CurrentBufferToSend->InputBlock;
				PPBufIn = &CurrentBufferToSend->PPBufIn;

				InputBlock->TotalInputBytesNeededForTransform=TargetBytes;
				TotalBytesTaken= InputBlock->TotalInputBytesRecevied;

				while(TargetBytes>TotalBytesTaken)
				{
					TargetBytes=ControlBlock->TargetBytes;
					TotalBytesTaken= InputBlock->TotalInputBytesRecevied;
					if(InputBlock->NumUsed >= INPUT_MAX_BLOCK_PER_TRANSFORM && InputBlock->NumFreeBlock ==0)
					{
						ControlBlock->GetDataState = MME_PP_INPUT_GET_DATA_IDLE;
						break;
					}
					switch(ControlBlock->GetDataState)
					{
					case MME_PP_INPUT_GET_DATA_IDLE:

						ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_CHECK_UNUSED_BLOCK;

					case MME_PP_INPUT_GET_DATA_CHECK_UNUSED_BLOCK:

						/*If we have any block in remaining then check for that
						and in the next transform mark it as Start*/
						STTBX_Print((" PP Use prev block \n"));
						/*NUmUsed is to indicate num of block */
						/*NumBlocks is index for array of PPInputBlock*/
						if(InputBlock->NumUsed!=
							InputBlock->NumFreeBlock)
						{

							NumBlocks=InputBlock->NumUsed;

							ControlBlock->CurInputBlockFromProducer=
								InputBlock->PPInputBlock[(NumBlocks-1)].InputBlockFromProducer;

							Offset=InputBlock->PPInputBlock[(NumBlocks-1)].BytesUsed;

							NumBytesInCurrentBlock=ControlBlock->CurInputBlockFromProducer->Size;

							NumBytesRemainingInCurrentBlock=NumBytesInCurrentBlock-Offset;

							// Mark this block as Start

							InputBlock->PPInputBlock[0]=InputBlock->PPInputBlock[NumBlocks-1];

							if(NumBlocks!=1)
							{
								InputBlock->PPInputBlock[NumBlocks-1].InputBlockFromProducer=NULL;
								InputBlock->PPInputBlock[NumBlocks-1].BytesUsed=0;
								InputBlock->PPInputBlock[NumBlocks-1].FullyUsed=TRUE;
							}

							NumBlocks=InputBlock->NumUsed=0;
							/*We got one block to use */

							InputBlock->NumUsed=1;
							InputBlock->NumFreeBlock=0;


							if(NumBytesRemainingInCurrentBlock>TargetBytes)
							{
							// More data in the block then expected //

								PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Page_p =
																					(void*)((char *)ControlBlock->CurInputBlockFromProducer->MemoryStart+Offset);

								PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Size =
																														TargetBytes;
								PPBufIn->BufferIn_p[0]->TotalSize = TargetBytes;

								InputBlock->PPInputBlock[NumBlocks].BytesUsed+=TargetBytes;

								InputBlock->PPInputBlock[NumBlocks].FullyUsed =FALSE;

								InputBlock->TotalInputBytesRecevied=TargetBytes;

								TotalBytesTaken=TargetBytes;

								ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_IDLE;
								break; // break the case


							}
							else
							{
								PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Page_p =
																					(void*)((char *)ControlBlock->CurInputBlockFromProducer->MemoryStart+Offset);

								PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Size =
																														NumBytesRemainingInCurrentBlock;

								PPBufIn->BufferIn_p[0]->TotalSize = NumBytesRemainingInCurrentBlock;

								InputBlock->PPInputBlock[NumBlocks].BytesUsed+=NumBytesRemainingInCurrentBlock;

								InputBlock->PPInputBlock[NumBlocks].FullyUsed =TRUE;

								InputBlock->TotalInputBytesRecevied=NumBytesRemainingInCurrentBlock;

								TotalBytesTaken+= NumBytesRemainingInCurrentBlock;

								if(NumBytesRemainingInCurrentBlock==TargetBytes)
								{
									ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_IDLE;
									break; // break the case
								}



							}

						}
						/*We have free all the blocks */
						else if (InputBlock->NumUsed==
							InputBlock->NumFreeBlock)
						{
							InputBlock->NumUsed=
							InputBlock->NumFreeBlock=0;
						}
						ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_NEW_BLOCK;



						case MME_PP_INPUT_GET_DATA_NEW_BLOCK:
							{

								STTBX_Print((" PP new Block \n"));
								/*Check if we have pending input */
								/*Check for the data if remaining in some Input
								At most we will be remaining with only One Input as Unused*/

								status = MemPool_GetIpBlk(ControlBlock->InMemoryBlockManagerHandle, (U32 *)&ControlBlock->CurInputBlockFromProducer,ControlBlock->Handle);
								if(status != ST_NO_ERROR)	/* No compressed buffer available */
								{
									STTBX_Print(("ST Error=%d in block manager \n",status));
									return status ;
								}

							/*We got the first frame do the Init*/
							if(!ControlBlock->TranformHandlePP)
							{
								U32 InputBytes;
								U32 InputSamples;
								MME_ERROR TransformerError=0;
								if(ControlBlock->CurInputBlockFromProducer->Flags&FREQ_VALID)
								{
									if(ControlBlock->DownSamplingEnabled == FALSE)
									ControlBlock->StartParams.InputFrequency=ControlBlock->StartParams.OutPutFrequency=
									ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];

									else
										ControlBlock->StartParams.InputFrequency=ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];

								}

								// else use the Input Frequency
								// calculate Output Number of Samples //
								InputBytes=ControlBlock->CurInputBlockFromProducer->Size;
								InputSamples=InputBytes/(ControlBlock->StartParams.NumChannels*4);

								TargetBytes = ControlBlock->TargetBytes=InputBytes;

								ControlBlock->StartParams.OutPutNbSamples=(InputSamples*ControlBlock->StartParams.OutPutFrequency)/
									ControlBlock->StartParams.InputFrequency;

								if(ControlBlock->ForcedOutputSamples)
								{
									ControlBlock->StartParams.OutPutNbSamples = 	ControlBlock->ForcedOutputSamples;
									if(ControlBlock->StartParams.OutPutFrequency!= 0 && ControlBlock->StartParams.InputFrequency!=0)
									{
										InputSamples =( ControlBlock->StartParams.OutPutNbSamples * ControlBlock->StartParams.InputFrequency)/
												(ControlBlock->StartParams.OutPutFrequency);
									}
									else
									{
										InputSamples = ControlBlock->StartParams.OutPutNbSamples;
									}
									TargetBytes = ControlBlock->TargetBytes = InputSamples *	(ControlBlock->StartParams.NumChannels)*4;
								}

								TransformerError = SetAndInitPP(ControlBlock);
								if(TransformerError!=MME_SUCCESS)
								{
									/*Error Handing */
									/*Put block Back */
									status =MemPool_FreeIpBlk(ControlBlock->InMemoryBlockManagerHandle, (U32 *)&ControlBlock->CurInputBlockFromProducer,ControlBlock->Handle);
									return TransformerError;

								}

							}

							else if ((ControlBlock->CurInputBlockFromProducer->Flags & LAYER_VALID )&&
								(ControlBlock->StartParams.OutPutNbSamples!=(ControlBlock->CurInputBlockFromProducer->Size/(ControlBlock->StartParams.NumChannels*4))))
							{

								U32 InputBytes;
								U32 InputSamples;
								MME_ERROR TransformerError=0;
								TransformerError=MME_TermTransformer(ControlBlock->TranformHandlePP);
								if(TransformerError!=MME_SUCCESS)
								{
									STTBX_PRINTError(("MME Term Failed in Layer Update Error =%d ", TransformerError));
									return TransformerError;
								}

								if(ControlBlock->CurInputBlockFromProducer->Flags & FREQ_VALID )
								{
									if(ControlBlock->DownSamplingEnabled == FALSE)
										ControlBlock->StartParams.InputFrequency=ControlBlock->StartParams.OutPutFrequency=
										ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];
									else
										ControlBlock->StartParams.InputFrequency=ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];

								}

								InputBytes=ControlBlock->CurInputBlockFromProducer->Size;
								InputSamples=InputBytes/(ControlBlock->StartParams.NumChannels*4);


								TargetBytes = ControlBlock->TargetBytes=InputBytes;

								ControlBlock->StartParams.OutPutNbSamples=(InputSamples*ControlBlock->StartParams.OutPutFrequency)/
									ControlBlock->StartParams.InputFrequency;

								if(ControlBlock->ForcedOutputSamples)
								{
									ControlBlock->StartParams.OutPutNbSamples = 	ControlBlock->ForcedOutputSamples;
									if(ControlBlock->StartParams.OutPutFrequency!= 0 && ControlBlock->StartParams.InputFrequency!=0)
									{
										InputSamples =( ControlBlock->StartParams.OutPutNbSamples * ControlBlock->StartParams.InputFrequency)/
												(ControlBlock->StartParams.OutPutFrequency);
									}
									else
									{
										InputSamples = ControlBlock->StartParams.OutPutNbSamples;
									}
									TargetBytes = ControlBlock->TargetBytes = InputSamples *	(ControlBlock->StartParams.NumChannels)*4;
								}

								TransformerError= SetAndInitPP(ControlBlock);
								if(TransformerError!=MME_SUCCESS)
								{
									status =MemPool_FreeIpBlk(ControlBlock->InMemoryBlockManagerHandle, (U32 *)&ControlBlock->CurInputBlockFromProducer,ControlBlock->Handle);
									return TransformerError;
								}
							}



							// Change of Input Frequency in run time
								else if((ControlBlock->StartParams.InputFrequency!=ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET])&&
									(ControlBlock->CurInputBlockFromProducer->Flags&FREQ_VALID))
								{
									U32 InputBytes;
									U32 InputSamples;
									MME_ERROR TransformerError=0;
									TransformerError= MME_TermTransformer(ControlBlock->TranformHandlePP);
									if(TransformerError!=MME_SUCCESS)
									{
										STTBX_PRINTError(("MME Term Failed in Freq Update Error =%d ", TransformerError));
										return TransformerError;
									}
									if(ControlBlock->DownSamplingEnabled == FALSE)
									ControlBlock->StartParams.InputFrequency=ControlBlock->StartParams.OutPutFrequency=
										ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];
									else
										ControlBlock->StartParams.InputFrequency= ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];

									InputBytes=ControlBlock->CurInputBlockFromProducer->Size;
									InputSamples=InputBytes/(ControlBlock->StartParams.NumChannels*4);
									TargetBytes = ControlBlock->TargetBytes=InputBytes;

									ControlBlock->StartParams.OutPutNbSamples=(InputSamples*ControlBlock->StartParams.OutPutFrequency)/
									ControlBlock->StartParams.InputFrequency;

									if(ControlBlock->ForcedOutputSamples)
									{
										ControlBlock->StartParams.OutPutNbSamples = 	ControlBlock->ForcedOutputSamples;
										if(ControlBlock->StartParams.OutPutFrequency!= 0 && ControlBlock->StartParams.InputFrequency!=0)
										{
											InputSamples =( ControlBlock->StartParams.OutPutNbSamples * ControlBlock->StartParams.InputFrequency)/
													(ControlBlock->StartParams.OutPutFrequency);
										}
										else
										{
											InputSamples = ControlBlock->StartParams.OutPutNbSamples;
										}
										TargetBytes = ControlBlock->TargetBytes = InputSamples *	(ControlBlock->StartParams.NumChannels)*4;
									}

									TransformerError= SetAndInitPP(ControlBlock);
									if(TransformerError!=MME_SUCCESS)
									{
										status =MemPool_FreeIpBlk(ControlBlock->InMemoryBlockManagerHandle, (U32 *)&ControlBlock->CurInputBlockFromProducer,ControlBlock->Handle);
										return TransformerError;
									}


								}
								else if((ControlBlock->GlobalPcmParams->InConfig.Config[0].AudioMode!=( enum eAccAcMode	)ControlBlock->CurInputBlockFromProducer->Data[CODING_OFFSET])&&
									(ControlBlock->CurInputBlockFromProducer->Flags&MODE_VALID))
								{

									U8 Count =0;
									for(Count =0; Count <=100; Count ++ )
									{
										if(ControlBlock->PPQueueTail== ControlBlock->PPQueueFront)
											break;
										else
											AUD_TaskDelayMs(1);
									}
									/*if not waiting for current transfer to complete
									than updating it some times causes zero o/p*/
									ControlBlock->GlobalPcmParams->InConfig.Config[0].AudioMode= ( enum eAccAcMode	)ControlBlock->CurInputBlockFromProducer->Data[CODING_OFFSET];
									UpdatePPParams(ControlBlock);

								}
								if ((ControlBlock->StartParams.OutPutNbSamples!=(ControlBlock->CurInputBlockFromProducer->Size/(ControlBlock->StartParams.NumChannels*4)))&&
									(ControlBlock->ForcedOutputSamples ==0))
								{

									U32 InputBytes;
									U32 InputSamples;

									if(ControlBlock->CurInputBlockFromProducer->Flags & FREQ_VALID )
									{
										if(ControlBlock->DownSamplingEnabled == FALSE)
											ControlBlock->StartParams.InputFrequency=ControlBlock->StartParams.OutPutFrequency=
											ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];
										else
											ControlBlock->StartParams.InputFrequency=ControlBlock->CurInputBlockFromProducer->Data[FREQ_OFFSET];

									}

									InputBytes=ControlBlock->CurInputBlockFromProducer->Size;
									InputSamples=InputBytes/(ControlBlock->StartParams.NumChannels*4);


									TargetBytes = ControlBlock->TargetBytes=InputBytes;

									ControlBlock->StartParams.OutPutNbSamples=(InputSamples*ControlBlock->StartParams.OutPutFrequency)/
										ControlBlock->StartParams.InputFrequency;
									/*Update output number of samples*/
									ControlBlock->OutConfig->NbOutputSamplesPerTransform = ControlBlock->StartParams.OutPutNbSamples;

									UpdatePPParams(ControlBlock);
								}


								if (ControlBlock->CurInputBlockFromProducer->Flags>1)
									STTBX_Print((" PP flag = %d \n ",ControlBlock->CurInputBlockFromProducer->Flags));

								NumBlocks=InputBlock->NumUsed;

								NumBytesInCurrentBlock=ControlBlock->CurInputBlockFromProducer->Size;

								NumBytesRemainingInCurrentBlock=NumBytesInCurrentBlock;

								//STTBX_Print(("PP Size =%d\n", NumBytesInCurrentBlock));

								// Fill a new Block



								InputBlock->PPInputBlock[NumBlocks].InputBlockFromProducer=ControlBlock->CurInputBlockFromProducer;
								InputBlock->PPInputBlock[NumBlocks].BytesUsed=0;
								InputBlock->PPInputBlock[NumBlocks].FullyUsed=FALSE;
								InputBlock->NumUsed++;



								if((NumBytesRemainingInCurrentBlock+ TotalBytesTaken)>TargetBytes)
								{
								// More data in the block then expected //

									PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Page_p =
																						(void*)((char *)ControlBlock->CurInputBlockFromProducer->MemoryStart);

									PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Size =
																															(TargetBytes-TotalBytesTaken);

									PPBufIn->BufferIn_p[0]->TotalSize += (TargetBytes-TotalBytesTaken);

								//	STTBX_Print(("PP 1 , Tar B= %d , Total Bytes = %d \n", TargetBytes,TotalBytesTaken));

									InputBlock->PPInputBlock[NumBlocks].BytesUsed=(TargetBytes-TotalBytesTaken);

									InputBlock->PPInputBlock[NumBlocks].FullyUsed =FALSE;

									InputBlock->TotalInputBytesRecevied+=(TargetBytes-TotalBytesTaken);

									TotalBytesTaken=TargetBytes;

									ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_IDLE;
									break; // break the case


								}
								else
								{
									PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Page_p =
																						(void*)((char *)ControlBlock->CurInputBlockFromProducer->MemoryStart);

									PPBufIn->BufferIn_p[0]->ScatterPages_p[NumBlocks].Size =NumBytesRemainingInCurrentBlock;

									PPBufIn->BufferIn_p[0]->TotalSize += NumBytesRemainingInCurrentBlock;

									//STTBX_Print(("PP 2 , Tar B= %d , Total Bytes = %d \n", TargetBytes,TotalBytesTaken));

									InputBlock->PPInputBlock[NumBlocks].BytesUsed+=NumBytesRemainingInCurrentBlock;

									InputBlock->PPInputBlock[NumBlocks].FullyUsed =TRUE;

									InputBlock->TotalInputBytesRecevied+=NumBytesRemainingInCurrentBlock;
									TotalBytesTaken+=NumBytesRemainingInCurrentBlock;
									if(TotalBytesTaken==TargetBytes)
									{
										ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_IDLE;
										break; // break the case
									}


									ControlBlock->GetDataState=MME_PP_INPUT_GET_DATA_NEW_BLOCK;

								}
							}

							default:
								break;
						}
					}
				}
				ControlBlock->PPInState = MME_PP_INPUT_STATE_UPDATE_PP_PARAMS;

				case MME_PP_INPUT_STATE_UPDATE_PP_PARAMS:
					{
						/* Update PP command Paramters */

						/* Get tail of PP Queue. We will add this input & output block there */
						PPCmdParam_t *CurrentBufferToSend;
						PPInBufParams_t *PPBufIn;
						PPInputBlocks_t *InputBlock;
						CurrentBufferToSend = ControlBlock->CurrentBufferToSend;
						PPBufIn = &CurrentBufferToSend->PPBufIn;
						InputBlock = &CurrentBufferToSend->InputBlock;





							/* Set the input buffer pointers ==> Since We have only one Input For debug*/
			/*				memset((void *)ControlBlock->CurInputBlockFromProducer->MemoryStart,0,(void*)ControlBlock->CurInputBlockFromProducer->Size);*/

							CurrentBufferToSend->BufferPtrs[0] = PPBufIn->BufferIn_p[0];
							CurrentBufferToSend->BufferPtrs[0]->NumberOfScatterPages=
								InputBlock->NumUsed;

							/* Set the output buffer pointers Since One Output*/
							CurrentBufferToSend->PPBufOut.BufferOut_p[0]->ScatterPages_p->Page_p =
																		(void*)ControlBlock->CurOutputBlockFromConsumer->MemoryStart;

							CurrentBufferToSend->PPBufOut.BufferOut_p[0]->ScatterPages_p->BytesUsed=0;

							/*Below memset is just for debug */
			/*				memset((void *)ControlBlock->CurOutputBlockFromConsumer->MemoryStart,0xff,MAX_SAMPLES_PER_FRAME*2*4);*/
							CurrentBufferToSend->BufferPtrs[1] = ControlBlock->CurrentBufferToSend->PPBufOut.BufferOut_p[0];

							/* update command params */
							/*To check wheather it will give the correct command ID or not -- to Do UK */
							status = acc_setAudioMixerTransformCmd(&CurrentBufferToSend->Cmd,
																&CurrentBufferToSend->PPTransformParams,
																			sizeof (MME_LxMixerTransformerFrameDecodeParams_t),
																			&ControlBlock->CurrentBufferToSend->PPFrameStatus,
																			sizeof (MME_LxMixerTransformerFrameDecodeStatusParams_t),
																			ControlBlock->CurrentBufferToSend->BufferPtrs,
																			ACC_CMD_PLAY);

							/* Copy Current In/Out memory buffers as we will have to copy Inputs buffers prams(PTS etc) to Output
							side, after PPoding is done */
							//ControlBlock->CurrentBufferToSend->InputBlockFromProducer = ControlBlock->CurInputBlockFromProducer;
							CurrentBufferToSend->OutputBlockFromConsumer = ControlBlock->CurOutputBlockFromConsumer;

							/* Update PP tail */
							ControlBlock->PPQueueTail++;


					/* Intended fall through */
					ControlBlock->PPInState = MME_PP_INPUT_STATE_SEND_TO_MME;
				}

		case MME_PP_INPUT_STATE_SEND_TO_MME:
			/* Send MME command to LX */

			STTBX_Print(("In Size %d \n",ControlBlock->CurrentBufferToSend->PPBufIn.BufferIn_p[0]->TotalSize));
	        status = MME_SendCommand(ControlBlock->TranformHandlePP, &ControlBlock->CurrentBufferToSend->Cmd);

			ControlBlock->CurrentBufferToSend = NULL;

			/* Change State to IDLE */
			ControlBlock->PPInState = MME_PP_INPUT_STATE_IDLE;
			break;
		default:
			break;
	}
	return status;
}

/******************************************************************************
 *  Function name 	: ProcessOutput
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: Send the PPoded data to next unit
 ***************************************************************************** */
ST_ErrorCode_t	ProcessOutput(PPControlBlock_t	*ControlBlock, U32 BytesUsed)
{

	ST_ErrorCode_t Error=ST_NO_ERROR;
	MemoryBlock_t	*InputBlockFromProducer;
	U8 NumBlockused;
	U8 i=0;
	PPCmdParam_t	*CurrentBufferToOut;
	PPInputBlocks_t	*InputBlock;
	PPInBufParams_t    *PPBufIn;

	/* Check if there is data to be sent to output */
	if(ControlBlock->PPQueueFront != ControlBlock->PPQueueTail)
	{
		CurrentBufferToOut = &ControlBlock->PPQueue[ControlBlock->PPQueueFront % PP_QUEUE_SIZE];
		NumBlockused=CurrentBufferToOut->InputBlock.NumUsed;
		InputBlock = &CurrentBufferToOut->InputBlock;
		PPBufIn 	 = &CurrentBufferToOut->PPBufIn;

		for(i=0;i<NumBlockused;i++)
		{
			InputBlockFromProducer= InputBlock->PPInputBlock[i].InputBlockFromProducer;
			// Check for Flags
			CurrentBufferToOut->OutputBlockFromConsumer->Flags|=
					InputBlockFromProducer->Flags;

			if(InputBlockFromProducer->Flags&PTS_VALID)
			{
				U32 ExtrapolatedPTS=0;
				U32 SizeOfBlockUsed=0;
				U32 TotalSizeofBlock=0;
				/*Get the start point of buffer 0 */
				if(i==0)
				{
					U32 SizeOfBlockUsedInPrevTransform=0;
					U32 TimeRequiredToplayPrevTransform=0;
					SizeOfBlockUsed = PPBufIn->BufferIn_p[0]->ScatterPages_p[0].Size;

					TotalSizeofBlock = InputBlockFromProducer->Size;

					SizeOfBlockUsedInPrevTransform = TotalSizeofBlock -SizeOfBlockUsed;

					TimeRequiredToplayPrevTransform = (SizeOfBlockUsedInPrevTransform*1000)/((ControlBlock->StartParams.NumChannels*4)*(ControlBlock->StartParams.OutPutFrequency)); /*in ms*/

					TimeRequiredToplayPrevTransform = TimeRequiredToplayPrevTransform *90 ; /*Value of Block in PTS already played*/
					/*So we have to increase PTS by this value*/
					ExtrapolatedPTS += TimeRequiredToplayPrevTransform ;
				}
				else
				{
					U32 TimeRequiredToPlayOtherBlocksForCurrentTransfer=0;
					U32 TimeRequiredToplayFirstBlock=0;

					TimeRequiredToPlayOtherBlocksForCurrentTransfer =
						((i-1)*InputBlockFromProducer->Size*1000)/((ControlBlock->StartParams.NumChannels*4)*(ControlBlock->StartParams.OutPutFrequency)); /*in ms*/
					/*Check the TimeRequired to PlayFirst Block */
					SizeOfBlockUsed =
					PPBufIn->BufferIn_p[0]->ScatterPages_p[0].Size;

					TimeRequiredToplayFirstBlock = (SizeOfBlockUsed*1000)/((ControlBlock->StartParams.NumChannels*4)*(ControlBlock->StartParams.OutPutFrequency)); /*in ms*/
					TimeRequiredToPlayOtherBlocksForCurrentTransfer+=TimeRequiredToplayFirstBlock;
					TimeRequiredToPlayOtherBlocksForCurrentTransfer = TimeRequiredToPlayOtherBlocksForCurrentTransfer*90;
					ExtrapolatedPTS -=TimeRequiredToPlayOtherBlocksForCurrentTransfer;

				}

#if 1
				CurrentBufferToOut->OutputBlockFromConsumer->Data[PTS_OFFSET] =
				InputBlockFromProducer->Data[PTS_OFFSET];
				CurrentBufferToOut->OutputBlockFromConsumer->Data[PTS33_OFFSET] =
				InputBlockFromProducer->Data[PTS33_OFFSET];

#else
				ControlBlock->CurrentBufferToOut->OutputBlockFromConsumer->Data[PTS_OFFSET] =
				ExtrapolatedPTS;
#endif
			}
			if(InputBlockFromProducer->Flags&FREQ_VALID)
			{
				CurrentBufferToOut->OutputBlockFromConsumer->Data[FREQ_OFFSET] =
					ControlBlock->StartParams.OutPutFrequency;

			}
		}




		CurrentBufferToOut->OutputBlockFromConsumer->Size = BytesUsed;

		/* Send output block to next unit(Consumer)*/
		Error=MemPool_PutOpBlk(ControlBlock->OutMemoryBlockManagerHandle ,
						(U32 *)&CurrentBufferToOut->OutputBlockFromConsumer);
		if(Error!=ST_NO_ERROR)
		{
			STTBX_PRINTError(("Post processor Memory block put error \n "));
		}


#if DUMP_OUTPUT_TO_FILE

		{
			static U32 index;
			char *temp;
			temp = (OutBuf+index);
			memcpy((void*)temp,(void*)CurrentBufferToOut->OutputBlockFromConsumer->MemoryStart,SIZE_MPEG_AUDIO_FRAME_BYTES);
			index+=SIZE_MPEG_AUDIO_FRAME_BYTES;
			if(index >= SIZE_MPEG_AUDIO_FRAME_BYTES*(FRAMES-1))
			{
				static FILE *f1 = NULL;
				if(f1==NULL)
					f1 = fopen("C:\\PP.dat","wb");
				fwrite(OutBuf, SIZE_MPEG_AUDIO_FRAME_BYTES*(FRAMES-1),1,f1);
			}
		}

#endif

		/* Free the input block */
		/*Check for number of free Blocks */

		for(i=0;i<NumBlockused;i++)
		{

			InputBlockFromProducer=
				InputBlock->PPInputBlock[i].InputBlockFromProducer;

			if((InputBlock->PPInputBlock[i].BytesUsed==
				InputBlockFromProducer->Size) &&
				InputBlock->PPInputBlock[i].FullyUsed==TRUE)
			{

					Error|=MemPool_FreeIpBlk(ControlBlock->InMemoryBlockManagerHandle,
					(U32 *)&InputBlockFromProducer,
					ControlBlock->Handle);

					if(Error!=ST_NO_ERROR)
					{
						STTBX_PRINTError(("Post processor Memory block Free \n "));
					}
					else
					{
						CurrentBufferToOut->InputBlock.NumFreeBlock++;
					}
					STTBX_Print(("PP IP_Free:%5u\n ", ControlBlock->PPQueueFromMME));
					ControlBlock->PPQueueFromMME++;
			}
			else
			{
					STTBX_Print(("PP No free:%5u,BytesUsed=%d,Size=%d,FullyUsed=%d\n ", ControlBlock->PPQueueFromMME,
					InputBlock->PPInputBlock[i].BytesUsed,InputBlockFromProducer->Size,
					InputBlock->PPInputBlock[i].FullyUsed));
			}

		}
		InputBlock->TotalInputBytesNeededForTransform=0;
		PPBufIn->BufferIn_p[0]->TotalSize=0;

		/* update queue front */
		ControlBlock->PPQueueFront++;
	}

	return Error;
}

void STAud_SetEqparams(MME_EqualizerGlobalParams_t *Equalizer,MME_EqualizerGlobalParams_t val )
{
	Equalizer->Id = ACC_RENDERER_EQUALIZER_ID;
	Equalizer->StructSize = sizeof(MME_EqualizerGlobalParams_t);

	Equalizer->Config[EQ_BAND_0] = val.Config[EQ_BAND_0];
	Equalizer->Config[EQ_BAND_1] = val.Config[EQ_BAND_1];
	Equalizer->Config[EQ_BAND_2] = val.Config[EQ_BAND_2];
	Equalizer->Config[EQ_BAND_3] = val.Config[EQ_BAND_3];
	Equalizer->Config[EQ_BAND_4] = val.Config[EQ_BAND_4];
	Equalizer->Config[EQ_BAND_5] = val.Config[EQ_BAND_5];
	Equalizer->Config[EQ_BAND_6] = val.Config[EQ_BAND_6];
	Equalizer->Config[EQ_BAND_7] = val.Config[EQ_BAND_7];
	Equalizer->Enable = val.Enable;
	Equalizer->Apply = val.Apply;
}

void	STAud_SetDelayparams(MME_DelayGlobalParams_t *Delay,MME_DelayGlobalParams_t val )
{

	Delay->Id = ACC_RENDERER_DELAY_ID;
	Delay->StructSize = sizeof(MME_DelayGlobalParams_t);
	Delay->Apply = val.Apply;
	Delay->DelayUpdate = val.DelayUpdate;
	Delay->Delay[ACC_MAIN_LEFT ]  = val.Delay[ACC_MAIN_LEFT ];
	Delay->Delay[ACC_MAIN_RGHT ]  = val.Delay[ACC_MAIN_RGHT ];
	Delay->Delay[ACC_MAIN_CNTR ]  = val.Delay[ACC_MAIN_CNTR ];
	Delay->Delay[ACC_MAIN_LFE  ]  = val.Delay[ACC_MAIN_LFE ];
	Delay->Delay[ACC_MAIN_LSUR ]  = val.Delay[ACC_MAIN_LSUR ];
	Delay->Delay[ACC_MAIN_RSUR ]  = val.Delay[ACC_MAIN_RSUR ];
	Delay->Delay[ACC_MAIN_CSURL]  = val.Delay[ACC_MAIN_CSURL ];
	Delay->Delay[ACC_MAIN_CSURR]  = val.Delay[ACC_MAIN_CSURR ];

}
void STAud_SetBassMgtGlobalParams(MME_BassMgtGlobalParams_t *BassMgt, MME_BassMgtGlobalParams_t val)
{
	U32 i = 0;
	BassMgt->Id=ACC_RENDERER_BASSMGT_ID;   //!< ID of this processing
	BassMgt->StructSize=sizeof(MME_BassMgtGlobalParams_t);
	BassMgt->Apply=val.Apply;
	for(i=0;i<BASSMGT_NB_CONFIG_ELEMENTS;i++)
	{
		BassMgt->Config[i]=val.Config[i];
	}
	for(i=0;i<VOLUME_NB_CONFIG_ELEMENTS;i++)
	{
		BassMgt->Volume[i]=val.Volume[i];/*MAX_ACC_VOL; 0;*/
	}
	for(i=0;i<DELAY_NB_CONFIG_ELEMENTS;i++)
	{
		BassMgt->Delay[i]=val.Delay[i];
	}

	BassMgt->DelayUpdate=val.DelayUpdate;

}

void	STAud_SetDcrmGlobalParams(MME_DCRemoveGlobalParams_t *DcRemove, MME_DCRemoveGlobalParams_t val)
{

	DcRemove->Id=ACC_RENDERER_DCREMOVE_ID;               //!< ID of this processing
	DcRemove->StructSize=sizeof(MME_DCRemoveGlobalParams_t);
	DcRemove->Apply=val.Apply;;

}
void STAud_SetTempoparams(MME_TempoGlobalParams_t *TempoControl, MME_TempoGlobalParams_t val)
{
	TempoControl->Id = ACC_RENDERER_TEMPO_ID;
	TempoControl->StructSize = sizeof(MME_TempoGlobalParams_t);
	TempoControl->Apply = ACC_MME_DISABLED;
	TempoControl->Ratio = val.Ratio=1; /*NO tempo at pp*/

}
void STAud_SetEncPPparams(MME_EncoderPPGlobalParams_t *EncControl, MME_EncoderPPGlobalParams_t val)
{
    EncControl->Id    = ACC_RENDERER_ENCODERPP_ID;
    EncControl->Apply = ACC_MME_DISABLED;
    EncControl->StructSize = sizeof(MME_EncoderPPGlobalParams_t);
}

void 	STAud_SetSFCPPparams(MME_SfcPPGlobalParams_t *SfcControl, MME_SfcPPGlobalParams_t val)
{
    SfcControl->Id          = ACC_RENDERER_SFC_ID;
    SfcControl->StructSize  = sizeof(MME_SfcPPGlobalParams_t);
    SfcControl->Apply       = ACC_MME_DISABLED;
}

void	STAud_SetLxMixerPCMParams( MME_LxPcmPostProcessingGlobalParameters_t *PcmParams, MME_LxPcmPostProcessingGlobalParameters_t val)
{

	PcmParams->StructSize = sizeof(MME_LxPcmPostProcessingGlobalParameters_t);
	PcmParams->Id = ACC_RENDERER_MIXER_POSTPROCESSING_ID;

	STAud_SetBassMgtGlobalParams(&PcmParams->BassMgt,val.BassMgt );
	STAud_SetDcrmGlobalParams(&PcmParams->DCRemove,val.DCRemove);
	STAud_SetEqparams(&PcmParams->Equalizer,val.Equalizer);
	STAud_SetDelayparams(&PcmParams->Delay,val.Delay);
	STAud_SetTempoparams(&PcmParams->TempoControl,val.TempoControl);
	STAud_SetEncPPparams(&PcmParams->Encoder,val.Encoder);
	STAud_SetSFCPPparams(&PcmParams->Sfc,val.Sfc);

}

void	STAud_SetLxMixerOutConfig(MME_LxMixerOutConfig_t *OutConfig,  STAud_PPStartParams_t StartParams)
{
	U32 NumSamplesAtInputFor32MS;
	OutConfig->StructSize = sizeof(MME_LxMixerOutConfig_t);
	OutConfig->Id = ACC_RENDERER_MIXER_OUTPUT_CONFIG_ID;

	NumSamplesAtInputFor32MS=(32 * StartParams.OutPutFrequency)/1000;
	OutConfig->NbOutputSamplesPerTransform=StartParams.OutPutNbSamples;

}
MME_ERROR	STAud_SetLxMixerInConfig(MME_LxMixerInConfig_t *InConfig,  STAud_PPStartParams_t StartParams)
{
	InConfig->StructSize = sizeof(MME_LxMixerInConfig_t);
	InConfig->Id = ACC_RENDERER_MIXER_ID;
	memset(InConfig->Config, 0x0, (sizeof(MME_MixerInputConfig_t)*ACC_MIXER_MAX_NB_INPUT));
	/* Set valid values for channel One */
	InConfig->Config[0].InputId = 0;
	InConfig->Config[0].Alpha =0xFFFF;

	if (StartParams.NumChannels==2)
	{
		InConfig->Config[0].AudioMode = ACC_MODE20;
	}
	else
	{
		InConfig->Config[0].AudioMode = ACC_MODE_ID;
	}

	InConfig->Config[0].AutoFade = ACC_MME_FALSE;
	InConfig->Config[0].FirstOutputChan = ACC_MAIN_LEFT;
	InConfig->Config[0].Mono2Stereo = ACC_MME_TRUE;
	InConfig->Config[0].NbChannels = StartParams.NumChannels;
	SetSamplingFrequency(StartParams.InputFrequency,&InConfig->Config[0].SamplingFreq);


	InConfig->Config[0].WordSize = ACC_WS32;

	/* Set ID for other inputs */
	InConfig->Config[1].InputId = 1;
	InConfig->Config[2].InputId = 2;
	InConfig->Config[3].InputId = 3;

	return MME_SUCCESS;
}

MME_ERROR	STAud_SetLxMixerTransformerGlobalParams(MME_LxMixerTransformerGlobalParams_t *GlobalParams,  STAud_PPStartParams_t StartParams,
													MME_LxMixerTransformerGlobalParams_t val)
{
	MME_ERROR	Error = MME_SUCCESS;

	GlobalParams->StructSize = sizeof(MME_LxMixerTransformerGlobalParams_t);

	STAud_SetLxMixerInConfig(&GlobalParams->InConfig,StartParams);
	STAud_SetLxMixerOutConfig(&GlobalParams->OutConfig,StartParams);
	STAud_SetLxMixerPCMParams(&GlobalParams->PcmParams,val.PcmParams);

	return Error;
}

MME_ERROR	STAud_SetMixerInitParam(MME_GenericParams_t	*init_param, STAud_PPStartParams_t StartParams, MME_LxMixerTransformerInitParams_t Val)
{
	MME_ERROR	Error = MME_SUCCESS;
	MME_LxMixerTransformerInitParams_t	*PP_Init;
	MME_LxMixerTransformerGlobalParams_t  GlobalVal;

	PP_Init = (MME_LxMixerTransformerInitParams_t	*)init_param;

	PP_Init->StructSize = sizeof(MME_LxMixerTransformerInitParams_t);
	PP_Init->CacheFlush = ACC_MME_ENABLED;
	PP_Init->NbInput = 1;


	PP_Init->MaxNbOutputSamplesPerTransform = MAX_SAMPLES_PER_FRAME;

	PP_Init->OutputNbChannels = StartParams.NumChannels;

	SetSamplingFrequency(StartParams.OutPutFrequency,&PP_Init->OutputSamplingFreq);

	GlobalVal=Val.GlobalParams;
	Error = STAud_SetLxMixerTransformerGlobalParams(&PP_Init->GlobalParams, StartParams,GlobalVal);

	return Error;
}
/******************************************************************************
 *  Function name 	: SetAndInitPP
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: MME_ERROR
 *  Description   	:
 ***************************************************************************** */
MME_ERROR	SetAndInitPP(PPControlBlock_t	*ControlBlock)
{
	MME_ERROR	Error;
//    U8 i=0;
	MME_LxMixerTransformerInitParams_t    *LXInit;
	/* CDS - Use common structure and function for Initial setup */

	LXInit=(MME_LxMixerTransformerInitParams_t *)ControlBlock->MMEinitParams.TransformerInitParams_p;

	STAud_SetMixerInitParam(ControlBlock->MMEinitParams.TransformerInitParams_p,ControlBlock->StartParams,*LXInit);
	/* Set the Other Pointer Values */
	/*Update the configuration, if recd from BM */
	ControlBlock->GlobalPcmParams=&LXInit->GlobalParams;
	ControlBlock->BassMgt=&ControlBlock->GlobalPcmParams->PcmParams.BassMgt;
	ControlBlock->Equalizer=&ControlBlock->GlobalPcmParams->PcmParams.Equalizer;
	ControlBlock->TempoControl=&ControlBlock->GlobalPcmParams->PcmParams.TempoControl;
	ControlBlock->DcRemove=&ControlBlock->GlobalPcmParams->PcmParams.DCRemove;
	ControlBlock->Delay=&ControlBlock->GlobalPcmParams->PcmParams.Delay;
	ControlBlock->OutConfig = &ControlBlock->GlobalPcmParams->OutConfig;

	if(ControlBlock->CurInputBlockFromProducer->Flags & MODE_VALID &&
		( enum eAccAcMode	)ControlBlock->CurInputBlockFromProducer->Data[CODING_OFFSET]!= ControlBlock->GlobalPcmParams->InConfig.Config[0].AudioMode)
	{
		ControlBlock->GlobalPcmParams->InConfig.Config[0].AudioMode = (enum eAccAcMode	)ControlBlock->CurInputBlockFromProducer->Data[CODING_OFFSET];

	}


	Error = MME_InitTransformer("MME_TRANSFORMER_TYPE_AUDIO_MIXER", &ControlBlock->MMEinitParams, &ControlBlock->TranformHandlePP);
		if(Error!=MME_SUCCESS)
		{
			STTBX_PRINTError(("PP MME_InitTransformer FAILED, Error =%d \n",Error));
			return Error;
		}
	STTBX_Print(("PP MME_InitTransformer SUCCESS \n"));

	return Error;
}

/******************************************************************************
 *  Function name 	: InitPPQueueInParams
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: Initalize PP queue params
 * 				  1. Allocate and initialize MME structure for input buffers
 *				  2. Allocate and initialize MME structure for Output buffers
 ***************************************************************************** */
ST_ErrorCode_t InitPPQueueInParams(	PPControlBlock_t	*TempPPBlock,
												STAVMEM_PartitionHandle_t AVMEMPartition)
{

	/* Local Variables */
	void				*VirtualAddress;
	STAVMEM_SharedMemoryVirtualMapping_t	VirtualMapping;
	STAVMEM_AllocBlockParams_t  			AllocParams;
	U32	i;
	U32 j;
	U32 k;
	ST_ErrorCode_t Error = ST_NO_ERROR;
	/**************** Initialize Input param ********************/
	STAVMEM_GetSharedMemoryVirtualMapping(&VirtualMapping);
	AllocParams.PartitionHandle = AVMEMPartition;
	AllocParams.Alignment = 32;
	AllocParams.AllocMode = STAVMEM_ALLOC_MODE_TOP_BOTTOM;
	AllocParams.ForbiddenRangeArray_p = NULL;
	AllocParams.ForbiddenBorderArray_p = NULL;
	AllocParams.NumberOfForbiddenRanges = 0;
	AllocParams.NumberOfForbiddenBorders = 0;
	AllocParams.Size = sizeof(MME_DataBuffer_t);
	for(i = 0; i < PP_QUEUE_SIZE; i++)
	{

		for(j=0;j<ACC_MIXER_NB_INPUT;j++)
		{
			Error = STAVMEM_AllocBlock(&AllocParams, &TempPPBlock->PPQueue[i].PPBufIn.BufferInHandle[j]);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}
			Error = STAVMEM_GetBlockAddress(TempPPBlock->PPQueue[i].PPBufIn.BufferInHandle[j], &VirtualAddress);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j] = STAVMEM_VirtualToCPU(VirtualAddress,&VirtualMapping);

		}

	}

	AllocParams.Size = sizeof(MME_ScatterPage_t)*ACC_MIXER_MAX_INPUT_PAGES_PER_STREAM;
	for(i = 0; i < PP_QUEUE_SIZE; i++)
	{
		for(j=0;j<ACC_MIXER_NB_INPUT;j++)
		{

			Error = STAVMEM_AllocBlock(&AllocParams, &TempPPBlock->PPQueue[i].PPBufIn.ScatterPageInHandle[j]);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}
			Error = STAVMEM_GetBlockAddress(TempPPBlock->PPQueue[i].PPBufIn.ScatterPageInHandle[j], &VirtualAddress);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}
			TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j]= STAVMEM_VirtualToCPU(VirtualAddress,&VirtualMapping);
		}
	}

	for(i = 0; i < PP_QUEUE_SIZE; i++)
	{
		/* We will set the Page_p to point to the compressed buffer, received from
		     Parser unit, in Process_Input function */
		for(j=0;j<ACC_MIXER_NB_INPUT;j++)
		{
			for(k=0;k<ACC_MIXER_MAX_INPUT_PAGES_PER_STREAM;k++)
			{
				TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j][k].Page_p = NULL;

				/* Data Buffers initialisation */
				TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j][k].Size = 0; /* update by the input buffer size*/
				TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j][k].BytesUsed = 0;
				TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j][k].FlagsIn = (U32)MME_DATA_CACHE_COHERENT;
				TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j][k].FlagsOut = 0;
			}
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->StructSize    = sizeof (MME_DataBuffer_t);
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->UserData_p    = NULL;
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->Flags         = 0;
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->StreamNumber  = 0;
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->NumberOfScatterPages = 1;
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->ScatterPages_p= TempPPBlock->PPQueue[i].PPBufIn.ScatterPageIn_p[j];
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->TotalSize     = TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->ScatterPages_p->Size;
			TempPPBlock->PPQueue[i].PPBufIn.BufferIn_p[j]->StartOffset   = 0;
		}

	}
	return ST_NO_ERROR;
}

/******************************************************************************
 *  Function name 	: InitPPQueueOutParams
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: Initalize PP queue params
 *				  1. Allocate and initialize MME structure for Output buffers
 ***************************************************************************** */
ST_ErrorCode_t InitPPQueueOutParams(PPControlBlock_t	*TempPPBlock,
												STAVMEM_PartitionHandle_t AVMEMPartition)
{

	/* Local Variables */

	void				*VirtualAddress;
	STAVMEM_SharedMemoryVirtualMapping_t	VirtualMapping;
	STAVMEM_AllocBlockParams_t  			AllocBlockParams;
	U32	i;
	U32 j;
	ST_ErrorCode_t Error = ST_NO_ERROR;

      STAVMEM_GetSharedMemoryVirtualMapping(&VirtualMapping);
  	AllocBlockParams.PartitionHandle = AVMEMPartition;
	AllocBlockParams.Alignment = 32;
	AllocBlockParams.AllocMode = STAVMEM_ALLOC_MODE_TOP_BOTTOM;
	AllocBlockParams.ForbiddenRangeArray_p = NULL;
	AllocBlockParams.ForbiddenBorderArray_p = NULL;
	AllocBlockParams.NumberOfForbiddenRanges = 0;
	AllocBlockParams.NumberOfForbiddenBorders = 0;
	AllocBlockParams.Size = sizeof(MME_DataBuffer_t);
	for(i = 0; i < PP_QUEUE_SIZE; i++)
	{
		for(j=0;j<ACC_MIXER_OUTPUT_BUFFERS;j++)
		{

			Error = STAVMEM_AllocBlock(&AllocBlockParams, &TempPPBlock->PPQueue[i].PPBufOut.BufferOutHandle[j]);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}

			Error = STAVMEM_GetBlockAddress(TempPPBlock->PPQueue[i].PPBufOut.BufferOutHandle[j], &VirtualAddress);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j] = STAVMEM_VirtualToCPU(VirtualAddress,&VirtualMapping);

		}
	}

	AllocBlockParams.Size = sizeof(MME_ScatterPage_t);
	for(i = 0; i < PP_QUEUE_SIZE; i++)
	{
		for(j=0;j<ACC_MIXER_OUTPUT_BUFFERS;j++)
		{
			Error = STAVMEM_AllocBlock(&AllocBlockParams, &TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOutHandle[j]);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}

			Error = STAVMEM_GetBlockAddress(TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOutHandle[j], &VirtualAddress);
			if(Error!=ST_NO_ERROR)
			{
				return Error;
			}
			TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j] = STAVMEM_VirtualToCPU(VirtualAddress,&VirtualMapping);
		}
	}

      for(i = 0; i < PP_QUEUE_SIZE; i++)
      {
		  for(j=0;j<ACC_MIXER_OUTPUT_BUFFERS;j++)
		  {
			/* We will set the Page_p to point to the Empty PCM buffer, received from
				Consumer unit, in Process_Input function */
			TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->Page_p = NULL;

			TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->Size = 0;
			/*update size at the time of Start depending upon the stream type */

			TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->BytesUsed = 0;
			TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->FlagsIn = (U32)MME_DATA_CACHE_COHERENT;
			TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->FlagsOut =0;
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->StructSize    = sizeof (MME_DataBuffer_t);
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->UserData_p    = NULL;
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->Flags         = 0;
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->StreamNumber  = 0;
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->NumberOfScatterPages = 1;
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->ScatterPages_p= TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j];
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->TotalSize     = TempPPBlock->PPQueue[i].PPBufOut.ScatterPageOut_p[j]->Size;
			TempPPBlock->PPQueue[i].PPBufOut.BufferOut_p[j]->StartOffset   = 0;

		  }
      }

	return ST_NO_ERROR;

}

void		InitPPTransformFrameParams(PPControlBlock_t *TempPPBlock)
{
	U32 i,j;

	for(i = 0; i < PP_QUEUE_SIZE; i++)
	{
		for(j=0;j<ACC_MIXER_NB_INPUT;j++)
		{
			TempPPBlock->PPQueue[i].PPTransformParams.InputParam[j].Command = ACC_CMD_PLAY;
			TempPPBlock->PPQueue[i].PPTransformParams.InputParam[j].StartOffset=0;
		}
		/*Init the status parames */
		TempPPBlock->PPQueue[i].PPFrameStatus.StructSize=sizeof(MME_LxMixerTransformerFrameDecodeStatusParams_t);
	}
}

/******************************************************************************
 *  Function name 	: DeInitPPQueueInParam
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: De allocate PP queue params
 *				  1. Deallocate Input buffers
 ***************************************************************************** */
static void	DeInitPPQueueInParam(PPControlBlock_t PPControlBlock)
{

	ST_ErrorCode_t 	Error=ST_NO_ERROR;
	STAVMEM_FreeBlockParams_t FreeBlockParams;
	U32		i;
	U32 j;
	STAVMEM_BlockHandle_t	ScatterPageInHandle,BufferInHandle;
	FreeBlockParams.PartitionHandle = PPControlBlock.InitParams.AVMEMPartition;

	for(i=0;i<PP_QUEUE_SIZE;i++)
	{
		for(j=0;j<ACC_MIXER_NB_INPUT;j++)
		{
			ScatterPageInHandle = 	PPControlBlock.PPQueue[i].PPBufIn.ScatterPageInHandle[j];
			Error = STAVMEM_FreeBlock(&FreeBlockParams,&ScatterPageInHandle);
			BufferInHandle = PPControlBlock.PPQueue[i].PPBufIn.BufferInHandle[j];
			Error = STAVMEM_FreeBlock(&FreeBlockParams,&BufferInHandle);
		}
	}
}

/******************************************************************************
 *  Function name 	: DeInitPPQueueOutParam
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: De allocate PP queue params
 *				  1. Deallocate output buffers
 ***************************************************************************** */
static void	DeInitPPQueueOutParam(PPControlBlock_t PPControlBlock)
{

	ST_ErrorCode_t 	Error=ST_NO_ERROR;
	STAVMEM_FreeBlockParams_t FreeBlockParams;
	U32		i;
	U32 j;
	STAVMEM_BlockHandle_t	ScatterPageHandle,BufferHandle;
	FreeBlockParams.PartitionHandle = PPControlBlock.InitParams.AVMEMPartition;
	for(i=0;i<PP_QUEUE_SIZE;i++)
	{
		for(j=0;j<ACC_MIXER_OUTPUT_BUFFERS;j++)
		{
			ScatterPageHandle = 	PPControlBlock.PPQueue[i].PPBufOut.ScatterPageOutHandle[j];
			Error = STAVMEM_FreeBlock(&FreeBlockParams,&ScatterPageHandle);
			BufferHandle = PPControlBlock.PPQueue[i].PPBufOut.BufferOutHandle[j];
			Error = STAVMEM_FreeBlock(&FreeBlockParams,&BufferHandle);
		}
	}
}

/******************************************************************************
 *  Function name 	: SendCommand
 *  Arguments    	:
 *       IN			:
 *       OUT    		: BOOL
 *       INOUT		:
 *  Return       	: BOOL
 *  Description   	: Send Command to PP Task
 ***************************************************************************** */
ST_ErrorCode_t SendCommand(MMEAudioPPStates_t	DesiredState,
									PPControlBlock_t *ControlBlock)
{

	/* Get the current PP State */
	if(ControlBlock->CurPPState != DesiredState)
	{
		/* Send command to PP. Change its next state to Desired state */
		STOS_MutexLock(ControlBlock->LockControlBlockMutex_p);
		ControlBlock->NextPPState = DesiredState;
		STOS_MutexRelease(ControlBlock->LockControlBlockMutex_p);
		/* Signal PP task Semaphore */
		STOS_SemaphoreSignal(ControlBlock->PPTaskSem_p);
	}
	return ST_NO_ERROR;
}

ST_ErrorCode_t STAud_PPCheckState(MMEAudioPPStates_t	DesiredState,
									PPControlBlock_t *ControlBlock)
{

	ST_ErrorCode_t Error = STAUD_ERROR_INVALID_STATE;

	switch(DesiredState)
	{
		case MME_PP_STATE_START:
			if((ControlBlock->CurPPState == MME_PP_STATE_IDLE) ||
				(ControlBlock->CurPPState == MME_PP_STATE_STOPPED))
			{

				Error = ST_NO_ERROR;
			}
			break;

		case MME_PP_STATE_PLAYING:
			/* Internal State */
			if((ControlBlock->CurPPState == MME_PP_STATE_START)  ||
				(ControlBlock->CurPPState == MME_PP_STATE_UPDATE))
			{
				Error = ST_NO_ERROR;
			}
			break;

		case MME_PP_STATE_UPDATE:
			if((ControlBlock->CurPPState == MME_PP_STATE_START) ||
				(ControlBlock->CurPPState == MME_PP_STATE_PLAYING))
			{
				Error = ST_NO_ERROR;
			}
			break;

		case MME_PP_STATE_STOP:
			if((ControlBlock->CurPPState == MME_PP_STATE_START) ||
				(ControlBlock->CurPPState == MME_PP_STATE_PLAYING))
			{
				Error = ST_NO_ERROR;
			}
			break;

		case MME_PP_STATE_STOPPED:
			/* Internal State */
			if(ControlBlock->CurPPState == MME_PP_STATE_STOP)
			{
				Error = ST_NO_ERROR;
			}
			break;

		case MME_PP_STATE_TERMINATE:
			if((ControlBlock->CurPPState == MME_PP_STATE_STOPPED) ||
				(ControlBlock->CurPPState == MME_PP_STATE_IDLE))
			{
				Error = ST_NO_ERROR;
			}
			break;
		case MME_PP_STATE_IDLE:
		case MME_PP_STATE_PAUSED:
		case MME_PP_STATE_TRICK:
		default:
			break;
	}

	return Error;
}



ST_ErrorCode_t MMETransformCompleted(MME_Command_t * CallbackData , void *UserData)
{
	/* Local variables */
	MME_Command_t		*command_p;
//    U32                 i;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	STAud_PPHandle_t	Handle;

	/* Get the PP refereance fro which this call back has come */
	Handle = (STAud_PPHandle_t)UserData;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		return 7; /* handle not found - We shall  come here - ERROR*/

	}
	//STTBX_Print(("PP call:%5u\n ", PP_p->PPControlBlock.PPQueueFromMME));
	command_p       = (MME_Command_t *) CallbackData;
	if(command_p->CmdStatus.State == MME_COMMAND_FAILED)
	{

		// Do not return error But return all the bytes--> MaX in case of AC3//
		ProcessOutput(&PP_p->PPControlBlock,MAX_SAMPLES_PER_FRAME*4*2);
	}
	/*else
		printf("Command success ");*/

	/*Get the Completed command and send PPoded data to next unit */
	ProcessOutput(&PP_p->PPControlBlock,(command_p->DataBuffers_p[1]->ScatterPages_p[0].BytesUsed));

	/* Signal PPode Task Semaphore */
	STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);

	return ST_NO_ERROR;

}

ST_ErrorCode_t MMESetGlobalTransformCompleted(MME_Command_t * CallbackData , void *UserData)
{
	/* Local variables */
	MME_Command_t		*command_p;
//    U32                 i;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	STAud_PPHandle_t	Handle;

	/* Get the PP refereance fro which this call back has come */
	Handle = (STAud_PPHandle_t)UserData;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		return 7; /* handle not found - We shall  come here - ERROR*/

	}

	command_p       = (MME_Command_t *) CallbackData;
	if(command_p->CmdStatus.State == MME_COMMAND_FAILED)
	{
		return STAUD_ERROR_MME_TRANSFORM;
	}

	STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);

	return ST_NO_ERROR;

}

ST_ErrorCode_t MMESendBufferCompleted(MME_Command_t * CallbackData, void *UserData)
{


	MME_Command_t		*command_p;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	STAud_PPHandle_t	Handle;

	/* Get the PP refereance fro which this call back has come */
	Handle = (STAud_PPHandle_t)UserData;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		return 7; /* handle not found - We shall  come here - ERROR*/

	}

	command_p       = (MME_Command_t *) CallbackData;
	if(command_p->CmdStatus.State == MME_COMMAND_FAILED)
	{
		return STAUD_ERROR_MME_TRANSFORM;
	}


	return ST_NO_ERROR;


}

/******************************************************************************
 *  Function name 	: TransformerCallback_AudioPP
 *  Arguments    	:
 *       IN			:
 *       OUT    		: Error status
 *       INOUT		:
 *  Return       	: ST_ErrorCode_t
 *  Description   	: PP Callback
 ***************************************************************************** */
static void TransformerCallback_AudioPP (MME_Event_t Event, MME_Command_t * CallbackData, void *UserData)
{
	/* Local variables */
	MME_Command_t	*command_p;

	command_p       = (MME_Command_t *) CallbackData;

	switch(command_p->CmdCode)
	{
		case MME_TRANSFORM:
			MMETransformCompleted(CallbackData,UserData);
			break;

		case MME_SET_GLOBAL_TRANSFORM_PARAMS:
			MMESetGlobalTransformCompleted(CallbackData,UserData);
			break;

		case MME_SEND_BUFFERS:
			MMESendBufferCompleted(CallbackData,UserData);
			break;
		default:
			break;
	}

}

/******************************************************************************
 *  Function name 	: STAud_PPIsInit
 *  Arguments    	:
 *       IN			:
 *       OUT    		: BOOL
 *       INOUT		:
 *  Return       	: BOOL
 *  Description   	: Search the list of PP control blocks to find if "this" PP is already
 *				  Initialized.
 ***************************************************************************** */
static BOOL STAud_PPIsInit(const ST_DeviceName_t DeviceName)
{
	BOOL	Initialized = FALSE;
	PPControlBlockList_t *queue = PPQueueHead_p;/* Global queue head pointer */

	while (queue)
	{
		/* Check the device name for a match with the item in the queue */
		if (strcmp(queue->PPControlBlock.DeviceName, DeviceName) != 0)
		{
			/* Next UART in the queue */
			queue = queue->Next_p;
		}
		else
		{
			/* The UART is already initialized */
			Initialized = TRUE;
			break;
		}
	}

    /* Boolean return value reflecting whether the device is initialized */
    return Initialized;

}

/******************************************************************************
 *  Function name 	: STAud_PPQueueAdd
 *  Arguments    	:
 *       IN			:
 *       OUT    		: BOOL
 *       INOUT		:
 *  Return       	: BOOL
 *  Description   	: This routine appends an allocated PP control block to the
 * 				   PP queue.
 ***************************************************************************** */
static void STAud_PPQueueAdd(PPControlBlockList_t *QueueItem_p)
{
    PPControlBlockList_t		*qp;

    /* Check the base element is defined, otherwise, append to the end of the
     * linked list.
     */
    if (PPQueueHead_p == NULL)
    {
        /* As this is the first item, no need to append */
        PPQueueHead_p = QueueItem_p;
        QueueItem_p->Next_p = NULL;
    }
    else
    {
        /* Iterate along the list until we reach the final item */
        qp = PPQueueHead_p;
        while (qp != NULL && qp->Next_p)
        {
            qp = qp->Next_p;
        }

        /* Append the new item */
        qp->Next_p = QueueItem_p;
        QueueItem_p->Next_p = NULL;
    }
} /* STAud_PPQueueAdd() */

/******************************************************************************
 *  Function name 	: STAud_PPQueueRemove
 *  Arguments    	:
 *       IN			:
 *       OUT    		: BOOL
 *       INOUT		:
 *  Return       	: BOOL
 *  Description   	: This routine removes a PP control block from the
 * 				   PP queue.
 ***************************************************************************** */
static void    STAud_PPQueueRemove( PPControlBlockList_t	*QueueItem_p)
{
	PPControlBlockList_t *this_p, *last_p;

    /* Check the base element is defined, otherwise quit as no items are
     * present on the queue.
     */
    if (PPQueueHead_p != NULL)
    {
        /* Reset pointers to loop start conditions */
        last_p = NULL;
        this_p = PPQueueHead_p;

        /* Iterate over each queue element until we find the required
         * queue item to remove.
         */
        while (this_p != NULL && this_p != QueueItem_p)
        {
            last_p = this_p;
            this_p = this_p->Next_p;
        }

        /* Check we found the queue item */
        if (this_p == QueueItem_p)
        {
            /* Unlink the item from the queue */
            if (last_p != NULL)
            {
                last_p->Next_p = this_p->Next_p;
            }
            else
            {
                /* Recalculate the new head of the queue i.e.,
                 * we have just removed the queue head.
                 */
                PPQueueHead_p = this_p->Next_p;
            }
        }
    }
} /* STAud_PPQueueRemove() */
/******************************************************************************
 *  Function name 	: STAud_PPGetControlBlockFromName
 *  Arguments    	:
 *       IN			:
 *       OUT    		: BOOL
 *       INOUT		:
 *  Return       	: BOOL
 *  Description   	: This routine removes a PP control block from the
 * 				   PP queue.
 ***************************************************************************** */
static PPControlBlockList_t *
   STAud_PPGetControlBlockFromName(const ST_DeviceName_t DeviceName)
{
    PPControlBlockList_t *qp = PPQueueHead_p; /* Global queue head pointer */

    while (qp != NULL)
    {
        /* Check the device name for a match with the item in the queue */
        if (strcmp(qp->PPControlBlock.DeviceName, DeviceName) != 0)
        {
            /* Next UART in the queue */
            qp = qp->Next_p;
        }
        else
        {
            /* The UART entry has been found */
            break;
        }
    }

    /* Return the UART control block (or NULL) to the caller */
    return qp;
} /* STAud_PPGetControlBlockFromName() */

/******************************************************************************
 *  Function name 	: STAud_PPGetControlBlockFromHandle
 *  Arguments    	:
 *       IN			:
 *       OUT    		: BOOL
 *       INOUT		:
 *  Return       	: BOOL
 *  Description   	: This routine returns the control block for a given handle
 ***************************************************************************** */
static PPControlBlockList_t *
   STAud_PPGetControlBlockFromHandle(STAud_PPHandle_t Handle)
{
    PPControlBlockList_t *qp = PPQueueHead_p; /* Global queue head pointer */

    /* Iterate over the uart queue */
    while (qp != NULL)
    {
        /* Check for a matching handle */
        if (Handle == qp->PPControlBlock.Handle && Handle != 0)
        {
            break;  /* This is a valid handle */
        }

        /* Try the next block */
        qp = qp->Next_p;
    }

    /* Return the PP control block (or NULL) to the caller */
    return qp;
}

ST_ErrorCode_t STAud_SetPP(STAud_PPHandle_t Handle, STAud_PPType_t type, STAud_PPValue_t value)
{
	ST_ErrorCode_t	Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	if(PP_p == NULL)
	{
		/* handle not found */
		return ST_ERROR_INVALID_HANDLE;
	}

	switch (type)
	{
	case STAUD_PP_EQUAL:
	case STAUD_PP_DCREMOVE:
	case STAUD_PP_DELAY:
	case STAUD_PP_BASS:
	default:
	    break;

	}

	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
		/*SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock); DO NOT HAVE THIS STATE */
		PP_p->PPControlBlock.UpdateRequired = TRUE;
		// Signal the PP Task
		STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_SetPP:Wrong State\n"));
	}

	return Error;
}

static MME_ERROR	UpdatePPParams(PPControlBlock_t	*ControlBlock)
{
	MME_ERROR	Error=MME_SUCCESS;

	/*if (ControlBlock->PPQueueTail!=ControlBlock->PPQueueFront)
	{
		UpdateNeeded=TRUE;
		SendCommand(MME_PP_STATE_IDLE, ControlBlock);
		return 7;

	}*/
	memset(&ControlBlock->GlobalCmd, 0, sizeof(MME_Command_t));


	ControlBlock->GlobalCmd.StructSize = sizeof(MME_Command_t);
	ControlBlock->GlobalCmd.CmdEnd   = MME_COMMAND_END_RETURN_NO_INFO; /*MME_COMMAND_END_RETURN_NOTIFY;*/
	ControlBlock->GlobalCmd.CmdCode = MME_SET_GLOBAL_TRANSFORM_PARAMS;
	ControlBlock->GlobalCmd.DueTime  = (MME_Time_t) 0;

	ControlBlock->GlobalCmd.ParamSize  = sizeof(MME_LxMixerTransformerGlobalParams_t);
	ControlBlock->GlobalCmd.Param_p  = ControlBlock->GlobalPcmParams;

	// right now we have to use the full struct size or we get an error in transformer
	if(ControlBlock->TranformHandlePP)
		Error=MME_SendCommand(ControlBlock->TranformHandlePP,&ControlBlock->GlobalCmd);
	if(Error!=MME_SUCCESS)
	{
		STTBX_PRINTError(("PP: MME Update Failed ErrorCode =%d", Error));
	}
	return Error;
}


ST_ErrorCode_t STAud_PPDcRemove(STAud_PPHandle_t Handle, enum eAccProcessApply *Apply)
{
	ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);

	ControlBlock->DcRemove->Apply=*Apply;

	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
		/*SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);*/
		PP_p->PPControlBlock.UpdateRequired = TRUE;
		// Signal PP Task
		STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_PPDcRemove:Wrong State\n"));
	}

	return ST_NO_ERROR;


}

ST_ErrorCode_t STAud_PPSetChannelDelay(STAud_PPHandle_t		Handle, STAudPP_Channel_t *ChannelDelay)
{
	ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	ControlBlock->Delay->Apply=ACC_MME_ENABLED;
	ControlBlock->Delay->DelayUpdate=ACC_MME_TRUE;
	ControlBlock->Delay->Delay[DELAY_LEFT]=ChannelDelay->Left;
	ControlBlock->Delay->Delay[DELAY_RGHT]=ChannelDelay->Right;
	ControlBlock->Delay->Delay[DELAY_LSUR]=ChannelDelay->LeftSurround;
	ControlBlock->Delay->Delay[DELAY_RSUR]=ChannelDelay->RightSurround;
	ControlBlock->Delay->Delay[DELAY_CNTR]=ChannelDelay->Center;
	ControlBlock->Delay->Delay[DELAY_LFE]=ChannelDelay->Subwoofer;
	ControlBlock->Delay->Delay[DELAY_CSURL]=ChannelDelay->CsLeft;
	ControlBlock->Delay->Delay[DELAY_CSURR]=ChannelDelay->CsRight;
	/*VcrLeft and VcrRight is not supported by the pcmprocessing_decodertypes.h*/
	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
//		SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
		PP_p->PPControlBlock.UpdateRequired = TRUE;
	// Signal PP Task
		STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_PPSetChannelDelay:Wrong State\n"));
	}

	return ST_NO_ERROR;
}
ST_ErrorCode_t STAud_PPGetChannelDelay(STAud_PPHandle_t		Handle, STAudPP_Channel_t *ChannelDelay)
{
//    ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);

	ChannelDelay->Left=ControlBlock->Delay->Delay[DELAY_LEFT];
	ChannelDelay->Right=ControlBlock->Delay->Delay[DELAY_RGHT];
	ChannelDelay->LeftSurround=ControlBlock->Delay->Delay[DELAY_LSUR];
	ChannelDelay->RightSurround=ControlBlock->Delay->Delay[DELAY_RSUR];
	ChannelDelay->Center=ControlBlock->Delay->Delay[DELAY_CNTR];
	ChannelDelay->Subwoofer=ControlBlock->Delay->Delay[DELAY_LFE];
	ChannelDelay->CsLeft=ControlBlock->Delay->Delay[DELAY_CSURL];
	ChannelDelay->CsRight=ControlBlock->Delay->Delay[DELAY_CSURR];


	return ST_NO_ERROR;

}

ST_ErrorCode_t STAud_PPSetVolParams(STAud_PPHandle_t		Handle, STAudPP_Channel_t *Attenuataion)
{
    ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	ControlBlock->BassMgt->Apply=ACC_MME_ENABLED;
	ControlBlock->BassMgt->DelayUpdate=ACC_MME_TRUE; /*Do not update delay here */
	/* Where to Use BASS
	ControlBlock->BassMgt->Config[Bass->Bass.BassType]=Bass->Bass.Value;*/

	ControlBlock->BassMgt->Volume[VOLUME_LEFT]=Attenuataion->Left;
	ControlBlock->BassMgt->Volume[VOLUME_RGHT]=Attenuataion->Right;
	ControlBlock->BassMgt->Volume[VOLUME_CNTR]=Attenuataion->Center;
	ControlBlock->BassMgt->Volume[VOLUME_LFE]=Attenuataion->Subwoofer;
	ControlBlock->BassMgt->Volume[VOLUME_LSUR]=Attenuataion->LeftSurround;
	ControlBlock->BassMgt->Volume[VOLUME_RSUR]=Attenuataion->RightSurround;
	ControlBlock->BassMgt->Volume[VOLUME_CSURL]=Attenuataion->CsLeft;
	ControlBlock->BassMgt->Volume[VOLUME_CSURR]=Attenuataion->CsRight;
	ControlBlock->BassMgt->Volume[VOLUME_AUX_LEFT]=Attenuataion->VcrLeft;
	ControlBlock->BassMgt->Volume[VOLUME_AUX_RIGHT]=Attenuataion->VcrRight;
	ControlBlock->Attenuataion=*Attenuataion;
/* Copy the Delay elements */
	{
		U8 i=0;
		for(i=0;i<DELAY_NB_CONFIG_ELEMENTS;i++)
		{
			ControlBlock->BassMgt->Delay[i]=ControlBlock->Delay->Delay[i];
		}
	}
	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
//		if(PP_p->PPControlBlock.TranformHandlePP!=0)
	//		SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
			PP_p->PPControlBlock.UpdateRequired = TRUE;
// Signal PP task
			STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_PPSetVolParams:Wrong State\n"));
	}

	return ST_NO_ERROR;

}


ST_ErrorCode_t STAud_PPGetVolParams(STAud_PPHandle_t		Handle, STAudPP_Channel_t *Attenuataion)
{
//    ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	*Attenuataion=ControlBlock->Attenuataion;
	return ST_NO_ERROR;

}

ST_ErrorCode_t STAud_PPSetEqualizationParams(STAud_PPHandle_t		Handle, STAUD_Equalization_t *Equal)
{
	ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	ControlBlock->Equalizer->Apply  = ACC_MME_ENABLED;
	ControlBlock->Equalizer->Enable = Equal->enable;
	ControlBlock->Equalizer->Config[EQ_BAND_0] = Equal->equalizerBand_0;
	ControlBlock->Equalizer->Config[EQ_BAND_1] = Equal->equalizerBand_1;
	ControlBlock->Equalizer->Config[EQ_BAND_2] = Equal->equalizerBand_2;
	ControlBlock->Equalizer->Config[EQ_BAND_3] = Equal->equalizerBand_3;
	ControlBlock->Equalizer->Config[EQ_BAND_4] = Equal->equalizerBand_4;
	ControlBlock->Equalizer->Config[EQ_BAND_5] = Equal->equalizerBand_5;
	ControlBlock->Equalizer->Config[EQ_BAND_6] = Equal->equalizerBand_6;
	ControlBlock->Equalizer->Config[EQ_BAND_7] = Equal->equalizerBand_7;
	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
//		if(PP_p->PPControlBlock.TranformHandlePP!=0)
	//		SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
			PP_p->PPControlBlock.UpdateRequired = TRUE;
			STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_PPSetVolParams:Wrong State\n"));
	}

	return ST_NO_ERROR;

}

ST_ErrorCode_t STAud_PPGetEqualizationParams(STAud_PPHandle_t		Handle, STAUD_Equalization_t *Equal)
{
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);

	Equal->enable		   = ControlBlock->Equalizer->Enable;
	Equal->equalizerBand_0 = ControlBlock->Equalizer->Config[EQ_BAND_0];
	Equal->equalizerBand_1 = ControlBlock->Equalizer->Config[EQ_BAND_1];
	Equal->equalizerBand_2 = ControlBlock->Equalizer->Config[EQ_BAND_2];
	Equal->equalizerBand_3 = ControlBlock->Equalizer->Config[EQ_BAND_3];
	Equal->equalizerBand_4 = ControlBlock->Equalizer->Config[EQ_BAND_4];
	Equal->equalizerBand_5 = ControlBlock->Equalizer->Config[EQ_BAND_5];
	Equal->equalizerBand_6 = ControlBlock->Equalizer->Config[EQ_BAND_6];
	Equal->equalizerBand_7 = ControlBlock->Equalizer->Config[EQ_BAND_7];

	return ST_NO_ERROR;
}



/* Just a Hack Function*/
static MME_ERROR acc_setAudioMixerTransformCmd(
                              MME_Command_t    * cmd,
							  MME_GenericParams_t params_p, MME_UINT params_size,
							  MME_GenericParams_t status_p, MME_UINT status_size,
                              MME_DataBuffer_t **buffer_array,
                              enum eAccCmdCode      playback_mode)
{

	MME_ERROR                         status       =  MME_SUCCESS;
	MME_LxMixerTransformerFrameDecodeParams_t * decode_params = (MME_LxMixerTransformerFrameDecodeParams_t *) params_p;

	U32 playback = playback_mode & 0x7FFF;
//	U32 length   = playback_mode >> 16 ;

 	if (playback == ACC_CMD_MUTE)
 	  playback = ACC_CMD_MUTE;
 	// Set command characteristics
	cmd->StructSize = sizeof(MME_Command_t);
	cmd->CmdCode    = MME_TRANSFORM;
	cmd->CmdEnd     = MME_COMMAND_END_RETURN_NOTIFY;
	cmd->DueTime    = 0; // immediate

	cmd->NumberInputBuffers  = 1;
	cmd->NumberOutputBuffers = 1;
	cmd->DataBuffers_p = buffer_array;

  // Set status Info
	cmd->CmdStatus.AdditionalInfo_p   = status_p;
	cmd->CmdStatus.AdditionalInfoSize = status_size;
	cmd->CmdStatus.Error              = MME_SUCCESS;
	cmd->CmdStatus.ProcessedTime      = 0;
	cmd->CmdStatus.State              = MME_COMMAND_IDLE;

	// Set transform specific info
	cmd->Param_p   = params_p;
	cmd->ParamSize = params_size;

	decode_params->InputParam[0].Command           = (U16) playback  ;
	decode_params->InputParam[0].StartOffset=0;


	return (status);
}

ST_ErrorCode_t STAud_PPDisableDownSampling(STAud_PPHandle_t Handle)
{
    ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;
	MME_LxMixerTransformerInitParams_t	*PP_Init;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	PP_Init= (MME_LxMixerTransformerInitParams_t	*)ControlBlock->MMEinitParams.TransformerInitParams_p;

	ControlBlock->StartParams.InputFrequency=ControlBlock->StartParams.OutPutFrequency=0;
	ControlBlock->DownSamplingEnabled = FALSE;
	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
		//SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
		PP_p->PPControlBlock.UpdateRequired = TRUE;
		STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_PPDisableDownSampling:Wrong State\n"));
	}

	return ST_NO_ERROR;


}

ST_ErrorCode_t STAud_PPEnableDownSampling(STAud_PPHandle_t Handle, U32 Frequency)
{
//    ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	/*Fix the Output Frequency */

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	PP_p->PPControlBlock.StartParams.OutPutFrequency=Frequency;
	ControlBlock->DownSamplingEnabled = TRUE;

	return ST_NO_ERROR;
}
static ST_ErrorCode_t STAud_ApplyBassDolby(PPControlBlock_t	*ControlBlock, STAUD_BassMgtType_t Type , BOOL LFEChannel)
{

	ControlBlock->BassMgt->Id=ACC_RENDERER_BASSMGT_ID;   //!< ID of this processing
	ControlBlock->BassMgt->StructSize=sizeof(MME_BassMgtGlobalParams_t);
	ControlBlock->BassMgt->Apply=ACC_MME_ENABLED;
	ControlBlock->BassMgt->DelayUpdate=ACC_MME_TRUE;

	ControlBlock->BassMgt->Config[BASSMGT_PROLOGIC_IN]=ACC_MME_FALSE;
	ControlBlock->BassMgt->Config[BASSMGT_OUT_WS]=32;

	switch(Type)
	{
	case BASS_MGT_DOLBY_1:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_DOLBY_1;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel;
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0;
		break;

	case BASS_MGT_DOLBY_2:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_DOLBY_2;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel; /*May be False*/
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;/*May be True*/
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0;
		break;

	case BASS_MGT_DOLBY_3:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_DOLBY_3;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel;/*May be False*/
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0;
		break;

	case BASS_MGT_SIMPLIFIED:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_SIMPLIFIED;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel;/*May be false*/
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0;
		break;

	case BASS_MGT_DOLBY_CERT:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_DOLBY_CERT;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel;
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0;
		break;


	case BASS_MGT_Philips:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_Philips;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel;
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0; /* Fill here the attenution for philips */
		break;

	case BASS_MGT_OFF:
	default:
		ControlBlock->BassMgt->Config[BASSMGT_TYPE]=BASS_MGT_OFF;
		ControlBlock->BassMgt->Config[BASSMGT_LFE_OUT]=LFEChannel;
		ControlBlock->BassMgt->Config[BASSMGT_BOOST_OUT]=ACC_MME_FALSE;
		ControlBlock->BassMgt->Config[BASSMGT_LIMITER]=0;
		break;
	}
	return ST_NO_ERROR;
}
ST_ErrorCode_t STAud_PPSetSpeakerConfig(STAud_PPHandle_t Handle,STAud_PPSpeakerConfiguration_t *SpeakerConfig,STAUD_BassMgtType_t BassMgmtType)
{
	ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;
	STAud_PPSpeakerConfiguration_t	LocalSpeakerConfig;
	STAUD_BassMgtType_t  BassType=BASS_MGT_OFF;
	BOOL BassRequested=FALSE;
	BOOL LFEChannel=FALSE;
	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

    if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}

	if(PP_p->PPControlBlock.StartParams.NumChannels == 2)
	{
		return ST_NO_ERROR;
	}


	ControlBlock= & (PP_p->PPControlBlock);
	LocalSpeakerConfig=*SpeakerConfig;
	LFEChannel = SpeakerConfig->LFEPresent;

	if ((LocalSpeakerConfig.Front==STAUD_PPSPEAKER_TYPE_SMALL) &&
		(LocalSpeakerConfig.Center==STAUD_PPSPEAKER_TYPE_SMALL) &&
		(LocalSpeakerConfig.RightSurround==STAUD_PPSPEAKER_TYPE_SMALL) &&
		(LocalSpeakerConfig.LeftSurround==STAUD_PPSPEAKER_TYPE_SMALL))
	{
		/*Apply PP Dolby bass management 1 */
		switch (BassMgmtType)
		{
		case BASS_MGT_DOLBY_1:
			BassType=BASS_MGT_DOLBY_1;
			break;
		case BASS_MGT_DOLBY_CERT:
			BassType=BASS_MGT_DOLBY_CERT;
			break;

		/*For invalid config */
		case BASS_MGT_OFF:
		case BASS_MGT_DOLBY_2:
		case BASS_MGT_DOLBY_3:
		case BASS_MGT_SIMPLIFIED:
		case BASS_MGT_Philips:
		default :
			BassType=BASS_MGT_OFF;
			break;
		}

		BassRequested=TRUE;
		STAud_ApplyBassDolby(ControlBlock,BassType,LFEChannel);
	}
	if((LocalSpeakerConfig.Front==STAUD_PPSPEAKER_TYPE_LARGE) &&
		(LocalSpeakerConfig.Center==STAUD_PPSPEAKER_TYPE_SMALL) &&
		(LocalSpeakerConfig.RightSurround==STAUD_PPSPEAKER_TYPE_SMALL)&&
		(LocalSpeakerConfig.LeftSurround==STAUD_PPSPEAKER_TYPE_SMALL))
	{
		/*Apply Dolby Bass Management 2 / Simplified or philips*/
		switch(BassMgmtType)
		{
			case BASS_MGT_Philips:
			BassType=BASS_MGT_Philips ; /*BASS_MGT_Philips;*/
			break;

			case BASS_MGT_DOLBY_2:
			BassType=BASS_MGT_DOLBY_2;/*BASS_MGT_SIMPLIFIED;BASS_MGT_Philips; */
			break;

			case BASS_MGT_SIMPLIFIED:
			BassType=BASS_MGT_SIMPLIFIED;
			break;
			/*For invalid config */
			case BASS_MGT_OFF:
			case BASS_MGT_DOLBY_1:
			case BASS_MGT_DOLBY_3:
			case BASS_MGT_DOLBY_CERT:
			default :
			BassType = BASS_MGT_OFF;
			break;

		}
		BassRequested=TRUE;
		STAud_ApplyBassDolby(ControlBlock,BassType,LFEChannel);
	}

	if((LocalSpeakerConfig.Front==STAUD_PPSPEAKER_TYPE_LARGE) &&
		(LocalSpeakerConfig.Center==STAUD_PPSPEAKER_TYPE_SMALL) &&
		(LocalSpeakerConfig.RightSurround==STAUD_PPSPEAKER_TYPE_LARGE)&&
		(LocalSpeakerConfig.LeftSurround==STAUD_PPSPEAKER_TYPE_LARGE))
	{
		/*Apply Bass Management 3*/
		BassType=BASS_MGT_DOLBY_3;
		BassRequested=TRUE;
		if(BassMgmtType == BASS_MGT_OFF)
				BassType=BASS_MGT_OFF;
		STAud_ApplyBassDolby(ControlBlock,BassType,LFEChannel);
	}

	if(((LocalSpeakerConfig.Front==STAUD_PPSPEAKER_TYPE_LARGE) &&
		(LocalSpeakerConfig.Center==STAUD_PPSPEAKER_TYPE_LARGE) &&
		(LocalSpeakerConfig.RightSurround==STAUD_PPSPEAKER_TYPE_LARGE)&&
		(LocalSpeakerConfig.LeftSurround==STAUD_PPSPEAKER_TYPE_LARGE)))
	{
		/*Apply Bass Management config 0 */
		BassType=BASS_MGT_DOLBY_CERT;
		if(BassMgmtType == BASS_MGT_OFF)
				BassType=BASS_MGT_OFF;
		BassRequested=TRUE;
		STAud_ApplyBassDolby(ControlBlock,BassType,LFEChannel);
	}


	if(BassRequested==FALSE)
	{
		BassType=BASS_MGT_OFF;
		STAud_ApplyBassDolby(ControlBlock,BassType,LFEChannel);
	}
	ControlBlock->SpeakerConfig=*SpeakerConfig;
    	Error = STAud_PPCheckState(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
	if(Error == ST_NO_ERROR)
	{
		//SendCommand(MME_PP_STATE_UPDATE, &PP_p->PPControlBlock);
		PP_p->PPControlBlock.UpdateRequired = TRUE;
		STOS_SemaphoreSignal(PP_p->PPControlBlock.PPTaskSem_p);
	}
	else
	{
		STTBX_PRINTError(("To MME_PP_STATE_UPDATE in STAud_PPSetSpeakerConfig:Wrong State\n"));
	}

	return ST_NO_ERROR;
}


ST_ErrorCode_t STAud_PPGetSpeakerConfig(STAud_PPHandle_t Handle,STAud_PPSpeakerConfiguration_t *SpeakerConfig)
{
//    ST_ErrorCode_t  Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);
	*SpeakerConfig=ControlBlock->SpeakerConfig;
	return ST_NO_ERROR;
}

static void SetSamplingFrequency (U32 SamplingFreq, enum eAccFsCode * ACCFsCode)
{
	switch (SamplingFreq)
		{
			case 48000:
				*ACCFsCode = ACC_FS48k;
				break;

			case 44100:
				*ACCFsCode = ACC_FS44k;
				break;

			case 32000:
				*ACCFsCode = ACC_FS32k;
				break;

			case 96000:
				*ACCFsCode = ACC_FS96k;
				break;

			case 88200:
				*ACCFsCode = ACC_FS88k;
				break;

			case 64000:
				*ACCFsCode = ACC_FS64k;
				break;

			case 192000:
				*ACCFsCode = ACC_FS192k;
				break;

			case 176400:
				*ACCFsCode = ACC_FS176k;
				break;

			case 128000:
				*ACCFsCode = ACC_FS128k;
				break;

			case 384000:
				*ACCFsCode = ACC_FS384k;
				break;

			case 352800:
				*ACCFsCode = ACC_FS352k;
				break;

			case 256000:
				*ACCFsCode = ACC_FS256k;
				break;

			case 12000:
				*ACCFsCode = ACC_FS12k;
				break;

			case 11025:
				*ACCFsCode = ACC_FS11k;
				break;

			case 8000:
				*ACCFsCode = ACC_FS8k;
				break;

			case 24000:
				*ACCFsCode = ACC_FS24k;
				break;

			case 22050:
				*ACCFsCode = ACC_FS22k;
				break;

			case 16000:
				*ACCFsCode = ACC_FS16k;
				break;

			default :
				break;


		}
}
ST_ErrorCode_t STAud_PostProcGetCapability(STAud_PPHandle_t Handle,STAUD_PPCapability_t *Capability_p)
{
	ST_ErrorCode_t	Error = ST_NO_ERROR;
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;
	MME_ERROR ErrorCode;
	MME_TransformerCapability_t TransformerCapability;
	MME_LxMixerTransformerInfo_t		Capability;
	U32 i;


	PP_p = STAud_PPGetControlBlockFromHandle(Handle);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	ControlBlock= & (PP_p->PPControlBlock);

	TransformerCapability.StructSize=sizeof(MME_TransformerCapability_t);
	TransformerCapability.TransformerInfoSize=sizeof(MME_LxMixerTransformerInfo_t);
	memset(&Capability,0,sizeof(MME_LxMixerTransformerInfo_t));
	TransformerCapability.TransformerInfo_p=&Capability;
	Capability.StructSize=sizeof(MME_LxMixerTransformerInfo_t);
	ErrorCode=MME_GetTransformerCapability("MME_TRANSFORMER_TYPE_AUDIO_MIXER",&TransformerCapability);
	if(ErrorCode!=MME_SUCCESS)
	{
		return STAUD_ERROR_MME_TRANSFORM;
	}

	for (i = 0; i < 32; i++)
	{
		switch (Capability.PcmProcessorCapabilityFlags[0] & (1 << i))
		{
		case (1 << ACC_VOLUME_CONTROL):
			Capability_p->ChannelAttenuationCapable=TRUE;
			break;
		case (1 << ACC_DELAY):
			Capability_p->DelayCapable=TRUE;
			break;


		default:
			break;
		}
	}

	Capability_p->DownsamplingCapable=TRUE;
	Capability_p->MultiChannelOutputCapable=TRUE;
	Capability_p->MaxAttenuation=60;
	Capability_p->AttenuationPrecision=1;
	Capability_p->MaxDelay=30;
	Capability_p->SupportedKaraokeModes=STAUD_KARAOKE_NONE;
	Capability_p->SupportedSpeakerTypes=STAUD_SPEAKER_TYPE_LARGE;
	return Error;



}
/* This function is required to work with encoder*/
ST_ErrorCode_t STAud_PPSetOutputStreamType(STAud_PPHandle_t		Handle, STAUD_StreamContent_t  StreamContent)
{
	PPControlBlockList_t	*PP_p= (PPControlBlockList_t*)NULL;
	PPControlBlock_t	*ControlBlock ;

	PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	ControlBlock= & (PP_p->PPControlBlock);

	if(PP_p == NULL)
	{
		/* Device not initialized */
		return ST_ERROR_UNKNOWN_DEVICE;
	}
	switch(StreamContent)
	{
		case STAUD_STREAM_CONTENT_AC3:
			ControlBlock->ForcedOutputSamples = 1536;
			break;

		case STAUD_STREAM_CONTENT_DTS:
			ControlBlock->ForcedOutputSamples = 512;
				break;

		default:
			ControlBlock->ForcedOutputSamples = 0;
			break;
	}


	return ST_NO_ERROR;
}

ST_ErrorCode_t	STAud_PPGetOPBMHandle(STAud_PPHandle_t	Handle, U32 OutputId,STMEMBLK_Handle_t * BMHandle_p)
{
	PPControlBlockList_t	*PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	ST_ErrorCode_t 	Error=ST_NO_ERROR;

	if(PP_p)
	{
		if(OutputId == 0)
		{
			* BMHandle_p = PP_p->PPControlBlock.OutMemoryBlockManagerHandle;
		}
		else
		{
			Error = ST_ERROR_BAD_PARAMETER;
		}
	}
	else
	{
		Error = ST_ERROR_INVALID_HANDLE;
	}

	return Error;
}

ST_ErrorCode_t	STAud_PPSetIPBMHandle(STAud_PPHandle_t	Handle, U32 InputId, STMEMBLK_Handle_t BMHandle)
{
	PPControlBlockList_t	*PP_p = STAud_PPGetControlBlockFromHandle(Handle);
	ST_ErrorCode_t 	Error=ST_NO_ERROR;

	if(PP_p)
	{
		PPControlBlock_t	*PPCtrlBlk_p = &(PP_p->PPControlBlock);
		STOS_MutexLock(PPCtrlBlk_p->LockControlBlockMutex_p);
		switch(PPCtrlBlk_p->CurPPState)
		{
		case MME_PP_STATE_IDLE:
		case MME_PP_STATE_STOPPED:
			if(InputId == 0)
			{
				PPCtrlBlk_p->InMemoryBlockManagerHandle = BMHandle;
			}
			else
			{
				Error = ST_ERROR_BAD_PARAMETER;
			}
			break;
		default:
			/*We can't change the handle in running condition*/
			Error = STAUD_ERROR_INVALID_STATE;
			break;
		}
		STOS_MutexRelease(PPCtrlBlk_p->LockControlBlockMutex_p);

	}
	else
	{
		Error = ST_ERROR_INVALID_HANDLE;
	}

	return Error;
}

