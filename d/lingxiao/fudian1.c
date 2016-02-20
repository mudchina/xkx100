// Room: /d/lingxiao/fudian1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","副殿");
	set("long",@LONG
这里是凌霄城的副殿之一。雪山派五代弟子，除掌门白自在外，另
分四支。各支如果自己派系内有什么事，而又不必提到全派解决的，往
往就在副殿商议。
LONG);
	set("exits",([ /* sizeof() == 1 */
		"west"  : __DIR__"lianwu1",
		"east"  : __DIR__"dadian",
	]));
	set("objects", ([
	       __DIR__"npc/dizi" : 2,
	]));
	set("coor/x", -31010);
	set("coor/y", -8890);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}

