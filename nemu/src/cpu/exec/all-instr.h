#include "prefix/prefix.h"

#include "CMOVcc/cmove.h"
#include "CMOVcc/cmovns.h"

#include "data-mov/mov.h"
#include "data-mov/xchg.h"
#include "data-mov/movsx.h"
#include "data-mov/movzx.h"
#include "data-mov/cbw.h"
#include "data-mov/cwd.h"

#include "arith/dec.h"
#include "arith/inc.h"
#include "arith/neg.h"
#include "arith/imul.h"
#include "arith/mul.h"
#include "arith/idiv.h"
#include "arith/div.h"
#include "arith/cmp.h"
#include "arith/add.h"
#include "arith/adc.h"
#include "arith/sub.h"
#include "arith/sbb.h"

#include "logic/and.h"
#include "logic/or.h"
#include "logic/not.h"
#include "logic/xor.h"
#include "logic/sar.h"
#include "logic/shl.h"
#include "logic/shr.h"
#include "logic/shrd.h"
#include "logic/test.h"
#include "logic/seta.h"
#include "logic/setae.h"
#include "logic/setb.h"
#include "logic/setbe.h"
#include "logic/sete.h"
#include "logic/setg.h"
#include "logic/setge.h"
#include "logic/setl.h"
#include "logic/setle.h"
#include "logic/setne.h"
#include "logic/setno.h"
#include "logic/setnp.h"
#include "logic/setns.h"
#include "logic/seto.h"
#include "logic/setp.h"
#include "logic/sets.h"

#include "string/rep.h"
#include "string/movs.h"
#include "string/stos.h"
#include "string/lods.h"
#include "string/scas.h"

#include "misc/misc.h"

#include "special/special.h"

#include "call/call.h"
#include "call/ret.h"
#include "call/je.h"
#include "call/jmp.h"
#include "call/ja.h"
#include "call/jae.h"
#include "call/jb.h"
#include "call/jbe.h"
#include "call/jg.h"
#include "call/jge.h"
#include "call/jl.h"
#include "call/jle.h"
#include "call/jnc.h"
#include "call/jne.h"
#include "call/jno.h"
#include "call/jnp.h"
#include "call/jns.h"
#include "call/jo.h"
#include "call/jp.h"
#include "call/js.h"
#include "call/jcxz.h"

#include "push/push.h"
#include "push/pop.h"
#include "push/leave.h"
#include "push/lea.h"
