/**
 * @file
 *
 * ActionScript to native mapping
 */
/*
 * (C) Copyright 2010 by Open-Plug, All Rights Reserved.
 */

#ifndef AS_NATIVE_MODEL_H
#define AS_NATIVE_MODEL_H

/** the ASContext is an object aggregating all the AS3 model and states, it is and has to be passed to each functions*/
typedef unsigned int ASContext;

typedef enum{
	ASTypeBool = 0,/**< 'Boolean' AS3 type*/
	ASTypeInt,/**< 'int' AS3 type*/
	ASTypeUnsignedInt,/**< 'uint' AS3 type*/
	ASTypeDouble,/**< 'Number' AS3 type*/
	ASTypeString,/**< 'String' AS3 type*/
	ASTypeObject,/**< 'Object' or any typed object (that is not a String or an Array) AS3 type*/
	ASTypeArray,/**< 'Array' AS3 type*/
	ASTypeUndefined,/**< used for undefined types*/
	_ASTypePAD = 0x7FFFFFFF
}ASType;

/** ASValue is equivalent to the '*' type in AS3, or when an object has no defined type 
 * see below all the *ToASValue() functions and the ASValueTo*() ones 
 * The real type of an ASValue can be queried with @ASGetValueType
 */
typedef unsigned int ASValue;

/** ASObject is equivalent to the AS3 type 'Object' or to any typed object, that is not a 'String' or an 'Array' */
typedef unsigned int ASObject;

/** ASArray is the equivalent to the 'Array' AS3 type */
typedef unsigned int ASArray;

/** ASString is the equivalent to the 'String' AS3 type */
typedef unsigned int ASString;

/** ASBool is the equivalent to the 'Boolean' AS3 type */
typedef unsigned char ASBool;
#define ASTrue 1
#define ASFalse 0

#define ASNULL 0

typedef enum{
	ASNoError = 0, /**< OK, no error detected */
	ASErrorExceptionRaised,/**< An exception has been raised and catched automatically, see @ASCtxtEnableExceptionCatch and @ASCtxtGetLastException*/
	ASErrorPropertyNotFound,/**< property doesn't exists on the object */
	ASErrorMemory,/**< memory issue */
	ASErrorWrongParameters,/**< wrong parameters passed */
	ASErrorUnsupported,/**< wrong parameters passed */
	ASErrorUnknown,/**< error unknon */
	_ASErrorPAD = 0x7FFFFFFF
}ASError;


/**
 * @brief Create an Action script object, given a type name.
 *
 * The "type" is a string with a full qualified name has used with the AS3 function getDefinitionByName()
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   type        A const char * with a fully qualified type name, as used by getDefinitionByName().
 * @param[in]   argc        Number of arguments to be passed to the object constructor.
 * @param[in]   argv        C array of argc ASValues, to be passed as arguments to the created object constructor.
 * @param[out]  obj         The created Object.
 *
 * @return                  ASNoError if the object has been correctly created, else an error code
 *
 */
ASError ASCreateObject(ASContext ctxt,const char* type, int argc, ASValue *argv, ASObject *obj);

/**
 * @brief Create an Action script object, given a type name.
 *
 * The "type" is a string with a full qualified name has used with the AS3 function getDefinitionByName()
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   type        An ASString (see ASCreateString) with a fully qualified type name, as used by getDefinitionByName().
 * @param[in]   argc        Number of arguments to be passed to the object constructor.
 * @param[in]   argv        C array of argc ASValues, to be passed as arguments to the created object constructor.
 * @param[out]  obj         The created Object.
 *
 * @return                  ASNoError if the object has been correctly created, else an error code
 *
 */
ASError ASCreateObjectString(ASContext ctxt,ASString type, int argc, ASValue *argv, ASObject *obj);

/**
 * @brief Create an AS3 Array usable in C
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   length      The length to be passed to the AS3 Array constructor
 * @param[out]  obj         The created Array.
 *
 * @return                  ASNoError if the Array has been correctly created,  else an error code
 *
 */
ASError ASCreateArray(ASContext ctxt,unsigned int length, ASArray *obj);

/**
 * @brief Get a value from an index out of an AS3 Array
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   arr         The Array
 * @param[in]   i           The index to get the property
 *
 * @return                  the generic ASValue at index i, can be undefined
 *
 */
ASValue ASArrayGet(ASContext ctxt,ASArray arr,unsigned int i);
/**
 * @brief Set a value at index of an AS3 Array
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   arr         The Array
 * @param[in]   i           The index to get the property
 * @param[in]   val         The value to be put at i
 *
 * @return                  ASNoError if no error
 *
 */
ASError ASArraySet(ASContext ctxt,ASArray arr,unsigned int i, ASValue val);

/**
 * @brief Equivalent in C of the AS3 array.length
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   arr         The Array
 *
 * @return                  length of arr
 *
 */
unsigned int ASArrayLength(ASContext ctxt,ASArray arr);

/**
 * @brief Create an AS3 String
 *
 * @param[in]   ctxt        The AS3 context.
 * @param[in]   str	       UTF8 string used to create the ASString, the buffer is duplicated so it can be freed whenever yu want
 * @param[out]  obj         The created String.
 *
 * @return                  ASNoError if the String has been correctly created, else an error code
 *
 */
ASError ASCreateString(ASContext ctxt, const char *str, ASString *obj);


/**
 * @brief Create an AS3 String
 *
 * @param[in]       ctxt                 The AS3 context.
 * @param[in]       str	                 The ASString to be converted in a UTF8 buffer
 * @param[in/out]   bufferLength         Can't be null (0) ,if "buffer" is NULL (0), bufferLength will be filled with the needed size in bytes (the trailing 0 is part of this size)
 *                                       else bufferLength has to be filled with the size in bytes of buffer, and will be modified with the actual number of filled bytes (with the trailing 0)
 * @param[in/out]   buffer               Can be null (0), in that case,  only bufferLength is set, use that to get the exact size of the buffer you need for a subsequent call to ASStringGetUTF8
 *                                       else buffer is an allocated (stack, heap, whatever) buffer of bufferLength bytes, that will be filled with the UTF8 chars of obj, with a trailing 0.
 *
 * @return                  ASNoError if the String has been correctly converted, else an error code
 *
 */
ASError ASStringGetUTF8(ASContext ctxt, ASString str, unsigned int *bufferLength, char *buffer);



/**
 * @brief Get a property from an AS3 object, using a const char * as a key
 *
 * This functions looks for dynamic properties, properties and members
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object on which the property has to be found	
 * @param[in]    s 	       UTF8 string used to lookup the property, can be destroyed after the call to this function
 * @param[out]  val         The returned value of the property, can be undefined if not found
 *
 * @return                  ASNoError if the property has been found, else an error code
 *
 */
ASError ASGetProperty(ASContext ctxt,ASObject obj, const char *s, ASValue *val);

/**
 * @brief Get a property from an AS3 object, using an ASString as a key
 *
 * This functions looks for dynamic properties, properties and members
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object on which the property has to be found	
 * @param[in]    s 	       ASString (see  ASCreateString) used to lookup the property
 * @param[out]  val         The returned value of the property, can be undefined if not found
 *
 * @return                  ASNoError if the property has been found, else an error code
 *
 */
ASError ASGetPropertyString(ASContext ctxt,ASObject obj, ASString s, ASValue *val);


/**
 * @brief Set a property on an AS3 object, using a const char * as a key
 *
 * If the property doesn't exists on the targetted object, this functions creates the property if the targetted object class is dynamic
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object on which the property has to be found	
 * @param[in]    s 	        UTF8 string used to lookup the property, can be destroyed after the call to this function
 * @param[in]    val          The value to be set on the property
 *
 * @return                  ASNoError if the property has been found, else an error code
 *
 */
ASError ASSetProperty(ASContext ctxt,ASObject obj, const char *s, ASValue value);


/**
 * @brief Set a property on an AS3 object, using an ASString as a key
 *
 * If the property doesn't exists on the targetted object, this functions creates the property if the targetted object class is dynamic
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object on which the property has to be found	
 * @param[in]    s 	       ASString (see  ASCreateString) used to lookup the property
 * @param[in]    val          The value to be set on the property
 *
 * @return                  ASNoError if the property has been found, else an error code
 *
 */
ASError ASSetPropertyString(ASContext ctxt,ASObject obj, ASString s, ASValue value);

/**
 * @brief Call a property on an AS3 object,  using a const char * as a key
 *
 * Used to call methods on an object, or field with a Function object inside.
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object on which the property has to be found	
 * @param[in]    s 	        UTF8 string used to lookup the property, can be destroyed after the call to this function
 * @param[in]   argc         Number of arguments to be passed to the method/Function.
 * @param[in]   argv         C array of argc ASValues, to be passed as arguments to the method/Function.
* @param[out] ret           The return value of called method/Function.
 *
 * @return                  ASNoError if the function has been called, else an error code
 *
 */
ASError ASCallProperty(ASContext ctxt,ASObject obj, const char *s,int argc, ASValue *argv, ASValue *ret);

/**
 * @brief Call a property on an AS3 object,  using an ASString as a key
 *
 * Used to call methods on an object, or field with a Function object inside.
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object on which the property has to be found	
 * @param[in]    s 	        ASString (see  ASCreateString) used to lookup the property
 * @param[in]   argc         Number of arguments to be passed to the method/Function.
 * @param[in]   argv         C array of argc ASValues, to be passed as arguments to the method/Function.
* @param[out]  ret           The return value of called method/Function.
 *
 * @return                  ASNoError if the function has been called, else an error code
 *
 */
ASError ASCallPropertyString(ASContext ctxt,ASObject obj, ASString s,int argc, ASValue *argv, ASValue *ret);


/**
 * @brief Call an AS3 Function.
 *
 * usefull for callback passed from AS3 to C for example
 * Can throw an exception
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    obj	       The AS3 object that will be called
 * @param[in]   argc         Number of arguments to be passed to the Function.
 * @param[in]   argv         C array of argc ASValues, to be passed as arguments to the Function.
* @param[out]  ret           The return value of called Function.
 *
 * @return                  ASNoError if the function has been called, else an error code
 *
 */
ASError ASCall(ASContext ctxt,ASObject obj, int argc, ASValue *argv, ASValue *ret);


/**
 * @brief Convert a generic ASValue to a C integer (int)
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The generic ASValue to be converted
 *
 * @return                  converted ASValue to int
 */
int ASValueToInt(ASContext ctxt,ASValue val);

/**
 * @brief Convert  a C integer (int) to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The integer to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASIntToASValue(ASContext ctxt,int val);


/**
 * @brief Convert a generic ASValue to a C unsigned integer (unsigned int)
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The generic ASValue to be converted
 *
 * @return                  converted ASValue to an unsigned int
 */
unsigned int ASValueToUnsignedInt(ASContext ctxt,ASValue val);

/**
 * @brief Convert  a C unsigned integer (unsigned int) to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The unsigned integer to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASUnsignedIntToASValue(ASContext ctxt,unsigned int val);

/**
 * @brief Convert a generic ASValue to a C double precison floating point number (double)
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val           The generic ASValue to be converted
 *
 * @return                  converted ASValue to a double
 */
double ASValueToDouble(ASContext ctxt,ASValue val);

/**
 * @brief Convert  a C double (double) to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The double to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASDoubleToASValue(ASContext ctxt,double val);

/**
 * @brief Convert a generic ASValue to a boolean
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val           The generic ASValue to be converted
 *
 * @return                  converted ASValue to a boolean
 */
ASBool ASValueToBool(ASContext ctxt,ASValue val);

/**
 * @brief Convert  a boolean to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The boolean to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASBoolToASValue(ASContext ctxt,ASBool val);

/**
 * @brief Convert a generic ASValue to an AS ASObject
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val           The generic ASValue to be converted
 *
 * @return                  converted ASValue to an ASObject, can be null if passed value is not an object
 */
ASObject ASValueToASObject(ASContext ctxt,ASValue val);

/**
 * @brief Convert  an AS Object to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The object to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASObjectToASValue(ASContext ctxt,ASObject val);

/**
 * @brief Convert a generic ASValue to an AS String
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val           The generic ASValue to be converted
 *
 * @return                  converted ASValue to an ASString, , can be null if passed value is not a String
 */
ASString ASValueToASString(ASContext ctxt,ASValue val);
/**
 * @brief Convert  an AS String to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The String  to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASStringToASValue(ASContext ctxt,ASString val);

/**
 * @brief Convert a generic ASValue to an AS Array
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val           The generic ASValue to be converted
 *
 * @return                  converted ASValue to an ASArray , can be null if passed value is not an Array
 */
ASArray ASValueToASArray(ASContext ctxt,ASValue val);

/**
 * @brief Convert  an AS Array to a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The Array  to be converted
 *
 * @return                  converted ASValue
 */
ASValue ASArrayToASValue(ASContext ctxt,ASArray val);


/**
 * @brief get the type out of a generic ASValue
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The generic ASValue to be probed
 *
 * @return                 the passed ASValue type, can  be ASTypeUndefined if the passed ASValue is nul or undifined or malformed
 */
ASType ASGetValueType(ASContext ctxt,ASValue val);

/**
 * @brief Check if the passed ASValue is undefined 
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The generic ASValue to be probed
 *
 * @return                 ASTrue is val undefined, ASFalse otherwise
 */
ASBool  ASIsValueUndefined(ASContext ctxt,ASValue val);

/**
 * @brief Check if the passed ASValue is undefined or null
 *
 * @param[in]    ctxt        The AS3 context.
 * @param[in]    val       The generic ASValue to be probed
 *
 * @return                 ASTrue is val undefined, or null ASFalse otherwise
 */
ASBool  ASIsValueNullOrUndefined(ASContext ctxt,ASValue val);


/**
 * @brief Forbid any Garbage Collection for the passed ASValue
 *
 * @param[in]    ctxt    The AS3 context.
 * @param[in]    obj      The generic ASValue to be saved from any Garbage collection
 *
 * @return                ASNoError if no issue
 */
ASError ASValueForbidGCCollect(ASContext ctxt,ASValue obj);

/**
 * @brief Allow  Garbage Collection for the passed ASValue
 *
 * to be called after a ASValueForbidGCCollect call
 *
 * @param[in]    ctxt    The AS3 context.
 * @param[in]    obj      Re-allow the Garbage collection of the passed ASValue
 *
 * @return                ASNoError if no issue
 */
ASError ASValueAllowGCCollect(ASContext ctxt,ASValue obj);


/**
 * @brief Stores a user pointer on the ASContext,
 *
 * This pointer can be retrieved with ASCtxtGetUserData

 *
 * @param[in]    ctxt    The AS3 context.
 * @param[in]    userData      User pointer to be stored on the ASContext 
 *
 * @return                ASNoError if no issue
 */
ASError ASCtxtSetUserData(ASContext ctxt,void * userData);

/**
 * @brief Retrieved the userData stored on the ASContext 
 *
 * This pointer has been stored on the ASContext with  ASCtxtSetUserData
 *
 * @param[in]    ctxt    The AS3 context.
 *
 * @return                the stored user data
 */
void * ASCtxtGetUserData(ASContext ctxt);

/**
 * @brief Enable or disable automatic exception check of the functions of this .h 
 *
 * If enabled, any exception thrown inside the functions of this .h are automatically catched 
 * if so the function will return ASErrorExceptionRaised and the exception can be retrieved
 * using @ASCtxtGetLastException.
 *If disabled: the exception will propagate to any upper level try catch block in AS3 code, 
 * so the current C function will be left up to this try block.
 * Use disable only if you want to treat exception in the AS code surounding the call to the native method
 *
 * @param[in]    ctxt    The AS3 context.
 * @param[in]    enable   ASTrue enable th eautomaticexception cach and the ASErrorExceptionRaised type of error, ASFalse to disable it
 *
 * @return                ASNoError if no issue
 */
ASError ASCtxtEnableExceptionCatch(ASContext ctxt,ASBool enable);

/**
 * @brief Get the latest exception thrown by a functions in this .h
 *
 * See @ASCtxtEnableExceptionCatch
 *
 * @param[in]    ctxt    The AS3 context.
 *
 * @return                the latest thrown exception (can be null or undefined)
 */
ASValue ASCtxtGetLastException(ASContext ctxt);


/**
 * @brief From an ELIPS DisplayObject, get, if available, the associated native view
 *
 * If no native view is associated to the given DisplayObject, NULL is returned.
 * The returned void * has to be casted to the right platform type, ex 
 *  - on iPhone use UIView *
 *  - on Android (NDK part) : jobject
 *
 * @param[in]    ctxt				The AS3 context.
 * @param[in]    displayObject		DisplayObject on which we want to get the corresponding native view.
 *
 * @return               ASNULL if no native view is associated to the passed displayObject
 */
void * ASGetNativeViewFromDisplayObject(ASContext ctxt,ASObject displayObject);

/**
 * @brief From a native view, get, if available, the associated ELIPS DisplayObject
 *
 * If no DisplayObject is associated to the given native view, ASNULL is returned.
 * The provided native view comes from the right platform type, and has to be casted to void *, ex:
 *  - on iPhone : UIView *
 *  - on Android (NDK part) : jobject
 *
 * @param[in]    ctxt				The AS3 context.
 * @param[in]    nativeView			native view on which we want to get the corresponding ELIPS DisplayObject.
 *
 * @return               ASNULL if no native view is associated to the passed displayObject
 */
ASObject ASGetDisplayObjectFromNativeView(ASContext ctxt,void *nativeView);


/**
 * @brief Get the application root file system where action script is writing/reading its files
 *
 * @param[in]       ctxt                 The AS3 context.
 * @param[in/out]   bufferLength         Can't be null (0) , if "bufferDir" is NULL (0), bufferLength will be filled with the needed size in bytes (the trailing 0 is part of this size)
 *                                       else bufferLength has to be filled with the size in bytes of bufferDir, and will be modified with the actual number of filled bytes (with the trailing 0)
 * @param[in/out]   buffer               Can be null (0), in that case,  only bufferLength is set, use that to get the exact size of the buffer you need for a subsequent call to ASCtxtGetApplicationFileSystemRoot
 *                                       else bufferDir is an allocated (stack, heap, whatever) buffer of bufferLength bytes, that will be filled with the UTF8 chars representing the Application Root file system with a trailing 0.
 *
 * @return                  ASNoError if the String has been correctly created, else an error code
 *
 */
ASError ASCtxtGetApplicationFileSystemRoot(ASContext ctxt,unsigned int *bufferLength, char *bufferDir);

/**
 * @brief Get a platform specific pointer (see specific platform extension .h to use it)
 *
 * @param[in]    ctxt    The AS3 context.
 *
 * @return                the specific platform data
 */
void * ASCtxtGetPlatformSpecificData(ASContext ctxt);
#endif
