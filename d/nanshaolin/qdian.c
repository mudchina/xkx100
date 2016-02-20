// Room: /d/nanshaolin/qdian.c
// Last Modified by Winder on May. 29 2001

inherit ROOM;
void create()
{
	set("short", "前殿");
	set("long", @LONG
这里是天王殿前的一处前殿。规模很小，殿内亦无很多摆设。只有
几个小沙祢在接待着来往的香客。透过洞开的大门，可以看到前面规模
雄伟的天王殿。
LONG );
	set("exits", ([
		"south" : __DIR__"gchang-1",
                "north" : __DIR__"twdian",
	]));
	set("objects",([
                CLASS_D("nanshaolin") + "/yuanshang" : 1,
		__DIR__"npc/xiang-ke" : 1,
	]));
	set("coor/x", 1820);
	set("coor/y", -6280);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

