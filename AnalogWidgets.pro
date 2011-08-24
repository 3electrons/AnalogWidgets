# Taki kiepski hack na Bartkom po to by sie skompilowala statyczna bibloteka
# najpierw - prawdopodobnie z czasem bedzie dodawana jako dynamiczna bibloteka 
#

TEMPLATE    = subdirs
CONFIG     += ordered 
SUBDIRS     = analogwidgets \
              scripttool \
	      test 

OTHER_FILES += \
    android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl \
    android/src/eu/licentia/necessitas/ministro/IMinistro.aidl \
    android/src/eu/licentia/necessitas/industrius/QtApplication.java \
    android/src/eu/licentia/necessitas/industrius/QtSurface.java \
    android/src/eu/licentia/necessitas/industrius/QtLayout.java \
    android/src/eu/licentia/necessitas/industrius/QtActivity.java \
    android/src/eu/licentia/necessitas/mobile/QtFeedback.java \
    android/src/eu/licentia/necessitas/mobile/QtMediaPlayer.java \
    android/src/eu/licentia/necessitas/mobile/QtSensors.java \
    android/src/eu/licentia/necessitas/mobile/QtAndroidContacts.java \
    android/src/eu/licentia/necessitas/mobile/QtCamera.java \
    android/src/eu/licentia/necessitas/mobile/QtLocation.java \
    android/src/eu/licentia/necessitas/mobile/QtSystemInfo.java \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/AndroidManifest.xml \
    android/src/eu/licentia/necessitas/ministro/IMinistroCallback.aidl \
    android/src/eu/licentia/necessitas/ministro/IMinistro.aidl \
    android/src/eu/licentia/necessitas/industrius/QtApplication.java \
    android/src/eu/licentia/necessitas/industrius/QtSurface.java \
    android/src/eu/licentia/necessitas/industrius/QtLayout.java \
    android/src/eu/licentia/necessitas/industrius/QtActivity.java \
    android/src/eu/licentia/necessitas/mobile/QtFeedback.java \
    android/src/eu/licentia/necessitas/mobile/QtMediaPlayer.java \
    android/src/eu/licentia/necessitas/mobile/QtSensors.java \
    android/src/eu/licentia/necessitas/mobile/QtAndroidContacts.java \
    android/src/eu/licentia/necessitas/mobile/QtCamera.java \
    android/src/eu/licentia/necessitas/mobile/QtLocation.java \
    android/src/eu/licentia/necessitas/mobile/QtSystemInfo.java \
    android/res/values/libs.xml \
    android/res/values/strings.xml \
    android/res/drawable-ldpi/icon.png \
    android/res/drawable-hdpi/icon.png \
    android/res/drawable-mdpi/icon.png \
    android/AndroidManifest.xml
