#include "w25q_lfs.h"

static w25q_device_t *dev = NULL;

int w25q_lfs_device_init(w25q_device_t *w25q_device)
{
    dev = w25q_device;
}

int w25q_lfs_read(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, void *buffer, lfs_size_t size)
{
    uint32_t addr = (block * (c->block_size)) + off;
    return w25q_read(dev, addr, (uint8_t *)buffer, size);
}

int w25q_lfs_prog(const struct lfs_config *c, lfs_block_t block, lfs_off_t off, const void *buffer, lfs_size_t size)
{
    uint32_t addr = (block * (c->block_size)) + off;
    return w25q_write(dev, addr, NULL, size);
}

int w25q_lfs_sector_erase(const struct lfs_config *c, lfs_block_t block)
{
    uint32_t addr = (block * (c->block_size));
    return w25q_sector_erase(dev, addr);
}

int w25q_lfs_sync(const struct lfs_config *c)
{
    UNUSED(c);
    return LFS_ERR_OK;
}