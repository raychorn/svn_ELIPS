/**
 * @file
 *
 * ActionScript to native mapping
 */
/*
 * (C) Copyright 2010 by Open-Plug, All Rights Reserved.
 */

#include "as_native_model_reg.h"

static ASModelAcess *gASModelAccessPif = 0;

ASError ASCreateObject(ASContext ctxt,const char *type, int argc, ASValue *argv, ASObject *obj){
	return gASModelAccessPif->pASCreateObject(ctxt,type,argc,argv,obj);
}
ASError ASCreateObjectString(ASContext ctxt,ASString type, int argc, ASValue *argv, ASObject *obj){
	return gASModelAccessPif->pASCreateObjectString(ctxt,type,argc,argv,obj);
}
ASError ASCreateArray(ASContext ctxt,unsigned int length, ASArray *obj){
	return gASModelAccessPif->pASCreateArray(ctxt,length,obj);
}
ASError ASCreateString(ASContext ctxt, const char *str, ASString *obj){
	return gASModelAccessPif->pASCreateString(ctxt,str,obj);
}

ASError ASStringGetUTF8(ASContext ctxt, ASString str, unsigned int *bufferLength, char *buffer){
	return gASModelAccessPif->pASStringGetUTF8(ctxt,str,bufferLength,buffer);
}

void * ASGetNativeViewFromDisplayObject(ASContext ctxt,ASObject displayObject){
	return gASModelAccessPif->pASGetNativeViewFromDisplayObject(ctxt,displayObject);
}
ASObject ASGetDisplayObjectFromNativeView(ASContext ctxt,void *nativeView){
	return gASModelAccessPif->pASGetDisplayObjectFromNativeView(ctxt,nativeView);
}
ASError ASCtxtGetApplicationFileSystemRoot(ASContext ctxt,unsigned int *bufferLength, char *bufferDir){
	return gASModelAccessPif->pASCtxtGetApplicationFileSystemRoot(ctxt,bufferLength,bufferDir);
}
ASError ASGetProperty(ASContext ctxt,ASObject obj, const char *s, ASValue *val){
	return gASModelAccessPif->pASGetProperty(ctxt,obj,s,val);
}
ASError ASSetProperty(ASContext ctxt,ASObject obj, const char * s, ASValue value){
	return gASModelAccessPif->pASSetProperty(ctxt,obj,s,value);
}
ASError ASCallProperty(ASContext ctxt,ASObject obj,const char * s, int argc, ASValue *argv, ASValue *ret){
	return gASModelAccessPif->pASCallProperty(ctxt,obj,s,argc,argv,ret);
}

ASError ASGetPropertyString(ASContext ctxt,ASObject obj, ASString s, ASValue *val){
	return gASModelAccessPif->pASGetPropertyString(ctxt,obj,s,val);
}
ASError ASSetPropertyString(ASContext ctxt,ASObject obj, ASString s, ASValue value){
	return gASModelAccessPif->pASSetPropertyString(ctxt,obj,s,value);
}
ASError ASCallPropertyString(ASContext ctxt,ASObject obj, ASString s,int argc, ASValue *argv, ASValue *ret){
	return gASModelAccessPif->pASCallPropertyString(ctxt,obj,s,argc,argv,ret);
}

ASError ASCall(ASContext ctxt,ASObject obj, int argc, ASValue *argv, ASValue *ret){
	return gASModelAccessPif->pASCall(ctxt,obj,argc,argv,ret);
}
int ASValueToInt(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToInt(ctxt,val);
}
unsigned int ASValueToUnsignedInt(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToUnsignedInt(ctxt,val);
}
double ASValueToDouble(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToDouble(ctxt,val);
}
ASObject ASValueToASObject(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToASObject(ctxt,val);
}
ASString ASValueToASString(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToASString(ctxt,val);
}
ASArray ASValueToASArray(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToASArray(ctxt,val);
}
ASValue ASIntToASValue(ASContext ctxt,int val){
	return gASModelAccessPif->pASIntToASValue(ctxt,val);
}
ASValue ASUnsignedIntToASValue(ASContext ctxt,unsigned int val){
	return gASModelAccessPif->pASUnsignedIntToASValue(ctxt,val);
}
ASValue ASDoubleToASValue(ASContext ctxt,double val){
	return gASModelAccessPif->pASDoubleToASValue(ctxt,val);
}
ASValue ASArrayToASValue(ASContext ctxt,ASArray val){
	return gASModelAccessPif->pASArrayToASValue(ctxt,val);
}
ASValue ASStringToASValue(ASContext ctxt,ASString val){
	return gASModelAccessPif->pASStringToASValue(ctxt,val);
}
ASValue ASObjectToASValue(ASContext ctxt,ASObject val){
	return gASModelAccessPif->pASObjectToASValue(ctxt,val);
}
ASBool  ASIsValueUndefined(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASIsValueUndefined(ctxt,val);
}
ASBool  ASIsValueNullOrUndefined(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASIsValueNullOrUndefined(ctxt,val);
}
ASError ASValueForbidGCCollect(ASContext ctxt,ASValue obj){
	return gASModelAccessPif->pASValueForbidGCCollect(ctxt, obj);
}
ASError ASValueAllowGCCollect(ASContext ctxt,ASValue obj){
	return gASModelAccessPif->pASValueAllowGCCollect(ctxt,obj);
}
ASValue ASArrayGet(ASContext ctxt,ASArray arr,unsigned int i){
	return gASModelAccessPif->pASArrayGet(ctxt,arr,i);
}
ASError ASArraySet(ASContext ctxt,ASArray arr,unsigned int i, ASValue val){
	return gASModelAccessPif->pASArraySet(ctxt,arr,i,val);
}
unsigned int ASArrayLength(ASContext ctxt,ASArray array){
	return gASModelAccessPif->pASArrayLength(ctxt,array);
}
void * ASCtxtGetUserData(ASContext ctxt){
	return gASModelAccessPif->pASCtxtGetUserData(ctxt);
}
ASError ASCtxtSetUserData(ASContext ctxt,void * userData){
	return gASModelAccessPif->pASCtxtSetUserData(ctxt,userData);
}
ASError ASCtxtEnableExceptionCatch(ASContext ctxt,ASBool enable){
	return gASModelAccessPif->pASCtxtEnableExceptionCatch(ctxt,enable);
}
ASValue ASCtxtGetLastException(ASContext ctxt){
	return gASModelAccessPif->pASCtxtGetLastException(ctxt);
}

ASType ASGetValueType(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASGetValueType(ctxt,val);
}

ASBool ASValueToBool(ASContext ctxt,ASValue val){
	return gASModelAccessPif->pASValueToBool(ctxt,val);
}
ASValue ASBoolToASValue(ASContext ctxt,ASBool val){
	return gASModelAccessPif->pASBoolToASValue(ctxt,val);
}

void * ASCtxtGetPlatformSpecificData(ASContext ctxt){
	return gASModelAccessPif->pASCtxtGetPlatformSpecificData(ctxt);
}


void ELIPSNativeLibrarySetASModel(ASModelAcess *m){
    gASModelAccessPif  = m;
}
