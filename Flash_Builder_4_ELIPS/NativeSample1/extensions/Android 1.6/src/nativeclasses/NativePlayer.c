#include "../as_native_model.h"
#include "NativePlayer.h"

#include <jni.h>
#include <stdlib.h>

extern JNIEnv *elips_get_jni_env(int *attached);
extern void elips_release_jni_env(int attached);

static jobject jObjNativePlayerImpl = 0;
static jclass jClassNativePlayerImpl = 0;

ASBool nativeclasses_NativePlayer_as_i_music_playback(ASContext ctxt, ASObject thiz)
{
	JNIEnv *jEnv = 0;
	jclass jClass = 0;
	jmethodID jMid = 0;
	int isAttached = 0;
	jobject jContext = 0;
	jobject jThiz = 0;
	ASBool result = 0;
	jboolean jResult = 0;

	jEnv = elips_get_jni_env(&isAttached);

	if(jObjNativePlayerImpl == 0)
	{
		jClassNativePlayerImpl = (*jEnv)->NewGlobalRef(jEnv, (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/nativeclasses/NativePlayerImpl"));
		jMid = (*jEnv)->GetMethodID(jEnv, jClassNativePlayerImpl, "<init>", "()V");
		jObjNativePlayerImpl = (*jEnv)->NewGlobalRef(jEnv, (*jEnv)->NewObject(jEnv, jClassNativePlayerImpl, jMid));
	}

	jClass = (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/ASContext");
	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jContext = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)ctxt);
	(*jEnv)->DeleteLocalRef(jEnv, jClass);

	jClass = (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/ASObject");
	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jThiz = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)thiz);
	(*jEnv)->DeleteLocalRef(jEnv, jClass);

	jMid = (*jEnv)->GetMethodID(jEnv, jClassNativePlayerImpl, "music_playback", "(Lcom/openplug/elips3/extension/ASContext;Lcom/openplug/elips3/extension/ASObject;)Z");
	jResult = (*jEnv)->CallBooleanMethod(jEnv, jObjNativePlayerImpl, jMid, jContext, jThiz);

	//(*jEnv)->DeleteLocalRef(jEnv, jObj);
	(*jEnv)->DeleteLocalRef(jEnv, jContext);
	(*jEnv)->DeleteLocalRef(jEnv, jThiz);
	elips_release_jni_env(isAttached);

	result = (ASBool)jResult;

	return result;
}


