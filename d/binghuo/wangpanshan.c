// Room: /binghuo/wangpanshan.c
// Date: Oct.28 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "王盘山海滩");
	set("long", @LONG
只听得岛上号角之声呜呜吹起，岸边两人各举大旗，挥舞示意。
只见两面大旗上均绣着一头大鹰，双翅伸展，甚是威武。两面大旗之
间站着一个老者。只听他朗声说道：“玄武坛白龟寿恭迎贵客。”声
音漫长，绵绵密密，虽不响亮，却是气韵醇厚。往南是一个山谷。
LONG );
	set("no_sleep_room",1);
	set("outdoors", "wangpan");
	set("exits", ([
		"south" : __DIR__"wangpangu1",
		"east"  : __DIR__"wangpanlin",
	]));
	set("objects", ([
		"/d/mingjiao/npc/baiguishou" : 1,
	]));
	setup();
	replace_program(ROOM);
}

