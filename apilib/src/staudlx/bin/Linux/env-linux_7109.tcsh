#setenv RPC_ROOT /dvd-vob/Dvd_driverExt/Multicom
#setenv RPC_ROOT /design/LinuxSTB/src/dvdroot/multicom-3.0.4-0822
setenv RPC_ROOT /opt/STM/multicom-3.0.4
#setenv LSPROOT /design/LinuxSTB/trees/linux-2.6.10rc1_st20050110
setenv DVD_ROOT /dvd-vob
setenv DVD_INCLUDE $DVD_ROOT/include
setenv DVD_MAKE $DVD_ROOT/dvdbr-prj-make
setenv DVD_EXPORTS ~/exports
setenv ARCHITECTURE ST40
setenv DVD_PLATFORM mb411
setenv DVD_FRONTEND 7109
setenv DVD_BACKEND 7109
setenv DVD_TRANSPORT stpti
setenv DEBUG 1
setenv ARCH sh
setenv CROSS_COMPILE sh4-linux-
setenv ST40ROOT /opt/STM/ST40R3.1.1
#setenv ST40ROOT /design/mcdt_products/st40/st40r2-3.1.1-linux
#setenv PATH /opt/STM/ST40R3.0.2/bin:/opt/STM/STLinux-2.0/devkit/sh4/bin:$RPC_ROOT/bin/linux/ia32:$PATH
setenv PATH $ST40ROOT/bin:/opt/STM/STLinux-2.0/devkit/sh4/bin:$RPC_ROOT/bin/linux/ia32:$PATH
#setenv STAUD_REMOVE_CLKRV_SUPPORT 1
#setenv KDIR /design/LinuxSTB/trees/mb411/linux-sh4-2.6.11_20050523
#setenv KDIR /design/LinuxSTB/trees/mb411/linux-sh4-2.6.11_20050523_videocut2
#setenv KDIR /design/LinuxSTB/trees/mb411/linux-sh4-2.6.11_20050523_video
#setenv KDIR /design/LinuxSTB/trees/mb411/linux-sh4-2.6.11_20050523-shenzen_14_10_05
setenv KDIR /opt/STM/STLinux-2.0/devkit/kernel/linux-sh4-2.6.11_stm20
setenv LSPROOT $KDIR
setenv LINUX_KERNEL_VERSION "2.6"
setenv STTBX_PRINT 1
setenv STTBX_REPORT 1
setenv DVD_SERVICE_DVB 1
setenv DVD_SERVICE DVB
#Clock Setting is board specific. Check the ossilator on your board 
setenv STCLKRV_EXT_CLK_MHZ 27
#setenv STCLKRV_EXT_CLK_MHZ 30
setenv DVD_OS LINUX
setenv OBJ_DIR $RPC_ROOT/lib/linux/st40

setenv LINUX_ARCHITECTURE LINUX_FULL_KERNEL_VERSION
setenv DVD_TOOLSET LINUX
#setenv CLKRV_TESTING 1
setenv AVMEM_KERNEL_MODE 1
setenv DVD_CFLAGS '-D UART_BAUD_RATE=115200 -DSTLINUX_RT_THREADS -DDVD_DEBUG_DISP_REG_CONTROL -DST_OSLINUX -DST_7109 -DSTVID_DEBUG_GET_STATISTICS -DGLOBAL_PASS_PARAMS_THROUGH_IOCTLS -DSTAPI_LINUX_DEV_DIR="\"/dvd-vob/\"" -DLINUX_FULL_KERNEL_VERSION -DWA_CLK_SET -pthread '
setenv KERNEL_RELEASE_NAME $KDIR
setenv DVD_BUILDING_IN_VOB true
