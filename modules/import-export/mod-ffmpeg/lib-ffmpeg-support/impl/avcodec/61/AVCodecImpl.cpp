extern "C"
{
#include "../../avutil/59/avconfig.h"
#include "../../ffmpeg-7.0.0-single-header.h"
}

#include <cstring>
#include <numeric>

#include "float_cast.h"

#include "FFmpegFunctions.h"

#include "wrappers/AVCodecContextWrapper.h"
#include "wrappers/AVCodecWrapper.h"
#include "wrappers/AVPacketWrapper.h"

#include "../../FFmpegAPIResolver.h"

namespace avcodec_61
{
#include "../AVCodecContextWrapperImpl.inl"
#include "../AVCodecWrapperImpl.inl"
#include "../AVPacketWrapperImpl.inl"

const bool registered = ([]() {
   FFmpegAPIResolver::Get().AddAVCodecFactories(61, {
      &CreateAVCodecContextWrapper,
      &CreateAVCodecContextWrapperFromCodec,
      &CreateAVCodecWrapper,
      &CreateAVPacketWrapper,
   });

   return true;
})();
}

#include "FFmpegTypes.h"
static_assert(
   AV_CODEC_FLAG_GLOBAL_HEADER == AUDACITY_AV_CODEC_FLAG_GLOBAL_HEADER
   && AV_CODEC_CAP_SMALL_LAST_FRAME == AUDACITY_AV_CODEC_CAP_SMALL_LAST_FRAME
   && AV_CODEC_FLAG_QSCALE == AUDACITY_AV_CODEC_FLAG_QSCALE
,
   "FFmpeg constants don't match"
);

