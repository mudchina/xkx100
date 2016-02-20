// Room: /d/taohua/tanzhige.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "弹指阁");
	set("long", @LONG
这是一个里面廊窗的小阁。透过窗缝，可以看到北面的弹指峰。东
面望去，是白浪滔滔的大海，海面上白鸥自由飞来飞去，真是“天高任
鸟飞”啊。阁里搁着一个橡皮人，满身标点着穴位(xuedao)，你忍不住
伸指向穴道弹(tan)去。
LONG
	);
        set("exits", ([ 
		"south" : __DIR__"zoulang4",
	]));
	set("no_clean_up", 0);
	set("coor/x", 9020);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}
void init()
{
	add_action("do_tan", "tan");
}
int do_tan(string arg)
{       
        mapping fam;
	object me = this_player();
	if (arg != "xuedao")
		return notify_fail("你点什么点啊你？往哪里点啊你？\n");
	if (!living(me)) return 0;
	if (!(fam = me->query("family")) || fam["family_name"] != "桃花岛")
		return notify_fail("你非本岛弟子，不能在此练功！\n");

	if ( (int)me->query_skill("finger", 1) > 100)
		return notify_fail("你伸指往橡皮人身上弹去，发现橡皮人太软了，没法锻炼你的指力。\n");
 
	if((int)me->query("qi")<30)
	{
		me->receive_damage("qi",10);
		write( "你伸指往橡皮人身上弹去，结果一点力气也没有，看来是太累了！\n");
		return 1;
	}
	me->receive_damage("qi", random(40));
	me->improve_skill("finger", me->query("int"));
	write("你伸指往橡皮人身上的穴道弹去，弹了个正着！\n");
	return 1;
}