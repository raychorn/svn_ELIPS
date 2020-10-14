#include <jni.h>
#include <stdlib.h>
#include "as_native_model.h"	

/*
 * Class:     com_openplug_elips3_extension_ASArray
 * Method:    ASCreateArray
 * Signature: (Lcom/openplug/elips3/extension/ASContext;ILcom/openplug/elips3/extension/ASArray;)Lcom/openplug/elips3/extension/ASError;
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASArray_ASCreateArray(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jint jLength, jobject jArray)
{
	jclass jClass2;
	jlong jContext;
	jfieldID jFid;
	ASError asError;
	ASArray asArray;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	asError = ASCreateArray((ASContext)jContext, (unsigned int)jLength, &asArray);

	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "array", "J");
	(*jEnv)->SetLongField(jEnv, jArray, jFid, (jlong)asArray);

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASArray
 * Method:    ASArrayGet
 * Signature: (Lcom/openplug/elips3/extension/ASContext;I)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASArray_ASArrayGet(JNIEnv *jEnv, jobject jObj, jobject jCtxt, jint jI)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jmethodID jMid;
	ASValue asValue;
	jlong jArray;
	jobject jResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "array", "J");
	jArray = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asValue = ASArrayGet((ASContext)jContext, (ASArray)jArray, (unsigned int)jI);

	jClass = (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/ASValue");
	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jResult = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);
	(*jEnv)->DeleteLocalRef(jEnv, jClass);

	return jResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASArray
 * Method:    ASArraySet
 * Signature: (Lcom/openplug/elips3/extension/ASContext;ILcom/openplug/elips3/extension/ASValue;)Lcom/openplug/elips3/extension/ASError;
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASArray_ASArraySet(JNIEnv *jEnv, jobject jObj, jobject jCtxt, jint jI, jobject jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jArray;
	ASError asError;
	jlong jValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "array", "J");
	jArray = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asError = ASArraySet((ASContext)jContext, (ASArray)jArray, (unsigned int)jI, (ASValue)jValue);

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASArray
 * Method:    ASArrayLength
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASArray_ASArrayLength(JNIEnv *jEnv, jobject jObj, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jArray;
	unsigned int asLength;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "array", "J");
	jArray = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asLength = ASArrayLength((ASContext)jContext, (ASArray)jArray);

	return (jint)asLength;
}

/*
 * Class:     com_openplug_elips3_extension_ASContext
 * Method:    ASCtxtSetUserData
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASContext_ASCtxtSetUserData(JNIEnv *jEnv, jobject jObj, jlong juserData)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASError asError;

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asError = ASCtxtSetUserData((ASContext)jContext, (void *)juserData);

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASContext
 * Method:    ASCtxtGetUserData
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_openplug_elips3_extension_ASContext_ASCtxtGetUserData(JNIEnv *jEnv, jobject jObj)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	void* asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asResult = ASCtxtGetUserData((ASContext)jContext);

	return (jlong)asResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASContext
 * Method:    ASCtxtEnableExceptionCatch
 * Signature: (Z)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASContext_ASCtxtEnableExceptionCatch(JNIEnv *jEnv, jobject jObj, jboolean jEnable)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASError asError;

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asError = ASCtxtEnableExceptionCatch((ASContext)jContext, (ASBool)jEnable);

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASContext
 * Method:    ASCtxtGetLastException
 * Signature: ()Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASContext_ASCtxtGetLastException(JNIEnv *jEnv, jobject jObj)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASValue asValue;
	jobject jResult;
	jmethodID jMid;

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asValue = ASCtxtGetLastException((ASContext)jContext);

	jClass = (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/ASValue");
	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jResult = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);
	(*jEnv)->DeleteLocalRef(jEnv, jClass);

	return jResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASContext
 * Method:    ASCtxtGetPlatformSpecificData
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_openplug_elips3_extension_ASContext_ASCtxtGetPlatformSpecificData(JNIEnv *jEnv, jobject jObj)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	void* asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	asResult = ASCtxtGetPlatformSpecificData((ASContext)jContext);

	return (jlong)asResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASObject
 * Method:    ASCreateObject
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Ljava/lang/String;I[Lcom/openplug/elips3/extension/ASValue;Lcom/openplug/elips3/extension/ASObject;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASObject_ASCreateObject(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jstring jType, jint jArgc, jobjectArray jArgv, jobject jObject)
{
	jclass jClass2;
	jlong jContext;
	jfieldID jFid;
	ASError asError;
	ASObject asObject;
	const jbyte *jbType;
	ASValue* asArgv;
	int i;
	jobject jElement;
	jlong jValue;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	if(jArgc > 0)
	{
		asArgv = (ASValue*)malloc(jArgc * sizeof(ASValue));
		for(i = 0; i < jArgc; i++)
		{
			jElement = (*jEnv)->GetObjectArrayElement(jEnv, jArgv, i);
			jClass2 = (*jEnv)->GetObjectClass(jEnv, jElement);
			jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "value", "J");
			jValue = (*jEnv)->GetLongField(jEnv, jElement, jFid);
			asArgv[i] = (ASValue)jValue;
		}
	}

	jbType = (*jEnv)->GetStringUTFChars(jEnv, jType, NULL);
	asError = ASCreateObject((ASContext)jContext, jbType, (int)jArgc, asArgv, &asObject);
	(*jEnv)->ReleaseStringUTFChars(jEnv, jType, jbType);

	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "object", "J");
	(*jEnv)->SetLongField(jEnv, jObject, jFid, (jlong)asObject);

	if(jArgc > 0)
	{
		free(asArgv);
	}

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASObject
 * Method:    ASGetProperty
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Ljava/lang/String;Lcom/openplug/elips3/extension/ASValue;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASObject_ASGetProperty(JNIEnv *jEnv, jobject jObj, jobject jCtxt, jstring jS, jobject jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASError asError;
	jlong jObject;
	ASValue asValue;
	const jbyte *jbType;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "object", "J");
	jObject = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	jbType = (*jEnv)->GetStringUTFChars(jEnv, jS, NULL);
	asError = ASGetProperty((ASContext)jContext, (ASObject)jObject, jbType, &asValue);
	(*jEnv)->ReleaseStringUTFChars(jEnv, jS, jbType);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	(*jEnv)->SetLongField(jEnv, jVal, jFid, (jlong)asValue);

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASObject
 * Method:    ASSetProperty
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Ljava/lang/String;Lcom/openplug/elips3/extension/ASValue;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASObject_ASSetProperty(JNIEnv *jEnv, jobject jObj, jobject jCtxt, jstring jS, jobject jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASError asError;
	jlong jObject;
	jlong jValue;
	const jbyte *jbType;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "object", "J");
	jObject = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	jbType = (*jEnv)->GetStringUTFChars(jEnv, jS, NULL);
	asError = ASSetProperty((ASContext)jContext, (ASObject)jObject, jbType, (ASValue)jValue);
	(*jEnv)->ReleaseStringUTFChars(jEnv, jS, jbType);

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASObject
 * Method:    ASCallProperty
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Ljava/lang/String;I[Lcom/openplug/elips3/extension/ASValue;Lcom/openplug/elips3/extension/ASValue;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASObject_ASCallProperty(JNIEnv *jEnv, jobject jObj, jobject jCtxt, jstring jS, jint jArgc, jobjectArray jArgv, jobject jRet)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASError asError;
	jlong jObject;
	const jbyte *jbType;
	ASValue asReturn;
	ASValue* asArgv;
	int i;
	jobject jElement;
	jlong jValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "object", "J");
	jObject = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	if(jArgc > 0)
	{
		asArgv = (ASValue*)malloc(jArgc * sizeof(ASValue));
		for(i = 0; i < jArgc; i++)
		{
			jElement = (*jEnv)->GetObjectArrayElement(jEnv, jArgv, i);
			jClass = (*jEnv)->GetObjectClass(jEnv, jElement);
			jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
			jValue = (*jEnv)->GetLongField(jEnv, jElement, jFid);
			asArgv[i] = (ASValue)jValue;
		}
	}

	jbType = (*jEnv)->GetStringUTFChars(jEnv, jS, NULL);
	asError = ASCallProperty((ASContext)jContext, (ASObject)jObject, jbType, (int)jArgc, asArgv, &asReturn);
	(*jEnv)->ReleaseStringUTFChars(jEnv, jS, jbType);

	jClass = (*jEnv)->GetObjectClass(jEnv, jRet);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	(*jEnv)->SetLongField(jEnv, jRet, jFid, (jlong)asReturn);

	if(jArgc > 0)
	{
		free(asArgv);
	}

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASObject
 * Method:    ASCall
 * Signature: (Lcom/openplug/elips3/extension/ASContext;I[Lcom/openplug/elips3/extension/ASValue;Lcom/openplug/elips3/extension/ASValue;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASObject_ASCall(JNIEnv *jEnv, jobject jObj, jobject jCtxt, jint jArgc, jobjectArray jArgv, jobject jRet)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASError asError;
	jlong jObject;
	ASValue asReturn;
	ASValue* asArgv;
	int i;
	jobject jElement;
	jlong jValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jObj);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "object", "J");
	jObject = (*jEnv)->GetLongField(jEnv, jObj, jFid);

	if(jArgc > 0)
	{
		asArgv = (ASValue*)malloc(jArgc * sizeof(ASValue));
		for(i = 0; i < jArgc; i++)
		{
			jElement = (*jEnv)->GetObjectArrayElement(jEnv, jArgv, i);
			jClass = (*jEnv)->GetObjectClass(jEnv, jElement);
			jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
			jValue = (*jEnv)->GetLongField(jEnv, jElement, jFid);
			asArgv[i] = (ASValue)jValue;
		}
	}

	asError = ASCall((ASContext)jContext, (ASObject)jObject, (int)jArgc, asArgv, &asReturn);

	jClass = (*jEnv)->GetObjectClass(jEnv, jRet);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	(*jEnv)->SetLongField(jEnv, jRet, jFid, (jlong)asReturn);

	if(jArgc > 0)
	{
		free(asArgv);
	}

	return (jint)asError;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toInt
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASValue_toInt(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	int asValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToInt((ASContext)jContext, (ASValue)jValue);

	return (jint)asValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromInt
 * Signature: (Lcom/openplug/elips3/extension/ASContext;I)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromInt(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jint jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	asValue = ASIntToASValue((ASContext)jContext, (int)jVal);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toUnsignedInt
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)J
 */
JNIEXPORT jlong JNICALL Java_com_openplug_elips3_extension_ASValue_toUnsignedInt(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	unsigned int asValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToUnsignedInt((ASContext)jContext, (ASValue)jValue);

	return (jlong)asValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromUnsignedInt
 * Signature: (Lcom/openplug/elips3/extension/ASContext;J)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromUnsignedInt(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jlong jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	asValue = ASUnsignedIntToASValue((ASContext)jContext, (unsigned int)jVal);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toDouble
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)D
 */
JNIEXPORT jdouble JNICALL Java_com_openplug_elips3_extension_ASValue_toDouble(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	double asValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToDouble((ASContext)jContext, (ASValue)jValue);

	return (jdouble)asValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromDouble
 * Signature: (Lcom/openplug/elips3/extension/ASContext;D)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromDouble(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jdouble jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	asValue = ASDoubleToASValue((ASContext)jContext, (double)jVal);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toBool
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_openplug_elips3_extension_ASValue_toBool(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASBool asValue;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToBool((ASContext)jContext, (ASValue)jValue);

	return (jboolean)asValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromBool
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Z)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromBool(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jboolean jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	asValue = ASBoolToASValue((ASContext)jContext, (ASBool)jVal);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toASObject
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)Lcom/openplug/elips3/extension/ASObject;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_toASObject(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASObject asValue;
	jmethodID jMid;
	jobject jResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToASObject((ASContext)jContext, (ASValue)jValue);

	jClass = (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/ASObject");
	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jResult = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);
	(*jEnv)->DeleteLocalRef(jEnv, jClass);

	return jResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromASObject
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Lcom/openplug/elips3/extension/ASObject;)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromASObject(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jobject jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;
	jlong jObject;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

    if (jVal != 0)
    {
        jClass2 = (*jEnv)->GetObjectClass(jEnv, jVal);
        jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "object", "J");
        jObject = (*jEnv)->GetLongField(jEnv, jVal, jFid);
    }
    else
    {
        jObject = 0;
    }

	asValue = ASObjectToASValue((ASContext)jContext, (ASObject)jObject);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toString
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_openplug_elips3_extension_ASValue_toString(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASString asValue;
	jstring jResult;
	unsigned int asValueLen;
	char* asValueString;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToASString((ASContext)jContext, (ASValue)jValue);

	ASStringGetUTF8((ASContext)jContext, asValue, &asValueLen, 0);
	asValueString = (char*)malloc(asValueLen * sizeof(char));
	ASStringGetUTF8((ASContext)jContext, asValue, &asValueLen, asValueString);
	jResult = (*jEnv)->NewStringUTF(jEnv, asValueString);

	free(asValueString);

	return jResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromString
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Ljava/lang/String;)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromString(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jstring jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;
	const jbyte *jbType;
	ASString asString;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

    if (jVal != 0)
    {
        jbType = (*jEnv)->GetStringUTFChars(jEnv, jVal, NULL);
        ASCreateString((ASContext)jContext, jbType, &asString);
        (*jEnv)->ReleaseStringUTFChars(jEnv, jVal, jbType);
    }
    else
    {
        asString = 0;
    }
    
	asValue = ASStringToASValue((ASContext)jContext, asString);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    toASArray
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)Lcom/openplug/elips3/extension/ASArray;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_toASArray(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASObject asValue;
	jmethodID jMid;
	jobject jResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asValue = ASValueToASArray((ASContext)jContext, (ASValue)jValue);

	jClass = (*jEnv)->FindClass(jEnv, "com/openplug/elips3/extension/ASArray");
	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jResult = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);
	(*jEnv)->DeleteLocalRef(jEnv, jClass);

	return jResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    fromASArray
 * Signature: (Lcom/openplug/elips3/extension/ASContext;Lcom/openplug/elips3/extension/ASArray;)Lcom/openplug/elips3/extension/ASValue;
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ASValue_fromASArray(JNIEnv *jEnv, jclass jClass, jobject jCtxt, jobject jVal)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass2;
	jobject jValue;
	ASValue asValue;
	jmethodID jMid;
	jlong jObject;

	jClass2 = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

    if (jVal != 0)
    {
        jClass2 = (*jEnv)->GetObjectClass(jEnv, jVal);
        jFid = (*jEnv)->GetFieldID(jEnv, jClass2, "array", "J");
        jObject = (*jEnv)->GetLongField(jEnv, jVal, jFid);
    }
    else
    {
        jObject = 0;
    }

	asValue = ASArrayToASValue((ASContext)jContext, (ASArray)jObject);

	jMid = (*jEnv)->GetMethodID(jEnv, jClass, "<init>", "(J)V");
	jValue = (*jEnv)->NewObject(jEnv, jClass, jMid, (jlong)asValue);

	return jValue;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    ASGetValueType
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASValue_ASGetValueType(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASType asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asResult = ASGetValueType((ASContext)jContext, (ASValue)jValue);

	return (jint)asResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    ASIsValueUndefined
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_openplug_elips3_extension_ASValue_ASIsValueUndefined(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASBool asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asResult = ASIsValueUndefined((ASContext)jContext, (ASValue)jValue);

	return (jboolean)asResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    ASIsValueNullOrUndefined
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_openplug_elips3_extension_ASValue_ASIsValueNullOrUndefined(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASBool asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asResult = ASIsValueNullOrUndefined((ASContext)jContext, (ASValue)jValue);

	return (jboolean)asResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    ASValueForbidGCCollect
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASValue_ASValueForbidGCCollect(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASError asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asResult = ASValueForbidGCCollect((ASContext)jContext, (ASValue)jValue);

	return (jint)asResult;
}

/*
 * Class:     com_openplug_elips3_extension_ASValue
 * Method:    ASValueAllowGCCollect
 * Signature: (Lcom/openplug/elips3/extension/ASContext;)I
 */
JNIEXPORT jint JNICALL Java_com_openplug_elips3_extension_ASValue_ASValueAllowGCCollect(JNIEnv *jEnv, jobject jVal, jobject jCtxt)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	jlong jValue;
	ASError asResult;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jVal);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "value", "J");
	jValue = (*jEnv)->GetLongField(jEnv, jVal, jFid);

	asResult = ASValueAllowGCCollect((ASContext)jContext, (ASValue)jValue);

	return (jint)asResult;
}

/*
 *
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ElipsAndroidUtils_getViewFromDisplayObject(JNIEnv *jEnv, jobject jVal, jobject jCtxt, jobject jDisplayObject)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	void *view;
	jlong jObject;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	jClass = (*jEnv)->GetObjectClass(jEnv, jDisplayObject);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "object", "J");
	jObject = (*jEnv)->GetLongField(jEnv, jDisplayObject, jFid);

	view = ASGetNativeViewFromDisplayObject((ASContext)jContext, (ASObject)jObject);

	return (jobject)view;
}

/*
 *
 */
JNIEXPORT jobject JNICALL Java_com_openplug_elips3_extension_ElipsAndroidUtils_getDisplayObjectFromView(JNIEnv *jEnv, jobject jVal, jobject jCtxt, jobject jView)
{
	jlong jContext;
	jfieldID jFid;
	jclass jClass;
	ASObject displayObject;

	jClass = (*jEnv)->GetObjectClass(jEnv, jCtxt);
	jFid = (*jEnv)->GetFieldID(jEnv, jClass, "context", "J");
	jContext = (*jEnv)->GetLongField(jEnv, jCtxt, jFid);

	displayObject = ASGetDisplayObjectFromNativeView((ASContext)jContext, (void *)jView);

	return (jobject)displayObject;
}
