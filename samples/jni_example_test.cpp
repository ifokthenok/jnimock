// Copyright 2008, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Author: wan@google.com (Zhanyong Wan)

// Google Mock - a framework for writing C++ mock classes.
//

#include <jni.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <jnimock/jnimock.h>

using testing::Return;
using namespace jnimock;

// This is a native function implemented in jni_c_exmaple.c
extern "C" jint Java_my_package_MyClass_cMethod(JNIEnv* env, jclass cls);

// This is a native function implemented in jni_cpp_exmaple.cpp
extern "C" jint Java_my_package_MyClass_cppMethod(JNIEnv* env, jclass cls);

TEST(JNITest, GetVersion) {

    // create a JNIEnvMock object (JNIEnvMock extends JNIEnv)
	JNIEnvMock* env = createJNIEnvMock();

    // check GetVersion interaction
	EXPECT_CALL(*env, GetVersion())
		.Times(2)
		.WillOnce(Return(JNI_VERSION_1_4))
		.WillRepeatedly(Return(JNI_VERSION_1_6));
	
    // invoke the c method
	jint r = Java_my_package_MyClass_cMethod(env, NULL);
	EXPECT_EQ(r, JNI_VERSION_1_4);

    // invoke the cpp method
	r = Java_my_package_MyClass_cppMethod(env, NULL);
	EXPECT_EQ(r, JNI_VERSION_1_6);

    // destory the created JNIEnvMock object
	destroyJNIEnvMock(env);
}




