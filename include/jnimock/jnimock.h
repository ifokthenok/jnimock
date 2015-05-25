#ifndef JNIMOCK_H_
#define JNIMOCK_H_

#include <jni.h>
#include <gmock/gmock.h>

namespace jnimock {

struct JNIEnvMock : public JNIEnv {
	JNIEnvMock();
	~JNIEnvMock();

	MOCK_METHOD0(GetVersion, jint());
	MOCK_METHOD4(DefineClass, jclass(const char*, jobject,
			const jbyte*, jsize));
    MOCK_METHOD1(FindClass, jclass(const char*));

    MOCK_METHOD1(FromReflectedMethod, jmethodID(jobject));
    MOCK_METHOD1(FromReflectedField, jfieldID(jobject));
    MOCK_METHOD3(ToReflectedMethod, jobject(jclass, jmethodID, jboolean));

	MOCK_METHOD1(GetSuperclass, jclass(jclass));
	MOCK_METHOD2(IsAssignableFrom, jboolean(jclass, jclass));

	MOCK_METHOD3(ToReflectedField, jobject(jclass, jfieldID, jboolean));

	MOCK_METHOD1(Throw, jint(jthrowable));
	MOCK_METHOD2(ThrowNew, jint(jclass, const char *));
	MOCK_METHOD0(ExceptionOccurred, jthrowable());
	MOCK_METHOD0(ExceptionDescribe, void());
	MOCK_METHOD0(ExceptionClear, void());
	MOCK_METHOD1(FatalError, void(const char*));

	MOCK_METHOD1(PushLocalFrame, jint(jint));
	MOCK_METHOD1(PopLocalFrame, jobject(jobject));

	MOCK_METHOD1(NewGlobalRef, jobject(jobject));
    MOCK_METHOD1(DeleteGlobalRef, void(jobject));
    MOCK_METHOD1(DeleteLocalRef, void(jobject));
    MOCK_METHOD2(IsSameObject, jboolean(jobject, jobject));

    MOCK_METHOD1(NewLocalRef, jobject(jobject));
    MOCK_METHOD1(EnsureLocalCapacity, jint(jint));

    MOCK_METHOD1(AllocObject, jobject(jclass));
    MOCK_METHOD3(NewObjectV, jobject(jclass, jmethodID, va_list));
    MOCK_METHOD3(NewObjectA,jobject(jclass, jmethodID, jvalue*));

	MOCK_METHOD1(GetObjectClass, jclass(jobject));
	MOCK_METHOD2(IsInstanceOf, jboolean(jobject, jclass));
	MOCK_METHOD3(GetMethodID, jmethodID(jclass, const char*, const char*));

    MOCK_METHOD3(CallObjectMethodV, jobject(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallObjectMethodA, jobject(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallBooleanMethodV, jboolean(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallBooleanMethodA, jboolean(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallByteMethodV, jbyte(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallByteMethodA, jbyte(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallCharMethodV, jchar(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallCharMethodA, jchar(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallShortMethodV, jshort(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallShortMethodA, jshort(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallIntMethodV, jint(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallIntMethodA, jint(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallLongMethodV, jlong(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallLongMethodA, jlong(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallFloatMethodV, jfloat(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallFloatMethodA, jfloat(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallDoubleMethodV, jdouble(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallDoubleMethodA, jdouble(jobject, jmethodID, jvalue*));
    MOCK_METHOD3(CallVoidMethodV, void(jobject, jmethodID, va_list));
    MOCK_METHOD3(CallVoidMethodA, void(jobject, jmethodID, jvalue*));

    MOCK_METHOD4(CallNonvirtualObjectMethodV, jobject(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualObjectMethodA, jobject(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualBooleanMethodV, jboolean(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualBooleanMethodA, jboolean(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualByteMethodV, jbyte(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualByteMethodA, jbyte(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualCharMethodV, jchar(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualCharMethodA, jchar(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualShortMethodV, jshort(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualShortMethodA, jshort(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualIntMethodV, jint(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualIntMethodA, jint(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualLongMethodV, jlong(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualLongMethodA, jlong(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualFloatMethodV, jfloat(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualFloatMethodA, jfloat(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualDoubleMethodV, jdouble(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualDoubleMethodA, jdouble(jobject, jclass, jmethodID, jvalue*));
    MOCK_METHOD4(CallNonvirtualVoidMethodV, void(jobject, jclass,  jmethodID, va_list));
    MOCK_METHOD4(CallNonvirtualVoidMethodA, void(jobject, jclass, jmethodID, jvalue*));

	MOCK_METHOD3(GetFieldID, jfieldID(jclass, const char*, const char*));

	MOCK_METHOD2(GetObjectField, jobject(jobject, jfieldID));
	MOCK_METHOD2(GetBooleanField, jboolean(jobject, jfieldID));
	MOCK_METHOD2(GetByteField, jbyte(jobject, jfieldID));
	MOCK_METHOD2(GetCharField, jchar(jobject, jfieldID));
	MOCK_METHOD2(GetShortField, jshort(jobject, jfieldID));
	MOCK_METHOD2(GetIntField, jint(jobject, jfieldID));
	MOCK_METHOD2(GetLongField, jlong(jobject, jfieldID));
	MOCK_METHOD2(GetFloatField, jfloat(jobject, jfieldID));
	MOCK_METHOD2(GetDoubleField, jdouble(jobject, jfieldID));

	MOCK_METHOD3(SetObjectField, void(jobject, jfieldID, jobject));
	MOCK_METHOD3(SetBooleanField, void(jobject, jfieldID, jboolean));
	MOCK_METHOD3(SetByteField, void(jobject, jfieldID, jbyte));
	MOCK_METHOD3(SetCharField, void(jobject, jfieldID, jchar));
	MOCK_METHOD3(SetShortField, void(jobject, jfieldID, jshort));
	MOCK_METHOD3(SetIntField, void(jobject, jfieldID, jint));
	MOCK_METHOD3(SetLongField, void(jobject, jfieldID, jlong));
	MOCK_METHOD3(SetFloatField, void(jobject, jfieldID, jfloat));
	MOCK_METHOD3(SetDoubleField, void(jobject, jfieldID, jdouble));

	MOCK_METHOD3(GetStaticMethodID, jmethodID(jclass, const char*, const char*));

	MOCK_METHOD3(CallStaticObjectMethodV, jobject(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticObjectMethodA, jobject(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticBooleanMethodV, jboolean(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticBooleanMethodA, jboolean(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticByteMethodV, jbyte(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticByteMethodA, jbyte(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticCharMethodV, jchar(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticCharMethodA, jchar(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticShortMethodV, jshort(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticShortMethodA, jshort(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticIntMethodV, jint(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticIntMethodA, jint(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticLongMethodV, jlong(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticLongMethodA, jlong(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticFloatMethodV, jfloat(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticFloatMethodA, jfloat(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticDoubleMethodV, jdouble(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticDoubleMethodA, jdouble(jclass, jmethodID, jvalue*));
	MOCK_METHOD3(CallStaticVoidMethodV, void(jclass, jmethodID, va_list));
	MOCK_METHOD3(CallStaticVoidMethodA, void(jclass, jmethodID, jvalue*));

	MOCK_METHOD3(GetStaticFieldID, jfieldID(jclass, const char*, const char*));

	MOCK_METHOD2(GetStaticObjectField, jobject(jclass, jfieldID));
	MOCK_METHOD2(GetStaticBooleanField, jboolean(jclass, jfieldID));
	MOCK_METHOD2(GetStaticByteField, jbyte(jclass, jfieldID));
	MOCK_METHOD2(GetStaticCharField, jchar(jclass, jfieldID));
	MOCK_METHOD2(GetStaticShortField, jshort(jclass, jfieldID));
	MOCK_METHOD2(GetStaticIntField, jint(jclass, jfieldID));
	MOCK_METHOD2(GetStaticLongField, jlong(jclass, jfieldID));
	MOCK_METHOD2(GetStaticFloatField, jfloat(jclass, jfieldID));
	MOCK_METHOD2(GetStaticDoubleField, jdouble(jclass, jfieldID));

	MOCK_METHOD3(SetStaticObjectField, void(jclass, jfieldID, jobject));
	MOCK_METHOD3(SetStaticBooleanField, void(jclass, jfieldID, jboolean));
	MOCK_METHOD3(SetStaticByteField, void(jclass, jfieldID, jbyte));
	MOCK_METHOD3(SetStaticCharField, void(jclass, jfieldID, jchar));
	MOCK_METHOD3(SetStaticShortField, void(jclass, jfieldID, jshort));
	MOCK_METHOD3(SetStaticIntField, void(jclass, jfieldID, jint));
	MOCK_METHOD3(SetStaticLongField, void(jclass, jfieldID, jlong));
	MOCK_METHOD3(SetStaticFloatField, void(jclass, jfieldID, jfloat));
	MOCK_METHOD3(SetStaticDoubleField, void(jclass, jfieldID, jdouble));

	MOCK_METHOD2(NewString, jstring(const jchar*, jsize));
	MOCK_METHOD1(GetStringLength, jsize(jstring));
	MOCK_METHOD2(GetStringChars, const jchar*(jstring, jboolean*));
	MOCK_METHOD2(ReleaseStringChars, void(jstring, const jchar*));
	MOCK_METHOD1(NewStringUTF, jstring(const char*));
	MOCK_METHOD1(GetStringUTFLength, jsize(jstring));
	MOCK_METHOD2(GetStringUTFChars, const char*(jstring, jboolean*));
	MOCK_METHOD2(ReleaseStringUTFChars, void(jstring, const char*));
	MOCK_METHOD1(GetArrayLength, jsize(jarray));
	MOCK_METHOD3(NewObjectArray, jobjectArray(jsize, jclass, jobject));
	MOCK_METHOD2(GetObjectArrayElement, jobject(jobjectArray, jsize));
	MOCK_METHOD3(SetObjectArrayElement, void(jobjectArray, jsize, jobject));

	MOCK_METHOD1(NewBooleanArray, jbooleanArray(jsize));
	MOCK_METHOD1(NewByteArray, jbyteArray(jsize));
	MOCK_METHOD1(NewCharArray, jcharArray(jsize));
	MOCK_METHOD1(NewShortArray, jshortArray(jsize));
	MOCK_METHOD1(NewIntArray, jintArray(jsize));
	MOCK_METHOD1(NewLongArray, jlongArray(jsize));
	MOCK_METHOD1(NewFloatArray, jfloatArray(jsize));
	MOCK_METHOD1(NewDoubleArray, jdoubleArray(jsize));

	MOCK_METHOD2(GetBooleanArrayElements, jboolean*(jbooleanArray, jboolean*));
	MOCK_METHOD2(GetByteArrayElements, jbyte*(jbyteArray, jboolean*));
	MOCK_METHOD2(GetCharArrayElements, jchar*(jcharArray, jboolean*));
	MOCK_METHOD2(GetShortArrayElements, jshort*(jshortArray, jboolean*));
	MOCK_METHOD2(GetIntArrayElements, jint*(jintArray, jboolean*));
	MOCK_METHOD2(GetLongArrayElements, jlong*(jlongArray, jboolean*));
	MOCK_METHOD2(GetFloatArrayElements, jfloat*(jfloatArray, jboolean*));
	MOCK_METHOD2(GetDoubleArrayElements, jdouble*(jdoubleArray, jboolean*));

	MOCK_METHOD3(ReleaseBooleanArrayElements, void(jbooleanArray, jboolean*, jint));
	MOCK_METHOD3(ReleaseByteArrayElements, void(jbyteArray, jbyte*, jint));
	MOCK_METHOD3(ReleaseCharArrayElements, void(jcharArray, jchar*, jint));
	MOCK_METHOD3(ReleaseShortArrayElements, void(jshortArray, jshort*, jint));
	MOCK_METHOD3(ReleaseIntArrayElements, void(jintArray, jint*, jint));
	MOCK_METHOD3(ReleaseLongArrayElements, void(jlongArray, jlong*, jint));
	MOCK_METHOD3(ReleaseFloatArrayElements, void(jfloatArray, jfloat*, jint));
	MOCK_METHOD3(ReleaseDoubleArrayElements, void(jdoubleArray, jdouble*, jint));

	MOCK_METHOD4(GetBooleanArrayRegion, void(jbooleanArray, jsize, jsize, jboolean*));
	MOCK_METHOD4(GetByteArrayRegion, void(jbyteArray, jsize, jsize, jbyte*));
	MOCK_METHOD4(GetCharArrayRegion, void(jcharArray, jsize, jsize, jchar*));
	MOCK_METHOD4(GetShortArrayRegion, void(jshortArray, jsize, jsize, jshort*));
	MOCK_METHOD4(GetIntArrayRegion, void(jintArray, jsize, jsize, jint*));
	MOCK_METHOD4(GetLongArrayRegion, void(jlongArray, jsize, jsize, jlong*));
	MOCK_METHOD4(GetFloatArrayRegion, void(jfloatArray, jsize, jsize, jfloat*));
	MOCK_METHOD4(GetDoubleArrayRegion, void(jdoubleArray, jsize, jsize, jdouble*));

	MOCK_METHOD4(SetBooleanArrayRegion, void(jbooleanArray, jsize, jsize, const jboolean*));
	MOCK_METHOD4(SetByteArrayRegion, void(jbyteArray, jsize, jsize, const jbyte*));
	MOCK_METHOD4(SetCharArrayRegion, void(jcharArray, jsize, jsize, const jchar*));
	MOCK_METHOD4(SetShortArrayRegion, void(jshortArray, jsize, jsize, const jshort*));
	MOCK_METHOD4(SetIntArrayRegion, void(jintArray, jsize, jsize, const jint*));
	MOCK_METHOD4(SetLongArrayRegion, void(jlongArray, jsize, jsize, const jlong*));
	MOCK_METHOD4(SetFloatArrayRegion, void(jfloatArray, jsize, jsize, const jfloat*));
	MOCK_METHOD4(SetDoubleArrayRegion, void(jdoubleArray, jsize, jsize, const jdouble*));

	MOCK_METHOD3(RegisterNatives, jint(jclass, const JNINativeMethod*, jint));
	MOCK_METHOD1(UnregisterNatives, jint(jclass));
	MOCK_METHOD1(MonitorEnter, jint(jobject));
	MOCK_METHOD1(MonitorExit, jint(jobject));
	MOCK_METHOD1(GetJavaVM, jint(JavaVM**));

	MOCK_METHOD4(GetStringRegion, void(jstring, jsize, jsize, jchar*));
	MOCK_METHOD4(GetStringUTFRegion, void(jstring, jsize, jsize, char*));

	MOCK_METHOD2(GetPrimitiveArrayCritical, void*(jarray, jboolean*));
	MOCK_METHOD3(ReleasePrimitiveArrayCritical, void(jarray, void*, jint));

	MOCK_METHOD2(GetStringCritical, const jchar*(jstring, jboolean*));
	MOCK_METHOD2(ReleaseStringCritical, void(jstring, const jchar*));

	MOCK_METHOD1(NewWeakGlobalRef, jweak(jobject));
	MOCK_METHOD1(DeleteWeakGlobalRef, void(jweak));

	MOCK_METHOD0(ExceptionCheck, jboolean());

	MOCK_METHOD2(NewDirectByteBuffer, jobject(void*, jlong));
	MOCK_METHOD1(GetDirectBufferAddress, void*(jobject));
	MOCK_METHOD1(GetDirectBufferCapacity, jlong(jobject));

	MOCK_METHOD1(GetObjectRefType, jobjectRefType(jobject));
};

JNIEnvMock* createJNIEnvMock();
int destroyJNIEnvMock(JNIEnvMock* envMock);

struct JavaVMMock: public JavaVM {
	JavaVMMock();
	~JavaVMMock();
    MOCK_METHOD0(DestroyJavaVM, jint());
    MOCK_METHOD2(AttachCurrentThread, jint(JNIEnv**, void*));
    MOCK_METHOD0(DetachCurrentThread, jint());
    MOCK_METHOD2(GetEnv, jint(void**, jint));
    MOCK_METHOD2(AttachCurrentThreadAsDaemon, jint(JNIEnv**, void*));
};

JavaVMMock* createJavaVMMock();
int destroyJavaVMMock(JavaVMMock* vmMock);

} // namespace jnimock

#endif
