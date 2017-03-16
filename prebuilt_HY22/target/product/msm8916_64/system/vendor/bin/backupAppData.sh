#!/system/bin/sh

# Local variable
SrcPath=/data/data
DstPath="$SECONDARY_STORAGE/backup/App"
CfgPath="$SECONDARY_STORAGE/backup/backupAppData.txt"
BusyBoxPath="/system/bin/busybox"
TarTool="$BusyBoxPath tar"

backpathFile=/data/data/com.android.backup/files/backup_path

if [ ! -f "$backpathFile" ]
then
log -p e -t BackUp "The backup path isn't exist use default path to backup"
else
read backpath < "$backpathFile"
DstPath="$backpath/backup/App"
CfgPath="$backpath/backup/backupAppData.txt"
rm -f "$backpathFile"
fi

log -p d -t BackUp "DstPath is $DstPath"
log -p d -t BackUp "CfgPath is $CfgPath"

# Environment Setting
export PATH=/sbin:/system/sbin:/system/bin:/system/xbin:$PATH

# Set Property
setprop "persist.sys.shflag" 0
mkdir -p $DstPath
while read line
do
    log -p d -t BackUp "$line"
    cd "$SrcPath"
    $TarTool -cpf "$DstPath/$line.tar" "$line"
    cd -
done < "$CfgPath"

rm "$CfgPath"
setprop "persist.sys.shflag" 1
