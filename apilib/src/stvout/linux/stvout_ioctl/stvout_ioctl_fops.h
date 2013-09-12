/*****************************************************************************
 *
 *  Module      : stvout_ioctl
 *  Date        : 23-10-2005
 *  Author      : ATROUSWA
 *  Description :
 *  Copyright   : STMicroelectronics (c)2005
 *****************************************************************************/


#ifndef stvout_ioctl_FOPS_H
#define stvout_ioctl_FOPS_H

int     stvout_ioctl_open   (struct inode*, struct file*);
ssize_t stvout_ioctl_read   (struct file*,        char*, size_t, loff_t*);
ssize_t stvout_ioctl_write  (struct file*,  const char*, size_t, loff_t*);
int     stvout_ioctl_flush  (struct file*);
loff_t  stvout_ioctl_lseek  (struct file*,  loff_t, int);
int     stvout_ioctl_readdir(struct file*,  void*, filldir_t);
int     stvout_ioctl_ioctl  (struct inode*, struct file*, unsigned int, unsigned long);
unsigned int     stvout_ioctl_poll   (struct file*,  struct poll_table_struct*);
int     stvout_ioctl_fsync  (struct inode*, struct dentry*, int);
int     stvout_ioctl_fasync (int,           struct file*,   int);
ssize_t stvout_ioctl_readv  (struct file*,  const struct iovec*, unsigned long, loff_t*);
ssize_t stvout_ioctl_writev (struct file*,  const struct iovec*, unsigned long, loff_t*);
int     stvout_ioctl_release(struct inode*, struct file*);  /* close */


#endif
