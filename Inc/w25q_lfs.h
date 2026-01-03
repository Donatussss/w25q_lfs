#ifndef INC_W25Q_LFS_H_
#define INC_W25Q_LFS_H_

#include "lfs.h"
#include "w25qxx.h"

int w25q_lfs_device_init(w25q_device_t *w25q_device);
int w25q_lfs_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size);
int w25q_lfs_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size);
int w25q_lfs_sector_erase(const struct lfs_config *c, lfs_block_t block);
int w25q_lfs_sync(const struct lfs_config *c);

#endif /* INC_W25Q_LFS_H_ */