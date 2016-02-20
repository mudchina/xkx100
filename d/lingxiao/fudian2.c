// Room: /d/lingxiao/fudian2.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","副殿");
	set("long",@LONG
这里是凌霄城的副殿之一。几个凌霄弟子正在一起，贼头贼脑地不
知在干什么，鬼鬼祟祟的，准没什么好事。最近凌霄城里不太平，麻烦
事情也挺多的，还是少理为妙。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"lianwu2",
		"west" : __DIR__"dadian",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 3,
	]));
	set("coor/x", -30990);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

