#include "cpu/exec/helper.h"

#define DATA_BYTE 1
#include "jmp-template.h"
#undef DATA_BYTE

#define DATA_BYTE 2
#include "jmp-template.h"
#undef DATA_BYTE

#define DATA_BYTE 4
#include "jmp-template.h"
#undef DATA_BYTE

/* for instruction encoding overloading */

make_helper_v(jmp_si)

    make_helper(ljmp)
{
    uint32_t gdl, gdh;
    cpu.CS = swaddr_read(eip + 5, 2, 1);
    gdl = lnaddr_read((cpu.GDTR.base_h << 16) + cpu.GDTR.base_l + (cpu.CS >> 3) * 8, 4);
    gdh = lnaddr_read((cpu.GDTR.base_h << 16) + cpu.GDTR.base_l + (cpu.CS >> 3) * 8 + 4, 4);
    cpu.CSlimit = ((gdh & 0xf0000) << 12) + ((gdl & 0xffff) << 12);
    cpu.CSbase = (gdl >> 16) + ((gdh & 0xff) << 16) + (gdh & 0xff000000);
    if ((gdh >> 23) == 0)
        cpu.CSlimit >>= 12;
    cpu.eip = swaddr_read(eip + 1, 4, 1) - 7;
    return 7;
}

make_helper(jmp_rm_v)
{
    if (ops_decoded.is_operand_size_16)
    {
        decode_rm_w(eip + 1);
        cpu.eip = op_src->val & 0xffff;
        return -1;
    }
    else
    {
        decode_rm_l(eip + 1);
        cpu.eip = op_src->val;
        return 0;
    }
}
