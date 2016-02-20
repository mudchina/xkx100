// Room: /d/changcheng/jiayuguan.c
// Last Modified by Winder on Aug. 25 2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "嘉峪关箭楼");
	set("long", WHT @LONG
你站在号称“天下第一雄关”的嘉峪关箭楼上，南面是终年积雪的
祁连山，北面是连绵起伏的马鬃山，西望几十里地的一马平川，真不愧
天下第一。长城在戈壁沙漠上的漫天黄沙中如苍龙蠕动，若隐若现，忽
断忽续。
LONG
NOR );
	set("outdoors", "xiyu");
	set("exits", ([
		"down"      : "/d/xingxiu/jiayuguan",
		"northeast" : __DIR__"changcheng21",
	]));
	set("no_clean_up", 0);
	set("coor/x", -18000);
	set("coor/y", 400);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}