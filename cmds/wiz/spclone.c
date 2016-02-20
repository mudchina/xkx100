// spclone.c
// Write by Spacenet@FXLT 1.11.Y2k
inherit F_CLEAN_UP;

#include "/doc/help.h"



int main(object me, string arg)
{
	object obj;
	string file, err, msg;
	int count = 1, i;

	seteuid( geteuid(me) );

	if (!arg)
		file = me->query("cwf");
	else if (sscanf(arg, "%s %d", file, count) != 2)
		if (sscanf(arg, "%s", file) != 1)
			return notify_fail("你要复制什么？\n");
	
	if (sscanf(file, "%*s.c") != 1)
		file += ".c";
		
	file = resolve_path(me->query("cwd"), file);
	me->set("cwf", file);

	if( file_size(file) < 0 )
		return notify_fail("没有这个档案(" + file + ")。\n");

	if( !find_object(file) ) {
		err = catch(call_other(file, "???"));
		if (err) {
			write("载入失败：" + err + "\n");
			return 1;
		}
	}
        
	err = catch(obj = new(file));
	if (err) {
		write("复制失败：" + err + "\n");
		return 1;
	}
	
	if( !stringp(msg = me->query("env/msg_clone")) )
		msg = sprintf("只见$N伸手凌空一指，变出了%s$n。\n", obj->query("money_id")?"一些":chinese_number(count) + obj->query("unit"));
	
	if ( !obj->is_character() && obj->move(me)) {
		write(obj->query("name") + "复制成功\，放在你的物品栏。\n");
        	message_vision(msg + "\n", me, obj);
        	for (i = 0; i < count -1; i ++) {
			obj = new(file);
			obj->move(me);
		}
		return 1;
        }
        
	if( obj->move(environment(me)) && i == 0 ) {
		write(obj->query("name") + "复制成功\，放在这个房间。\n");
        	message_vision(msg + "\n", me, obj);
        	for (i = 0; i < count - 1; i ++) {
			obj = new(file);
			obj->move(environment(me));
		}
		return 1;
        }
        
	destruct(obj);
	return notify_fail("无法复制不能移动的物件(" + file + ")。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : spclone <文件名> [数量]

利用此指令可复制任何能移动之对象(含NPC)，如果不指定数量，则等同于clone指令。
HELP
    );
    return 1;
}

