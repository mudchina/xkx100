// /d/meizhuang/dating.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;

void create()
{
	set("short", "四雅清风");
	set("long", @LONG
你已经到了梅庄的大厅门口，门内的匾额(bian)龙飞凤舞的写着“
四雅清风”四个大字，笔法娟秀中透着挺拔，不失为一笔好字。透过后
门，你看到里面一尘不染，一张石桌和几个石凳都安放得整整齐齐。厅
中悬着一幅大中堂，所绘的是一个仙人的背面，墨意淋漓，笔力雄健，
画上题款是：“丹青生大醉后泼墨”八字，笔法森严，一笔笔便如长剑
的刺划。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
		"bian" : "这块匾已经很陈旧了，看起来摇摇晃晃的，似乎不大结实。\n",
	]));
	set("exits", ([ /* sizeof() == 2 */
		"north" : __DIR__"keting",
		"south" : __DIR__"tianjing",
	]));
	set("no_clean_up", 0);

	set("coor/x", 3500);
	set("coor/y", -1420);
	set("coor/z", 10);
	setup();
	"/clone/board/meizhuang_b"->foo();
}
