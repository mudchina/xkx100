// Room: /d/lingxiao/qianyuan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void init();
int pick(string);
void create()
{
	set("short","前院");
	set("long",@LONG 
这里是凌霄城的前院，凌霄弟子大都居住于此后。这里种了一棵三
人合围粗的墨梅，花瓣漆黑，气味芬芳。深邃的大院里，高山阳光透过
墨梅的花瓣射下，在雪地上映出一块块亮斑。一只雪鹤在树下翩翩起舞，
黑白相映，互有情趣。 
LONG);
	set("outdoors", "lingxiao");
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"huajing", 
		"south" : __DIR__"dadian",
		"north" : __DIR__"zhongting",
	]));
	set("objects", ([
		__DIR__"npc/xuehe" : 1,
		__DIR__"obj/ban" : 1,
	]));
	set("coor/x", -31000);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
}

void init()
{
	add_action("do_pick","pick");
}
int do_pick(string arg)
{
	object ob, me = this_player();

	if (!arg || arg!="hua" && arg!="flower")
		return notify_fail("你要摘什么？\n");
	ob=new(__DIR__"obj/mei");
	ob->move(me);
	message_vision("$N从路旁的树上摘了一朵"+ob->query("name")+"。\n"NOR,me);
	return 1;
}

