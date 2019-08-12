set -e

PROJECT="UnityHelper/UnityHelper"
NDK="C:/Users/Edward/Documents/ndk-bundle/"

$NDK/ndk-build.cmd NDK_PROJECT_PATH=C:/Users/Edward/Documents/ndk-bundle APP_BUILD_SCRIPT=C:/Users/Edward/Documents/GitHub/$PROJECT/Android.mk NDK_APPLICATION_MK=C:/Users/Edward/Documents/GitHub/$PROJECT/Application.mk