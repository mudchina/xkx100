// tai.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",CYN "望乡台" NOR);
	set("long", 
"这是鬼魂与"+RED "前世" NOR+"告别的最后之所了。眼前是一个高高的"+CYN "石台" NOR+"，四面
凌空，皆是浓雾笼罩一般，如梦似幻，"+HIW "脚下" NOR+"似有万丈"+BLU "深渊" NOR+"，远处是曾经
相识的"+HIR "家乡故土" NOR+"，极目望去，隐隐可见生前之地，亲朋好友故土旧屋，
皆"HIG"历历如在"NOR"，然虚无缥缈，可望而不可及........\n"
BLU "        望着所有熟悉的一切，你的记忆似乎又被唤醒了，不禁悲\n"
"    从衷来，恋恋不舍.................\n\n" NOR
);
	set("no_fight", 1);
	set("exits", ([ 
		"west" : __DIR__"dadian",
	]));
	set("no_clean_up", 0);
	setup();
}
void init()
{
	object ob;
	if( interactive(ob = this_player())  )
	{
		remove_call_out("do_string");
		call_out("do_string",20,ob);
	}
}
int do_string(object ob)
{
	if( !ob || environment(ob) != this_object() ) return 0;
	write(BLU "    一个声音在你耳边说道：“汝已身入冥府，该当在此于前世一刀两断，\n速速去登西方极乐世界为妙，"+RED "切不可再纵身于尘世情色之中......\n\n" NOR);
	ob->unconcious();
	return 1;
}
