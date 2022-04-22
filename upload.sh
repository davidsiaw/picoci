set -e

mkdir -p /mnt/pico
mount /dev/sda1 /mnt/pico
cp $1 /mnt/pico
sync
umount /mnt/pico
