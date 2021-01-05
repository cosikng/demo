#include "common.h"
#include "x86/memory.h"
#include <string.h>

#define VMEM_ADDR 0xa0000
#define SCR_SIZE (320 * 200)

#ifdef IA32_PAGE
#define KOFFSET 0xC0000000
#else
#define KOFFSET 0
#endif

#define va_to_pa(addr) ((void*)(((uint32_t)(addr)) - KOFFSET))
#define pa_to_va(addr) ((void*)(((uint32_t)(addr)) + KOFFSET))

static PTE videotable[(SCR_SIZE & ~PAGE_MASK) / PAGE_SIZE + 1] align_to_page;

/* Use the function to get the start address of user page directory. */
PDE *get_updir();

void create_video_mapping()
{
	/* TODO: create an identical mapping from virtual memory area 
	 * [0xa0000, 0xa0000 + SCR_SIZE) to physical memory area 
	 * [0xa0000, 0xa0000 + SCR_SIZE) for user program. You may define
	 * some page tables to create this mapping.
	 */
	//panic("please implement me");
	uint32_t i, j;
	PDE *updir = get_updir();
	for (i = 0; i < (SCR_SIZE & ~(PT_SIZE - 1)) / PT_SIZE + 1; i++)
	{
		updir[i + (VMEM_ADDR >> 22)].val = (uint32_t)(va_to_pa(videotable) + i * PAGE_SIZE);
		updir[i + (VMEM_ADDR >> 22)].present = 1;
		for (j = 0; j < (SCR_SIZE & ~PAGE_MASK) / PAGE_SIZE + 1; j++)
		{
			videotable[j].val = VMEM_ADDR + j * PAGE_SIZE;
			videotable[j].present = 1;
		}
	}
}

void video_mapping_write_test()
{
	int i;
	uint32_t *buf = (void *)VMEM_ADDR;
	for (i = 0; i < SCR_SIZE / 4; i++)
	{
		buf[i] = i;
	}
}

void video_mapping_read_test()
{
	int i;
	uint32_t *buf = (void *)VMEM_ADDR;
	for (i = 0; i < SCR_SIZE / 4; i++)
	{
		assert(buf[i] == i);
	}
}

void video_mapping_clear()
{
	memset((void *)VMEM_ADDR, 0, SCR_SIZE);
}
