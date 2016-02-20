inherit F_CLEAN_UP;
#include <ansi.h>

int mask_check(object ob);

int main(object me)
{
	object *mask_ob;
	string str;
	int i;
	
	mask_ob = filter_array(users(), (: mask_check :));

	if ( sizeof(mask_ob) > 0 ) {
		str = "目前线上使用面具的玩家有：\n";
		for (i = 0;i < sizeof(mask_ob);i ++)
			str = sprintf("%s%-16s      =    %s \n", str, mask_ob[i]->name(1) + "(" + 
				mask_ob[i]->query("id") + ")", mask_ob[i]->name(0));
		me->start_more(str);
		return 1;
	} else  return notify_fail("目前没有玩家使用面具。\n");
}

int mask_check(object ob)
{
	if (ob->name(0) != ob->name(1))
		return 1;
	return 0;
}
