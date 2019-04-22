#define _CRT_SECURE_NO_WARNINGS
#include "Jni_JniTest.h"
#include <string.h>
#include <Windows.h>

int cmp(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

/* 
 * 中文乱码问题 --- 调用Java方法
 */
JNIEXPORT jobject JNICALL Java_Jni_JniTest_getStringFromC
(JNIEnv *env, jclass jcls) {
	const char *str = "你好鸭Jni！";

	jclass str_cls = env->FindClass("java/lang/String");
	jmethodID constructor_mid = env->GetMethodID(str_cls, "<init>", "([BLjava/lang/String;)V");
	jbyteArray bytes = env->NewByteArray(strlen(str));
	env->SetByteArrayRegion(bytes, 0, strlen(str), (jbyte *)str);
	jstring charseName = env->NewStringUTF("GB2312");

	return env->NewObject(str_cls,constructor_mid,bytes,charseName);
}

JNIEXPORT jint JNICALL Java_Jni_JniTest_accessStaticField
(JNIEnv * env, jclass jcls,jintArray nums) {
	jint *elems = env->GetIntArrayElements(nums,JNI_FALSE);
	jint len = env->GetArrayLength(nums);
	qsort(elems,len,sizeof(jint),cmp);
	// 0 Java数组更新，并且释放C/C++数组
	// JNI_COMMIT Java数组更新，不释放C/C++数组（函数执行完时释放）
	// JNI_ABORT Java数组不更新，释放C/C++数组
	env->ReleaseIntArrayElements(nums,elems,0);

	jfieldID jfid = env->GetStaticFieldID(jcls, "num", "I");
	jint new_num = env->GetStaticIntField(jcls, jfid);
	new_num++;
	env->SetStaticIntField(jcls, jfid, new_num);
	return new_num;
}

JNIEXPORT jstring JNICALL Java_Jni_JniTest_accessField
(JNIEnv *env, jobject jobj) {
	jclass cls = env->GetObjectClass(jobj);
	//即使我们获取到了异常对象，这个异常仍然在JVM中存在，直到我们调用ExceptionClear方法清空异常。
	jfieldID  fid = env->GetFieldID(cls, "wrong_key", "Ljava/lang/String;");
	//获取JVM抛出的异常
	jthrowable exception = env->ExceptionOccurred();
	if (exception != NULL) {
		//清空异常信息，程序继续向下执行
		env->ExceptionClear();
		//抛出一个新异常对象，可以在Java层捕获
		jclass newExcCls = env->FindClass("java/lang/IllegalArgumentException");
		env->ThrowNew(newExcCls,"key wrong,begin firstly try..");
		//获取正确的fid
		fid = env->GetFieldID(cls, "key", "Ljava/lang/String;");
	}
	jstring jstr = (jstring)env->GetObjectField(jobj, fid);
	//isCopy
	const char *c_str = env->GetStringUTFChars(jstr, JNI_FALSE);
	char prefix[50] = "no ";
	strcat(prefix, c_str);
	jstring new_str = env->NewStringUTF(prefix);
	env->SetObjectField(jobj, fid, new_str);
	return new_str;
}

JNIEXPORT void JNICALL Java_Jni_JniTest_accessMethod
(JNIEnv *env, jobject jobj) {
	jclass jcls = env->GetObjectClass(jobj);
	jmethodID mid = env->GetMethodID(jcls, "outPut", "()V");
	env->CallVoidMethod(jobj, mid);
}

/*
 * 调用构造方法
 */
JNIEXPORT jobject JNICALL Java_Jni_JniTest_accessConstructor
(JNIEnv *env, jobject jobj) {
	WinExec("D:/KGMusic/KuGou.exe", 0);
	jclass jcls = env->FindClass("java/util/Date");
	jmethodID constructor_mid = env->GetMethodID(jcls, "<init>", "()V");
	jobject date_obj = env->NewObject(jcls,constructor_mid);
	jmethodID mid = env->GetMethodID(jcls, "getTime", "()J");
	jlong time = env->CallLongMethod(date_obj,mid);
	printf("Time : %lld",time);
	return date_obj;
}

