#include "as_native_model_reg.h"
#include "nativeclasses/NativePlayer.h"

static const ELIPS_nativeFunctionNameTable ELIPS_native_function_name_table[] =
{
    { "nativeclasses_NativePlayer_as_i_music_playback", nativeclasses_NativePlayer_as_i_music_playback },
};

void ELIPSNativeLibraryGetFunctionTable(ELIPS_nativeFunctionNameTable **table,unsigned int *size)
{
    *table = (ELIPS_nativeFunctionNameTable*)ELIPS_native_function_name_table;
    *size = 1;
}
void ELIPSNativeLibraryReleaseFunctionTable(ELIPS_nativeFunctionNameTable *table,unsigned int size)
{
}

