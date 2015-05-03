typedef unsigned int   uint;
typedef unsigned short ushort;
typedef unsigned char  uchar;
typedef uint pde_t;

// mprotect usage
#define PROT_NONE           0x000   // Not present
#define PROT_READ           0x001   // Present only
#define PROT_WRITE          0x003   // Writeable and present 
