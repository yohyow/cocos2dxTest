LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := game_shared

LOCAL_MODULE_FILENAME := libgame

# 定义 all-cpp-files 返回当前路径和 Classes 路径想的所有 cpp 文件，注意：这里只考虑 cpp 而没有 c，如果需要自行添加
#define all-cpp-files
#$(patsubst jni/%,%, $(shell find $(LOCAL_PATH)/../../Classes/ $(LOCAL_PATH)/hellocpp -name "*.cpp"))  
#endef
# 这里使用新的方式替换换来的方式，以自动添加源文件
#LOCAL_SRC_FILES := $(call all-cpp-files)

LOCAL_SRC_FILES := main.cpp \
                   AppDelegate.cpp \
                   PlaneLayer.cpp \
                   BulletLayer.cpp \
                   GameLayer.cpp \
                   GameScene.cpp 
                   
                  
                   
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes                   

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static cocosdenshion_static
            
include $(BUILD_SHARED_LIBRARY)

$(call import-module,CocosDenshion/android) \
$(call import-module,cocos2dx)
