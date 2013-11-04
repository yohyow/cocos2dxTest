LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

# ���� all-cpp-files ���ص�ǰ·���� Classes ·��������� cpp �ļ���ע�⣺����ֻ���� cpp ��û�� c�������Ҫ�������
#define all-cpp-files
#$(patsubst jni/%,%, $(shell find $(LOCAL_PATH)/../../Classes/ $(LOCAL_PATH)/hellocpp -name "*.cpp"))  
#endef
# ����ʹ���µķ�ʽ�滻�����ķ�ʽ�����Զ����Դ�ļ�
LOCAL_SRC_FILES := $(call all-cpp-files)

LOCAL_SRC_FILES := main.cpp \
                   AppDelegate.cpp \
                  HelloWorldScene.cpp
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static cocos_extension_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx) \
$(call import-module,extensions)
