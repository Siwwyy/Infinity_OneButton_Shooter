#!/bin/sh
cd "`dirname "$0"`"
ADB=
if [ "$ANDROID_HOME" != "" ]; then ADB=$ANDROID_HOME/platform-tools/adb; else ADB=C:/Users/andry/AppData/Local/Android/Sdk/platform-tools/adb; fi
DEVICE=
if [ "$1" != "" ]; then DEVICE="-s $1"; fi
echo
echo Uninstalling existing application. Failures here can almost always be ignored.
$ADB $DEVICE uninstall com.YourCompany.Infinite_Shooter
echo
echo Installing existing application. Failures here indicate a problem with the device \(connection or storage permissions\) and are fatal.
$ADB $DEVICE install Infinite_Shooter-Android-Shipping-armv7.apk
if [ $? -eq 0 ]; then
	echo
	echo Grant READ_EXTERNAL_STORAGE and WRITE_EXTERNAL_STORAGE to the apk for reading OBB or game file in external storage.
	$ADB $DEVICE shell pm grant com.YourCompany.Infinite_Shooter android.permission.READ_EXTERNAL_STORAGE
	$ADB $DEVICE shell pm grant com.YourCompany.Infinite_Shooter android.permission.WRITE_EXTERNAL_STORAGE
	echo
	echo Removing old data. Failures here are usually fine - indicating the files were not on the device.
	$ADB $DEVICE shell 'rm -r $EXTERNAL_STORAGE/UE4Game/Infinite_Shooter'
	$ADB $DEVICE shell 'rm -r $EXTERNAL_STORAGE/UE4Game/UE4CommandLine.txt'
	$ADB $DEVICE shell 'rm -r $EXTERNAL_STORAGE/obb/com.YourCompany.Infinite_Shooter'
	$ADB $DEVICE shell 'rm -r $EXTERNAL_STORAGE/Android/obb/com.YourCompany.Infinite_Shooter'
	$ADB $DEVICE shell 'rm -r $EXTERNAL_STORAGE/Download/obb/com.YourCompany.Infinite_Shooter'
	echo
	echo Installing new data. Failures here indicate storage problems \(missing SD card or bad permissions\) and are fatal.
	STORAGE=$(echo "`$ADB $DEVICE shell 'echo $EXTERNAL_STORAGE'`" | cat -v | tr -d '^M')
	$ADB $DEVICE push main.1.com.YourCompany.Infinite_Shooter.obb $STORAGE/obb/com.YourCompany.Infinite_Shooter/main.1.com.YourCompany.Infinite_Shooter.obb
	if [ $? -eq 0 ]; then




		echo
		echo Installation successful
		exit 0
	fi
fi
echo
echo There was an error installing the game or the obb file. Look above for more info.
echo
echo Things to try:
echo Check that the device (and only the device) is listed with \"$ADB devices\" from a command prompt.
echo Make sure all Developer options look normal on the device
echo Check that the device has an SD card.
exit 1
