#include <ansi.h>
inherit ROOM;
void create()
{
	set("short","深谷");
	set("long",@LONG
深谷中四处碧树丛生，怪石嶙峋，好一副优美的自然景致。
深谷之中，有一个大山洞出现在面前，不知道是什么前辈高人住
在里面。
LONG
	);
	set("exits",([
		"south":__DIR__"shangu",
		"north":__DIR__"donghou",
		"enter":__DIR__"shandong1",
	]));
	set("objects",([
		__DIR__"npc/shendiao":1,
		CLASS_D("gumu")+"/yangguo":1,
	]));
	set("outdoors", "jianzhong");
	set("coor/x", -400);
	set("coor/y", -440);
	set("coor/z", 0);
	setup();
}
	