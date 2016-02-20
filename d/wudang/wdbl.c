//Room: wdbl.c 武当柏林
//Date: Sep 22 1997

inherit ROOM;

void create()
{
	set("short","武当柏林");
	set("long",@LONG
你穿行在一片茂密的柏林中，阴森郁翠，怪石嶙峋，草深没人。林
子里时而传出丁丁冬冬的伐木声响，不时地惊起兔子从你的身边飞跑而
过。
LONG);
	set("objects", ([
		__DIR__"npc/yetu" : 2,
	]));
	set("outdoors", "wudang");
	set("exits",([ /* sizeof() == 1 */
		"northdown": __DIR__"yuzhengong",
		"southup"  : __DIR__"haohanpo",
		"west"     : __DIR__"wdbl1",
		"east"     : __DIR__"wdbl2",
	]));
	set("coor/x", -2050);
	set("coor/y", -830);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
