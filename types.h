typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

// mprotect usage
#define PROT_WRITE          0x002   // Writeable
#define PROT_READ           0x004   // User
#define PROT_NONE           0x1     // only present
