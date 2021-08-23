#ifndef _DEVICE_MEMORY_MAP_H_
#define _DEVICE_MEMORY_MAP_H_

#include <Library/ArmLib.h>

#define MAX_ARM_MEMORY_REGION_DESCRIPTOR_COUNT 64

/* Below flag is used for system memory */
#define SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES                               \
  EFI_RESOURCE_ATTRIBUTE_PRESENT | EFI_RESOURCE_ATTRIBUTE_INITIALIZED |        \
      EFI_RESOURCE_ATTRIBUTE_TESTED | EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE |     \
      EFI_RESOURCE_ATTRIBUTE_WRITE_COMBINEABLE |                               \
      EFI_RESOURCE_ATTRIBUTE_WRITE_THROUGH_CACHEABLE |                         \
      EFI_RESOURCE_ATTRIBUTE_WRITE_BACK_CACHEABLE |                            \
      EFI_RESOURCE_ATTRIBUTE_EXECUTION_PROTECTABLE

typedef enum { NoHob, AddMem, AddDev, MaxMem } DeviceMemoryAddHob;

typedef struct {
  EFI_PHYSICAL_ADDRESS         Address;
  UINT64                       Length;
  EFI_RESOURCE_TYPE            ResourceType;
  EFI_RESOURCE_ATTRIBUTE_TYPE  ResourceAttribute;
  ARM_MEMORY_REGION_ATTRIBUTES ArmAttributes;
  DeviceMemoryAddHob           HobOption;
  EFI_MEMORY_TYPE              MemoryType;
} ARM_MEMORY_REGION_DESCRIPTOR_EX, *PARM_MEMORY_REGION_DESCRIPTOR_EX;

static ARM_MEMORY_REGION_DESCRIPTOR_EX gDeviceMemoryDescriptorEx[] = {
    /* Address,	  Length,     ResourceType, Resource Attribute, ARM MMU
       Attribute,                  HobOption, EFI Memory Type */
    /*  HYP  */
    {0x80000000, 0x00600000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  AOP CMD DB  */
    {0x80820000, 0x00020000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  SMEM  */
    {0x80900000, 0x00200000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  PIL Reserved  */
    {0x84400000, 0x0F800000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  DXE Heap  */    
    {0x93C00000, 0x04500000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiConventionalMemory},
    /*  DBI Dump  */    
    {0x98100000, 0x03700000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     NoHob, EfiConventionalMemory},
    /*  Sched Heap  */    
    {0x9B800000, 0x00400000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  Display Reserved  */    
    {0x9C000000, 0x01800000, EFI_RESOURCE_MEMORY_RESERVED,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_THROUGH,
     AddMem, EfiReservedMemoryType},
    /*  FV Region  */
    {0x9F800000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  ABOOT FV  */
    {0x9FA00000, 0x00200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  UEFI FD  */    
    {0x9FC00000, 0x00300000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  SEC Heap  */    
    {0x9FF00000, 0x0008C000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData}, 
    /*  CPU Vectors  */    
    {0x9FF8C000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  MMU PageTables  */ 
    {0x9FF8D000, 0x00003000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  UEFI Stack  */ 
    {0x9FF90000, 0x00040000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiBootServicesData},
    /*  Log Buffer  */ 
    {0x9FFF7000, 0x00008000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiRuntimeServicesData},
    /*  Info Blk  */ 
    {0x9FFFF000, 0x00001000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiRuntimeServicesData},
    /*  Secure DSP  */ 
    {0xA0000000, 0x01200000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  Kernel  */
    {0xA1200000, 0x08000000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  MLVM_APSS  */
    {0xA9200000, 0x03A00000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  MLVM_1  */
    {0xACC00000, 0x07800000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},
    /*  SEC DEBUG  */
    {0xB4400000, 0x00C00000, EFI_RESOURCE_MEMORY_RESERVED,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_UNCACHED_UNBUFFERED,
     AddMem, EfiReservedMemoryType},
    /*  SOD Test  */
    {0xC2000000, 0x0A100000, EFI_RESOURCE_SYSTEM_MEMORY,
     SYSTEM_MEMORY_RESOURCE_ATTR_CAPABILITIES, ARM_MEMORY_REGION_ATTRIBUTE_WRITE_BACK,
     AddMem, EfiReservedMemoryType},

    /* Other memory regions */
    /* AOP_SS_MSG_RAM */
    {0x0C300000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     NoHob, EfiConventionalMemory},
     /* IMEM Base */
    {0x14680000, 0x0002B000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     NoHob, EfiConventionalMemory},
     /* IMEM Cookie Base */
    {0x146AA000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_INITIALIZED, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiConventionalMemory},

    /*  Registers  */ 
    {0x00100000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x00780000, 0x00007000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x00790000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x007C0000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x00800000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x00A00000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x01D80000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x01DC0000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x01FC0000, 0x00040000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x03500000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x03900000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x03D00000, 0x00300000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x05090000, 0x00009000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0509A000, 0x00004000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0C200000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x62B00000, 0x00060000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x08800000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x090B0000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0A600000, 0x0011B000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0A720000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0B2A0000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0B4A0000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0BA00000, 0x00200000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0C221000, 0x00003000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0C263000, 0x00003000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0C400000, 0x02800000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0AB00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x09980000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0AD00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0AF00000, 0x00020000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x18280000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x18282000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x18284000, 0x00001000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x18200000, 0x00030000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x17A00000, 0x00010000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x17A60000, 0x00100000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x17C00000, 0x00110000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x18300000, 0x000B0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x0AE00000, 0x00134000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    {0x15000000, 0x000D0000, EFI_RESOURCE_MEMORY_MAPPED_IO,
     EFI_RESOURCE_ATTRIBUTE_UNCACHEABLE, ARM_MEMORY_REGION_ATTRIBUTE_NONSECURE_DEVICE,
     AddDev, EfiMemoryMappedIO},
    /* Terminator */
    {}};

#endif
