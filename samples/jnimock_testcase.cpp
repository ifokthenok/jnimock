#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <jnimock/jnimock.h>

using namespace testing;
using namespace jnimock;

int f(int x) {
	return x + x;
}

TEST(f, Positive) {
	EXPECT_EQ(2, f(1));
}
TEST(f, Negative) {
	EXPECT_EQ(-2, f(-1));
}
TEST(f, Zero) {
	EXPECT_TRUE(0 == f(0));
}

struct I {
	virtual ~I() {}
	virtual int f1(int x) = 0;
	virtual int f2(int x) = 0;
};


int g(int x, I* i) {
	return i->f1(x) + i->f2(x);
}


struct IStub: public I {
	int f1(int x) { return x; }
	int f2(int x) { return x; }
};

TEST(g, UseStub) {
	IStub stub;
	EXPECT_EQ(2, g(1, &stub));
	EXPECT_EQ(4, g(2, &stub));
}


struct IMock: public I {
     MOCK_METHOD1(f1, int(int x));
     MOCK_METHOD1(f2, int(int x));
};

TEST(g, UseGoogleMock) {
	IMock mock;
	EXPECT_CALL(mock, f1(Ge(1)))
		.Times(2)
		.WillOnce(Return(-1))
		.WillRepeatedly(Return(1));
	
	EXPECT_CALL(mock, f2(Ge(1)))
	 	.Times(2)
		.WillOnce(Return(-2))
		.WillRepeatedly(Return(2));
	EXPECT_EQ(-3, g(1, &mock));
	EXPECT_EQ(3, g(2, &mock));
}


jint getVersion(JNIEnv* env) {
	return env->GetVersion();
}


TEST(getVersion, UseJNIMock) {
     JNIEnvMock* env = createJNIEnvMock();
     EXPECT_CALL(*env, GetVersion())
		.Times(1)
		.WillRepeatedly (Return(JNI_VERSION_1_6));
     EXPECT_EQ(JNI_VERSION_1_6, getVersion (env));
     destroyJNIEnvMock(env);
}

