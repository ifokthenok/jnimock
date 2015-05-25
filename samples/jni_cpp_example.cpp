#include <jni.h>

/**
 * The JNI code would be tested by using jnimock
 * The java class looks like:
 *	package my.package;
 *	class MyClass {
 *	    public native static int cppMethod();
 *	}
 */
extern "C" JNIEXPORT jint Java_my_package_MyClass_cppMethod(JNIEnv* env, jclass cls) {
	return env->GetVersion();
}

