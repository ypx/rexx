
#ifndef HEADER_BUFFER_H
# define HEADER_BUFFER_H

# include <openssl/ossl_typ.h>

#ifdef  __cplusplus
extern "C" {
#endif

# include <stddef.h>

# if !defined(NO_SYS_TYPES_H)
#  include <sys/types.h>
# endif

/* Already declared in ossl_typ.h */
/* typedef struct buf_mem_st BUF_MEM; */

struct buf_mem_st {
    size_t length;              /* current number of bytes */
    char *data;
    size_t max;                 /* size of buffer */
};

BUF_MEM *BUF_MEM_new(void);
void BUF_MEM_free(BUF_MEM *a);
int BUF_MEM_grow(BUF_MEM *str, size_t len);
int BUF_MEM_grow_clean(BUF_MEM *str, size_t len);
size_t BUF_strnlen(const char *str, size_t maxlen);
char *BUF_strdup(const char *str);

/*
 * Like strndup, but in addition, explicitly guarantees to never read past the
 * first |siz| bytes of |str|.
 */
char *BUF_strndup(const char *str, size_t siz);

void *BUF_memdup(const void *data, size_t siz);
void BUF_reverse(unsigned char *out, const unsigned char *in, size_t siz);

/* safe string functions */
size_t BUF_strlcpy(char *dst, const char *src, size_t siz);
size_t BUF_strlcat(char *dst, const char *src, size_t siz);

/* BEGIN ERROR CODES */
/*
 * The following lines are auto generated by the script mkerr.pl. Any changes
 * made after this point may be overwritten when the script is next run.
 */
void ERR_load_BUF_strings(void);

/* Error codes for the BUF functions. */

/* Function codes. */
# define BUF_F_BUF_MEMDUP                                 103
# define BUF_F_BUF_MEM_GROW                               100
# define BUF_F_BUF_MEM_GROW_CLEAN                         105
# define BUF_F_BUF_MEM_NEW                                101
# define BUF_F_BUF_STRDUP                                 102
# define BUF_F_BUF_STRNDUP                                104

/* Reason codes. */

#ifdef  __cplusplus
}
#endif
#endif
