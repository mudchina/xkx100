// summon command..

inherit F_CLEAN_UP;

int main(object me, string str)
{
	object ob;
       
	int i;
	if (!str) return notify_fail("<Syntax>: spcome <object id>\n");
	ob = LOGIN_D->find_body(str);
	if (!ob) ob = find_object(str);
	if (!ob) return notify_fail("没有这个东西。\n");
	// moving
	if (!clonep(ob)) return notify_fail("不能移动复制源物件。\n");
	if (ob->move(environment(me)))
  {
  	tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前。\n");
	  return 1;
	}
	else
	return notify_fail("无法移动的物件"+str+"。\n");
}

int help(object me)
{
write(@HELP
指令格式 : comehere <某人>

此指令可让你将某人(物)抓到你面前。
HELP
);
    return 1;
}
