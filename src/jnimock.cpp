#include <jnimock/jnimock.h>

//-----------------------------------------------------------------------------
// The JNIEnvMoc implementation
//-----------------------------------------------------------------------------
namespace jnimock {

static jint GetVersion(JNIEnv* env) {
	return ((JNIEnvMock*)env)->GetVersion();
}

static jclass DefineClass(JNIEnv* env, const char *name, jobject loader,
		const jbyte* buf, jsize bufLen) {
	return ((JNIEnvMock*)env)->DefineClass(name, loader, buf, bufLen);
}
static jclass FindClass(JNIEnv* env, const char* name) {
	return ((JNIEnvMock*)env)->FindClass(name);
}

static jmethodID FromReflectedMethod(JNIEnv* env, jobject method) {
	return ((JNIEnvMock*)env)->FromReflectedMethod(method);
}

static jfieldID FromReflectedField(JNIEnv* env, jobject field) {
	return ((JNIEnvMock*)env)->FromReflectedField(field);
}

static jobject ToReflectedMethod(JNIEnv* env, jclass cls,
		jmethodID methodID, jboolean isStatic) {
	return ((JNIEnvMock*)env)->ToReflectedMethod(cls, methodID, isStatic);
}

static jclass GetSuperclass(JNIEnv* env, jclass clazz) {
	return ((JNIEnvMock*)env)->GetSuperclass(clazz);
}

static jboolean IsAssignableFrom(JNIEnv* env, jclass clazz1, jclass clazz2) {
	return ((JNIEnvMock*)env)->IsAssignableFrom(clazz1, clazz2);
}

static jobject ToReflectedField(JNIEnv* env, jclass cls,
		jfieldID fieldID, jboolean isStatic) {
	return ((JNIEnvMock*)env)->ToReflectedField(cls, fieldID, isStatic);
}

static jint Throw(JNIEnv* env, jthrowable obj) {
	return ((JNIEnvMock*)env)->Throw(obj);
}

static jint ThrowNew(JNIEnv* env, jclass clazz, const char* message) {
	return ((JNIEnvMock*)env)->ThrowNew(clazz, message);
}

static jthrowable ExceptionOccurred(JNIEnv* env) {
	return ((JNIEnvMock*)env)->ExceptionOccurred();
}

static void ExceptionDescribe(JNIEnv* env) {
	((JNIEnvMock*)env)->ExceptionDescribe();
}

static void ExceptionClear(JNIEnv* env) {
	((JNIEnvMock*)env)->ExceptionClear();
}

static void FatalError(JNIEnv* env, const char* msg) {
	((JNIEnvMock*)env)->FatalError(msg);
}

static jint PushLocalFrame(JNIEnv* env, jint capacity) {
	return ((JNIEnvMock*)env)->PushLocalFrame(capacity);
}

static jobject PopLocalFrame(JNIEnv* env, jobject result) {
	return ((JNIEnvMock*)env)->PopLocalFrame(result);
}

static jobject NewGlobalRef(JNIEnv* env, jobject obj) {
	return ((JNIEnvMock*)env)->NewGlobalRef(obj);
}

static void DeleteGlobalRef(JNIEnv* env, jobject globalRef) {
	((JNIEnvMock*)env)->DeleteGlobalRef(globalRef);
}

static void DeleteLocalRef(JNIEnv* env, jobject localRef) {
	((JNIEnvMock*)env)->DeleteLocalRef(localRef); }

static jboolean IsSameObject(JNIEnv* env, jobject ref1, jobject ref2) {
	return ((JNIEnvMock*)env)->IsSameObject(ref1, ref2);
}

static jobject NewLocalRef(JNIEnv* env, jobject ref) {
	return ((JNIEnvMock*)env)->NewLocalRef(ref);
}

static jint EnsureLocalCapacity(JNIEnv* env, jint capacity) {
	return ((JNIEnvMock*)env)->EnsureLocalCapacity(capacity);
}

static jobject AllocObject(JNIEnv* env, jclass clazz) {
	return ((JNIEnvMock*)env)->AllocObject(clazz);
}

static jobject NewObject(JNIEnv* env, jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    jobject result = ((JNIEnvMock*)env)->NewObjectV(clazz, methodID, args);
    va_end(args);
    return result;
}

static jobject NewObjectV(JNIEnv* env, jclass clazz,
		jmethodID methodID, va_list args) {
	return ((JNIEnvMock*)env)->NewObjectV(clazz, methodID, args);
}

static jobject NewObjectA(JNIEnv* env, jclass clazz,
		jmethodID methodID, const jvalue* args) {
	return ((JNIEnvMock*)env)->NewObjectA(clazz, methodID, args);
}

static jclass GetObjectClass(JNIEnv* env, jobject obj) {
	return ((JNIEnvMock*)env)->GetObjectClass(obj);
}

static jboolean IsInstanceOf(JNIEnv* env, jobject obj, jclass clazz) {
	return ((JNIEnvMock*)env)->IsInstanceOf(obj, clazz);
}

static jmethodID GetMethodID(JNIEnv* env, jclass clazz,
		const char* name, const char* sig) {
	return ((JNIEnvMock*)env)->GetMethodID(clazz, name, sig);
}

#define JNI_CALL_TYPE_METHOD(_jtype, _jname)                                    		\
                                                           								\
static _jtype Call##_jname##Method(JNIEnv* env, jobject obj,							\
		jmethodID methodID, ...) {   													\
    _jtype result;                                                      				\
    va_list args;                                                       				\
    va_start(args, methodID);                                           				\
    result = ((JNIEnvMock*)env)->Call##_jname##MethodV(obj, methodID,      				\
                args);                                                  				\
    va_end(args);                                                       				\
    return result;                                                      				\
}
#define JNI_CALL_TYPE_METHODV(_jtype, _jname)                                   		\
                                                           								\
static _jtype Call##_jname##MethodV(JNIEnv* env, jobject obj, jmethodID methodID,		\
    va_list args) {                                                      				\
	return ((JNIEnvMock*)env)->Call##_jname##MethodV(obj, methodID, args);				\
}
#define JNI_CALL_TYPE_METHODA(_jtype, _jname)                                   		\
                                                           								\
static _jtype Call##_jname##MethodA(JNIEnv* env, jobject obj, jmethodID methodID, 		\
		const jvalue* args) {                                                     			\
	return ((JNIEnvMock*)env)->Call##_jname##MethodA(obj, methodID, args);				\
}

#define JNI_CALL_TYPE(_jtype, _jname)                                           		\
JNI_CALL_TYPE_METHOD(_jtype, _jname)                                        			\
JNI_CALL_TYPE_METHODV(_jtype, _jname)                                       			\
JNI_CALL_TYPE_METHODA(_jtype, _jname)

JNI_CALL_TYPE(jobject, Object)
JNI_CALL_TYPE(jboolean, Boolean)
JNI_CALL_TYPE(jbyte, Byte)
JNI_CALL_TYPE(jchar, Char)
JNI_CALL_TYPE(jshort, Short)
JNI_CALL_TYPE(jint, Int)
JNI_CALL_TYPE(jlong, Long)
JNI_CALL_TYPE(jfloat, Float)
JNI_CALL_TYPE(jdouble, Double)

static void CallVoidMethod(JNIEnv* env, jobject obj, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    ((JNIEnvMock*)env)->CallVoidMethodV(obj, methodID, args);
    va_end(args);
}

static void CallVoidMethodV(JNIEnv* env, jobject obj,
		jmethodID methodID, va_list args) {
	((JNIEnvMock*)env)->CallVoidMethodV(obj, methodID, args);
}

static void CallVoidMethodA(JNIEnv* env, jobject obj,
		jmethodID methodID, const jvalue* args) {
	((JNIEnvMock*)env)->CallVoidMethodA(obj, methodID, args);
}

#define JNI_CALL_NONVIRT_TYPE_METHOD(_jtype, _jname)                            		\
                                                           	   	   	   	 	 	 	 	\
static _jtype CallNonvirtual##_jname##Method(JNIEnv* env, jobject obj, jclass clazz,  	\
		jmethodID methodID, ...) {                                           			\
    _jtype result;                                                      				\
    va_list args;                                                       				\
    va_start(args, methodID);                                           				\
    result = ((JNIEnvMock*)env)->CallNonvirtual##_jname##MethodV(obj,      				\
                clazz, methodID, args);                                 				\
    va_end(args);                                                       				\
    return result;                                                      				\
}
#define JNI_CALL_NONVIRT_TYPE_METHODV(_jtype, _jname)                           		\
                                                           	   	   	   	   	   	   	    \
static _jtype CallNonvirtual##_jname##MethodV(JNIEnv* env, jobject obj, jclass clazz,	\
		jmethodID methodID, va_list args) {                                  			\
	return ((JNIEnvMock*)env)->CallNonvirtual##_jname##MethodV(obj, clazz,   			\
				methodID, args); 														\
}
#define JNI_CALL_NONVIRT_TYPE_METHODA(_jtype, _jname)                           		\
                                                           	   	   	   	   	   	   	   	\
static _jtype CallNonvirtual##_jname##MethodA(JNIEnv* env, jobject obj, jclass clazz,	\
		jmethodID methodID, const jvalue* args) {                                 			\
	return ((JNIEnvMock*)env)->CallNonvirtual##_jname##MethodA(obj, clazz,   			\
				methodID, args);														\
}

#define JNI_CALL_NONVIRT_TYPE(_jtype, _jname)                                   		\
JNI_CALL_NONVIRT_TYPE_METHOD(_jtype, _jname)                                			\
JNI_CALL_NONVIRT_TYPE_METHODV(_jtype, _jname)                               			\
JNI_CALL_NONVIRT_TYPE_METHODA(_jtype, _jname)

JNI_CALL_NONVIRT_TYPE(jobject, Object)
JNI_CALL_NONVIRT_TYPE(jboolean, Boolean)
JNI_CALL_NONVIRT_TYPE(jbyte, Byte)
JNI_CALL_NONVIRT_TYPE(jchar, Char)
JNI_CALL_NONVIRT_TYPE(jshort, Short)
JNI_CALL_NONVIRT_TYPE(jint, Int)
JNI_CALL_NONVIRT_TYPE(jlong, Long)
JNI_CALL_NONVIRT_TYPE(jfloat, Float)
JNI_CALL_NONVIRT_TYPE(jdouble, Double)

static void CallNonvirtualVoidMethod(JNIEnv* env, jobject obj,
		jclass clazz, jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    ((JNIEnvMock*)env)->CallNonvirtualVoidMethodV(obj, clazz, methodID, args);
    va_end(args);
}
static void CallNonvirtualVoidMethodV(JNIEnv* env, jobject obj, jclass clazz,
		jmethodID methodID, va_list args){
	((JNIEnvMock*)env)->CallNonvirtualVoidMethodV(obj, clazz, methodID, args);
}
static void CallNonvirtualVoidMethodA(JNIEnv* env, jobject obj, jclass clazz,
    jmethodID methodID, const jvalue* args) {
	((JNIEnvMock*)env)->CallNonvirtualVoidMethodA(obj, clazz, methodID, args);
}

static jfieldID GetFieldID(JNIEnv* env, jclass clazz,
		const char* name, const char* sig) {
	return ((JNIEnvMock*)env)->GetFieldID(clazz, name, sig);
}

static jobject GetObjectField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetObjectField(obj, fieldID);
}
static jboolean GetBooleanField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetBooleanField(obj, fieldID);
}
static jbyte GetByteField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetByteField(obj, fieldID);
}
static jchar GetCharField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetCharField(obj, fieldID);
}
static jshort GetShortField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetShortField(obj, fieldID);
}
static jint GetIntField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetIntField(obj, fieldID);
}
static jlong GetLongField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetLongField(obj, fieldID);
}

static jfloat GetFloatField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetFloatField(obj, fieldID);
}

static jdouble GetDoubleField(JNIEnv* env, jobject obj, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetDoubleField(obj, fieldID);
}

static void SetObjectField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jobject value) {
	((JNIEnvMock*)env)->SetObjectField(obj, fieldID, value);
}
static void SetBooleanField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jboolean value) {
	((JNIEnvMock*)env)->SetBooleanField(obj, fieldID, value);
}
static void SetByteField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jbyte value) {
	((JNIEnvMock*)env)->SetByteField(obj, fieldID, value);
}
static void SetCharField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jchar value) {
	((JNIEnvMock*)env)->SetCharField(obj, fieldID, value);
}
static void SetShortField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jshort value) {
	((JNIEnvMock*)env)->SetShortField(obj, fieldID, value);
}
static void SetIntField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jint value) {
	((JNIEnvMock*)env)->SetIntField(obj, fieldID, value);
}
static void SetLongField(JNIEnv* env, jobject obj,
		jfieldID fieldID, jlong value) {
	((JNIEnvMock*)env)->SetLongField(obj, fieldID, value);
}

static void SetFloatField(JNIEnv* env, jobject obj, jfieldID fieldID, jfloat value) {
	((JNIEnvMock*)env)->SetFloatField(obj, fieldID, value);
}

static void SetDoubleField(JNIEnv* env, jobject obj, jfieldID fieldID, jdouble value) {
	((JNIEnvMock*)env)->SetDoubleField(obj, fieldID, value);
}

static jmethodID GetStaticMethodID(JNIEnv* env, jclass clazz,
		const char* name, const char* sig) {
	return ((JNIEnvMock*)env)->GetStaticMethodID(clazz, name, sig);
}

#define JNI_CALL_STATIC_TYPE_METHOD(_jtype, _jname)                             		\
                                                           								\
static _jtype CallStatic##_jname##Method(JNIEnv* env, jclass clazz,      				\
		jmethodID methodID, ...) {   													\
    _jtype result;                                                      				\
    va_list args;                                                       				\
    va_start(args, methodID);                                           				\
    result = ((JNIEnvMock*)env)->CallStatic##_jname##MethodV(clazz,        				\
                methodID, args);                                        				\
    va_end(args);                                                       				\
    return result;                                                      				\
}
#define JNI_CALL_STATIC_TYPE_METHODV(_jtype, _jname)                            		\
                                                           								\
static _jtype CallStatic##_jname##MethodV(JNIEnv* env, jclass clazz,					\
		jmethodID methodID,  va_list args)  {   										\
	return ((JNIEnvMock*)env)->CallStatic##_jname##MethodV(clazz, methodID, args);  	\
}
#define JNI_CALL_STATIC_TYPE_METHODA(_jtype, _jname)                            		\
                                                           								\
static _jtype CallStatic##_jname##MethodA(JNIEnv* env, jclass clazz,  					\
		jmethodID methodID, const jvalue* args) {        										\
	return ((JNIEnvMock*)env)->CallStatic##_jname##MethodA(clazz, methodID, args);		\
}

#define JNI_CALL_STATIC_TYPE(_jtype, _jname)                                    		\
JNI_CALL_STATIC_TYPE_METHOD(_jtype, _jname)                                 			\
JNI_CALL_STATIC_TYPE_METHODV(_jtype, _jname)											\
JNI_CALL_STATIC_TYPE_METHODA(_jtype, _jname)

JNI_CALL_STATIC_TYPE(jobject, Object)
JNI_CALL_STATIC_TYPE(jboolean, Boolean)
JNI_CALL_STATIC_TYPE(jbyte, Byte)
JNI_CALL_STATIC_TYPE(jchar, Char)
JNI_CALL_STATIC_TYPE(jshort, Short)
JNI_CALL_STATIC_TYPE(jint, Int)
JNI_CALL_STATIC_TYPE(jlong, Long)
JNI_CALL_STATIC_TYPE(jfloat, Float)
JNI_CALL_STATIC_TYPE(jdouble, Double)

static void CallStaticVoidMethod(JNIEnv* env, jclass clazz,
		jmethodID methodID, ...) {
    va_list args;
    va_start(args, methodID);
    ((JNIEnvMock*)env)->CallStaticVoidMethodV(clazz, methodID, args);
    va_end(args);
}
static void CallStaticVoidMethodV(JNIEnv* env, jclass clazz,
		jmethodID methodID, va_list args) {
	((JNIEnvMock*)env)->CallStaticVoidMethodV(clazz, methodID, args);
}
static void CallStaticVoidMethodA(JNIEnv* env, jclass clazz,
		jmethodID methodID, const jvalue* args){
	((JNIEnvMock*)env)->CallStaticVoidMethodA(clazz, methodID, args);
}

static jfieldID GetStaticFieldID(JNIEnv* env, jclass clazz,
		const char* name, const char* sig) {
	return ((JNIEnvMock*)env)->GetStaticFieldID(clazz, name, sig);
}

static jobject GetStaticObjectField(JNIEnv* env, jclass clazz,
		jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticObjectField(clazz, fieldID);
}
static jboolean GetStaticBooleanField(JNIEnv* env, jclass clazz,
		jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticBooleanField(clazz, fieldID);
}
static jbyte GetStaticByteField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticByteField(clazz, fieldID);
}
static jchar GetStaticCharField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticCharField(clazz, fieldID);
}
static jshort GetStaticShortField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticShortField(clazz, fieldID);
}
static jint GetStaticIntField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticIntField(clazz, fieldID);
}
static jlong GetStaticLongField(JNIEnv* env, jclass clazz, jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticLongField(clazz, fieldID);
}

static jfloat GetStaticFloatField(JNIEnv* env, jclass clazz,
		jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticFloatField(clazz, fieldID);
}

static jdouble GetStaticDoubleField(JNIEnv* env, jclass clazz,
		jfieldID fieldID) {
	return ((JNIEnvMock*)env)->GetStaticDoubleField(clazz, fieldID);
}

static void SetStaticObjectField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jobject value) {
	((JNIEnvMock*)env)->SetStaticObjectField(clazz, fieldID, value);
}
static void SetStaticBooleanField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jboolean value) {
	((JNIEnvMock*)env)->SetStaticBooleanField(clazz, fieldID, value);
}
static void SetStaticByteField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jbyte value) {
	((JNIEnvMock*)env)->SetStaticByteField(clazz, fieldID, value);
}
static void SetStaticCharField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jchar value) {
	((JNIEnvMock*)env)->SetStaticCharField(clazz, fieldID, value);
}
static void SetStaticShortField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jshort value) {
	((JNIEnvMock*)env)->SetStaticShortField(clazz, fieldID, value);
}
static void SetStaticIntField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jint value) {
	((JNIEnvMock*)env)->SetStaticIntField(clazz, fieldID, value);
}
static void SetStaticLongField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jlong value) {
	((JNIEnvMock*)env)->SetStaticLongField(clazz, fieldID, value);
}

static void SetStaticFloatField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jfloat value) {
	((JNIEnvMock*)env)->SetStaticFloatField(clazz, fieldID, value);
}

static void SetStaticDoubleField(JNIEnv* env, jclass clazz,
		jfieldID fieldID, jdouble value) {
	((JNIEnvMock*)env)->SetStaticDoubleField(clazz, fieldID, value);
}

static jstring NewString(JNIEnv* env, const jchar* unicodeChars, jsize len) {
	return ((JNIEnvMock*)env)->NewString(unicodeChars, len);
}

static jsize GetStringLength(JNIEnv* env, jstring string) {
	return ((JNIEnvMock*)env)->GetStringLength(string);
}

const jchar* GetStringChars(JNIEnv* env, jstring string, jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetStringChars(string, isCopy);
}

static void ReleaseStringChars(JNIEnv* env, jstring string,
		const jchar* chars) {
	((JNIEnvMock*)env)->ReleaseStringChars(string, chars);
}

static jstring NewStringUTF(JNIEnv* env, const char* bytes) {
	return ((JNIEnvMock*)env)->NewStringUTF(bytes);
}

static jsize GetStringUTFLength(JNIEnv* env, jstring string) {
	return ((JNIEnvMock*)env)->GetStringUTFLength(string);
}

const char* GetStringUTFChars(JNIEnv* env, jstring string, jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetStringUTFChars(string, isCopy);
}

static void ReleaseStringUTFChars(JNIEnv* env, jstring string,
		const char* utf) {
	((JNIEnvMock*)env)->ReleaseStringUTFChars(string, utf);
}

static jsize GetArrayLength(JNIEnv* env, jarray array) {
	return ((JNIEnvMock*)env)->GetArrayLength(array);
}

static jobjectArray NewObjectArray(JNIEnv* env, jsize length,
		jclass elementClass, jobject initialElement) {
	return ((JNIEnvMock*)env)->NewObjectArray(length,
			elementClass, initialElement);
}

static jobject GetObjectArrayElement(JNIEnv* env, jobjectArray array,
		jsize index) {
	return ((JNIEnvMock*)env)->GetObjectArrayElement(array, index);
}

static void SetObjectArrayElement(JNIEnv* env, jobjectArray array,
		jsize index, jobject value) {
	((JNIEnvMock*)env)->SetObjectArrayElement(array, index, value);
}

static jbooleanArray NewBooleanArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewBooleanArray(length);
}
static jbyteArray NewByteArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewByteArray(length);
}
static jcharArray NewCharArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewCharArray(length);
}
static jshortArray NewShortArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewShortArray(length);
}
static jintArray NewIntArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewIntArray(length);
}
static jlongArray NewLongArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewLongArray(length);
}
static jfloatArray NewFloatArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewFloatArray(length);
}
static jdoubleArray NewDoubleArray(JNIEnv* env, jsize length) {
	return ((JNIEnvMock*)env)->NewDoubleArray(length);
}

static jboolean* GetBooleanArrayElements(JNIEnv* env, jbooleanArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetBooleanArrayElements(array, isCopy);
}
static jbyte* GetByteArrayElements(JNIEnv* env, jbyteArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetByteArrayElements(array, isCopy);
}
static jchar* GetCharArrayElements(JNIEnv* env, jcharArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetCharArrayElements(array, isCopy);
}
static jshort* GetShortArrayElements(JNIEnv* env, jshortArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetShortArrayElements(array, isCopy);
}
static jint* GetIntArrayElements(JNIEnv* env, jintArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetIntArrayElements(array, isCopy);
}
static jlong* GetLongArrayElements(JNIEnv* env, jlongArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetLongArrayElements(array, isCopy);
}
static jfloat* GetFloatArrayElements(JNIEnv* env, jfloatArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetFloatArrayElements(array, isCopy);
}
static jdouble* GetDoubleArrayElements(JNIEnv* env, jdoubleArray array,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetDoubleArrayElements(array, isCopy);
}

static void ReleaseBooleanArrayElements(JNIEnv* env, jbooleanArray array,
		jboolean* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseBooleanArrayElements(array, elems, mode);
}
static void ReleaseByteArrayElements(JNIEnv* env, jbyteArray array, jbyte* elems,
    jint mode)
{ ((JNIEnvMock*)env)->ReleaseByteArrayElements(array, elems, mode); }
static void ReleaseCharArrayElements(JNIEnv* env, jcharArray array,
		jchar* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseCharArrayElements(array, elems, mode);
}
static void ReleaseShortArrayElements(JNIEnv* env, jshortArray array,
		jshort* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseShortArrayElements(array, elems, mode);
}
static void ReleaseIntArrayElements(JNIEnv* env, jintArray array,
		jint* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseIntArrayElements(array, elems, mode);
}
static void ReleaseLongArrayElements(JNIEnv* env, jlongArray array,
		jlong* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseLongArrayElements(array, elems, mode);
}
static void ReleaseFloatArrayElements(JNIEnv* env, jfloatArray array,
		jfloat* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseFloatArrayElements(array, elems, mode);
}
static void ReleaseDoubleArrayElements(JNIEnv* env, jdoubleArray array,
		jdouble* elems, jint mode) {
	((JNIEnvMock*)env)->ReleaseDoubleArrayElements(array, elems, mode);
}

static void GetBooleanArrayRegion(JNIEnv* env, jbooleanArray array,
		jsize start, jsize len, jboolean* buf) {
	((JNIEnvMock*)env)->GetBooleanArrayRegion(array, start, len, buf);
}
static void GetByteArrayRegion(JNIEnv* env, jbyteArray array,
		jsize start, jsize len, jbyte* buf) {
	((JNIEnvMock*)env)->GetByteArrayRegion(array, start, len, buf);
}
static void GetCharArrayRegion(JNIEnv* env, jcharArray array,
		jsize start, jsize len, jchar* buf) {
	((JNIEnvMock*)env)->GetCharArrayRegion(array, start, len, buf);
}
static void GetShortArrayRegion(JNIEnv* env, jshortArray array,
		jsize start, jsize len, jshort* buf) {
	((JNIEnvMock*)env)->GetShortArrayRegion(array, start, len, buf);
}
static void GetIntArrayRegion(JNIEnv* env, jintArray array,
		jsize start, jsize len, jint* buf) {
	((JNIEnvMock*)env)->GetIntArrayRegion(array, start, len, buf);
}
static void GetLongArrayRegion(JNIEnv* env, jlongArray array,
		jsize start, jsize len, jlong* buf) {
	((JNIEnvMock*)env)->GetLongArrayRegion(array, start, len, buf);
}
static void GetFloatArrayRegion(JNIEnv* env, jfloatArray array,
		jsize start, jsize len, jfloat* buf) {
	((JNIEnvMock*)env)->GetFloatArrayRegion(array, start, len, buf);
}
static void GetDoubleArrayRegion(JNIEnv* env, jdoubleArray array,
		jsize start, jsize len, jdouble* buf) {
	((JNIEnvMock*)env)->GetDoubleArrayRegion(array, start, len, buf);
}

static void SetBooleanArrayRegion(JNIEnv* env, jbooleanArray array,
		jsize start, jsize len, const jboolean* buf) {
	((JNIEnvMock*)env)->SetBooleanArrayRegion(array, start, len, buf);
}
static void SetByteArrayRegion(JNIEnv* env, jbyteArray array, jsize start, jsize len,
    const jbyte* buf) {
	((JNIEnvMock*)env)->SetByteArrayRegion(array, start, len, buf);
}
static void SetCharArrayRegion(JNIEnv* env, jcharArray array,
		jsize start, jsize len, const jchar* buf) {
	((JNIEnvMock*)env)->SetCharArrayRegion(array, start, len, buf);
}
static void SetShortArrayRegion(JNIEnv* env, jshortArray array,
		jsize start, jsize len, const jshort* buf) {
	((JNIEnvMock*)env)->SetShortArrayRegion(array, start, len, buf);
}
static void SetIntArrayRegion(JNIEnv* env, jintArray array,
		jsize start, jsize len, const jint* buf) {
	((JNIEnvMock*)env)->SetIntArrayRegion(array, start, len, buf);
}
static void SetLongArrayRegion(JNIEnv* env, jlongArray array,
		jsize start, jsize len, const jlong* buf) {
	((JNIEnvMock*)env)->SetLongArrayRegion(array, start, len, buf);
}
static void SetFloatArrayRegion(JNIEnv* env, jfloatArray array,
		jsize start, jsize len, const jfloat* buf) {
	((JNIEnvMock*)env)->SetFloatArrayRegion(array, start, len, buf);
}
static void SetDoubleArrayRegion(JNIEnv* env, jdoubleArray array,
		jsize start, jsize len, const jdouble* buf) {
	((JNIEnvMock*)env)->SetDoubleArrayRegion(array, start, len, buf);
}

static jint RegisterNatives(JNIEnv* env, jclass clazz,
		const JNINativeMethod* methods, jint nMethods) {
	return ((JNIEnvMock*)env)->RegisterNatives(clazz, methods, nMethods);
}

static jint UnregisterNatives(JNIEnv* env, jclass clazz) {
	return ((JNIEnvMock*)env)->UnregisterNatives(clazz);
}

static jint MonitorEnter(JNIEnv* env, jobject obj) {
	return ((JNIEnvMock*)env)->MonitorEnter(obj);
}

static jint MonitorExit(JNIEnv* env, jobject obj) {
	return ((JNIEnvMock*)env)->MonitorExit(obj);
}

static jint GetJavaVM(JNIEnv* env, JavaVM** vm) {
	return ((JNIEnvMock*)env)->GetJavaVM(vm);
}

static void GetStringRegion(JNIEnv* env, jstring str,
		jsize start, jsize len, jchar* buf) {
	((JNIEnvMock*)env)->GetStringRegion(str, start, len, buf);
}

static void GetStringUTFRegion(JNIEnv* env, jstring str,
		jsize start, jsize len, char* buf) {
	((JNIEnvMock*)env)->GetStringUTFRegion(str, start, len, buf);
}

static void* GetPrimitiveArrayCritical(JNIEnv* env,
		jarray array, jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetPrimitiveArrayCritical(array, isCopy);
}

static void ReleasePrimitiveArrayCritical(JNIEnv* env,
		jarray array, void* carray, jint mode) {
	((JNIEnvMock*)env)->ReleasePrimitiveArrayCritical(array, carray, mode);
}

static const jchar* GetStringCritical(JNIEnv* env, jstring string,
		jboolean* isCopy) {
	return ((JNIEnvMock*)env)->GetStringCritical(string, isCopy);
}

static void ReleaseStringCritical(JNIEnv* env, jstring string, const jchar* carray) {
	((JNIEnvMock*)env)->ReleaseStringCritical(string, carray);
}

static jweak NewWeakGlobalRef(JNIEnv* env, jobject obj) {
	return ((JNIEnvMock*)env)->NewWeakGlobalRef(obj);
}

static void DeleteWeakGlobalRef(JNIEnv* env, jweak obj) {
	((JNIEnvMock*)env)->DeleteWeakGlobalRef(obj);
}

static jboolean ExceptionCheck(JNIEnv* env) {
	return ((JNIEnvMock*)env)->ExceptionCheck();
}

static jobject NewDirectByteBuffer(JNIEnv* env,
		void* address, jlong capacity) {
	return ((JNIEnvMock*)env)->NewDirectByteBuffer(address, capacity);
}

static void* GetDirectBufferAddress(JNIEnv* env, jobject buf) {
	return ((JNIEnvMock*)env)->GetDirectBufferAddress(buf);
}

static jlong GetDirectBufferCapacity(JNIEnv* env, jobject buf) {
	return ((JNIEnvMock*)env)->GetDirectBufferCapacity(buf);
}

// added in JNI 1.6
static jobjectRefType GetObjectRefType(JNIEnv* env, jobject obj) {
	return ((JNIEnvMock*)env)->GetObjectRefType(obj);
}

#ifdef __ANDROID__
typedef JNINativeInterface JNINativeInterface_;
#endif

static const JNINativeInterface_ nativeInterface = {
	NULL,
	NULL,
	NULL,
	NULL,
	GetVersion,
	DefineClass,
	FindClass,

	FromReflectedMethod,
	FromReflectedField,
	ToReflectedMethod,

	GetSuperclass,
	IsAssignableFrom,

	ToReflectedField,

	Throw,
	ThrowNew,
	ExceptionOccurred,
	ExceptionDescribe,
	ExceptionClear,
	FatalError,

	PushLocalFrame,
	PopLocalFrame,

	NewGlobalRef,
	DeleteGlobalRef,
	DeleteLocalRef,
	IsSameObject,

	NewLocalRef,
	EnsureLocalCapacity,

	AllocObject,
	NewObject,
	NewObjectV,
	NewObjectA,

	GetObjectClass,
	IsInstanceOf,
	GetMethodID,

	CallObjectMethod,
	CallObjectMethodV,
	CallObjectMethodA,
	CallBooleanMethod,
	CallBooleanMethodV,
	CallBooleanMethodA,
	CallByteMethod,
	CallByteMethodV,
	CallByteMethodA,
	CallCharMethod,
	CallCharMethodV,
	CallCharMethodA,
	CallShortMethod,
	CallShortMethodV,
	CallShortMethodA,
	CallIntMethod,
	CallIntMethodV,
	CallIntMethodA,
	CallLongMethod,
	CallLongMethodV,
	CallLongMethodA,
	CallFloatMethod,
	CallFloatMethodV,
	CallFloatMethodA,
	CallDoubleMethod,
	CallDoubleMethodV,
	CallDoubleMethodA,
	CallVoidMethod,
	CallVoidMethodV,
	CallVoidMethodA,

	CallNonvirtualObjectMethod,
	CallNonvirtualObjectMethodV,
	CallNonvirtualObjectMethodA,
	CallNonvirtualBooleanMethod,
	CallNonvirtualBooleanMethodV,
	CallNonvirtualBooleanMethodA,
	CallNonvirtualByteMethod,
	CallNonvirtualByteMethodV,
	CallNonvirtualByteMethodA,
	CallNonvirtualCharMethod,
	CallNonvirtualCharMethodV,
	CallNonvirtualCharMethodA,
	CallNonvirtualShortMethod,
	CallNonvirtualShortMethodV,
	CallNonvirtualShortMethodA,
	CallNonvirtualIntMethod,
	CallNonvirtualIntMethodV,
	CallNonvirtualIntMethodA,
	CallNonvirtualLongMethod,
	CallNonvirtualLongMethodV,
	CallNonvirtualLongMethodA,
	CallNonvirtualFloatMethod,
	CallNonvirtualFloatMethodV,
	CallNonvirtualFloatMethodA,
	CallNonvirtualDoubleMethod,
	CallNonvirtualDoubleMethodV,
	CallNonvirtualDoubleMethodA,
	CallNonvirtualVoidMethod,
	CallNonvirtualVoidMethodV,
	CallNonvirtualVoidMethodA,

	GetFieldID,

	GetObjectField,
	GetBooleanField,
	GetByteField,
	GetCharField,
	GetShortField,
	GetIntField,
	GetLongField,
	GetFloatField,
	GetDoubleField,

	SetObjectField,
	SetBooleanField,
	SetByteField,
	SetCharField,
	SetShortField,
	SetIntField,
	SetLongField,
	SetFloatField,
	SetDoubleField,

	GetStaticMethodID,

	CallStaticObjectMethod,
	CallStaticObjectMethodV,
	CallStaticObjectMethodA,
	CallStaticBooleanMethod,
	CallStaticBooleanMethodV,

	CallStaticBooleanMethodA,

	CallStaticByteMethod,
	CallStaticByteMethodV,
	CallStaticByteMethodA,
	CallStaticCharMethod,
	CallStaticCharMethodV,
	CallStaticCharMethodA,
	CallStaticShortMethod,
	CallStaticShortMethodV,
	CallStaticShortMethodA,
	CallStaticIntMethod,
	CallStaticIntMethodV,
	CallStaticIntMethodA,
	CallStaticLongMethod,
	CallStaticLongMethodV,
	CallStaticLongMethodA,
	CallStaticFloatMethod,
	CallStaticFloatMethodV,
	CallStaticFloatMethodA,
	CallStaticDoubleMethod,
	CallStaticDoubleMethodV,
	CallStaticDoubleMethodA,
	CallStaticVoidMethod,
	CallStaticVoidMethodV,
	CallStaticVoidMethodA,

	GetStaticFieldID,

	GetStaticObjectField,
	GetStaticBooleanField,
	GetStaticByteField,
	GetStaticCharField,
	GetStaticShortField,
	GetStaticIntField,
	GetStaticLongField,
	GetStaticFloatField,
	GetStaticDoubleField,

	SetStaticObjectField,
	SetStaticBooleanField,
	SetStaticByteField,
	SetStaticCharField,
	SetStaticShortField,
	SetStaticIntField,
	SetStaticLongField,
	SetStaticFloatField,
	SetStaticDoubleField,

	NewString,
	GetStringLength,
	GetStringChars,
	ReleaseStringChars,
	NewStringUTF,
	GetStringUTFLength,
	GetStringUTFChars,
	ReleaseStringUTFChars,
	GetArrayLength,
	NewObjectArray,
	GetObjectArrayElement,
	SetObjectArrayElement,

	NewBooleanArray,
	NewByteArray,
	NewCharArray,
	NewShortArray,
	NewIntArray,
	NewLongArray,
	NewFloatArray,
	NewDoubleArray,

	GetBooleanArrayElements,
	GetByteArrayElements,
	GetCharArrayElements,
	GetShortArrayElements,
	GetIntArrayElements,
	GetLongArrayElements,
	GetFloatArrayElements,
	GetDoubleArrayElements,

	ReleaseBooleanArrayElements,
	ReleaseByteArrayElements,
	ReleaseCharArrayElements,
	ReleaseShortArrayElements,
	ReleaseIntArrayElements,
	ReleaseLongArrayElements,
	ReleaseFloatArrayElements,
	ReleaseDoubleArrayElements,

	GetBooleanArrayRegion,
	GetByteArrayRegion,
	GetCharArrayRegion,
	GetShortArrayRegion,
	GetIntArrayRegion,
	GetLongArrayRegion,
	GetFloatArrayRegion,
	GetDoubleArrayRegion,

	SetBooleanArrayRegion,
	SetByteArrayRegion,
	SetCharArrayRegion,
	SetShortArrayRegion,
	SetIntArrayRegion,
	SetLongArrayRegion,
	SetFloatArrayRegion,
	SetDoubleArrayRegion,

	RegisterNatives,

	UnregisterNatives,
	MonitorEnter,
	MonitorExit,
	GetJavaVM,

	GetStringRegion,
	GetStringUTFRegion,

	GetPrimitiveArrayCritical,
	ReleasePrimitiveArrayCritical,

	GetStringCritical,
	ReleaseStringCritical,

	NewWeakGlobalRef,
	DeleteWeakGlobalRef,

	ExceptionCheck,

	NewDirectByteBuffer,
	GetDirectBufferAddress,
	GetDirectBufferCapacity,

	GetObjectRefType,
};

JNIEnvMock::JNIEnvMock() {
	functions = &nativeInterface;
}

JNIEnvMock::~JNIEnvMock() {
	functions = NULL;
}

JNIEnvMock* createJNIEnvMock() {
	return new JNIEnvMock;
}

int destroyJNIEnvMock(JNIEnvMock* envMock) {
	delete envMock;
	return 0;
}

//-----------------------------------------------------------------------------
// The JavaVMMock implementation for android
//-----------------------------------------------------------------------------

#ifdef __ANDROID__
typedef JNIEnv** JVM_EnvPtr;
typedef JNIInvokeInterface JNIInvokeInterface_;
#else
typdeef void** JVM_EnvPtr;
#endif

static jint DestroyJavaVM(JavaVM* vm) {
	return ((JavaVMMock*)vm)->DestroyJavaVM();
}

static jint AttachCurrentThread(JavaVM* vm, JVM_EnvPtr p_env, void* thr_args) {
	return ((JavaVMMock*)vm)->AttachCurrentThread((JNIEnv**)p_env, thr_args);
}

static jint DetachCurrentThread(JavaVM* vm) {
	return ((JavaVMMock*)vm)->DetachCurrentThread();
}

static jint GetEnv(JavaVM* vm, void** env, jint version) {
	return ((JavaVMMock*)vm)->GetEnv(env, version);
}

static jint AttachCurrentThreadAsDaemon(JavaVM* vm, JVM_EnvPtr p_env, void* thr_args) {
	return ((JavaVMMock*)vm)->AttachCurrentThreadAsDaemon((JNIEnv**)p_env, thr_args);
}

static const JNIInvokeInterface_ invokeInterface = {
	NULL,
	NULL,
	NULL,
    DestroyJavaVM,
    AttachCurrentThread,
    DetachCurrentThread,
    GetEnv,
    AttachCurrentThreadAsDaemon,
};

JavaVMMock::JavaVMMock() {
	functions = &invokeInterface;
}

JavaVMMock::~JavaVMMock() {
	functions = NULL;
}

JavaVMMock* createJavaVMMock() {
	return new JavaVMMock;
}

int destroyJavaVMMock(JavaVMMock* vmMock) {
	delete vmMock;
	return 0;
}

} // namespace jnimock
