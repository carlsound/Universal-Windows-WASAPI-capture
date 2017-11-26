#include "pch.h"
#include "WasapiCapture2.h"

//
using namespace UnivWasapiCapture2;
using namespace Platform;
//
WasapiCapture2::WasapiCapture2()
{
	pAudioClient = NULL;
	pCaptureClient = NULL;
	pwfx = NULL;
	packetLength = 0;
	bDone = FALSE;
	//
	/*hr1 = ActivateAudioInterface(
		GetDefaultAudioCaptureId(Default),
		__uuidof(IAudioClient),
		(void**)&pAudioClient
		);*/
	//
	hr1 = CoCreateInstance(
		CLSID_MMDeviceEnumerator, NULL,
		CLSCTX_ALL, IID_IMMDeviceEnumerator,
		(void**)&pEnumerator);
	//
	hr2 = pEnumerator->GetDefaultAudioEndpoint(
		eCapture, eConsole, &pDevice);

	//
	hr2 = pAudioClient->GetMixFormat(&pwfx);
	//
	hr3 = pAudioClient->Initialize(
		AUDCLNT_SHAREMODE_SHARED,
		AUDCLNT_STREAMFLAGS_EVENTCALLBACK,
		hnsRequestedDuration,
		0,//hnsRequestedDuration,
		pwfx,
		NULL
		);
	//
	//hEvent = CreateEventExW(NULL, NULL, CREATE_EVENT_MANUAL_RESET, EVENT_ALL_ACCESS);
	hWASAPICaptureCallbackEvent = CreateEventExW(NULL, NULL, CREATE_EVENT_MANUAL_RESET, EVENT_ALL_ACCESS);
	//
	//hr4 = pAudioClient->SetEventHandle(hEvent);
	hr4 = pAudioClient->SetEventHandle(hWASAPICaptureCallbackEvent);
	//
	hr5 = pAudioClient->GetBufferSize(&bufferFrameCount);
	//
	hr6 = pAudioClient->GetService(
		__uuidof(IAudioCaptureClient),
		(void**)&pCaptureClient
		);
	//
	/*
	hr1 = pAudioClient->GetService(
	__uuidof(IAudioRenderClient),
	(void**)&pRenderClient
	);
	*/
	//
	// Notify the audio sink which format to use.
	//hr2 = pMySink->SetFormat(pwfx);
	//
	// Calculate the actual duration of the allocated buffer.
	hnsActualDuration = (double)10000000 * bufferFrameCount / pwfx->nSamplesPerSec;
	//
	//hr1 = pAudioClient->Start();  // Start recording.
	//
}


WasapiCapture2::~WasapiCapture2()
{
}

void WasapiCapture2::startCapturing()
{
	//throw(gcnew System::NotImplementedException);
	//
	hr7 = pAudioClient->Start();  // Start recording.
	//
	// Grab the entire buffer for the initial fill operation.
	hr8 = pCaptureClient->GetBuffer(ppData,
		pNumFramesToRead,
		pdwFlags,
		pu64DevicePosition,
		pu64QPCPosition);
	//
	// Load the initial data into the shared buffer.
	//hr9 = pAudioClient->LoadData(bufferFrameCount, pData, &flags);
	//
	if (pNumFramesToRead > 0)
	{
		NumFramesRead = *pNumFramesToRead;
	}
	else
	{
		NumFramesRead = 0;
	}
	//
	hr10 = pCaptureClient->ReleaseBuffer(NumFramesRead);
	//
	int i = 0;
	//
}


void WasapiCapture2::stopCapturing()
{
	//throw(gcnew System::NotImplementedException);
	//
	hr11 = pAudioClient->Stop();  // Stop recording.
}