/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "audio_provider.h"

#include "micro_features/micro_model_settings.h"

namespace {
    constexpr int kAudioCaptureBufferSize = kAudioSampleFrequency / 2;
    int16_t g_audio_capture_buffer[kAudioCaptureBufferSize];
    int16_t g_audio_output_buffer[kMaxAudioSampleSize];
    uint32_t g_audio_capture_buffer_index = 0;
    int32_t g_latest_audio_timestamp = 0;
}  // namespace

extern "C" {
    void CopyToCaptureBuffer(int16_t *buf) {
        for (int i = 0; i < kMaxAudioSampleSize; ++i) {
           g_audio_capture_buffer[(g_audio_capture_buffer_index + i) % kAudioCaptureBufferSize] = buf[i];
        }

        g_audio_capture_buffer_index += kMaxAudioSampleSize;
        g_latest_audio_timestamp += 32;
    }
}

TfLiteStatus GetAudioSamples(tflite::ErrorReporter* error_reporter,
                             int start_ms, int duration_ms,
                             int* audio_samples_size, int16_t** audio_samples) {


  const int start_offset = start_ms * (kAudioSampleFrequency / 1000);
  const int duration_sample_count = duration_ms * (kAudioSampleFrequency / 1000);
  for (int i = 0; i < duration_sample_count; ++i) {
    const int capture_index = (start_offset + i) % kAudioCaptureBufferSize;
    g_audio_output_buffer[i] = (g_audio_capture_buffer[capture_index] - 8192) * 2;
  }

  *audio_samples_size = kMaxAudioSampleSize;
  *audio_samples = g_audio_output_buffer;
  return kTfLiteOk;
}

int32_t LatestAudioTimestamp() {
  return g_latest_audio_timestamp;
}
