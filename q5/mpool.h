typedef struct mpool_impl mpool;

mpool *mpool_init(int min2, int max2);
void mpool_free(mpool *mp);

void *mpool_alloc(mpool *mp, int sz);
void mpool_repool(mpool *mp, void *p, int sz);
