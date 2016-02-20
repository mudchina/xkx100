// Room: /d/huijiang/linzhong.c
// Last Modified by winder on Sep. 12 2001
inherit ROOM;

void create()
{
	set ("short", "树林中");
	set ("long", @LONG
这是树林中的一片空地，给人为的打扫整理过，空地的中央一堆篝
火已经熄灭，边上散落着一些牛羊的骨头，几块大石块散落在篝火的四
周。草地上留下许多人践踏过的痕迹。
LONG);
	set("outdoors", "huijiang");
	set("exits", ([ /* sizeof() == 2 */
		"east"  : __DIR__"shulin2",
		"north" : __DIR__"shulin1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -50060);
	set("coor/y", 9030);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
