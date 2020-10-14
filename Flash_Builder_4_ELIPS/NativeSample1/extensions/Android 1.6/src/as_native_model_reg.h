/**
 * @file
 *
 * ActionScript to native mapping
 */
/*
 * (C) Copyright 2010 by Open-Plug, All Rights Reserved.
 */

#ifndef AS_NATIVE_MODEL_ACCESS_H
#define AS_NATIVE_MODEL_ACCESS_H

#include "as_native_model.h"

#ifdef __cplusplus
extern "C"
{
#endif


typedef struct{
	char *name;
	void *func;
}ELIPS_nativeFunctionNameTable;

typedef struct{
	unsigned int idx;
	char *name;
}ELIPS_nativeFunctionIndexTable;

typedef struct {
    ASError (*pASCreateObject)(ASContext ctxt,const char *type, int argc, ASValue *argv, ASObject *obj);
    ASError (*pASCreateObjectString)(ASContext ctxt,ASString type, int argc, ASValue *argv, ASObject *obj);
	ASError (*pASCreateArray)(ASContext ctxt,unsigned int length, ASArray *obj);
	ASError (*pASCreateString)(ASContext ctxt, const char *str, ASString *obj);
    ASError (*pASGetProperty)(ASContext ctxt,ASObject obj, const char *s, ASValue *val);
    ASError (*pASSetProperty)(ASContext ctxt,ASObject obj, const char *s, ASValue value);
    ASError (*pASCallProperty)(ASContext ctxt,ASObject obj, const char *s, int argc, ASValue *argv, ASValue *ret);
    ASError (*pASGetPropertyString)(ASContext ctxt,ASObject obj, ASString s, ASValue *val);
    ASError (*pASSetPropertyString)(ASContext ctxt,ASObject obj, ASString s, ASValue value);
    ASError (*pASCallPropertyString)(ASContext ctxt,ASObject obj, ASString s, int argc, ASValue *argv, ASValue *ret);
    ASError (*pASCall)(ASContext ctxt,ASObject obj,int argc, ASValue *argv, ASValue *ret);
    int (*pASValueToInt)(ASContext ctxt,ASValue val);
    unsigned int (*pASValueToUnsignedInt)(ASContext ctxt,ASValue val);
    double (*pASValueToDouble)(ASContext ctxt,ASValue val);
    ASObject (*pASValueToASObject)(ASContext ctxt,ASValue val);
    ASString (*pASValueToASString)(ASContext ctxt,ASValue val);
    ASArray (*pASValueToASArray)(ASContext ctxt,ASValue val);
    ASValue (*pASIntToASValue)(ASContext ctxt,int val);
    ASValue (*pASUnsignedIntToASValue)(ASContext ctxt,unsigned int val);
    ASValue (*pASDoubleToASValue)(ASContext ctxt,double val);
    ASValue (*pASArrayToASValue)(ASContext ctxt,ASArray val);
    ASValue (*pASStringToASValue)(ASContext ctxt,ASString val);
    ASValue (*pASObjectToASValue)(ASContext ctxt,ASObject val);
    ASBool  (*pASIsValueUndefined)(ASContext ctxt,ASValue val);
    ASBool  (*pASIsValueNullOrUndefined)(ASContext ctxt,ASValue val);
    ASError (*pASValueForbidGCCollect)(ASContext ctxt,ASValue obj);
    ASError (*pASValueAllowGCCollect)(ASContext ctxt,ASValue obj);
    ASValue (*pASArrayGet)(ASContext ctxt,ASArray arr,unsigned int i);
    ASError (*pASArraySet)(ASContext ctxt,ASArray arr,unsigned int i, ASValue val);
    unsigned int (*pASArrayLength)(ASContext ctxt,ASArray arr);
    void * (*pASCtxtGetUserData)(ASContext ctxt);
    ASError (*pASCtxtSetUserData)(ASContext ctxt,void * userData);
    ASError (*pASCtxtEnableExceptionCatch)(ASContext ctxt,ASBool enable);
    ASValue (*pASCtxtGetLastException)(ASContext ctxt);
	ASType  (*pASGetValueType)(ASContext ctxt,ASValue val);
	ASBool (*pASValueToBool)(ASContext ctxt,ASValue val);
	ASValue (*pASBoolToASValue)(ASContext ctxt,ASBool val);
	void * (*pASCtxtGetPlatformSpecificData)(ASContext ctxt);
	void  (*pASCtxtSetPlatformSpecificData)(ASContext ctxt,void *data);
	ASError (*pASStringGetUTF8)(ASContext ctxt, ASString str, unsigned int *bufferLength, char *buffer);
	void * (*pASGetNativeViewFromDisplayObject)(ASContext ctxt,ASObject displayObject);
	ASObject (*pASGetDisplayObjectFromNativeView)(ASContext ctxt,void *nativeView);
	ASError (*pASCtxtGetApplicationFileSystemRoot)(ASContext ctxt,unsigned int *bufferLength, char *bufferDir);
} ASModelAcess;


	//to be implemented by the native dynamic library
	void ELIPSNativeLibrarySetASModel(ASModelAcess *lASModelAcessComp);
	void ELIPSNativeLibraryGetFunctionTable(ELIPS_nativeFunctionNameTable **table,unsigned int *size);
	void ELIPSNativeLibraryReleaseFunctionTable(ELIPS_nativeFunctionNameTable *table,unsigned int size);

	typedef void (*ELIPSNativeLibrarySetASModel_t)(ASModelAcess *lASModelAcessComp);
	typedef void (*ELIPSNativeLibraryGetFunctionTable_t)(ELIPS_nativeFunctionNameTable **table,unsigned int *size);
	typedef void (*ELIPSNativeLibraryReleaseFunctionTable_t)(ELIPS_nativeFunctionNameTable *table,unsigned int size);

#ifdef __cplusplus
}
#endif

#endif
