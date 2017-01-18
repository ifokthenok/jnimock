jnimock
=======

Overview
--------
jnimock is implemented on top of [gmock](http://code.google.com/p/googlemock/).
It provides two C++ classes 'JNIEnvMock' and 'JavaVMMock' to separately mock 'JNIEnv' and 'JavaVM'.
You can simply employ them to mock the JNI functions in your C++ testcase. 
Currently, jnimock API is only tested for Android.

Example
-------
You can use jnimock API to write JNI code related testcase like the following exmaple.

The tested code:

```c++
#include <jni.h>
extern "C" jint Java_my_package_MyClass_myMethod(JNIEnv* env, jclass cls) {
	return env->GetVersion();
}
```

The testcase:

```c++
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "jnimock/jnimock.h"

using testing::Return;
using namespace jnimock;

// Declare the JNI function that wanted to be tested
extern "C" jint Java_my_package_MyClass_myMethod(JNIEnv* env, jclass cls);

// The testcase
TEST(JNITest, GetVersion) {

    // Create a JNIEnvMock object (JNIEnvMock extends JNIEnv)
	JNIEnvMock* env = createJNIEnvMock();

	EXPECT_CALL(*env, GetVersion())
		.Times(1)
		.WillOnce(Return(JNI_VERSION_1_6));

	jint r = Java_my_package_MyClass_myMethod(env, NULL);
	EXPECT_EQ(r, JNI_VERSION_1_6);

    // Destory the created JNIEnvMock object
	destroyJNIEnvMock(env);
}
```

Usage
-----

### Use the source

You can directly use the jnimock source for your testing. Copy the following two
files to a proper place in your project's dir.

	<jnimock-src-dir>/include/jnimock/jnimock.h
	<jnimock-src-dir>/src/jnimock.cpp

#### Notice

 - a. jnimock depends on gmock, so make sure you have gmock installed.
 - b. jnimock depends on jni.h, so make sure you has Android NDK or Android cross-compile toolchain installed.

### Use the lib (jnimock.a and jnimock_main.a)

First copy the following header file to your project's including dir

	<jnimock-src-dir>/include/jnimock/jnimock.h

Then, you can alternately use jnimock.a or jnimock_main.a for your convenience.

 - jnimock.a is a static library which contains jnimock implementation.
 - jnimock_main.a is a static library which contains jnimock and gmock main() function implementation.

Refer to the Building section to build jnimock.a and jnimock_main.a.
If you want to build a shared lib, you can tweak the following makefile

	<jnimock-src-dir>/make/Makefile


Building
----------

### Prequirement 
 - a. Linux/cygwin (Ubutun 12.04 is tested)
 - b. git (version 1.7 is tested)
 - c. GNU Make (version 3.81 is tested)
 - d. Android NDK or Android cross-compile toolchain (arm-linux-androideabi-4.6 is tested)
 - e. gmock (gmock-1.7.0 is tested)

### Building steps

1) Download [Android NDK](https://developer.android.com/tools/sdk/ndk/index.html) and unpack it 
a dir (say \<android-ndk-dir\>)

2) Downlaod [gmock](http://code.google.com/p/googlemock/) and upack it a dir (say \<gmock-src-dir\>) 

3) Download jnimock (suppose the root of jnimock is \<jnimock-src-dir\>)
```bash
$git clone https://github.com/ifokthenok/jnimock <jnimock-src-dir>
```

4) Generate android cross-compile toolchain from Android NDK
```bash
$<android-ndk-dir>/build/tools/make-standalone-toolchain.sh --arch=arm --platform=android-19 --install-dir=<generated-toolchain-dir>
```

5) Build jnimock.a and jnimock_main.a
```bash
$ cd <jnimock-src-dir>/make
$ make GMOCK_DIR=<gmock-src-dir> CROSS_PREFIX=<generated-toolchain-dir>/bin/arm-linux-androideabi-
```

After a successful building, jnimock.a and jnimock_main.a are generated in the following dir:

	<jnimock-src-dir>/make/ 
	
You can use them for your JNI related testcase.
