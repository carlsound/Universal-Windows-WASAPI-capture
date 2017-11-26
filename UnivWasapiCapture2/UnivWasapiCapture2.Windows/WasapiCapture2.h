#pragma once
//
//#include <client.h> // ComPtr
#include <audioclient.h> // WASAPI
#include <audiosessiontypes.h> // STREAM FLAGS
#include <mmdeviceapi.h>
//
namespace UnivWasapiCapture2
{
	class WasapiCapture2
	{
	public:
		WasapiCapture2();
		~WasapiCapture2();

		void startCapturing();
		void stopCapturing();

		//Microsoft::WRL::ComPtr<IAudioClient> wasapiClient;
		//Microsoft::WRL::ComPtr<IAudioCaptureClient> wasapiCapture;
		//
		IAudioClient *pAudioClient = NULL;
		IAudioCaptureClient *pCaptureClient = NULL;
		//
		const CLSID CLSID_MMDeviceEnumerator = __uuidof(MMDeviceEnumerator);
		const IID IID_IMMDeviceEnumerator = __uuidof(IMMDeviceEnumerator);
		//
		IMMDeviceEnumerator *pEnumerator = NULL;
		//
		WAVEFORMATEX *pwfx = NULL;
		UINT32 packetLength = 0;
		BOOL bDone = FALSE;
		BYTE *pData;
		DWORD flags;
		//
		const REFERENCE_TIME hnsRequestedDuration = 10000000;
		REFERENCE_TIME hnsActualDuration;
		//
		UINT32 bufferFrameCount;
		UINT32 numFramesAvailable;
		//
		HRESULT hr1;
		HRESULT hr2;
		HRESULT hr3;
		HRESULT hr4;
		HRESULT hr5;
		HRESULT hr6;
		HRESULT hr7;
		HRESULT hr8;
		HRESULT hr9;
		HRESULT hr10;
		HRESULT hr11;
		void** audioInt;
		//
		//HANDLE hEvent;
		HANDLE hWASAPICaptureCallbackEvent; // for event-driven callbacks
		//
		/* for IAudioCaptureClient::GetBuffer method */
		BYTE **ppData;
		UINT32 *pNumFramesToRead;
		DWORD *pdwFlags;
		UINT64 *pu64DevicePosition;
		UINT64 *pu64QPCPosition;
		//
		/* for IAudioCaptureClient::ReleaseBuffer*/
		UINT32 NumFramesRead;
	};

}