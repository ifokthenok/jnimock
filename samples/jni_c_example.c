#include <jni.h>

/**
 * The JNI code would be tested by using jnimock
 * The java class looks like:
 *	package my.package;
 *	class MyClass {
 *	    public native static int cMethod();
 *	}
 */
JNIEXPORT jint Java_my_package_MyClass_cMethod(JNIEnv* env, jclass cls) {
	return (*env)->GetVersion(env);
}

