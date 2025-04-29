
cd /sys/devices/system/cpu
echo core | sudo tee /proc/sys/kernel/core_pattern 2>&1 | grep -v core